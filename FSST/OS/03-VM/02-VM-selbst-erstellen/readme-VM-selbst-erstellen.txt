#
# LUBUNTU als Virtuelle Maschine (VM) erstellen
# ==============================================================
# readme-VM-selbst-erstellen.txt   2016.03

#
# Ziel
# --------------------------------------------------------------
# Eine virtuelle Linux-Maschine  (VM)
# zum Programmieren in c, cpp, java
 + geany, gedit (Texteditoren)
 + eclipse (Programmentwicklungswerkzeug) 
 + nessi (Struktogrammeditor)
 + git (Versionsverwaltung)
 + LibreOffice (Office-Werkzeug)


#
# Note
# --------------------------------------------------------------
 Diese VM ist nur fuer Testzwecke und wird nicht gewartet und 
 sollte deshalb nicht in produktiven Umgebungen eingesetzt werden

 
 
#
# Step 1. Download and install Oracle VM VirtualBox.
# --------------------------------------------------------------
# https://www.virtualbox.org/wiki/Downloads
# download and install:
 1. VirtualBox platform packages.
 2. VirtualBox X.X.X Oracle VM VirtualBox Extension Pack



#
# Step 2. Lubuntu als VM installieren.
# --------------------------------------------------------------
# http://lubuntu.net/
	Download: lubuntu-desktop-iso Datei:
	zB: lubuntu-15.10-desktop-amd64.iso

# Mit Virtualbox: Neue VM erstellen:
	Name: VM
	Typ: Linux
	Version: Ubuntu 64-bit
	Speichergröße: 1GB (od. mehr)
	Harddisk: VDI, 64 GB HD, (dynamisch wachsend), Name: VM

# Mit Virtualbox: VM ändern:
	Massenspeicher: CD-Laufwerk: lubuntu-desktop-iso Datei 'einlegen'
	
# Mit Virtualbox: Neue VM starten und Lubuntu installieren
	Rechnername: VM
	user: informatik
	pwd: comein


# Nach dem Installieren vom virtuellen Lubuntu
	Virtuelles Lubuntu ausschalten. (iso vorher evtl. aushängen)



#
# Step 3. VM konfigurieren.
# --------------------------------------------------------------
# Nun bei der neuen VM anmelden:
 	user: informatik
 	pwd: comein

# dann:
# lxterminal starten (Alt+F2 und lxterminal eingeben) und folg. eingeben
	sudo apt-get update
		(pwd: comein)
	sudo apt-get upgrade
	sudo apt-get install dkms build-essential -y


# dann:
# Virtualbox Guest Addition installieren
# Im Programm VirtualBox: 
 Menü->Device/Geräte->Medium mit Gasterweiterung einlegen/Vbox Guest Addition installieren

# nun im lxterminal der Virtuellen Maschine
	cd /media/informatik/VBOX.....
	sudo bash	(evtl. pwd: comein eingeben)
	sh ./VBoxLinuxAdditions.run

# dann: 
# Vorbereitung f. shared Verzeichnis (mit dem Host-System)
# nun im lxterminal der Virtuellen Maschine
	sudo adduser informatik vboxsf

# dann: 
# einen gemeinsamen Ordner des HOST/Windows-Rechners 
# (z.B: D:\informatik) der VM zugängig machen
# Im Programm Virtual Box: 
# Menü->Gemeinsamer Ordner
# rechts auf das Ordner-Icon klicken und Windows-Verzeichnis 
# auswählen und einen Namen vergeben: (z.B: home) und 
# automatisch einbinden aktivieren.

# dann: 
# Im Programm Virtual Box: 
# Menü->Ändern->Allgemein/Erweitert
# Gemeinsame Zwischenablage: bidrektional (checkbox aktivieren)
# drag and drop: bidirektional
# Mini-Toolbar: am oberen Bildschirm anzeigen


# dann: 
# Virtuelle Maschine neu starten
# nun im lxterminal der Virtuellen Maschine
	sudo init 6



#
# Step 4. Software Installationen im Virtuellen Lubuntu.
# --------------------------------------------------------------
# in lxterminal (evtl: pwd: comein eingeben) einen Editor
# starten und den Inhalt der folgenden Datei mit Copy&Paste
# in den Editor kopieren und als Datei namens install.sh 
# speichern.

1. lxterminal starten (Alt+F2 und lxterminal eingeben) und
	folgendes eingeben:
	
	leafpad install.sh

2. den folgenden Text markieren und mit Ctrl-C in die
	Zwischenablage geben.

3. In der VM im leafpad mit Ctrl-V den Inhalt der Zwischen-
	ablage einfügen.
	
4. Im leafpad: Menü->Datei speichern. Menü->Datei beenden.


5. Hier nun die Datei: install.sh


# --------------------------------------------------------------
# BEGIN: Datei: intall.sh 
# --------------------------------------------------------------
# 2016
# Waehlen Sie hier die zu installierenden Pakete aus, indem
# Sie das #-Zeichen vor der jeweiligen Zeile, die mit sudo beginnt
# wegnehmen bzw. davorsetzen. (# ... leitet eine Kommentarzeile ein)

echo === Was nicht gebraucht wird entfernen =====================
sudo apt-get purge abiword gnumeric leafpad -y

echo === LIBREOFFICE ============================================
sudo apt-get install libreoffice -y

echo === PROGRAMMIEREN ==========================================
sudo apt-get install gdb cmake -y
sudo apt-get install codeblocks -y
sudo apt-get install vim gedit geany -y
#sudo apt-get install eclipse eclipse-cdt -y 
sudo apt-get install git git-core -y

echo === openJDK ===============================================
sudo apt-get install openjdk-7-jdk -y

