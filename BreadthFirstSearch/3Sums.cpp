#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> & nums)
	{
		vector<vector<int>> res;
		if (nums.size() < 3)
			return res;
		std::sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); ++i)
		{
			if (i > 0 && (nums[i] == nums[i - 1]))
			{
				continue;
			}
			if (nums[i] > 0)
			{
				break;
			}

			int low = i + 1;
			int high = nums.size() - 1;
			while (high > low)
			{
				if (nums[low] + nums[high] + nums[i] > 0)
				{
					high--;
				}
				else if (nums[low] + nums[high] + nums[i] < 0)
				{
					low++;
				}
				else
				{
					vector<int> temp({nums[low], nums[i], nums[high]});
					res.push_back(temp);
					low++;
					if (nums[low] + nums[high] + nums[i] == 0)
					{
						low++;
					}


				}

			}
		}
		return res;

		

	}
};



int main()
{
	Solution s;
	vector<vector<int>> res;
	vector<int> v;
	v.push_back(-1);
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(-1);
	v.push_back(-4);


	res = s.threeSum(v);
	for (int i = 0; i < res.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << "]";
	}

	
}