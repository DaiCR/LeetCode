## 54. Spiral Matrix ##
### Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

### For example, Given the following matrix: ###
### [ ###
### [ 1, 2, 3 ], ###
### [ 4, 5, 6 ], ###
### [ 7, 8, 9 ] ###
### ] ###

spiral order就是螺旋式的排序，比较奇怪的一个要求，如果用很多种循环求解的话必然是可以的，但是时间复杂度也是非常的高，这里需要一个稍微简洁的方法。

比较巧妙的一个方法就是，螺旋式的排序可以分解成四个动作，就是“右下左上”的顺序，以此循环，直到不能循环为止。

那么如何去构建这四个动作呢？例如，以右来说，实际上就是横坐标不变，纵坐标不断加1，假如初始的坐标为(a,b)，那么就是a+0,b+1。这里的方法就是**设置一个二维数组，每个元素代表不同的方向**。[[0,1],[1,0],[0,-1],[-1,0]]。

在想好四个方向之后，下一步就是去开始循环，假设对于5*3的二维数组来说，实际上垂直方面的移动最多也就移动2步，水平最多移动4步,这里还需要一个数组来标志着我们是否可以退出循环。

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int> > Dir{{0,1},{1,0},{0,-1},{-1,0}};
        vector<int> res;
        int r = matrix.size();
        if(r == 0)  return res; //这边要注意！！！！！得先判断，不然输入为空的话就会报错
        int c = matrix[0].size();
        if(c == 0)  return res;
        
        int iDir = 0;
        int ir = 0;
        int ic = -1;
        vector<int> nsteps{c,r-1};
        
        while(nsteps[iDir % 2]){
            for(int i = 0; i < nsteps[iDir % 2]; i++){
                ir += Dir[iDir][0];
                ic += Dir[iDir][1];
                res.push_back(matrix[ir][ic]);
            }
            
            nsteps[iDir % 2]--;
            iDir = (iDir + 1) % 4;
            
        }
        return res;
        
    }
};
```