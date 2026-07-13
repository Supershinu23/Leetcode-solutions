// Last updated: 14/07/2026, 00:53:29
class Solution {
public:
bool haveSameSign(int a, int b) {
    return (a * b) > 0;
}
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        st.push(asteroids[0]);
        int n = asteroids.size();

        for(int i=1;i<n;i++){
            if(asteroids[i]<0 && !st.empty() && st.top()>0){
                while(!st.empty() && st.top()>0 && abs(st.top())<abs(asteroids[i])){
                    st.pop();
                }

                if(st.empty() || st.top()<0){
                    st.push(asteroids[i]);
                }else if(st.top()==asteroids[i]*-1){
                    st.pop();
                }
            }else{
                st.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};