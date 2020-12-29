--
-- anton.hofmann@htl-salzburg.ac.at
-- demo zu sql: is_way.sql
-- db: is_way
-- user: is_way oder is_way@localhost
-- pwd: comein
-- als root ausführen

drop database if exists is_way;

create database if not exists is_way;
grant create,drop, references, select,insert,update,delete on is_way.* to is_way@localhost identified by 'comein';

use is_way;


-- ==============================================================
-- table: way                                        
-- ==============================================================
drop table if exists way;
CREATE TABLE way (
	id INT NOT NULL AUTO_INCREMENT ,
	cr_date TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ,
	lat VARCHAR( 80 ) NOT NULL ,
	lng VARCHAR( 80 ) NOT NULL ,
	title VARCHAR( 80 ) NOT NULL ,
	description VARCHAR( 80 ) NOT NULL ,
	icon VARCHAR( 80 ) NOT NULL ,
	PRIMARY KEY ( id )
) ENGINE = innodb;

	
--
commit;
--

insert into way (lat,lng,title,description, icon)
values ('47.800038', '13.044499',
'Anton Hofmann', 
'<a href="http://www.fh-salzburg.ac.at">zur FH</a> <br/>(to hide: click icon again)',
'hofa.jpg');

insert into way (lat,lng,title,description, icon)
values ('47.799583', '13.041857',
'Anton Hofmann', 
'<a href="http://www.htl-salzburg.ac.at">zur HTL</a> <br/>(to hide: click icon again)',
'hofa.jpg');

insert into way (lat,lng,title,description, icon)
values ('47.800661', '13.042792',
'Anton Hofmann', 
'<a href="http://www.uni-salzburg.ac.at">zur Uni</a> <br/>(to hide: click icon again)',
'hofa.jpg');

	
--
commit;
--
