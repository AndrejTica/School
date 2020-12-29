--
-- anton.hofmann@htl-salzburg.ac.at
-- demo zu sql: is_registration.sql
-- db: is_registration
-- user: is_registration
-- pwd: comein

-- quelle: https://codewithawa.com/posts/complete-user-registration-system-using-php-and-mysql-database

-- -------------------------------------------------------------------------------------------
-- Dieses sql-script als root ausführen
-- -------------------------------------------------------------------------------------------

drop database if exists is_registration;

create database if not exists is_registration;
grant create,drop, references, select,insert,update,delete on is_registration.* to is_registration@localhost identified by 'comein';

use is_registration;

-- ==============================================================
-- table: users                                      
-- ==============================================================
drop table if exists `users`;

CREATE TABLE `users` (
  `id` 			int(11) 			NOT NULL AUTO_INCREMENT PRIMARY KEY,
  `username` 	varchar(100) 	NOT NULL,
  `email` 		varchar(100) 	NOT NULL,
  `password` 	varchar(100) 	NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



commit;
