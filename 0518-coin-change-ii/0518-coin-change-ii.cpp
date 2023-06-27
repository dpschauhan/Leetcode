// Backtracking - At least O(2^n)
class Solution1 {
public:
    int change(int amount, vector<int>& coins) {
        int count = 0;
        int combination = 0;
        search(0, coins, combination, count, amount);
        return count;
    }
private:
    void search(int i, const vector<int>& coins, int sum, int& count, const int amount) {
        if(i == coins.size()) {
            if(sum == amount) count++;
            else {
                // one invalid combination
            }
        } else {
            search(i+1, coins, sum, count, amount); // without coins[i]
            
            // with at least one of coins[i]
            sum += coins[i]; // one occurrence of coins[i]
            if(sum <= amount) {          
               search(i, coins, sum, count, amount);
            } else {
                // branch pruning
            }
            // sum -= coins[i;]
        }
    }
};

// Head Recursive - At least O(2^n)
class Solution2 {
public:
    int change(int amount, vector<int>& coins) {
        return f1(0, amount, coins);
    }
private:
    int f1(int i, int a, const vector<int>& coins) {
        if(i == coins.size()) {
            if(a == 0) return 1; //valid combination
            else return 0; // smaller invalid combination
        } else if(a < 0) {
            return 0; //branch pruning
        } else {
            int ans = f1(i+1, a, coins); //without coins[i]
            ans += f1(i, a - coins[i], coins);
            return ans;
        }
    }
};

// Head Recursive 2 - At least O(2^n) ==> 10^90 time
class Solution3 {
public:
    int change(int amount, vector<int>& coins) {
        return f1(0, amount, coins);
    }
private:
    int f1(int i, int a, const vector<int>& coins) {
        if(i == coins.size()) {
            if(a == 0) return 1; //valid combination
            else return 0; // smaller invalid combination
        } else {
            int ans = f1(i+1, a, coins); //without coins[i]
            if(a >= coins[i])
                ans += f1(i, a - coins[i], coins);
            return ans;
        }
    }
};

// ACCEPTED by LeetCode
// Head Recursive ==> Memoization
// O(n * amount) time and space ==> 1.5 * 10^6 time
class Solution4 {
public:
    int change(int amount, vector<int>& coins) {
        unordered_map<string, int> tbl;
        return f1(0, amount, coins, tbl);
    }
private:
    int f1(int i, int a, const vector<int>& coins, unordered_map<string, int>& tbl) {
        string key = to_string(i) + "," + to_string(a);
        if(tbl.find(key) != tbl.end()) return tbl[key];
        
        if(i == coins.size()) {
            if(a == 0) return tbl[key] = 1; //valid combination
            else return tbl[key] =0; // smaller invalid combination
        } else {
            int ans = f1(i+1, a, coins, tbl); //without coins[i]
            if(a >= coins[i])
                ans += f1(i, a - coins[i], coins, tbl);
            return tbl[key] = ans;
        }
    }
};

// Head Recursive ==> Memoization using 2D-Array
// O(n * amount) time and space ==> 1.5 * 10^6 time
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // unordered_map<string, int> tbl;
        vector<vector<int>> tbl(coins.size() + 1, vector<int>(amount + 1, INT_MIN));
        return f1(0, amount, coins, tbl);
    }
private:
    int f1(int i, int a, const vector<int>& coins, vector<vector<int>>& tbl) {
        // string key = to_string(i) + "," + to_string(a);
        // if(tbl.find(key) != tbl.end()) return tbl[key];
        if(tbl[i][a] != INT_MIN) return tbl[i][a];
        
        if(i == coins.size()) {
            if(a == 0) return tbl[i][a] = 1; //valid combination
            else return tbl[i][a] =0; // smaller invalid combination
        } else {
            int ans = f1(i+1, a, coins, tbl); //without coins[i]
            if(a >= coins[i])
                ans += f1(i, a - coins[i], coins, tbl);
            return tbl[i][a] = ans;
        }
    }
};
