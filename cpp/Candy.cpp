class Solution {
public:
    int candy(vector<int> &ratings) {
        int childrenNum = ratings.size();
        vector<int> candy(childrenNum,0);
        int sum = 0 ;
        candy[0] = 1;
        for (int i = 1; i < childrenNum ; i++) {
            if( ratings[i] > ratings[i-1] )
                candy[i] = candy[i-1]+1;
            else
                candy[i]=1;
        }
        if (candy[childrenNum-1]==0) {
            candy[childrenNum-1] = 1;
        }
        sum = candy[childrenNum-1];
        for (int i = childrenNum-2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1] && candy[i+1]+1 > candy[i] )
                candy[i] = candy[i+1]+1;
            sum+= candy[i];
        }
        return sum;
    }
};