//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    vector<vector<int>> dp;
    int solve(int i,int W, int wt[], int val[], int n){
        if(i==0){
            if(wt[i]<= W) return val[i];
            else return 0;
        }
        if(dp[i][W]!=-1)return dp[i][W];
        int take = INT_MIN;
        int notTake = solve(i-1,W,wt,val,n);
        
        if(wt[i]<=W)
            take = val[i] + solve(i-1,W-wt[i],wt,val,n);

        return dp[i][W] = max(notTake,take);
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
       dp.resize(n,vector<int>(W+1,-1));
       solve(n-1,W,wt,val,n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends