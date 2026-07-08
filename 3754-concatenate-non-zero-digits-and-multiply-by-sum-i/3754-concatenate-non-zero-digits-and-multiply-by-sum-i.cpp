class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        int x=0, i=0;

        while(n!=0){
            int r = n%10;

            if (r != 0){
                x += (pow(10, i))*r;
                sum += r;
                i++;
            }
            n /= 10;
        }

        return x*sum;
    }
};