with interfaces.C; use interfaces.C;

package Recursive is

    function Factorial(N : Integer) return Integer
        with 
            Export        => True,
            Convention    => C,
            External_Name => "factorial_c";

    function GCD(A, B : Integer) return Integer
        with 
            Export        => True,
            Convention    => C,
            External_Name => "gcd_c";

    procedure Diophantine(A, B, C : Integer; X, Y : out Integer)
        with 
            Export        => True,
            Convention    => C,
            External_Name => "diophantine_c";

end Recursive;