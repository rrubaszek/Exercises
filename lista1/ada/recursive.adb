package body Recursive is

    function Factorial(N : Integer) return Integer is
    begin
        if N > 0 then
            return N * Factorial(N-1);
        else
            return 1;
        end if;
    end Factorial;

    function GCD(A, B : Integer) return Integer is
    begin 
        if B /= 0 then  
            return GCD(B, A mod B);
        else
            return A;
        end if;
    end GCD;

    procedure Diophantine(A, B, C : Integer; X, Y : out Integer) is
    Temp : Integer;
    begin
        if (C mod GCD(A, B)) /= 0 then
            X := -1;
            Y := -1;
        elsif A mod B = 0 then
            X := 0;
            Y := C / B;
        else
            Diophantine(B, A mod B, C, X, Y);
            Temp := Y;
            Y := X - ((A / B) * Y);
            X := Temp;
        end if;
    end Diophantine;

end Recursive;