/*这道题就是找一个数组中处于峰值元素打索引，比如1,3,2，那么3就是我们要找的元素，可能一个数组中有很多这样的元素，我们只要返回其中一个就可以了。
假设nums[-1]和nums[n]为负无穷，这样对于每一个数组都存在这样的元素了。题目要求时间复杂度为log级别的，因此很容易想到二分法。*/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while(low < high){
            int mid1 = (low + high) / 2;
            int mid2 = mid1 + 1;
//对于某一个中间元素，它的索引是x，值为nums[x],假如nums[x] < nums[x+1]，说明峰值元素出现在右半部分，有两种情况：
//1.右边一直都是递增，那么这个元素就是最后一个元素。
//2.右边在某一处不再是递增，那么转折的那个地方就是峰值元素。
            if(nums[mid1] > nums[mid2])
                high = mid1;
            else
                low = mid2;
        }
        return low;
        
    }
};
