// Last updated: 14/07/2026, 00:54:37
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int l = 1,mid ;
        // int r = n ;
        while(n>l){
            mid = (n+l)/2 ;
            if(isBadVersion(mid)==false)l=mid+1 ;
            else n = mid ;
        }
        return l ;
    }
};