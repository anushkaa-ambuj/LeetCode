class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char> set;
        for (int i=0;i<jewels.length();i++){
            set.insert(jewels[i]);
        }
        
        int count =0;
        for (int i=0;i<stones.length();i++)
        {
            if (set.find(stones[i]) != set.end())
                count+=1;
        }
        return count;
    }
};