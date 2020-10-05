library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.aLL;

entity lauflicht is
     port (

            -- -------------------
            -- system           --
            -- -------------------
            
            res1_n_i             : in std_ulogic;  -- system reset
            sys_clk_i            : in std_ulogic;  -- system clock
				
				scl						: in std_logic;
				sda_io					: inout std_logic;
				
				led_o						: out std_ulogic
	);
	
	architecture lauflicht_rtl of lauflicht is
	
	
	begin
	
	
	end lauflicht_rtl;