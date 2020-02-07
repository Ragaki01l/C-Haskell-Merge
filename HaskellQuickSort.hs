--HOW TO RUN Haskell
-- 1) New Terminal 
-- 2) Type "ghci" in terminal
-- 3) Load Haskell file by :l HaskellFile.hs

quick :: [Integer] -> [Integer] -- Sets up the expected inputs to be used
quick []   = []  -- Empty Set Rule
quick (h:t)= quick  [ y | y <- t , y < h] ++ [h] ++  quick[ y | y <- t , y > h]

--  [ y | y <- t , y < h] maps left side of the list with condition y < h
-- h is the pivot, mapped from the 1st element of the list 
-- quick[ y | y <- t , y > h] maps right side of the list with condition y > h

-- EX: [5, 1, 9, 4, 6, 7, 3]
-- [1, 4 ,3] ++ [5] ++ [9, 6, 7] 1st iteration
-- [1] ++ [4, 3]        [6, 7] ++ [9]
-- [1] [3] [4]           [6] [7] [9]
-- [1, 3, 4]             [6, 7, 9]
--        [1, 3, 4, 6, 7, 9]