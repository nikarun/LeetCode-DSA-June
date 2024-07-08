class Solution(object):
    def findTheWinner(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        l1=[]
        for i in range(1,n+1):
            l1.append(i)
        curr_idx=0
        while(len(l1)!=1):
            curr_idx=curr_idx+k-1
            if(curr_idx>=len(l1)):
                curr_idx=curr_idx%len(l1)
            l1.pop(curr_idx)
        return l1[0]


        