// Last updated: 14/07/2026, 00:54:28
class Solution {
public:
    struct compare{
        bool operator()(pair<int, int> a, pair<int, int> b){
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>, compare> pq ;

        for(auto it: mpp){
            pq.push({it.first, it.second});
        }

        vector<int> ans;
        while(!pq.empty() && k>0){
            pair<int, int> p = pq.top();
            pq.pop();
            ans.push_back(p.first);
            k--;
        }
        return ans;
    }
};