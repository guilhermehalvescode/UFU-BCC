membro(X,[X|_]).
membro(X,[_|T]):-
    membro(X,T).

/* 
membro(a,[1,2,a,b]) 
[trace] 2 ?- membro(a,[1,2,a,b]).
   Call: (10) membro(a, [1, 2, a, b]) ? creep
   Call: (11) membro(a, [2, a, b]) ? creep
   Call: (12) membro(a, [a, b]) ? creep
   Exit: (12) membro(a, [a, b]) ? creep
   Exit: (11) membro(a, [2, a, b]) ? creep
   Exit: (10) membro(a, [1, 2, a, b]) ? creep
true ;
   Redo: (12) membro(a, [a, b]) ? creep
   Call: (13) membro(a, [b]) ? creep
   Call: (14) membro(a, []) ? creep
   Fail: (14) membro(a, []) ? creep
   Fail: (13) membro(a, [b]) ? creep
   Fail: (12) membro(a, [a, b]) ? creep
   Fail: (11) membro(a, [2, a, b]) ? creep
   Fail: (10) membro(a, [1, 2, a, b]) ? creep
false.

membro(z,[1,2,a,b]).
[trace] 3 ?- membro(z,[1,2,a,b]). 
   Call: (10) membro(z, [1, 2, a, b]) ? creep
   Call: (11) membro(z, [2, a, b]) ? creep
   Call: (12) membro(z, [a, b]) ? creep
   Call: (13) membro(z, [b]) ? creep
   Call: (14) membro(z, []) ? creep
   Fail: (14) membro(z, []) ? creep
   Fail: (13) membro(z, [b]) ? creep
   Fail: (12) membro(z, [a, b]) ? creep
   Fail: (11) membro(z, [2, a, b]) ? creep
   Fail: (10) membro(z, [1, 2, a, b]) ? creep
false.

membro(X,[1,2,a,b]).
[trace] 4 ?- membro(X,[1,2,a,b]). 
   Call: (10) membro(_112, [1, 2, a, b]) ? creep
   Exit: (10) membro(1, [1, 2, a, b]) ? creep
X = 1 ;
   Redo: (10) membro(_112, [1, 2, a, b]) ? creep
   Call: (11) membro(_112, [2, a, b]) ? creep
   Exit: (11) membro(2, [2, a, b]) ? creep
   Exit: (10) membro(2, [1, 2, a, b]) ? creep
X = 2 ;
   Redo: (11) membro(_112, [2, a, b]) ? creep
   Call: (12) membro(_112, [a, b]) ? creep
   Exit: (12) membro(a, [a, b]) ? creep
   Exit: (11) membro(a, [2, a, b]) ? creep
   Exit: (10) membro(a, [1, 2, a, b]) ? creep
X = a ;
   Redo: (12) membro(_112, [a, b]) ? creep
   Call: (13) membro(_112, [b]) ? creep
   Exit: (13) membro(b, [b]) ? creep
   Exit: (12) membro(b, [a, b]) ? creep
   Exit: (11) membro(b, [2, a, b]) ? creep
   Exit: (10) membro(b, [1, 2, a, b]) ? creep
X = b ;
   Redo: (13) membro(_112, [b]) ? creep
   Call: (14) membro(_112, []) ? creep
   Fail: (14) membro(_112, []) ? creep
   Fail: (13) membro(_112, [b]) ? creep
   Fail: (12) membro(_112, [a, b]) ? creep
   Fail: (11) membro(_112, [2, a, b]) ? creep
   Fail: (10) membro(_112, [1, 2, a, b]) ? creep
false.
*/