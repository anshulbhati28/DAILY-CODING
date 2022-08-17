class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> st;
        vector<string> temp = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(auto word : words){
            string str = "";
            for(auto ch : word){
                str += temp[ch-'a'];
            }
            st.insert(str);
        }
        return st.size();
    }
};