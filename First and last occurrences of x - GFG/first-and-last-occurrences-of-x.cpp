//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int first(int arr[], int n , int x )
{
    int start = 0, end = n-1;
    
    while(start<=end){
        
        int mid = start + (end-start)/2;
        
        if(arr[mid]==x){
            if(arr[mid-1]!=x)
            return mid;
            else end = mid-1;
        }
        else if(arr[mid]>x){
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return -1;
}
int last(int arr[], int n , int x )
{
    int start = 0, end = n-1;
    
    while(start<=end){
        
        int mid = start + (end-start)/2;
        
        if(arr[mid]==x){
            if(arr[mid+1]!=x)
            return mid;
            else start = mid+1;
        }
        else if(arr[mid]>x){
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return -1;
}
vector<int> find(int arr[], int n , int x )
{
    vector<int> ans;
    int f = first(arr,n,x);
    int l = last(arr,n,x);
    ans.push_back(f);
    ans.push_back(l);
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends