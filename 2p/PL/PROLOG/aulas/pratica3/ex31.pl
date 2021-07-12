s(C) :- sn(A), sv(B), append(A, B, C).
sn(C) :- det(A), n(B), append(A,B, C).
sv(C) :- v(A), sn(B), append(A, B, C).
sv(C) :- v(C).
det([o]).
det([a]).
n([homem]).
n([mulher]).
n([bola]).
v([chuta]).




