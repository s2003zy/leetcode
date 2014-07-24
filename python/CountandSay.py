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