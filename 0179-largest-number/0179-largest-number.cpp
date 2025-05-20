class Solution {
public:
    // Custom comparator to decide the order based on concatenated string comparison
    static bool compare(string a, string b) {
        return a + b > b + a;
    }
    
    string largestNumber(vector<int>& nums) {
        // Convert integers to strings
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        // Sort using custom comparator
        sort(strNums.begin(), strNums.end(), compare);

        // If the largest number is "0", return "0"
        if (strNums[0] == "0") return "0";

        // Concatenate the result
        string result;
        for (string s : strNums) {
            result += s;
        }

        return result;
    }
};