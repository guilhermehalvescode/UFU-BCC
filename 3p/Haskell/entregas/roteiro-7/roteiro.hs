{- exercício 1 -}
paridade :: [Int] -> [Bool]
paridade l = map even l

{- exercício 2 -}
prefixos :: [String] -> [String]
prefixos l = map (take 3) l

{- exercício 3 -}
saudacao :: [String] -> [String]
saudacao l = map ("Oi " ++) l

{- exercício 4 -}
filtrar :: (a -> Bool) -> [a] -> [a]
filtrar _ [] = []
filtrar f (x : xs)
  | f x = x : filtrar f xs
  | otherwise = filtrar f xs

filtrarComp :: (a -> Bool) -> [a] -> [a]
filtrarComp f l = [x | x <- l, f x] 

{- exercício 5 -}
pares :: [Int] -> [Int]
pares lst = filter even lst

{- exercício 6 -}
solucoes :: [Int] -> [Int]
solucoes l = filter (\x -> ((5 * x) + 6) < (x * x)) l

{- exercício 7 -}
  
maior :: (Ord a) => [a] -> a
maior l = foldr1 max l

{- exercício 8 -}
menor_min10 :: (Ord a) => (Num a) => [a] -> a
menor_min10 lst = foldr min (10) lst

{- exercício 9 -}
junta_silabas_plural :: [String] -> String
junta_silabas_plural sil = foldr (++) "s" sil

{- exercício 10 -}
menores10 :: [Int] -> ([Int], Int)
menores10 l = _contador10 l ([], 0)
  where
    _contador10 :: [Int] -> ([Int], Int) -> ([Int], Int)
    _contador10 [] (lis, c) = (lis, c)
    _contador10 (h:hs) (l, c)
      | h < 10 = _contador10 hs (l ++ [h], c + 1)
      | otherwise = _contador10 hs (l, c)

{- exercício 11 -}
busca :: (Eq a) => a -> [a] -> (Bool, Int)
busca v l = _busca v l (False, 0)
  where
    _busca :: (Eq a) => a -> [a] -> (Bool, Int) -> (Bool, Int)
    _busca _ [] (l, c) = (l, c)
    _busca v (h:hs) (l, c)
      | v == h = (True, c + 1)
      | otherwise = _busca v hs (l, c + 1)