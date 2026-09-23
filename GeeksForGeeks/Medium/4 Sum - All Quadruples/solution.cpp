class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
      sort(arr.begin(),arr.end());
      vector<vector<int>> ans;
      int n=arr.size();
      int i=0;
      
     
      map<vector<int>,int>mp;
      while(i<n-3)
      {
          int j=i+1;
          while(j<n-2)
          {
              int left=j+1;
              int right=n-1;
              
              while(left<right)
              {
                  int sum=arr[i]+arr[j]+arr[left]+arr[right];
                  if(sum==target)
                  {
                      vector<int>v1{arr[i],arr[j],arr[left],arr[right]};
                      if(mp.find(v1)==mp.end()) 
                      { mp[v1]=1;
                        ans.push_back(v1);  
                      }
                      left++;
                      right--;
                  }
                  
                 else if(sum<target)
                  {
                      left++;
                  }
                 else if(sum>target)
                 {
                     right--;
                 }
              }j++;
              
          }i++;
          
      } return ans;
        
    }
};