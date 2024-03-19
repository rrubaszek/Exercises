{ fpc test.pas }

program test;
uses iterative, recursive;

var
  number, a, b, c, d, e: Integer;
  x, y: Integer;

begin

  writeln('Enter a number to calculate factorial: ');
  Readln(number);
  writeln('Enter two numbers to calculate gcd: ');
  Readln(a, b);
  writeln('Enter three coefficients to calculate diophantine eq: ');
  Readln(c, d, e);

  writeln('Factorial: ', iterative.factorial(number));
  writeln('GCD: ', iterative.gcd(a, b));
  iterative.diophantine(c, d, e, x, y);
  writeln('X=', x, 'Y=', y);

  writeln('Factorial: ', recursive.factorial(number));
  writeln('GCD: ', recursive.gcd(a, b));
  recursive.diophantine(c, d, e, x, y);
  writeln('X=', x, 'Y=', y);

end.