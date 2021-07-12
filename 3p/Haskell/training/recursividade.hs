binoG :: (Int, Int) -> Int

-- binoG (n, k) 
--   | k == 0 = 1
--   | n == k = 1
--   | otherwise = binoG(n - 1, k) + binoG(n - 1, k - 1)

binoG (n, 0) = 1
binoG (n, k) = 
  if n == k then 1
  else binoG(n - 1, k) + binoG(n - 1, k - 1)
