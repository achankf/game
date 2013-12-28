create table player (
	pid integer primary key autoincrement,
	uid varchar(10) not null unique
);

create table creature_type(
	tid integer primary key autoincrement,
	name varchar(20) not null unique
);

insert into creature_type (name) values ('HUMAN');

create table locatable (
	lid integer primary key autoincrement,
	x float not null,
	y float not null
);

create table creature (
	cid integer primary key autoincrement,
	own_by integer not null references player,
	type integer not null references creature_type,
	lid integer not null references locatable
);
