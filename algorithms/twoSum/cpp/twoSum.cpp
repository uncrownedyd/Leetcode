/***********************
* Author : wding 
* Data:    Feb 8th 2017
* 
*  O(n) = n;
************************/


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

    index = 0;
    for (const auto &j : nums)
    {
        if (num_map.find(j) != num_map.end() && index != num_map[j])
        {
            result.push_back(index);
            result.push_back(num_map[j]);
            break;
        }
        ++index;
    }
    return result;
}

#if 0
//use biary search, O(n) = nlogn;
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> bak = nums;
        vector<int> res;
        sort(nums.begin(), nums.end());
        int n_begin = 1;
        int n_end   = nums.size()-1;
        for (int n = 0; n < nums.size(); n++) {
            target -= nums[n];
            while (n_begin <= n_end) {
                int n_mid = (n_end - n_begin)/2 + n_begin;
                if (nums[n_mid] == target) {
                    res.push_back(nums[n]);
                    res.push_back(target);
                    break;
                } else if (nums[n_mid] < target) {
                    n_begin = n_mid + 1;
                    continue;
                } else {
                    n_end = n_mid - 1;
                    continue;
                }
            }
        }
        vector<int> output;
        for (int n = 0; n < bak.size(); n++) {
            if (bak[n] == res[0]){
                output.push_back(n);
                continue;
            }
            if (bak[n] == res[1]){
                output.push_back(n);
                continue;
            }
        }
        return output;
    }
#endif

int main()
{
    vector<int> testcase = {3, 2, 4};
    int target = 6;
    vector<int> result = twoSum(testcase, target);
    cout<<"result is : ";
    for (const auto &w : result)
        cout<<w<<" ";
    cout<<endl;
    return 0;
}
