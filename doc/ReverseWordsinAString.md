# Reverse Words in a String

[Reverse Words in a String On LeetCode](https://oj.leetcode.com/problems/reverse-words-in-a-string/)

###c++

```cpp
class Solution {
public:
    void reverseWords(string &s) {
        string res = "";
        for (int i = s.size()-1; i >= 0 ; i--) {
            while(i>=0&&s[i]==' ') i--;
            if(i<0)break;
            string temp = "";
            while ( i>=0 && s[i]!=' ')temp+=s[i],i--;
            reverse(temp.begin(), temp.end());
            if(res=="") res+=temp;
            else res+=" " + temp;
        }
        s = res;
    }
};
```