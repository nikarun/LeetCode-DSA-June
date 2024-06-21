class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0;
        int n=customers.size();
        for(int i=0;i<n;++i){
            if(grumpy[i]==0){
                sum+=customers[i];
            }
        }
        cout<<sum<<endl;
        int i=0;
        int max_sum=0;
        while(i<n){
            int update_sum=sum;
            for(int j=i;j<i+minutes && j<n;++j){
                if(grumpy[j]==1) update_sum+=customers[j];
            }
            max_sum=max(max_sum,update_sum);
            ++i;
        }
        return max_sum;

    }
};