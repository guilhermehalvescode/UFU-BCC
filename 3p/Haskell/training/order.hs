--bubble
bolha [] = []
bolha lista = bolhaOrd lista (length lista)

bolhaOrd lista 0 = lista
bolhaOrd lista n = bolhaOrd (troca lista) (n - 1)

troca [x] = [x]
troca (x:y:zs)
  | x > y = y : troca(x:zs)
  | otherwise = x : troca (y:zs)

--selection
selecao :: (Ord a) => [a] -> [a]
selecao [] = []
selecao xs = x : selecao(remove x xs)
              where x = minimo xs

remove :: (Ord a) => a -> [a] -> [a]
remove _ [] = []
remove a (x:xs)
  | a == x = xs
  | otherwise = x : (remove a xs)

minimo :: (Ord a) => [a] -> a
minimo [] = undefined
minimo [x] = x 
minimo (x:y:xs)
  | x < y = minimo (x:xs)
  | otherwise = minimo (y:xs)

--insertion
insercao :: (Ord a) => [a] -> [a]
insercao [] = []
insercao (x : xs) = insereOrd x (insercao xs)

insereOrd :: (Ord a) => a -> [a] -> [a]
insereOrd x [] = [x]
insereOrd x (y:ys)
  | x <= y = (x:y:ys)
  | otherwise = y : (insereOrd x ys)

--quick
quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
-- quicksort (p : xs) = 
--   quicksort [x | x <- xs, x < p]
--   ++ [p] ++
--   quicksort [x | x <- xs, x >= p]

quicksort (p : xs) = 
  quicksort (fst maiorMenor)
  ++ [p] ++
  quicksort (snd maiorMenor)
  where 
    maiorMenor = seleciona p xs ([], [])
    seleciona :: (Ord a) => a -> [a] -> ([a], [a]) -> ([a], [a])
    seleciona pivo [] (menores, maiores) = (menores, maiores)
    seleciona pivo (h:hs) (menores, maiores) 
      | h < pivo = seleciona pivo hs (h:menores, maiores)
      | otherwise = seleciona pivo hs (menores, h:maiores)
      

