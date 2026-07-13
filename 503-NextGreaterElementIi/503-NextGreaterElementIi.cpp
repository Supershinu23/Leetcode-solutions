// Last updated: 14/07/2026, 00:54:07
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            vec.push_back(nums[i]);
        }

        stack<int> s;
        vector<int> ans(2*n);
        ans[2*n-1] = -1;
        s.push(vec[2*n-1]);
        for(int i=2*n-2;i>=0;i--){
            while(!s.empty() && s.top()<=vec[i])s.pop();

            if(!s.empty())ans[i] = s.top();
            else ans[i] = -1;

            s.push(vec[i]);
        }
        ans[0] = ans[n];
        return vector<int>(ans.begin(), ans.begin() + n);
    }
};