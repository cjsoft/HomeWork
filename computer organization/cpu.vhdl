library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity cpu is
    port(
            SWD: in std_logic_vector(2 downto 0);
            IR: in std_logic_vector(7 downto 4);
            C, Z: in std_logic;
            CLR: in std_logic;
            T3: in std_logic;
            W1, W2, W3: in std_logic;
            SHORT, LONG, STOP: out std_logic;
            ABUS, LDZ, LDC, M, CIN: out std_logic;
            S: out std_logic_vector(3 downto 0);
            SBUS: out std_logic;
            MBUS, MEMW, LAR, PCINC, ARINC, PCADD, LPC: out std_logic;
            SEL: out std_logic_vector(3 downto 0);
            SELCTL, DRW: out std_logic;
            LIR: out std_logic;
        );
end cpu;

architecture design of cpu is
    signal ST0: std_logic;
    signal SST0: std_logic;
begin
    process(SWD, IR, T3, W1, W2, W3, ST0, SST0)
    begin
        if (not CLR)
    end process;

    process(CLR)
    begin
        ST0 <= '0';
        SST0 <= '0';
        SHORT <= '0';
        LONG <= '0';
        STOP <= '0';
        ABUS <= '0';
        LDZ <= '0';
        LDC <= '0';
        M <= '0';
        CIN <= '0';
        S <= "0000";
        SBUS <= '0';
        MBUS <= '0';
        MEMW <= '0';
        LAR <= '0';
        PCINC <= '0';
        ARINC <= '0';
        PCADD <= '0';
        LPC <= '0';
        SEL <= "0000";
        SELCTL <= '0';
        DRW <= '0';
        LIR <= '0';
    end process;
end design;
