DROP DATABASE IF EXISTS proyecto;
CREATE DATABASE proyecto;
USE proyecto;
CREATE TABLE players (name TEXT, playerid INTEGER PRIMARY KEY NOT NULL,class INTEGER, hp INTEGER, dmg INTEGER);
INSERT INTO players (name,playerid,class,hp,dmg) VALUES ('Carlos',1,2,700,120);
INSERT INTO players (name,playerid,class,hp,dmg) VALUES ('Juan',2,1,1000,90);
INSERT INTO players (name,playerid,class,hp,dmg) VALUES ('Alex',3,2,700,120);

CREATE TABLE juego (matchid INTEGER, winnerid INTEGER NOT NULL, datetimefinish DATETIME, duration INTEGER,FOREIGN KEY (winnerid) REFERENCES  players(playerid));
INSERT INTO juego(matchid,winnerid,datetimefinish,duration) VALUES (1,1,'2024-09-28 15:12:49',40);
INSERT INTO juego(matchid,winnerid,datetimefinish,duration) VALUES (2,1,'2024-09-29 11:37:32',20);
INSERT INTO juego(matchid,winnerid,datetimefinish,duration) VALUES (2,2,'2024-09-29 14:16:27',30);
