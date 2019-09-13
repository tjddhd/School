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
-- CREATED		"Mon Oct 24 21:43:34 2011"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY Accumulator IS 
	PORT
	(
		IL :  IN  STD_LOGIC;
		IR :  IN  STD_LOGIC;
		S0 :  IN  STD_LOGIC;
		S1 :  IN  STD_LOGIC;
		Clk :  IN  STD_LOGIC;
		I :  IN  STD_LOGIC_VECTOR(3 DOWNTO 0);
		Y :  OUT  STD_LOGIC_VECTOR(3 DOWNTO 0)
	);
END Accumulator;

ARCHITECTURE bdf_type OF Accumulator IS 

COMPONENT bit4sel
	PORT(D3 : IN STD_LOGIC;
		 D2 : IN STD_LOGIC;
		 D1 : IN STD_LOGIC;
		 D0 : IN STD_LOGIC;
		 S1 : IN STD_LOGIC;
		 S0 : IN STD_LOGIC;
		 Y : OUT STD_LOGIC
	);
END COMPONENT;

SIGNAL	Y_ALTERA_SYNTHESIZED :  STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL	SYNTHESIZED_WIRE_12 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_1 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_4 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_7 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_10 :  STD_LOGIC;


BEGIN 
SYNTHESIZED_WIRE_12 <= '1';



b2v_inst : bit4sel
PORT MAP(D3 => IL,
		 D2 => Y_ALTERA_SYNTHESIZED(2),
		 D1 => I(3),
		 D0 => Y_ALTERA_SYNTHESIZED(3),
		 S1 => S1,
		 S0 => S0,
		 Y => SYNTHESIZED_WIRE_1);


b2v_inst1 : bit4sel
PORT MAP(D3 => Y_ALTERA_SYNTHESIZED(3),
		 D2 => Y_ALTERA_SYNTHESIZED(1),
		 D1 => I(2),
		 D0 => Y_ALTERA_SYNTHESIZED(2),
		 S1 => S1,
		 S0 => S0,
		 Y => SYNTHESIZED_WIRE_4);


b2v_inst2 : bit4sel
PORT MAP(D3 => Y_ALTERA_SYNTHESIZED(2),
		 D2 => Y_ALTERA_SYNTHESIZED(0),
		 D1 => I(1),
		 D0 => Y_ALTERA_SYNTHESIZED(1),
		 S1 => S1,
		 S0 => S0,
		 Y => SYNTHESIZED_WIRE_7);


b2v_inst3 : bit4sel
PORT MAP(D3 => Y_ALTERA_SYNTHESIZED(1),
		 D2 => IR,
		 D1 => I(0),
		 D0 => Y_ALTERA_SYNTHESIZED(0),
		 S1 => S1,
		 S0 => S0,
		 Y => SYNTHESIZED_WIRE_10);


PROCESS(Clk,SYNTHESIZED_WIRE_12,SYNTHESIZED_WIRE_12)
BEGIN
IF (SYNTHESIZED_WIRE_12 = '0') THEN
	Y_ALTERA_SYNTHESIZED(3) <= '0';
ELSIF (SYNTHESIZED_WIRE_12 = '0') THEN
	Y_ALTERA_SYNTHESIZED(3) <= '1';
ELSIF (RISING_EDGE(Clk)) THEN
	Y_ALTERA_SYNTHESIZED(3) <= SYNTHESIZED_WIRE_1;
END IF;
END PROCESS;


PROCESS(Clk,SYNTHESIZED_WIRE_12,SYNTHESIZED_WIRE_12)
BEGIN
IF (SYNTHESIZED_WIRE_12 = '0') THEN
	Y_ALTERA_SYNTHESIZED(2) <= '0';
ELSIF (SYNTHESIZED_WIRE_12 = '0') THEN
	Y_ALTERA_SYNTHESIZED(2) <= '1';
ELSIF (RISING_EDGE(Clk)) THEN
	Y_ALTERA_SYNTHESIZED(2) <= SYNTHESIZED_WIRE_4;
END IF;
END PROCESS;


PROCESS(Clk,SYNTHESIZED_WIRE_12,SYNTHESIZED_WIRE_12)
BEGIN
IF (SYNTHESIZED_WIRE_12 = '0') THEN
	Y_ALTERA_SYNTHESIZED(1) <= '0';
ELSIF (SYNTHESIZED_WIRE_12 = '0') THEN
	Y_ALTERA_SYNTHESIZED(1) <= '1';
ELSIF (RISING_EDGE(Clk)) THEN
	Y_ALTERA_SYNTHESIZED(1) <= SYNTHESIZED_WIRE_7;
END IF;
END PROCESS;


PROCESS(Clk,SYNTHESIZED_WIRE_12,SYNTHESIZED_WIRE_12)
BEGIN
IF (SYNTHESIZED_WIRE_12 = '0') THEN
	Y_ALTERA_SYNTHESIZED(0) <= '0';
ELSIF (SYNTHESIZED_WIRE_12 = '0') THEN
	Y_ALTERA_SYNTHESIZED(0) <= '1';
ELSIF (RISING_EDGE(Clk)) THEN
	Y_ALTERA_SYNTHESIZED(0) <= SYNTHESIZED_WIRE_10;
END IF;
END PROCESS;


Y <= Y_ALTERA_SYNTHESIZED;

END bdf_type;