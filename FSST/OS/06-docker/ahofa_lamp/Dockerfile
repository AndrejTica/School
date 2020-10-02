#
# 2016-02-11 ahofmann
# ahofa/lamp:14.04
#
# lamp with:
# 	* mysql (root@localhost/comein)
# 	* phpmyadmin (root/comein)
# 	* dvwa  (take care!!!! admin/password)
#
# http://localhost/phpmyadmin
# http://localhost/dvwa
# http://localhost/test-mysql.php
#
# see also: http://txt.fliglio.com/2013/11/creating-a-mysql-docker-container/
#

FROM ubuntu:14.04 
MAINTAINER Anton Hofmann <anton.hofmann@htl-salzburg.ac.at> 

# Setup environment 
ENV DEBIAN_FRONTEND noninteractive 

# Update sources 
RUN apt-get update 
RUN apt-get -y upgrade

#install utils
RUN apt-get install -y vim unzip 

# install http 
RUN apt-get install -y apache2
RUN mkdir -p /var/lock/apache2 /var/run/apache2


# install mysql 
RUN apt-get install -y mysql-client mysql-server


# install php 
RUN apt-get install -y php5 php5-mysql php5-dev php5-gd php5-memcache php5-pspell php5-snmp snmp php5-xmlrpc libapache2-mod-php5 php5-cli


# install phpmyadmin
RUN /usr/sbin/mysqld & sleep 10s && apt-get install -y phpmyadmin
RUN ln -s /etc/phpmyadmin/apache.conf /etc/apache2/conf-available/phpmyadmin.conf
RUN a2enconf phpmyadmin
RUN php5enmod mcrypt



# start mysqld to set password for root (comein)
# change it later with mysql: alter user 'root'@'localhost' identified by 'newpasswd'
#
RUN /usr/sbin/mysqld & \
    sleep 10s &&\
    echo "GRANT ALL ON *.* TO 'root'@'%' IDENTIFIED BY 'comein' WITH GRANT OPTION; FLUSH PRIVILEGES" | mysql -u root &&\
    echo "GRANT ALL ON *.* TO 'root'@'localhost' IDENTIFIED BY 'comein' WITH GRANT OPTION; FLUSH PRIVILEGES" | mysql -u root &&\
    echo "create database test" | mysql -u root --password=comein

# allow remote login for user root@%, username@%, ...
RUN sed -i -e"s/^bind-address\s*=\s*127.0.0.1/bind-address = 0.0.0.0/" /etc/mysql/my.cnf


#
# install DVWA
# 
ADD https://github.com/RandomStorm/DVWA/archive/v1.9.zip /var/www/html/v1.9.zip
RUN cd /var/www/html && unzip v1.9
RUN chmod 777 /var/www/html/DVWA-1.9/hackable/uploads
RUN chmod 777 /var/www/html/DVWA-1.9/external/phpids/0.6/lib/IDS/tmp/phpids_log.txt
RUN sed -i "s/p@ssw0rd/comein/g" /var/www/html/DVWA-1.9/config/config.inc.php
ADD .htaccess /var/www/html/DVWA-1.9/.htaccess
RUN sed -i "s/FileInfo/All/g" /etc/apache2/sites-available/000-default.conf
RUN ln -s /var/www/html/DVWA-1.9 /var/www/html/dvwa
RUN sed -i 's/allow_url_include = Off/allow_url_include = On/' /etc/php5/apache2/php.ini
#
# a sample mysql/php test
#
ADD test-mysql.php /var/www/html/test-mysql.php

#
#
VOLUME /var/www/html
EXPOSE 80 443 3306


# to run more than one service we use Supervisor
# https://docs.docker.com/engine/admin/using_supervisord/
# Here is the file: supervisord.conf
# [supervisord]
# nodaemon=true
#
# [program:sshd]
# command=/usr/sbin/mysqld
#
# [program:apache2]
# command=/bin/bash -c "source /etc/apache2/envvars && exec /usr/sbin/apache2 -DFOREGROUND"
#

RUN apt-get install -y supervisor
COPY supervisord.conf /etc/supervisor/conf.d/supervisord.conf


# start apache and mysql
CMD ["/usr/bin/supervisord"]

