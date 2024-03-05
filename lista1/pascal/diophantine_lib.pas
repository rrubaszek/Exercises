unit diophantine_lib;
interface
function factorial(n: Integer): Integer;

implementation
function factorial(n: Integer): Integer;
begin  
    if n > 1 then 
        factorial := n * factorial(n-1)
    else
        factorial := 1;
end;

end.