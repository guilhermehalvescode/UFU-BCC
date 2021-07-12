combinacao(0,_,[]).
combinacao(N,[X|Xs],[X|Ys]):- 
    N>0,N1 is N - 1,
combinacao(N1,Xs,Ys).
combinacao(N,[_|Xs], Ys) :- 
    N>0,
    combinacao(N,Xs,Ys).

/* 
(a) combinacao(5, [a1,a2,a3,a4,a5,a6,a7,a8,a9,a10], C).
(b) combinacao(3, [m1,m2,m3,m4,m5,m6,m7,m8,m9], M), combinacao(4, [c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11], C).
*/