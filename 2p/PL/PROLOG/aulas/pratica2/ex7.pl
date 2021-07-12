/*(a)[a,b,c,d] = [a,[b,c,d]]. res = false.
(b)[a,b,c,d] = [a|[b,c,d]]. res = true.
(c)[a,b,c,d] = [a,b,[c,d]]. res = false.
(d)[a,b,c,d] = [a,b|[c,d]]. res = true.
(e)[a,b,c,d] = [a,b,c,[d]]. res = false.
(f)[a,b,c,d] = [a,b,c|[d]]. res = true.
(g)[a,b,c,d] = [a,b,c,d,[]]. res = false.
(h)[a,b,c,d] = [a,b,c,d|[]]. res = true.
(i)[] = _. res = true.
(j)[] = [_]. res = false.
(k)[] = [_|[]]. res = false.
*/