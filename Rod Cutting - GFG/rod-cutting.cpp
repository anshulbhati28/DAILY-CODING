//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
       vector<vector<int>> dp(n,vector<int>(n+1,-1));
       for (int i=0 ;i<=n;i++){
           dp[0][i] = i*price[0];
       }
       for(int i=1;i<n;i++){
           for(int l=0;l<=n;l++){
               int notTake = dp[i-1][l];
               int take = INT_MIN;
               if(i+1<=l) take = price[i] + dp[i][l-(i+1)];
               dp[i][l] = max(take,notTake);
           }
       }
       return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends