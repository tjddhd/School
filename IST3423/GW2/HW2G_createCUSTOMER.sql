CREATE TABLE HW2G_CUSTOMER (
   CustomerID	Integer      NOT NULL,
   FirstName	VarChar(15)  NOT NULL,
   LastName		VarChar(20)  NOT NULL,
   Phone		VarChar(12)	 NULL,
   Email		VarChar(30)	 NULL,
   CONSTRAINT  HW2G_CUSTOMER_PK  PRIMARY KEY (CustomerID)
   );
