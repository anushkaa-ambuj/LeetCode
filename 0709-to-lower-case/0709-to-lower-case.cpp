class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.length();i++){
		    if (s[i] >= 'A' && s[i] <= 'Z')    //checking for uppercase characters
			    s[i] = s[i] + 32;              //converting uppercase to lowercase
	    }
	    return s;
    }
};

