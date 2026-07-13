// Last updated: 14/07/2026, 00:53:15
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size()!=s.size())return false;
        string temp = s+s;
        int n = goal.size();
        for(int i=0;i<temp.size()-n;i++){
            if(temp.substr(i,n)==goal)return true;
        }
        return false;
    }
};