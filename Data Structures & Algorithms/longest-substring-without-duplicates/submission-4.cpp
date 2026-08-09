class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }

        int max_length = 0;  
        string cont; 

        for (char c: s) {

            if (cont.find(c) != string::npos) {
                int size_of_cont = cont.size();
                max_length = max(max_length, size_of_cont); 
                
                while (cont.find(c) != string::npos) {
                    cont = cont.substr(1);
                }
            }

            cont += c;
            

        }

        max_length = max(max_length, (int)cont.size());

        return max_length;  
    }
};
