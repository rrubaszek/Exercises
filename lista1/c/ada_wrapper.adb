with Interfaces.C; use Interfaces.C;
with Ada.Text_IO; use Ada.Text_IO;

procedure Ada_wrapper is
    function factorial(n : Integer) return Integer 
        with
            Import => True,
            Convention => C;

    function gcd(a, b : Integer) return Integer
        with
            Import => True,
            Convention => C;

    procedure diophantine(a, b, c : Integer; x, y : out Integer)
        with
            Import => True,
            Convention => C;

    F : Integer;
    G : Integer;  
    X, Y : Integer;      
begin
    F := factorial(5);
    G := gcd(30, 25);
    diophantine(4, 7, 8, X, Y);

    Put_Line("Factorial:" & Integer'Image(F));
    Put_Line("GCD:" & Integer'Image(G));
    Put_Line("X=" & Integer'Image(X) & " Y=" & Integer'Image(Y));

end Ada_wrapper;