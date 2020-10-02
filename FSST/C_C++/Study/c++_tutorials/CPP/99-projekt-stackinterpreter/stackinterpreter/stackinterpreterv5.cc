// a.hofmann
//stackinterpreterv5.cc

#include "stackengine.h"
#include "stackinterpreterv5.h"
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
		
	       int while_begin, while_end;
	       bool while_block;	//zeigt an, ob die while-Bedingung erfüllt ist
	       bool then_block;	//zeigt an, ob der IF-Teil ausgeführt wird
	       bool in_if, in_while;	// merker ob, Verzweigung oder Schleife
	       					// wichtig für lt, gt, .....
	       	
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
				in_if=true;
				in_while=false;
			}
			else if (str=="while"){
				in_while=true;
				in_if=false;
				while_begin=m_pc;
			}

			else if (str=="lt") {
				if (in_while){
				 	if (m_stackengine.lt())
						while_block=true;
					else {
						while_block=false;
						while (m_code[m_pc]!="endwhile")
							m_pc++;
						//m_pc zeigt nun auf die Zeile mit dem text endwhile					
					}
				}
				else { //in if
					if (m_stackengine.lt())
						then_block=true;
					else {
						then_block=false;
						//suche else bzw endif
						while (m_code[m_pc]!="else"){
							if (m_code[m_pc] == "endif")
								break;
							m_pc++;
						}
						//m_pc zeigt nun auf die Zeile mit dem text else oder endif					
					}
				}
			}
			else if (str=="le") {
				if (in_while){
				 	if (m_stackengine.le())
						while_block=true;
					else {
						while_block=false;
						while (m_code[m_pc]!="endwhile")
							m_pc++;
						//m_pc zeigt nun auf die Zeile mit dem text endwhile					
					}
				}
				else { //in if
					if (m_stackengine.le())
						then_block=true;
					else {
						then_block=false;
						//suche else bzw endif
						while (m_code[m_pc]!="else"){
							if (m_code[m_pc] == "endif")
								break;
							m_pc++;
						}
						//m_pc zeigt nun auf die Zeile mit dem text else oder endif					
					}
				}
			}
						
			else if (str=="gt") {
				if (in_while){
				 	if (m_stackengine.gt())
						while_block=true;
					else {
						while_block=false;
						while (m_code[m_pc]!="endwhile")
							m_pc++;
						//m_pc zeigt nun auf die Zeile mit dem text endwhile					
					}
				}
				else { //in if
					if (m_stackengine.gt())
						then_block=true;
					else {
						then_block=false;
						//suche else bzw endif
						while (m_code[m_pc]!="else" || m_code[m_pc]!="endif")
							m_pc++;
						//m_pc zeigt nun auf die Zeile mit dem text else oder endif					
					}
				}
			}
			
			else if(str=="endif"){
				in_if=false;
				then_block=false;
			}	
			else if(str=="else" && then_block==true){
				while (m_code[m_pc]!="endif")
					m_pc++;
					//m_pc zeigt nun auf die Zeile mit dem text  endif					
			}
			else if(str=="else" && then_block==false)
				;									
        		else if (str=="endwhile" && while_block==false){
				in_while=false;
			}
        		else if (str=="endwhile" && while_block==true){
				in_while=true;
				m_pc=while_begin;
			}			
				
				
			else if (str=="add")
                        	m_stackengine.add();
                	else if (str=="sub")
                        	m_stackengine.sub();
                	else if (str=="mul")
        	                m_stackengine.mul();
	                else if (str=="div")
                	        m_stackengine.div();
			else if (str=="mod")
                	        m_stackengine.mod();

	                else if (str=="read"){
				getline(sin,str);
                	        cout << endl << "READ: <"<< str << "> ";
				cin >> dblValue;
				m_stackengine.push(dblValue);
			}
	                else if (str=="write"){
				getline(sin,str);
                	        cout << endl << "WRITE: <" << str << "> "<< m_stackengine.top() << endl;
				m_stackengine.pop();
			}
			else if (str=="quit")
				return m_pc;
			else{
				cout <<"UNKNOWN COMMAND !" << endl;
				return -1; 	//UNKNOWN COMMAND
			}	
			
	        	m_pc++;		//PC erhöhen: zum nächsten Befehl
			
			#ifdef DEBUG
			cout << "DEBUG: m_code[m_pc]= " <<m_code[m_pc] << endl;
			cout << "m_pc= " <<m_pc << endl;
			#endif
			
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
