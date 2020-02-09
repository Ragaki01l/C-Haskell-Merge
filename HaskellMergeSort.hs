--HOW TO RUN Haskell
-- 1) New Terminal 
-- 2) Type "ghci" in terminal
-- 3) Load Haskell file by :l HaskellFile.hs


merge :: [Integer] -> [Integer] -> [Integer] -- Sets up the expected inputs to be used
merge xs [] = xs  -- Empty Set Rule
merge [] xs = xs
merge (x: xs) (y:ys) | x < y  = x:(merge xs (y:ys))
                     |otherwise = y:(merge (x:xs) ys)

divide :: [Integer] -> ([Integer], [Integer])
divide [] = ([], [])
divide [x] = ([x], [])
divide (x:y:xs) = ((x:ys), (y:zs))
    where (ys, zs) = divide xs


mergesort :: [Integer] -> [Integer]
mergesort [] = []
mergesort [x] = [x]
mergesort xs = merge (mergesort ys) (mergesort zs)
    where (ys, zs) = divide xs