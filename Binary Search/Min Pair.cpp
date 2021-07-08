#include <bits/stdc++.h>
using namespace std;


//Min Pair
void min_pair(vector<int> v1, vector<int> v2)
{

	int n = v1.size();
	int diff = INT_MAX;
	int left = -1, right = -1;

	sort(v2.begin(), v2.end());

	for (int i = 0; i < n; i++)
	{
		auto it = lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin();

		if (it == 0)
		{
			if (abs(v2[it] - v1[i]) < diff)
			{
				diff = abs(v2[it] - v1[i]);
				left = v1[i];
				right = v2[it];
			}
		}
		else if (it == v2.size())
		{
			if (abs(v2[it - 1] - v1[i]) < diff)
			{
				diff = abs(v2[it - 1] - v1[i]);
				left = v1[i];
				right = v2[it - 1];
			}
		}
		else
		{
			if (abs(v2[it] - v1[i]) < (abs(v2[it - 1] - v1[i])))
			{
				if (abs(v2[it] - v1[i]) < diff)
				{
					diff = abs(v2[it] - v1[i]);
					left = v1[i];
					right = v2[it];
				}
			}
			else
			{
				if (abs(v2[it - 1] - v1[i]) < diff)
				{
					diff = abs(v2[it - 1] - v1[i]);
					left = v1[i];
					right = v2[it - 1];
				}
			}
		}
	}
	cout << left << " " << right << endl;
}

int main()
{

	vector<int> a1 = {-1, 5, 10, 20, 3};
	vector<int> a2 = {26, 134, 135, 15, 17};
	min_pair(a1, a2);

	return 0;
}
