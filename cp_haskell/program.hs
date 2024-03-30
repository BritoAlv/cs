{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Avoid lambda" #-}
myAggregate:: (b -> a -> b) -> b -> [a] -> b
myAggregate _ x [] = x
myAggregate f x (a : as) = myAggregate f mn as where mn = f x a

myFilter:: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter f (x : xs) = ([x | f x]) ++ myFilter f xs

myQuickSort:: (Ord a) => [a] -> [a]
myQuickSort [] = []
myQuickSort (x: xs) =
    let smallPart = myQuickSort ( myFilter (<= x) xs)
        biggerPart = myQuickSort ( myFilter (> x) xs)
    in smallPart ++ [x] ++ biggerPart

myInsert:: (Ord a) => [a] -> a -> [a]
myInsert [] x = [x]
myInsert (x : xs) y | y <= x = y : x : xs
                    | otherwise = x : myInsert xs y

myInsertionSort:: (Ord a) => [a] -> [a]
myInsertionSort [] = []
myInsertionSort (x : xs) = myInsert (myInsertionSort xs) x

myMap:: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap f (x : xs) = f x : myMap f xs

myReverse:: [a] -> [a]
myReverse [] = []
myReverse [x] = [x]
myReverse (x : xs) = myReverse xs ++ [x]

myMax :: (Ord a) => [a] -> a
myMax [x] = x
myMax (x : y : xs) | x < y = myMax (y : xs)
                | otherwise =  myMax (x : xs)

myDivisible:: (Integral a) => a -> a -> Bool
myDivisible x y = x `mod` y == 0

myEven :: Integral a => a -> Bool
myEven n = myDivisible n 2

myOdd :: Integral a => a -> Bool
myOdd n = myDivisible n 2

applyTwice :: (a -> a) -> a -> a
applyTwice f x = f (f x)


applyInt :: (Int -> Int) -> Int
applyInt f = f 1

multiplyInt :: Int -> Int -> Int
multiplyInt x y = x*y

identity :: (Int -> Int) -> (Int -> Int)
identity f = f

myOr :: Bool -> (Bool -> Bool)
myOr x y = x || y

myMap2 :: (a -> b) -> [a] -> [b]
myMap2 f l = [f y | y <- l]

myFilter2 :: (a -> Bool) -> [a] -> [a]
myFilter2 f l = [y | y <- l, f y]

cumplen:: (a -> Bool) -> [a] -> Bool
cumplen f l = length l == length (myFilter2 f l)

myBinarySearch :: (Integral a) => (a -> Bool) -> a -> a -> a
myBinarySearch f st ed  | ed - st <= 2 = head (myFilter2 f (myReverse [st .. ed]))
                        | otherwise = if f md then myBinarySearch f md ed else myBinarySearch f st (md-1)
                        where md = st + div (ed - st) 2

floorSquareRoot:: (Integral a) => a -> a
floorSquareRoot x = myBinarySearch (\y -> y*y <= x) 1 x


esPrimo:: (Integral a) => a -> Bool
esPrimo 1 = False
esPrimo 2 = True
esPrimo x = null ([y | y <- [2 .. (floorSquareRoot x)], x `mod` y == 0])

sieve :: Integral a => [a] -> [a]
sieve [] = []
sieve (x : xs) = x : sieve [y | y <- xs, mod y x > 0]

myproducto :: (Integral a) => ([a] -> a)
myproducto  = foldr (*) 1

collatzSeq :: (Integral a) => a -> [a]
collatzSeq 1 = [1]
collatzSeq n
    | myEven n = n : collatzSeq (n `div` 2)
    | otherwise = n : collatzSeq (n*3 + 1)

myLength :: (Integral b) => [a] -> b
myLength = foldr (\x y  -> y + 1) 0

collatzSeqLeng :: (Integral a) => a -> a -> [[a]]
collatzSeqLeng n m = myFilter (\y -> myLength y == m) (map collatzSeq [1 .. n])

myReverse2 :: [b] -> [b]
myReverse2 = foldr (\x y -> y ++ [x]) []

myReverse3 :: [b] -> [b]
myReverse3  = foldl (\x y -> y : x) []

isPalyndrome :: (Eq b) => [b] -> Bool
isPalyndrome l = myReverse3 l == l

factores :: Int -> [Int]
factores 1 = []
factores x = ms ++ factores (x `div` myproducto ms)  where ms = [y | y <- [1 .. x], esPrimo y, x `mod`y == 0]

carNum :: Char -> [[Char]] -> Int
carNum c l = length [y | y <- l, not (null y), head y == c]

myFibonacci :: Num t => t -> t -> [t]
myFibonacci x y = x : myFibonacci y (x+y)

longPro :: [[t]] -> Int
longPro l = sum (map length l)  `div` length l

doblePos :: [Int] -> [Int]
doblePos = map (\x -> 2*x)

adyac :: [a] -> [(a, a)]
adyac [] = []
adyac [x] = []
adyac (x : y : xs) = (x, y) : adyac xs

takeUntil :: (a -> Bool) -> [a] -> [a]
takeUntil _ []  = []
takeUntil p (x : xs) | p x = x : takeUntil p xs
                     | otherwise = []

hd:: [a] -> a
hd (x : xs) = x

tl:: [a] -> [a]
tl (x : xs) = xs

mypred :: (Num a) => a -> a
mypred x = x - 1

mymult :: Int -> Int -> Int
mymult x y = x*y

{-
In both types of evaluations is from left to right.
Impacient Evaluation is first arguments, and then application of function.

mymul (1+2) (2+3)
mymul   3   (2+3)
mymul   3     5
15

Lazy Evalution is first function and then arguments, consuming an argument only if needed to apply function.

mymul (1+2) (2+3)
(1+2) * (2+3)
  3 * (2+3)
  3 * 5
  15

Bajo una estrategia impaciente la evaluación de cualquier expressión cuya evaluación falla, fallará también, sin importar si el resultado de calcular dicha subexpressión se requiere para computar el valor de la expresión general.

length[2+1, 1/0, 5-4] => falla cuando evalua 1/0

infinito :: Int
infinito = 1 + infinito

La evaluación impaciente no puede handlear eso.

infinito
 = 1 + infinito
 = 1 + ( 1 + infinito)
 = ....

fst ( 1+2, infinito)
= fst (3, infinito)
= fst (3, 1 + infinito)
= fst (3, 1 + (1 + infinito))
= ....

de la otra forma una vez que puede aplicar fst lo hace y no procede a computar infinito porque no le hace falta.

El problema de la evaluación perezosa es que los argumentos pueden ser evaluados muchas veces.

doble ( 2 * 3)
(2 * 3) + (2 * 3)
6 + (2*3)
6 + 6
12
-}

ones :: [Int]
ones = 1 : ones

ins :: Ord a => a -> [a] -> [a]
ins x [] = [x]
ins x (y : ys) | x <= y = x : y : ys
               | otherwise = y : ins x ys

ordIns :: Ord a => [a] -> [a]
ordIns = foldr ins []

min xs = head (ordIns xs)


{-
min xs = head (ordIns xs)
min [9,5,4,3,2]

= head ( ordIns [9 5 4 3 2] )
= head ( ordIns (9 : [5, 4, 3, 2]))
= head ( ins 9 ( ordIns [5, 4, 3, 2])
= head ( ins 9 ( ins 5 ( ordIns [4,3,2])))
= head ( ins 9 ( ins 5 ( ins 4 ( ins 3 ( ins 2 [] )))))
= head ( ins 9 ( ins 5 ( ins 4 ( ins 3 ( [2])))))
= head ( ins 9 ( ins 5 ( ins 4 ( 2 : ins 3 []))))
= head ( ins 9 ( ins 5 ( 2 : ins 4 ( ins 3 []))))
-}

{-

take 4 cribar [2 ..]
take 4 3 : cribar [x | x <- [3 ..], x `mod` 2 /= 0 ]
2: take 3 cribar [x | x <- [3 ..], x `mod` 2 /= 0]
2: take 3 (3 : cribar [x | x <- [x | x <- [4 ..], x `mod` 2 /= 0], x `mod 3` /= 0])

...

foldl :: (a -> b -> a) -> a -> [b] -> a
foldl f a [] = a
foldl f a (x: xs) = foldl f (f a x) xs

foldl (+) 0 [1 .. 100]
    = foldl (+) 0 (1: [2..100])
    = foldl (+) (+ 0 1) [2 .. 100]
    // now notice that it do not need the value of
    // (+ 0 1) to keep so lazy
    = foldl (+) (+(+ 0 1) 2) [3 .. 100]
    = ...
    = foldl (+) ... []
    // generated an expression like (+(+(+ 0 1) 2) 3)
    // a lot of space so a space leak.

seq :: a -> b -> b
seq a b = b

// this will force evaluation of a before obtain b, so to avoid memory leak in foldl

foldl' :: a (x : xs) = let a' = f a x in seq a' (foldl f a' xs)

the thing is that seq will force evaluation.

-}


{-
Algebraic Data Types.
-}

data Color where
  Rojo :: Color
  Amarillo :: Color
  Verde :: Color
  Azul :: Color
  Violeta :: Color

data Figura where
  Circulo :: Float -> Figura
  Rectangulo :: Float -> Float -> Figura
  deriving (Show)

area :: Figura -> Float
area (Circulo r) = pi * r * r
area (Rectangulo x y) = x*y

data Par a = P a a

fst ( P a _) = a
snd ( P _ a) = a

{- declare types -}
data Persona = Persona{
    nombre :: String,
    apellido :: String,
    edad :: Int,
    ocupacion :: String
} deriving Show

data Expr = Lit Integer | Suma Expr Expr | Resta Expr Expr deriving Eq

eval :: Expr -> Integer
eval (Lit n) = n
eval (Suma e1 e2) = eval e1 + eval e2
eval (Resta e1 e2) = eval e1 - eval e2

data Arbol a = Vacio | Nodo a ( Arbol a) (Arbol a) deriving (Show)

instance Eq (Arbol a) where
  (==) :: Arbol a -> Arbol a -> Bool
  (==) x y = True

contiene :: Eq a => Arbol a -> a -> Bool
contiene Vacio _ = False
contiene (Nodo a b c) e | a == e = True
                        | otherwise = contiene b e || contiene c e

elems :: Arbol a -> [a]
elems Vacio = []
elems (Nodo a b c) = elems b ++ [a] ++ elems c

{- declare class of types -}

main :: IO ()
main = print ( Suma (Lit 5) (Lit 2) == Lit 3)