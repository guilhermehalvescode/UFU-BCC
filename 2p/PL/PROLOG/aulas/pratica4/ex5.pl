s(s(SN, SV)) --> sn(sujeito, singular, SN), sv(singular, SV).
s(s(SN, SV)) --> sn(sujeito, plural, SN), sv(plural, SV).
sn(_, X, sn(Det, N)) --> det(X, Det), n(X, N).                  
sn(Y, X, sn(Pro)) --> pro(Y, X, Pro).
sv(X, sv(V ,SN)) --> v(X, V), sn(objeto, X, SN).
sv(X, s(V)) --> v(X, s(V)).

det(singular, det(Palavra))-->[Palavra], {lex(Palavra, det, singular)}.
n(singular, n(Palavra))-->[Palavra], {lex(Palavra, n, singular)}.
v(singular, v(Palavra))-->[Palavra], {lex(Palavra, v, singular)}.

det(plural, det(Palavra))-->[Palavra], {lex(Palavra, det, plural)}.
n(plural, n(Palavra))-->[Palavra], {lex(Palavra, n, plural)}.
v(plural, v(Palavra))-->[Palavra], {lex(Palavra, v, plural)}.

pro(sujeito, singular, pro(Palavra)) --> [Palavra], {lex(Palavra, pro, sujeito, singular)}.
pro(objeto, singular, pro(Palavra)) --> [Palavra], {lex(Palavra, pro, objeto, singular)}.
pro(sujeito, plural, pro(Palavra)) --> [Palavra], {lex(Palavra, pro, sujeito, plural)}.
pro(objeto, plural, pro(Palavra)) --> [Palavra], {lex(Palavra, pro, objeto, plural)}.

%arquivo separado
lex(o, det, singular).
lex(a, det, singular).
lex(mulher, n, singular).
lex(homem, n, singular).
lex(bate, v, singular).
lex(os, det, plural).
lex(as, det, plural).
lex(mulheres, n, plural).
lex(homens, n, plural).
lex(batem, v, plural).

lex(ele, pro, sujeito, singular).
lex(ela, pro, sujeito, singular).
lex(nele, pro, objeto, singular).
lex(nela, pro, objeto, singular).

lex(eles, pro, sujeito, plural).
lex(elas, pro, sujeito, plural).
lex(neles, pro, objeto, plural).
lex(nelas, pro, objeto, plural).