class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        if(n==0) return {};
        int maxXor=pow(2,maximumBit)-1;
        vector<int>xors(n);
        int XOR=0;
        for(int i=0;i<n;++i) XOR^=nums[i];
        for(int i=0;i<n;++i){
            xors[i]=XOR^maxXor;
            XOR^=nums[n-1-i];
        }
        return xors;
    }
};
// 2-->010
// 5-->101
// 7-->111

// 1-->pow(2,20)
// generate all numbers & check xor with which no is giving max.

// 0-->00
// 1-->01
// 1-->01
// 3-->11


// store xor till i somewhere.
// not iterate on this results .
// now I want to take xor of this result with some number k such that result should be maximum.
// if bit is set then take unset bit else set bit for max result.

// so lets say xor of some n umbers is 3 now for max result generate a number which will have reverse bits of 3 i.e 00
// if this is in range then it will give max result otherwise another number would be first bit from start could be set other could be unset.


