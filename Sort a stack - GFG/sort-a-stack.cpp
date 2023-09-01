//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insertCorrect(stack<int> &s,int n){
    if(s.empty() || s.top() < n){
        s.push(n);
        return;
    }
    int x = s.top();
    s.pop();
    insertCorrect(s,n);
    s.push(x);
}

void SortStack(stack<int> &s){
   if(s.empty()) return;
   int n = s.top();
   s.pop();
   SortStack(s);
   insertCorrect(s,n);
}

void SortedStack :: sort()
{
   SortStack(s);
}