// Last updated: 14/07/2026, 00:54:21
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans  = 0 ;
        sort(intervals.begin(), intervals.end());
        int endTime = intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            if(endTime>intervals[i][0]){
                endTime = min(endTime, intervals[i][1]);
                ans++;
            }else{
                endTime = intervals[i][1];
            }
        }
        return ans;
    }
};