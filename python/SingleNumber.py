class Solution:
    def singleNumber(self, A):
    	result = 0
    	for number in A:
    		result ^= number
    	return result
     