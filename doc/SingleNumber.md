#Single Number

...cpp
class Solution {
public:
    int singleNumber(int A[], int n) {
    	//eg. 123^123 = 0 ;
    	//eg. 123^123^anyNumber = anyNumber; 
        int result = 0;
        for (int i = 0 ; i < n ; i++) {
            result = result ^ A[i];
        }
        return result;
    }
};
...

...python
class Solution:
    def singleNumber(self, A):
    	result = 0
    	for number in A:
    		result ^= number
    	return result
...python