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
-- CREATED		"Wed Aug 31 14:03:49 2011"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY Lab2 IS 
	PORT
	(
		inputA :  IN  STD_LOGIC;
		inputB :  IN  STD_LOGIC;
		outAND :  OUT  STD_LOGIC;
		outNAND :  OUT  STD_LOGIC;
		outOR :  OUT  STD_LOGIC;
		outNOR :  OUT  STD_LOGIC
	);
END Lab2;

ARCHITECTURE bdf_type OF Lab2 IS 



BEGIN 



outAND <= inputA AND inputB;


outNAND <= NOT(inputB AND inputA);


outOR <= inputB OR inputA;


outNOR <= NOT(inputB OR inputA);


END bdf_type;