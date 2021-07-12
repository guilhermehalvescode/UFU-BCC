/* 
?- 12 is 2*6. res: true.
?- 14 =\= 2*6. res: true.
?- 14 = 2*7. res: false.
?- 14 == 2*7. res: false.
?- 14 \== 2*7. res: true.
?- 14 =:= 2*7. res: true.
?- [1,2,3|[d,e]] == [1,2,3,d,e]. res: true.
?- 2+3 == 3+2. res: false.
?- 2+3 =:= 3+2. res: true.
?- 7-2 =\= 9-2. res: true.
?- p == 'p'. res: true.
?- p =\= 'p'. res: falha. Arithmetic: `p/0' is not a function
?- vicente == VAR. res: false.
?- vicente=VAR, VAR==vicent. res: false.
*/