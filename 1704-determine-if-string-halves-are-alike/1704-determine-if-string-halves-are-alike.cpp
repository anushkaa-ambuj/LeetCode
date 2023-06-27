class Solution {
public:
    bool halvesAreAlike(string s) {
        set <char> sets = {'a','e','i','o','u','A','E','I','O','U'};
        int mid = s.length()/2;
        int count1 = 0; int count2 = 0;
        for (int i=0;i<mid;i++){
            if (sets.find(s[i]) != sets.end())
                count1 +=1;
        }
        for (int j=mid;j<s.length();j++){
            if (sets.find(s[j]) != sets.end())
                count2 +=1;
        }
        if (count1 == count2)
            return true;
        else 
            return false;
    }
};