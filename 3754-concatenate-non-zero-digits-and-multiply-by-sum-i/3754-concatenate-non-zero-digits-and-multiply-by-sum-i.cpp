class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        int x=0, i=-1;

        while(n!=0){
            int r = n%10;

            if (r != 0){
                i++;
                x += (pow(10, i))*r;
                sum += n%10;
            }
            n /= 10;
        }

        return x*sum;
    }
};