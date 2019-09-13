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
-- CREATED		"Wed Oct 05 14:19:08 2011"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY Lab7_4 IS 
	PORT
	(
		CarryIn :  IN  STD_LOGIC;
		A :  IN  STD_LOGIC_VECTOR(3 DOWNTO 0);
		B :  IN  STD_LOGIC_VECTOR(3 DOWNTO 0);
		CarryOut :  OUT  STD_LOGIC;
		Sum :  OUT  STD_LOGIC_VECTOR(3 DOWNTO 0)
	);
END Lab7_4;

ARCHITECTURE bdf_type OF Lab7_4 IS 

COMPONENT lab7_1
	PORT(A : IN STD_LOGIC;
		 B : IN STD_LOGIC;
		 CarryIn : IN STD_LOGIC;
		 Sum : OUT STD_LOGIC;
		 CarryOut : OUT STD_LOGIC
	);
END COMPONENT;

SIGNAL	Sum_ALTERA_SYNTHESIZED :  STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL	SYNTHESIZED_WIRE_0 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_1 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_2 :  STD_LOGIC;


BEGIN 



b2v_Adder1 : lab7_1
PORT MAP(A => A(0),
		 B => B(0),
		 CarryIn => CarryIn,
		 Sum => Sum_ALTERA_SYNTHESIZED(0),
		 CarryOut => SYNTHESIZED_WIRE_0);


b2v_Adder2 : lab7_1
PORT MAP(A => A(1),
		 B => B(1),
		 CarryIn => SYNTHESIZED_WIRE_0,
		 Sum => Sum_ALTERA_SYNTHESIZED(1),
		 CarryOut => SYNTHESIZED_WIRE_1);


b2v_Adder3 : lab7_1
PORT MAP(A => A(2),
		 B => B(2),
		 CarryIn => SYNTHESIZED_WIRE_1,
		 Sum => Sum_ALTERA_SYNTHESIZED(2),
		 CarryOut => SYNTHESIZED_WIRE_2);


b2v_Adder4 : lab7_1
PORT MAP(A => A(3),
		 B => B(3),
		 CarryIn => SYNTHESIZED_WIRE_2,
		 Sum => Sum_ALTERA_SYNTHESIZED(3),
		 CarryOut => CarryOut);

Sum <= Sum_ALTERA_SYNTHESIZED;

END bdf_type;