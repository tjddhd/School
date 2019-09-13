CREATE OR REPLACE TRIGGER HW10I_EMP_DEPT_UpdateCheck
	INSTEAD OF UPDATE ON HW10I_EMP_DEPT_VIEW
	
FOR EACH ROW

BEGIN 
	-- This trigger handles the situation of question 11
	-- This outputs an error as there is no action actually taken 
	
		DBMS_OUTPUT.PUT_LINE(' ');
		DBMS_OUTPUT.PUT_LINE('//////////////////////////////////');
		DBMS_OUTPUT.PUT_LINE('Modification not allowed because');
		DBMS_OUTPUT.PUT_LINE('employee cannot cahnge department');
		DBMS_OUTPUT.PUT_LINE('//////////////////////////////////');
		DBMS_OUTPUT.PUT_LINE(' ');
END;

/
