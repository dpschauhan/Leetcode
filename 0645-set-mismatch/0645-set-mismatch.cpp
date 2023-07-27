// Solution 1 (With hash map)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int ans = 0, n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[nums[i]]++;
        int actSum = (n*(n+1)) / 2, sum = 0;
        for(auto x : mp){
            if(x.second > 1)
                ans = x.first;
            sum += x.first;
        }
        return {ans, actSum - sum};
    }
};

// Solution 2 (without hash map)
vector<int> findErrorNums(vector<int>& nums) {
	sort(begin(nums), end(nums));
	int dupl = -1;
	for (int i = 0; i < nums.size() - 1; i++) {
		if (nums[i] == nums[i + 1]) {
			dupl = nums[i];
			break;
		}
	}
	int sum = (nums.size() + 1) * nums.size() / 2;
	for (int i = 0; i < nums.size(); i++) {
		sum -= nums[i];
	}
	return { dupl, sum + dupl };
}