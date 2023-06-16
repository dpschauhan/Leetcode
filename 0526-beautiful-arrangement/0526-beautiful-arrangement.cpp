class Solution {
public:
    int countArrangement(int n) {
        vector<bool> bitvec(n+1,true);
        vector<int> p;
        vector<vector<int>> all;
        s(n,bitvec,p,all);
        return all.size();
    }
private:
    void s(int n,vector<bool> bitvec, vector<int> p,vector<vector<int>>& all){
        if(p.size()==n )all.push_back(p);
        else{
            for(int i=1;i<=n;i++){
                if(bitvec[i] && ((i%(p.size()+1)==0 || ((p.size()+1) %i==0)))){
                    bitvec[i]=0;
                    p.push_back(i);
                    s(n,bitvec,p,all);
                    p.pop_back();
                    bitvec[i]=1;
                    }
            }
        }
    }
};