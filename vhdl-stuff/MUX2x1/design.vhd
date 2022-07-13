-- file: design.vhd

library IEEE;
use IEEE.std_logic_1164.all;

entity MUX2x1 is
	port (
		i0, i1, s : in  std_logic;
		y         : out std_logic
	);
end;

architecture mydesign of MUX2x1 is
begin
	y <= (i1 and s) or ((not s) and i0);
end mydesign;
