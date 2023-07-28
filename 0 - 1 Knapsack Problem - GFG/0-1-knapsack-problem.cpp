//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    vector<vector<int>> dp;
    int knapSack(int W, int wt[], int val[], int n)
    {
       vector<int>prev(W+1,0);
       
       for(int j=wt[0];j<=W;j++){
           prev[j] = val[0];
       }
       for(int i=1;i<n;i++){
           vector<int> temp(W+1,0);
           for(int j=0;j<=W;j++){
               int take = INT_MIN;
               if(wt[i]<=j) take = val[i] + prev[j-wt[i]];
               int notTake = prev[j];
               temp[j] = max(take,notTake); 
           }
           prev = temp;
       }
       return prev[W];
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