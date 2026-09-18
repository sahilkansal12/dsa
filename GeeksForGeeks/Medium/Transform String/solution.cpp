class Solution {
  public:
    int transform(string &s1, string &s2) {
       int n=s1.size();
        int m=s2.size();
        if(n!=m) return -1;
      
        
        int f1[256]={0};
        int f2[256]={0};
        for(int i=0;i<n;i++)
        {
            f1[(int)s1[i]]++;
        }
         for(int i=0;i<m;i++)
        {
            f2[(int)s2[i]]++;
        }
        
        for(int i=0;i<256;i++)
        {
            if(f1[i]!=f2[i]) return -1;
        }
       
        int i=n-1,j=m-1;
        int c=0;
        while(i>=0&&j>=0)
        {
            if(s1[i]==s2[j])
            {i--;
            j--;}
            
            else 
            {c++;
                i--;
            }
        }
        
        return c;
        
    }
    
    
};
