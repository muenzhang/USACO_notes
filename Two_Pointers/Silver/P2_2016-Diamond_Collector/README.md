# [USACO 2016 US Open Contest, Silver](https://usaco.org/index.php?page=open16results)
## [Problem 2. Diamond Collector](https://usaco.org/index.php?page=viewproblem2&cpid=643)

Bessie the cow, always a fan of shiny objects, has taken up a hobby of mining diamonds in her spare time! She has collected `N` diamonds `(N≤50,000)` of varying sizes, and she wants to arrange some of them in a pair of display cases in the barn.

Since Bessie wants the diamonds in each of the two cases to be relatively similar in size, she decides that she will not include two diamonds in the same case if their sizes differ by more than `K` (two diamonds can be displayed together in the same case if their sizes differ by exactly `K`). Given `K`, please help Bessie determine the maximum number of diamonds she can display in both cases together.

### INPUT FORMAT (file diamond.in):

The first line of the input file contains `N` and `K` `(0≤K≤1,000,000,000)`. The next `N` lines each contain an integer giving the size of one of the diamonds. All sizes will be positive and will not exceed `1,000,000,000`.

### OUTPUT FORMAT (file diamond.out):

Output a single positive integer, telling the maximum number of diamonds that Bessie can showcase in total in both the cases.

### SAMPLE INPUT:

```
7 3
10
5
1
12
9
5
14
```

### SAMPLE OUTPUT:

```
5
```
