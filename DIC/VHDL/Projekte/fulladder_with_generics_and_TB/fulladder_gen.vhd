-- add file header or comment
-- Siegbert Schrempf, 20.06.2011
-- fulladder für HTL Salzburg
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity fulladder_gen is
generic (
  width         : integer := 4
  );
port (
  a_i           : in  std_logic_vector(width-1 downto 0);
  b_i           : in  std_logic_vector(width-1 downto 0);
  sum_o         : out std_logic_vector(width-1 downto 0);
  carry_o       : out std_logic
  );
end entity;


architecture rtl of fulladder_gen is
  
-- signal decleration
signal sum_int : std_logic_vector(width downto 0);
  
begin
  -- use sign extension to get carry bit
  sum_int <= unsigned("0" & a_i) + unsigned("0" & b_i);
  sum_o   <= std_logic_vector(sum_int(width-1 downto 0));
  carry_o <= sum_int(width);

end rtl;

CONFIGURATION fulladder_gen_conf OF fulladder_gen IS 
  FOR rtl
  END FOR;
END fulladder_gen_conf; 

