/*这道题是用来求一个数组的最小值，这个数组首先是排序好的，题目中的sorted好像是假定序列是升序的，然后对此数组中的某一个
元素进行旋转，求现在数组中最小的元素是什么。比如原来序列是[0,1,2,3,4],变成了[3,4,0,1,2]，找到0就行了。无重复元素。*/

class Solution {
public:
    int findMin(vector<int>& nums) {
/*用二分法来做，为什么会想放用二分法来做呢？实际上这还是找一个元素的问题，只不过数组不是常规的那样而已，可以这样想，假如
这个数组的首元素值小于末元素值，那么这个数组就已经是升序的了，不存在旋转了，最小元素就是第一个元素。假如不是这样呢？
那么这里会有两种情况，像[3,4,0,1,2]这样的情况，分成两部分[3,4]和[0,1,2]。情况一，取中间元素，该值大于或等于第一个
元素，则还处于第一部分，那么需要将start设为mid+1，因为小元素还在后面，这里要注意等于号，因为是要处理[2,1]这样的情况，
start元素和mid值一样，这样我们需要去找后面的元素。情况二，中间元素小于第一个元素，那么这个元素有可能是最小的，也有可能排在它
之前的，所以要将end设为mid值。*/
        int len = nums.size();

            int a = 0;
            int b = len - 1;

            while(a < b){
                if(nums[a] < nums[b])
                    return nums[a];
                int mid = (a+b)/2;
                if(nums[mid] >= nums[a]) //情况1
                    a = mid + 1;
                else                    //情况2
                    b = mid;
            }
            return nums[a];

        }

};
