s(A-C):- sn(A-B), sv(B-C).
sn(A-C):- det(A-B), n(B-C). 
sv(A-C):- v(A-B), sn(B-C). 
sv(A-C):- v(A-C).
det([o|P]-P).           
det([a|P]-P). 
n([homem|P]-P).    
n([mulher|P]-P).      
n([carro|P]-P).      
n([cadeira|P]-P).
v([chuta|P]-P). 
v([pula|P]-P). 
v([corre|P]-P). 
v([peida|P]-P). 