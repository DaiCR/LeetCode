## 414. Third Maximum Number ##
这道题就是求一串数组中第三个大的元素，如果没有，就返回最大的元素。
时间复杂度要求在O(n)。
```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long int max = LONG_MIN;
        long int mid = LONG_MIN;
        long int small = LONG_MIN;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == max || nums[i] == mid || nums[i] == small)    continue;
            if(nums[i] > max){
                small = mid;
                mid = max;
                max = nums[i];
                count++;
            }
            else if(nums[i] > mid){
                small = mid;
                mid = nums[i];
                count++;
            }
            else if(nums[i] > small){
                small = nums[i];
                count++;
            }
        }
        return count < 3 ? max : small;
    }
};
```
主要思路是三个变量，在循环中往右移，最大的一个问题就是这三个变量初始值的问题，因为要去除重复的问题所以一开始我们要做continue判断，要是初始值设置成INT_MIN，其中有个元素也是INT_MIN，这就会被跳过了，所以设置成LONG_MIN