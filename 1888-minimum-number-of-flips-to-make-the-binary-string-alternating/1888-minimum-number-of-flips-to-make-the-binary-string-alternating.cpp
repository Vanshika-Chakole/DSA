class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string x = s + s;
        string a1 = "", a2 = "";

        for(int i = 0; i < 2*n; i++){
            if(i % 2 == 0){
                a1 += "0";
                a2 += "1";
            }
            else{
                a1 += "1";
                a2 += "0";
            }
        }
        int res = INT_MAX;
        int d1 = 0, d2 = 0;
        int l = 0;

        for(int r = 0; r < 2*n; r++){
            if(x[r] != a1[r])
            d1++;
            if(x[r] != a2[r])
            d2++;

            if(r - l + 1 > n){
            if(x[r] != a1[l])
            d1--;
            if(x[r] != a2[l])
            d2--;
            l++;
        }
        if(r - l + 1 == n){
            res = min(res,min(d1, d2));
        }
    }
    return res;
}
};