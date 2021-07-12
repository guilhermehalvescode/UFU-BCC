-- pegaLetras :: String -> String
-- pegaLetras [] = []
-- pegaLetras (c:cs) 
--   | isAlpha c = c : pegaLetras cs
--   | otherwise = pegaLetras cs

-- pegaLetras xs = [x | x <- xs, isAlpha x]

-- pegaDigitos :: String -> String
-- pegaDigitos [] = []
-- pegaDigitos (c:cs) 
--   | isDigit c = c : pegaDigitos cs
--   | otherwise = pegaDigitos cs

-- pegaDigitos xs = [x | x <- xs, isDigit x]

filter1 :: (a -> Bool) -> [a] -> [a]
filter1 _ [] = []
filter1 f (x : xs)
  | f x = x : filter1 f xs
  | otherwise = filter1 f xs

pegaLetras :: String -> String
pegaLetras xs = filter isAlpha xs

pegaDigitos :: String -> String
pegaDigitos xs = filter isDigit xs