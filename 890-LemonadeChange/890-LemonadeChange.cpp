// Last updated: 14/07/2026, 00:53:11
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> m;

        for(int i=0;i<bills.size();i++){
            if(bills[i]==10){
                if(m[5]>0){
                    m[5]--;
                }else{
                    return false;
                }
            }else if(bills[i]==20){
                if(m[10]>0 && m[5]>0){
                    m[10]--;
                    m[5]--;
                }else if(m[5]>=3){
                    m[5]-=3;
                }else{
                    return false;
                }
            }
            m[bills[i]]++;
        }
        return true;
    }
};