# [USACO 2018 January Contest, Gold](http://www.usaco.org/index.php?page=jan18results)
## [Problem 2. Cow at Large](http://www.usaco.org/index.php?page=viewproblem2&cpid=790)

Cornered at last, Bessie has gone to ground in a remote farm. The farm consists of `N` barns `(2 <= N <= 10^5)` and `N-1` bidirectional tunnels between barns, so that there is a unique path between every pair of barns. Every barn which has only one tunnel is an exit. When morning comes, Bessie will surface at some barn and attempt to reach an exit.

But the moment Bessie surfaces, the law will be able to pinpoint her location. Some farmers will then start at various exit barns, and attempt to catch Bessie. The farmers move at the same speed as Bessie (so in each time step, each farmer can move from one barn to an adjacent barn). The farmers know where Bessie is at all times, and Bessie knows where the farmers are at all times. The farmers catch Bessie if at any instant a farmer is in the same barn as Bessie, or crossing the same tunnel as Bessie. Conversely, Bessie escapes if she reaches an exit barn before any farms catch her.

Bessie is unsure about her chances of success, which depends on the number of farmers that the law is able to deploy. Given that Bessie surfaces at barn `K`, help Bessie determine the minimum number of farmers who would be needed to catch Bessie, assuming that the farmers distribute themselves optimally among the exit barns.

### INPUT FORMAT (file atlarge.in):
The first line of the input contains `N` and `K`. Each of the following `N−1` lines specify two integers, each in the range `1…N`, describing a tunnel between two barns.

### OUTPUT FORMAT (file atlarge.out):
Please output the minimum number of farmers needed to ensure catching Bessie.

### SAMPLE INPUT:
```
7 1
1 2
1 3
3 4
3 5
4 6
5 7
```

### SAMPLE OUTPUT:
```
3
```

# [Solutions](https://github.com/Reddimus/USACO_notes/tree/main/Graphs/Gold/P2_2018-Cow_At_Large)

## Graphs - Breadth-first search approach

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