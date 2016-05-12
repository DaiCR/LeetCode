//这是一条注释
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = -1;
        for(int i = nums.size() -2 ;i >= 0;i--){
            if(nums[i] < nums[i+1]){
                k = i;
                break;
            }
        }
        
        if(k == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(int i = nums.size() -1;i>=0;i--){
            if(nums[k] < nums[i]){
                swap(nums[k],nums[i]);
                break;
            }
        }
        reverse(nums.begin()+k+1,nums.end());
        return;
    }
};
