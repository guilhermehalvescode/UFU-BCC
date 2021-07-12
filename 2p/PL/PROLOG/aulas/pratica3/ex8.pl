
inverte([], X, X).

inverte([H|Hs], X, Z) :-
    inverte(Hs, [H|X], Z).
    
inverte(L, X) :-
    inverte(L, [], X). 
    
palindromo(L, L).
palindromo(L) :-
    inverte(L, L).

/*
1.true
2.true
3.true
4.true
5.true 
 */