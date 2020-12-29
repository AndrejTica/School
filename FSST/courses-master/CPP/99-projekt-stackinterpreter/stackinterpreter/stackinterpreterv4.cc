// a.hofmann
//stackinterpreterv4.cc

#include "stackengine.h"
#include "stackinterpreterv4.h"
#include <string>
#include <fstream>
#include <strstream>
#include <iostream>
#include <map>
using namespace std;

CStackinterpreter::CStackinterpreter(const char* pFilename){
	m_pc=m_nol=0;
	this->open(pFilename);
}
bool CStackinterpreter::open(const char* pFilename){
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

void CStackinterpreter::reset(){
	m_pc=m_nol=0;
	// stack leeren
	m_stackengine.clear();
	//Daten leeren
	m_data.clear();
}


int CStackinterpreter::run(){
               string str;
	       double dblValue;

	       	
	       while (m_pc < m_nol) {
		       istrstream sin(m_code[m_pc].c_str());
	       		
			sin >> str;
			if (str[0]=='/' && str[1]=='/' )		//Kommentar
				;
			else if (str=="debug"){
				getline(sin, str);
				cout << "DEBUG:> at Line: "<<m_pc<<": " << str<<endl;
				cout << *this;
			}
                	else if (str=="push"){
                        	sin >> dblValue;
                        	m_stackengine.push(dblValue);
               		}
                	else if (str=="assign"){
                        	sin >> str;
                        	m_data[str]=m_stackengine.top();
				m_stackengine.pop();
               		}
                	else if (str=="vpush" || str=="pushv"){
                        	sin >> str;
				m_stackengine.push(m_data[str]);
               		}
                	else if (str=="if"){
				int nextline=m_pc;
				while (m_code[nextline]!="endif")
					nextline++;
				//nextline zeigt nun auf zeile mit endif
				m_pc++;
				if (m_code[m_pc] == "neq" && m_stackengine.neq() == true)
					; 
				else if (m_code[m_pc] == "eq" && m_stackengine.eq() == true)
					;
				else if (m_code[m_pc] == "lt" && m_stackengine.lt() == true)
					;
				else if (m_code[m_pc] == "le" && m_stackengine.le() == true)
					;
				else if (m_code[m_pc] == "gt" && m_stackengine.gt() == true)
					;
				else if (m_code[m_pc] == "ge" && m_stackengine.ge() == true)
					;
				else
					m_pc=nextline;   //m_pc zeigt auf endif
               		}
			else if(str=="endif")
				;				
			else if (str=="add")
                        	m_stackengine.add();
                	else if (str=="sub")
                        	m_stackengine.sub();
                	else if (str=="mul")
        	                m_stackengine.mul();
	                else if (str=="div")
                	        m_stackengine.div();

	                else if (str=="read"){
				getline(sin,str);
                	        cout << endl << "READ: "<< str << "> ";
				cin >> dblValue;
				m_stackengine.push(dblValue);
			}
	                else if (str=="write"){
				getline(sin,str);
                	        cout << endl << "WRITE: " << str << "> "<< m_stackengine.top() << endl;
				m_stackengine.pop();
			}
        		else if (str=="quit")
				return m_pc;
			else
				return -1; 	//UNKNOWN COMMAND
				
	        	m_pc++;		//PC erhöhen: zum nächsten Befehl
			//cout<<m_stackengine;
		}
		return m_pc;
}

ostream& operator<<(ostream& o,  CStackinterpreter& e){
	
	o<<endl;
	o<<">>>____________________<< Speicher Begin >> ______________"<<endl;
	int i=0;
	while (i<e.m_nol){
		o<<"   CODE:> [" << i << "] = " << e.m_code[i]<<endl;
		i++;
	}
	o << "   ......."<<endl;
		
	map<string, double, less<string> > tmp =e.m_data;	
	map<string, double, less<string> >::iterator iter = tmp.begin();
	for(; iter != tmp.end(); iter++){
		o<<"   DATA:> [" << iter->first<< "] = " << iter->second<<endl;
	}
	o << "   ......."<<endl;
	
	o<< e.m_stackengine;
//	o <<endl;
		
	o<<">>>____________________<< Speicher end >> ______________"<<endl;
	//o<<endl;

	return o;
}


double CStackinterpreter::top(){
	return m_stackengine.top();
}
