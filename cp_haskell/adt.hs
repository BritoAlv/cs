data Color where
  Rojo :: Color
  Amarillo :: Color
  Verde :: Color
  Azul :: Color
  Violeta :: Color

data Figura where
    Circulo :: Float -> Figura
    Rectangulo :: Float -> Float -> Figura
    deriving Show

area :: Figura -> Float
area (Circulo r) = pi * r * r
area (Rectangulo x y) = x * y

data Par a = P a a

fst :: Par a -> a
fst (P a _) = a

snd :: Par a -> a
snd (P _ a) = a
