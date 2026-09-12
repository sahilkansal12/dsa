class Solution {
public:
    bool isAnagram(string s, string t) {
      int n=s.size();
      
      if(s.size()!=t.size()) return false;
      int fre[26]={0};
      for(int i=0;i<n;i++)
      {
        fre[s[i]-'a']++;
        fre[t[i]-'a']--;
      } 

      for(int i=0;i<26;i++)
      {
        if(fre[i]!=0) return false;
      }

   return true;
        
        
    }
};