DROP TRIGGER HW7G_Cust_Update;

DROP TRIGGER HW7G_Service_Update;

DROP TRIGGER HW7G_Order_Update;




UPDATE	HW7G_SERVICE
	SET		Description = 'Mens'' Shirt'
	WHERE	Description = 'Mens Shirt';
	
DELETE FROM	HW7G_ORDER
WHERE		InvoiceNumber = 2009010;

CREATE VIEW HW7G_OrderSummaryView AS
	SELECT	HW7G_ORDER.InvoiceNumber, HW7G_ORDER.DateIn, HW7G_ORDER.DateOut,
			HW7G_ORDER_ITEM.ItemNumber, HW7G_ORDER_ITEM.Service,
			HW7G_ORDER_ITEM.ExtendedPrice
	FROM	HW7G_ORDER, HW7G_ORDER_ITEM
	WHERE	HW7G_ORDER.InvoiceNumber = HW7G_ORDER_ITEM.InvoiceNumber;
	
	
CREATE VIEW HW7G_CustomerOrderSummaryView AS
	SELECT	HW7G_ORDER.InvoiceNumber, HW7G_CUSTOMER.FirstName,
			HW7G_CUSTOMER.LastName, HW7G_CUSTOMER.PhoneNumber,
			HW7G_ORDER.DateIn, HW7G_ORDER.DateOut, HW7G_ORDER.Subtotal,
			HW7G_ORDER_ITEM.ItemNumber, HW7G_ORDER_ITEM.Service,
			HW7G_ORDER_ITEM.ExtendedPrice
	FROM	HW7G_ORDER, HW7G_ORDER_ITEM, HW7G_CUSTOMER
	WHERE	HW7G_ORDER.InvoiceNumber = HW7G_ORDER_ITEM.InvoiceNumber
		AND	HW7G_CUSTOMER.CustomerID = HW7G_ORDER.CustomerID;
		
		
		
CREATE VIEW HW7G_CustomerOrderHistoryView AS
	SELECT	HW7G_ORDER.InvoiceNumber, HW7G_CUSTOMER.FirstName,
			HW7G_CUSTOMER.LastName, HW7G_ORDER.DateOut,
			HW7G_ORDER.Subtotal, HW7G_ORDER_ITEM.ExtendedPrice AS EP,
			SUM(HW7G_ORDER_ITEM.ExtendedPrice) AS TotEP, AVG(HW7G_ORDER_ITEM.ExtendedPrice) AS AvgEP
	FROM	HW7G_ORDER, HW7G_ORDER_ITEM, HW7G_CUSTOMER
	WHERE	HW7G_ORDER.InvoiceNumber = HW7G_ORDER_ITEM.InvoiceNumber
		AND	HW7G_CUSTOMER.CustomerID = HW7G_ORDER.CustomerID
	GROUP BY	HW7G_ORDER.InvoiceNumber, HW7G_CUSTOMER.FirstName,
			HW7G_CUSTOMER.LastName, HW7G_ORDER.DateOut, 
			HW7G_ORDER.Subtotal, HW7G_ORDER_ITEM.ExtendedPrice;
			
			
			
			
			
CREATE VIEW HW7G_CustomerOrderCheckView AS
	SELECT	HW7G_CUSTOMER.LastName, HW7G_CUSTOMER.FirstName,
			HW7G_ORDER.InvoiceNumber, HW7G_ORDER.Subtotal,
			SUM(HW7G_ORDER_ITEM.ExtendedPrice) AS TotEP,
			HW7G_ORDER_ITEM.ExtendedPrice AS EP, HW7G_ORDER.DateOut, 
			AVG(HW7G_ORDER_ITEM.ExtendedPrice) AS AvgEP
	FROM	HW7G_ORDER, HW7G_ORDER_ITEM, HW7G_CUSTOMER
	WHERE	HW7G_ORDER.InvoiceNumber = HW7G_ORDER_ITEM.InvoiceNumber
		AND	HW7G_CUSTOMER.CustomerID = HW7G_ORDER.CustomerID
		AND HW7G_ORDER.Subtotal NOT IN(
			SELECT	ExtendedPrice
			FROM	HW7G_ORDER_ITEM, HW7G_ORDER
			WHERE	HW7G_ORDER.InvoiceNumber = HW7G_ORDER_ITEM.InvoiceNumber
			AND	ExtendedPrice = Subtotal
			)
	GROUP BY	HW7G_ORDER.InvoiceNumber, HW7G_CUSTOMER.FirstName,
			HW7G_CUSTOMER.LastName, HW7G_ORDER.DateOut, 
			HW7G_ORDER.Subtotal, HW7G_ORDER_ITEM.ExtendedPrice
	ORDER BY	HW7G_CUSTOMER.LastName, HW7G_CUSTOMER.FirstName, 
			HW7G_ORDER.InvoiceNumber, HW7G_ORDER.Subtotal, TotEP;
			
DROP VIEW  HW7G_CustomerOrderCheckView;
		
SELECT   * 
FROM     HW7G_CustomerOrderCheckView
ORDER BY LastName, FirstName, InvoiceNumber;

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		