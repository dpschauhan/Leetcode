class Solution1 {
public:
    int coinRow(vector<int>& a,int n){
        if(n==0)return 0;
        if(n==1)return a[0];
        int n1=coinRow(a,n-1);
        int n2=a[n-1]+coinRow(a,n-2);
        return max(n1,n2);
    }
    int rob(vector<int>& nums) {
        return coinRow(nums,nums.size());
    }
};
class Solution2 {
public:
    int rob(vector<int>& nums) {
        vector<int> tbl(nums.size()+1);
        tbl[0]=0 , tbl[1]=nums[0];
        for (int n=2;n<=nums.size();n++){
            tbl[n]=max(tbl[n-1],nums[n-1]+ tbl[n-2]);
        }
        return tbl[nums.size()];
        
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> tbl(3);
        tbl[0]=0 , tbl[1]=nums[0];
        for (int n=2;n<=nums.size();n++){
            tbl[n%3]=max(tbl[(n-1)%3],nums[n-1]+ tbl[(n-2)%3]);
        }
        return tbl[(nums.size())%3];
        
    }
};

class Solution4 {
public:
    int rob(vector<int>& nums) {
        return 0;
        
    }
};