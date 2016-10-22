## 15. 3Sum ##
### Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero. ###

### Note: The solution set must not contain duplicate triplets. ###
涉及到三个数之和，当然不用三重循环，一个O(n^2)的思路如下：
先贴代码。
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int j,k;
        for(int i = 0; i < n ; i++){
            if(i > 0 && nums[i] == nums[i - 1])  continue;
            j = i + 1;
            k = n - 1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] > 0) k--;
                else if(nums[i] + nums[j] + nums[k] < 0)    j++;
                else{
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    res.push_back(tmp);
                    while(j < k && nums[k] == nums[k - 1])  k--;
                    while(j < k && nums[j] == nums[j + 1])  j++;
                    k--;
                    j++;
                }
            }

        }
        return res;
    }
};
```
其实这里一个巧妙的想法就是先对nums进行排序，排序好了之后用两个游标一前一后，首先从第一个元素开始，找另外两个元素，这两个元素就是由这两个游标控制，排序的好处就是可以利用三个数加起来与0比较，大于0的话就可以让后面的游标减1，小于0就让前面的游标加一。
还有一个需要注意的就是，题目要求得到不重复的三元组，所以需要省略部分重复的情况，一头一尾，头的重复在开始的时候判断，尾的重复就是在找到三元组之后，进行判断。