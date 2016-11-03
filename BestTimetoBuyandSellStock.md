## 121. Best Time to Buy and Sell Stock ##
### Say you have an array for which the ith element is the price of a given stock on day i. ###

### If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit. ###

Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)

Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.

这道题就是其最大利润，给一个数组，代表价钱，然后你要先买再卖，求最大利润。
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = INT_MAX;
        int sell = 0;
        int res = 0;
        for(int i = 0;i < n;i++){
            buy = min(prices[i],buy);
            sell = max(prices[i] - buy,sell);
        }
        return sell;
    }
};
```
其实就是找两个数的差值最大，但是要后面的一个数比前面那个数大，主要是把时间复杂度控制在O(n)，所以就用上面的方法。
思路就是最大的差值肯定就是最大的减最小的，利用min和max函数，首先找到最小，然后再比较减去这个最小的当前值和之前的结果谁比较大。