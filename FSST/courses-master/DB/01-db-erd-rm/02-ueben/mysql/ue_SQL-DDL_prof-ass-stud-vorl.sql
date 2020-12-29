-- ÜBUNG: ue_SQL-DDL_prof-ass-stud-vorl.sql
-- ----------------------------------------------------------------
-- ahofmann, 2013
--
-- dieses SQL-Skript erzeugt:
-- db: informatik
-- user: informatik@localhost
-- pwd: comein
-- table: is_professoren, is_assistenten
-- PK <-> FK Beziehungen
-- fügt Daten ein


-- AUFGABE 01: 1:N Beziehungen
-- ----------------------------------------------------------------
-- 1.) dieses SQL-skript als root ausühren
-- 2.) Erstellen Sie ein ähnliches Skript zu
-- 		Jeder Schueler ist einer Abteilung zugeordnet
--		Jeder Abteilung sind mehrere Schueler zugeordnet
-- 		ALSO: Schueler  N:1  Abteilung
-- 

-- AUFGABE 02: M:N - Beziehungen
-- ----------------------------------------------------------------
-- 1.) Erweitern Sie dieses Skript, für
--		Studenten M:N Vorlesungen 
--


-- ==============================================================
-- db erzeugen
-- ==============================================================
drop database if exists informatik;
create database if not exists informatik;

-- ==============================================================
-- user erzeugen
-- ==============================================================
grant create,drop,references, select,insert,update,delete on informatik.* to informatik@localhost identified by 'comein';

use informatik;


-- ==============================================================
-- table: is_professoren                                        
-- ==============================================================
drop table if exists is_professoren;
create table is_professoren (
   persnr               int                           not null,
   name                 varchar(30)                     not null,
   rang                 char(2),
   raum                 int,
   gebdatum             datetime,
	constraint prof_pk primary key (persnr),
	constraint raum_uq unique (raum)
)
ENGINE=InnoDB
ROW_FORMAT=default;


-- ==============================================================
--  table: is_assistenten                                        
-- ==============================================================
drop table if exists is_assistenten;
create table is_assistenten (
   persnr               int                           not null,
   name                 varchar(30)                     not null,
   fachgebiet           varchar(30),
   boss                 int,
   gebdatum             datetime,
	constraint ass_pk primary key (persnr),
	index boss_idx(boss)
)
ENGINE=InnoDB
ROW_FORMAT=default;
 
alter table is_assistenten 
	add constraint ass_prof_fk 
	foreign key boss_idx(boss) references is_professoren(persnr)
	on delete restrict;


insert into is_professoren(persnr, name, rang, raum, gebdatum) 
values (2125, 'sokrates', 'c4', 226, '1940-12-13'  ); 

insert into is_professoren(persnr, name, rang, raum, gebdatum) 
values (2126, 'russel', 'c4', 232, '1942-12-13'  );  
 
insert into is_professoren(persnr, name, rang, raum, gebdatum) 
values (2127, 'kopernikus', 'c3', 310, '1941-02-14'  ); 
 
insert into is_professoren(persnr, name, rang, raum, gebdatum) 
values (2133, 'popper', 'c3', 052, '1940-12-17'  ); 
 
insert into is_professoren(persnr, name, rang, raum, gebdatum) 
values (2134, 'augustinus', 'c3', 309, '1940-12-24'  ); 
 
insert into is_professoren(persnr, name, rang, raum, gebdatum) 
values (2136, 'curie', 'c4', 036, '1939-01-01'  ); 
 
insert into is_professoren(persnr, name, rang, raum, gebdatum) 
values (2137, 'kant', 'c4', 007, '1940-07-13'  ); 
 
 
 
insert into is_assistenten(persnr, name, fachgebiet, boss, gebdatum) 
values (3002, 'platon', 'ideenlehre', 2125, '1960-12-13'  ); 
 
insert into is_assistenten(persnr, name, fachgebiet, boss, gebdatum) 
values (3003, 'aristoteles', 'syllogistik', 2125, '1962-12-13'  ); 
 
insert into is_assistenten(persnr, name, fachgebiet, boss, gebdatum) 
values (3004, 'wittgenstein', 'sprachtheorie', 2126, '1961-12-24'  ); 
 
insert into is_assistenten(persnr, name, fachgebiet, boss, gebdatum) 
values (3005, 'rhetikus', 'planetenbewegung', 2127, '1960-06-13'  ); 
 
insert into is_assistenten(persnr, name, fachgebiet, boss, gebdatum) 
values (3006, 'newton', 'keplersche gesetze', 2127, '1963-12-13'  ); 
 
insert into is_assistenten(persnr, name, fachgebiet, boss, gebdatum) 
values (3007, 'spinoza', 'gott und natur', 2134, '1964-12-11'  ); 

commit;



-- AUFGABE 02: M:N - Beziehungen
-- ----------------------------------------------------------------
-- 1.) Erweitern Sie dieses Skript, für
--		Studenten M:N Vorlesungen 
--


