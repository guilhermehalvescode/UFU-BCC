
-- Exercício 1 -> ex1.png

-- Exercício 2
-- (a)
enumA :: [Int]
enumA = [5, 4..1]

-- (b)
enumB :: [Char]
enumB = ['a', 'c'..'e']

-- (c)
enumC :: [Int]
enumC = [1, 4..16]

-- (d)
enumD :: [(Int, Int)]
enumD = zip [1,-2..(-11)] [1, 5..17]

-- Exercício 3
-- (a)
enum :: Int -> Int -> [Int]
enum a b = [a..b]

-- (b)
enum2 :: Int -> Int -> [Int]
enum2 a b
  | mod a 2 == 0 && mod b 2 == 0 = [a + 2, a + 4 .. b - 2] 
  | mod a 2 == 0 && mod b 2 /= 0 = [a + 2, a + 4 .. b - 1] 
  | mod a 2 /= 0 && mod b 2 == 0 = [a + 1, a + 3 .. b - 2] 
  | otherwise = [a + 1, a + 3 .. b - 1] 

-- Exercício 4 -> ex4.png

-- Exercício 5
quadrados :: Int -> Int -> [Int]
quadrados a b = [x^2 | x <- [a .. b]]

-- Exercício 6
seleciona_impares :: [Int] -> [Int]
seleciona_impares xs = [x | x <- xs, mod x 2 == 1]

-- Exercício 7
tabuada :: Int -> [Int]
tabuada tab = [x | x <- [tab, tab+tab .. tab * 10]]

-- Exercício 8
bissexto :: Int -> Bool
bissexto ano
  | mod ano 400 == 0 = True
  | mod ano 4 == 0 && mod ano 100 /= 0 = True
  | otherwise = False

bissextos :: [Int] -> [Int]
bissextos xs = [x | x <- xs, bissexto x]

-- Exercício 9
sublistas :: [[a]] -> [a]
sublistas xs = [y | ys <- xs, y <- ys]

-- Exercício 10
type Data = (Int, Int, Int)
type Emprestimo = (String, String, Data, Data, String)
type Emprestimos = [Emprestimo]
bdEmprestimo :: Emprestimos
bdEmprestimo = 
  [("H123C9","BSI945",(12,9,2009),(20,09,2009),"aberto"),   
  ("L433C5","BCC021",(01,9,2009),(10,09,2009),"encerrado"),   
  ("M654C3","BCC008",(04,9,2009),(15,09,2009),"aberto")]

bissexto2 :: Data -> Bool
bissexto2 (dia, mes, ano)
  | mod ano 400 == 0 = True
  | mod ano 4 == 0 && mod ano 100 /= 0 = True
  | otherwise = False

valida :: Data -> Bool
valida (dia, mes, ano) 
  | (dia < 1 || dia > 31) || (mes < 1 || mes > 12) = False {- Tira mes e dia com valores inválidos -}
  | dia > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11) = False {- Tira as datas com dia 31 em meses que são de 30 dias -}
  | mes == 2 && dia > 29 = False {- Tira as datas com dia 30 de fevereiro-}
  | mes == 2 && dia > 28 && not (bissexto2 (dia, mes, ano)) = False {- Tira as datas com dia 29 que não são bissextas -}
  | otherwise = True

precede :: Data -> Data -> Bool
precede (dia1, mes1, ano1) (dia2, mes2, ano2) 
  | not (valida (dia1, mes1, ano1)) || not (valida (dia2, mes2, ano2)) = False
  | ano1 < ano2 = True
  | ano1 == ano2 && mes1 < mes2 = True
  | ano1 == ano2 && mes1 == mes2 && dia1 < dia2 = True
  | otherwise = False

atrasados :: Emprestimos -> Data -> Emprestimos
atrasados livros dataAtual = 
  [(codigoLivro, codigoAluno, dataEmprestimo, dataDevolucao, status) | (codigoLivro, codigoAluno, dataEmprestimo, dataDevolucao, status) <- livros,  
  not (precede dataAtual dataDevolucao)]

-- Exercício 11
uniaoNRec :: [Int] -> [Int] -> [Int]
uniaoNRec xs ys = xs ++ [ y | y <- ys, not (elem y xs)]