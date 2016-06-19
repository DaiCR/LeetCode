## 75. Sort Colors ##
### Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue. ###

### Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively. ###
这道题就是现用0，1，2分别代表红、白、蓝，要求，给一个数组，把他按照红白蓝的顺序排好，当然题目限制使用排序算法，要不然直接就排好了。
先给出一种解决方案，总的思路就是三种颜色相当于三个部分，第一部分是0，第二部分是1，第三部分是2，令第一部分最后一个索引是r,第二部分的最后一个元素的索引是w，最后一部分是b，显然刚开始都设为0，然后从数组的第一个元素一个个往后查，不断更新。

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
      int r = 0;			//记录每一部分最后一个（下一个）元素的索引值
      int w = 0;
      int b = 0;
      for(int i = 0; i < nums.size(); i++){
          if(nums[i] == 0){				//假如第一个元素是0，由于1和2排在后面，我们要让2先往后挪一个位置，然后是1最后是0
										//往后挪的意思就是把对应部分的值赋值给nums[b/w/r]，同时++更新下一个元素摆放的位置
              nums[b++] = 2;
              nums[w++] = 1;
              nums[r++] = 0;
          }
          else if(nums[i] == 1){		//同理，先把2往后挪一个
              nums[b++] = 2;
              nums[w++] = 1;
          }
          else if(nums[i] == 2){		//这里直接把b往后挪一个索引即可
              b++;
          }
      }
    }
};
```