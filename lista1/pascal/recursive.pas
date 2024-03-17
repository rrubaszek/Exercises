unit recursive;
interface
function factorial(n: Integer): Integer;
function gcd(a, b: Integer): Integer;
procedure diophantine(a, b, c: Integer; var x, y: Integer);


implementation
function factorial(n: Integer): Integer;
begin  
    if n > 1 then 
        factorial := n * factorial(n-1)
    else
        factorial := 1;
end;

function gcd(a, b: Integer): Integer;
begin
    if b <> 0 then
        gcd := gcd(b, a mod b)
    else
        gcd := a;
end;

procedure diophantine(a, b, c: Integer; var x, y: Integer);  
var 
    temp: Integer;
begin
    if c mod gcd(a, b) <> 0 then 
    begin
        x := -1;
        y := -1;
    end
    else if a mod b = 0 then 
    begin
        x := 0;
        y := c div b;
    end
    else
    begin
        diophantine(b, a mod b, c, x, y);
        temp := y;
        y := x - ((a div b) * y);
        x := temp;   
    end;
end;

end.