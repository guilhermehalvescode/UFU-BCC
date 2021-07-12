-- (h:t)
-- head tail

contElem :: [a] -> Int
contElem [] = 0;
contElem (_:t) = 1 + contElem(t)

maiorElem :: [Int] -> Int
maiorElem [x] = x
maiorElem (x:y:r) 
  | x > y = maiorElem (x:r)
  | otherwise = maiorElem (y:r)


nPrimeiros :: Int -> [t] -> [t]
nPrimeiros 0 _ = []
nPrimeiros _ [] = []
nPrimeiros n (x:r) = (x : nPrimeiros (n - 1) r)

{- Dúvida -}
{- pertence :: t -> [t] -> Bool
pertence _ [] = False
pertence elem (x:xs)
  | (x == elem) = True
  | otherwise = pertence elem xs
 -}

uniaoR :: [t] -> [t] -> [t]
uniaoR [] lis = lis
uniaoR (x:xs) lis 
  | pertence x lis = uniaoR xs lis
  | otherwise = x : uniaoR xs lis

uniao :: [t] -> [t] -> [t]
uniao as bs = as ++ [b | b <- bs, not(pertence b as)]