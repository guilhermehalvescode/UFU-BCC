%a
/* 
nu(X, Y) :-
    \+ X = Y. 
*/

%b
/* 
nu(X, Y) :-
    X = Y, !,
    fail.
nu(_,_). 
*/

%c
/* 
nu(X, X) :- !,fail.
nu(_, _). 
*/
