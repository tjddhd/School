CREATE TABLE HW7I_EMPLOYEE(
	EmpNumber		Int			NOT NULL,
	LastName		Varchar(20)	NOT NULL,
	FirstName		Varchar(15)	NOT NULL,
	Eaddr			Varchar(25)	NULL,
	CONSTRAINT	HW7I_EMPLOYEE_PK PRIMARY KEY (EmpNumber),
	CONSTRAINT	HW7I_EMPLOYEE_AK UNIQUE (LastName, FirstName)
	);
	
	
CREATE TABLE HW7I_PROJECT(
	ProjectName		Varchar(20)		NOT NULL,
	Description		Varchar(40)		NULL,
	StartDate		Date			NULL,
	EndDate			Date			NULL,
	CONSTRAINT	HW7I_PROJECT_PK	PRIMARY KEY (ProjectName)
	);
	
	
CREATE TABLE HW7I_ASSIGNMENT(
	EmpNumber			Int				NOT NULL,
	ProjectName			Varchar(20)		NOT NULL,
	TotalHoursWorked	Number(5,2)		NULL,
	CONSTRAINT	HW7I_ASSIGNEMNT_PK	PRIMARY KEY (EmpNumber,ProjectName),
	CONSTRAINT 	HW7I_ASSIGNMENT_FK_1 FOREIGN KEY (EmpNumber)
				REFERENCES HW7I_EMPLOYEE (EmpNumber),
	CONSTRAINT 	HW7I_ASSIGNMENT_FK_2 FOREIGN KEY (ProjectName)
				REFERENCES HW7I_Project (ProjectName)
				ON DELETE CASCADE
	);
	
	
ALTER TABLE HW7I_ASSIGNMENT
	MODIFY	TotalHoursWorked	Number(5,2)		DEFAULT (4.0);
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	