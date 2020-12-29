# DB
-----

## 1. ER-Diagramm: Das Konzeptionelle Modell
------
1. L: ERD: Entität->Attribute->UID->Beziehungen->Kardinalität (Ass,Prof)
2. S/S: **Erstelle das ERD: IS_UNI** (auf Papier)
	* <https://gitlab.com/4me/courses/blob/master/DB/01-db-erd-rm/02-ueben/AB-01-is_uni_interview_reports.txt>
3. S/S: **Erstelle das ERD: PROJEKTMANAGEMENT, AUTORENSCHAFT** (auf Papier od. mysql-workbench)
	* <https://gitlab.com/4me/courses/blob/master/DB/01-db-erd-rm/02-ueben/AB-02-projektmanagement-autorenschaft.md>
4. S/S: **Lies**
	* <https://gitlab.com/4me/courses/blob/master/DB/01-db-erd-rm/01-lernen/>
5. S/S: MAB-ERD
	* Autorenschaft, 
	* Praktikum


## 2. RM: Das Logische Datenmodell (relationales Datenmodell)
------
1. L: Tabelle,Spalte,Primary/Foreign Key, 1:N, N:M Zuordnungstabelle
2. L: SQL-DDL: (Ass,Prof, Stud, Vorl)
3. L: Constraints und referentielle Integrität (Ass,Prof)
4. L: Datenbank,User,Rollen verwalten mit MysqlWorkbench
5. S/S: **Erstellen Sie die Datei IS-SCHULE-DDL.sql** 
	* <https://gitlab.com/4me/courses/blob/master/DB/02-db-sql/02-ueben/AB-01-IS-SCHULE-DDL.md>
6. S/S: MAB-SQL-DDL
	* <https://gitlab.com/4me/courses/blob/master/DB/02-db-sql/03-wissen/mab-ref-integritaet-ddl.txt>


## 3. SQL: select,insert,update,delete,views,triggers,stored proc
------
1. S/S: **install**
	* <https://gitlab.com/4me/courses/blob/master/DB/02-db-sql/02-ueben/is_uni_mysql.sql>
2. S/S: **Beantworten** Sie
	* is_uni: <https://gitlab.com/4me/courses/blob/master/DB/02-db-sql/02-ueben/AB-02-IS_UNI_DML.sql> 
	* is_fussball: <https://gitlab.com/4me/courses/blob/master/DB/02-db-sql/02-ueben/AB-03-IS_FUSSBALL-DML.odt>
	* Abgabe:is_fussball: <https://gitlab.com/4me/courses/blob/master/DB/02-db-sql/02-ueben/AB-03-IS_FUSSBALL-DML.sql>
3. S/S: **Bearbeiten** Sie	
	* views,trigger,...: <https://gitlab.com/4me/courses/blob/master/DB/02-db-sql/02-ueben/AB-03-sql-mysql-trigger-views-procs.sql>
4. S/S: **Lies**
	* <<https://gitlab.com/4me/courses/blob/master/DB/02-db-sql/01-lernen>






## 4. Normalformen
------
1. L: Anomalien, Redundanzfreiheit, Inkonsistenz,Minmalität des Schlüssels,Funktionale Abhängigkeiten, Transitivität
2. L: Normalformen
3. S/S: **Lies**
	* <https://gitlab.com/4me/courses/blob/master/DB/03-db-normalformen/01-lernen/03-db-normalformen.pdf>
4. S/S: **Bearbeiten** Sie
	* <https://gitlab.com/4me/courses/blob/master/DB/03-db-normalformen/02-ueben/AB-normalformen-pkw-cd-firmenkurse.pdf>


## 5. DB-Anbindungen
------

### 5.1. Aufgaben ODBC:

	1. 01-odbc/AB-access_ODBC_mysql.md
		* MS-ACCESS und Mysql gemeinsam verwenden



### 5.2. Aufgaben PHP:

	1. 02-php/01-maps/01-mysql-googlemap.zip
		* php, xml, mysql, google maps

	2. 02-php/01-maps/02-mysql-openstreetmap.zip
		* wie oben aber mit openstreetmap
			* Way: Where Are You APP

	3. 02-php/02-fragen-va/AB-php-fragen-va.odt
		* php mit Formularen
			* SQL-Fragen Verwaltungs APP
			* Veranstaltungskalender APP

	4. 02-php/03-easyUI-kurs/AB-php-easyUI-kurs.txt
		* Ein UI-Framework mit DB-Anbindung


### 5.3. Referate:
	
	1. JDBC
	2. JPA und openxava
	3. SQL-Lite
	


## Tipps:
-----------------
~~~
alter table is_professoren add constraint prof_pk primary key (persnr);

alter table is_vorlesungen add constraint vorl_prof_fk foreign key (gelesenvon)
references is_professoren(persnr) on delete restrict;
~~~

## Weitere AUFGABEN: Gesucht ERD und RM

### Aufgabe: RM-Projekt: projekt_ddl.sql
----------------------------------------
	Erstellen Sie die Datei projekt_ddl.sql
	– Mitarbeiter arbeiten an Projekten mit und sind gleichzeitig Abteilungen
	zugeordnet.
	– Es gibt Angestellte, die einen echten Dienstvertrag besitzen und andere, die
	einen freien Dienstnehmervertrag besitzen.
	– Die Angestellten haben bestimmte Qualifikationen, die bei der Projektarbeit
	notwendige Voraussetzung sind.


### Aufgabe: RM-Autorenschaft: autoren_ddl.sql
----------------------------------------------
	Erstellen Sie die Datei: autoren_ddl.sql
	– Bücher werden von Autoren erstellt. Dabei ist die Reihenfolge der
	Autorenauflistung für die Entlohnung wichtig

