-- -----------------------------------------------------------------------------
-- is_googlemap.sql
-- -----------------------------------------------------------------------------
-- googlemaps, xml, mysql, php
-- 
-- execute sql script as user root 
--

drop database if exists is_googlemap;

create database if not exists is_googlemap;
grant create,drop, references, select,insert,update,delete on is_googlemap.* to is_googlemap@localhost identified by 'comein';

use is_googlemap;


-- ==============================================================
-- table: markers
-- ==============================================================
drop table if exists markers;
CREATE TABLE `markers` (
`id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY ,
`name` VARCHAR( 60 ) NOT NULL ,
`address` VARCHAR( 80 ) NOT NULL ,
`lat` FLOAT( 10, 6 ) NOT NULL ,
`lng` FLOAT( 10, 6 ) NOT NULL ,
`type` VARCHAR( 30 ) NOT NULL
) ENGINE = MYISAM ;


INSERT INTO `markers` (`name`, `address`, `lat`, `lng`, `type`) VALUES ('Pan Africa Market', '1521 1st Ave, Seattle, WA', '47.608941', '-122.340145', 'restaurant');
INSERT INTO `markers` (`name`, `address`, `lat`, `lng`, `type`) VALUES ('Buddha Thai & Bar', '2222 2nd Ave, Seattle, WA', '47.613591', '-122.344394', 'bar');
INSERT INTO `markers` (`name`, `address`, `lat`, `lng`, `type`) VALUES ('The Melting Pot', '14 Mercer St, Seattle, WA', '47.624562', '-122.356442', 'restaurant');
INSERT INTO `markers` (`name`, `address`, `lat`, `lng`, `type`) VALUES ('Ipanema Grill', '1225 1st Ave, Seattle, WA', '47.606366', '-122.337656', 'restaurant');
INSERT INTO `markers` (`name`, `address`, `lat`, `lng`, `type`) VALUES ('Sake House', '2230 1st Ave, Seattle, WA', '47.612825', '-122.34567', 'bar');
INSERT INTO `markers` (`name`, `address`, `lat`, `lng`, `type`) VALUES ('Crab Pot', '1301 Alaskan Way, Seattle, WA', '47.605961', '-122.34036', 'restaurant');
INSERT INTO `markers` (`name`, `address`, `lat`, `lng`, `type`) VALUES ("Mama 's Mexican Kitchen", '2234 2nd Ave, Seattle, WA', '47.613975', '-122.345467', 'bar');
INSERT INTO `markers` (`name`, `address`, `lat`, `lng`, `type`) VALUES ('Wingdome', '1416 E Olive Way, Seattle, WA', '47.617215', '-122.326584', 'bar');
INSERT INTO `markers` (`name`, `address`, `lat`, `lng`, `type`) VALUES ('Piroshky Piroshky', '1908 Pike pl, Seattle, WA', '47.610127', '-122.342838', 'restaurant');
