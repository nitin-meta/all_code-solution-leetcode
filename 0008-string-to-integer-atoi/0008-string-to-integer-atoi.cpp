class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        int i = 0;
        int sign = 1;

        // Whitespace remove
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        //Sign Check
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        //while (i < s.length() && isdigit(s[i])) { or becoz isdigit is an STL(to check whther it lies in range from 0-9 or not)
         while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            // overflow check karna hai
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            res = res * 10 + digit;
            i++;
        }

        return res * sign;
    }
};
