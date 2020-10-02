# AB-01-IS-SCHULE-DDL.sql

## Topic
* become a sql expert

## 1. study: create table ...
* see **is_uni-mysql.sql** 

## 2. lab 01: is_schule-DDL.sql

1. use mysql-workbench or phpMyAdmin and create
	* database: is_schule
	* user: is_schule
	* pwd: comein

2. create **IS-SCHULE-DDL.sql** for entities:
	* abteilungen (id, name, vorstand)
	* schueler (id, name, klasse)
	* lehrer (id, name)

3. Beziehungen
	* abteilungen-schueler: 1:N
	* abteilungen-lehrer: 1:N
	* lehrer-schueler: N:M
	* lehrer-schueler hat noch das Attribut note

4. Referentielle Integrität
	* Wenn eine Abteilung gelöscht wird, müssen alle zugeordneten Lehrer und Schueler auch gelöscht werden.
	* Ein Lehrer kann erst dann gelöscht werden, wenn er keine Schüler mehr unterrichtet.

5. Testdaten einfügen: *insert into statements*
	* see *is_uni.sql* 

6. Give a presentation of **your IS-SCHULE-DDL.sql**

7. SQL-Tipps:
~~~
	Überblick:
	* CREATE TABLE TabellenName (Spalte1 Datentyp Constraint, ...);

	* ALTER TABLE name ADD CONSTRAINT name FOREIGN KEY name
	 	REFERENCES name(name) ON .....;

	* CREATE INDEX IndexName ON TabellenName(Spaltenname, …);

	* SELECT Spalten FROM Tabellen WHERE Join-Bedingung [AND|OR einfache Bedingung ]
	   ORDER BY Spalten;

	* SELECT Spalte1, SUM(Spalte2) FROM Tabellen GROUP BY Spalte1 HAVING Bedingung;

	* DROP TABLE Tabelle;

	* INSERT INTO Tabelle (Spalten) VALUES (Werte);

	* UPDATE Tabelle SET Spalte= Wert WHERE Bedingung;

	* DELETE FROM Tabelle WHERE Bedingung; 

	Im Detail:
		http://dev.mysql.com/doc/refman/5.6/en/sql-syntax.html
~~~
