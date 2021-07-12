{- exercício 1 -}
dobro :: Int -> Int
dobro x = x * 2

quadruplicar :: Int -> Int
quadruplicar x = dobro(dobro x)

hipotenusa :: Float -> Float -> Float
hipotenusa a b = sqrt(a ** 2 + b ** 2)

distancia :: Float -> Float -> Float -> Float -> Float
distancia x1 y1 x2 y2 = sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

{- exercício 2 PNG -}

{- exercício 3 -}
conversao :: Float -> (Float, Float, Float)
conversao real = (real, real * 3.96, real * 4.45) 

{- exercício 4 -}
bissexto :: Int -> Bool
bissexto ano 
  | mod ano 400 == 0 = True
  | mod ano 4 == 0 && mod ano 100 /= 0 = True
  | otherwise = False

{- exercício 5 -}
type Data = (Int, Int, Int)
bissexto2 :: Data -> Bool
bissexto2 (dia, mes, ano)
  | mod ano 400 == 0 = True
  | mod ano 4 == 0 && mod ano 100 /= 0 = True
  | otherwise = False

{- exercício 6 -}
valida :: Data -> Bool
valida (dia, mes, ano) 
  | (dia < 1 || dia > 31) || (mes < 1 || mes > 12) = False {- Tira mes e dia com valores inválidos -}
  | dia > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11) = False {- Tira as datas com dia 31 em meses que são de 30 dias -}
  | mes == 2 && dia > 29 = False {- Tira as datas com dia 30 de fevereiro-}
  | mes == 2 && dia > 28 && not (bissexto ano) = False {- Tira as datas com dia 29 que não são bissextas -}
  | otherwise = True

{- exercício 7 -}
precede :: Data -> Data -> Bool
precede (dia1, mes1, ano1) (dia2, mes2, ano2) 
  | not (valida (dia1, mes1, ano1)) || not (valida (dia2, mes2, ano2)) = False
  | ano1 < ano2 = True
  | ano1 == ano2 && mes1 < mes2 = True
  | ano1 == ano2 && mes1 == mes2 && dia1 < dia2 = True
  | otherwise = False

{- exercício 8 -}
{-            codígo  título  autor   editora ano -}
type Livro = (String, String, String, String, Int)

{-            codígo  nome    email   telefone -}
type Aluno = (String, String, String, String)

{-                codígo-livro  código-aluno data-emprestimo data-devolucao situacao -}
type Emprestimo = (String,      String,      Data,           Data,          String)

{- exercício 9 -}
e1 :: Emprestimo
e1 = ("H123C9", "BSI200945", (12, 9, 2009), (20, 9, 2009), "aberto")

verificaEmprestimoEmDia :: Data -> Emprestimo -> Bool 
verificaEmprestimoEmDia dataHoje (codLivro, codAluno, dataEmprestimo, dataDevolucao, situacao)
  | situacao /= "aberto" = True {- Se já estiver fechado, está em dia -}
  | not(precede dataEmprestimo dataDevolucao) = False {- Se a data de emprestimo não preceder a de devolução, erro -}
  | precede dataHoje dataEmprestimo = False {- Se a data de hoje preceder a de emprestimo, erro -}
  | dataHoje == dataDevolucao = True {- Se a data de hoje for igual a de devolução, ainda está em dia -}
  | not(precede dataHoje dataDevolucao) = False {- Se a data de hoje nao preceder a de devolução, emprestimo não está em dia -}
  | otherwise = True