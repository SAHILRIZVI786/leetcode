class Solution {
public:
    int minDeletions(string s) {
        vector<int>ans(26,0);
        int count=0;
        for(int i=0;i<s.size();i++){
            ans[s[i]-'a']++;
        }
        int size=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=0){
                size++;
            }
        }
        sort(ans.begin(),ans.end(),greater<int>());
        for(int i=0;i<size-1;i++){
            if(ans[i+1]>=ans[i]){
                int curr=ans[i+1]-ans[i]+1;
                count+=ans[i+1]-ans[i]+1;
                ans[i+1]-=curr;
                if(ans[i+1]<0){
                     count-=1;
                     ans[i+1]=0;
                }
            }
        }
        return count;
    }
};