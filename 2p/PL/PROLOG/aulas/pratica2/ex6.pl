deCarro(auckland,hamilton).
deCarro(hamilton,raglan).
deCarro(valmont,saarbruecken).
deCarro(valmont,metz).
deTrem(metz,frankfurt).
deTrem(saarbruecken,frankfurt).
deTrem(metz,paris).
deTrem(saarbruecken,paris).
deAviao(frankfurt,bangkok).
deAviao(frankfurt,singapore).
deAviao(paris,losAngeles).
deAviao(bangkok,auckland).
deAviao(losAngeles,auckland).

viagem(X, Y, vai(X, decarro, Y)) :-
    deCarro(X, Y).
viagem(X, Y, vai(X, detrem, Y)) :-
    deTrem(X, Y).
viagem(X, Y, vai(X, deaviao, Y)) :-
    deAviao(X, Y).

viagem(X, Y, vai(X, decarro, Z, K)) :-
    deCarro(X ,Z),
    viagem(Z, Y, K).
viagem(X, Y, vai(X, detrem, Z, K)) :-
    deTrem(X, Z),
    viagem(Z, Y, K).
viagem(X, Y, vai(X, deaviao, Z, K)) :-    
    deAviao(X , Z),
    viagem(Z, Y, K).
