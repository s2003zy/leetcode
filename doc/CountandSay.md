# Count and Say

[Count and Say On LeetCode](https://oj.leetcode.com/problems/count-and-say/)

### c++

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string str="1";
        for (int i = 1; i < n ; i++) {
            int counter = 0;
            stringstream s;
            char last = str[0];
            for (int j = 0;j<=str.size(); j++) {
                if(str[j]==last)
                {
                    counter++;
                    continue;
                }
                s<<counter<<last;
                counter=1;
                last = str[j];
            }
            str = s.str();
        }
        return str;
    }
};
```
### python 

```python
class Solution:
    # @return a string
    def countAndSay(self, n):
        string = '1'
        for i in range(n-1):
            counter = 0
            last = string[0]
            newstr = ""
            for s in string:
                if last == s :
                    counter+=1
                    continue
                newstr = newstr +  str(counter)+last
                last = s
                counter = 1;
            newstr = newstr +  str(counter)+last
            string = newstr
        return string
```