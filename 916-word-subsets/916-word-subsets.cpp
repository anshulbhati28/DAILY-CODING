class Solution {
public:
    vector<int> getFreq(string s)
    {
        vector<int> temp(26,0);
        for(int i=0;i<s.length();i++){
            temp[s[i]-'a']++; 
        }
        return temp;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2)
    {
        int n = words2.size();
        vector<string> ans;
        
        vector<int> countMax(26,0);    
        for(int i=0;i<n;i++){
            vector<int> temp = getFreq(words2[i]);
            
            for(int j=0;j<26;j++){
                countMax[j] = max(countMax[j],temp[j]);
            }
        }
        
        for(int i=0;i<words1.size();i++){
            vector<int> temp = getFreq(words1[i]);
            
            for(int k=0;k<26;k++){
                if(temp[k]<countMax[k]) goto h;
            }
            ans.push_back(words1[i]);
            h:;
        }
        return ans;
    }
};