class Solution {
public:
    bool isAnagram(string s, string t) {
        // could do a frequency count of the number 
        // could do sort of s dn t and just chekc if they're equal to each other
        string s_sort = s; 
        string t_sort = t; 
        sort(s_sort.begin(), s_sort.end());
        sort(t_sort.begin(), t_sort.end());
        
        return s_sort == t_sort; 
        
    }
};
