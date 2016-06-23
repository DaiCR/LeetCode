## 74. Search a 2D Matrix ##
### Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties: ###

### Integers in each row are sorted from left to right. ###
### The first integer of each row is greater than the last integer of the previous row. ###
### For example,Consider the following matrix: ###

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
### Given target = 3, return true. ###
这道题实际上就是找数字，虽然给的是二维数组，但是因为题目给的特性，可以直接把它当作一维数组来做，然后就转换为二分法来求解即可。
因为需要把二维数组和一维数组相互转换，所以有了下面的：
其中，m为二维数组的行，n为二维数组的列。

nums[x] = numnums[x/n][x%n]
numnums[a][b] = nums[a*n+b]
接下来的二分法就没什么说的了，直接按模板来。
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0;
        int end = m * n - 1;
        int mid = 0;
        while(start < end){
            mid = (start + end) >> 1;
            if(matrix[mid/n][mid%n] < target)
                start = mid + 1;
            else if(matrix[mid/n][mid%n] > target)
                end = mid - 1;
            else
                return true;
        }
        
        return matrix[start/n][start%n] == target;
        
        
    }
};
```
这么做的问题：m*n可能会使得int溢出，需要注意。