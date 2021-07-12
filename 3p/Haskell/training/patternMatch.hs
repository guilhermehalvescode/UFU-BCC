{- ex 1 -}
( || ) :: Bool -> Bool -> Bool

False || False = False
_ || _ = True 

True || True = True
True || False = True
False || True = True
False || False = True

False || a = a 
True || _ = True 


{- ex 2 -}
( && ) :: Bool -> Bool -> Bool
a && b = 
  if a then (
    if b then True else False
  ) else False

{- ex 3 -}
a && b 
  | a = b
  | otherwise = False  


{- ex 4 -}
type Ponto = (Float, Float, Float)
distancia :: Ponto -> Ponto -> Float
distancia (x, y, z) (i, j, k) = sqrt((x - i) ** 2 + (y - j) ** 2 + (z - k) ** 2)

{- ex 5 -}
opp :: (Int, (Int, Int)) -> Int
opp (z, (x, y)) 
  | z == 1 = x + y  
  | z == 2 = x - y
  | otherwise = 0
 