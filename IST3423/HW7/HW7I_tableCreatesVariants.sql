CREATE TABLE HW7I_PROJECT2(
	ProjectName		Varchar(20)		NOT NULL,
	Description		Varchar(40)		NULL,
	StartDate		Date			NULL,
	EndDate			Date			NULL,
	CONSTRAINT	HW7I_PROJECT2_PK	PRIMARY KEY (ProjectName),
	CONSTRAINT	check_proj CHECK (ProjectName IN('Red', 'Blue', 'Yellow')),
	CONSTRAINT	check_date CHECK (EndDate > StartDate)
	);
	
CREATE TABLE HW7I_ASSIGNMENT2(
	EmpNumber			Int				NOT NULL,
	ProjectName			Varchar(20)		NOT NULL,
	TotalHoursWorked	Number(5,2)		DEFAULT (4.0),
	CONSTRAINT	HW7I_ASSIGNEMNT2_PK	PRIMARY KEY (EmpNumber,ProjectName),
	CONSTRAINT 	HW7I_ASSIGNMENT2_FK_1 FOREIGN KEY (EmpNumber)
				REFERENCES HW7I_EMPLOYEE (EmpNumber),
	CONSTRAINT 	HW7I_ASSIGNMENT2_FK_2 FOREIGN KEY (ProjectName)
				REFERENCES HW7I_Project (ProjectName)
				ON DELETE CASCADE,
	CONSTRAINT	HW7I_ASSIGNMENT2_AK	UNIQUE (EmpNumber)
	);
	
	
CREATE TABLE HW7I_EMPLOYEE2(
	EmpNumber		Int			NOT NULL,
	LastName		Varchar(20)	NOT NULL,
	FirstName		Varchar(15)	NOT NULL,
	Eaddr			Varchar(25)	NULL,
	CONSTRAINT	HW7I_EMPLOYEE2_PK PRIMARY KEY (EmpNumber),
	CONSTRAINT	HW7I_EMPLOYEE2_AK UNIQUE (LastName, FirstName)
	);	
	
	
ALTER TABLE HW7I_EMPLOYEE2
	ADD	Phone	Char(12)	NULL;
	
	
ALTER TABLE HW7I_EMPLOYEE2
	DROP COLUMN	Eaddr;
	
	
ALTER TABLE HW7I_EMPLOYEE2
	ADD	CONSTRAINT HW7I_EMPLOYEE2_AK2 UNIQUE (Phone);
	
	
ALTER TABLE HW7I_EMPLOYEE2
	DROP CONSTRAINT HW7I_EMPLOYEE2_AK;