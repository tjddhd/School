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
-- CREATED		"Mon Oct 24 20:17:41 2011"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY LE IS 
	PORT
	(
		A :  IN  STD_LOGIC;
		B :  IN  STD_LOGIC;
		S2 :  IN  STD_LOGIC;
		S3 :  IN  STD_LOGIC;
		M :  IN  STD_LOGIC;
		Q :  OUT  STD_LOGIC
	);
END LE;

ARCHITECTURE bdf_type OF LE IS 

SIGNAL	SYNTHESIZED_WIRE_0 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_1 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_2 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_3 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_4 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_11 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_7 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_8 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_9 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_10 :  STD_LOGIC;


BEGIN 



SYNTHESIZED_WIRE_3 <= NOT(S2);



Q <= SYNTHESIZED_WIRE_0 OR SYNTHESIZED_WIRE_1;


SYNTHESIZED_WIRE_4 <= NOT(S3);



SYNTHESIZED_WIRE_11 <= NOT(M);



SYNTHESIZED_WIRE_2 <= NOT(A);



SYNTHESIZED_WIRE_9 <= SYNTHESIZED_WIRE_2 AND SYNTHESIZED_WIRE_3 AND SYNTHESIZED_WIRE_4 AND SYNTHESIZED_WIRE_11;


SYNTHESIZED_WIRE_8 <= B AND S2 AND S3 AND SYNTHESIZED_WIRE_11;


SYNTHESIZED_WIRE_10 <= B AND A AND S2;


SYNTHESIZED_WIRE_7 <= S3 AND A;


SYNTHESIZED_WIRE_1 <= M AND A;


SYNTHESIZED_WIRE_0 <= SYNTHESIZED_WIRE_7 OR SYNTHESIZED_WIRE_8 OR SYNTHESIZED_WIRE_9 OR SYNTHESIZED_WIRE_10;


END bdf_type;