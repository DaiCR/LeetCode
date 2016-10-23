## 16.3Sum Closest ##
### Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution. ###
###  For example, given array S = {-1 2 1 -4}, and target = 1. ###
### The sum that is closest to the target is 2. (-1 + 2 + 1 = 2). ###
这道题与之前的3Sum也很像，先贴代码。
```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n <= 3) return accumulate(nums.begin(),nums.end(),0);
        sort(nums.begin(),nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < n - 2; i++){
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target - ans) > abs(target - sum)){
                    ans = sum;
                    if(ans == target)   return target;
                }
                target > sum ? j++ : k--;
            }
        }
        return ans;
    }
};
```
这里我们同样要先排个序，针对三个数的情况，还是从i=0开始，然后用两个游标j和k，一头一尾，排序的好处就是我们可以对每次加起来的和与target进行比较，如果比target小，我们就让j++,比target大，就k--，这就是排序的好处，而且可以让时间复杂度变低。