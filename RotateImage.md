## 48. Rotate Image ##
### You are given an n x n 2D matrix representing an image. ###

### Rotate the image by 90 degrees (clockwise). ###

**旋转90度矩阵的问题需要记住特性：**
**1. 顺时针转90度**
1 2 3		
4 5 6  
7 8 9
先上下对调变为
7 8 9
4 5 6
1 2 3
再交换对称元素
7 4 1
8 5 2
9 6 3

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
//reverse函数对二维数组就是把一行当作一个数据以此来逆置
        reverse(matrix.begin(),matrix.end());
        for(int i = 0;i < matrix.size();i++){
            for(int j = i + 1;j < matrix[i].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
```

**2. 逆时针转90度**
1 2 3		
4 5 6  
7 8 9
先左右对调变为
3 2 1
6 5 4
9 8 7
再交换对称元素
3 6 9
2 5 8
1 4 7

```cpp
void anti_rotate(vector<vector<int> > &matrix) {
//仔细观察 实际上是每行其中的数据都被逆置，可以采用如下方法巧妙实现
    for (auto vi : matrix) reverse(vi.begin(), vi.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}
```