class Solution {
public:

vector<int> computeLPS(string &part) {

        int m = part.length();
        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {

            if (part[i] == part[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }

        return lps;
    }

    int findOccurrence(string &s, string &part, vector<int>& lps) {

        int n = s.length();
        int m = part.length();

        int i = 0;
        int j = 0;

        while (i < n) {

            if (s[i] == part[j]) {
                i++;
                j++;
            }
            else if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }

            if (j == m)
                return i - j;
        }

        return -1;
    }
    string removeOccurrences(string s, string part) {
    
vector<int> lps = computeLPS(part);

     
      while( true){
            int pos = findOccurrence(s, part, lps);

           if (pos ==-1) break;

            s.erase(pos, part.length());
      }

        return s;
    }
        
    
};