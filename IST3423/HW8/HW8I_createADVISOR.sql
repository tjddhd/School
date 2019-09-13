CREATE TABLE HW8I_ADVISOR (
	AdvisorID		Int			NOT NULL,
	AdvisorName		VarChar(25)		NOT NULL,
	AdvisorPhone 		Char(12)		NOT NULL,
	GarbageNote		VarChar(15)		NOT NULL,
	CONSTRAINT		AdvisorPK		PRIMARY KEY (AdvisorID)
	);

