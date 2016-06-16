## 39. Combination Sum ##
### Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.The same repeated number may be chosen from C unlimited number of times. ###
**Note:**
* All numbers (including target) will be positive integers.
* The solution set must not contain duplicate combinations.

### For example, given candidate set [2, 3, 6, 7] and target 7, A solution set is: ###
[
  [7],
  [2, 2, 3]
]

这道题就是给你一个数组和一个目标数，找出数组中元素相加可以得到目标数的组合。**回溯法**是解决此问题的一个很好的方法，它是一种算法思想，用到了递归。为什么要用到回溯法呢？我觉得可能是需要找到所有满足条件的组合，需要从第一个元素开始一个一个开始试，遇到不可能的就需要剪枝。
```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> line;
//排序后是为了方便剪枝
        sort(candidates.begin(),candidates.end());
        combinationSum(res,candidates,line,0,target);
        return res;
    }
//需要好好思考
private:
    void combinationSum(vector<vector<int>> &res,vector<int>& candidates,vector<int> &line,int begin,int target){
//target为0就说已经找到了，可以加进res里面了
        if(!target){
            res.push_back(line);
            return;
//注意这里return跳出函数后，会执行下面的pop_back，用于不断清空line
        }
        
        for(int i = begin;i < candidates.size() && target >= candidates[i];i++){
            line.push_back(candidates[i]);
            combinationSum(res,candidates,line,i,target - candidates[i]);
//这里的pop_back很关键
            line.pop_back();
        }
    }
};
```