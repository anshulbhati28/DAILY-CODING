//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int N, long long int k) {
                                                 
            vector<long long> ans;
            list<long long> l;
            long long i=0,j=0;
            while(j<N){
                if(arr[j]<0) l.push_back(arr[j]);
                if(j-i+1<k) j++;
                else if(j-i+1==k){
                    if(l.size()==0) ans.push_back(0);
                    else {
                        ans.push_back(l.front());
                    }
                    if(arr[i]<0) l.pop_front();
                    i++;
                    j++;
                }
            }
            return ans;
 }