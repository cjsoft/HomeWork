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
                    STOP <= W1 or W2;
                    SBUS <= W1 or W2;
                    SELCTL <= W1 or W2;
                    DRW <= W1 or W2;
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
                    STOP <= W1 or W2;
                    SELCTL <= W1 or W2;
                    if (W1 = '1') then
                        SEL <= "0001";
                    end if;
                    if (W2 = '1') then
                        SEL <= "1011";
                    end if;
                when "010" =>       -- memory read
                    SHORT <= W1;
                    SST <= (not ST) and W1;
                    STOP <= W1;
                    SBUS <= (not ST) and W1;
                    MBUS <= ST and W1;
                    LAR <= (not ST) and W1;
                    ARINC <= ST and W1;
                    SELCTL <= W1;
                when "001" =>       -- memory write
                    SHORT <= W1;
                    SST <= (not ST) and W1;
                    STOP <= W1;
                    SBUS <= W1;
                    MEMW <= ST and W1;
                    LAR <= (not ST) and W1;
                    ARINC <= ST and W1;
                    SELCTL <= W1;
                when "000" =>
                    -- /* if (W1 = '1') then */
                    -- /*     if (ST = '0') then */
                    -- /*         SBUS <= W1; */
                    -- /*         LPC <= W1; */
                    -- /*         SHORT <= W1; */
                    -- /*         SST <= W1; */
                    -- /*         STOP <= '0'; */
                    -- /*     else */ 
                    -- /*         LIR <= W1; */
                    -- /*         PCINC <= W1; */
                    -- /*     end if; */
                    -- /* else */
                        if (IR = "0000") then -- nop
                            if (ST = '0') then
								SHORT <= W1;
								SBUS <= W1;
								LPC <= W1;
								SST <= W1;
								STOP <= '0';
                            else
								SHORT <= W1;
								PCINC <= W1;
								LIR <= W1;
                            end if;
                            -- SBUS <= W1;
                            -- LPC <= W1;
                            -- if (W1 = '1') then
                            --     STOP <= '0';
                            -- end if;
                            -- LIR <= W2;
                            -- PCINC <= W2;
                        end if;
                        if (IR = "0001") then -- add
                            SHORT <= W1;
                            PCINC <= W1;
                            LIR <= W1;

                            ABUS <= W1;
                            LDZ <= W1;
                            LDC <= W1;
                            CIN <= W1;
                            DRW <= W1;
                            if (W1 = '1') then
                                S <= "1001";
                            end if;
                        end if;
                        if (IR = "0010") then -- sub
                            SHORT <= W1;
                            PCINC <= W1;
                            LIR <= W1;

                            ABUS <= W1;
                            LDZ <= W1;
                            LDC <= W1;
                            DRW <= W1;
                            if (W1 = '1') then
                                S <= "0110";
                            end if;
                        end if;
                        if (IR = "0011") then -- and
                            SHORT <= W1;
                            PCINC <= W1;
                            LIR <= W1;

                            ABUS <= W1;
                            LDZ <= W1;
                            M <= W1;
                            DRW <= W1;
                            if (W1 = '1') then
                                S <= "1011";
                            end if;
                        end if;
                        if (IR = "0100") then -- inc
                            SHORT <= W1;
                            PCINC <= W1;
                            LIR <= W1;

                            ABUS <= W1;
                            LDZ <= W1;
                            LDC <= W1;
                            DRW <= W1;
                            if (W1 = '1') then
                                S <= "0000";
                            end if;
                        end if;
                        if (IR = "0101") then -- ld
                            LIR <= W2;
                            PCINC <= W2;

                            LONG <= W1;
                            ABUS <= W1;
                            M <= W1;
                            MBUS <= W2;
                            LAR <= W1;
                            DRW <= W2;
                            if (W1 = '1') then
                                S <= "1010";
                            end if;
                        end if;
                        if (IR = "0110") then -- st
                            LIR <= W2;
                            PCINC <= W2;

                            ABUS <= W1 or W2;
                            M <= W1 or W2;
                            MEMW <= W2;
                            LAR <= W1;
                            if (W1 = '1') then
                                S <= "1111";
                            end if;
                            if (W2 = '1') then
                                S <= "1010";
                            end if;
                        end if;
                        if (IR = "0111") then -- jc
                            SHORT <= (not C) and W1;
                            PCINC <= (not C) or (W2 and C);
                            LIR <= (not C) or (W2 and C);
                            PCADD <= C and W2;
                        end if;
                        if (IR = "1000") then -- jz
                            SHORT <= (not Z) and W1;
                            PCINC <= (not Z) or (W2 and Z);
                            LIR <= (not Z) or (W2 and Z);
                            PCADD <= Z and W2;
                        end if;
                        if (IR = "1001") then -- jmp
                            PCINC <= W2;
                            LIR <= W2;

							ABUS <= W1;
                            M <= W1;
                            LPC <= W1;
                            if (W1 = '1') then
                                S <= "1111";
                            end if;
                        end if;
                        if (IR = "1010") then -- out
                            SHORT <= W1;
                            LIR <= W1;
                            PCINC <= W1;

                            ABUS <= W1;
                            M <= W1;
                            if (W1 = '1') then
                                S <= "1010";
                            end if;
                        end if;
                        if (IR = "1110") then -- stp
                            STOP <= W1;
                        end if;

                        if (IR = "1011") then -- or
                            SHORT <= W1;
                            PCINC <= W1;
                            LIR <= W1;

                            ABUS <= W1;
                            LDZ <= W1;
                            M <= W1;
                            DRW <= W1;
                            if (W1 = '1') then
                                S <= "1110";
                            end if;
                        end if;

                        if (IR = "1100") then -- xor
                            SHORT <= W1;
                            PCINC <= W1;
                            LIR <= W1;

                            ABUS <= W1;
                            LDZ <= W1;
                            M <= W1;
                            DRW <= W1;
                            if (W1 = '1') then
                                S <= "0110";
                            end if;
                        end if;

                        if (IR = "1101") then -- not
                            SHORT <= W1;
                            PCINC <= W1;
                            LIR <= W1;

                            ABUS <= W1;
                            LDZ <= W1;
                            M <= W1;
                            DRW <= W1;
                            if (W1 = '1') then
                                S <= "0101";
                            end if;
                        end if;

                    -- /* end if; */
                when others =>
            end case;
        else
            ST <= '0';
            SST <= '0';
        end if;
    end process;
    


end design;
