data Persona where
    Persona :: {
        nombre :: String,
        apellido :: String,
        edad :: Int,
        ocupacion :: String} ->
        Persona

mixNames :: Persona -> Persona -> String
mixNames p q = nombre p ++ nombre q

instance Show Persona where 
  show :: Persona -> String
  show = nombre

    
main :: IO()
main = print ( show (
    mixNames
        (Persona "Alan Brito " "A" 10 "PensadorNocturno")
        (Persona "Delgado" "A" 10 "PensadorMadrugante")
        )
    )
