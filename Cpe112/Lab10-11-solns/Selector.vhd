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
-- CREATED		"Mon Oct 24 19:50:51 2011"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY Selector IS 
	PORT
	(
		S :  IN  STD_LOGIC;
		Input :  IN  STD_LOGIC_VECTOR(3 DOWNTO 0);
		Y :  OUT  STD_LOGIC_VECTOR(3 DOWNTO 0)
	);
END Selector;

ARCHITECTURE bdf_type OF Selector IS 

COMPONENT bit2sel
	PORT(D1 : IN STD_LOGIC;
		 D0 : IN STD_LOGIC;
		 S : IN STD_LOGIC;
		 Y : OUT STD_LOGIC
	);
END COMPONENT;

SIGNAL	Y_ALTERA_SYNTHESIZED :  STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL	SYNTHESIZED_WIRE_4 :  STD_LOGIC;


BEGIN 
SYNTHESIZED_WIRE_4 <= '0';



b2v_inst : bit2sel
PORT MAP(D1 => Input(3),
		 D0 => SYNTHESIZED_WIRE_4,
		 S => S,
		 Y => Y_ALTERA_SYNTHESIZED(3));


b2v_inst1 : bit2sel
PORT MAP(D1 => Input(2),
		 D0 => SYNTHESIZED_WIRE_4,
		 S => S,
		 Y => Y_ALTERA_SYNTHESIZED(2));


b2v_inst2 : bit2sel
PORT MAP(D1 => Input(1),
		 D0 => SYNTHESIZED_WIRE_4,
		 S => S,
		 Y => Y_ALTERA_SYNTHESIZED(1));


b2v_inst3 : bit2sel
PORT MAP(D1 => Input(0),
		 D0 => SYNTHESIZED_WIRE_4,
		 S => S,
		 Y => Y_ALTERA_SYNTHESIZED(0));


Y <= Y_ALTERA_SYNTHESIZED;

END bdf_type;