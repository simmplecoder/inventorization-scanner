-- DROP TABLE BORROWING;
-- DROP TABLE LAB_MASTER;
-- DROP TABLE ITEM;
-- DROP TABLE USER;
-- DROP TABLE LAB;
     

create table LAB
    (id INT,
     name VARCHAR(40) NOT NULL,
     PRIMARY KEY (id));
     
INSERT INTO LAB VALUES
	(1, "Fume tower"),
    (2, "Tower of Heyde");
     
create table USER
    (id INT,
     password VARCHAR(24) NOT NULL,
     photo VARCHAR(255),
     name VARCHAR(20) NOT NULL,
     surname VARCHAR(25) NOT NULL,
     course INT NOT NULL,
     school VARCHAR(25) NOT NULL,
     privelege INT NOT NULL,
     e_mail VARCHAR(60) NOT NULL,
     lab_id INT NOT NULL,
     primary key (id),
     foreign key (lab_id) references LAB(id));

INSERT INTO USER VALUES
	(1, "peter", "peter.png", "Peter", "Parker", 1, "SST", 3, "peter.parker@inbox.com", 1),
    (2, "ashley", "ashley.png", "Ashley", "Romanoff", 1, "SST", 3, "ashley.romanoff@gmail.com", 1),
    (3, "thomas", "thomas.png", "Thomas", "Morrison", -1, "SST", 4, "thomas.morrison@nu.edu.kz", 1),
    (4, "sarah", "sarah.png", "Sarah", "Johnson", -1, "SST", 4, "sarah.johnson@nu.edu.kz", 2);
     
create table LAB_MASTER
    (user_id INT NOT NULL,
     lab_id INT NOT NULL,
     foreign key(user_id) references USER(id),
     foreign key(lab_id) references LAB(id));
     
INSERT INTO LAB_MASTER VALUES
    (3, 1),
    (4, 2);

create table ITEM
    (id INT NOT NULL,
     name VARCHAR(100) NOT NULL,
     description VARCHAR(255),
     lab_id INT NOT NULL,
     privelege INT NOT NULL,
     primary key (id),
     foreign key (lab_id) references LAB(id));
     
INSERT INTO ITEM VALUES
	(1, "Flame Thrower", "used to burn something down", 1, 3),
    (2, "Flame Thrower", "used to burn something down", 2, 3),
    (3, "Gloves", "just a pair of gloves", 1, 1),
    (4, "Goggles", "used to protect eyes", 1, 1),
    (5,  "flask", "used to store fluids and manipulate them", 2, 1);


create table BORROWING
    (id INT NOT NULL AUTO_INCREMENT,
     user_id INT NOT NULL,
     lab_id INT NOT NULL,
     item_id INT NOT NULL,
     returned BOOL NOT NULL,
     primary key(id),
     foreign key(user_id) references USER(id),
     foreign key(lab_id) references LAB(id),
     foreign key(item_id) references ITEM(id));
     