## 55. Jump Game ##
### Given an array of non-negative integers, you are initially positioned at the first index of the array. ###

### Each element in the array represents your maximum jump length at that position. ###

### Determine if you are able to reach the last index. ###
### For example: ###
### A = [2,3,1,1,4], return true. ###

### A = [3,2,1,0,4], return false. ###

这道题就是给你一个数组，按照里面的元素代表可以往后走的范围，比如某个元素是2，就代表从这个位置开始最多可以往后走2步，最后求这个数组能否从刚开始走到最后最后一个元素。

实际上，影响走不走到最后一步主要是0的存在，正面不太好想，换一种思路就是：从头开始，计算目前所能到达的最远距离，每次循环索引会加1，当索引的值大于最大的距离时，就代表无法到达最底部了。最后比较最大距离和数组长度是否相等。
```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int m = nums.size();
        int maxJump = 0;
        int i;
        for(i = 0; i < m && i <= maxJump; i++){
            maxJump = max(maxJump, nums[i] + i);
        }
        return i == m;
    }
};
```