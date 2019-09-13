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
-- CREATED		"Wed Dec 07 13:53:58 2011"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY BigPart IS 
	PORT
	(
		CountQ0 :  IN  STD_LOGIC;
		CountQ1 :  IN  STD_LOGIC;
		CountQ2 :  IN  STD_LOGIC;
		A :  OUT  STD_LOGIC;
		B :  OUT  STD_LOGIC
	);
END BigPart;

ARCHITECTURE bdf_type OF BigPart IS 

COMPONENT yourpart
	PORT(D0 : IN STD_LOGIC;
		 D1 : IN STD_LOGIC;
		 D2 : IN STD_LOGIC;
		 OutputA : OUT STD_LOGIC;
		 OutputB : OUT STD_LOGIC
	);
END COMPONENT;



BEGIN 



b2v_YourPart1 : yourpart
PORT MAP(D0 => CountQ0,
		 D1 => CountQ1,
		 D2 => CountQ2,
		 OutputA => A,
		 OutputB => B);


END bdf_type;