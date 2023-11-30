# [USACO 2016 December Contest, Gold](http://www.usaco.org/index.php?page=dec16results)
## [Problem 3. Lasers and Mirrors](http://www.usaco.org/index.php?page=viewproblem2&cpid=671)

For some reason, Farmer John's cows always seem to be running laser light shows.

For their latest show, the cows have procured a large powerful laser -- so large, in fact, that they cannot seem to move it easily from the location where it was delivered. They would like to somehow send the light from the laser to the barn on the other side of FJ's property. Both the laser and the barn can be considered to be located at points in the 2D plane on a map of FJ's farm. The cows plan to point the laser so that it sends a beam of light out either horizontally or vertically (i.e., aligned with the x or y axes). They will then bounce this beam off a number of mirrors to direct it to the barn.

On the farm there are `N` fence posts `(1≤N≤100,000)` located at distinct 2D points (also distinct from the laser and the barn) at which the cows can mount mirrors. The cows can choose not to mount a mirror on a fence post, in which case the laser would simply pass straight over the top of the post without changing direction. If the cows do mount a mirror on a fence post, they align it diagonally like / or \ so that it will re-direct a horizontal beam of light in a vertical direction or vice versa.

Please compute the minimum possible number of mirrors the cows need to use in order to re-direct the laser to the barn.

### INPUT FORMAT (file lasers.in):
The first line of input contains 5 space-separated integers: `N`, `x_L`, `y_L`, `x_B`, and `y_B`, where `(x_L,y_L)` is the location of the laser and `(x_B,y_B)` is the location of the barn. All coordinates are between `0` and `1,000,000,000`.

The next `N` lines each contain `x` and `y` locations of a fence post, both integers in the range `0…1,000,000,000`.

### OUTPUT FORMAT (file lasers.out):

Please output the minimum number of mirrors needed to direct the laser to the barn, or -1 if this is impossible to do.

### SAMPLE INPUT
```
4 0 0 7 2
3 2
0 2
1 6
3 0
```

### SAMPLE OUTPUT
```
1
```

# [Solutions](https://github.com/Reddimus/USACO_notes/tree/main/Graphs/Gold/P3_2016-Lasers_And_Mirrors)

## Shortest paths with Unweighted edges approach

### Steps
1. 

### Time & Space complexity:
Time: `O()`
Space: `O()`

Where 

### C++ Code:
```cpp
```

### Java Code:
```java
```