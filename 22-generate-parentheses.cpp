class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return calc(0,n);
    }
    vector<string> calc(int p, int q){
        vector<string> ret;
        if(q==0){
            ret.push_back(string(p,')'));
            return ret;
        }
        if(p!=0){
            vector<string> tail=calc(p-1,q);
            for(auto str: tail){
                ret.push_back(")"+str);
            }
        }
        vector<string> tail=calc(p+1, q-1);
        for(auto str: tail){
            ret.push_back("("+str);
        }
        return ret;
    }
};
