LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY circuit IS
  PORT (
    a : IN STD_LOGIC;
    b : IN STD_LOGIC;
    cout : OUT STD_LOGIC;
    sum : OUT STD_LOGIC
  );
END circuit;

ARCHITECTURE adder OF circuit IS

BEGIN
  cout <= a XOR b;
  sum <= a AND b;
END ARCHITECTURE;