with Ada.Text_IO; 
with Recursive; use Recursive;
with Iterative; use Iterative;

procedure Test is
    use Ada.Text_IO;

    N : Integer := 5;

    A : Integer := 25;
    B : Integer := 30;

    C : Integer := 4;
    D : Integer := 6;
    E : Integer := 90;

    X, Y : Integer;

begin  

    Put_Line("Factorial of" & Integer'Image(N) & " is" & Integer'Image(Recursive.Factorial(N)));

    Put_Line("Iterative factorial of" & Integer'Image(N) & " is" & Integer'Image(Iterative.Factorial(N)));

    Put_Line("GCD of" & Integer'Image(A) & " and" & Integer'Image(B) & " is" & Integer'Image(Recursive.GCD(A, B)));

    Put_Line("Iterative GCD of" & Integer'Image(A) & " and" & Integer'Image(B) & " is" & Integer'Image(Iterative.GCD(A, B)));

    --Recursive.Diophantine(C, D, E, X, Y);

    Iterative.Diophantine(C, D, E, X, Y);

    Put_Line("Diophantine x:" & Integer'Image(X));

    Put_Line("Diophantine y:" & Integer'Image(Y));

end Test;