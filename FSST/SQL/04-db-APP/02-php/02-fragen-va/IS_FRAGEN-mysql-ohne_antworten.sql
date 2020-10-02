-- 
-- AB-03-IS_FRAGEN-DML.sql
-- 
-- Sammlung von SQL Fragen
--
-- A.Hofmann
--

DROP database if exists is_fragen;
CREATE database if not exists is_fragen
DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;

grant create,drop, references, select,insert,update,delete 
on is_fragen.* to is_fragen@localhost identified by 'comein';


use is_fragen;



DROP TABLE IF EXISTS `fragen`;
CREATE TABLE `fragen` (
  `id` int(11) NOT NULL default '0',
  `thema` varchar(240) default NULL,
  `kapitel` varchar(240) default NULL,
  `frage` varchar(240) default '',
  `antwort` text,
  `hinweis` text
);

INSERT INTO `fragen` (`id`,`thema`,`kapitel`,`frage`,`antwort`,`hinweis`) VALUES 
 (81,'SQL','Kapitel 01 Create table, Primary/Foreign Keys, Constraints, ...','Frage 01 Zeigen Sie die CREATE TABLE Anweisungen zu den Tabellen Professoren, Assistenten, Studenten, Vorlesungen, hoeren','?','Geben Sie auch die referentielle Integritätsregeln an. http://www.users.fh-salzburg.ac.at/~ahofmann/lva/db/demo'),
 (82,'SQL','Kapitel 02 Grundprinzip Projektion und Selektion','Frage 01 Liste alle Studenten','?','Selektion'),
 (83,'SQL','Kapitel 02 Grundprinzip Projektion und Selektion','Frage 02 Liste Personalnummer und Name der Assistenten','?','projection'),
 (84,'SQL','Kapitel 02 Grundprinzip Projektion und Selektion','Frage 03 Liste Personalnummer und Name der C4-Professoren','?','projection, where-prädikat'),
 (85,'SQL','Kapitel 02 Grundprinzip Projektion und Selektion','Frage 04 Liste Namen und Studiendauer in Jahren von allen Studenten, die eine Semesterangabe haben','?','Arithmetik, not null'),
 (86,'SQL','Kapitel 02 Grundprinzip Projektion und Selektion','Frage 05 Liste alle Studenten mit Semesterzahlen zwischen 1 und 4','?','Boolsche Operatoren (not, and, or, x between y and b, <,>,<=, >=, <>, IN, LIKE)');
INSERT INTO `fragen` (`id`,`thema`,`kapitel`,`frage`,`antwort`,`hinweis`) VALUES 
 (87,'SQL','Kapitel 02 Grundprinzip Projektion und Selektion','Frage 06 Liste alle Vorlesungen, die im Titel den String Ethik enthalten, klein oder groß geschrieben','?','Upper(), %, _'),
 (88,'SQL','Kapitel 02 Grundprinzip Projektion und Selektion','Frage 07 Liste Personalnummer, Name und Rang aller Professoren, \nabsteigend sortiert nach Rang, innerhalb des Rangs aufsteigend sortiert nach Name','?','Sortieren: Order by asc/desc'),
 (89,'SQL','Kapitel 02 Grundprinzip Projektion und Selektion','Frage 08 Liste alle verschiedenen Einträge in der Spalte Rang der Relation Professoren','?','Duplikatfrei (distinct)'),
 (90,'SQL','Kapitel 02 Grundprinzip Projektion und Selektion','Frage 09 Liste alle Geburtstage der Professoren mit ausgeschriebenem Monatsnamen','?','Datum to_char(sysdate, DD.MON.YYYY)'),
 (91,'SQL','Kapitel 02 Grundprinzip Projektion und Selektion','Frage 10 Liste das Alter der Studenten in Jahren','?','Round (sysdate - gebdatum)/365'),
 (92,'SQL','Kapitel 02 Grundprinzip Projektion und Selektion','Frage 11 Liste die Wochentage der Geburtsdaten der Studenten','?','To_char(gebdatum, day)');
