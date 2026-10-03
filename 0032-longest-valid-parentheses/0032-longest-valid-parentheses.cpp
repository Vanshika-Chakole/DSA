class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);

        int ans = 0;

        for(int i = 0; i < s.length(); i++){ 
        if(s[i] == '(')
        {
            st.push(i);
        }
        else {
            st.pop();
            if(st.empty()){
                st.push(i);
            }
            else{
               ans = max(i - st.top(), ans);
            }
        }
        }
        return ans;
    }
};
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         stack<int> st;
//         st.push(-1);

//         int ans = 0;

//         for (int i = 0; i < s.length(); i++) {

//             if (s[i] == '(') {
//                 st.push(i);
//             }
//             else {
//                 st.pop();

//                 if (st.empty()) {
//                     // Current ')' becomes a new boundary
//                     st.push(i);
//                 }
//                 else {
//                     // Length of valid substring
//                     ans = max(ans, i - st.top());
//                 }
//             }
//         }

//         return ans;
//     }
// };