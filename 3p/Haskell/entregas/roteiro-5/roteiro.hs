{- exercício 1 -}
conta_ch :: [Char] -> Int
conta_ch [] = 0;
conta_ch (_:t) = 1 + conta_ch(t)

conta :: [a] -> Int
conta [] = 0;
conta (_:t) = 1 + conta(t)

maior :: [Int] -> Int
maior [x] = x
maior (x:y:r) 
  | x > y = maior (x:r)
  | otherwise = maior (y:r)

primeiros :: Int -> [t] -> [t]
primeiros 0 _ = []
primeiros _ [] = []
primeiros n (x:r) = (x : primeiros (n - 1) r)

pertence :: (Eq t) => t -> [t] -> Bool
pertence _ [] = False
pertence elem (x:xs)
  | (x == elem) = True
  | otherwise = pertence elem xs
 
uniaoR :: (Eq t) => [t] -> [t] -> [t]
uniaoR [] lis = lis
uniaoR (x:xs) lis 
  | pertence x lis = uniaoR xs lis
  | otherwise = x : uniaoR xs lis

{- exercício 2 -}
npares :: [Int] -> Int
npares [] = 0
npares (h:t) 
  | mod h 2 == 0 = 1 + npares t
  | otherwise = npares t

{- exercício 3 -}
produtorio :: [Int] -> Int
produtorio [] = 0
produtorio [x] = 1 * x
produtorio (h:t) = h * produtorio t

{- exercício 4 -}
comprime :: [[t]] -> [t]
comprime [[]] = []
comprime ([]:tail) = comprime tail
comprime ((h:ta):tail) = h : comprime (ta:tail)
{- exercício 5 -}
tamanho :: [a] -> Int
tamanho [] = 0;
tamanho (_:t) = 1 + tamanho(t)

{- exercício 6 -}
uniaoRec2 :: [Int] -> [Int] -> [Int]
uniaoRec2 l1 [] = l1
uniaoRec2 l1 (x:xs)
  | pertence x l1 = uniaoRec2 l1 xs
  | otherwise = uniaoRec2 (l1 ++ [x]) xs
