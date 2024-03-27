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
myMap2 f [] = []
myMap2 f (x : xs) = f x : [f y | y <- xs]

myFilter2 :: (a -> Bool) -> [a] -> [a]
myFilter2 f [] = []
myFilter2 f (x : xs) = ([x | f x]) ++ [y | y <- xs, f y]

cumplen:: (a -> Bool) -> [a] -> Bool
cumplen f [] = True
cumplen f (x : xs) = length (x : xs) == length (myFilter2 f (x: xs))


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

producto :: (Integral a) => [a] -> a
producto [] = 1
producto (x : xs) = myAggregate (*) 1 (x : xs)


collatzSeq :: (Integral a) => a -> [a]
collatzSeq 1 = [1]
collatzSeq n
    | myEven n = n : collatzSeq (n `div` 2)
    | otherwise = n : collatzSeq (n*3 + 1)

myLength :: (Integral b) => [a] -> b
myLength [] = 0
myLength (x : xs) = foldr (\x y  -> y + 1) 0 (x:xs)

collatzSeqLeng :: (Integral a) => a -> a -> [[a]]
collatzSeqLeng n m = myFilter (\y -> myLength y == m) (map collatzSeq [1 .. n])

myReverse2 :: [b] -> [b]
myReverse2 [] = []
myReverse2 (x : xs) = foldr (\x y -> y ++ [x]) [] (x : xs)

myReverse3 :: [b] -> [b]
myReverse3 [] = []
myReverse3 (x : xs) = foldl (\x y -> y : x) [] (x : xs)


isPalyndrome :: (Eq b) => [b] -> Bool
isPalyndrome [] = True
isPalyndrome (x : xs) = myReverse3 (x : xs) == (x : xs)

main = print ( foldl (+) 1 [1,2,3] )