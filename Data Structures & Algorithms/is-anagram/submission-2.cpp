class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq1; 
        unordered_map<char, int> freq2; 

        for (char c1: s) {
            freq1[c1]++;
        }

        for (char c2: t) {
            freq2[c2]++;
        }

        return freq1 == freq2; 
    }
};
