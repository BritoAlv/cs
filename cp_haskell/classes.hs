data Arbol a = Vacio | Nodo a (Arbol a) (Arbol a) deriving (Show)

instance Eq (Arbol a) where
  (==) :: Arbol a -> Arbol a -> Bool
  (==) x y = True

contiene :: (Eq a) => Arbol a -> a -> Bool
contiene Vacio _ = False
contiene (Nodo a b c) e
    | a == e = True
    | otherwise = contiene b e || contiene c e

elems :: Arbol a -> [a]
elems Vacio = []
elems (Nodo a b c) = elems b ++ [a] ++ elems c

class (LinkedList t a) where
    push :: t a -> a -> t a
    pop :: t a -> t a
    first :: t a -> a

instance LinkedList Stack a where
    push :: Stack a -> a -> Stack a
    push = pushS
    pop :: Stack a -> Stack a
    pop = popS
    first :: Stack a -> a
    first (NodeS x y)  = x

data Stack a = EmptyS | NodeS a (Stack a) deriving Show

pushS :: Stack a -> a -> Stack a
pushS y x = NodeS x y

popS :: Stack a -> Stack a
popS (NodeS a b) = b

data Queue a = EmptyQ | NodeQ a (Queue a) deriving Show

pushQ :: Queue a -> a -> Queue a
pushQ EmptyQ x = NodeQ x EmptyQ
pushQ (NodeQ a b) x = pushQ b x

popQ :: Queue a -> Queue a
popQ (NodeQ a b) = b

instance LinkedList Queue a where
    push :: Queue a -> a -> Queue a
    push = pushQ
    pop :: Queue a -> Queue a
    pop = popQ
    first :: Queue a -> a
    first (NodeQ y x) = y

main :: IO ()
main = print ( show ( push EmptyS 5 ))