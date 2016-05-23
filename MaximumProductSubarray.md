## 152. Maximum Product Subarray ##
### Find the contiguous subarray within an array (containing at least one number) which has the largest product. ###
### For example, given the array [2,3,-2,4],the contiguous subarray [2,3] has the largest product = 6. ###

这道题实际上就是来求一个数组中最大乘积的字串，这种题之前也遇到过，但是忘记如何去分析了，看了讨论区之后，发现对于这样的问题，因为要求是连续元素的子串，所以只有两种可能性。

假设这个数组中没有0，那么要么这个字串就是A[0],A[1],...A[i]，要么就是A[j],A[j+1],A[n-1]，不会说存在中间字串的情况，比如说，一个数组中间有两个连着的元素为[100,100]，那么会不会就是这两个元素呢？不会的，因为这种情况也就是说前面有奇数个负数，后面也有奇数个负数，但是这种情况整体就是个最大乘积了。

如果有0的话，那就要从0的位置开始，重新将值设为1了。

注意边界情况的考虑，如果数组是空的呢？

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = 1;
        int back = 1;
        int ans = INT_MIN;
        for(int i = 0;i < nums.size();i++){
            first *=nums[i];      //一前一后开始遍历
            back  *=nums[nums.size()-1-i];
            ans = max(ans,max(first,back));
            first = first ==0?1:first;
            back = back == 0?1:back;
        }
        return ans;
    }
};
```