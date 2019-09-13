CREATE OR REPLACE TRIGGER HW7G_Cust_Update
BEFORE UPDATE ON HW7G_CUSTOMER
FOR EACH ROW
DECLARE
	varOldID	Int;
	varNewID	Int;
	Results		Int;
BEGIN
	SELECT	COUNT(*) INTO Results
	FROM	HW7G_CUSTOMER,HW7G_ORDER
	WHERE	HW7G_CUSTOMER.CustomerID = HW7G_ORDER.CustomerID;
	
	IF(Results = 0)
	THEN
		RETURN;
	ELSE
		varOldID := :old.CustomerID;
		varNewID := :new.CustomerID;
		UPDATE	HW7G_ORDER
			SET		CustomerID = varNewID
			WHERE	CustomerID = varOldID;
	END IF;
END;
/

CREATE OR REPLACE TRIGGER HW7G_Service_Update
BEFORE UPDATE ON HW7G_SERVICE
FOR EACH ROW
DECLARE
	varOldService	Int;
	varNewService	Int;
	Results			Int;
BEGIN
	SELECT COUNT(*) INTO Results
	FROM HW7G_SERVICE, HW7G_ORDER_ITEM
	WHERE HW7G_SERVICE.Service = HW7G_ORDER_ITEM.Service;
	
	IF(Results = 0)
	THEN
		RETURN;
	ELSE
		varOldService := :old.Service;
		varNewService := :new.Service;
		UPDATE HW7G_ORDER_ITEM
			SET Service = varNewService
			WHERE Service = varOldService;
	END IF;
END;
/

CREATE OR REPLACE TRIGGER HW7G_Order_Update
BEFORE UPDATE ON HW7G_ORDER
FOR EACH ROW
DECLARE
	varOldInvoice	Int;
	varNewInvoice	Int;
	Results			Int;
BEGIN
	SELECT COUNT(*) INTO Results
	FROM HW7G_ORDER, HW7G_ORDER_ITEM
	WHERE HW7G_ORDER.InvoiceNumber = HW7G_ORDER_ITEM.InvoiceNumber;
	
	IF(Results = 0)
	THEN
		RETURN;
	ELSE
		varOldInvoice := :old.InvoiceNumber;
		varNewInvoice := :new.InvoiceNumber;
		UPDATE HW7G_ORDER_ITEM
			SET InvoiceNumber = varNewInvoice
			WHERE InvoiceNumber = varOldInvoice; 
	END IF;
END;
/