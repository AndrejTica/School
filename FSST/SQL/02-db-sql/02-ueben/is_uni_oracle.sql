-- 
-- Anton.Hofmann
-- DEMO zu SQL: is_uni.sql
-- 
-- start is_uni.sql 
--
-- 1. Tabellen anlegen 
-- 2. Synonyme anlegen
-- 	(Notwendig ist: grant create synonym to USERNAME;)
-- 3. Daten einlesen
-- 
-- --------------------------------------------------------------
--
rem set heading off
rem set define on

-- -------------------
-- 1. Tabellen anlegen
-- ------------------- 
 DROP TABLE IS_hoeren;
 DROP TABLE IS_voraussetzen;
 DROP TABLE IS_pruefen;
 DROP TABLE IS_Assistenten ;
 DROP TABLE IS_Vorlesungen ;
 DROP TABLE IS_Professoren ;
 DROP TABLE IS_Studenten ;
 commit;

-- ==============================================================
-- Table: IS_PROFESSOREN                                        
-- ==============================================================
create table IS_PROFESSOREN (
   PERSNR               NUMBER                           not null,
   NAME                 VARCHAR2(30)                     not null,
   RANG                 CHAR(2),
   RAUM                 NUMBER,
   GEBDATUM             DATE,
	constraint PROF_PK primary key (PERSNR),
	constraint RAUM_UQ unique (RAUM)
);

-- ==============================================================
--  Table: IS_STUDENTEN                                          
-- ==============================================================
create table IS_STUDENTEN (
   MATRNR               NUMBER                           not null,
   NAME                 VARCHAR2(30)                     not null,
   SEMESTER             NUMBER,
   GEBDATUM             DATE,
	constraint STUD_PK primary key (MATRNR)
);

-- ==============================================================
--  Table: IS_VORLESUNGEN                                        
-- ==============================================================
create table IS_VORLESUNGEN (
   VORLNR               NUMBER                           not null,
   TITEL                VARCHAR2(30),
   SWS                  NUMBER,
   GELESENVON           NUMBER,
	constraint VORL_PK primary key (VORLNR),
	constraint VORL_PROF_FK foreign key (GELESENVON)
   	references IS_PROFESSOREN (PERSNR)
);

-- ==============================================================
--  Table: IS_PRUEFEN                                            
-- ==============================================================
create table IS_PRUEFEN (
   MATRNR               NUMBER                           not null,
   VORLNR               NUMBER                           not null,
   PERSNR               NUMBER,
   NOTE                 NUMBER(2,1),
	constraint PRFG_PK primary key (MATRNR, VORLNR),
	constraint PRFG_STUD_FK foreign key (MATRNR)
   	references IS_STUDENTEN (MATRNR)on delete cascade,
	constraint PRFG_VORL_FK foreign key (VORLNR)
   	references IS_VORLESUNGEN (VORLNR),
	constraint PRFG_PROF_FK foreign key (PERSNR)
   	references IS_PROFESSOREN (PERSNR)
);

-- ==============================================================
--  Table: IS_HOEREN                                             
-- ==============================================================
create table IS_HOEREN (
   MATRNR               NUMBER                           not null,
   VORLNR               NUMBER                           not null,
	constraint HOER_PK primary key (MATRNR, VORLNR),
	constraint HOER_STUD_FK foreign key (MATRNR)
   	references IS_STUDENTEN (MATRNR) on delete cascade,
	constraint HOER_VORL_FK foreign key (VORLNR)
   	references IS_VORLESUNGEN (VORLNR) on delete cascade
);

-- ==============================================================
--  Table: IS_VORAUSSETZEN                                       
-- ==============================================================
create table IS_VORAUSSETZEN (
   VORGAENGER           NUMBER                           not null,
   NACHFOLGER           NUMBER                           not null,
	constraint VORAUS_PK primary key (VORGAENGER, NACHFOLGER),
	constraint VORAUS_VORLVORGAENGER_FK foreign key (VORGAENGER)
   	references IS_VORLESUNGEN (VORLNR)on delete cascade,
	constraint VORAUS_VORLNACHFOLGER_FK foreign key (NACHFOLGER)
   	references IS_VORLESUNGEN (VORLNR)on delete cascade
);

