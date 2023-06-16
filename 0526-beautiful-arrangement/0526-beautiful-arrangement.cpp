class Solution1 {
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
class Solution {
public:
    int countArrangement(int n) {
        vector<bool> bitvec(n+1,true);
        int p=0;
        int all=s(n,bitvec,p);
        return all;
    }
private:
    int s(int n,vector<bool> bitvec, int p){
        int a=0;
        if(p==n )return 1;
        else{
            for(int i=1;i<=n;i++){
                if(bitvec[i] && ((i%(p+1)==0 || ((p+1) %i==0)))){
                    bitvec[i]=0;
                    p++;
                    a+=s(n,bitvec,p);
                    p--;
                    bitvec[i]=1;
                    }
            }
        }
        return a;
    }
};
class Solution3 {
public:
    int countArrangement(int n) {
        vector<bool> bitvec(n+1,true);
        int p=0;
        int all=0;
        s(n,bitvec,p,all);
        return all;
    }
private:
    void s(int n,vector<bool> bitvec, int p,int& all){
        if(p==n )all++;
        else{
            for(int i=1;i<=n;i++){
                if(bitvec[i] && ((i%(p+1)==0 || ((p+1) %i==0)))){
                    bitvec[i]=0;
                    p++;
                    s(n,bitvec,p,all);
                    p--;
                    bitvec[i]=1;
                    }
            }
        }
    }
};
class Solution2 {
public:
    int countArrangement(int n) {
        vector<bool> bitvec(n+1,true);
        vector<int> p;
        int all=0;
        s(n,bitvec,p,all);
        return all;
    }
private:
    void s(int n,vector<bool> bitvec, vector<int> p,int& all){
        if(p.size()==n )all++;
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