## 78. Subsets ##
### Given a set of distinct integers, nums, return all possible subsets. ###

### Note: The solution set must not contain duplicate subsets. ###

### For example, If nums = [1,2,3], a solution is: ###
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

这道题就是用来找子集，给你[1,2,3]，返回上述的子集。
这种题因为还是需要一遍遍的去找，所以容易想到递归的方法。
```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
//函数重载
        subsets(subs,sub,0,nums);
        return subs;
    }
private:
//以[1,2,3]为例
    void subsets(vector<vector<int>> &subs, vector<int> &sub, int start, vector<int>& nums){
//先把空集加入进去
        subs.push_back(sub);
        for(int i = start; i < nums.size(); i++){
//从第一个元素1开始，加入sub
            sub.push_back(nums[i]);				
            subsets(subs,sub,i + 1,nums);		//从当前元素往后，这里就是下一次调用函数时是从2开始，然后会先把1放到subs，在把[1,2]放到sub
            sub.pop_back();						//这里就是跳出函数才会出现的，需要把sub清空，就是说1开头的子集找完后，需要清空sub从2开始。
        }
    }
};

```

这题还有个用位运算的神器方法，主要是因为改题符合这三个步骤的规律。
[], [], [], [], [], [], [], []

[], [1], [], [1], [], [1], [], [1]

[], [1], [2], [1, 2], [], [1], [2], [1, 2]

[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]

首先初始化8个空，然后按照上述的方法依次添加元素就可以找到所有子集，规律就是1是隔一个出现一次，2是每四个出现两次，3是每八个出现四个。
```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int num_subset = pow(2, nums.size()); 
        vector<vector<int> > res(num_subset, vector<int>());
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < num_subset; j++)
                if ((j >> i) & 1)					//拿第一次循环来说，只有末位是1的才符合条件，也就是单数，把1加进去。
                    res[j].push_back(nums[i]);
        return res;  
    }
};
```