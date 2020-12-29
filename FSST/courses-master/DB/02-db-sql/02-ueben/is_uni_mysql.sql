--
-- anton.hofmann@htl-salzburg.ac.at
-- demo zu sql: is_uni_mysql.sql
-- db: is_uni
-- user: is_uni
-- pwd: comein

-- einige anmerkungen:
--
-- THEMA: MYSQL mit innoDB
-- -------------------------
-- XAMPP/mysql/bin/my.cnf
-- notepad ffnen und my.cnf hineinziehen
-- #skip-innodb 
-- # Uncomment the following if you are using InnoDB tables 
-- innodb_data_home_dir = C:/Programme/xampp/mysql/data/
-- innodb_data_file_path = ibdata1:10M:autoextend 
-- innodb_log_group_home_dir = C:/Programme/xampp/mysql/data/
-- innodb_log_arch_dir = C:/Programme/xampp/mysql/data/
-- # You can set .._buffer_pool_size up to 50 - 80 % 
-- # of RAM but beware of setting memory usage too high 
-- #set-variable = innodb_buffer_pool_size=16M 
-- #set-variable = innodb_additional_mem_pool_size=2M 
-- # Set .._log_file_size to 25 % of buffer pool size 
-- #set-variable = innodb_log_file_size=5M 
-- #set-variable = innodb_log_buffer_size=8M 
-- #innodb_flush_log_at_trx_commit=1 
-- #set-variable = innodb_lock_wait_timeout=50 
--
-- 
-- THEMA: Mysql mit XAMPP nutzen
-- ------------------------------
-- * xampp installieren
-- * security-check durchfhren !!!!!!
-- *.http://localhost/phpmyadmin/
-- * als root
-- * User anlegen: (Rechte)
-- * Datenbank anlegen
-- * Dem User alle Rechte auf die Datenbank geben
-- * so, jetzt haben wir fr eine neue datebank einen User, der nur auf diese
--   dDatenbank vollen Zugriff hat
-- * als user
-- * SQL-Fenster: SQL-befehle eingeben
--   zB: create table is_professoren .......insert into ........
-- * fertig
-- -------------------------------------------------------------------------------------------
--
drop database if exists is_uni;

create database if not exists is_uni;
grant create,drop, references, select,insert,update,delete on is_uni.* to is_uni@localhost identified by 'comein';

use is_uni;

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
--  table: is_studenten                                          
-- ==============================================================
drop table if exists is_studenten;
create table is_studenten (
   matrnr               int                           not null,
   name                 varchar(30)                     not null,
   semester             int,
   gebdatum             datetime,
	constraint stud_pk primary key (matrnr)
)
ENGINE=InnoDB
ROW_FORMAT=default;

-- ==============================================================
--  table: is_vorlesungen                                        
-- ==============================================================
drop table if exists  is_vorlesungen;
create table is_vorlesungen (
   vorlnr               int                           not null,
   titel                varchar(30),
   sws                  int,
   gelesenvon           int,
	constraint vorl_pk primary key (vorlnr) ,
	index gelesenvon_idx(gelesenvon)
)
ENGINE=InnoDB
ROW_FORMAT=default;

alter table is_vorlesungen add constraint vorl_prof_fk 
	foreign key gelesenvon_idx(gelesenvon) 
	references is_professoren(persnr);


-- ==============================================================
--  table: is_pruefen                                            
-- ==============================================================
drop table if exists is_pruefen;
create table is_pruefen (
   matrnr               int                           not null,
   vorlnr               int                           not null,
   persnr               int,
   note                 int,
	constraint prfg_pk primary key (matrnr, vorlnr),
	index matrnr_idx(matrnr),
	index vorlnr_idx(vorlnr),
	index persnr_idx(persnr)
)
ENGINE=InnoDB
ROW_FORMAT=default;

alter table is_pruefen 
	add constraint prfg_stud_fk
	foreign key  matrnr_idx(matrnr) references is_studenten(matrnr)
		on delete cascade,
	add constraint prfg_vorl_fk
	foreign key  vorlnr_idx(vorlnr) references is_vorlesungen(vorlnr)
		on delete REstrict,
	add constraint prfg_prof_fk
	foreign key  persnr_idx(persnr) references is_professoren(persnr)
		on delete REstrict;

-- ==============================================================
--  table: is_hoeren                                             
-- ==============================================================
drop table if exists is_hoeren;
create table is_hoeren (
   matrnr               int                           not null,
   vorlnr               int                           not null,
	constraint hoer_pk primary key (matrnr, vorlnr),
	
	index matrnr_idx(matrnr),
	index vorlnr_idx(vorlnr)
)
ENGINE=InnoDB
ROW_FORMAT=default;

alter table is_hoeren 
	add constraint hoer_stud_fk
	foreign key  matrnr_idx(matrnr) references is_studenten(matrnr)
		on delete cascade,
	add constraint hoer_vorl_fk
	foreign key  vorlnr_idx(vorlnr) references is_vorlesungen(vorlnr)
		on delete cascade;
		
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


	
--
commit;
--

insert into is_studenten(matrnr, name, semester, gebdatum) 
values (24002, 'xenokrates', 18, '1970-12-13'); 
 
insert into is_studenten(matrnr, name, semester, gebdatum) 
values (25403, 'jonas', 12, '1969-05-10'  ); 
 
insert into is_studenten(matrnr, name, semester, gebdatum) 
values (26120, 'fichte', 10, '1940-12-13'  ); 

