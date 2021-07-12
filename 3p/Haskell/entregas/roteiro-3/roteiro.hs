
{- exercício 1 -}
 
{- ou :: Bool -> Bool -> Bool -}

{- (a) -}
{- 
ou False False = False
ou _ _ = True 

ou True True = True
ou True False = True
ou False True = True
ou False False = False

ou False a = a 
ou True _ = True  
-}

{- (b) -}
{- 
ou x y = 
  if (not x) then (
    if (not y) then False else True 
  ) else True

ou x y 
  | x = True
  | y = True 
  | otherwise = False  
-}

{- exercício 2 -}
distancia :: (Float, Float) -> (Float, Float)-> Float
distancia (x1, y1) (x2, y2) = sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

{- exercício 3 -}

fact :: Int -> Int
factG :: Int -> Int
fact 0 = 1
fact x = x * fact(x - 1)


factG x 
  | x == 0 = 1
  | otherwise = x * fact(x - 1)


{- exercício 4 -}
fibo :: Int -> Int
fibo 0 = 0
fibo 1 = 1
fibo x = fibo(x - 1) + fibo (x - 2)

{- exercício 5 -}
n_tri :: Int -> Int
n_tri 0 = 0
n_tri x = x + n_tri(x - 1)

{- exercício 6 -}
potencia2 :: Int -> Int
potencia2 0 = 1
potencia2 x = 2 * potencia2(x - 1)

{- exercício 7 -}
{- (a) -}
prodIntervalo :: (Int, Int) -> Int
prodIntervalo (m, n)
  | m > n = -1
  | m == n = n
  | otherwise = n * prodIntervalo(m, n - 1)

{- (b) -}
fatProd :: Int -> Int
fatProd n
  | n == 0 = 1
  | otherwise = prodIntervalo(1, n)

{- exercício 8 -}
resto_div :: (Int, Int) -> Int
resto_div (m, n) 
  | m < n = m
  | otherwise = resto_div(m - n, n)

div_inteira :: (Int, Int) -> Int
div_inteira (m, n)
  | m - n < n = 1
  | otherwise = 1 + div_inteira(m - n, n)

{- exercício 9 -}
mdc :: (Int, Int) -> Int
mdc (m, 0) = m
mdc (m, n) = if n > 0 then mdc(n , (mod m n)) else -1

mdcG :: (Int, Int) -> Int
mdcG (m, n)
  | n == 0 = m
  | otherwise = mdcG (n, (mod m n))

{- exercício 10 -}
bino :: (Int, Int) -> Int
bino (n, 0) = 1
bino (n, k) =
  if k > n then -1
  else (
    if n == k then 1
    else bino (n - 1, k) + bino (n - 1, k - 1) 
  ) 

binoG :: (Int, Int) -> Int
binoG (n, 0) = 1
binoG (n, k) 
  | k > n = -1
  | k == 0 = 1
  | n == k = 1
  | otherwise = bino (n - 1, k) + bino (n - 1, k - 1)

{- exercício 11 -}
{- (a) -}
type Par = (Int, Int)

{- (b) -}
passo :: Par -> Par
passo (x, y) = (y, x + y)

{- (c) -}
n_par :: Int -> Par
n_par n = n_calcula (n, (1,1))

n_calcula :: (Int, Par) -> Par
n_calcula (n, par)
  | n == 1 = par
  | otherwise = n_calcula (n - 1, passo(par))

{- (d) -}
fibo2 :: Int -> Int
fibo2 n = fst(n_par(n))