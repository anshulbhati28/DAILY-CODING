//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

int floor(int arr[],int n,int x){
    int l = 0, h=n-1,ans = -1;
    while(l<=h){
        int mid = (l+h)/2;
        if(arr[mid]<=x){
            ans = mid;
            l = mid+1;
        }
        else {
            h=mid-1;
        }
    }
    return ans;
}

int ceil(int arr[],int n,int x){
    int l = 0, h=n-1,ans = -1;
    while(l<=h){
        int mid = (l+h)/2;
        if(arr[mid]<x){
            l = mid+1;
        }
        else {
            ans = mid;
            h=mid-1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    sort(arr,arr+n);
    int f,c;
    pair<int,int> p;
    if(floor(arr,n,x)==-1){ 
       f = -1;
    }
    else  f = arr[floor(arr,n,x)];
    
    if(ceil(arr,n,x)==-1) c = -1;
    else    c = arr[ceil(arr,n,x)];
    
    p.first = f;
    p.second = c;
    return p;
}