insert into is_studenten(matrnr, name, semester, gebdatum) 
values (26830, 'aristoxenos', 8, '1968-12-13'  ); 
 
insert into is_studenten(matrnr, name, semester, gebdatum) 
values (27550, 'schopenhauer', 6, '1967-11-13'  ); 

insert into is_studenten(matrnr, name, semester, gebdatum) 
values (28106, 'carnap', 3, '1969-06-13'  ); 
 
insert into is_studenten(matrnr, name, semester, gebdatum) 
values (29120, 'theophrastos', 2, '1970-12-13'  ); 
 
insert into is_studenten(matrnr, name, semester, gebdatum) 
values (29555, 'feuerbach', 2, '1971-11-13'  ); 
 


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


 
insert into is_vorlesungen(vorlnr, titel, sws, gelesenvon) 
values (5001, 'grundzüge', 4, 2137);

insert into is_vorlesungen(vorlnr, titel, sws, gelesenvon) 
values (5041, 'ethik', 4, 2125);
 
insert into is_vorlesungen(vorlnr, titel, sws, gelesenvon) 
values (5043, 'erkenntnistheorie', 3, 2126);
 
insert into is_vorlesungen(vorlnr, titel, sws, gelesenvon) 
values (5049, 'Mäeutik', 2, 2125);
 
insert into is_vorlesungen(vorlnr, titel, sws, gelesenvon) 
values (4052, 'logik', 4, 2125);
 
insert into is_vorlesungen(vorlnr, titel, sws, gelesenvon) 
values (5052, 'wissenschaftstheorie', 3, 2126); 
 
insert into is_vorlesungen(vorlnr, titel, sws, gelesenvon) 
values (5216, 'bioethik', 2, 2126); 
 
insert into is_vorlesungen(vorlnr, titel, sws, gelesenvon) 
values (5259, 'der wiener kreis', 2, 2133); 
 
insert into is_vorlesungen(vorlnr, titel, sws, gelesenvon) 
values (5022, 'glaube und wissen', 2, 2134); 
 
insert into is_vorlesungen(vorlnr, titel, sws, gelesenvon) 
values (4630, 'die 3 kritiken', 4, 2137); 


 
insert into is_hoeren (vorlnr, matrnr) values (5041, 26120);
insert into is_hoeren (vorlnr, matrnr) values (4052, 26120);
insert into is_hoeren (vorlnr, matrnr) values (4630, 26120);
 
insert into is_hoeren(matrnr, vorlnr) 
values (26120, 5001); 
 
insert into is_hoeren(matrnr, vorlnr) 
values (27550, 5001); 
 
insert into is_hoeren(matrnr, vorlnr) 
values (27550, 4052); 
 
insert into is_hoeren(matrnr, vorlnr) 
values (28106, 5041); 
 
insert into is_hoeren(matrnr, vorlnr) 
values (28106, 5052); 
 
insert into is_hoeren(matrnr, vorlnr) 
values (28106, 5216); 
 
insert into is_hoeren(matrnr, vorlnr) 
values (28106, 5259); 
 
insert into is_hoeren(matrnr, vorlnr)  
values (28106, 5001);  

insert into is_hoeren(matrnr, vorlnr) 
values (29120, 5001); 

insert into is_hoeren(matrnr, vorlnr) 
values (29120, 5041); 

insert into is_hoeren(matrnr, vorlnr) 
values (29120, 5049); 

insert into is_hoeren(matrnr, vorlnr) 
values (29555, 5022); 

insert into is_hoeren(matrnr, vorlnr) 
values (25403, 5022);  
 
insert into is_hoeren(matrnr, vorlnr) 
values (29555, 5001);  
 
 
 


insert into is_pruefen(matrnr, vorlnr, persnr, note) 
values (28106, 5001, 2126, 1.0);

insert into is_pruefen(matrnr, vorlnr, persnr, note) 
values (25403, 5041, 2125, 2.0);

insert into is_pruefen(matrnr, vorlnr, persnr, note) 
values (27550, 4630, 2137, 2.0);



commit;
-- end of script


/* ***********************************************************************
--========================================================
-- Kontrolle der wartung der referentiellen integritaet
-- is_hoeren hat on delete cascade
-- is_pruefen hat on delete cascade bei matrnr
-- d.h. wir löschen einen Studenten, der einen Eintrag in
--      is_pruefen und in is_hoeren hat 
--      Wir werden sehen, dass dies der Student carnap ist
-- ========================================================

-- vorlesungsverzeichnis
select s.name, v.titel from is_studenten s, is_hoeren h, is_vorlesungen v
where 	h.matrnr=s.matrnr and
	h.vorlnr=v.vorlnr;

-- pruefungsverzeichnis	
select s.matrnr, s.name as student, p.note, prof.name as professor, v.titel,v.vorlnr
from is_studenten s, is_pruefen p, is_vorlesungen v, is_professoren prof
where 	p.matrnr=s.matrnr and
	p.persnr=prof.persnr and
	p.vorlnr=v.vorlnr;
	

--der student carnap hat die vorlesung "grundzge" gehoert und auch eine
-- pruefung darueber gemacht.
-- lsche den student carnap
--    frage: in welchen tabellen wird was gelscht?
	
delete from is_studenten
where name="carnap"


-- GEGENPROBE
-- frage: warum funktioniert folg. anweisung nicht?
delete from is_professoren
where name ="sokrates";


-- kontrolle
select a.name as assistent, p.name as professor 
from is_assistenten a, is_professoren p
where a.boss=p.persnr


* ***************************************/
