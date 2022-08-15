class Solution {
public:
    int romanCharToInt(char c){
        switch(c){
        case 'I': 	return 1;
        case 'V':	return 5;
        case 'X':	return 10;
        case 'L':	return 50;
        case 'C':	return 100;
        case 'D':	return 500;
        case 'M':	return 1000;
        default:	return 0;
        }
    }
    int romanToInt(string s) {
        
        int size = s.size();
        int ans = 0;
        
        for(int i=0;i<size;i++){
            if(i<size-1 && romanCharToInt(s[i]) < romanCharToInt(s[i+1])){
                ans -= romanCharToInt(s[i]);
            }
            else ans += romanCharToInt(s[i]);
        }
        return ans;
    }
};