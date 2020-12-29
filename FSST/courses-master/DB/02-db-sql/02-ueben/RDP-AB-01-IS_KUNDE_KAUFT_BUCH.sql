/* 
RDP-DB: AUFGABENSTELLUNG
--------------------------------------------

DB SQL: Kunde kauft Buch

Gegeben seien folg. Tabellen (Schlüssel sind unterstrichen u. fett)

kunde {kd_nr, name, geb_dat}
kauf {kd_nr, isbn_nr, datum}
buch {isbn_nr, verlag, titel,sparte,preis}
Die Schlüssel sind unterstrichen.

1. Gesucht ist das dazugehörige ER-Diagramm.
2. Wie nennt man den Vorgang aus dem Relationenschema ein ER-Diagramm zu erzeugen?
3. Gesucht sind die SQL-Anweisungen zu:
3.1. Aus welchen Verlagen stammen die Buecher, die Herr Mustermann gekauft hat?
3.2. Liste die Verlage und die Anzahl der Buecher, die sie(=die Verlage) anbieten, in
       absteigender Reihenfolge (Verlag und Anzahl soll ausgegeben werden)
*/

-- RDP-DB: LÖSUNG
--------------------------------------------
-- file: RDP-AB-01-IS_KUNDE_KAUFT_BUCH-SOLVED.sql
-- autor: anton.hofmann@htl-salzburg.ac.at
-- demo zu sql: RDP-AB-02-IS_KUNDE_KAUFT_BUCH.sql
-- db: is_kunde_kauft_buch
-- user: is_kunde_kauft_buch oder is_kunde_kauft_buch@localhost
-- pwd: comein
-- als root ausführen (zB mit phpmyadmin


-- Schritt 1: Datenbankschema erzeugen
-- -----------------------------------

drop database if exists is_kunde_kauft_buch;
create database if not exists is_kunde_kauft_buch;

grant create,drop, references, select,insert,update,delete 
on is_kunde_kauft_buch.* to is_kunde_kauft_buch@localhost identified by 'comein';


use is_kunde_kauft_buch;

DROP TABLE if exists kunde;
CREATE TABLE kunde
(
????????????????????
);

DROP TABLE if exists buch;
CREATE TABLE buch
(
???????????????????????????

);


DROP TABLE if exists kauf;
CREATE TABLE kauf
(
?????????????????????????
);

INSERT INTO buch (  isbn_nr,  verlag, titel,   sparte,  preis)
VALUES(111,'Hanser Verlag', 'DB I', 'IT', 10.90);
??????????????????????


INSERT INTO kunde ??????????????????????


INSERT INTO kauf ?????????????????????????

-- Schritt 2: SQL Fragen
-- 1. Gesucht ist das dazugehörige ER-Diagramm.
--    Antwort: M:N Beziehung zwischen Buch und Kunde (+ zusätzlichem datum Attribut)

-- 2. Wie nennt man den Vorgang aus dem Relationenschema ein ER-Diagramm zu erzeugen?
--    Antwort: Reverse Engineering

-- 3. Gesucht sind die SQL-Anweisungen zu:
-- 3.1. Aus welchen Verlagen stammen die Buecher, die Herr Mustermann gekauft hat?

	SELECT ????????????????????????????????????????
	
-- Antwort:
--    verlag
--    -------------
--    Dpunkt Verlag
--    Dreier Verlag


-- 3.2. Liste die Verlage und die Anzahl der Buecher, die sie(=die Verlage) anbieten, in
--       absteigender Reihenfolge (Verlag und Anzahl soll ausgegeben werden)
	SELECT ?????????????????????????????????????

-- Antwort:
-- 	verlag 	 		anz_buecher Absteigend
--    --------------------------
--		Dreier Verlag 	3
--		Dpunkt Verlag 	1
--		Hanser Verlag 	1
