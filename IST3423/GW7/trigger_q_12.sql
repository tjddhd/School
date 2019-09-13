CREATE OR REPLACE TRIGGER HW10I_EMP_DEPT_DeleteCheck
	INSTEAD OF DELETE ON HW10I_DELETE_DEPT_VIEW
	
FOR EACH ROW

DECLARE

	rowcount	int;
	
BEGIN
	-- This trigger handles the situation of Question 12
	
	SELECT	Count(*) INTO rowcount
	FROM	HW10I_EMPLOYEE H
	WHERE	HW10I_EMPLOYEE.EmpNumber = :old.EmpNumber
	AND		Department IN(
		`	SELECT	*
			FROM	HW10I_EMPOYEE G
			WHERE	H.EmpNumber <> G.EmpNumber
			AND		H.Department = G.Department);
	
	IF (rowcount > 1)
	THEN
	
		-- Not last employee, allow deletion 
		
		DELETE   FROM   HW10I_EMPLOYEE
		WHERE   Department = :old.Department;
		
	ELSE
		INSERT INTO HW10I_EMPLOYEE VALUES(:old.EmpNumber, :old.EmpName,
			'Human Resources', :old.Email);
			
		DELETE   FROM   HW10I_EMPLOYEE
		WHERE   Department = :old.Department;
		
		DELETE FROM HW10I_DEPARTMENT
		WHERE Department = :old.Department;
		
	END IF;

	
END;

/