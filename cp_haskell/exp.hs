data Expr = Lit Integer | Binary Expr Expr

myVisitor :: (Expr -> a) -> (a -> a -> a) -> Expr -> a
myVisitor f _ (Lit x) = f (Lit x)
myVisitor f g (Binary x y) = g (myVisitor f g x) (myVisitor f g y)

eval :: Expr -> Integer
eval = myVisitor (\(Lit a) -> a) (+)

mylength :: Expr -> Integer
mylength = myVisitor (\(Lit a) -> 1) (+)

main :: IO ()
main =
  print
    ( show
        ( mylength
            ( Binary
                (Binary (Lit 3) (Lit 4))
                (Lit 4)
            )
        )
    )