# Erste Schulwoche FSST5:DB
---------------------------------------------------
A.Hofmann, 2016, Gitlab/ERSTE-SCHULWOCHE


## 1. AUFGABE: SQL (UE)
---------------------------------------------------
* LIES: DB/02-db-sql/01-lernen/01-db-sql.pdf
	* Inner Join
	* Aggregate (group by having)
* Beantworte:
	* DB/02-db-sql/02-ueben/AB-03-IS_FUSSBALL-DML.odt
	* DB/02-db-sql/02-ueben/AB-03-IS_FUSSBALL-DML.sql


## 2. Fragen: ERD
---------------------------------------------------

~~~
﻿mab-erd-is_schule:

1. (3) is_schule
--------------------------------------------------------------
	Gegeben sind folg. Tabellen
	`is_schule`.`Schueler`, 
	`is_schule`.`Lehrer`, 
	`is_schule`.`Abteilungen`, 
	`is_schule`.`Schule`, 
	`is_schule`.`Lehrer_has_Abteilungen`, 
	`is_schule`.`Lehrer_has_Schueler`

1.1. (3) Zeichne das dazugehörige ERD 
	(inkl. Kardinalitäten der Beziehungen)
	Lehrer unterrichten Schüler.
	Schüler sind höchstens einer Abteilung zugeordnet. 
	Lehrer können in mehreren Abteilungen unterrichten. 
	Abteilungen, Lehrer und Schüler werden Schulen zugeordnet.


2. (3) is_schule  (reorg)
--------------------------------------------------------------
	Bei einer Reorganisation werden folg. Tabellen eingeführt:
	Jahrgang (name)
	Unterrichtsfach (name, inhalte)

2.1(3)	Lehrer unterrichten Schueler wird reorganisiert.
	Gesucht ist das neue ERD?
~~~



## 1. AUFGABE: SQL (V)
* LIES: DB/02-db-sql/01-lernen/02-db-sql-function_trigger_view.pdf
* UEBE: DB/02-db-sql/02-ueben/AB-04-sql-mysql-trigger-views-procs.sql
