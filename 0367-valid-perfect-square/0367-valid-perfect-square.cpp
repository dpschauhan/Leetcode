class Solution {
public:
    bool isPerfectSquare(int num) {
        // Square numbers end with 0, 1, 4, 5, 6 or 9
        int ld = num % 10; //last digit
        if(ld==2 ||ld==3|| ld==7 || ld==8 ){
            return 0;
        }
        else {
            long long int i=0;
            while (i*i<=num){
                if(i*i==num){
                    return 1; 
                }
                i++;
            }
            return 0;
        }
    }
};
class Solution1 {
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