--HOW TO RUN Haskell
-- 1) New Terminal 
-- 2) Type "ghci" in terminal
-- 3) Load Haskell file by :l HaskellFile.hs


merge :: [Integer] -> [Integer] -> [Integer] -- Sets up the expected inputs to be used
merge xs [] = xs  -- Empty Set Rule
merge [] xs = xs --If empty use xs 
merge (x: xs) (y:ys) | x < y  = x:(merge xs (y:ys)) --If left element is smaller, output to first
                     |otherwise = y:(merge (x:xs) ys) -- otherwise output right first

divide :: [Integer] -> ([Integer], [Integer]) --Divides the set of integers 
divide [] = ([], []) -- Emplty Set Rule
divide [x] = ([x], []) -- Uses X if 2nd set is empty
divide (x:y:xs) = ((x:ys), (y:zs)) --Divides on the left and right integer sets
    where (ys, zs) = divide xs --Puts elements in ys and zs after dividing from set xs

--Wrapper class of merge sort
mergesort :: [Integer] -> [Integer] --Sets expected input
mergesort [] = [] --Empty Sets
mergesort [x] = [x] -- If just x -> x
mergesort xs = merge (mergesort ys) (mergesort zs) --Merges left and right integer sets together after sorting
    where (ys, zs) = divide xs --ys and zs get mapped after being divided from xs set

--Main function
main :: IO()
main = print(mergesort [4, 65, 2, -31, 0, 99, 2, 83, 782, 1]) --array to be sorted