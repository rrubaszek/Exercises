program pascal_test;
uses pascal_wrapper, ctypes;

var
    n, a, b, c, d, e: ctypes.cint32;
    x, y: ctypes.cint32;
begin
    n := 5;
    a := 30;
    b := 25;
    c := 4;
    d := 7;
    e := 8;
    // Call the C function to calculate factorial
    writeln('Factorial: ', pascal_wrapper.factorial(n));
    writeln('GCD: ', pascal_wrapper.gcd(a, b));
    pascal_wrapper.diophantine(c, d, e, x, y);
     writeln('X=', x , 'Y=', y);
end.