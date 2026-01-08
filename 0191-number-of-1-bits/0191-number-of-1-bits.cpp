class Solution {
public:
    int hammingWeight(int n) {
        int set_bits = 0;

        while (n){
            if (n & 1 == 1){
                set_bits++;
            }
            n>>=1;
        }

        return set_bits;
    }
};