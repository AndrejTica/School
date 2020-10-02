docker run -d -p 80:80 -p 3306:3306 -p 443:443  --name ahofa_lamp ahofa/lamp:14.04

# mit -v wird /var/www/html vom container nicht mehr zugängig sein, sondern es wird der HOST-Ordner verwendet.
#docker run -d -p 80:80 -p 3306:3306 -p 443:443  -v /media/home/home/docker/data/lamp/html:/var/www/html --name ahofa_lamp ahofa/lamp:14.04


