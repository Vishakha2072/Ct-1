#include <bits/stdc++.h>
using namespace std;

vector< pair<int, int> > findSubArrays(vector<int> arr, int n)
{
  unordered_map<int, vector<int> > map;
  vector <pair<int, int>> out;
  int sum = 0;

  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
    if (sum == 0)
      out.push_back(make_pair(0, i));

    if (map.find(sum) != map.end())
    {
      vector<int> vc = map[sum];
      for (auto it = vc.begin(); it != vc.end(); it++)
        out.push_back(make_pair(*it + 1, i));
    }

    map[sum].push_back(i);
  }

  return out;
}

int main()
{
    vector<int> nums;
    int size;
    cin>>size;
    
    int a;
    for(int i=0; i<size; i++){
        cin>>a;
        nums.push_back(a);
    }

    vector<pair<int, int>> out = findSubArrays(nums, size);
    for(auto& p: out){
        for(int i=p.first; i<=p.second; i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }

  return 0;
}
