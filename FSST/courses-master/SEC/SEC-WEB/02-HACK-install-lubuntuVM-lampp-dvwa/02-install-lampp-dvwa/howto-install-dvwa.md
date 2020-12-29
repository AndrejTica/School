# IT-SEC4WEB : install xampp and dvwa

> DO NOT INSTALL DVWA on a production service!!!!

* Annahme: login-user ist 'informatik' und passwd ist 'comein'

## download:

* xampp for linux or xampp for windows
* DVWA-master.zip


## install lamp:
~~~
cd Download

sudo ./xampp-linux-x64-7.2.0-0-installer.run

echo 'PATH=/opt/lampp/bin:$PATH' >> /home/informatik/.bashrc
~~~


## install and config dvwa:
~~~
cd Download

unzip DVWA-master.zip 
mv DVWA-master dvwa
sudo mv dvwa /opt/lampp/htdocs/


cd /opt/lampp/htdocs/dvwa

chmod -R 777 /opt/lampp/htdocs/dvwa/hackable/uploads
chmod -R 777 /opt/lampp/htdocs/dvwa/config 
chmod -R 777 /opt/lampp/htdocs/dvwa/external/phpids/0.6/lib/IDS/tmp/phpids_log.txt


cp /opt/lampp/htdocs/dvwa/config/config.inc.php.dist /opt/lampp/htdocs/dvwa/config/config.inc.php

sed -i "s/$_DVWA[ 'recaptcha_private_key' ] = ''/$_DVWA[ 'recaptcha_private_key' ] = 'TaQ185RFuWM'/g" /opt/lampp/htdocs/dvwa/config/config.inc.php
sed -i "s/$_DVWA[ 'recaptcha_public_key' ] = ''/$_DVWA[ 'recaptcha_public_key' ] = 'TaQ185RFuWM'/g" /opt/lampp/htdocs/dvwa/config/config.inc.php 


sudo bash
sed -i 's/allow_url_include = Off/allow_url_include = On/g' /opt/lampp/etc/php.ini
sed -i 's/allow_url_fopen = Off/allow_url_fopen = On/g' /opt/lampp/etc/php.ini
echo 'session.save_path = "/tmp"' >> /opt/lampp/etc/php.ini
exit


sed -i 's/root/admin/g' /opt/lampp/htdocs/dvwa/config/config.inc.php

echo "use mysql;grant all on dvwa.* to 'admin'@'%' identified by 'p@ssw0rd';" | /opt/lampp/bin/mysql -u root
echo "use mysql;grant all on dvwa.* to 'admin'@'localhost' identified by 'p@ssw0rd';" | /opt/lampp/bin/mysql -u root


## start lampp
~~~
sudo /opt/lampp/manager-linux-x64.run
~~~


## login
~~~
http://localhost/dvwa

user: admin
pwd: password
~~~

