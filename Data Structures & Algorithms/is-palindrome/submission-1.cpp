class Solution {
public:
    bool isPalindrome(string s) {
        string hold = ""; 

        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                char c = 'a' + (s[i] - 'A');
                hold += c;

            } else if (s[i] >= 'a' && s[i] <= 'z') {
                hold += s[i];
            } else if (s[i] >= '0' && s[i] <= '9') {
                hold += s[i];
            }
        }

        int back = hold.length() - 1;

        for (int i = 0; i < (hold.length() / 2); i++) {
            if (hold[i] != hold[back]) {
                return false; 
            }
            
            back--;
        }
        return true;
        
    }
};
