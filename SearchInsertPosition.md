## 35. Search Insert Position ##
### Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order. ###

### You may assume no duplicates in the array. ###

### Here are few examples. ###
### [1,3,5,6], 5 → 2 ###
### [1,3,5,6], 2 → 1 ###
### [1,3,5,6], 7 → 4 ###
### [1,3,5,6], 0 → 0 ###

**这道题还是比骄傲简单的，就是求这个数在排好序的数组里的索引，如果没有的话，就求应该插在哪个位置**

同样用二分法来做。
```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        /*这里之所以用<=符号是，是因为不确定最后找到的数是正好那个数还是前面或后面的数，同时需要考虑数组只有一个数的情况。*/
        while(i <= j){
            int mid = (i + j) / 2;
            if(nums[mid] == target)
                return mid;
            else if(target < nums[mid])
                j = mid - 1;
            else
                i = mid + 1;
        }
        //循环出来的i就是我们要找的索引。
       return i;
        
    }
};
```