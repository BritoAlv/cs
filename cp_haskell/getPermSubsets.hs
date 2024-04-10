getSubsets :: [a] -> [[a]]
getSubsets [] = [[]]
getSubsets (x : xs) = getSubsets xs ++ [ x : t | t <- getSubsets xs ]

insertarP :: [a] -> a -> [[a]]
insertarP [] a = [[a]]
insertarP (x : xs) a = (a : x : xs) : [ x : p | p <- insertarP xs a]

perms :: [a] -> [[a]]
perms [] = []
perms [x] = [[x]]
perms (x : xs) = concat [ insertarP m x | m <- perms xs]

getPermSubsets :: [a] -> [[a]]
getPermSubsets l = concat [perms t | t <- getSubsets l]

main :: IO()
main = print ( show ( getPermSubsets [1,2,3]))