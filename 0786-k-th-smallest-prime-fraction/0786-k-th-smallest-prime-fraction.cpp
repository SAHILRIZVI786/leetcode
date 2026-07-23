class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<pair<float,pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                float x=arr[i];
                float y=arr[j];
                float ans=x/y;
                pq.push({ans,{arr[i],arr[j]}});
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        vector<int>temp(2);
        temp[0]=pq.top().second.first;
        temp[1]=pq.top().second.second;
        return temp;
    }
};