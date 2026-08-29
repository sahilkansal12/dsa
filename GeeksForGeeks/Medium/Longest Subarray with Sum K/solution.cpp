class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        
        // int r=0;
        // int l=0;
        // int sum=0;
        // int max_len=INT_MIN;
        // while(r<arr.size())
        // {
        //     sum=sum+arr[r];
        //     if(sum==k)
        //     {
        //         max_len=max(max_len,r-l+1);
        //     }
            
        //     if(sum>k)
        //     {
        //         sum=sum-arr[l];
        //         l++;
        //     }
            
        //     r++;
            
        // }
        // return max_len;
        
        int i=0;
        int max_len=INT_MIN;
        unordered_map<int,int>mp;
        int n=arr.size();
        int sum=0;
        while(i<n)
        {
          sum=sum+arr[i];
          if(sum==k)
          {
              max_len=i+1;
          }
          
          if(mp.find(sum-k)!=mp.end())
          {
              int len=i-mp[sum-k];
              max_len=max(max_len,len);
          }
          
          if(mp.find(sum)==mp.end())
          {
              mp[sum]=i;
          }
          
          i=i+1;
          
          
        }
        
        if (max_len==INT_MIN) return 0;
        
        return max_len;
        
        
        
        
        
        
        
        
        
        
        
        
    }
};