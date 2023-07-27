//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<bool>prev(sum+1,false);
        
        if(arr[0]<=sum){
            prev[arr[0]] = true;
        }
        prev[0] = true;
        
        for(int ind=1;ind<n;ind++){
            vector<bool> curr(sum+1,false);
            curr[0] = true;
            for(int target = 1;target<=sum;target++){
                bool notTaken = prev[target];
                bool taken = false;
                if(arr[ind]<=target) taken = prev[target-arr[ind]];
                curr[target] = taken || notTaken;
            }
            prev = curr;
        }
        
        return prev[sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends