# Valid Palindrome

[Valid Palindrome On LeetCode](https://oj.leetcode.com/problems/valid-palindrome/)

### c++

```cpp
class Solution {
public:
    bool isPalindrome( string s ) {
        if( s == "" ){
            return "";
        }
        
        string IgnoredString = CasesIgnor( s );
        int sLen = IgnoredString.size();
        int halfLen = sLen / 2;
        int index = 0;
        
        while( index <= halfLen ){
            if( IgnoredString[ index ] != IgnoredString[ sLen - index - 1 ] ){
                return false;
            }
            index++;
        }
        return true;
    }
private:
    string CasesIgnor( string str ){
        if( str == "" ) {
            return "";
        }
        
        string res = "";
        for( int i = 0; i < str.size(); i++ ){
            char c = ToLowerCase( str[i] );
            if( c == ' ' ){
                continue;
            }
            res += c;
        }
        return res;
        
    }
    
    char ToLowerCase( char c ){
        
        bool isNumber =  ( c >= '0' && c <= '9' ) ? true : false;
        bool isLower = ( c >= 'a' && c <= 'z' ) ? true : false;
        bool isUper = ( c >= 'A' && c <= 'Z' ) ? true : false;
        
        if( (!isLower) && (!isUper) && (!isNumber) ){
            return ' ';
        }
        
        if( isLower || isNumber ){
            return c;
        }
        
        return c - 'A' + 'a';
    }

};
```