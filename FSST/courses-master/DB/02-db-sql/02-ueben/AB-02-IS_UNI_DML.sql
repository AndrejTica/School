/** 
SQL-KURS: Select, joins, Gruppierungen, views, index

@name AB-02-IS_UNI_DML.sql
@author A.Hofmann
@description  Hier werden folg. Themen besprochen:
	Select, joins, Gruppierungen, views, index

ABGABE:
------------------------------
	Datei: AB-02-IS_UNI_DML-SOLVED.sql mit den SQL-Befehlen

AUFGABE 1: DB is_uni erstellen 
------------------------------
	Erzeugen Sie die Datenbank: is_uni
	Verwenden Sie dazu das folgende sql-script:
	is_uni_mysql.sql oder is_uni_oracle.sql 

	Es enthält alle SQL-Anweisungen zum Erzeugen der user und Tabellen. 

AUFGABE 2:
------------------------------
	Starten Sie ein DB-Client-Programm: (SQL-Developer od. MySql-workbench, ...)
	Laden Sie diese Datei in den dortigen SQL-Editor und

AUFGABE 3:
------------------------------
	Beantworten Sie die Fragen 
	mit dem Schwierigkeitsgrad: 1-, 2-

HINWEIS: SQL
	DB/02-db-sql/01-lernen
	http://de.wikipedia.org/wiki/SQL
	http://sqlzoo.net/de
	http://www.w3schools.com/sql/default.asp


SQL-Tipps:
	Überblick:
	CREATE TABLE TabellenName (Spalte1 Datentyp Constraint, ...);

	CREATE INDEX IndexName ON TabellenName(Spaltenname, …);

	SELECT Spalten FROM Tabellen WHERE Join-Bedingung [AND|OR einfache Bedingung ]
	   ORDER BY Spalten;

	SELECT Spalte1, SUM(Spalte2) FROM Tabellen GROUP BY Spalte1 HAVING Bedingung;

	DROP TABLE Tabelle;

	INSERT INTO Tabelle (Spalten) VALUES (Werte);

	UPDATE Tabelle SET Spalte= Wert WHERE Bedingung;

	DELETE FROM Tabelle WHERE Bedingung; 

	Im Detail:
		http://dev.mysql.com/doc/refman/5.6/en/sql-syntax.html

*/



-- =======================================================================
-- 1.	is_uni Schema/Datenbank erstellen
-- 		siehe: is_uni_oracle.sql
-- 		siehe: is_uni_mysql.sql
-- =======================================================================


-- mysql
use is_uni;



-- ---------------- 
-- SELECT Abfragen 
-- ---------------- 
-- 1-1. Liste alle IS_Studenten: 

-- 1-2. Liste Personalnummer und Name der C4-IS_Professoren: 

-- 1-3. Zähle alle IS_Studenten: 

-- 1-4. Liste Namen und Studiendauer in Jahren von allen IS_Studenten, 
-- die eine Semesterangabe haben: 

-- 1-5. Liste alle IS_Studenten mit Semesterzahlen zwischen 1 und 4: 

-- 1-6.Liste alle IS_Vorlesungen, die im Titel den String 
-- Ethik enthalten, klein oder groß geschrieben: 

-- 1-7. Liste Personalnummer, Name und Rang aller IS_Professoren, 
-- absteigend sortiert nach Rang, innerhalb des Rangs 
-- aufsteigend sortiert nach Name: 

-- 1-8. Liste alle verschiedenen Einträge in der Spalte Rang der Tabelle IS_Professoren:  


-- -------------
-- Date, Time
-- http://dev.mysql.com/doc/refman/5.1/de/date-and-time-functions.html 
-- -------------

-- 0-9. Liste alle Geburtstage mit ausgeschriebenem Monatsnamen: 

-- 0-10.Liste das Alter der IS_Studenten in Jahren: 
-- http://dev.mysql.com/doc/refman/5.1/de/date-and-time-functions.html

