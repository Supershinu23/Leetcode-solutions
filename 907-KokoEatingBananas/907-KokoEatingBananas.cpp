// Last updated: 14/07/2026, 00:53:09
class Solution {
public:
    int findHours(vector<int> &piles, int k){
        int ans = 0;
        int n =piles.size();

        for(int i=0;i<n;i++){
            ans += (piles[i] + k - 1) / k;
        }

        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l =1 ;
        int r = INT_MIN;
        for(int i=0;i<n;i++){
            r = max(r, piles[i]);
        }

        while(r>l){
            int mid = (l+r)/2;

            if(findHours(piles, mid) > h){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return l;
    }
};