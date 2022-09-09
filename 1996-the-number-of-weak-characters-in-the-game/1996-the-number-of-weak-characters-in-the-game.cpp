class Solution {
public:
   static bool comparator(const vector<int>& v1,const vector<int>& v2){
       if(v1[0]==v2[0])
        return v1[1] > v2[1];
       return v1[0] < v2[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
    sort(properties.begin(),properties.end(),comparator);
        
    int min = INT_MIN;
    int result = 0;
    
    for(int i=properties.size()-1;i>=0;i--){
        vector<int> arr = properties[i];

        int def = arr[1];
        if(def<min)
            result++;
        min = max(min,def);
    }
        return result;
    }
};