INSERT INTO `fragen` (`id`,`thema`,`kapitel`,`frage`,`antwort`,`hinweis`) VALUES 
 (93,'SQL','Kapitel 02 Grundprinzip Projektion und Selektion','Frage 12 Liste die Uhrzeiten der Geburtsdaten der Studenten','?','To_char(gebdatum, hh:mi:ss)'),
 (94,'SQL','Kapitel 03 Verknüpfung von Tabellen (Join)','Frage 01 Welcher Professor liest Mäeutik?','?','Join/Gleichverbund, Alias Namen'),
 (95,'SQL','Kapitel 03 Verknüpfung von Tabellen (Join)','Frage 02 Liste die Namen der Studenten mit ihren Vorlesungstiteln','?','Join'),
 (96,'SQL','Kapitel 03 Verknüpfung von Tabellen (Join)','Frage 03 Finde die Angestellten ANG(NAME,GEHALT, MANAGER references ANG(ID),...) die mehr als ihre (direkten) Manager verdienen (Ausgabe NAME,GEHALT, NAME des Managers)','?','Exkurs: Self-referencing'),
 (97,'SQL','Kapitel 03 Verknüpfung von Tabellen (Join)','Frage 04 Liste die Namen der Assistenten, die für denselben Professor arbeiten, für den Aristoteles arbeitet','?','Self-referencing'),
 (98,'SQL','Kapitel 04 GROUP BY (Aggregatfunktionen)','Frage 01 Liste die durchschnittliche Semesterzahl der Studenten','?','Aggregatfunktionen (max, min, avg, sum, count)'),
 (99,'SQL','Kapitel 04 GROUP BY (Aggregatfunktionen)','Frage 02 Liste die höchste Semesterzahl der Studenten','?','max');
INSERT INTO `fragen` (`id`,`thema`,`kapitel`,`frage`,`antwort`,`hinweis`) VALUES 
 (100,'SQL','Kapitel 04 GROUP BY (Aggregatfunktionen)','Frage 03 Zähle alle Studenten','?','Count()\nCount(*)    Anzahl der Datensätze\nCount(Spalte) Anzahl der Datensätze, die in Spalte einen Wert haben\nCount(distinct Spalte) Anzahl der Datensätze, die in Spalte einen versch. Wert haben\n'),
 (101,'SQL','Kapitel 04 GROUP BY (Aggregatfunktionen)','Frage 04 Liste Geburtstage der Gehaltsklassenältesten (ohne Namen !)','?','Gruppierungen, Group by\nBsp: Gesucht ist pro gehaltsklasse=Rang das Geburtsdatum des Ältesten =max(gebdatum)\nPro Gruppe wird eine Zeile ermittelt\nEine Gruppe wird durch die GROUP BY Klausel festgelegt\nIn der selectKlausel dürfen nur Konstante, Aggregatfunktionen, Spalten (die auch in der group by-klausel sind) vorkommen\n'),
 (102,'SQL','Kapitel 04 GROUP BY (Aggregatfunktionen)','Frage 05 Liste Summe der SWS pro Professor (die gehaltenen SWS pro Professor)','?','group by'),
 (103,'SQL','Kapitel 04 GROUP BY (Aggregatfunktionen)','Frage 06 Liste Summe der SWS pro Professor, sofern seine Durchschnitts-SWS größer als 3 ist','?','having\n1. evtl. Join der beteiligten Tabellen\n2. Selektion der Zeilen (WHERE)\n3. Gruppierung\n4. Selektion der Gruppen (having)\n5. Projektion auf gesuchte Attribute\n'),
 (104,'SQL','Kapitel 04 GROUP BY (Aggregatfunktionen)','Frage 07 Liste Summe der SWS pro C4-Professor, sofern seine Durchschnitts-SWS größer als 3 ist','?','.');
