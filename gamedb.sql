begin;

create table player (
	pid integer primary key autoincrement,
	uid varchar(10) not null unique
);

create table creature_type(
	tid integer primary key autoincrement,
	name varchar(20) not null unique
);

create table locatable (
	lid integer primary key autoincrement,
	x float not null,
	y float not null,
	z float not null
);

create index idx_locatable on locatable(x,y,z);

create table creature (
	cid integer primary key autoincrement,
	own_by integer not null references player,
	birthday integer not null default 0,
	type integer not null references creature_type,
	lid integer not null references locatable
);

create table skill (
	sid integer primary key autoincrement,
	name varchar(20) not null unique,
	value float not null
);

create table has_skill (
	cid integer not null references creature,
	sid integer not null references skill,
	proficiency float not null default 0,
	check (proficiency between 0 and 1),
	primary key(cid, sid)
);

-- create_type
insert into creature_type (name) values ('HUMAN');

commit;
