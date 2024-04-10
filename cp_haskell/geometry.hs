data Point = Point
  { px, py :: Float
  }

absPoint :: Point -> Float
absPoint p = sqrt (px p * px p + py p * py p)

data Line = Line Point Point

coef :: Line -> (Float, Float)
coef (Line p1 p2) = (m, n)
  where
    m = (py p1 - py p2) / (px p1 - px p2)
    n = py p1 - m * px p1

isInLine :: Line -> Point -> Float
isInLine (Line p1 p2) p
  | py p1 == py p2 = if py p1 == py p then 0 else 1000000000
  | otherwise = py p - m * px p - n
  where
    m = fst (coef (Line p1 p2))
    n = snd (coef (Line p1 p2))

main :: IO ()
main =
  print
    ( show
        ( isInLine
            ( Line
                (Point 1 3)
                (Point 2 4)
            )
            (Point 2 3)
        )
    )