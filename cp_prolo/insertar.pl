member(X, [X | _]).
member(X, [_ | As]) :- member(X, As).

append(X, [], [X]).
append(X, [A | Xs], [A | Zs]) :- append(X, Xs, Zs).

conc([], [], []).
conc([], [A | Bs], [A | Bs]).
conc([A | Bs], [], [A | Bs]).
conc([A | As], [C | Cs], [A | Zs]) :- append(C, As, Ms) , conc(Ms, Cs, Zs).

insertar(X, As, [X | As]). % works with two variables. 
insertar(X, [A | Bs], [A | Z1s] ) :- insertar( X, Bs, Z1s).

perm([], []).
perm(Xs, [A | Ys]) :-
    var(Xs), ! ,  perm(Ts, Ys), insertar(A, Ts, Xs).
perm([A | Ys], Xs) :-
    var(Xs), perm(Ys, Ts), insertar(A, Ts, Xs).

len([], 0).
len([_ |Xs] , Len) :-
    integer(Len), Len > 0, Len1 is Len-1, len(Xs, Len1).
len([_ | Xs], Len) :-
    var(Len), len(Xs, Len1), Len is Len1+1.

% returns true if Y > X.
mayor(X, Y) :- var(Y), Y is X+1.
mayor(X, Y) :- var(Y), Z is X+1, mayor(Y, Z).
mayor(X, Y) :- var(X), X is Y-1.
mayor(X, Y) :- var(X), Z is Y-1, mayor(X, Z).
mayor(X, Y) :- nonvar(X), nonvar(Y), X < Y.

mayorIgual(X, Y) :- var(Y), Y is X.
mayorIgual(X, Y) :- var(Y), Z is X+1, mayor(Y, Z).
mayorIgual(X, Y) :- var(X), X is Y.
mayorIgual(X, Y) :- var(X), Z is Y-1, mayor(X, Z).
mayorIgual(X, Y) :- nonvar(X), nonvar(Y), X =< Y.

	   
insertar_sort(X, [], [X]).
insertar_sort(X, [Y | Xs], [X, Y | Xs]) :- mayorIgual(X, Y).
insertar_sort(X, [Y | Xs], [Y | Ms]) :- mayor(Y, X), insertar_sort(X, Xs, Ms).

% this only work to sort the array, not to generate the permutations
% of the array. is there any way of obtain that ?
insertion_sort([], []).
insertion_sort([X | Xs], Ts) :-
    insertion_sort(Xs, Rs),
    insertar_sort(X, Rs, Ts).

max([X], X).
max([X, Y], Y) :- mayorIgual(X, Y).
max([X, Y], X) :- mayor(Y, X).
max([X, Y, Z | Zs], M) :- 
    max([X, Y], M1), 
    max([Z | Zs], M2),
    max([M1, M2], M).
