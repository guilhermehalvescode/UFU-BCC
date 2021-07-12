{-Exercicio 9-}
--a
--Types Student
type Ano = Int

type NomeColegio = String

type Peso = Float

--Types Academical
type NomeCurso = String

type NomeUniversidade = String

type Idade = Int

--types Academical & Student
type Matricula = Int

type Altura = Float

data Estudante
  = Colegio Ano NomeColegio Matricula Altura Peso
  | Universitario NomeUniversidade NomeCurso Matricula Altura Idade

baseEstudantes :: [Estudante]
baseEstudantes =
  [ Colegio 1 "Nacional" 12345 1.60 70,
    Colegio 2 "Gabarito" 12845 1.63 65,
    Colegio 3 "Olimpo" 12385 1.69 80,
    Colegio 1 "Nacional" 72385 1.86 86,
    Colegio 2 "Gabarito" 12325 1.80 66,
    Colegio 1 "Nacional" 19385 1.83 56,
    Colegio 3 "Olimpo" 12315 1.77 78,
    Colegio 1 "Nacional" 14235 1.88 71,
    Colegio 2 "Gabarito" 92315 1.96 73,
    Colegio 1 "Olimpo" 12305 1.95 74,

    Universitario "UFU" "Computação" 12305456 1.65 20,
    Universitario "UNITRI" "Medicina" 12305349 1.66 22,
    Universitario "UNA" "Direito" 12305789 1.67 25,
    Universitario "UFU" "Música" 12305648 1.72 20,
    Universitario "UNITRI" "Computação" 12305782 1.81 25,
    Universitario "UNITRI" "Direito" 12305000 1.89 19,
    Universitario "UFU" "Computação" 12302568 1.84 18,
    Universitario "UFU" "Música" 12305760 1.71 22,
    Universitario "UNA" "Medicina" 12305493 1.98 21,
    Universitario "UNA" "Medicina" 12305243 1.93 17
  ]

--b
data Nebuloso = Verdadeiro | Falso | Talvez Float deriving Show
fuzzifica :: Float -> Nebuloso
fuzzifica grau 
  | grau <= 0 = Falso
  | grau >= 1 = Verdadeiro
  | otherwise = Talvez grau
verifica_alto :: Float -> Nebuloso
verifica_alto alt = fuzzifica ((alt - 1.70)/0.20)

descobre_altos :: [Estudante] -> [(Int, Nebuloso)]
descobre_altos estudantes = map avaliaEstudante estudantes
  where 
    avaliaEstudante :: Estudante -> (Int, Nebuloso)
    avaliaEstudante (Colegio _ _ mat alt _) = (mat, verifica_alto alt)
    avaliaEstudante (Universitario _ _ mat alt _) = (mat, verifica_alto alt)
