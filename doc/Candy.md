# Candy

[Candy On LeetCode](https://oj.leetcode.com/problems/candy/)

### c++

```cpp
class Solution {
public:
    int candy(vector<int> &ratings) {
        if( ratings.size() == 0 ){
            return 0;
        }
        int sum = 0 ;
        vector<int> candy( ratings.size() , 1 );
    
        for ( int i = 1; i < ratings.size(); i++ ) {
            if( ratings[i] > ratings[ i - 1 ] ){
                candy[i] = candy[i-1]+1;
            }
        }
        
        sum = candy[ ratings.size() - 1 ];
        
        for ( int i = ratings.size() - 2; i >= 0; i-- ) {
            if( ratings[i] > ratings[ i + 1 ] ){
                candy[i] = max( candy[ i + 1 ] + 1 , candy[i] ) ;
            }
            sum += candy[i];
        }
        return sum;
    }
};
```
