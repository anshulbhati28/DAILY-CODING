class Solution {
public:
        string sorted_num(int n){
            string str = to_string(n);
            sort(str.begin(),str.end());
            return str;
        }
    bool reorderedPowerOf2(int n) {
        string str = sorted_num(n);
        for(int i=0;i<32;i++){
            if(str == sorted_num(1<<i)) return true;
        }
        return false;
    }
};