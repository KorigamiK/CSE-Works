-- Code your design here

library IEEE;
use IEEE.std_logic_1164.all;

entity full_adder is
	port (
		a, b, cin : in  std_logic;
		s, cout   : out std_logic
	);
end;

architecture mydesign of full_adder is
begin
	s    <= a xor b xor cin;
	cout <= (a and b) or (cin and b);
end mydesign;
