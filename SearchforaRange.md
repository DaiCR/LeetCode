## 34. Search for a Range ##
### Given a sorted array of integers, find the starting and ending position of a given target value. ###

### Your algorithm's runtime complexity must be in the order of O(log n).###

### If the target is not found in the array, return [-1, -1]. ###

### For example, Given [5, 7, 7, 8, 8, 10] and target value 8,return [3, 4]. ###

**题目要求是来求给定的数在数组里的范围,比如上面的target是8,在数组里的范围就是从3到4。**

因为题目要求时间复杂度为O(logn)，所以很自然的想到用二分法来做，但在实际的操作中，发现假如对于有一段是[8,8,8]来说，如果先二分中间那个8的话，实际上我们需要向左并且向右继续二分，这样跟一般的二分法就有区别了。

**两段二分法**，根据上述分析，得用两段的二分法。
```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        vector<int> res(2,-1);   //vector初始化成[-1,-1]
       
		//第一段的二分法
        while(i < j){
            int mid = (i + j) / 2;
            if(nums[mid] < target)
                i = mid + 1;
            else				//**注意这里的范围，只是把大于和等于合并到了一起，大于是mid-1赋值给j，等于是mid赋值给j，因此合并在一起就是这样。**		
                j = mid;
        }
        if(nums[i] != target)
            return res;
        else
            res[0] = i;			//找到了最左边的范围
        
        j = n - 1;
		//第二段的二分法
        while(i < j){
            int mid = (i + j) / 2 + 1;	//**注意这里的，因为后面会合并而出现i=mid的情况，因此这里我们的mid需要+1,否则一直在循环里。**
            if(nums[mid] > target)
                j = mid - 1;
            else
                i = mid;
        }
        res[1] = i ;
        return res;
        
    }
};
```