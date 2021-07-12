pais(alemanha,europa, 83, [franca,belgica,holanda,suica]).
pais(australia,oceania, 25, []).
pais(belgica,europa, 11, [franca,holanda,alemanha]).
pais(espanha,europa, 47, [portugal,franca]).
pais(franca,europa, 67, [espanha,suica,belgica,alemanha,italia]).
pais(holanda,europa, 17, [belgica,alemanha]).
pais(indonesia,oceania, 268, []).
pais(italia,europa, 60, [franca,suica]).
pais(madagascar,africa, 26, []).
pais(portugal,europa, 10, [espanha]).
pais(suica,europa, 8, [franca,alemanha,italia]).

isolados_grandes(Lista) :-
    findall(Cont, (isolados_grandes(Pais1, Cont), 
        isolados_grandes(Pais2, Cont),
        Pais1 \= Pais2), List),
    sort(List, Lista).
    
isolados_grandes(Pais, Cont) :-
    pais(Pais, Cont, Pop, Viz),
    Pop > 15,
    length(Viz, T),
    T < 3.
    
    
