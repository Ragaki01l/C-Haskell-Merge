--HOW TO RUN Haskell
-- 1) New Terminal 
-- 2) Type "ghci" in terminal
-- 3) Load Haskell file by :l HaskellFile.hs

quick :: [Integer] -> [Integer] 
quick []   = [] 
quick (h:t)= quick  [ y | y <- t , y < h] ++ [h] ++  quick[ y | y <- t , y > h]