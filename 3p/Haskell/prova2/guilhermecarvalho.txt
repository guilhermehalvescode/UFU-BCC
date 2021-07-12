-- Nome: Guilherme Alves Carvalho
-- Matrícula: 11921BCC016
-- 1 Questão
quicksort3 :: (Ord a) => [a] -> ([a], Int)
quicksort3 [] = ([], 0)
quicksort3 [x] = ([x], 0)
quicksort3 (s : xs) = (maiores ++ [s] ++ menores, contEsq + contDir + 1)
  where
    (lst1, lst2) = divide s xs
    (maiores, contEsq) = quicksort3 lst1
    (menores, contDir) = quicksort3 lst2
divide :: (Ord a) => a -> [a] -> ([a], [a])
divide p [] = ([], [])
divide p (x : xs) = if (x > p) then (x : l1, l2) else (l1, x : l2)
  where
    (l1, l2) = divide p xs

-- 2 Questão
-- a)
totaliza :: [Int] -> Int
totaliza lst = foldl (\x y -> x * y) 1 (filter (\x -> mod x 2 == 0) lst)
-- b)
addTriplas :: [(Int, Int, Int)] -> [Int]
addTriplas lst = filter (\x -> mod x 2 == 0) (map (\(x, y, z) -> x + y + z) lst)

-- 3 Questão
data ArvoreBinInt = Nulo | No Int ArvoreBinInt ArvoreBinInt deriving (Show, Eq)
arvEx :: ArvoreBinInt
arvEx = No 7 (No 3 (No 6 Nulo Nulo) (No 1 (No 4 Nulo Nulo) Nulo)) (No 10 Nulo (No 14 Nulo Nulo))
buscaMult3 :: ArvoreBinInt -> String -> Int
buscaMult3 arv tipo 
  | tipo == "pre" = preOrd arv
  | tipo == "sim" = emOrd arv
  | otherwise = -1
preOrd :: ArvoreBinInt -> Int
preOrd Nulo = -1
preOrd (No x Nulo Nulo) = if mod x 3 == 0 then x else -1
preOrd (No x esq dir) 
  | mod x 3 == 0 = x
  | mod resEsq 3 == 0 = resEsq
  | mod resDir 3 == 0 = resDir
  | otherwise = -1
    where 
      resEsq = preOrd esq
      resDir = preOrd dir
emOrd :: ArvoreBinInt -> Int
emOrd Nulo = -1
emOrd (No x Nulo Nulo) = if mod x 3 == 0 then x else -1
emOrd (No x esq dir) 
  | mod resEsq 3 == 0 = resEsq
  | mod x 3 == 0 = x
  | mod resDir 3 == 0 = resDir
  | otherwise = -1
    where 
      resEsq = emOrd esq
      resDir = emOrd dir 