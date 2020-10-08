LIBRARY ieee ;

USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.ALL;

entity light is
	port (
		res_in : in std_logic;
		clk_in : in std_logic;
		
		data_o  : out std_ulogic_Vector(7 downto 0));
end light;

architecture light_beahave of light is

constant L0     : std_ulogic_vector (7 downto 0) := "00000001";
constant L1     : std_ulogic_vector (7 downto 0) := "00000010";
constant L2     : std_ulogic_vector (7 downto 0) := "00000100";
constant L3     : std_ulogic_vector (7 downto 0) := "00001000";
constant L4     : std_ulogic_vector (7 downto 0) := "00010000";
constant L5     : std_ulogic_vector (7 downto 0) := "00100000";
constant L6     : std_ulogic_vector (7 downto 0) := "01000000";
constant L7     : std_ulogic_vector (7 downto 0) := "10000000";

constant UP     : std_ulogic := '1';
constant DOWN   : std_ulogic := '0';

signal counter : unsigned(21 downto 0);
signal led_cnt : std_ulogic_vector(7 downto 0);  -- running light
signal dir     : std_ulogic;

-- End declaration

begin

   -- counter
	cnt_proc : process( clk_in, res_in )
	begin
		if ( res_in = '0' ) then
			counter <= ( others => '0' );
		elsif ( clk_in'event and clk_in = '1' ) then
			counter <= counter + 1;
	   end if;
	end process;
	
	-- select leds
	led_porc : process ( clk_in, res_in )
	begin
		if ( res_in = '0' ) then
			led_cnt <= "01010101"; -- L0;
	   elsif ( clk_in'event and clk_in = '1' ) then
			if ( counter = 0 ) then
				case led_cnt & dir is
					when L0 & DOWN => led_cnt <= L1;
					when L1 & DOWN => led_cnt <= L2;
					when L2 & DOWN => led_cnt <= L3;
					when L3 & DOWN => led_cnt <= L4;
					when L4 & DOWN => led_cnt <= L5;
					when L5 & DOWN => led_cnt <= L6;
					when L6 & DOWN => led_cnt <= L7;
					-- when L7 & DOWN => led_cnt <= L7;
					
					when L7 &  UP => led_cnt <= L6;
					when L6 &  UP => led_cnt <= L5;
					when L5 &  UP => led_cnt <= L4;
					when L4 &  UP => led_cnt <= L3;
					when L3 &  UP => led_cnt <= L2;
					when L2 &  UP => led_cnt <= L1;
					when L1 &  UP => led_cnt <= L0;
					when L0 &  UP => led_cnt <= L7;
					
					when others => led_cnt <= L0;
					
				end case;
				
			end if;
		end if;
   end process;

	dir_proc : process ( clk_in, res_in )
	begin
		if ( res_in = '0' ) then
			dir     <= DOWN;
	   elsif ( clk_in'event and clk_in = '1' ) then
		   if ( counter = 0 and led_cnt = L6 and dir = DOWN ) then
					dir <= UP;
			elsif ( counter = 0 and led_cnt = L1 and dir = UP ) then
					dir <= DOWN;
			end if;
		end if;
	end process;
	
	
	data_o <= led_cnt;

end light_beahave;