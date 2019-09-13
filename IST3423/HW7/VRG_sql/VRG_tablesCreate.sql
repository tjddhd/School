CREATE TABLE VRG_CUSTOMER(
	CustomerID 	Int 		NOT NULL,
	LastName 	Varchar(15) 	NOT NULL,
	FirstName	Varchar(15)	NOT NULL,
	Street 		Varchar(25) 	NULL,
	City 		Varchar(20) 	NULL,
	State 		Char(2) 	NULL,
	ZipPostalCode	Char(9)		NULL,
	Country		Varchar(10)	NULL,
	AreaCode 	Char(3)		NULL,
	PhoneNumber 	Char(8) 	NULL,
	Email		Varchar(40) 	NULL,
	CONSTRAINT 	VRG_CUSTOMER_PK PRIMARY KEY (CustomerID)
	);

CREATE TABLE VRG_ARTIST(
	ArtistID 	Int 		NOT NULL,
	LastName 	Varchar(15)	NOT NULL,
	FirstName	Varchar(15)	NOT NULL,
	Nationality 	Varchar(15)	NULL,
	BirthYear 	Number (4,0)	NULL,
	DeathYear 	Number (4,0)	NULL,
	CONSTRAINT 	VRG_ARTIST_PK PRIMARY KEY (ArtistID),
	CONSTRAINT 	VRG_ARTIST_AK1 UNIQUE (LastName, FirstName),
	CONSTRAINT 	NationalityValues CHECK (Nationality IN 
			('Canadian', 'English', 'French','German',
			 'Mexican', 'Russian', 'Spanish', 
			 'United States')),
	CONSTRAINT 	BirthYearCheck CHECK 
			(BirthYear < DeathYear),
	CONSTRAINT 	ValidBirthYear CHECK 
			((BirthYear >= 1000) AND 
			 (BirthYear <= 2100)),
	CONSTRAINT 	ValidDeathYear CHECK 
			((DeathYear >= 1000) AND 
			 (DeathYear <= 2100))
	);

CREATE TABLE VRG_CUSTOMER_ARTIST_INT(
	ArtistID 	Int 		NOT NULL, 
	CustomerID 	Int 		NOT NULL,
 	CONSTRAINT 	VRG_CUSTOMER_ARTIST_PK PRIMARY KEY 
			(ArtistID, CustomerID),
	CONSTRAINT 	VRG_CUSTOMER_ARTIST_Int_FK1
			FOREIGN KEY (ArtistID) REFERENCES 
			VRG_ARTIST (ArtistID) ON DELETE CASCADE,
	CONSTRAINT 	CUSTOMER_ARTIST_Int_FK2 
			FOREIGN KEY (CustomerID) REFERENCES 
			VRG_CUSTOMER (CustomerID) ON DELETE CASCADE
	);

CREATE TABLE VRG_WORK (
	WorkID 		Int 		NOT NULL,
	Title 		Varchar(25) 	NOT NULL,
	Copy 		Varchar(12)	NOT NULL,
	Medium		Varchar(30)	NULL,
	Description 	Varchar(50)     DEFAULT 'Unknown provenance',
	ArtistID 	Int 		NOT NULL,
	CONSTRAINT 	VRG_WORK_PK PRIMARY KEY (WorkID),
	CONSTRAINT 	VRG_WORK_AK1 UNIQUE (Title, Copy),
	CONSTRAINT 	VRG_WORK_FK FOREIGN KEY(ArtistID) 
			REFERENCES VRG_ARTIST (ArtistID)
	);

CREATE TABLE VRG_TRANS (
	TransactionID	Int 		NOT NULL,
	DateAcquired 	Date		NOT NULL, 
	AcquisitionPrice Number (8,2)	NULL,
	DateSold	Date		NULL, 
	AskingPrice	Number (8,2)	NULL,
	SalesPrice 	Number (8,2)	NULL, 
	CustomerID	Int 		NULL,
	WorkID		Int 		NOT NULL,
	CONSTRAINT 	VRG_TRANS_PK PRIMARY KEY (TransactionID),
	CONSTRAINT 	VRG_TRANS_FK1 FOREIGN KEY(WorkID) 
			REFERENCES VRG_WORK (WorkID),
	CONSTRAINT 	VRG_TRANS_FK2 
			FOREIGN KEY(CustomerID) REFERENCES 
			VRG_CUSTOMER (CustomerID),
	CONSTRAINT 	SalesPriceRange CHECK 
			((SalesPrice > 0) AND 
			 (SalesPrice <=500000)),
	CONSTRAINT 	ValidTransDate CHECK 
			(DateAcquired <= DateSold)
	);


