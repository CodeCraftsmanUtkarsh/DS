class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd=n*n;
        int sumEven=n*(n+1);
        int gcd=1;
        for(int i=2;i<=sumEven;i++){
            if(sumOdd%i == sumEven%i){
                gcd=max(gcd,i);
            }
        }
        return gcd;
    }
};