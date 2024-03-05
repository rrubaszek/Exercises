package body Iterative is

    function Factorial(N : Integer) return Integer is
    Result : Integer := 1;
    Temp : Integer := N;
    begin 
        while Temp > 1 loop
            Result := Result * Temp;
            Temp := Temp - 1;
        end loop;
        return Result;
    end Factorial;

    function GCD(A, B : Integer) return Integer is
    X : Integer := A;
    Y : Integer := B;

    begin
        if X = 0 then
            return Y;
        elsif Y = 0 then
            return X;
        end if;

        while X /= Y loop
            if X > Y then
                X := X - Y;
            else
                Y := Y - X;
            end if;
        end loop;
        return X;
    end GCD;

    procedure Diophantine(A, B, C : Integer; X, Y : out Integer) is
    A_copy : Integer := A;
    B_copy : Integer := B;
    C_copy : Integer := C;

    X_prev, Y_next : Integer := 1;
    X_next, Y_prev : Integer := 0;

    Quotient, Temp, Reminder : Integer;

    begin 
        while B_copy /= 0 loop
            Quotient := A_copy / B_copy;
            Temp := X_prev;
            X_prev := X_next;
            X_next := Temp - Quotient * X_next;

            Temp := Y_prev;
            Y_prev := Y_next;
            Y_next := Temp - Quotient * Y_next;

            Reminder := A_copy mod B_copy;
            A_copy := B_copy;
            B_copy := Reminder;
        end loop;

        if C_copy mod A_copy /= 0 then
            X := -1;
            Y := -1;
        else
            X := X_prev * (C_copy / A_copy);
            Y := Y_prev * (C_copy / A_copy);
        end if;
    end Diophantine;

end Iterative;
        