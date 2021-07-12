-- double :: [Int] -> [Int]
-- double [] = []
-- double (x:xs) = 2*x : double xs

-- double xs = [x*2 | x <- xs]

-- incrementa :: (Num a) => [a] -> [a]
-- incrementa [] = []
-- incrementa (x:xs) = x + 1 : incrementa xs

-- incrementa xs = [x + 1 | x <- xs]

map1 :: (a -> b) -> [a] -> [b]
map1 _ [] = []
map1 f (x:xs) = (f x) : map1 f xs

map2 :: (a -> b) -> [a] -> [b]
map2 f xs = [f x | x <- xs]