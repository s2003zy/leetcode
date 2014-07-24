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