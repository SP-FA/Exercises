#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums)
{
    int L = 0;
    int R = nums.size() - 1;
    while (R >= L){
        int mid = (L + R) >> 1;
        if (nums[mid] > nums[mid + 1])
        {
            return nums[mid + 1];
        }
        if (nums[mid] < nums[mid - 1])
        {
            return nums[mid];
        }
        if (nums[L] < nums[mid])
        {
            L = mid;
        }
        else 
        {
            R = mid - 1;
        }
    }
    return nums[L];
}

int ans;
vector <int> num = {4,5,6,7,0,1,2};

int main(void)
{
    ans = findMin(num);
    cout << ans;
    return 0;
}