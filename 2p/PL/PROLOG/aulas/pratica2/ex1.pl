%a
sobre(a, mesa).
sobre(b, a).

%b
acima_de(X, Y) :- sobre(X, Y).

%c
/* acima_de(b, mesa). 
    false.
*/