class Solution {
public:
    bool rotateString(string s, string goal) {
      
      if(s.size()!=goal.size()) return false;

      int n=s.size();

      for(int i=0;i<n;i++)
      {
         if(s==goal) return true;
         char first=s[0];

         for(int j=0;j<n-1;j++)
         {
            s[j]=s[j+1];
         }
         s[n-1]=first;

      }
     return false;
        
    }
};