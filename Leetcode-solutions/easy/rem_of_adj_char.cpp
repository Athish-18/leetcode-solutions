class Solution {
public:
    string removeDuplicates(string s) {
     int i = 0;
    while (i < (int)s.length() - 1) {
        if (s[i] == s[i + 1]) {
            s.erase(i, 2);
            // Move back one step to re-check new neighbors
            if (i > 0) i--;
        } else {
            i++;
        }
    }
    return s;
} 
    
};