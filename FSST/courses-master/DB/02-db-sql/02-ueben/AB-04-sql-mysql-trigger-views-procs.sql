-- sql-mysql-trigger-views-procs.sql

-- !!!!!!!!!!!!!!!
-- Vorbedingungen
-- !!!!!!!!!!!!!!!

-- als root folg. Rechte dem user is_uni geben!!!! 
-- create view, SUPER, execute, 
-- create routine, alter routine
-- 

use is_uni;
-- ----------------------------------------------------
-- Views
-- ----------------------------------------------------
create or replace view v_notenliste as
select s.matrnr, s.name stud_name,
           v.vorlnr,v.titel, p.name prof_name, note
from is_studenten s, is_vorlesungen v, is_professoren p,
           is_pruefen prfg
where
          prfg.matrnr= s.matrnr and
          prfg.vorlnr= v.vorlnr and
          prfg.persnr= p.persnr;


Select * from v_notenliste;



create or replace view v_prof_hat_viele_studenten
as
select persnr, name, count(*) as anz_studenten
from is_professoren p,
     is_vorlesungen v,
     is_hoeren h
     where p.persnr = v.gelesenvon
     and v.vorlnr = h.vorlnr
group by p.persnr, p.name
    having count(*) > 4; -- die mehr als 4 Hoerer haben


select * from v_prof_hat_viele_studenten;


-- ----------------------------------------------------
-- stored proc
-- ----------------------------------------------------

create procedure sp_pruefungen()
    select s.name, v.titel, p.note
    from is_vorlesungen v, is_pruefen p, is_studenten s
    where p.matrnr=s.matrnr and p.vorlnr=v.vorlnr;
		

call sp_pruefungen();


-- ----------------------------------------------------
-- cursor
-- ----------------------------------------------------
-- kopiert Daten aus der View v_prof_hat_viele_studenten;
-- in die Tabelle is_prof_hat_viele_studenten und fügt zudem
-- das Datum des Kopierens hinzu.
--
-- Beachte den Primary key (persnr,  create_date)
-- Dadurch kann dieser Vorgang nur 1 mal pro Tag erfolgreich 
-- durchgeführt werden

drop table if exists is_prof_hat_viele_studenten;

create table is_prof_hat_viele_studenten (
  persnr    integer,
  name  varchar(30),
  anz_stud int,
  create_date date,
  constraint pk_is_prof_viele_studenten primary key (persnr, create_date)
);

select * from is_prof_hat_viele_studenten;

delimiter // 

CREATE PROCEDURE sp_prof_mit_vielen_studenten_speichern()
BEGIN
DECLARE done INT DEFAULT 0;
DECLARE vpersnr INT;
DECLARE vname varchar(30);
DECLARE vanz_studenten INT;
DECLARE cur1 CURSOR FOR select persnr, name, anz_studenten from v_prof_hat_viele_studenten;
DECLARE CONTINUE HANDLER FOR SQLSTATE '02000' SET done = 1;    -- NOT FOUND

OPEN cur1;
WHILE done = 0 DO
	FETCH cur1 INTO vpersnr, vname, vanz_studenten;
	IF done = 0 THEN
		INSERT INTO is_uni.is_prof_hat_viele_studenten values (vpersnr,vname, vanz_studenten, CURDATE());
	END IF;
END WHILE;
CLOSE cur1;
END
//

delimiter ;


call sp_prof_mit_vielen_studenten_speichern();

select * from is_prof_hat_viele_studenten;





-- ----------------------------------------------------
-- trigger
-- ----------------------------------------------------
-- Vorbedingung: Der user, der den Trigger ausführt muss das 
--      GLOBALE RECHT SUPER haben!
--      als user: root
-- 		GRANT SUPER ON *.* TO 'is_uni'@'localhost';
-- 
-- Beispiel: in einer Tabelle zum Speichern von usern soll das Passwort 
--      automatisch (also per Trigger) verschlüsselt gespeichert werden.
--

drop table if exists is_user;

create table is_user (
    name varchar(40),
    pw varchar(40),
    pw_verschluesselt varchar(40)
);

select * from is_user;
describe is_user;


drop trigger if exists trg_bi_user_insert;


delimiter //

create trigger trg_bi_user_insert
before insert on is_user
for each row
begin
 set NEW.pw_verschluesselt=  md5(NEW.pw_verschluesselt);
