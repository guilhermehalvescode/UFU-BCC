{-Exercicio 8-}

--a
data Nebuloso = Verdadeiro | Falso | Talvez Float deriving Show

--b
fuzzifica :: Float -> Nebuloso
fuzzifica grau 
  | grau <= 0 = Falso
  | grau >= 1 = Verdadeiro
  | otherwise = Talvez grau

--c 
verifica_alto :: Float -> Nebuloso
verifica_alto alt = fuzzifica ((alt - 1.70)/0.20)

--d
verifica_barato :: Float -> Nebuloso
verifica_barato custo = fuzzifica ((50000 - custo)/20000)