-- 0-11. Liste die Wochentage der Geburtsdaten der IS_Studenten: 
-- http://dev.mysql.com/doc/refman/5.1/de/date-and-time-functions.html

-- 0-12. Liste die Uhrzeiten der Geburtsdaten der IS_Studenten: 
-- http://dev.mysql.com/doc/refman/5.1/de/date-and-time-functions.html

 
-- ----------------------------------- 
-- JOINS 
-- ----------------------------------- 


-- CROSS JOIN 
-- ------------------------------------------------------
-- 1-13.1 cross join 
SELECT 
is_assistenten.name as AssName, 
is_assistenten.boss , 
is_professoren.persnr,
is_professoren.name as ProfName
FROM  is_assistenten, is_professoren ;

-- oder mit alias
SELECT 
a.name as AssName, 
a.boss , 
p.persnr,
p.name as ProfName
FROM  is_assistenten a, is_professoren p ;

-- oder


-- 1-13.2 inner join 
-- Welche Assistenten arbeiten für welchen Professor?
SELECT 
is_assistenten.name as AssName, 
is_assistenten.boss , 
is_professoren.persnr,
is_professoren.name as ProfName
FROM  is_assistenten, is_professoren 
WHERE ?????????????????????;

-- oder
SELECT 
a.name as AssName, 
p.name as ProfName
FROM  is_assistenten a INNER JOIN is_professoren p
ON    ?????????????????????;


-- 1-13.3 inner join 
-- Welche Assistenten arbeiten für den Professor Sokrates?


-- 1-13.4 Welcher Professor liest Mäeutik? 


-- 1-14.1 Liste die Namen der IS_Studenten mit ihren Vorlesungstiteln: 

-- 1-14.2 Welche Studenten haben bei welchen Professoren zu welchen
--        Vorlesungen welche Noten erhalten (tipp: is_pruefen)


-- ---------------------- 
-- JOIN: Self-referencing 
-- ---------------------- 
-- 3-15. Liste die Namen der IS_Assistenten, die für 
-- denselben Professor arbeiten, für den Aristoteles arbeitet: 


