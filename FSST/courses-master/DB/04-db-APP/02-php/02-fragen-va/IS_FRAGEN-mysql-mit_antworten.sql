-- 
-- AB-03-IS_FRAGEN-mit_antworten-DML.sql
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
  `id` int(11) NOT NULL primary key auto_increment,
  `thema` varchar(240) default NULL,
  `kapitel` varchar(240) default NULL,
  `frage` varchar(240) default '',
  `antwort` text,
  `hinweis` text
);




-- ===================================================
-- SQL
-- ===================================================
insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 01 Create table, Primary/Foreign Keys, Constraints, ...',
'Frage 01 Zeigen Sie die CREATE TABLE Anweisungen zu den Tabellen Professoren, Assistenten, Studenten, Vorlesungen, hoeren','.',
'Geben Sie auch die referentielle Integritätsregeln an.');

 

insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 02 Grundprinzip Projektion und Selektion',
'Frage 01 Liste alle Studenten', 
'select * from Studenten',
'Selektion');

insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 02 Grundprinzip Projektion und Selektion',
'Frage 02 Liste Personalnummer und Name der Assistenten', 
'select PersNr, Name from Assistenten',
'projection');


insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 02 Grundprinzip Projektion und Selektion',
'Frage 03 Liste Personalnummer und Name der C4-Professoren', 
'select PersNr, Name from Professoren where Rang = ''C4''',
'projection, where-prädikat');

insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 02 Grundprinzip Projektion und Selektion',
'Frage 04 Liste Namen und Studiendauer in Jahren von allen Studenten, die eine Semesterangabe haben', 
'select Name, Semester/2 AS Studienjahr from Studenten where Semester is not null',
'Arithmetik, not null');

 
insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 02 Grundprinzip Projektion und Selektion',
'Frage 05 Liste alle Studenten mit Semesterzahlen zwischen 1 und 4', 
'select * from Studenten where Semester >= 1 and Semester <= 4
Alternativ: 
select * from Studenten where Semester between 1 and 4
Alternativ: 
select * from Studenten where Semester in (1,2,3,4)
',
'Boolsche Operatoren (not, and, or, x between y and b, <,>,<=, >=, <>, IN, LIKE)');


insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 02 Grundprinzip Projektion und Selektion',
'Frage 06 Liste alle Vorlesungen, die im Titel den String Ethik enthalten, klein oder groﬂ geschrieben', 
'select * from Vorlesungen where upper(Titel) like ''%ETHIK%''',
'Upper(), %, _');


insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 02 Grundprinzip Projektion und Selektion',
'Frage 07 Liste Personalnummer, Name und Rang aller Professoren, 
absteigend sortiert nach Rang, innerhalb des Rangs aufsteigend sortiert nach Name', 
'select PersNr, Name, Rang from Professoren order by Rang desc, Name asc',
'Sortieren: Order by asc/desc');



insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 02 Grundprinzip Projektion und Selektion',
'Frage 08 Liste alle verschiedenen Einträge in der Spalte Rang der Relation Professoren', 
'select distinct Rang from Professoren',
'Duplikatfrei (distinct)');
 



insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 02 Grundprinzip Projektion und Selektion',
'Frage 09 Liste alle Geburtstage der Professoren mit ausgeschriebenem Monatsnamen', 
'select name, to_char(GebDatum,''month DD, YYYY'') AS Geburtstag from studenten',
'Datum to_char(sysdate, DD.MON.YYYY)');


insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 02 Grundprinzip Projektion und Selektion',
'Frage 10 Liste das Alter der Studenten in Jahren', 
'select name,round((sysdate - GebDatum) / 365) as Alter_in_Jahren from studenten',
'Round (sysdate - gebdatum)/365');


insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 02 Grundprinzip Projektion und Selektion',
'Frage 11 Liste die Wochentage der Geburtsdaten der Studenten', 
'select name, to_char(GebDatum,''day'') from studenten',
'To_char(gebdatum, day)');



insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 02 Grundprinzip Projektion und Selektion',
'Frage 12 Liste die Uhrzeiten der Geburtsdaten der Studenten', 
'select name, to_char(GebDatum,''hh:mi:ss'') from studenten',
'To_char(gebdatum, hh:mi:ss)');



insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 03 Verknüpfung von Tabellen (Join)',
'Frage 01 Welcher Professor liest Mäeutik?', 
'select Name, Titel from Professoren, Vorlesungen where PersNr = gelesenVon and Titel = ''Mäeutik''',
'Join/Gleichverbund, Alias Namen');
 


insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 03 Verknüpfung von Tabellen (Join)',
'Frage 02 Liste die Namen der Studenten mit ihren Vorlesungstiteln', 
'select Name, Titel from Studenten, hoeren, Vorlesungen
where Studenten.MatrNr = hoeren.MatrNr and hoeren.VorlNr = Vorlesungen.VorlNr

