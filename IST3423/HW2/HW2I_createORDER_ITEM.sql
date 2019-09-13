CREATE TABLE HW2G_C_ORDER (
   InvoiceNumber	Integer		NOT NULL,
   CustomerID		Integer		NOT NULL,
   DateIn			Date		NOT NULL,
   DateOut          Date		NULL,
   TotalAmount		Number(5,2)	NULL,
   CONSTRAINT     HW2G_C_ORDER_PK	PRIMARY KEY (InvoiceNumber),
   CONSTRAINT     HW2G_C_ORDER_FK	FOREIGN KEY (CustomerID)
	REFERENCES HW2G_CUSTOMER (CustomerID)
   );