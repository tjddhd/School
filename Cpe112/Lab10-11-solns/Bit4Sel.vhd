-- Copyright (C) 1991-2010 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- PROGRAM		"Quartus II"
-- VERSION		"Version 10.1 Build 153 11/29/2010 SJ Full Version"
-- CREATED		"Mon Oct 24 19:45:19 2011"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY Bit4Sel IS 
	PORT
	(
		D3 :  IN  STD_LOGIC;
		D2 :  IN  STD_LOGIC;
		D1 :  IN  STD_LOGIC;
		D0 :  IN  STD_LOGIC;
		S1 :  IN  STD_LOGIC;
		S0 :  IN  STD_LOGIC;
		Y :  OUT  STD_LOGIC
	);
END Bit4Sel;

ARCHITECTURE bdf_type OF Bit4Sel IS 

SIGNAL	SYNTHESIZED_WIRE_8 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_9 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_4 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_5 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_6 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_7 :  STD_LOGIC;


BEGIN 



SYNTHESIZED_WIRE_8 <= NOT(S0);



SYNTHESIZED_WIRE_9 <= NOT(S1);



SYNTHESIZED_WIRE_6 <= S0 AND S1 AND D3;


SYNTHESIZED_WIRE_5 <= SYNTHESIZED_WIRE_8 AND S1 AND D2;


SYNTHESIZED_WIRE_7 <= S0 AND SYNTHESIZED_WIRE_9 AND D1;


SYNTHESIZED_WIRE_4 <= SYNTHESIZED_WIRE_8 AND SYNTHESIZED_WIRE_9 AND D0;


Y <= SYNTHESIZED_WIRE_4 OR SYNTHESIZED_WIRE_5 OR SYNTHESIZED_WIRE_6 OR SYNTHESIZED_WIRE_7;


END bdf_type;