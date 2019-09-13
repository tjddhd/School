
isEven(N) :- 0 is mod(N, 2).

addFibs(fibStart, fibEnd, 0) :- fibEnd >= 4000000.

addFibs(fibStart, fibEnd, Sum) :-
fibEnd < 4000000, isEven(fibStart), newEnd is (fibEnd + fibStart), addFibs(fibEnd, newEnd, SumFib), Sum is SumFib + fibStart.

addFibs(fibStart, fibEnd, Sum) :-
fibEnd < 4000000,\+ isEven(fibStart), newEnd is (fibEnd + fibStart), addFibs(fibEnd, newEnd, SumFib), Sum is SumFib.

