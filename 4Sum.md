## 18. 4Sum ##
### Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target. ###
这次变成了4sum，其实思路和3sum差不多，先给代码。
```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int> > res;
        if(n < 4)   return res;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n - 3;i++){
            if(i > 0 && nums[i] == nums[i - 1])  continue;
            if((nums[i] + nums[i+1] + nums[i+2] + nums[i+3]) > target)  break;
            for(int j = i + 1;j < n - 2;j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                if((nums[i] + nums[j] + nums[j + 1] + nums[j + 2]) > target)    break;
                int left = j + 1;
                int right = n - 1;
                while(left < right){
                    if(nums[i] + nums[j] + nums[left] + nums[right] > target)
                        right--;
                    else if(nums[i] + nums[j] + nums[left] + nums[right] < target)
                        left++;
                    else{
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[left]);
                        tmp.push_back(nums[right]);
                        res.push_back(tmp);
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return res;
    }
};
```
其实思路是差不多的，其中，加入res还可以这样写：
```cpp
res.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
```
而且后面用到do while也是非常巧妙。