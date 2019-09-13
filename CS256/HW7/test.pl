
isOdd(N) :-1 is mod(N,2).

addOdds(N,0) :- N>=20.

addOdds(N,Sum) :-
N<20, isOdd(N), M is N+1, addOdds(M,SumM), Sum is SumM + N.

addOdds(N,Sum) :-
N<20,\+ isOdd(N), M is N+1, addOdds(M,SumM), Sum is SumM.
