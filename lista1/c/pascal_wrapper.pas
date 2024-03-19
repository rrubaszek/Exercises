unit pascal_wrapper;

{$link wrapper.o}
{$linklib c}

interface
uses CTypes;

function factorial(n : ctypes.cint32): ctypes.cint32; cdecl; external;

function gcd(a, b : ctypes.cint32): ctypes.cint32; cdecl; external;

procedure diophantine(a, b, c: ctypes.cint32; var x, y: ctypes.cint32); cdecl; external;
implementation

end.
