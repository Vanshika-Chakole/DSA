class Solution {
public:
   
        int countBits(int n){
            int count = 0;
            while(n > 0){
                if(n % 2 == 1){
                    count++;
                }
                n = n / 2;
            }
            return count;
        }
         vector<int> sortByBits(vector<int>& arr) {
       
            sort(arr.begin(), arr.end(), [this] (int a, int b){
                int countA = countBits(a);
                int countB = countBits(b);

                if(countA == countB){
                    return a<b;
                }
                return countA<countB;
            });
            return arr;
        }
};