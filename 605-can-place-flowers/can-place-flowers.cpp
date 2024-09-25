class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int k=flowerbed.size();
        if(n==0) return true;
        if(k==1) {
            return flowerbed[0]==0 && n<=1;
        }
        for(int i=0;i<flowerbed.size();++i){
            if(flowerbed[i]==0){
                //can be planted in this but after & before should be empty
                if(i==0 && i<k-1 && flowerbed[i+1]==0){
                    --n;
                    flowerbed[i]=1;
                }
                else if(i==k-1 && i>0 && flowerbed[i-1]==0){
                      --n;
                    flowerbed[i]=1;
                }
                else if(i>0 && i<k-1 && flowerbed[i-1]==0 && flowerbed[i+1]==0) {
                    flowerbed[i]=1;
                    --n;
                }
            }
            if(n==0) return true;
        }
        return n==0;
    }
};


// [1,0,1,0,1]

// [1,0,1,0,1]