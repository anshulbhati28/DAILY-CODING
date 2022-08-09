class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        int mod = pow(10, 9) + 7;
        map<int,long long int> mp;
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++)
        {
            mp.insert({arr[i],1});
        }        
        
        for(int i=1;i<n;i++){
           long long int count = 1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 && mp.find(arr[i]/arr[j])!= mp.end()){
                    count += mp[arr[j]]*mp[arr[i]/arr[j]];
                }
                mp[arr[i]] = count;
            }
        }
      long long int ans = 0;
        for(int i=0;i<n;i++){
            ans += mp[arr[i]];
        }
        return ans%(1000000007);
    }
};