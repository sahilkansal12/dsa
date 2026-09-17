class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
      vector<int> lps(n,0);
       int i=1;
       int j=0;
       lps[0]=0; 
       while(i<n)
       {
        if(s[i]==s[j])
        {
            j++;
            lps[i]=j;
            i++;
        }
        else 
        {
            if(j!=0)
            {j=lps[j-1];}
            else 
            {
                 lps[i]=0;
                i++;
            }
        }
        
       }
       string ans;
       int  k=0;
       for(int i=n-1;i>n-1-lps[n-1];i--) 
       {
           ans.push_back(s[i]);
           
       }
       reverse(ans.begin(),ans.end());
return ans;
        
    }
};