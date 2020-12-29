#
# ahofmann, 2016-08-03
# 
# image:
# ahofa/xubuntu:16.04
#
# desc:
# xubuntu with 
#    gcc,g++,make,git, x2go, ...
#    ssh, http access (/var/www/html)
#
# user: root/comein
# user: informatik/comein
#
# shared workspace: /home/informatik/ws-docker
#
#
# image erzeugen:
# docker build -t ahofa/xubuntu:16.04 .
#
# container erzeugen:
# docker run -d -p 2222:22 -v docker/data/ws-docker:/home/informatik/ws-docker -t ahofa/xubuntu:16.04
#
# aufruf via ssh:
# ssh -X informatik@localhost 2222
# ssh -X root@localhost 2222
#
# aufruf via x2go client:
# http://wiki.x2go.org/doku.php/doc:installation:x2goclient
#
# New session ...
# Host: localhost Port: 2222 Username: root Password: comein
# Session TYPE: XFCE
#
# New session ...
# Host: localhost Port: 2222 Username: informatik Password: comein
# Session TYPE: XFCE
#


FROM ubuntu:16.04
MAINTAINER Anton Hofmann "anton.hofmann@htl-salzburg.ac.at"

ENV DEBIAN_FRONTEND noninteractive

#
# update base system
#
RUN apt-get update 
RUN apt-get -y upgrade

# Upstart and DBus have issues inside docker. 
RUN dpkg-divert --local --rename --add /sbin/initctl && ln -sf /bin/true /sbin/initctl


#
# install: gcc,g++, ...
#
RUN apt-get install -y build-essential gdb cmake git 

#
# install: editors
#
RUN apt-get install -y vim nano geany

#
# install ide
RUN apt-get install -y codeblocks


#
# install utils
#
RUN apt-get install -y wget openssl


#
# install xubuntu, x2go
#
RUN apt-get install -y xubuntu-desktop 

RUN add-apt-repository ppa:x2go/stable
RUN apt-get update
RUN apt-get install x2goserver x2goserver-xsession pwgen -y
RUN mkdir -p /tmp/.X11-unix && chmod 1777 /tmp/.X11-unix


# 
# user erzeugen und pwd
# 	root/comein
# 	informatik/comein
#
RUN echo 'root:comein' | chpasswd
RUN groupadd -g 1000 informatik
RUN useradd -m -d /home/informatik -s /bin/bash -c "Informatik Account" -u 1000 -g 1000 informatik
RUN mkdir /home/informatik/ws-docker
RUN chown -R informatik:informatik /home/informatik
RUN echo 'informatik:comein' | chpasswd
RUN usermod -aG sudo,adm informatik

#
# vim config for informatik
#
##USER informatik
##RUN git clone https://github.com/amix/vimrc.git ~/.vim_runtime
##RUN sh ~/.vim_runtime/install_awesome_vimrc.sh


# 
# vim config for root
#
##USER root
##RUN git clone https://github.com/amix/vimrc.git ~/.vim_runtime
##RUN sh ~/.vim_runtime/install_awesome_vimrc.sh


#
# volume /home/informatik/ws-docker
# -v docker/data/ws-docker:/home/informatk/ws-docker
#
VOLUME /home/informatik/ws-docker


#
# remote access via sshd
#
RUN apt-get install -y openssh-server
RUN mkdir /var/run/sshd

RUN sed -i 's/PermitRootLogin without-password/PermitRootLogin yes/' /etc/ssh/sshd_config

RUN sed -i "s/UsePrivilegeSeparation.*/UsePrivilegeSeparation no/g" /etc/ssh/sshd_config 
RUN sed -i "s/UsePAM.*/UsePAM no/g" /etc/ssh/sshd_config
RUN sed -i "s/PermitRootLogin.*/PermitRootLogin yes/g" /etc/ssh/sshd_config


#
# -p 2222:22 
#
EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]