Alternativ: 
select s.Name, s.Titel
from Studenten s, hoeren h, Vorlesungen v
where s.MatrNr = h.MatrNr and
      h.VorlNr = v.VorlNr',
'Join');


insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 03 Verknüpfung von Tabellen (Join)',
'Frage 03 Finde die Angestellten ANG(NAME,GEHALT, MANAGER references ANG(ID),...) die mehr als ihre (direkten) Manager verdienen (Ausgabe NAME,GEHALT, NAME des Managers)', 
'Select p.name, p.gehalt, m.name
From ang p, ang m
Where p.mnr = m.id and
p.gehalt > m.gehalt',
'Exkurs: Self-referencing');



insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 03 Verknüpfung von Tabellen (Join)',
'Frage 04 Liste die Namen der Assistenten, die für denselben Professor arbeiten, für den Aristoteles arbeitet', 
'select a2.Name
from assistenten a1, assistenten a2
where a2.boss = a1.boss
and a1.name = ''Aristoteles''
and a2.name != ''Aristoteles''
',
'Self-referencing');


 
insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 04 GROUP BY (Aggregatfunktionen)',
'Frage 01 Liste die durchschnittliche Semesterzahl der Studenten', 
'select avg(Semester) from Studenten',
'Aggregatfunktionen (max, min, avg, sum, count)');
 

insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 04 GROUP BY (Aggregatfunktionen)',
'Frage 02 Liste die höchste Semesterzahl der Studenten', 
'select max(Semester)from Studenten',
'max');

 

insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 04 GROUP BY (Aggregatfunktionen)',
'Frage 03 Zähle alle Studenten', 
'select count(*) from Studenten',
'Count()
Count(*)    Anzahl der Datensätze
Count(Spalte) Anzahl der Datensätze, die in Spalte einen Wert haben
Count(distinct Spalte) Anzahl der Datensätze, die in Spalte einen versch. Wert haben
');


insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 04 GROUP BY (Aggregatfunktionen)',
'Frage 04 Liste Geburtstage der Gehaltsklassenältesten (ohne Namen !)', 
'select rang, max(GebDatum)
from Professoren
group by rang',
'Gruppierungen, Group by
Bsp: Gesucht ist pro gehaltsklasse=Rang das Geburtsdatum des Ältesten =max(gebdatum)
Pro Gruppe wird eine Zeile ermittelt
Eine Gruppe wird durch die GROUP BY Klausel festgelegt
In der selectKlausel dürfen nur Konstante, Aggregatfunktionen, Spalten (die auch in der group by-klausel sind) vorkommen
');


insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 04 GROUP BY (Aggregatfunktionen)',
'Frage 05 Liste Summe der SWS pro Professor (die gehaltenen SWS pro Professor)', 
'select gelesenVon, sum(SWS)
from Vorlesungen
group by gelesenVon',
'group by');


insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 04 GROUP BY (Aggregatfunktionen)',
'Frage 06 Liste Summe der SWS pro Professor, sofern seine Durchschnitts-SWS gröﬂer als 3 ist', 
'select gelesenVon, sum(SWS)
from Vorlesungen
group by gelesenVon
having avg(SWS) > 3',
'having
1. evtl. Join der beteiligten Tabellen
2. Selektion der Zeilen (WHERE)
3. Gruppierung
4. Selektion der Gruppen (having)
5. Projektion auf gesuchte Attribute
');


insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 04 GROUP BY (Aggregatfunktionen)',
'Frage 07 Liste Summe der SWS pro C4-Professor, sofern seine Durchschnitts-SWS größer als 3 ist', 
'select gelesenVon, Name, sum(SWS)
from Vorlesungen, Professoren
where gelesenVon = PersNr and Rang = ''C4''
group by gelesenVon, Name
having avg(SWS) > 3',
'.');



insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 05 Teilabfragen/Subqueries',
'Frage 01 Liste alle Prüfungen, die als Ergebnis die Durchschnittsnote haben', 
'select *
from pruefen
where Note = (select round(avg(Note))
              from pruefen)',
'Einfache Teilabfrage (muss  nur einmal ausgeführt werden)
Round (avg(note))
');

insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 05 Teilabfragen/Subqueries',
'Frage 02 Liste alle Professoren (PersNR, Name, Lehrbelastung) zusammen mit ihrer Lehrbelastung', 
'select PersNr, Name, (select sum(SWS) 
                      from Vorlesungen
                      where gelesenVon = PersNr) as Lehrbelastung
from Professoren',
'Korrelierte Teilabfrage
(select Sum(sws) from vorlesungen where ...) as Lehrbelastung)');
 

insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 06 Teilabfragen und Prädikte (ANY, ALL,IN, NOT IN, EXISTS)',
'Frage 01 Liste alle Professoren, die keine Vorlesung halten', 
'select Name
from Professoren
where PersNr not in ( select gelesenVon
                      from Vorlesungen )
                      Alternativ: 
select Name
from Professoren
where not exists ( select *
                   from Vorlesungen
                   where gelesenVon = PersNr )
',
'Wenn Ergebnis der Teilanfrage nicht ein einzelnes Tupel ist, sondern eine Menge von Tupeln
ANY Bedingung muss für irgendein Tupel der Teilabfrage erfüllt sein
ALL Bedingung muss für alle Tupel der Teilabfrage erfüllt sein
IN  Bedingung mit Prädikat IN ist erfüllt, wenn Ergebnismenge der Teilabfrage
    den aktuellen Wert enthält
EXISTS Bedingung ist erfüllt, wenn Ergebnismenge der Teilabfrage nicht leer ist
');


insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 06 Teilabfragen und Prädikte (ANY, ALL,IN, NOT IN, EXISTS)',
'Frage 02 Liste Studenten mit gröﬂter Semesterzahl', 
'select Name
from Studenten
where Semester >= all ( select Semester
                        from Studenten )',
'>= ALL ');


 
insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 07 Mengen (union, minus, intersect, ...)',
'Frage 01 Liste die Vereinigung von Professoren- und Assistenten-Namen', 
'( select Name
  from Assistenten )
union
( select Name
  from Professoren )',
'union');



insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 07 Mengen (union, minus, intersect, ...)',
'Frage 02 Liste die Differenz von Professoren- und Assistenten-Namen', 
'( select Name
  from Assistenten )
minus
( select Name
  from Professoren )',
'minus');
 
insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 07 Mengen (union, minus, intersect, ...)',
'Frage 03 Liste den Durchschnitt von Professoren- und Assistenten-Namen', 
'( select Name from Assistenten )
intersect
( select Name from Professoren )',
'.');


 
insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 08 Datenmanipulation: Insert , Update, Delete',
'Frage 01 Füge Student mit Matrikelnummer und Name ein', 
'insert into Studenten (MatrNr, Name)
            values (28121, ''Archimedes'')',
'insert');

 
 
insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 08 Datenmanipulation: Insert , Update, Delete',
'Frage 02 Alle Studenten sollen die Vorlesung ''Selber Atmen'' hören', 
'insert into hoeren
   select MatrNr, VorlNr
   from Studenten, Vorlesungen
   where Titel = ''Selber Atmen''',
'insert');


insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 08 Datenmanipulation: Insert , Update, Delete',
'Frage 03 Alle Studenten um 10 Tage älter machen', 
'update studenten
set GebDatum = GebDatum + 10',
'update');



insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 08 Datenmanipulation: Insert , Update, Delete',
'Frage 04 Alle Studenten mit Semesterzahlen gröﬂer als 13 löschen', 
'delete from Studenten
   where Semester > 13',
'delete');
 

insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 08 Datenmanipulation: Insert , Update, Delete',
'Frage 05 Niemand soll mehr die Vorlesung ''Selber Atmen'' hören', 
'delete from hoeren
   where vorlnr = 
   (select VorlNr from Vorlesungen
   where Titel = ''Selber Atmen'')',
'.');
 


 
insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 09 Create Views',
'Frage 01 Lege Sicht an für Prüfungen ohne Note', 
'create view pruefenSicht as
   select MatrNr, VorlNr, PersNr
   from pruefen',
'Nicht alle Views/Sichten sind update-fähig, da sich eine Änderung 
ihrer Daten nicht immer auf die Originaltabellen zurückpropagieren läﬂt 
');
 



insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 09 Create Views',
'Frage 02 Lege Sicht an für Studenten mit ihren Professoren', 
'create view StudProf (Sname, Semester, Titel, PName) as
  select s.Name, s.Semester, v.Titel, p.Name
  from Studenten s, hoeren h, Vorlesungen v, Professoren p
  where s.MatrNr = h.MatrNr and h.VorlNr = v.VorlNr
  and v.gelesenVon = p.PersNr',
'.');


insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 09 Create Views',
'Frage 03 Lege Sicht an mit Professoren und ihren Durchschnittsnoten', 
'create view ProfNote (PersNr, Durchschnittsnote) as
  select PersNr, round(avg (Note))
  from pruefen
  group by PersNr',
'.');
 

insert into fragen ( thema, kapitel, frage, antwort, hinweis)
values ( 'SQL','Kapitel 10 Create INDEX ',
'Frage 01 Lege Index an für Professoren Namen', 
'CREATE INDEX PROF_NAME_IDX ON PROFESSOREN (NAME)',
'.'); 

commit;
