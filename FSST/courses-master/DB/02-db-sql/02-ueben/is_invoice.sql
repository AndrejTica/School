--
-- anton.hofmann@htl-salzburg.ac.at
-- demo zu sql: is_invoice.sql
-- db: is_invoice
-- user: is_invoice oder is_invoice@localhost
-- pwd: comein
-- als root ausführen

drop database if exists is_invoice;
create database if not exists is_invoice;

grant create,drop, references, select,insert,update,delete 
on is_invoice.* to is_invoice@localhost identified by 'comein';

use is_invoice;

drop table if exists customer;
create table customer(
	id int  primary key,
	name varchar(80) not null default 'Anton Hofmann',
	address varchar(80) not null default 'address n/a'
);

drop table if exists product;
create table product(
	id	 int primary key,
	description varchar(80) not null default 'desc n/a',	
	price	double not null default 1.0
);

drop table if exists invoice;
create table invoice(
	id int primary key,
	full_price double not null default 0.0,
    date date,

    customer_id int not null,

	constraint inv_cust_fk
	foreign key (customer_id) references customer(id) on delete restrict
);

drop table if exists invoice_position;
create table invoice_position (
	position int not null,
	number_of_items int not null default 1,

    product_id int not null ,
    invoice_id int not null ,

	constraint invpos_pk 
	primary key (product_id,invoice_id),

	constraint invpos_prod_fk 
	foreign key (product_id) references product(id) on delete restrict,

	constraint invpos_cust_fk 
	foreign key (invoice_id) references invoice(id) on delete restrict
);


commit;

-- insert customers 

insert into customer (id,name,address)
values (1, 'Anton Hofmann','road 1');

insert into customer (id,name,address)
values(2, 'Beta Hofmann','road 2');

insert into customer (id,name,address) 
values(3, 'Gamme Hofmann','road 3');


-- insert products: computer, tablet, handy

insert into product values (1,'computer', 300.0);
insert into product values (2,'tablet', 100.0);
insert into product values (3,'handy', 50.0);


-- insert invoices
-- full_price can only be calculated on invoice closing

insert into invoice (id,full_price,date,customer_id)
values(1,1.0,'2016-12-10', 1);
insert into invoice (id,full_price,date,customer_id)
values(2,2.0,'2016-12-20', 2);
insert into invoice (id,full_price,date,customer_id)
values(3,3.0,'2016-12-30', 3);


-- insert sold: 11 computers and 2 tables

insert into invoice_position(position, number_of_items,product_id, invoice_id)
values (1, 10, 1, 1);
insert into invoice_position(position, number_of_items,product_id, invoice_id)
values (1, 1, 1, 2);
insert into invoice_position(position, number_of_items,product_id, invoice_id)
values (2, 2, 2, 2);
    


-- which products are best-sellers?
 
select description, product_id, sum(number_of_items) as countProduct
from invoice_position, product
where product.id= invoice_position.product_id
group by description, product_id
order by countProduct desc;

