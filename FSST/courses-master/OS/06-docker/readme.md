# DOCKER

ahofa/2016.08.03: Modern management of virtual machines / microservices.

## what is docker

- <https://www.youtube.com/watch?v=JSLpG_spOBM>

## 1. images overview
```
builds ... Dockerfiles by ahofa
	ahofa_xubuntu (with x2go)
	ahofa_opencv
	ahofa_lamp
	ahofa_openvas
	ahofa_server ... http,sshd (zur abgabe)
```


## 2. create image ahofa/xubuntu:16.04 (internet access)
```
cd ahofa_xubuntu
docker build ahofa/xubuntu:16.04 .
```

## 3. create&run container ahofa_xubuntu using ahofa/xubuntu:16.04
```
docker run -d -p 2222:22 -v /media/home/home/docker/data/ws-docker:/home/informatik/ws-docker --name ahofa_xubuntu ahofa/xubuntu:16.04
```
replace /media/home/home/docker/data/ws-docker with your dir on your PC (for example: D:/docker/ws-docker)

check if your container is running
```
docker ps -a
```


## 4. work with the container ahofa_xubuntu

login via ssh
```
ssh -X root@localhost -p2222 or
ssh -X informatik@localhost -p2222
```

login via x2go client:
```
- install: <http://wiki.x2go.org/doku.php/doc:installation:x2goclient>
- New session ...

- Host: localhost Port: 2222 Username: root Password: comein
- Session TYPE: XFCE
- Host: localhost Port: 2222 Username: schueler Password: comein
- Session TYPE: XFCE
```

on problems, you might delete entries in .ssh/knonwn_hosts


## 4. stop/start/delete the container ahofa_xubuntu
```
docker start ahofa_xubuntu
docker stop ahofa_xubuntu
docker rm ahofa_xubuntu
```

## 5. other commands

```
docker history ahofa/xubuntu:14.04

#interactive login
docker exec -it ahofa_xubuntu /bin/bash

#map webcam
docker run --privileged -v /dev/video0:/dev/video0 ahofa_xubuntu /bin/bash

#Restart container
docker exec ahofa_xubuntu service ssh restart

# alle container löschen
docker rm $(docker ps -a -q)

# images löschen
docker images
docker rmi ahofa/xubuntu:16.04

#commit changes in your container into your image
docker commit ahofa_xubuntu ahofa/xubuntu:16.04

```
