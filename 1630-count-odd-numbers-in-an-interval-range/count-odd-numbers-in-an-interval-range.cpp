class Solution {
public:
    int countOdds(int low, int high) {
        // 1->n (n/2 +1 , n);
        return (high%2!=0)?((high/2+1)-(low/2)):((high/2)-(low/2));
    }
};

