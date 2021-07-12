{- Árvores haskell -}

-- O conceito de árvore é recursivo, logo sua implemetação em haskell é simplificada
data BinTreeInt = Null | No Int BinTreeInt BinTreeInt deriving Show


arvEx = (No 2 (No 3 Null Null) (No 4 Null Null))


emOrdemTree :: BinTreeInt -> [Int]
emOrdemTree Null = []
emOrdemTree (No x esq dir) = (emOrdemTree esq) ++ [x] ++ (emOrdemTree dir)

preOrdemTree :: BinTreeInt -> [Int]
preOrdemTree Null = []
preOrdemTree (No x esq dir) = [x] ++ (preOrdemTree esq) ++ (preOrdemTree dir)

posOrdemTree :: BinTreeInt -> [Int]
posOrdemTree Null = []
posOrdemTree (No x esq dir) = (posOrdemTree esq) ++ (posOrdemTree dir) ++ [x]

--Árvore Binária de Busca
{- O percorrimento em ordem já retorna uma lista ordenada, pelo fato da arvore seguir a regra de ordenação -}

--Arvore Genérica
data BinTreeGen a = Null | No a (BinTreeGen a) (BinTreeGen a) deriving Show

insereGen :: Ord a => a -> BinTreeGen a -> BinTreeGen A
insereGen x Null = (No x Null Null)
insereGen x (No y esq dir)
  | x == y = No y esq dir
  | x < y = No y (insereGen x esq) dir
  | otherwise = No y esq (insereGen x dir)