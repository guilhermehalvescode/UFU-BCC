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

{-Função auxiliar que filtra e conta-}
filtrarCont :: (a -> Bool) -> [a] -> ([a], Int)
filtrarCont _ [] = ([], 0)
filtrarCont f (x : xs) =
  if f x
    then (x : lis, c + 1)
    else (lis, c + 1)
  where
    (lis, c) = filtrarCont f xs

{-Original-}
quickSortOri :: (Ord a) => [a] -> ([a], Int)
quickSortOri [] = ([], 0)
quickSortOri (p : xs) = (ordEsq ++ [p] ++ ordDir, cont_esq + cont_dir + n_dir + n_esq)
  where
    (esq, cont_esq) = filtrarCont (< p) xs
    (dir, cont_dir) = filtrarCont (>= p) xs
    (ordEsq, n_esq) = quickSortOri esq
    (ordDir, n_dir) = quickSortOri dir

{-Variação 1-}

quickSortV1 :: (Ord a) => [a] -> ([a], Int)
quickSortV1 [] = ([], 0)
quickSortV1 (p : xs) = (ordEsq ++ [p] ++ ordDir, contComp + n_dir + n_esq)
  where
    (esq, dir, contComp) = divide p xs
    (ordEsq, n_esq) = quickSortV1 esq
    (ordDir, n_dir) = quickSortV1 dir

{-Divide Variação1-}
divide :: (Ord a) => a -> [a] -> ([a], [a], Int)
divide pivo [] = ([], [], 0)
divide pivo (h : hs)
  | h < pivo = (h : menores, maiores, cont + 1)
  | otherwise = (menores, h : maiores, cont + 1)
  where
    (menores, maiores, cont) = divide pivo hs

{-Variação 2-}

analisaPivo :: Ord a => [a] -> ([a], a)
analisaPivo lis =
  let lista = fst (quickSortV1 (take 3 lis))
      len = length lista
      mediano =
        if len < 3
          then head lista
          else lista !! 1
   in (remove mediano lis, mediano)
  where
    remove :: (Ord a) => a -> [a] -> [a]
    remove _ [] = []
    remove a (x : xs)
      | a == x = xs
      | otherwise = x : remove a xs

-- xyz
-- xzy
-- yxz
-- yzx
-- zyx
-- zxy
analisaPivoH :: (Ord a) => [a] -> (a, a, a, [a], Int)
analisaPivoH (x : y : z : resto)
  | x >= y && y >= z = (x, y, z, resto, 2)
  | x >= z && z >= y = (x, z, y, resto, 4)
  | y >= z && x >= z = (y, x, z, resto, 6)
  | y >= z && z >= x = (y, z, x, resto, 8)
  | z >= y && y >= x = (z, y, x, resto, 10)
  | otherwise = (z, x, y, resto, 10)

quickSortV2 :: (Ord a) => [a] -> ([a], Int)
quickSortV2 [] = ([], 0)
quickSortV2 list = (ordEsq ++ [p] ++ ordDir, contComp + n_dir + n_esq)
  where
    (maior, p, menor, xs, trocaPivo) = analisaPivoH list
    (esq, dir, contComp) = divide p xs
    (ordEsq, n_esq) = quickSortV1 (menor : esq)
    (ordDir, n_dir) = quickSortV1 (maior : dir)
