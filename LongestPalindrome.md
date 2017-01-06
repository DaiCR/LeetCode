## 409. Longest Palindrome ##
### Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

### This is case sensitive, for example "Aa" is not considered a palindrome here. ###

### Note:Assume the length of given string will not exceed 1,010. ###

比如abccccdd，结果就是7 因为可以构成dccaccd这个回文序列。
其实就是偶数的话没有问题，如果奇数的话，比如3个a，那么其中两个a没有问题，另一个a可以放在中间，但是如果其他落单的字母就不行了。
```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int odds=0;
        for(char i = 'A';i <= 'z';i++){
//与1运算就是把奇数不论多少个都按1个计算
            odds += count(s.begin(),s.end(),i) & 1;
        }
        return s.size() - odds + (odds > 0);
    }
};
```
