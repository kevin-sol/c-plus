class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()){
            return "";
        }
        int length=strs.size();
        int n=strs[0].size();
        for(int i=0;i<n;++i){
            char ch=strs[0][i];
            for(int j=0;j<length;++j){
                if(strs[j][i]!=ch||i==strs[j].size()){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};