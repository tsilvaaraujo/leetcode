class Solution {
public:
    bool hasSameDigits(string s) {
        int left, right;
        string number;
        while(s.size() != 2) {
            number = "";
            for(int i = 0; i < s.size() - 1; i++) {
                left = s[i];
                right = s[i+1];
                number += to_string((left + right) % 10);
            }
            s = number;
        }
        if(s[0] == s[1])
            return true;
        else
            return false;
    }
};
