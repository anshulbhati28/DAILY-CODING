class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int> st;
        map<int,int> mp;
        
        for(int i=n2-1;i>=0;i--){
            if(st.empty())
                mp[nums2[i]] = -1;
            else if(st.top() > nums2[i])
                mp[nums2[i]] = st.top();
            else{
                while(!st.empty() && st.top()<=nums2[i])
                    st.pop();
                if(st.empty())
                    mp[nums2[i]]=-1;
                else mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> res;
        for(auto x: nums1)
            res.push_back(mp[x]);
        return res;
    }
};