end
//

delimiter ;


insert into is_user values ('Max Mustermann','comein','comein');

select * from is_user;


-- Beispiel: Eine Degradierung eines Professors, d.h. von C4 auf C3 bzw.
--          von C3 auf C2 darf nicht möglich sein.
--
--          Hier können Trigger gute Diense leisten.

delimiter //

Create trigger trg_bu_keinedegradierung
Before update on is_professoren
For each row
Begin
        if OLD.rang= 'C4' then
                SET NEW.rang='C4';
        end if;

        if OLD.rang= 'C3' and NEW.rang= 'C2' then
                SET NEW.rang='C3';
        end if;

        if NEW.rang is NULL then
                SET NEW.rang= OLD.rang;
        end if;
End
//

delimiter ;


-- teste trigger
select * from is_professoren where rang= 'C4';

-- Sollte das folg. Update nicht funktionieren (bei mysql-workbnch:
-- Lösung:
-- You are using safe update mode and you tried to update a table without 
-- a WHERE that uses a KEY column To disable safe mode, toggle the option in 
-- Preferences -> SQL Editor -> Query Editor and reconnect.

update is_professoren
set rang= 'C3'
where rang='C4';

commit;

select * from is_professoren where rang= 'C4';


-- nun löschen wir den Trigger und versuchen dann die Degradierung
drop trigger trg_bu_keinedegradierung;


update is_professoren
set rang= 'C3'
where rang='C4';
commit;

select * from is_professoren where rang= 'C4';

-- wiederherstellung
update is_professoren
set rang= 'C4'
where name in ('sokrates', 'russel', 'curie','kant');

select * from is_professoren where rang= 'C4';

commit;



-- -----------------------------------------------------
-- Der folgende Trigger Befördert die Professoren, die 
-- viele Studenten haben. Siehe v_prof_hat_viele_studenten
-- -----------------------------------------------------

delimiter //

create trigger trg_ai_befoerderung -- definiere den Trigger befoerderung
after insert on is_hoeren          -- nach insert bei hoeren
for each row
begin
  update is_professoren set rang='C4' -- befoerdere Professor nach C4
  where persnr in                     -- falls seine Personalnummer in
    (select persnr                    -- der Menge der Personalnummern liegt
    from v_prof_hat_viele_studenten
    where anz_studenten > 6);
end
//

delimiter ;



-- ----------------------------------------------------
-- Der System-Katalog (DataDictionary)
-- ----------------------------------------------------
-- Alle Tabellen
SELECT table_name, table_type, engine
FROM information_schema.tables
WHERE table_schema = 'is_uni'
ORDER BY table_name DESC;

desc information_schema.tables;

-- Alle Views
SELECT
V.TABLE_SCHEMA,
V.TABLE_NAME,
V.VIEW_DEFINITION
FROM
INFORMATION_SCHEMA.VIEWS V;


-- Alle Stor. Proc
SELECT
    R.ROUTINE_SCHEMA,
    R.ROUTINE_NAME,
    R.ROUTINE_TYPE,
    R.ROUTINE_BODY,
    R.ROUTINE_DEFINITION,
    R.SQL_PATH,
    R.EXTERNAL_NAME,
    R.EXTERNAL_LANGUAGE,
    R.CREATED, R.LAST_ALTERED,
    R.DEFINER
FROM
INFORMATION_SCHEMA.ROUTINES R;


-- ALle Trigger
SELECT
   T.TRIGGER_NAME, T.EVENT_MANIPULATION, T.TRIGGER_SCHEMA, T.EVENT_OBJECT_TABLE,
   T.ACTION_STATEMENT
FROM INFORMATION_SCHEMA.TRIGGERS T;


-- -----------------------------------------------------------------------------------
-- Cleanup
-- -----------------------------------------------------------------------------------

Drop view v_notenliste;
Drop view v_prof_hat_viele_studenten;
drop procedure sp_pruefungen;
drop table if exists is_prof_hat_viele_studenten;
drop procedure sp_prof_mit_vielen_studenten_speichern;
drop table if exists is_user;
drop trigger if exists trg_bi_user_insert;
drop trigger if exists trg_bu_keinedegradierung;
drop trigger if exists trg_ai_befoerderung;
