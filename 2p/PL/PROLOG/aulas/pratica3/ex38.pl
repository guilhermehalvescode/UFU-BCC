/* s-->foo,bar,wiggle.
foo-->[chu].
foo-->foo,foo.
bar-->mar,zar.
mar-->me,my.
me-->[eu].
my-->[sou].
zar-->blar,car.
blar-->[um].
car-->[trem].
wiggle-->[tchu].
wiggle-->wiggle,wiggle. */

s(A-D) :- foo(A-B), bar(B-C), wiggle(C-D).
foo([chu|P] - P).
foo(A-C) :- foo(A-B),foo(B-C).
bar(A-C) :- mar(A-B), zar(B-C).
mar(A-C) :- me(A-B), my(B-C).
me([eu|P] - P).
my([sou|P] - P).
zar(A-C) :- blar(A-B), car(B-C).
blar([um|P] - P).
car([trem|P] - P).
wiggle([tchu|P] - P).
wiggle(A-C) :- wiggle(A-B), wiggle(B-C).

/* 
X = [chu, eu, sou, um, trem, tchu] ;
X = [chu, eu, sou, um, trem, tchu, tchu] ;
X = [chu, eu, sou, um, trem, tchu, tchu, tchu] ;
 */