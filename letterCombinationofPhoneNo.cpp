class Solution {
public:
    void solve(vector<string>&ans,vector<string>&mapp,int idx,string digits,string output){
        if(idx>=digits.size()){
            if(!output.empty()){
                ans.push_back(output);
            }    
            return;
        }
        string letters=mapp[digits[idx]-'0'];
        for(auto it:letters){
            solve(ans,mapp,idx+1,digits,output+it);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>mapp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string output="";
        solve(ans,mapp,0,digits,output);
        return ans;
    }
};