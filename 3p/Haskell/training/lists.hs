-- Dúvida palin n = [n..1] porque não funciona?
-- porque esta definição é usando [<limite-inferior>..<limite-superior>]
-- para fazer teria q fazer uma PA igual na forma abaixo
palin n = [n, n-1 .. 1]


-- list compression
dobraPos :: [Int] -> [Int]
dobraPos list = [ n * 2 | n <- list, n > 0] 