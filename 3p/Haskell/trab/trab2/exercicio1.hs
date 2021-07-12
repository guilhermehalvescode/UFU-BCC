l1 = [1 .. 2000]

l2 = [2000, 1999 .. 1]

l3 = l1 ++ [0]

l4 = 0 : l2

l5 = l1 ++ [0] ++ l2

l6 = l2 ++ [0] ++ l1

l7 = l2 ++ [0] ++ l2

x1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]

x2 = [20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1]

x3 = [11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

x4 = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11]

x5 = [11, 12, 13, 14, 15, 5, 4, 3, 2, 1, 16, 17, 18, 19, 20, 10, 9, 8, 7, 6]

x6 = [1, 12, 3, 14, 5, 15, 4, 13, 2, 11, 6, 17, 8, 19, 20, 10, 9, 18, 7, 16]

x7 = [20, 8, 2, 11, 13, 3, 7, 18, 14, 4, 16, 10, 15, 1, 9, 17, 19, 12, 5, 6]

{-Original-}
bolhaOri :: Ord a => [a] -> ([a], Int)
bolhaOri [] = ([], 0)
bolhaOri lista = bolhaOrdOri lista (length lista)

bolhaOrdOri :: Ord a => [a] -> Int -> ([a], Int)
bolhaOrdOri lista 0 = (lista, 0)
bolhaOrdOri lista n = (bolhaOrd, j + cont)
  where 
    (lst, j) = trocaOri lista
    (bolhaOrd, cont) = bolhaOrdOri lst (n - 1)

trocaOri :: Ord a => [a] -> ([a], Int)
trocaOri [x] = ([x], 0)
trocaOri (x : y : zs)
  | x > y = (y : l1, c1 + 1)
  | otherwise = (x : l2, c2)
    where
      (l1, c1) = trocaOri (x : zs)
      (l2, c2) = trocaOri (y : zs)

{-Variação 1-}
bolhaV1 :: Ord a => [a] -> ([a], Int)
bolhaV1 [] = ([], 0)
bolhaV1 lista = bolhaOrdV1 lista (length lista)

bolhaOrdV1 :: Ord a => [a] -> Int -> ([a], Int)
bolhaOrdV1 lista 0 = (lista, 0)
bolhaOrdV1 lista n = (bolhaOrd, j + cont)
  where 
    (lst, j) = trocaV1 lista
    (bolhaOrd, cont) = if j == 0 then (lst, j) else bolhaOrdV1 lst (n - 1)

trocaV1 :: Ord a => [a] -> ([a], Int)
trocaV1 [x] = ([x], 0)
trocaV1 (x : y : zs)
  | x > y = (y : l1, c1 + 1)
  | otherwise = (x : l2, c2)
    where
      (l1, c1) = trocaV1 (x : zs)
      (l2, c2) = trocaV1 (y : zs)

{-Variação 2-}
bolhaV2 :: Ord a => [a] -> ([a], Int)
bolhaV2 [] = ([], 0)
bolhaV2 lista = bolhaOrdV2 lista (length lista)

bolhaOrdV2 :: Ord a => [a] -> Int -> ([a], Int)
bolhaOrdV2 lista 0 = (lista, 0)
bolhaOrdV2 lista n = (bolhaOrd, j + cont)
  where 
    (lst, j) = trocaV2 lista n
    {- (lst, j) = trocaV2 (take n lista) -}
    (bolhaOrd, cont) = if j == 0 then (lst, j) else bolhaOrdV2 lst (n - 1)

trocaV2 :: Ord a => [a] -> Int -> ([a], Int)
trocaV2 [x] _ = ([x], 0)
trocaV2 lis 0 = (lis, 0)
trocaV2 (x : y : zs) n
  | x > y = (y : l1, c1 + 1)
  | otherwise = (x : l2, c2)
    where
      (l1, c1) = trocaV2 (x : zs) n
      (l2, c2) = trocaV2 (y : zs) n