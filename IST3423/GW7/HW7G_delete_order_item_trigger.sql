
CREATE VIEW DeleteOrderItemView AS
	SELECT	*
	FROM	HW7G_ORDER_ITEM;

CREATE OR REPLACE TRIGGER HW7G_ORDER_ITEM_DeleteCheck
	INSTEAD OF DELETE ON DeleteOrderItemView
	
FOR EACH ROW

DECLARE

	rowcount	int;
	
BEGIN
	-- This trigger handles the situation of Cell 6 
	-- First determine if this is the last Order Item in the Order 
	
	SELECT	Count(*) INTO rowcount
	FROM	HW7G_ORDER_ITEM
	WHERE	HW7G_ORDER_ITEM.InvoiceNumber = :old.InvoiceNumber;
	
	IF (rowcount > 1)
	THEN
	
		-- Not last order item, allow deletion 
		
		DELETE	HW7G_ORDER_ITEM
		WHERE	HW7G_ORDER_ITEM.InvoiceNumber = :old.InvoiceNumber
		AND		HW7G_ORDER_ITEM.ItemNumber = :old.ItemNumber;
			
		--COMMIT; commented out since changes wouldn't commit ironically
		
	ELSE
		-- Error Message 
		DBMS_OUTPUT.PUT_LINE(' ');
		DBMS_OUTPUT.PUT_LINE('//////////////////////////////////');
		DBMS_OUTPUT.PUT_LINE('Deletion not completed due');
		DBMS_OUTPUT.PUT_LINE('only 1 Order Item remaining');
		DBMS_OUTPUT.PUT_LINE(' ');
		DBMS_OUTPUT.PUT_LINE('Please delete Order if you');
		DBMS_OUTPUT.PUT_LINE('wish to complete this deletion');
		DBMS_OUTPUT.PUT_LINE('//////////////////////////////////');
		DBMS_OUTPUT.PUT_LINE(' ');
	END IF;

	
END;

/



SET SERVEROUTPUT ON;

DELETE	DeleteOrderItemView
WHERE	InvoiceNumber = 2009001
AND		ItemNumber = 1;

SELECT	*
FROM	HW7G_ORDER_ITEM;

SELECT	*
FROM	DeleteOrderItemView;

