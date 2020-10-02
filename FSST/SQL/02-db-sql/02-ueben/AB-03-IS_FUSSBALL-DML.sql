-- 
-- AB-03-IS_FUSSBALL-DML.sql
-- 
-- Fussball WM 2006 (Deutschland)
--
-- Quellen:
-- http://www3.informatik.tu-muenchen.de/teaching/ws0708/dbsys/exercises/index.shtml
-- Anpassungen: A.Hofmann
--

/*
DROP database if exists is_fussball;
CREATE database if not exists is_fussball
DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;

grant create,drop, references, select,insert,update,delete 
on is_fussball.* to is_fussball@localhost identified by 'comein';


use is_fussball;
*/



use is_fussball;

-- Fragen: Einfache select
-- 1. Liste alle Spieler (Name, Land, Position) aufsteigend sortiert nach Land.

-- 2. Wie viele Länder haben an der WM teilgenommen?

-- 3. Liste alle Stadien (Stadt, AnzPlaetze) sortiert nach Stadt mit mehr als 50000 Plätzen. 

-- 4. Liste alle Stadien (Stadt, AnzPlaetze) sortiert nach AnzPlaetze

-- 5. Wie viele Personen fassen alle Stadien?


-- Fragen: Join
-- 1. Liste alle Spieler (Name, Land, Position), die zumindest 1 Tor erzielt haben.

-- 2. Liste alle Spieler (Name, Land, Position) aufsteigend sortiert nach Land, 
--    die verwarnt (Karte, Minute) wurden.

-- 3. Liste alle Spiele (ManschaftA, ManschaftB) inklusive der 
--    Kampfrichter (Name, Nationalität, Funktion).

-- 4. Liste alle Stadien, die zumindest einmal ausverkauft waren.
 


-- Fragen: Group by
-- 1. Wieviele Zuschauer waren pro Spiel (MannschaftA, ManschaftB) durchschnittlich?
-- 2. Wieviele Zuschauer waren pro Stadion (Stadt, AnzPlaetze, durchschnittl. 
--    Besucher) durchschnittlich?
-- 3. In welchem(n) Spiel(en) vielen die meisten Tore?
-- 4. Liste pro Spiel (MannschaftA, ManschaftB) die Tore (Spieler, Minute, 
--    Spielsituation).


-- Fragen: insert, update, delete
-- 1. siehe sql-file


-- Fragen: Views
-- ACHTUNG:
-- Als root muss der User is_fussball das Rechte create view erhalten.
-- Also a) login as root 
--      b) use is_fussball;
--         grant create view on is_fussball.* to  is_fussball@localhost; 
--      c) relogin as user is_fussball


-- 1.	Erzeuge die View v_spiel ( tag, stadion, zuschauer, MannschaftA, ManschaftB, ToreMannschaftA, ToreMannschaftB, Kampfrichter)

select Tore.Spiel, Spiel.ID, SpielerNr, Minute
from Tore, Spiel
where Spiel.ID = Tore.Spiel
group by SpielerNr;


select SpielerNr, name, Land from Spieler;

-- wieviel Tore hat
select Spiel, Spieler.SpielerNr, Land, sum(Spiel)
from Tore, Spieler
where Spieler.SpielerNr= Tore.SpielerNr
group by Spiel,Spieler.SpielerNr,Land;

drop view v_land_tore;

create view v_land_tore (spiel, land, tore) as
select Tore.Spiel,  Spieler.Land, count(Tore.Spiel)
from Tore, Spieler
where Spieler.SpielerNr= Tore.SpielerNr
group by Tore.Spiel,Spieler.Land;

select * from v_land_tore
order by spiel;

select * from leitet;


drop view v_spiel;

create View v_spiel ( tag, stadion, zuschauer, MannschaftA, ManschaftB, 
ToreMannschaftA, ToreMannschaftB, Kampfrichter) as 
select Spiel.tag, Spiel.Stadion, Spiel.Zuschauer,
Spiel.MannschaftA, Spiel.MannschaftB,
IFNULL((select v_land_tore.Tore from v_land_tore where v_land_tore.Land= Spiel.MannschaftA 
and Spiel.ID= v_land_tore.spiel ),0) ,
IFNULL((select v_land_tore.Tore from v_land_tore where v_land_tore.Land= Spiel.MannschaftB
and Spiel.ID= v_land_tore.spiel),0) ,
Kampfrichter.name
from Spiel,leitet, Kampfrichter
where Spiel.ID= leitet.SpielID and
Kampfrichter.KRID= leitet.KRID and
leitet.Funktion='Referee';


select * from v_spiel;

