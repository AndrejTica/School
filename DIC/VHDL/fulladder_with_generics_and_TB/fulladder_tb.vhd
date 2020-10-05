library ieee;
use ieee.std_logic_1164.all;
--use ieee.std_logic_textio.all;
use ieee.std_logic_arith.all;
--use std.textio.all;


entity fulladder_tb is
end entity fulladder_tb;

architecture beh of fulladder_tb is

constant width           : integer := 4;
-- component declarations
  
  component fulladder_gen
  generic ( width         : integer := 4
    	  );
  port (
    a_i           : in  std_logic_vector(width-1 downto 0);
    b_i           : in  std_logic_vector(width-1 downto 0);
    sum_o         : out std_logic_vector(width-1 downto 0);
    carry_o       : out std_logic
    );
  end component;


--signal declarations
  signal a	      : std_logic_vector(width-1 downto 0);
  signal b	      : std_logic_vector(width-1 downto 0);
  signal sum          : std_logic_vector(width-1 downto 0);
  signal carry        : std_logic;
  
begin

 -- port map fulladder
 dut: fulladder_gen
    generic map ( width => width
    )
    port map (
      a_i       => a,
      b_i       => b,
      sum_o     => sum,
      carry_o   => carry
      );
      
control_tb: process
begin
  
  --
  wait for 10 us;
  a <= "0110";
  b <= "1100";
  wait for 100 us;
  
  -- 
  a <= "0111";
  b <= "0011";
  wait for 100 us;
    
  wait;
  
end process;
      
end beh;



-- configuration 
configuration fulladder_tb_conf of fulladder_tb is 

  for beh
  
    for dut: fulladder_gen
      use configuration work.fulladder_gen_conf;
    end for;
    
  end for;

end fulladder_tb_conf;

