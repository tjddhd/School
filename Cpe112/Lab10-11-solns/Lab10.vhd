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
-- CREATED		"Mon Oct 24 21:55:06 2011"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY Lab10 IS 
	PORT
	(
		S :  IN  STD_LOGIC;
		M :  IN  STD_LOGIC;
		S3 :  IN  STD_LOGIC;
		S2 :  IN  STD_LOGIC;
		S1 :  IN  STD_LOGIC;
		S0 :  IN  STD_LOGIC;
		IL :  IN  STD_LOGIC;
		IR :  IN  STD_LOGIC;
		Clk :  IN  STD_LOGIC;
		Input :  IN  STD_LOGIC_VECTOR(3 DOWNTO 0);
		cout :  OUT  STD_LOGIC;
		op :  OUT  STD_LOGIC_VECTOR(3 DOWNTO 0)
	);
END Lab10;

ARCHITECTURE bdf_type OF Lab10 IS 

COMPONENT selector
	PORT(S : IN STD_LOGIC;
		 Input : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
		 Y : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
	);
END COMPONENT;

COMPONENT alu
	PORT(S2 : IN STD_LOGIC;
		 M : IN STD_LOGIC;
		 S3 : IN STD_LOGIC;
		 A : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
		 B : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
		 COUT : OUT STD_LOGIC;
		 F : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
	);
END COMPONENT;

COMPONENT accumulator
	PORT(IL : IN STD_LOGIC;
		 IR : IN STD_LOGIC;
		 S0 : IN STD_LOGIC;
		 S1 : IN STD_LOGIC;
		 Clk : IN STD_LOGIC;
		 I : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
		 Y : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
	);
END COMPONENT;

SIGNAL	SYNTHESIZED_WIRE_0 :  STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL	SYNTHESIZED_WIRE_1 :  STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL	SYNTHESIZED_WIRE_2 :  STD_LOGIC_VECTOR(3 DOWNTO 0);


BEGIN 
op <= SYNTHESIZED_WIRE_1;



b2v_inst : selector
PORT MAP(S => S,
		 Input => Input,
		 Y => SYNTHESIZED_WIRE_0);


b2v_inst1 : alu
PORT MAP(S2 => S2,
		 M => M,
		 S3 => S3,
		 A => SYNTHESIZED_WIRE_0,
		 B => SYNTHESIZED_WIRE_1,
		 COUT => cout,
		 F => SYNTHESIZED_WIRE_2);


b2v_inst3 : accumulator
PORT MAP(IL => IL,
		 IR => IR,
		 S0 => S0,
		 S1 => S1,
		 Clk => Clk,
		 I => SYNTHESIZED_WIRE_2,
		 Y => SYNTHESIZED_WIRE_1);


END bdf_type;