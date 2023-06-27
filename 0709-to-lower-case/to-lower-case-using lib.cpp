class Solution {
public:
    string toLowerCase(string s) {
        for(int j=0;j<s.length();j++){
		    s[j]=tolower(s[j]);
        }
	    return s;
    }
};
