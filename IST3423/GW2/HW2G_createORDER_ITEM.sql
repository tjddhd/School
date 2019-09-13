CREATE TABLE HW2G_ORDER_ITEM (
   InvoiceNumber	Integer		NOT NULL,
   ItemNumber		Integer		NOT NULL,
   Item				VarChar(20)	NOT NULL,
   Quantity         Integer		NOT NULL,
   UnitPrice		Number(5,2)	NULL,
   CONSTRAINT     HW2G_ORDER_ITEM_PK	PRIMARY KEY (InvoiceNumber,ItemNumber),
   CONSTRAINT     HW2G_ORDER_ITEM_FK	FOREIGN KEY (InvoiceNumber)
	REFERENCES HW2G_C_ORDER (InvoiceNumber)
   );