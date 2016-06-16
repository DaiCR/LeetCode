## 11. Container With Most Water ##
### Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water. ###

### Note: You may not slant the container. ###
这道题的意思就是有个高度数组，就相当于隔板的高度，求数组中任意两隔板间盛水的最大量。隔板间的距离与较低隔板的高度乘积即为盛水的容量。

我们需要想一个巧妙的方法来做，我们首先认为最大乘积就是一头一尾，此时间隔是最大的，然后我们以此缩小范围，但我们缩小的准则是：因为缩小范围会让乘积的一个元素变小，所以我们找的应该是让较低隔板的高度变大的情况。

注意，使用两个变量（游标）来遍历，一头一尾，而不是一个。

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
//上面的都很常规，下面要注意的是，我们不是一定要两边同时缩小，要找的是刚刚最小的高度，让它的游标增1，尝试一下这样的情况是否会让乘积变大，
//而较大高度我们暂时不管，除非出现两个隔板是一个高度。
        if(height[i] == h)
            i++;
        if(height[j] == h)
            j--;

    }
    return water;
}
};
```