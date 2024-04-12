krLevelGenerator :: [Int] -> [Int]
krLevelGenerator [] = []
krLevelGenerator (x : ls) = x : insertarO (insertarO (krLevelGenerator ls) (2*x+1)) (3*x+1)

krIt :: Int -> [Int]
krIt 0 = []
krIt 1 = [1]
krIt k = krLevelGenerator (krIt (k-1))

insertarO :: (Ord a) => [a] -> a -> [a]
insertarO [] a = [a]
insertarO (x : xs) a
    | a < x = a : x : xs
    | a == x = x :xs
    | otherwise = x : insertarO xs a

main :: IO()
main = print (take 100 (krIt 10))