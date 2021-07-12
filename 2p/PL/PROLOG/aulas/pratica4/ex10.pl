:- op(300, xfx, [sao, eh_um]).
:- op(300, fx, gosta_de).
:- op(200, xfy, e).
:- op(100, fy, famoso).
/* 
?- X eh_um bruxo. 
res: Bem formado.
    -Operador principal: eh_um()
    -eh_um(_90, bruxo).
?- harry e ron e hermione sao amigos.
res: Bem formado.
    -Operador principal: sao()
    -sao(e(harry,e(ron,hermione)),amigos)
?- harry eh_um mago e gosta_de quadribol.
res: Mal formado.
?- dumbledore eh_um famoso famoso mago. 
res: Bem formado.
    -Operador principal: eh_um()
    -eh_um(dumbledore,famoso(famoso(mago)))
*/