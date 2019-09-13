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
-- CREATED		"Mon Oct 24 21:19:37 2011"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY ALU IS 
	PORT
	(
		M :  IN  STD_LOGIC;
		S3 :  IN  STD_LOGIC;
		S2 :  IN  STD_LOGIC;
		A :  IN  STD_LOGIC_VECTOR(3 DOWNTO 0);
		B :  IN  STD_LOGIC_VECTOR(3 DOWNTO 0);
		COUT :  OUT  STD_LOGIC;
		F :  OUT  STD_LOGIC_VECTOR(3 DOWNTO 0)
	);
END ALU;

ARCHITECTURE bdf_type OF ALU IS 

COMPONENT fulladd
	PORT(A : IN STD_LOGIC;
		 B : IN STD_LOGIC;
		 C : IN STD_LOGIC;
		 S : OUT STD_LOGIC;
		 CY : OUT STD_LOGIC
	);
END COMPONENT;

COMPONENT le
	PORT(A : IN STD_LOGIC;
		 B : IN STD_LOGIC;
		 S2 : IN STD_LOGIC;
		 S3 : IN STD_LOGIC;
		 M : IN STD_LOGIC;
		 Q : OUT STD_LOGIC
	);
END COMPONENT;

COMPONENT ae
	PORT(B : IN STD_LOGIC;
		 S2 : IN STD_LOGIC;
		 S3 : IN STD_LOGIC;
		 M : IN STD_LOGIC;
		 P : OUT STD_LOGIC
	);
END COMPONENT;

SIGNAL	F_ALTERA_SYNTHESIZED :  STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL	SYNTHESIZED_WIRE_0 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_1 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_2 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_3 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_4 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_5 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_6 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_7 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_8 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_9 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_10 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_11 :  STD_LOGIC;


BEGIN 



b2v_inst : fulladd
PORT MAP(A => SYNTHESIZED_WIRE_0,
		 B => SYNTHESIZED_WIRE_1,
		 C => SYNTHESIZED_WIRE_2,
		 S => F_ALTERA_SYNTHESIZED(0),
		 CY => SYNTHESIZED_WIRE_11);


b2v_inst10 : le
PORT MAP(A => A(2),
		 B => B(2),
		 S2 => S2,
		 S3 => S3,
		 M => M,
		 Q => SYNTHESIZED_WIRE_3);


b2v_inst11 : ae
PORT MAP(B => B(2),
		 S2 => S2,
		 S3 => S3,
		 M => M,
		 P => SYNTHESIZED_WIRE_4);


b2v_inst12 : fulladd
PORT MAP(A => SYNTHESIZED_WIRE_3,
		 B => SYNTHESIZED_WIRE_4,
		 C => SYNTHESIZED_WIRE_5,
		 S => F_ALTERA_SYNTHESIZED(2),
		 CY => SYNTHESIZED_WIRE_8);


b2v_inst13 : le
PORT MAP(A => A(3),
		 B => B(3),
		 S2 => S2,
		 S3 => S3,
		 M => M,
		 Q => SYNTHESIZED_WIRE_6);


b2v_inst14 : ae
PORT MAP(B => B(3),
		 S2 => S2,
		 S3 => S3,
		 M => M,
		 P => SYNTHESIZED_WIRE_7);


b2v_inst15 : fulladd
PORT MAP(A => SYNTHESIZED_WIRE_6,
		 B => SYNTHESIZED_WIRE_7,
		 C => SYNTHESIZED_WIRE_8,
		 S => F_ALTERA_SYNTHESIZED(3),
		 CY => COUT);


SYNTHESIZED_WIRE_2 <= M AND S3;


b2v_inst5 : le
PORT MAP(A => A(0),
		 B => B(0),
		 S2 => S2,
		 S3 => S3,
		 M => M,
		 Q => SYNTHESIZED_WIRE_0);


b2v_inst6 : ae
PORT MAP(B => B(0),
		 S2 => S2,
		 S3 => S3,
		 M => M,
		 P => SYNTHESIZED_WIRE_1);


b2v_inst7 : le
PORT MAP(A => A(1),
		 B => B(1),
		 S2 => S2,
		 S3 => S3,
		 M => M,
		 Q => SYNTHESIZED_WIRE_9);


b2v_inst8 : ae
PORT MAP(B => B(1),
		 S2 => S2,
		 S3 => S3,
		 M => M,
		 P => SYNTHESIZED_WIRE_10);


b2v_inst9 : fulladd
PORT MAP(A => SYNTHESIZED_WIRE_9,
		 B => SYNTHESIZED_WIRE_10,
		 C => SYNTHESIZED_WIRE_11,
		 S => F_ALTERA_SYNTHESIZED(1),
		 CY => SYNTHESIZED_WIRE_5);

F <= F_ALTERA_SYNTHESIZED;

END bdf_type;