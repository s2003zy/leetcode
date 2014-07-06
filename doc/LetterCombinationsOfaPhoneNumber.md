#Letter Combinations of a Phone Number

[Letter Combinations of a Phone Number On LeetCode](https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/)

###c++

```cpp
class Solution {
    
public:
    
    vector<string> letterCombinations(string digits) {
        this->initTeleButtons();        
        getResult(digits, 0, "");
        return resutul;    
    }
    
    void getResult(string digits,int k,string tempstring)
    {
        if( k >= digits.length() ){
            resutul.push_back(tempstring);
            return;
        }
        char cButton = digits[k];
        int button = std::atoi(&cButton);
        for (int i = 0 ; i < teleButtons[button].size(); i++ ) {
            tempstring += teleButtons[button][i];
            getResult(digits, k+1, tempstring);
            tempstring.pop_back();
        }
    }
    
    vector<string> resutul;
    
    vector< vector<char> > teleButtons;
    
    void initTeleButtons()
    {
        vector<char> emptyButton;
        for (int i = 0; i < 10 ; i++) {
            teleButtons.push_back(emptyButton);
        }
        int button = 2;
        for ( char c = 'a'; c < 's' ; c++) {
            int mark = ( c - 'a' +1 ) % 3;
            teleButtons[button].push_back(c);
            if(!mark)
                button++;
        }
        teleButtons[7].push_back('s');
        teleButtons[8].push_back('t');
        teleButtons[8].push_back('u');
        teleButtons[8].push_back('v');
        teleButtons[9].push_back('w');
        teleButtons[9].push_back('x');
        teleButtons[9].push_back('y');
        teleButtons[9].push_back('z');
    }
};
```

