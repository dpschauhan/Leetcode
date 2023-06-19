class Solution {
private:
int dp[10001];
    bool solve(vector<int>& nums,int n,int indx){
        if(indx==n-1)return true; 
        if(indx>n-1)return false; 
        if(dp[indx]!=-1)return dp[indx];
        for(int i=1;i<=nums[indx];i++){
            if(solve(nums,n,indx+i))return dp[indx]=true;
        }
        return dp[indx]=false;
    }
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,n,0);
    }
};