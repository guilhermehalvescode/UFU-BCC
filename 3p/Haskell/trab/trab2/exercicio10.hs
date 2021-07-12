arvEx :: BinTreeInt
arvEx =
  No
    8
    ( No
        3
        ( No
            1
            Null
            Null
        )
        ( No
            6
            (No 4 Null Null)
            (No 7 Null Null)
        )
    )
    ( No
        10
        Null
        ( No
            14
            (No 13 Null Null)
            Null
        )
    )

{-Exercício 10-}
data BinTreeInt = Null | No Int BinTreeInt BinTreeInt deriving (Show, Eq)

folhas :: BinTreeInt -> [Int]
folhas Null = []
folhas (No x esq dir) =
  if esq == Null && dir == Null then [x]
  else folhas esq ++ folhas dir

somaNosInternos :: BinTreeInt -> Int
somaNosInternos Null = 0
somaNosInternos (No x Null Null) = x
somaNosInternos (No x esq dir) = somaNosInternos esq + somaNosInternos dir + x

pertence :: BinTreeInt -> Int -> Bool
pertence Null _ = False
pertence (No x esq dir) valor =
  pertence esq valor || x == valor || pertence dir valor