CREATE OR REPLACE PROCEDURE HW10I_Artist_View
	(
		newName		IN	Char
	)
AS
	varLN		Char;
	varNat		Char;

BEGIN
	
	SELECT	LastName INTO varLN, Nationality INTO varNat
	FROM	VRG_ARTIST
	WHERE	LastName = newName;
	
		DBMS_OUTPUT.PUT_LINE(' ');
		DBMS_OUTPUT.PUT_LINE('//////////////////////////////////');
		DBMS_OUTPUT.PUT_LINE('Artist Last Name:     '||varLN);
		DBMS_OUTPUT.PUT_LINE('Artist Nationality:   '||varNat);
		DBMS_OUTPUT.PUT_LINE('//////////////////////////////////');
		DBMS_OUTPUT.PUT_LINE(' ');
		
END;

/