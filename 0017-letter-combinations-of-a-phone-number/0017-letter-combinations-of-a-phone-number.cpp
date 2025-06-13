class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // If the input string is empty, return an empty vector
        if (digits.empty()) return {};
      
        // Create a mapping for the digits to their corresponding letters
        std::vector<std::string> dialpad = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
      
        // Initialize the answer vector with an empty string to start the combinations
        std::vector<std::string> combinations = {""};
      
        // Loop through each digit in the input string
        for (char digit : digits) {
            // Get the string that corresponds to the current digit
            std::string chars = dialpad[digit-'0'];
          
            // Temporary vector to store the new combinations
            std::vector<std::string> tempCombinations;
          
            // Loop through each combination we have so far
            for (std::string &combination : combinations) {
                // Append each character that corresponds to the current digit
                for (char ch : chars) {
                    tempCombinations.push_back(combination + ch);
                }
            }
            // Replace the combinations with the updated ones
            combinations = std::move(tempCombinations);
        }
        // Return the vector containing all combinations
        return combinations;
    }
};