-- --------------------------------------- 
-- Aggregatfunktionen (avg,min,max,sum,... 
-- und GROUP BY 
-- --------------------------------------- 
-- 2-16. Liste die durchschnittliche Semesterzahl der Studenten:


-- 3-17. Liste Geburtstage der gehaltsklassenältesten Professoren(ohne Namen !): 

-- 2-18.1 Liste Summe der SWS (is_vorlesungen):



-- 2-18.2 Liste Summe der SWS (is_vorlesungen) pro Professor:
--          (ausgabe: gelesenvon , summeSWS)


-- 2-18.3 Liste Summe der SWS (is_vorlesungen) pro Professor:
--          (ausgabe: gelesenvon , ProfName, summeSWS)



-- 2-18.4 Liste ANZAHL (!) der SWS (is_vorlesungen) pro Professor:
--          (ausgabe: gelesenvon , ProfName, summeSWS)




-- 2-19. Liste Summe der SWS pro Professor, 
--          (ausgabe: gelesenvon , ProfName, summeSWS)
-- sofern seine Durchschnitts-SWS größer als 3 ist: 
-- (Tipp: having) 




-- 2-20. Liste Summe der SWS pro C4-Professor, 
-- sofern seine Durchschnitts-SWS größer als 3 ist: 



-- ----------------------------- 
-- Subqueries 
-- ----------------------------- 
-- 3-21. Liste alle Prüfungen, die als Ergebnis 
-- die Durchschnittsnote haben: 
			  
-- 3-22. Liste alle IS_Professoren zusammen mit ihrer 
-- Lehrbelastung: 

-- 3-23. Liste alle IS_Studenten, die älter sind als der jüngste Professor: 
-- Korrelierte Formulierung: 

-- Alternativ: 
-- Äquivalente, unkorrelierte Formulierung 
-- Vorteil: Unteranfrageergebnis kann materialisiert werden 
-- Unteranfrage braucht nur einmal ausgewertet zu werden 

-- 3-24. Liste alle IS_Assistenten, die für einen jüngeren 
-- Professor arbeiten: 

-- 3-25. Liste alle IS_Studenten mit der Zahl ihrer 
-- IS_Vorlesungen, sofern diese Zahl größer als 2 ist: 

-- 3-26. Liste die Namen und Geburtstage der Gehaltsklassenältesten: 

-- 3-27. Liste IS_Vorlesungen zusammen mit Marktanteil, 
-- definiert als = Studenten_pro_vorlesung/Studenten_insgesamt: 
-- (Anm: cast(expression as type) 

-- --------------------------------- 
-- mengen (union, intersect, ...) 
-- --------------------------------- 
-- 3-28. Liste die Vereinigung von IS_Professoren- und IS_Assistenten-Namen: 

-- 3-29. Liste die Differenz von IS_Professoren- und IS_Assistenten-Namen: 
-- (Nicht mssql) 
-- ( select Name 
--   from IS_Assistenten ) 
-- minus 
-- ( select Name 
--   from IS_Professoren ); 


-- 3-30. Liste den Durchschnitt von IS_Professoren- und IS_Assistenten-Namen: 
-- (Nicht mssql) 
-- ( select Name from IS_Assistenten ) 
-- intersect 
-- ( select Name from IS_Professoren ); 


-- 3-31. Liste alle IS_Professoren, die keine Vorlesung halten: 
-- (Anm: not in) 

-- 3-32. Liste IS_Studenten mit größter Semesterzahl: 
-- (Anm: >= all) 

-- 3-33. Liste IS_Studenten, die nicht die größte Semesterzahl haben: 
-- (Anm: < some) 



-- ------------------------------------------------ 
-- SQL-Queries zum Einfügen, Modifizieren, Löschen 
-- ------------------------------------------------ 

-- Füge neue Vorlesung mit einigen Angaben ein: 
-- ------------------------------------------------
insert into is_vorlesungen (VorlNr, Titel, gelesenVon)
values (4711,'Selber Atmen', 2125);


-- 1-1. Füge Student mit Matrikelnummer und Name ein: 

-- 1-2. Alle IS_Studenten sollen die Vorlesung 'Selber Atmen' hören: 

-- 1-3. Die neue Vorlesung soll 6 Semesterwochenstunden haben: 

-- 1-4. Alle IS_Studenten mit Semesterzahlen größer als 13 löschen: 

-- 1-5. Niemand soll mehr die Vorlesung 'Selber Atmen' hören: 
   
-- ------------------------------------------------ 
-- Views 
-- ------------------------------------------------ 
-- Nicht alle Views sind update-fähig, da sich eine Änderung 
-- ihrer Daten nicht immer auf die Originaltabellen zurückpropagieren läßt 
-- 
-- ACHTUNG:
-- Als root muss der User is_uni das Rechte create view erhalten.
-- Also a) login as root 
--      b) use is_uni;
--         grant create view on is_uni.* to  is_uni@%; oder to is_uni@localhost
--      c) relogin as user is_uni



-- 2-1. Lege View an für Prüfungen v_pruefen (StudName, ProfName, VorlTitel) ohne Note: 
drop view if exists v_pruefen;

-- Kontrolle
select * from v_pruefen;

-- 2-2. Lege View an für IS_Studenten mit ihren IS_Professoren und VorlTitel:
--      v_inskription (Ausgabe: StudName, ProfName, VorlTitel)

drop view if exists v_inskription;


-- Kontrolle
select * from v_inskription order by VorlTitel;



-- 3-3. Lege Sicht an mit IS_Professoren und ihren Durchschnittsnoten: 
--      (Ausgabe: ProfName, DurchschnittsNote)



-- -------------------------------------- 
-- INDEX 
-- -------------------------------------- 
-- 2-1. Erzeuge einen Index namens idx_pname bzgl Tabelle IS_Professoren und 
-- der Spalte name. 

