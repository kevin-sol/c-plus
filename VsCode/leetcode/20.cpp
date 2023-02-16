#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int l= s.size();
        if(l%2==1||l==0)return false;
        for (int i = 0; i < l; i++)
        {
            if (s[i]==')')
            {
                if(stk.empty())return false;
                if(stk.top()=='('){
                    stk.pop();
                    continue;
                }
            }
            if (s[i]==']')
            {
                if(stk.empty())return false;
                if(stk.top()=='['){
                    stk.pop();
                    continue;
                }
            }if (s[i]=='}')
            {
                if(stk.empty())return false;
                if(stk.top()=='{'){
                    stk.pop();
                    continue;
                }
            }
            stk.push(s[i]);
        }
        return stk.empty();
    }
};
int main(int argc, char const *argv[])
{
    Solution si;
    string s="(){}";
    cout<< si.isValid(s)<<endl;
    
    return 0;
}
