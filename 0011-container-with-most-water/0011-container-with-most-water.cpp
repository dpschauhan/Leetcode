class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int lh=0,rh=height.size()-1;
        while(lh<=rh){
            int l=abs(lh-rh);
            ans=max(ans,min(height[lh],height[rh])*l);
            if(height[lh]<height[rh])
                lh++;
            else
                rh--;
        }
        return ans;
    }
};