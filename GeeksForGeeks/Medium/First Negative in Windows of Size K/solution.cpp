class Solution {
	public:
	vector<int> firstNegInt(vector<int>& arr, int k) {
		int left = 0;
		int right = 0;
		vector<int>ans;
		queue<int>q;
		while (right<arr.size())
			{
			if (arr[right]<0)
				{
				q.push(arr[right]);
			}
			
			if ((right - left + 1) == k)
				{
				if (q.empty())
					{
					ans.push_back(0);
				}
				else
					{
					ans.push_back(q.front());
					if (arr[left] == q.front())
						{
						q.pop();
					}
				}
				
				left++;
			}
			
			right++;
		}
		
		return ans;
		
	}
};
