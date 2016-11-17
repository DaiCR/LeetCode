## 448. Find All Numbers Disappeared in an Array ##
### Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

### Find all the elements of [1, n] inclusive that do not appear in this array. ###

### Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space. ###
### Input:[4,3,2,7,8,2,3,1] ###
### Output:[5,6] ###
对于这个问题， 主要是要找到没有出现的数字。
```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if(n == 0)  return res;
        for(int i = 0;i < n;i++){
            int tmp = abs(nums[i]) - 1;
            if(nums[tmp] > 0)
                nums[tmp] = -nums[tmp];
        }
    
        for(int i = 0;i < n;i++){
            if(nums[i] > 0)
                res.push_back(i + 1);
        }
        return res;
    }
};
```
利用负数形式来标志出现过的，比如对于3，2，1，1这个序列，第一个3，实际上代表nums[2]上已经出现，将nums[2]置为负数，以此类推，为了防止负数会影响，需要设置一个中间变量，保证不会影响正常的循环。
最后再来个循环，如果大于0，说明对应位置没有数，i+1就为该数。