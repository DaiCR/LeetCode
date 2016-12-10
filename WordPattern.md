## 290. Word Pattern ##
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.

巧妙地运用map将pattern和str里东西都转变为int型的比较。
需要考虑pattern比str长或者str比pattern长的情况。
```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,int> pa;
        map<string,int> strstr;
        int i = 0;
        int n = pattern.size();
        istringstream in(str);
        for(string word; in >> word; i++){
            if(i == n || pa[pattern[i]] != strstr[word])
                return false;
            pa[pattern[i]] = strstr[word] = i + 1;
        }
        return i == n;
    }
};
```
运用到了istringstream，在这里的功能就是将str里的字符串以空格区分分别输出到word里。
中间的for循环很巧妙，因为map默认对Int设置为0，所以当在i=0的循环里，第一步肯定是对的，接下来需要将对应的字符串map到i+1,这里就是1，以此类推。
假如pattern过长，word短的话，in>>word操作就会判断为空，所以就直接终止循环了，比较i和n就行。
word过长的话，pattern短的情况下，注意，此时会进入循环，但是pattern[i]是非法的，所以就做个if i==n判断。