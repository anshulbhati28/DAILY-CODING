class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s==t) return true;
       if(s.length()!=t.length()) return false;
       int umap[26] = {};
        for(int i=0;i<s.length();i++){
            umap[s[i]-'a']++;
            umap[t[i]-'a']--;
        }
        for(int i:umap)
            if(i) return false;
        return true;
    }
};