unit iterative;
interface
function factorial(n: Integer): Integer;
function gcd(a, b: Integer): Integer;
procedure diophantine(a, b, c: Integer; var x, y: Integer);

implementation
function factorial(n: Integer): Integer;
var
    result, temp: Integer;
begin
    result := 1;
    temp := n; 
    while temp > 1 do
    begin
        result := result * temp;
        temp := temp - 1;
    end;
    factorial := result;
end;

function gcd(a, b: Integer): Integer;
begin
    if a = 0 then
        gcd := b
    else if b = 0 then
        gcd := a;

    while a <> b do
    begin
        if a > b then
            a := a - b
        else
            b := b - a;
    end;
    gcd := a;
end;

procedure diophantine(a, b, c: Integer; var x, y: Integer);
var
    X_prev, Y_next: Integer;
    X_next, Y_prev: Integer;
    Quotient, Temp, Reminder : Integer;
begin
    X_prev := 1;
    Y_next := 1;
    X_next := 0;
    Y_prev := 0;
    
    while b <> 0 do
    begin
        Quotient := a div b;
        Temp := X_prev;
        X_prev := X_next;
        X_next := Temp - Quotient * X_next;

        Temp := Y_prev;
        Y_prev := Y_next;
        Y_next := Temp - Quotient * Y_next;

        Reminder := a mod b;
        a := b;
        b := Reminder;
    end;

    if c mod a <> 0 then
    begin
        X := -1;
        Y := -1;
    end
    else
    begin
        X := X_prev * (c div a);
        Y := Y_prev * (c div a);
    end;
end;

end.