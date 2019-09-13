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

-- PROGRAM		"Quartus II 64-Bit"
-- VERSION		"Version 10.1 Build 153 11/29/2010 SJ Full Version"
-- CREATED		"Wed Sep 28 13:24:26 2011"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY Lab6 IS 
	PORT
	(
		InputX :  IN  STD_LOGIC;
		InputY :  IN  STD_LOGIC;
		InputA :  IN  STD_LOGIC;
		InputB :  IN  STD_LOGIC;
		pin_name :  OUT  STD_LOGIC
	);
END Lab6;

ARCHITECTURE bdf_type OF Lab6 IS 

SIGNAL	SYNTHESIZED_WIRE_14 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_1 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_2 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_15 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_16 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_8 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_9 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_10 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_11 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_12 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_13 :  STD_LOGIC;


BEGIN 



SYNTHESIZED_WIRE_10 <= SYNTHESIZED_WIRE_14 AND InputX AND InputY;


pin_name <= SYNTHESIZED_WIRE_1 OR SYNTHESIZED_WIRE_2;


SYNTHESIZED_WIRE_8 <= SYNTHESIZED_WIRE_14 AND InputB AND InputX;


SYNTHESIZED_WIRE_9 <= InputB AND SYNTHESIZED_WIRE_15 AND InputY;


SYNTHESIZED_WIRE_13 <= InputA AND InputB AND SYNTHESIZED_WIRE_15;


SYNTHESIZED_WIRE_11 <= InputA AND SYNTHESIZED_WIRE_16 AND InputY;


SYNTHESIZED_WIRE_12 <= InputA AND SYNTHESIZED_WIRE_16 AND InputX;


SYNTHESIZED_WIRE_2 <= SYNTHESIZED_WIRE_8 OR SYNTHESIZED_WIRE_9 OR SYNTHESIZED_WIRE_10;


SYNTHESIZED_WIRE_1 <= SYNTHESIZED_WIRE_11 OR SYNTHESIZED_WIRE_12 OR SYNTHESIZED_WIRE_13;


SYNTHESIZED_WIRE_14 <= NOT(InputA);



SYNTHESIZED_WIRE_16 <= NOT(InputB);



SYNTHESIZED_WIRE_15 <= NOT(InputX);




END bdf_type;