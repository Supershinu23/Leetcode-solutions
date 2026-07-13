// Last updated: 14/07/2026, 00:54:50
class Solution {
public:
void func(vector<int>& arr, int target, int idx, vector<vector<int>>&ans, vector<int>& temp, int k){
        if(target==0){
            if(temp.size()==k)ans.push_back(temp);
            return;
        }
        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1])continue;
            if(arr[i]>target)break;
            temp.push_back(arr[i]);
            func(arr, target-arr[i], i+1, ans, temp,k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates;
        for(int i=1;i<10;i++){
            candidates.push_back(i);
        }
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        
        func(candidates, n, 0, ans, temp,k);
        return ans;
    }
};