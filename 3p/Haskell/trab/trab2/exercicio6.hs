{-Exercício 6-}
{-
data Exp a =
  Val a
  | Add (Exp a) (Exp a)
  | Sub (Exp a) (Exp a)

avalia :: Num a => Exp a -> a
avalia (Val x) = x
avalia (Add exp2 exp2) = avalia exp1 + avalia exp2
avalia (Sub exp1 exp2) = avalia exp1 - avalia exp2
-}

--a
data Exp a
  = Val a
  | Add (Exp a) (Exp a)
  | Sub (Exp a) (Exp a)
  | Mul (Exp a) (Exp a)
  | Div (Exp a) (Exp a)

avalia :: (Num a, Fractional a) => Exp a -> a
avalia (Val x) = x
avalia (Add exp1 exp2) = avalia exp1 + avalia exp2
avalia (Sub exp1 exp2) = avalia exp1 - avalia exp2
avalia (Mul exp1 exp2) = avalia exp1 * avalia exp2
avalia (Div exp1 exp2) = avalia exp1 / avalia exp2

--b --dúvida na ordem
exp1 :: Exp Float
exp1 =
  Div
    (Mul (Add (Val 3) (Val 12)) (Sub (Val 15) (Val 5)))
    (Mul (Val 1) (Val 3))

-- Res: 50
exp2 :: Exp Float
exp2 =
  Mul
    (Val (-1))
    ( Mul
        (Add (Val 6) (Add (Val 1) (Sub (Val 8) (Val 5))))
        (Add (Val 2) (Div (Val 6) (Val 2)))
    )

-- Res: -50