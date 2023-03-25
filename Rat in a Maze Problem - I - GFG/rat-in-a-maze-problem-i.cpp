//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void helper(vector<vector<int>> &m, int n,int x,int y, string ans, vector<string>& res){
        if(x==n-1 && y==n-1){
            res.push_back(ans);
            return;
        }
        
        if(x<0 || x>=n || y<0 || y>=n || m[x][y]==0) return;
        
        m[x][y] = 0;
        
        helper(m,n,x-1,y,ans+"U",res);
        helper(m,n,x+1,y,ans+"D",res);
        helper(m,n,x,y-1,ans+"L",res);
        helper(m,n,x,y+1,ans+"R",res);
        
        m[x][y] = 1;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        if(m[n-1][n-1]==0 || m[0][0]==0){
            res.push_back("-1");
            return res;
        }
        helper(m,n,0,0,"",res);
        sort(res.begin(),res.end());
        return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends