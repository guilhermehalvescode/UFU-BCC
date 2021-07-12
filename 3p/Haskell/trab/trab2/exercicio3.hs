l1 = [1 .. 2000]

l2 = [2000, 1999 .. 1]

l3 = l1 ++ [0]

l4 = [0] ++ l2

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

isort :: Ord a => [a] -> [a]
isort lista = insertOrd lista []
  where
    insertOrd [] x = x
    insertOrd (x : y : xs) res =
      if x > y
        then insertOrd (y : xs) (x : res)
        else insertOrd (x : xs) (y : res)

{-Original-}
insertionOri :: (Ord a) => [a] -> ([a], Int)
insertionOri [] = ([], 0)
insertionOri (x : xs) = (res, cont + contInsert)
  where
    (list, cont) = insertionOri xs
    (res, contInsert) = insertOrdOri x list

insertOrdOri :: (Ord a) => a -> [a] -> ([a], Int)
insertOrdOri x [] = ([x], 0)
insertOrdOri x (y : ys)
  | x <= y = (x : y : ys, 1)
  | otherwise = (y : res, cont + 1)
  where
    (res, cont) = insertOrdOri x ys

{-Variação 1-}
--TODO
insertionV1 :: (Ord a) => [a] -> ([a], Int)
insertionV1 [] = ([], 0)
insertionV1 lis = foldl insertOrdV1 ([], 0) lis
  where
    insertOrdV1 :: (Ord a) => ([a], Int) -> a -> ([a], Int)
    insertOrdV1 ([], c) x  = ([x], c)
    insertOrdV1 (y : ys, c) x 
      | x <= y = (x : y : ys, c + 1)
      | otherwise = (y : res, cont + 1)
      where
        (res, cont) = insertOrdV1 (ys, c) x