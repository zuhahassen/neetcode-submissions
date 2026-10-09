class Solution {
public:
    bool permutationCheck(string s1, string s2) {
        unordered_set<char> first(s1.begin(), s1.end()); 
        unordered_set<char> second(s2.begin(), s2.end());

        return first == second; 
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.size() == 0 || s2.size() == 0) {
            return false; 
        }
        int l = 0; 
        string sorteds1 = s1;
        sort(sorteds1.begin(), sorteds1.end()); 

        for (int r = 0; r < s2.size(); r++) {
            while ((r - l + 1) > s1.size()) {
                l++; 
            }
            
            string sorteds2 = s2.substr(l, r - l + 1); 

            sort(sorteds2.begin(), sorteds2.end()); 

            if (sorteds1 == sorteds2) {
                return true;
            }
        }
        
        return false;  
    }
};
