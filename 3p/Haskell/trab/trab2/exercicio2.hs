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
selectionSortOri :: (Ord a) => [a] -> ([a], Int)
selectionSortOri [] = ([], 0)
selectionSortOri xs = (x : resto, contTrocas + trocasResto)
  where
    (x, contTrocas) = minimoOri xs
    (resto, trocasResto) = selectionSortOri (delElemOri x xs)

delElemOri :: (Ord a) => a -> [a] -> [a]
delElemOri _ [] = []
delElemOri a (x : xs)
  | a == x = xs
  | otherwise = x : delElemOri a xs

minimoOri :: (Ord a) => [a] -> (a, Int)
minimoOri [x] = (x, 0)
minimoOri (x : y : xs)
  | x < y = (menor1, cont1)
  | otherwise = (menor2, cont2 + 1)
  where
    (menor1, cont1) = minimoOri (x : xs)
    (menor2, cont2) = minimoOri (y : xs)

{-Variação 1-}
selectionSortV1 :: (Ord a) => [a] -> ([a], Int)
selectionSortV1 [] = ([], 0)
selectionSortV1 xs = (x : resto, trocas + trocasResto)
  where
    (semMenor, x, trocas) = removeMenorV1 xs
    (resto, trocasResto) = selectionSortV1 semMenor

removeMenorV1 :: (Ord a, Num b) => [a] -> ([a], a, b)
removeMenorV1 l = _removeMenorV1 l ([], 0)
  where
    _removeMenorV1 [x] (lis, c) = (reverse lis, x, c)
    _removeMenorV1 (x : y : zs) (l, c)
      | x < y = _removeMenorV1 (x : zs) (y : l, c)
      | otherwise = _removeMenorV1 (y : zs) (x : l, c + 1)

{-Variação 2-}
selectionSortV2 :: (Ord a) => [a] -> ([a], Int)
selectionSortV2 [] = ([], 0)
selectionSortV2 (h : xs) = (x : resto, contTrocas + trocasResto)
  where
    (x, contTrocas) = foldl minimoV1 (h, 0) xs
    (resto, trocasResto) = selectionSortV2 (delElemV1 x (h : xs))

delElemV1 :: (Ord a) => a -> [a] -> [a]
delElemV1 _ [] = []
delElemV1 a (x : xs)
  | a == x = xs
  | otherwise = x : delElemV1 a xs

minimoV1 :: (Ord a) => (a, Int) -> a -> (a, Int)
minimoV1 (x, c) y
  | x < y = (x, c)
  | otherwise = (y, c + 1)