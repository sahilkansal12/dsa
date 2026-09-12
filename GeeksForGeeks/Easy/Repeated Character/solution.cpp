class Solution {
  public:
    char firstRep(string s) {
//      unordered_map<char,int>mp;
     int n=s.size();
//      for(int i=0;i<n;i++)
//      {
//          mp[s[i]]++;
//      }
     
//      for(int i=0;i<n;i++)
//      {
//          if(mp[s[i]]>1) return s[i];
//      }
            
//   return '#';
 
    int fre[26]={0};
     for(int i=0;i<n;i++)
     {
         fre[s[i]-'a']++;
     }
     
     for(int i=0;i<n;i++)
     {
         if(fre[s[i] -'a']>1) return s[i];
     }
     
     return '#';
    }
};