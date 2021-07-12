


%travessias
travessia(1,2).
travessia(1,5).
travessia(1,10).
travessia(2,5).
travessia(2,10).
travessia(5,10).

%voltas
volta(1).
volta(2).
volta(5).
volta(10).

find(D) :- 
    D >= 17.

find(D) :- 
    travessia(X , Y), 
    volta(X),
    D is D + Y + X,
    find(D).  


