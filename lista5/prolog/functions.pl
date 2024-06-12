merge(A, [], A).
merge([], B, B).
merge([A | Ra], [B | Rb], [A | M]) :-
    A =< B,
    merge(Ra, [B | Rb], M).
merge([A | Ra], [B | Rb], [B | M]) :-
    A > B,
    merge([A | Ra], Rb, M).

divide(List, FirstHalf, SecondHalf) :-
    length(List, Len),
    HalfLen is Len // 2,
    length(FirstHalf, HalfLen),
    append(FirstHalf, SecondHalf, List).

mergeSort([], []). 
mergeSort([A], [A]).
mergeSort([A, B | Rest], S) :-
    divide([A, B | Rest], L1, L2),
    mergeSort(L1, S1),
    mergeSort(L2, S2),
    merge(S1, S2, S).

gcd(A, 0, A, 1, 0) :- !.
gcd(A, B, G, X, Y) :-
    B \= 0,
    Q is A // B,
    R is A mod B,
    gcd(B, R, G, X1, Y1),
    X is Y1,
    Y is X1 - Q * Y1.

de(A, B, G, X, Y) :-
    gcd(A, B, G, X, Y).

factorize(N, _, []) :-
    N < 2.

factorize(N, Div, Factors) :-
    (N mod Div =:= 0 ->
        NextN is N // Div,
        Factors = [Div | Rest],
        factorize(NextN, Div, Rest)
    ; 
        NextDiv is Div + 1,
        factorize(N, NextDiv, Factors)
    ).
	
primeFactors(N, List):-
	factorize(N, 2, List).

gcd(A, 0, A).
gcd(A, B, GCD) :- 
	B > 0,
	Remainder is A mod B,
	gcd(B, Remainder, GCD).

totientHelper(N, N, Acc, Acc) :- !.
totientHelper(N, A, Acc, X) :-
    A < N,
    gcd(N, A, D),
    (D =:= 1 ->
        NextAcc is Acc + 1
    ; 
        NextAcc is Acc
    ),
    NextA is A + 1,
    totientHelper(N, NextA, NextAcc, X).

totient(N, X) :-
    totientHelper(N, 1, 0, X).

primes(N, List):-
	numlist(2, N, Temp),
	sieve(Temp, List).
	
removeMultiples(_, [], []).
removeMultiples(P, [H | T], [H | Primes]) :-
    (H mod P =:= 0 ->
        removeMultiples(P, T, Primes)
    ; 
        Primes = [H | Rest],
        removeMultiples(P, T, Rest)
    ).

sieve([], []).
sieve([H | T], [H | Primes]) :-
    removeMultiples(H, T, NewList),
    sieve(NewList, Primes).