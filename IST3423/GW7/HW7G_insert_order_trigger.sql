CREATE VIEW InsertOrderView AS
	SELECT *
	FROM HW7G_ORDER;
	
CREATE OR REPLACE TRIGGER HW7G_ORDER_InsertCheck
	INSTEAD OF INSERT ON InsertOrderView
	
FOR EACH ROW

DECLARE
	varInvoiceNumber	int;
	varItemNumber	int;
	varService	int;
	varQuantity	int;
	varUnitPrice	int;
	varExtendedPrice	Number(8,2);
	
	
BEGIN
	--This trigger handles the situation of cell 1
	--
	varInvoiceNumber := :new.InvoiceNumber;
	varItemNumber := :new.InvoiceNumber;
	varService := :new.InvoiceNumber;
	varUnitPrice := :new.InvoiceNumber;
	
	DBMS_OUTPUT.PUT_LINE(' ');
	DBMS_OUTPUT.PUT_LINE('//////////////////////////////////');
	DBMS_OUTPUT.PUT_LINE('New order item has been added');
	DBMS_OUTPUT.PUT_LINE(' ');
	DBMS_OUTPUT.PUT_LINE('  InvoiceNumber  = '||varInvoiceNumber);
	DBMS_OUTPUT.PUT_LINE('  ItemNumber  = '||varItemNumber);
	DBMS_OUTPUT.PUT_LINE('  Service  = '||varService);
	DBMS_OUTPUT.PUT_LINE('  Quantity  = '||varQuantity);
	DBMS_OUTPUT.PUT_LINE('  UnitPrice  = '||varUnitPrice);
	DBMS_OUTPUT.PUT_LINE('  ExtendedPrice  = '||varExtendedPrice);
	DBMS_OUTPUT.PUT_LINE('//////////////////////////////////');
	DBMS_OUTPUT.PUT_LINE(' ');
	
	INSERT INTO HW7G_ORDER VALUES(
		:new.InvoiceNumber, :new.CustomerID, :new.DateIn, :new.DateOut,
		:new.Subtotal, :new.Tax, :new.TotalAmount);
		
	INSERT INTO HW7G_ORDER_ITEM VALUES(
		varInvoiceNumber, varItemNumber, varService, varQuantity,
		varUnitPrice, varExtendedPrice);
END;

/

SET SERVEROUTPUT ON;

SELECT * 
FROM InsertOrderView;

INSERT INTO InsertOrderView VALUES(2009010, 120,'10-DEC-12','10-DEC-13',0.0,0.0,0.0);

SELECT * 
FROM InsertOrderView;