class Solution {
public:
    int t[501][501];
    
    int lcs(string text1, string text2){
        
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
              if(i==0 || j==0)  t[i][j]=0;
            }
        }
        
        int m = text1.length();
        int n = text2.length();
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]) t[i][j] = 1+t[i-1][j-1];
                else t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
        return t[m][n];
    }
    int minInsertions(string s) {
        string str = s;
        reverse(s.begin(),s.end());
       int n = lcs(str,s);
       int ans = s.length() - n;
        return ans;
    }
};