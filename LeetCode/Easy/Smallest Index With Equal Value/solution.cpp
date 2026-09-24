class Solution {
public:
    int smallestEqual(vector<int>& nums) {
         int smallest;

     int n=nums.size();
     for(int i=0;i<n;i++)
     {
       if(i%10==nums[i])
       {
         return i;
         break;
       }

     }  
     return -1;
        
    }
};