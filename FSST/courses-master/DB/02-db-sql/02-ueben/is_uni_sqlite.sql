--
-- anton.hofmann@htl-salzburg.ac.at
-- demo zu sql: is_uni.sqlite
-- db: is_uni
-- user: is_uni
-- pwd: comein

-- einige anmerkungen:
-- -------------------------
--
-- 
-- ==============================================================
-- table: is_professoren                                        
-- ==============================================================
drop table if exists is_professoren;
create table is_professoren (
	persnr               int			not null,
	name                 varchar(30)	not null,
	rang                 char(2),
	raum                 int,
	gebdatum             datetime,
	constraint prof_pk primary key (persnr),
	constraint raum_uq unique (raum)
);

-- ==============================================================
--  table: is_studenten                                          
-- ==============================================================
drop table if exists is_studenten;
create table is_studenten (
	matrnr               int         	not null,
	name                 varchar(30) 	not null,
	semester             int,
	gebdatum             datetime,
	constraint stud_pk primary key (matrnr)
);

-- ==============================================================
--  table: is_vorlesungen                                        
-- ==============================================================
drop table if exists  is_vorlesungen;
create table is_vorlesungen (
	vorlnr               int              not null,
	titel                varchar(30),
	sws                  int,
	gelesenvon           int,

	constraint vorl_pk primary key (vorlnr),

	constraint vorl_prof_fk	foreign key (gelesenvon)
		references is_professoren (persnr) 
		on delete restrict
);


-- ==============================================================
--  table: is_pruefen                                            
-- ==============================================================
drop table if exists is_pruefen;
create table is_pruefen (
	matrnr               int                           not null,
	vorlnr               int                           not null,
	persnr               int,
	note                 int,

	constraint prfg_pk primary key (matrnr, vorlnr)

	constraint prfg_stud_fk	foreign key (matrnr)
		references is_studenten (matrnr) 
		on delete cascade,

	constraint prfg_vorl_fk	foreign key (vorlnr)
		references is_vorlesungen (vorlnr) 
		on delete restrict,

	constraint prfg_prof_fk	foreign key (persnr)
		references is_professoren (persnr) 
		on delete restrict
);

-- ==============================================================
--  table: is_hoeren                                             
-- ==============================================================
drop table if exists is_hoeren;
create table is_hoeren (
	matrnr               int                           not null,
	vorlnr               int                           not null,

	constraint hoer_pk primary key (matrnr, vorlnr),

	constraint hoeren_stud_fk	foreign key (matrnr)
		references is_studenten (matrnr) 
		on delete cascade,

	constraint hoer_vorl_fk	foreign key (vorlnr)
		references is_vorlesungen (vorlnr) 
		on delete cascade

);

		
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

	constraint ass_prof_fk	foreign key (boss)
		references is_professoren (persnr) 
		on delete restrict

);



	
--
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
