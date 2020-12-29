// demo-regex-replace.cpp
//
// http://www.cplusplus.com/reference/regex/

#include <regex> 
#include <iostream> 
using namespace std;

#include <vector>
vector<string> from = {
"insert into Spiel values( 57,'Quarter-finals','30 June 2006 5:00 PM', 'Germany','Argentina','Berlin',72000 ); ",
"insert into Spiel values( 58,'Quarter-finals','30 June 2006 9:00 PM', 'Italy','Ukraine','Hamburg',50000  ); ",
"insert into Spiel values( 59,'Quarter-finals','1 July 2006 5:00 PM', 'England','Portugal','Gelsenkirchen',52000  ); ",
"insert into Spiel values( 60,'Quarter-finals','1 July 2006 9:00 PM', 'Brazil','France','Frankfurt',48000 ); ",
"insert into Spiel values( 61,'Semi-Finals','4 July 2006 9:00 PM', 'Germany','Italy','Dortmund',65000 ); "
};

/*
durch 
insert into Spiel values( 57,'Quarter-finals',str_to_date('30 June 2006 5:00 PM', '%d %M %Y %h:%i PM'),'Germany','Argentina','Berlin',72000 ); 

insert into Spiel values( 58,'Quarter-finals',str_to_date('30 June 2006 9:00 PM', '%d %M %Y %h:%i PM'),'Italy','Ukraine','Hamburg',50000  ); 

insert into Spiel values( 59,'Quarter-finals',str_to_date('1 July 2006 5:00 PM', '%d %M %Y %h:%i PM'), 'England','Portugal','Gelsenkirchen',52000); 

insert into Spiel values( 60,'Quarter-finals',str_to_date('1 July 2006 9:00 PM', '%d %M %Y %h:%i PM'),'Brazil','France','Frankfurt',48000 ); 

insert into Spiel values( 61,'Semi-Finals',str_to_date('4 July 2006 9:00 PM', '%d %M %Y %h:%i PM'),'Germany','Italy','Dortmund',65000 ); 

*/

int main ()
{
    std::string s ("we have 10 students working for 11 companies using 12 computers");
    std::regex e ("([0-9]+)"); // search digits

	cout << s << endl;
	cout << regex_replace(s,e,"<$1>") << endl;

	cout << endl;
	
	regex find( "'([0-9]+ [A-Z][a-z]+ [0-9][0-9][0-9][0-9] [0-9]+:[0-9][0-9]) (PM|AM)'");
	string replace("str_to_date('$1 $2', '%d %M %Y %h:%i $2')");
		
	s="insert into Spiel values( 57,'Quarter-finals','30 June 2006 5:00 AM', 'Germany','Argentina','Berlin',72000 ); ";
	cout << s << endl;
	cout << regex_replace(s, find, replace) << endl;
	
	cout << endl;
	
	s="insert into Spiel values( 57,'Quarter-finals','3 July 2006 15:00 PM', 'Germany','Argentina','Berlin',72000 ); ";
	cout << s << endl;
	cout << regex_replace(s, find, replace) << endl;
	
    return 0;
}

/*
Output:
found: 10
found: 11
found: 12
*/