#echo === JAVASCRIPT   ============================================
#sudo apt-get install nodejs -y
#sudo apt-get install nodejs-legacy -y
#sudo apt-get install npm

#echo === mongodb ================================
#sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv 7F0CEB10
#echo 'deb http://downloads-distro.mongodb.org/repo/ubuntu-upstart dist 10gen' | sudo tee /etc/apt/sources.list.d/mongodb.list

#sudo apt-get update
#sudo apt-get install mongodb-10gen
##sudo service mongodb start
##sudo service mongodb stop


#echo === NESSI Struktogramme ====================================
sudo apt-get install wget -y
sudo mkdir /opt/nessi
sudo wget -c "http://eii.ucv.cl/nessi/download/v1.0.6.6.21/Nessi.jar" -O /opt/nessi/Nessi.jar
sudo wget -c "http://eii.ucv.cl/nessi/download/v1.0.6.6.21/help.zip" -O /opt/nessi/help.zip
sudo unzip /opt/nessi/help.zip -d /opt/nessi


#echo === 4Beagleboard  ===========================================
##Terminal f. serielle: 
#sudo apt-get install gtkterm -y
#sudo apt-get install gparted -y
#sudo apt-get install wget pv dosfstools parted u-boot-tools uboot-mkimage btrfs-tools -y
##Compiler-AUfruf: arm-linux-gnueabi-gcc hallo.c -o hallo.exe
#sudo apt-get install gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf -y


#echo === PYTHON ================================================
#sudo apt-get install python-gtk2 python-glade2 -y

#echo === MONODEVELOP ===========================================
#sudo apt-get install monodevelop


#echo === DOXYGEN  ============================================
#sudo apt-get install doxygen doxygen-gui

#echo === FREEMIND  ============================================
#sudo apt-get install freemind



echo === PASSWORD Verwaltung ====================================
sudo apt-get install seahorse -y

echo === SCREEN RECORDER ========================================
sudo apt-get install shutter -y


#echo === SICHERHEIT  ============================================
#sudo apt-get install pgp -y 
#sudo apt-get install crack -y
#sudo apt-get install john -y
#sudo apt-get install whois -y
#sudo apt-get install traceroute -y
#sudo apt-get install hping3 -y
#sudo apt-get install nmap -y
#sudo apt-get install zenmap -y
#sudo apt-get install wireshark -y
#sudo apt-get install openssl -y
#sudo apt-get install libssl-dev -y

#echo === cURL ============================================
#sudo apt-get install curl libcurl4-openssl-dev -y


#echo === UML   ============================================
#sudo apt-get install umbrello -y


#echo === Vorbereitung für LAMPP ================================
sudo adduser informatik www-data



#echo === OPENGL ================================================
#sudo apt-get install libglu1-mesa-dev -y

#echo === SDL  ================================================
#sudo apt-get install libsdl1.2-dev -y



echo === DESKTOP Icons erstellen ================================

echo '[Desktop Entry]
Encoding=UTF-8
Name=LXTerminal
TryExec=lxterminal
Exec=lxterminal
Icon=lxterminal
Type=Application
Categories=GTK;Utility;TerminalEmulator;' > /home/informatik/Schreibtisch/lxterminal.desktop

echo '[Desktop Entry]
Encoding=UTF-8
Name=Nessi
Comment=Nessi
Exec=java -jar /opt/nessi/Nessi.jar
Icon=/opt/nessi/help/commonImgs/add_decision.png
Categories=Application;Development
Version=1.0
Type=Application
Terminal=0' > /home/informatik/Schreibtisch/nessi.desktop

echo '[Desktop Entry]
Type=Application
Name=Eclipse
Comment=Eclipse Integrated Development Environment
Icon=eclipse
Exec=eclipse
Terminal=false
Categories=Development;IDE;Java;' > /home/informatik/Schreibtisch/eclipse.desktop

echo '[Desktop Entry]
Type=Application
Version=1.0
Name=Geany
Exec=geany %F
Icon=geany
Terminal=false
Categories=GTK;Development;IDE;
MimeType=text/plain;text/x-chdr;text/x-csrc;text/x-c++hdr;text/x-c++src;text/x-java;text/x-dsrc;text/x-pascal;text/x-perl;text/x-python;application/x-php;application/x-httpd-php3;application/x-httpd-php4;application/x-httpd-php5;application/xml;text/html;text/css;text/x-sql;text/x-diff;
StartupNotify=true'  > /home/informatik/Schreibtisch/geany.desktop

# --------------------------------------------------------------
# ENDE: Datei: intall.sh 
# --------------------------------------------------------------


6. jetzt die Installation der Software starten mit:
sh ./install.sh



#
# Step 5. Kleinen Anpassungen (optional)
# --------------------------------------------------------------
Menu: Einstellungen-> Erscheinungsbild anpassen->Farben
		Minihilfe (grau als Hintergrund #CFCFCF
		und schwarz #000000 als Vordergrund)
		
		
lxterminal:
	Einstellungen->Stil->bold und Vordergrund 0xffffff


gedit: Bearbeiten->Einstellungen
	tab (4)
	Zeilennummern
	akt. Zeile hervorheben
	
geany: Bearbeiten->Einstellungen
	Terminal Pfad der aktuellen Datei setzen
		
	
Filemanager:
	Listenansicht
	
==================== fertig ============================


Gemeinsam wird in der ersten VL-Stunde folg.
* VM in Betrieb nehmen
* VirtualBox: gemeinsamen Ordner einrichten
* FileManager anpassen
* chrome-browser anpassen (Links zum Skriptum, Bücher)
* Arbeitsordner einrichten: 
	zB.: /home/informatik/home/2012.12.12-erste-programme
* README.txt (gcc, make, ... anwenden lernen)
