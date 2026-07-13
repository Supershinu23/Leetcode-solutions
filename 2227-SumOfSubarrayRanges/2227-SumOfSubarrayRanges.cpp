// Last updated: 14/07/2026, 00:52:35
class Solution {
public:
    vector<int> findNSE(vector<int> &nums){
        int n = nums.size();
        vector<int> nse(n);
        stack<int> s;

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]>=nums[i])s.pop();

            if(!s.empty())nse[i] = s.top();
            else nse[i] = n;

            s.push(i);
        }
        return nse;
    }

    vector<int> findPSEE(vector<int> &nums){
        int n = nums.size();
        vector<int> pse(n);
        stack<int> s;

        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]>nums[i])s.pop();

            if(!s.empty())pse[i] = s.top();
            else pse[i] = -1;

            s.push(i);
        }
        return pse;
    }
    long long findMinSum(vector<int> &nums){
        int n  = nums.size();
        vector<int> nse = findNSE(nums);
        vector<int> pse = findPSEE(nums);
        long long ans = 0 ;
        for(int i=0;i<n;i++){
            long long next = nse[i]-i ;
            long long prev = i-pse[i];

            long long total = next*prev;
            ans+=total*nums[i];
        }
        return ans;
    }

vector<int> findNGE(vector<int> &nums){
        int n = nums.size();
        vector<int> nse(n);
        stack<int> s;

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<nums[i])s.pop();

            if(!s.empty())nse[i] = s.top();
            else nse[i] = n;

            s.push(i);
        }
        return nse;
    }

    vector<int> findPGEE(vector<int> &nums){
        int n = nums.size();
        vector<int> pse(n);
        stack<int> s;

        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]<=nums[i])s.pop();

            if(!s.empty())pse[i] = s.top();
            else pse[i] = -1;

            s.push(i);
        }
        return pse;
    }
    long long findMaxSum(vector<int> &nums){
        int n  = nums.size();
        vector<int> nse = findNGE(nums);
        vector<int> pse = findPGEE(nums);
        long long ans = 0 ;
        for(int i=0;i<n;i++){
            long long next = nse[i]-i ;
            long long prev = i-pse[i];

            long long total = next*prev;
            ans+=total*nums[i];
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {

        long long maxSum = findMaxSum(nums);
        long long minSum = findMinSum(nums);
        return maxSum-minSum;

    }
};