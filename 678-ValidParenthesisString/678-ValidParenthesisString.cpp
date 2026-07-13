// Last updated: 14/07/2026, 00:53:34
class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<char,int>> q ;
        stack<pair<char, int>> starsq;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                q.push({s[i],i});
            }else if(s[i]==')'){
                if(q.size()>0){
                    q.pop();
                }else if(starsq.size()>0){
                    starsq.pop();
                }else{
                    cout<<"1";
                    return false;
                }
            }else{
                starsq.push({s[i],i});
            }
        }
        while(!q.empty()){
            if(starsq.size()>0){
                pair<char, int> frontElement = q.top();
                pair<char,int> starsqElement = starsq.top();
                if(starsqElement.second<frontElement.second){
                    cout<<"2";
                    return false;
                }
                q.pop();
                starsq.pop();
            }
            else{
                    cout<<"3";
                 return false;
            }
        }
        return true;
    }
};