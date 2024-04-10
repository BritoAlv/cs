{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}

{-# HLINT ignore "Avoid lambda" #-}
myAggregate :: (b -> a -> b) -> b -> [a] -> b
myAggregate _ x [] = x
myAggregate f x (a : as) = myAggregate f mn as where mn = f x a

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter f (x : xs) = ([x | f x]) ++ myFilter f xs

myQuickSort :: (Ord a) => [a] -> [a]
myQuickSort [] = []
myQuickSort (x : xs) =
  let smallPart = myQuickSort (myFilter (<= x) xs)
      biggerPart = myQuickSort (myFilter (> x) xs)
   in smallPart ++ [x] ++ biggerPart

myInsert :: (Ord a) => [a] -> a -> [a]
myInsert [] x = [x]
myInsert (x : xs) y
  | y <= x = y : x : xs
  | otherwise = x : myInsert xs y

myInsertionSort :: (Ord a) => [a] -> [a]
myInsertionSort [] = []
myInsertionSort (x : xs) = myInsert (myInsertionSort xs) x

myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap f (x : xs) = f x : myMap f xs

myReverse :: [a] -> [a]
myReverse [] = []
myReverse [x] = [x]
myReverse (x : xs) = myReverse xs ++ [x]

myMax :: (Ord a) => [a] -> a
myMax [x] = x
myMax (x : y : xs)
  | x < y = myMax (y : xs)
  | otherwise = myMax (x : xs)

myDivisible :: (Integral a) => a -> a -> Bool
myDivisible x y = x `mod` y == 0

myEven :: (Integral a) => a -> Bool
myEven n = myDivisible n 2

myOdd :: (Integral a) => a -> Bool
myOdd n = myDivisible n 2

applyTwice :: (a -> a) -> a -> a
applyTwice f x = f (f x)

applyInt :: (Int -> Int) -> Int
applyInt f = f 1

multiplyInt :: Int -> Int -> Int
multiplyInt x y = x * y

identity :: (Int -> Int) -> (Int -> Int)
identity f = f

myOr :: Bool -> (Bool -> Bool)
myOr x y = x || y

myMap2 :: (a -> b) -> [a] -> [b]
myMap2 f l = [f y | y <- l]

myFilter2 :: (a -> Bool) -> [a] -> [a]
myFilter2 f l = [y | y <- l, f y]

cumplen :: (a -> Bool) -> [a] -> Bool
cumplen f l = length l == length (myFilter2 f l)

myBinarySearch :: (Integral a) => (a -> Bool) -> a -> a -> a
myBinarySearch f st ed
  | ed - st <= 2 = head (myFilter2 f (myReverse [st .. ed]))
  | otherwise = if f md then myBinarySearch f md ed else myBinarySearch f st (md - 1)
  where
    md = st + div (ed - st) 2

floorSquareRoot :: (Integral a) => a -> a
floorSquareRoot x = myBinarySearch (\y -> y * y <= x) 1 x

esPrimo :: (Integral a) => a -> Bool
esPrimo 1 = False
esPrimo 2 = True
esPrimo x = null ([y | y <- [2 .. (floorSquareRoot x)], x `mod` y == 0])

sieve :: (Integral a) => [a] -> [a]
sieve [] = []
sieve (x : xs) = x : sieve [y | y <- xs, mod y x > 0]

myproducto :: (Integral a) => ([a] -> a)
myproducto = foldr (*) 1

collatzSeq :: (Integral a) => a -> [a]
collatzSeq 1 = [1]
collatzSeq n
  | myEven n = n : collatzSeq (n `div` 2)
  | otherwise = n : collatzSeq (n * 3 + 1)

myLength :: (Integral b) => [a] -> b
myLength = foldr (\x y -> y + 1) 0

collatzSeqLeng :: (Integral a) => a -> a -> [[a]]
collatzSeqLeng n m = myFilter (\y -> myLength y == m) (map collatzSeq [1 .. n])

myReverse2 :: [b] -> [b]
myReverse2 = foldr (\x y -> y ++ [x]) []

myReverse3 :: [b] -> [b]
myReverse3 = foldl (\x y -> y : x) []

isPalyndrome :: (Eq b) => [b] -> Bool
isPalyndrome l = myReverse3 l == l

factores :: Int -> [Int]
factores 1 = []
factores x = ms ++ factores (x `div` myproducto ms) where ms = [y | y <- [1 .. x], esPrimo y, x `mod` y == 0]

carNum :: Char -> [[Char]] -> Int
carNum c l = length [y | y <- l, not (null y), head y == c]

myFibonacci :: (Num t) => t -> t -> [t]
myFibonacci x y = x : myFibonacci y (x + y)

longPro :: [[t]] -> Int
longPro l = sum (map length l) `div` length l

doblePos :: [Int] -> [Int]
doblePos = map (\x -> 2 * x)

adyac :: [a] -> [(a, a)]
adyac [] = []
adyac [x] = []
adyac (x : y : xs) = (x, y) : adyac xs

takeUntil :: (a -> Bool) -> [a] -> [a]
takeUntil _ [] = []
takeUntil p (x : xs)
  | p x = x : takeUntil p xs
  | otherwise = []

hd :: [a] -> a
hd (x : xs) = x

tl :: [a] -> [a]
tl (x : xs) = xs

mypred :: (Num a) => a -> a
mypred x = x - 1

mymult :: Int -> Int -> Int
mymult x y = x * y

ones :: [Int]
ones = 1 : ones

ins :: (Ord a) => a -> [a] -> [a]
ins x [] = [x]
ins x (y : ys)
  | x <= y = x : y : ys
  | otherwise = y : ins x ys

ordIns :: (Ord a) => [a] -> [a]
ordIns = foldr ins []

min :: Ord a => [a] -> a
min xs = head (ordIns xs)

main :: IO()
main = print (show (myFibonacci 1 8))