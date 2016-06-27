## 64. Minimum Path Sum ##
## Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path. ##

这是个典型的动态规划问题，棋子只能往下和往右走。
说白了，就是要先创建一个空间，这个空间保存了从开始往后走每一步的最小sum，每走一步就更新一次，全部更新完，终点的位置就是到终点最短路径。

那需要开辟多少空间呢？首先最容易想到的是同样开辟一个二维数组空间。
```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); 
        vector<vector<int> > sum(m, vector<int>(n, grid[0][0]));
        for (int i = 1; i < m; i++)                   //先初始化第一行和第一列
            sum[i][0] = sum[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; j++)
            sum[0][j] = sum[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; i++)					  //动态规划不断更新
            for (int j = 1; j < n; j++)
                sum[i][j]  = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
        return sum[m - 1][n - 1];
    }
};
```
因为每次只更新两列的数据，所以只需要创建两个一维数组也可以。
```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> pre(m, grid[0][0]);
        vector<int> cur(m, 0);
        for (int i = 1; i < m; i++)
            pre[i] = pre[i - 1] + grid[i][0];
        for (int j = 1; j < n; j++) { 
            cur[0] = pre[0] + grid[0][j]; 
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], pre[i]) + grid[i][j];
            swap(pre, cur); 
        }
        return pre[m - 1];
    }
};
```
当然，最简单的就是创建一个vector，因为每次比较的都是前一个元素和当前元素。
这种优化方法和之前某道题很像，忘记是哪道题了，反正都是典型的动态规划。
```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cur(m,grid[0][0]);
        for(int i = 1; i < m; i++){
            cur[i] = cur[i-1] + grid[i][0];
        }
        for(int j = 1; j < n; j++){
            cur[0] += grid[0][j];
            for(int i = 1; i < m; i++){
                cur[i] = min(cur[i-1],cur[i]) + grid[i][j];
            }
        }
        return cur[m-1];
        
    }
};
```