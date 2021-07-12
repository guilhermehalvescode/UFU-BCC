{- 
data ExNovoTipo = 
  Constr1 Tipo12 Tipo12
  |Constr2 Tipo21
  |Constr3 Tipo31 Tipo32 Tipo33
  |Constr4 
-}

data Temperatura = Quente | Frio deriving (Show)
data Estacao = Verao | Outono | Inverno | Primavera
-- data Meses = 
--   Jan | Fev | Mar | Abr | Mai | Jun | Jul | Ago | Set | Out | Nov | Dez

data Meses = 
  Jan | Fev | Mar | Abr | Mai | Jun | Jul | Ago | Set | Out | Nov | Dez
  deriving (Eq, Show, Enum)

clima :: Estacao -> Temperatura
clima Inverno = Frio
clima _ = Quente


-- type Nome = String
-- type Sobrenome = String
-- type AnoNascimento = Int

-- data Pessoa = Ind Nome Sobrenome AnoNascimento deriving (Show)

p1, p2, p3 :: Pessoa
p1 = Ind "Stephen" "Hawking" 1942
p2 = Ind "Albert" "Einstein" 1879
p3 = Ind "Isaac" "Newton" 1643

primeiroNome :: Pessoa -> String
primeiroNome (Ind pNome _ _) = pNome

ultimoNome :: Pessoa -> String
ultimoNome (Ind _ uNome _) = uNome

anoNascimento :: Pessoa -> Int
anoNascimento (Ind _ _ anoNasc) = anoNasc

data Pessoa = Ind {
  primNome :: String,
  ultNome :: String, 
  anoNasc :: Int  
} deriving (Show)

p4 :: Pessoa
p4 = Ind {
  primNome = "Guilherme",
  ultNome = "Alves", 
  anoNasc = 2002
}


data Ponto = Pt Float Float deriving Show

data Forma = 
  Circulo Ponto Float | 
  Retangulo Ponto Ponto
  deriving Show

area :: Forma -> Float
area (Circulo _ r) = pi * r ^ 2
area (Retangulo (Pt x1 y1) (Pt x2 y2)) = (abs (x2 - x1)) * (abs (y2 - y1))

move :: Forma -> Float -> Float -> Forma
move (Circulo (Pt x y) r) a b = Circulo (Pt (x + a) (y + b)) r
move (Retangulo (Pt x1 y1) (Pt x2 y2)) a b = 
  Retangulo (Pt (x1+a) (y1+b)) (Pt (x2+a) (y2 + b))

baseCirculo :: Float -> Forma
baseCirculo r = Circulo (Pt 0 0) r

baseRetang :: Float -> Float -> Forma
baseRetang x y = Retangulo (Pt 0 0) (Pt x y)

-- TIPOS RECURSIVOS
data Expr = Lit Int | Add Expr Expr | Sub Expr Expr deriving Show

eval :: Expr -> Int
eval (Lit a) = a
eval (Add exp1 exp2) = eval(exp1) + eval(exp2)
eval (Sub exp1 exp2) = eval(exp1) - eval(exp2)

toStringEval :: Expr -> String
toStringEval (Lit a) = show a
toStringEval (Add exp1 exp2) = toStringEval(exp1) ++ "+" ++ toStringEval(exp2)
toStringEval (Sub exp1 exp2) = toStringEval(exp1) ++ "-" ++ toStringEval(exp2)

tamEval :: Expr -> Int
tamEval (Lit a) = 0
tamEval (Add exp1 exp2) = 1 + tamEval(exp1) + tamEval(exp2)
tamEval (Sub exp1 exp2) = 1 + tamEval(exp1) + tamEval(exp2)