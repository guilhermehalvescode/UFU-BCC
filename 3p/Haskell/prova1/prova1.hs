-- q1
-- correção questão 1
figura :: Int -> Int -> Int -> Int -> Int -> String
figura l1 l2 l3 l4 ang 
  | ((l1 == l2 && l3 == l4) || (l1 == l3 && l2 == l4)) && ang == 90 = "retangulo"
  | l1 == l3 && l3 == l2 && l4 == l2 && ang == 90 = "quadrado"  
  | l1 == l3 && l3 == l2 && l4 == l2 && ang /= 90 = "losango"
  | otherwise = "simples"


-- q2
seleciona :: [[Int]] -> [Int]
seleciona lista = [h | (h:cab:_) <- lista, cab > 5]


--q3
retira :: (Eq t) => t -> [t] -> [t]
retira _ [] = []
retira a (h:hs) 
  | a == h = retira a hs
  | otherwise = h : retira a hs

retira_varias :: (Eq t) => [t] -> [t] -> [t]
retira_varias [] l = l
retira_varias (h:hs) l = retira_varias hs (retira h l)


--q4
sequencia :: String -> String -> Bool
sequencia [] _ = True --Removeu todas corretamente da primeira lista
sequencia _ [] = False --Removeu todas mas a segunda ainda tem letras, lista 1 maior q lista 2
sequencia (h:hs) (x:xs) 
  | h == x = sequencia hs xs
  | otherwise = False


--q5
dicionario = ["arara","aro","arreio"]
retira_vogais :: String -> String
retira_vogais [] = []
retira_vogais (h:hs) 
  | (h == 'a') || (h == 'e') || (h == 'i') || (h == 'o') ||( h == 'u') = retira_vogais hs
  | otherwise = h : retira_vogais hs

representa :: [String] -> String -> [String]
representa palavras c = [ word | word <- palavras, retira_vogais word == c]