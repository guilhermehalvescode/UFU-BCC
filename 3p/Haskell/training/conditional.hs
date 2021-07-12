{- If then else -}
menor :: Int -> Int -> Int
menor x y = 
  if x <= y 
    then x
    else y
{- Nested if -}
maxTres :: Int -> Int -> Int -> Int 
maxTres x y z = 
  if x >= y && x >= z
    then x
    else (
      if y >= z
      then y
      else z
    )

{- Using Guard -}
maxTresGuarda :: Int -> Int -> Int -> Int 
maxTresGuarda x y z 
  | x >= y && x >= z = x
  | y >= z = y
  | otherwise = z
