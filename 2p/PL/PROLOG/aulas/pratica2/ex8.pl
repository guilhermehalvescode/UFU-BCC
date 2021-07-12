trad(eins,um).
trad(zwei,dois).
trad(drei,tres).
trad(vier,quatro).
trad(fuenf,cinco).
trad(sechs,seis).
trad(sieben,sete).
trad(acht,oito).
trad(neun,nove).

tradLista([], []).
    
tradLista([H|T], [Z|C]) :- 
    trad(H, Z),
    tradLista(T, C).

