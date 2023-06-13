class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size() -1;
        int m=0;
        while(s<=e){
            m=(s+e)/2;
            if(nums[m]==target )return m;
            else if(nums[s]<=nums[m]){
                if(nums[s]<=target && nums[m]>=target){
                    e=m-1;
                }
                else{
                    s=m+1;
                }  
            }
            else{
                if(nums[e]>=target && nums[m]<=target){
                    s=m+1;
                }
                else{
                    e=m-1;
                }
            }
        }
        return -1;  
    }
};
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
    }
};