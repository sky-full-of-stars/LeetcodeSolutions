easy solution to think.
tricky implementation.
​
A) we always want to consider positives.
B) with negatives 2 cases:
1) even num of negatives: consider all of them
2) odd num of negatives :
a) ignore either 1st odd num or
b) last odd num.
consider everything in between.
a) ans = suffix prod of all till 1st negative num
b) ans = prefix prod of all till last negative num
C) with 0 in between, calculate ans for all non zero subsequences.
​
​
​