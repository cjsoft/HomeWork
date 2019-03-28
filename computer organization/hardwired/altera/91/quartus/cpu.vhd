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
            LIR: out std_logic
        );
end cpu;

architecture design of cpu is
    signal ST: std_logic;
    signal SST: std_logic;
    signal EXEC: std_logic;
    type instruction is (iadd, isub, iand, iinc, ild, ist, ijc, ijz, ijmp, iout, istp);
    procedure softclr is
    begin
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
    end procedure;
begin
    process(CLR, SWD, W1, W2, W3, SST, ST, T3, IR)
    begin
        softclr;
        if (CLR = '1') then
            if (T3'event and T3 = '0') then
                if (SST = '1') then
                    ST <= '1';
                end if;
            end if;
            case SWD is
                when "100" =>       -- register write
                    SST <= W2 and not ST;
                    STOP <= '1';
                    SBUS <= '1';
                    SELCTL <= '1';
                    DRW <= '1';
                    if (W1 = '1' and ST = '0') then
                        SEL <= "0011";
                    end if;
                    if (W2 = '1' and ST = '0') then
                        SEL <= "0100";
                    end if;
                    if (W1 = '1' and ST = '1') then
                        SEL <= "1001";
                    end if;
                    if (W2 = '1' and ST = '1') then
                        SEL <= "1110";
                    end if;
                when "011" =>       -- register read
                    STOP <= '1';
                    SELCTL <= '1';
                    if (W1 = '1') then
                        SEL <= "0001";
                    end if;
                    if (W2 = '1') then
                        SEL <= "1011";
                    end if;
                when "010" =>       -- memory read
                    SHORT <= '1';
                    SST <= not ST;
                    STOP <= '1';
                    SBUS <= not ST;
                    MBUS <= ST;
                    LAR <= not ST;
                    ARINC <= ST;
                    SELCTL <= '1';
                when "001" =>       -- memory write
                    SHORT <= '1';
                    SST <= not ST;
                    STOP <= '1';
                    SBUS <= '1';
                    MEMW <= ST;
                    LAR <= not ST;
                    ARINC <= ST;
                    SELCTL <= '1';
                when "000" =>
                    if (W1 = '1') then
                        if (ST = '0') then
                            SBUS <= '1';
                            LPC <= '1';
                            SHORT <= '1';
                            SST <= '1';
                            STOP <= '0';
                        else 
                            LIR <= '1';
                            PCINC <= '1';
                        end if;
                    else
                        if (IR = "0001") then -- add
                            ABUS <= W2;
                            LDZ <= W2;
                            LDC <= W2;
                            CIN <= W2;
                            DRW <= W2;
                            if (W2 = '1') then
                                S <= "1001";
                            end if;
                        end if;
                        if (IR = "0010") then -- sub
                            ABUS <= W2;
                            LDZ <= W2;
                            LDC <= W2;
                            DRW <= W2;
                            if (W2 = '1') then
                                S <= "0110";
                            end if;
                        end if;
                        if (IR = "0011") then -- and
                            ABUS <= W2;
                            LDZ <= W2;
                            M <= W2;
                            DRW <= W2;
                            if (W2 = '1') then
                                S <= "1011";
                            end if;
                        end if;
                        if (IR = "0100") then -- inc
                            ABUS <= W2;
                            LDZ <= W2;
                            LDC <= W2;
                            DRW <= W2;
                            if (W2 = '1') then
                                S <= "0000";
                            end if;
                        end if;
                        if (IR = "0101") then -- ld
                            LONG <= W2;
                            ABUS <= W2;
                            M <= W2;
                            MBUS <= W3;
                            LAR <= W2;
                            DRW <= W3;
                            if (W2 = '1') then
                                S <= "1010";
                            end if;
                        end if;
                        if (IR = "0110") then -- st
                            LONG <= W2;
                            ABUS <= '1';
                            M <= '1';
                            MEMW <= W3;
                            LAR <= W2;
                            if (W2 = '1') then
                                S <= "1111";
                            end if;
                            if (W3 = '1') then
                                S <= "1010";
                            end if;
                        end if;
                        if (IR = "0111") then -- jc
                            PCADD <= C and W2;
                        end if;
                        if (IR = "1000") then -- jz
                            PCADD <= Z and W2;
                        end if;
                        if (IR = "1001") then -- jmp
							ABUS <= W2;
                            M <= W2;
                            LPC <= W2;
                            if (W2 = '1') then
                                S <= "1111";
                            end if;
                        end if;
                        if (IR = "1010") then -- out
                            ABUS <= W2;
                            M <= W2;
                            if (W2 = '1') then
                                S <= "1010";
                            end if;
                        end if;
                        if (IR = "1110") then -- stp
                            STOP <= '1';
                        end if;

                        if (IR = "1011") then -- or
                            ABUS <= W2;
                            LDZ <= W2;
                            M <= W2;
                            DRW <= W2;
                            if (W2 = '1') then
                                S <= "1110";
                            end if;
                        end if;

                        if (IR = "1100") then -- xor
                            ABUS <= W2;
                            LDZ <= W2;
                            M <= W2;
                            DRW <= W2;
                            if (W2 = '1') then
                                S <= "0110";
                            end if;
                        end if;

                        if (IR = "1101") then -- not
                            ABUS <= W2;
                            LDZ <= W2;
                            M <= W2;
                            DRW <= W2;
                            if (W2 = '1') then
                                S <= "0101";
                            end if;
                        end if;

                    end if;
                when others =>
            end case;
        else
            ST <= '0';
            SST <= '0';
        end if;
    end process;
    


end design;
