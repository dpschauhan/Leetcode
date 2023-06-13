class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int i=0;
        while (i*i<=num){
            if(i*i==num){
                return 1; 
            }
            i++;
        }
        return 0;
    }
};