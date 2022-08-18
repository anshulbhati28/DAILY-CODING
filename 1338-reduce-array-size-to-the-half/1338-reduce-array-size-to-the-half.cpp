class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        map<int,int> mp;
        set<int> st;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        priority_queue<int> pq;
        for(auto it:mp) pq.push(it.second);
        
        int sum = 0, ans = 0;
        
        while(!pq.empty()){
            ans++;
            sum += pq.top();
            pq.pop();
            if(sum>=n/2) break;
        }
        return ans;
    }
};