-- ==============================================================
--  Table: IS_ASSISTENTEN                                        
-- ==============================================================
create table IS_ASSISTENTEN (
   PERSNR               NUMBER                           not null,
   NAME                 VARCHAR2(30)                     not null,
   FACHGEBIET           VARCHAR2(30),
   BOSS                 NUMBER,
   GEBDATUM             DATE,
	constraint ASS_PK primary key (PERSNR),
	constraint ASS_PROF_FK foreign key (BOSS)
   	references IS_PROFESSOREN (PERSNR)
);
 
 COMMIT;

---
-- 2. Synonyme anlegen
DROP SYNONYM Studenten;
DROP SYNONYM Vorlesungen;
DROP SYNONYM Assistenten;
DROP SYNONYM Professoren;
DROP SYNONYM hoeren;
DROP SYNONYM voraussetzen;
DROP SYNONYM pruefen;

CREATE SYNONYM Studenten FOR IS_Studenten;
CREATE SYNONYM Vorlesungen FOR IS_Vorlesungen;
CREATE SYNONYM Assistenten FOR IS_Assistenten;
CREATE SYNONYM Professoren FOR IS_Professoren;
CREATE SYNONYM hoeren FOR IS_hoeren;
CREATE SYNONYM voraussetzen FOR IS_voraussetzen;
CREATE SYNONYM pruefen FOR IS_pruefen;
--
--
-- 3. Daten einlesen
DELETE Studenten;

DELETE Vorlesungen;

DELETE Assistenten;

DELETE Professoren;

DELETE hoeren;

DELETE voraussetzen;

DELETE pruefen;

COMMIT;

INSERT INTO Studenten(MatrNr, Name, Semester, GebDatum) 
VALUES (24002, 'Xenokrates', 18, to_date('13.12.1940.08:15:00','DD.MM.YYYY.hh:mi:ss')); 
 
INSERT INTO Studenten(MatrNr, Name, Semester, GebDatum) 
VALUES (25403, 'Jonas', 12,to_date('13.11.1980','DD.MM.YYYY')); 
 
INSERT INTO Studenten(MatrNr, Name, Semester, GebDatum) 
VALUES (26120, 'Fichte', 10,to_date('13.09.1980','DD.MM.YYYY')); 

INSERT INTO Studenten(MatrNr, Name, Semester, GebDatum) 
VALUES (26830, 'Aristoxenos', 8,to_date('11.12.1981','DD.MM.YYYY')); 
 
INSERT INTO Studenten(MatrNr, Name, Semester, GebDatum) 
VALUES (27550, 'Schopenhauer', 6,to_date('13.07.1982','DD.MM.YYYY')); 

INSERT INTO Studenten(MatrNr, Name, Semester, GebDatum) 
VALUES (28106, 'Carnap', 3,to_date('07.07.1983','DD.MM.YYYY')); 
 
INSERT INTO Studenten(MatrNr, Name, Semester, GebDatum) 
VALUES (29120, 'Theophrastos', 2,to_date('03.01.1981','DD.MM.YYYY')); 
 
INSERT INTO Studenten(MatrNr, Name, Semester, GebDatum) 
VALUES (29555, 'Feuerbach', 2,to_date('13.03.1982','DD.MM.YYYY')); 
 


INSERT INTO Professoren(PersNr, Name, Rang, Raum, GebDatum) 
VALUES (2125, 'Sokrates', 'C4', 226,to_date('13.12.1960','DD.MM.YYYY')); 

INSERT INTO Professoren(PersNr, Name, Rang, Raum, GebDatum) 
VALUES (2126, 'Russel', 'C4', 232,to_date('13.11.1961','DD.MM.YYYY'));  
 
INSERT INTO Professoren(PersNr, Name, Rang, Raum, GebDatum) 
VALUES (2127, 'Kopernikus', 'C3', 310,to_date('13.03.1962','DD.MM.YYYY')); 
 
INSERT INTO Professoren(PersNr, Name, Rang, Raum, GebDatum) 
VALUES (2133, 'Popper', 'C3', 052,to_date('13.09.1963','DD.MM.YYYY')); 
 
INSERT INTO Professoren(PersNr, Name, Rang, Raum, GebDatum) 
VALUES (2134, 'Augustinus', 'C3', 309,to_date('04.06.1958','DD.MM.YYYY')); 
 
INSERT INTO Professoren(PersNr, Name, Rang, Raum, GebDatum) 
VALUES (2136, 'Curie', 'C4', 036,to_date('03.02.1959','DD.MM.YYYY')); 
 
INSERT INTO Professoren(PersNr, Name, Rang, Raum, GebDatum) 
VALUES (2137, 'Kant', 'C4', 007,to_date('13.11.1961','DD.MM.YYYY')); 
 
 
 
