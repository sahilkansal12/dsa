class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=0;
        int max1=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
           
            if(nums[i]!=nums[i+1])
             {  count++;}
            if(count==2) 
            { return nums[i];
             
             }

             
        }

        return max1;
        
    }
};