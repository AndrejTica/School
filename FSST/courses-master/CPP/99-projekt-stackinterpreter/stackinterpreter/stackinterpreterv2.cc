#include "stackengine.h"
#include "stackinterpreterv2.h"
#include <string>
#include <fstream>
#include <strstream>
#include <iostream>
#include <map>
using namespace std;

CStackinterpreter::CStackinterpreter(char* pFilename){
	m_pc=m_nol=0;
	this->open(pFilename);
}
bool CStackinterpreter::open(char* pFilename){
	ifstream fin;
	fin.open(pFilename);
	if (!fin.fail()){
		int i=0;
		while(getline(fin, m_code[i], '\n')){
			i++;
		}
		m_nol=i;
		fin.close();
		
		#ifdef DEBUG
		for(int j=0;j<m_nol; j++)
			cout<<m_code[j]<<endl;
		#endif
		return true;
	}
	else
		return false;	
}

int CStackinterpreter::step(){
}

int CStackinterpreter::run(){
               string str;
	       double dblValue;

	       while (m_pc < m_nol) {
		       istrstream sin(m_code[m_pc].c_str());
	       		
			sin >> str;
                	if (str=="push"){
                        	sin >> dblValue;
                        	m_stackengine.push(dblValue);
               		}
                	else if (str=="assign"){
                        	sin >> str;
                        	m_data[str]=m_stackengine.top();
				m_stackengine.pop();
               		}
                	else if (str=="vpush"){
                        	sin >> str;
				m_stackengine.push(m_data[str]);
               		}
                	else if (str=="add")
                        	m_stackengine.add();
                	else if (str=="sub")
                        	m_stackengine.sub();
                	else if (str=="mul")
        	                m_stackengine.mul();
	                else if (str=="div")
                	        m_stackengine.div();
        		else if (str=="quit")
				return m_pc;
			else
				return -1; 	//UNKNOWN COMMAND
				
	        	m_pc++;		//PC erhöhen: zum nächsten Befehl
		}
		return m_pc;
}

ostream& operator<<(ostream& o, const CStackinterpreter& e){
	
	o<<endl;
	o<<"============== StackinterpreterV2 ==="<<endl;
	
	int i=0;
	while (i<e.m_nol){
		o<<"CODE:> m_code[" << i << "] = " << e.m_code[i]<<endl;
		i++;
	}
	o <<endl;
		
	map<string, double, less<string> > tmp =e.m_data;	
	map<string, double, less<string> >::iterator iter = tmp.begin();
	for(; iter != tmp.end(); iter++){
		o<<"DATA:> m_data[" << iter->first<< "] = " << iter->second<<endl;
	}
	o <<endl;
	
	o<<"STACK:>"<< e.m_stackengine;
	o <<endl;
		
	o<<"============== StackinterpreterV2 ==="<<endl;
	o<<endl;

	return o;
}


double CStackinterpreter::top(){
	return m_stackengine.top();
}
