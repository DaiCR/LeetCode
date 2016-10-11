## 53. Maximum Subarray ##
### Find the contiguous subarray within an array (containing at least one number) which has the largest sum. ###

### For example, given the array [-2,1,-3,4,-1,2,1,-5,4], ###
### the contiguous subarray [4,-1,2,1] has the largest sum = 6. ###

非常直接的要求，就是求解最大和的子串，因为这里不需要返回具体是哪一个子串，而是只需要返回最大和，因此一些细节不需要强调，利用sum不断加，但ans是最后的结果，ans每次都要和sum比对下，看一些是否有最大和的更新，sum在将数组元素添加进去的时候，注意，一旦低于0，就可以设置为0，代表下次开始可以不带前面的了。
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        int sum = 0;
        int ans = nums[0];
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            ans = max(sum,ans);
            sum = max(sum,0); 
        }
        return ans;
    }
};

```
题目还说可以用分治法求解这道题，感觉稍微有点复杂，先练练其他题目，之后再回头研究下。