class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        
        int maxLen = 0; 

        int window_start = 0; 
        unordered_map<char, int> position; 

        for (int i = 0; i < s.length(); i++) {

            if (position.count(s[i]) && position[s[i]] >= window_start) {
                window_start = position[s[i]] + 1;
            }

            position[s[i]] = i; 

            maxLen = max(maxLen, i - window_start + 1);
        }

        // int remaining = s.length() - window_start - 1; 
        // maxLen = max(maxLen, remaining);

        return maxLen; 

        // int max_length = 0;  
        // string cont; 

        // for (char c: s) {

        //     if (cont.find(c) != string::npos) {
        //         int size_of_cont = cont.size();
        //         max_length = max(max_length, size_of_cont); 
                
        //         while (cont.find(c) != string::npos) {
        //             cont = cont.substr(1);
        //         }
        //     }

        //     cont += c;
            

        // }

        // max_length = max(max_length, (int)cont.size());

        // return max_length;  
    }
};
