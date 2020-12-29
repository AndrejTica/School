
// Contents of file "calc.h": 
//gsoap ns service name: calculator
//gsoap ns service style: rpc
//gsoap ns service encoding: encoded
//gsoap ns service port: http://127.0.0.1/calculator.cgi
//gsoap ns service namespace: urn:calculator
int ns__add(double a, double b, double &result); 
int ns__sub(double a, double b, double &result); 
int ns__sqrt(double a, double &result); 