INSERT INTO Assistenten(PersNr, Name, Fachgebiet, Boss, GebDatum) 
VALUES (3002, 'Platon', 'Ideenlehre', 2125,to_date('13.12.1950','DD.MM.YYYY')); 
 
INSERT INTO Assistenten(PersNr, Name, Fachgebiet, Boss, GebDatum) 
VALUES (3003, 'Aristoteles', 'Syllogistik', 2125,to_date('08.08.1972','DD.MM.YYYY')); 
 
INSERT INTO Assistenten(PersNr, Name, Fachgebiet, Boss, GebDatum) 
VALUES (3004, 'Wittgenstein', 'Sprachtheorie', 2126,to_date('21.09.1971','DD.MM.YYYY')); 
 
INSERT INTO Assistenten(PersNr, Name, Fachgebiet, Boss, GebDatum) 
VALUES (3005, 'Rhetikus', 'Planetenbewegung', 2127,to_date('23.02.1971','DD.MM.YYYY')); 
 
INSERT INTO Assistenten(PersNr, Name, Fachgebiet, Boss, GebDatum) 
VALUES (3006, 'Newton', 'Keplersche Gesetze', 2127,to_date('03.12.1972','DD.MM.YYYY')); 
 
INSERT INTO Assistenten(PersNr, Name, Fachgebiet, Boss, GebDatum) 
VALUES (3007, 'Spinoza', 'Gott und Natur', 2134,to_date('13.02.1973','DD.MM.YYYY')); 


 
INSERT INTO Vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (5001, 'Grundzüge', 4, 2137);

INSERT INTO Vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (5041, 'Ethik', 4, 2125);
 
INSERT INTO Vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (5043, 'Erkenntnistheorie', 3, 2126);
 
INSERT INTO Vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (5049, 'Mäeutik', 2, 2125);
 
INSERT INTO Vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (4052, 'Logik', 4, 2125);
 
INSERT INTO Vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (5052, 'Wissenschaftstheorie', 3, 2126); 
 
INSERT INTO Vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (5216, 'Bioethik', 2, 2126); 
 
INSERT INTO Vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (5259, 'Der Wiener Kreis', 2, 2133); 
 
INSERT INTO Vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (5022, 'Glaube und Wissen', 2, 2134); 
 
INSERT INTO Vorlesungen(VorlNr, Titel, SWS, gelesenVon) 
VALUES (4630, 'Die 3 Kritiken', 4, 2137); 


 
insert into hoeren (vorlnr, matrnr) values (5041, 26120);
insert into hoeren (vorlnr, matrnr) values (4052, 26120);
insert into hoeren (vorlnr, matrnr) values (4630, 26120);
 
INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (26120, 5001); 
 
INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (27550, 5001); 
 
INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (27550, 4052); 
 
INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (28106, 5041); 
 
INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (28106, 5052); 
 
INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (28106, 5216); 
 
INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (28106, 5259); 
 
INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (29120, 5001); 

INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (29120, 5041); 

INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (29120, 5049); 

INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (29555, 5022); 

INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (25403, 5022);  
 
INSERT INTO hoeren(MatrNr, VorlNr) 
VALUES (29555, 5001);  
 
 
 
INSERT INTO voraussetzen(Vorgaenger, Nachfolger) 
VALUES (5001, 5041); 
 
INSERT INTO voraussetzen(Vorgaenger, Nachfolger) 
VALUES (5001, 5043); 
 
INSERT INTO voraussetzen(Vorgaenger, Nachfolger) 
VALUES (5001, 5049); 
 
INSERT INTO voraussetzen(Vorgaenger, Nachfolger) 
VALUES (5041, 5216);  

INSERT INTO voraussetzen(Vorgaenger, Nachfolger) 
VALUES (5043, 5052);  

INSERT INTO voraussetzen(Vorgaenger, Nachfolger) 
VALUES (5041, 5052); 
 
INSERT INTO voraussetzen(Vorgaenger, Nachfolger) 
VALUES (5052, 5259); 
 


INSERT INTO pruefen(MatrNr, VorlNr, PersNr, Note) 
VALUES (28106, 5001, 2126, 1.0);

INSERT INTO pruefen(MatrNr, VorlNr, PersNr, Note) 
VALUES (25403, 5041, 2125, 2.0);

INSERT INTO pruefen(MatrNr, VorlNr, PersNr, Note) 
VALUES (27550, 4630, 2137, 2.0);

COMMIT;

