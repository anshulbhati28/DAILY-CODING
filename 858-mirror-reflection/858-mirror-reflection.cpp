class Solution {
public:
        int mirrorReflection(int p, int q)
    {

        int reflection = p; 
        int extention = q; 
            
        while (reflection % 2 == 0 && extention % 2 == 0)
        { 

            reflection = reflection / 2;
            extention = extention / 2;
        }

        if (reflection % 2 != 0 && extention % 2 == 0)
        {
            return 0;
        }
        else if (reflection % 2 != 0 && extention % 2 != 0)
        {
            return 1;
        }
        else if (reflection % 2 == 0 && extention % 2 != 0)
        {
            return 2;
        }
        return -1;
    } 
};