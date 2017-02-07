#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> num_map;
    int index = 0;
    for (const auto &i : nums)
    {
        num_map[target - i] = index++;
    }

    vector<int> result;

    for (const auto &j : nums)
    {
        if (num_map.find(j) != num_map.end())
        {
            cout<<j<<" "<<num_map[j]<<endl;
            result.push_back(j);
            result.push_back(num_map[j]);
        }
    }
    return result;
}

int main()
{
    vector<int> testcase = {1, 2, 3, 4, 5, 6, 7};
    int target = 13;
    vector<int> result = twoSum(testcase, target);
    cout<<"result is : ";
    for (const auto &w : result)
        cout<<w<<" ";
    cout<<endl;
    return 0;
}
