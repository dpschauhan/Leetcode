class Solution {
public:
    vector<vector<int>> ans;
    void s(vector<int>& c, int t,vector<int> a,int n){
        if(t==0){
            ans.push_back(a);
        }
        else if(n==0){
        }
        else{
            s(c,t,a,n-1);
            if(t>=c[n-1]){
               a.push_back(c[n-1]); 
               s(c,t-c[n-1],a,n);
               c.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> a;
        s(candidates,target,a,candidates.size());
        return ans;
    }
};