{-Exercício 7-}
--a
data Jogada = Pedra | Papel | Tesoura deriving (Eq, Show)

--b
vence :: Jogada -> Jogada -> Bool
vence j1 j2 =
  j1 /= j2 && comp j1 j2
  where
    comp Pedra Papel = False
    comp Pedra Tesoura = True
    comp Papel Pedra = True
    comp Papel Tesoura = False
    comp Tesoura Pedra = False
    comp Tesoura Papel = True


--c
vencedoras :: [(Jogada, Jogada)] -> [Jogada]
vencedoras jogadas = [ quemVence j1 j2 | (j1, j2) <- jogadas]
  where 
    quemVence :: Jogada -> Jogada -> Jogada
    quemVence j1 j2 
      | j1 == j2 = j1
      | vence j1 j2 = j1
      | otherwise = j2