INSERT INTO `fragen` (`id`,`thema`,`kapitel`,`frage`,`antwort`,`hinweis`) VALUES 
 (105,'SQL','Kapitel 05 Teilabfragen/Subqueries','Frage 01 Liste alle Prüfungen, die als Ergebnis die Durchschnittsnote haben','?','Einfache Teilabfrage (muss  nur einmal ausgeführt werden)\nRound (avg(note))\n'),
 (106,'SQL','Kapitel 05 Teilabfragen/Subqueries','Frage 02 Liste alle Professoren (PersNR, Name, Lehrbelastung) zusammen mit ihrer Lehrbelastung','?','Korrelierte Teilabfrage\n(select Sum(sws) from vorlesungen where ...) as Lehrbelastung)'),
 (107,'SQL','Kapitel 06 Teilabfragen und Prädikte (ANY, ALL,IN, NOT IN, EXISTS)','Frage 01 Liste alle Professoren, die keine Vorlesung halten','?','Wenn Ergebnis der Teilanfrage nicht ein einzelnes Tupel ist, sondern eine Menge von Tupeln\nANY Bedingung muss für irgendein Tupel der Teilabfrage erfüllt sein\nALL Bedingung muss für alle Tupel der Teilabfrage erfüllt sein\nIN  Bedingung mit Prädikat IN ist erfüllt, wenn Ergebnismenge der Teilabfrage\n    den aktuellen Wert enthält\nEXISTS Bedingung ist erfüllt, wenn Ergebnismenge der Teilabfrage nicht leer ist\n'),
 (108,'SQL','Kapitel 06 Teilabfragen und Prädikte (ANY, ALL,IN, NOT IN, EXISTS)','Frage 02 Liste Studenten mit größter Semesterzahl','?','>= ALL ');
INSERT INTO `fragen` (`id`,`thema`,`kapitel`,`frage`,`antwort`,`hinweis`) VALUES 
 (109,'SQL','Kapitel 07 Mengen (union, minus, intersect, ...)','Frage 01 Liste die Vereinigung von Professoren- und Assistenten-Namen','?','union'),
 (110,'SQL','Kapitel 07 Mengen (union, minus, intersect, ...)','Frage 02 Liste die Differenz von Professoren- und Assistenten-Namen','?','minus'),
 (111,'SQL','Kapitel 07 Mengen (union, minus, intersect, ...)','Frage 03 Liste den Durchschnitt von Professoren- und Assistenten-Namen','?','.'),
 (112,'SQL','Kapitel 08 Datenmanipulation: Insert , Update, Delete','Frage 01 Füge Student mit Matrikelnummer und Name ein','?','insert'),
 (113,'SQL','Kapitel 08 Datenmanipulation: Insert , Update, Delete','Frage 02 Alle Studenten sollen die Vorlesung \'Selber Atmen\' hören','?','insert'),
 (114,'SQL','Kapitel 08 Datenmanipulation: Insert , Update, Delete','Frage 03 Alle Studenten um 10 Tage älter machen','?','update'),
 (115,'SQL','Kapitel 08 Datenmanipulation: Insert , Update, Delete','Frage 04 Alle Studenten mit Semesterzahlen größer als 13 löschen','?','delete'),
 (116,'SQL','Kapitel 08 Datenmanipulation: Insert , Update, Delete','Frage 05 Niemand soll mehr die Vorlesung \'Selber Atmen\' hören','?','.');
INSERT INTO `fragen` (`id`,`thema`,`kapitel`,`frage`,`antwort`,`hinweis`) VALUES 
 (117,'SQL','Kapitel 09 Create Views','Frage 01 Lege Sicht an für Prüfungen ohne Note','?','Nicht alle Views/Sichten sind update-fähig, da sich eine Änderung \nihrer Daten nicht immer auf die Originaltabellen zurückpropagieren läßt \n'),
 (118,'SQL','Kapitel 09 Create Views','Frage 02 Lege Sicht an für Studenten mit ihren Professoren','?','.'),
 (119,'SQL','Kapitel 09 Create Views','Frage 03 Lege Sicht an mit Professoren und ihren Durchschnittsnoten','?','.'),
 (120,'SQL','Kapitel 10 Create INDEX','Frage 01 Lege Index an für Professoren Namen','?','.');

