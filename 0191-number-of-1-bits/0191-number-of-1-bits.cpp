class Solution {
public:
    int hammingWeight(int n) {
        int set_bits = 0;

        while (n){
            n&=(n-1);
            set_bits++;
        }

        return set_bits;
    }
};