create table player (
	pid integer primary key autoincrement,
	uid varchar(10) not null unique
);

create table creature (
	cid integer primary key autoincrement,
	own_by integer not null references player,
	x float not null,
	y float not null
);
