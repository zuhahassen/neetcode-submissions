class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 0) {
            return true; 
        }

        stack<char> parentheses; 
        unordered_map<char, char> brackets; 
        brackets['('] = ')';
        brackets['{'] = '}';
        brackets['['] = ']';


        for (char c: s) {
            if (c == ')' || c == '}' || c == ']') {
                if (parentheses.size() == 0) {
                    return false; 
                }

                char match = parentheses.top(); 

                if (brackets[match] != c) {
                    return false;
                } else {
                    parentheses.pop(); 
                }

            } else {
               parentheses.push(c); 
            }

        }
        
        return parentheses.size() == 0; 
    }
};
