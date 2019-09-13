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
-- CREATED		"Mon Oct 24 20:55:15 2011"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY Fulladd IS 
	PORT
	(
		A :  IN  STD_LOGIC;
		B :  IN  STD_LOGIC;
		C :  IN  STD_LOGIC;
		S :  OUT  STD_LOGIC;
		CY :  OUT  STD_LOGIC
	);
END Fulladd;

ARCHITECTURE bdf_type OF Fulladd IS 

SIGNAL	SYNTHESIZED_WIRE_4 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_2 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_3 :  STD_LOGIC;


BEGIN 



SYNTHESIZED_WIRE_4 <= A XOR B;


S <= SYNTHESIZED_WIRE_4 XOR C;


SYNTHESIZED_WIRE_3 <= NOT(C AND SYNTHESIZED_WIRE_4);


SYNTHESIZED_WIRE_2 <= NOT(B AND A);


CY <= NOT(SYNTHESIZED_WIRE_2 AND SYNTHESIZED_WIRE_3);


END bdf_type;