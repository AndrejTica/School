====================================================================
STUNDENPLAN - js serverside
====================================================================


INSTALL
	cloud9 - IDE
	monogodb 
	node, npm, express

LAB NODE REST CLIENT
	https://www.npmjs.org/package/node-rest-client

LAB NODE EXPRESS MONGO
	http://cwbuecheler.com/web/tutorials/2013/node-express-mongo/


LAB REST-API with EXPRESS and NODE				
http://coenraets.org/blog/2012/10/creating-a-rest-api-using-node-js-express-and-mongodb/
http://weblog.bocoup.com/synchronizing-html5-slides-with-node-js/




LAB 03
	"CLIENT-side: JQM and Twitter-API"
	http://www.elated.com/articles/jquery-mobile-masterclass-simple-twitter-app/


LAB 04
	"login"
	http://www.quietless.com/kitchen/building-a-login-system-in-node-js-and-mongodb/


PROJECTS (teams)
http://coenraets.org/blog/2012/10/creating-a-rest-api-using-node-js-express-and-mongodb/
http://nmj.quora.com/
[Javascript for Javadeveloper]http://http://www.ibm.com/developerworks/library/j-javadev2-18/ http://coding.smashingmagazine.com/2011/09/16/useful-node-js-tools-tutorials-and-resources/
https://restful-api-design.readthedocs.org/en/latest/
http://iconof.com/blog/from-lamp-to-the-new-full-js-web-stack-with-node-js-mongodb-jquery-backbone-js-and-other-cool-stuff/
http://www.apress.com/9781430260707


!!!!!!!!!!!!!!!SUPER
http://isolasoftware.it/2012/05/28/call-rest-api-with-node-js/
http://isolasoftware.it/2012/04/23/beaglebone-and-websockets-a-full-example-that-turn-onoff-a-led/
http://beagleboard.org/support/bonescript
https://github.com/jadonk/bonescript/blob/for-koen-weatherstation/blinkled.js




--------------------------------------------------------------------
INSTALL node (ubuntu)
--------------------------------------------------------------------
sudo apt-get update
sudo apt-get install -y python-software-properties python g++ make
sudo add-apt-repository -y ppa:chris-lea/node.js
sudo apt-get update
sudo apt-get install nodejs

evtl.
sudo ln -s /usr/bin/nodejs /usr/bin/node

--------------------------------------------------------------------
INSTALL node (debian)
--------------------------------------------------------------------
Add in 
/etc/apt/sources.list.d/sources.list

deb http://ftp.it.debian.org/debian wheezy-backports main 

apt-get update
apt-get install nodejs
apt-get install nodejs-legacy

node --version
v0.10.21


--------------------------------------------------------------------
INSTALL npm
--------------------------------------------------------------------
To install npm you to install curl:

apt-get install curl
curl https://npmjs.org/install.sh | sh







--------------------------------------------------------------------
INSTALL CLOUD9
--------------------------------------------------------------------
* see: https://github.com/ajaxorg/cloud9/
* tip: dont use shared folder


sudo npm install -g sm


sudo apt-get install -y build-essential g++ curl libssl-dev apache2-utils git libxml2-dev

cd
mkdir GIT
cd GIT
 
git clone https://github.com/ajaxorg/cloud9.git
cd cloud9
npm install


* start cloud9
cd
cd GIT/cloud9 
bin/cloud9.sh -w /home/informatik/GIT/ws-cloud9 -l 10.0.0.7

* use cloud9
http://10.0.0.7:3131


*see also: http://dotnetdavid.wordpress.com/2013/09/16/beaglebone-black-cloud9-and-bonescript-install-guide/


--------------------------------------------------------------------
INSTALL mongodb (lubuntu)
--------------------------------------------------------------------
see: http://www.mongodb.org/

sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv 7F0CEB10

echo 'deb http://downloads-distro.mongodb.org/repo/ubuntu-upstart dist 10gen' | sudo tee /etc/apt/sources.list.d/mongodb.list

sudo apt-get update

sudo apt-get install mongodb-10gen

sudo service mongodb start
sudo service mongodb stop



--------------------------------------------------------------------
INSTALL mongodb (debian)
--------------------------------------------------------------------
curl -O http://downloads.mongodb.org/linux/mongodb-linux-x86_64-2.4.9.tgz

tar -zxvf mongodb-linux-x86_64-2.4.9.tgz

mkdir -p mongodb
cp -R -n mongodb-linux-x86_64-2.4.9/ mongodb


