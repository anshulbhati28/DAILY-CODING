//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends

bool bs(int arr[],int size,int l,int h,int target){
    while(l<=h){
        int m = l+(h-l)/2;
        if(arr[m]==target) return true;
        else if(arr[m]>target) h = m-1;
        else l = m+1;
    }
    return false;
}

bool findPair(int arr[], int size, int n){
    sort(arr,arr+size);
    bool flag = false;
    for(int i=0;i<size;i++){
        flag = bs(arr,size,i+1,size-1,arr[i]+n);
        if(flag) return flag;
    }
    return flag;
}