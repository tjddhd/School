CREATE TABLE HW7G_CUSTOMER(
	CustomerID 	Int 			NOT NULL,
	LastName 	Varchar(15) 	NOT NULL,
	FirstName	Varchar(15)		NOT NULL,
	PhoneNumber Char(12) 		NOT NULL,
	Email		Varchar(30) 	NOT NULL,
	CONSTRAINT 	HW7G_CUSTOMER_PK PRIMARY KEY (CustomerID),
	CONSTRAINT	HW7G_CUSTOMER_AK UNIQUE (PhoneNumber, Email)
	);
	
CREATE TABLE HW7G_SERVICE (
	Service 		Int 		NOT NULL,
	Description		Varchar(40)	NOT NULL,
	UnitPrice		Number(8,2)	NOT NULL,
	CONSTRAINT 	HW7G_SERVICE_PK PRIMARY KEY (Service),
	CONSTRAINT	UnitPriceRange CHECK ((UnitPrice >=1.5) AND (UnitPrice <= 10.0))
	);

CREATE TABLE HW7G_ORDER(
	InvoiceNumber	Int 			NOT NULL,
	CustomerID 		Int				NOT NULL,
	DateIn			Date			NULL,
	DateOut 		Date			NULL,
	Subtotal 		Number(8,2)		NULL,
	Tax 			Number(8,2)		NULL,
	TotalAmount		Number(8,2)		NULL,
	CONSTRAINT 	HW7G_ORDER_PK PRIMARY KEY (InvoiceNumber),
	CONSTRAINT 	HW7G_ORDER_FK FOREIGN KEY (CustomerID)
				REFERENCES HW7G_CUSTOMER (CustomerID) 
				ON DELETE CASCADE
	);

CREATE TABLE HW7G_ORDER_ITEM(
	InvoiceNumber 	Int 		NOT NULL, 
	ItemNumber 		Int 		NOT NULL,
	Service			Int			NOT NULL,
	Quantity		Int			DEFAULT		1,
	UnitPrice		Number(8,2)	NOT NULL,
	ExtendedPrice	Number(8,2)	NULL,
 	CONSTRAINT 	HW7G_ORDER_ITEM_PK PRIMARY KEY 
			(InvoiceNumber, ItemNumber),
	CONSTRAINT 	HW7G_ORDER_ITEM_FK1
			FOREIGN KEY (InvoiceNumber) REFERENCES 
			HW7G_ORDER (InvoiceNumber) ON DELETE CASCADE,
	CONSTRAINT 	CUSTOMER_ORDER_ITEM_FK2 
			FOREIGN KEY (Service) REFERENCES 
			HW7G_SERVICE (Service) ON DELETE CASCADE
	);


