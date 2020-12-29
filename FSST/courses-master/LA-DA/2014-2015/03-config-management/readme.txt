================================================================================
CONFIGURATION Management
================================================================================
<pre>

--------------------------------------------------------------------------------
Inhalt
--------------------------------------------------------------------------------
	Versionsverwaltung mit GIT
	GIT und eclipse
	Testgetriebene SW-Entwicklung mit eclipse und CUTE
	Wiki mit Markdown
	+Jenkins: Continous Integration
	+SonarQube 




--------------------------------------------------------------------------------
Versionsverwaltung mit GIT
--------------------------------------------------------------------------------


GIT und gitlab.com
--------------------------------------------------------------------------------
* Create Account:
	Erstellen Sie für sich einen Account bei gitlab.com

* Install: Ein erster Überblick und die Installation von GIT 
	http://rogerdudler.github.io/git-guide/index.de.html
	
* Install 
	SmartGIT HG

* Lies: Der normale GIT-Workflow
	https://gitlab.com/help/workflow/workflow.md




ÜBUNG: Arbeiten mit git:
--------------------------------------------------------------------------------
gitlab.com:
	auf gitlab eine Gruppe erstellen (zB: 4me)
	auf gitlab ein Projekt in der Gruppe erstellen (zB: students)

lokal:
	1. einen Ornder erstellen
	mkdir GITlab
	cd GITlab

	2. remote Git Repo clonen
	git clone https://gitlab.com/4me/students.git
		(s. gitlab.com für die richtige URL)

	3. im Ordner Gitlab/students Files erstellen
	vi README
	vi hello.c
	....

	4. lokale Files fürs commit vormerken (s. stage/index)
	git add hello.c
	oder
	git add *
	oder
	git add -A

	5. ins lokale Repo einspeichern
	git commit -m"mein erstes commit ..."

	6. lokales Repo auf gitlab.com legen
	git push origin master
		(hier wird der master branch des repo nach origin (=gitlab.com) kopiert


tägliches Arbeiten im Team:
	1. git pull origin master
	2. Files bearbeiten
	3. git add/remove/.... fürs lokale commit vorbreiten
	4. git commit -m"meine anmerkungen..."
	5. git push origin master

FERTIG!!!!



Arbeiten mit git und eigenen branch erzeugen
--------------------------------------------------------------------------------
https://gitlab.com/help/workflow/workflow.md

Workflow

    Clone project:

    git clone git@example.com:project-name.git

    Create branch with your feature:

    git checkout -b $feature_name

    Write code. Commit changes:

    git commit -am "My feature is ready"

    Push your branch to GitLab:

    git push origin $feature_name

    Review your code on commits page.

    Create a merge request.

    Your team lead will review the code & merge it to the main branch.







--------------------------------------------------------------------------------
GIT und eclipse
--------------------------------------------------------------------------------
Überblick
--------------------------------------------------------------------------------
Verschiedene Arten von Benutzern:
	Ein GIT-MASTER / PROJECT-Master
		verwaltet den Master-Branch verwaltet

	Mehrere DEVELOPER
		verwaltet eigene Branch bzw (mit and. gemeinsamen Branch)


GIT-MASTER (erzeugt Projekt und branch: master)
--------------------------------------------------------------------------------
	REMOTE:
		erzeugt das Remote Git-REPO
		Gitlab.com (Projekt: dala)
		Fügt seine Developer zum Repo als member (Rolle Developer) hinzu.

	LOKAL:
		erstellt einen Ordner für die lokale Working Area
		mkdir GITlab0

	LOKAL:
		clonen des REMOTE GIT-REPO
		mit eclipse
			View Git Repositories aktivieren
			clone a remote Git Repository
			URI: https://gitlab.com/ahofmann/dala.git
			lok. Ordner: GITlab/dala

	LOKAL:
		erstellt mit eclipse einen eigenen workspace:
		Name: ws-eclipse-git

	LOKAL:
		entpacke GIT-RESTweather.zip im workspace: ws-eclipse-git
		FILE->IMPORT->General->Existing PROJECT into workspace

	LOKAL:
		stellt das Java-Projekt ins Git-REPO stellt
		re. Maustaste auf Projekt: GIT-RESTweather
		TEAM->share Project->Git
			Repo: GITlab/dala
			Working dir: Gitlab/dala


	LOKAL -> REMOTE:
		editiert das Java-Programm
		TEAM->add
		TEAM->commit
		TEAM->push
			refs/head/master add


DEVELOPER (erzeugt eig. branch: proxy)
--------------------------------------------------------------------------------
	LOKAL:
		erstellt den lok. Ordner: GITlab		
		mkdir GITlab

	LOKAL:
		import mit eclipse das Projekt vom Remote REPO
		FILE->IMPORT->Git-> (Projects from Git)->CLONE URI
			https://gitlab.com/ahofmann/dala.git
		Destination Directory: GITlab/dala

	LOKAL:
		neuen branch erzeugen
		TEAM->SWITCH to...->NEW BRANCH
			Name: proxy

	LOKAL:
		edit: RESTclient01.java 
			uncomment code for proxy
		TEAM->add
		TEAM->commit
		TEAM->push
			refs/head/proxy add
		
	REMOTE:
		https://gitlab.com/ahofmann/dala/blob/proxy/GIT-RESTweather/src/RESTclient01.java
		bzw.:
https://gitlab.com/ahofmann/dala/blob/master/GIT-RESTweather/src/RESTclient01.java

	

GIT-MASTER (merge: proxy -> master)
--------------------------------------------------------------------------------
	LOKAL:
		TEAM->switch to master
		TEAM->merge
			proxy into master
			




+GIT-MASTER (merge: proxy -> master)
Fortgeschrittenes Rückgängig machen/Wiederherstellen
--------------------------------------------------------------------------------

* http://www-cs-students.stanford.edu/~blynn/gitmagic/intl/de/ch02.html


Manchmal möchtest Du einfach zurückgehen und alle Änderungen ab einem bestimmten Zeitpunkt verwerfen, weil sie falsch waren. Dann:

$ git log

zeigt Dir eine Liste der bisherigen Commits und deren SHA1 Hashwerte:

commit 766f9881690d240ba334153047649b8b8f11c664
Author: Bob <bob@example.com>
Date:   Tue Mar 14 01:59:26 2000 -0800

    Ersetze printf() mit write().

commit 82f5ea346a2e651544956a8653c0f58dc151275c
Author: Alice <alice@example.com>
Date:   Thu Jan 1 00:00:00 1970 +0000

    Initial commit.

Die ersten paar Zeichen eines Hashwert reichen aus um einen Commit zu identifizieren; alternativ benutze kopieren und einfügen für den kompletten Hashwert. Gib ein:

$ git reset --hard 766f

um den Stand eines bestimmten Commits wieder herzustellen und alle nachfolgenden Änderungen für immer zu löschen.

Ein anderes Mal willst Du nur kurz zu einem älteren Stand springen. In diesem Fall, gib folgendes ein:

$ git checkout 82f5

Damit springst Du in der Zeit zurück, behältst aber neuere Änderungen. Aber, wie bei Zeitreisen in einem Science-Fiction-Film, wenn Du jetzt etwas änderst und commitest, gelangst Du in ein alternative Realität, denn Deine Änderungen sind anders als beim früheren Commit.




* Lies auch:
	http://wiki.eclipse.org/EGit/User_Guide#Basic_Tutorial:_Adding_a_project_to_version_control








--------------------------------------------------------------------------------
Testgetriebene SW-Entwicklung mit eclipse und CUTE
--------------------------------------------------------------------------------
eclipse und CUTE


* install cute from eclipse Marketplace
* Test.cpp als CUTE-Projekt laufen lassen

* näheres siehe IKT-Unterricht



--------------------------------------------------------------------------------
Wiki mit Markdown
--------------------------------------------------------------------------------
* Lies:
	http://markdown-here.com/livedemo.html

	https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet

* ÜBUNG:
	Erstellen Sie diesen Text in Ihrem Gitlab-Wiki unter Verwendung des 
	Markdown-Formats.



--------------------------------------------------------------------------------
+Jenkins: Continous Integration
--------------------------------------------------------------------------------
*SEE:
	https://www.youtube.com/watch?v=R0gyFokexks

	create a new job in jenkins
	https://www.youtube.com/watch?v=RR0LabeUQ88

* INSTALL: turnkey-linux jenkins

* config:
	eclipse - gitlab - jenkins



???
https://www.youtube.com/watch?v=Jt5zZ0FJ1Bc
	selenium-maven-git-jenkins
???


--------------------------------------------------------------------------------
+SonarQube 
--------------------------------------------------------------------------------
is an open platform to manage code quality. 
http://www.sonarqube.org/



--------------------------------------------------------------------------------
Weiteres
--------------------------------------------------------------------------------
turnkey-etherpad-13.0-wheezy-amd64-vmdk.zip
turnkey-owncloud-13.0-wheezy-amd64-vmdk.zip
turnkey-redmine-13.0-wheezy-amd64-vmdk.zip
</pre>

