## 228. Summary Ranges ##
### Given a sorted integer array without duplicates, return the summary of its ranges. ###

### For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. ###

这道题比较有意思的是返回一个string类型的vector，这里查到一个比较方便的函数就是**to_string**，可以将int型转换为string。
我们在一个循环里，开始一个个遍历，这里的for循环值得学习，因为涉及到循环里面去找一个范围。
```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;
        if(n == 0)  return res;
//不需要i++ 因为后面的i会变成end+1
        for(int i = 0; i < n;){
            int start = i;
            int end = i;
//这个里面需要循环讨论一个范围，找出范围后退出循环然后加入到res的vector里
            while(end + 1 < n && nums[end] + 1 == nums[end + 1])
                end++;
            if(end > start)
                res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            else
                res.push_back(to_string(nums[start]));
            i = end + 1;
        }
        return res;
    }
};
```

