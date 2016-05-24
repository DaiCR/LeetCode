## 120. Triangle ##
### Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below. ###

### For example, given the following triangle： ###

[
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[2]
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[3,4]
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[-1,2,-3]
]

**题目要求是在每行中取个元素使之加起来之和最小，但是一行取完后下一行只能找相邻的，比如给出的这个列子，找到3之后，不能找到-3，只能找-1和2.**

### 动态规划 ###

需要使用动态规划的方法，很难直接找出一条最佳的路径，因此需要使用动态规划的方法，我的理解就是去生成一个空间，然后再这个空间里不断更新每次的路径。看了别人的解答之后，豁然开朗，是利用**从下往上**做的，代码如下：

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();  //求triangle的行
        vector<int> minlen(triangle.back());   //首先将minlen用triangle的最后一行元素初始化，这样待会从下往上遍历不需要从最后一行了，可以从倒数第二行开始遍历。
        for(int layer = m-2;layer >= 0;layer--){   //层数
            for(int i = 0;i <= layer;i++){    //对一层中的每一个元素进行遍历
//下面这句很关键，每次先找出minlen相邻两个元素的最小值，这两个元素就是下面一层的元素。
//找出最小值，与当前这个元素相加，拿上面这个列子，就是选出[-1,2]的最小值与3相加。
//加出来这个结果就是从3开始的话最小和路径，依次网上，最后就找到了最上面的元素的最小值。
                minlen[i] = min(minlen[i],minlen[i+1]) + triangle[layer][i];
            }
        }
        return minlen[0];
    }
};
```