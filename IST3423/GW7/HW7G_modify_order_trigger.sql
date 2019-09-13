CREATE VIEW ModifyOrderView AS
	SELECT * 
	FROM HW7G_ORDER;
	
CREATE OR REPLACE TRIGGER HW7G_ORDER_ModfiyCheck
	INSTEAD OF UPDATE ON ModifyOrderView
	
FOR EACH ROW

	
BEGIN 
	-- This trigger handles the situation of cell 3
	-- This outputs an error as there is no action actually taken 
	
		DBMS_OUTPUT.PUT_LINE(' ');
		DBMS_OUTPUT.PUT_LINE('//////////////////////////////////');
		DBMS_OUTPUT.PUT_LINE('Modification not allowed');
		DBMS_OUTPUT.PUT_LINE('because of the surrogate key');
		DBMS_OUTPUT.PUT_LINE('//////////////////////////////////');
		DBMS_OUTPUT.PUT_LINE(' ');
END;

/


SET SERVEROUTPUT ON;

UPDATE ModifyOrderView 
SET InvoiceNumber = 1;

SELECT	*
FROM	ModifyOrderView;
