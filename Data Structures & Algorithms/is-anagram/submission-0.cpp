class Solution {
public:
    bool isAnagram(string s, string t) {
        string s_1 = s;
        string t_1 = t; 
        sort(s_1.begin(), s_1.end());
        sort(t_1.begin(), t_1.end());
        return  s_1 == t_1;
    }
};
