/*对于一个序列来说，这道题就是去求这个序列的下一个增序列，就是最小的增序列。
假如某一个序列是 4,5,3,1,2,那么输出的序列就是 4 5 3 2 1。本来是想用二层循环做
的，但是看到有O(n)的方法，记录一下。*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = -1;
/*这个循环是用来找相邻元素中比后一个元素值小的index，举个例子，对于5,2,3,4,1,从最后开始找
3<4，所以记录3的index，赋值给k，但是虽然k的元素值是要比后面的大，但是不能简单的调换这两个
相邻的元素，因为还没跟后面所有的元素比较。*/
        for(int i = nums.size() -2 ;i >= 0;i--){
            if(nums[i] < nums[i+1]){
                k = i;
                break;
            }
        }
/*如果一直都没break循环，说明序列就是递减序列，那么输出序列就是这个序列的递增序列，用
vector的reverse函数就可以了。*/
        if(k == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
/*上面说到还没和后面所有的元素比较，而与后面所有元素比较的目的就是，从后面开始找，找到最大index
元素值大于k的，然后交换。*/
        for(int i = nums.size() -1;i>=0;i--){
            if(nums[k] < nums[i]){
                swap(nums[k],nums[i]);
                break;
            }
        }
/*注意，调换之后，还没有调成最小的比原序列大一个的序列，之后的序列肯定是递减的，因此在利用vector
的reverse函数调整一下为递增序列。
这就好比对于 2 5 1 4 3 --> 2 5 3 4 1 --> 2 5 3 1 4*/
        reverse(nums.begin()+k+1,nums.end());
        return;
    }
};
