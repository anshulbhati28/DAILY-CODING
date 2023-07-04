//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int calculate(vector<int> mat, int mid){
        int lo = 0, h = mat.size()-1;
        while(lo <= h){
            int md = (lo+h)/2;
            if(mat[md]<=mid) lo = md+1;
            else h = md-1;
        }
        return lo;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int low=1, high = 1e9;
        while(low<=high){
            int mid = (low+high)/2;
            int count = 0;
            for(int i=0;i<R;i++){
                count += calculate(matrix[i],mid);
            }
            if(count <= (R*C)/2) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends