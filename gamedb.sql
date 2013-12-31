begin;

create table player (
	pid integer primary key autoincrement,
	uid varchar(10) not null unique
);

create table locatable (
	lid integer primary key autoincrement,
	x float not null,
	y float not null,
	z float not null
);

create index idx_locatable on locatable(x,y,z);

create table entity (
	eid integer primary key autoincrement,
	own_by integer not null references player,
	lid integer not null references locatable
);

create table race(
	rid integer primary key autoincrement,
	name varchar(20) not null unique
);

create table living_entity(
	eid integer not null primary key references entity,
	rid integer not null references race,
	birthday integer not null default 0
);

create table ability (
	sid integer primary key autoincrement,
	name varchar(20) not null unique,
	value float not null
);

create table object_type(
	oid integer primary key autoincrement,
	name varchar(20) not null unique
);

create table object_entity(
	eid integer not null primary key references entity,
	oid integer not null references object_type
);

create table has_ability (
	cid integer not null references entity,
	sid integer not null references ability,
	value float not null default 0,
	check (value between 0 and 1),
	primary key(cid, sid)
);

-- create_type
insert into race(name) values ('HUMAN');

commit;
