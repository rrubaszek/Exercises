{ fpc hello.pas }

program test;
uses diophantine_lib;

var
  number, result: Integer;

begin

  writeln('Enter a number to calculate factorial: ');
  Readln(number);

  result := diophantine_lib.factorial(number);

  writeln('Factorial: ', result);

end.