library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity LFSR_WhiteNoise is
    Port ( clk : in STD_LOGIC;
           start : in STD_LOGIC;
           white_noise : out STD_LOGIC_VECTOR(31 downto 0));
end LFSR_WhiteNoise;

architecture Behavioral of LFSR_WhiteNoise is
    signal lfsr : STD_LOGIC_VECTOR(31 downto 0) := (others => '0');
    signal lfsr_initialized : BOOLEAN := FALSE;
begin
    process(clk)
    begin
        if rising_edge(clk) then
            if start = '1' and not lfsr_initialized then
                lfsr <= (others => '0');  -- Initialize the LFSR to 0 on the first rising edge after start
                lfsr_initialized <= TRUE;
            else
                -- XOR feedback based on taps at positions 1, 5, 6, and 31
                lfsr(31) <= lfsr(0) xor lfsr(4) xor lfsr(5) xor lfsr(30);
                lfsr(30 downto 0) <= lfsr(31 downto 1);  -- Shift the LFSR to the right
            end if;
        end if;
    end process;

    white_noise <= lfsr;  -- Output the entire LFSR as white noise
end Behavioral;
