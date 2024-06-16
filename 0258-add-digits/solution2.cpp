class Solution {
public:
    int addDigits(int num) {
        int res = num%9;
        if (num!=0 and res == 0){
            return 9;
        }
        else
            return res;
    }
};
