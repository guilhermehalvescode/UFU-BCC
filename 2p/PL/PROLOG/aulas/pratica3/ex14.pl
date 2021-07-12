multiEsc(_, [], []).

multiEsc(X, [H|Hs], [W|Ws]) :-
    W is H * X,
    multiEsc(X, Hs, Ws).
