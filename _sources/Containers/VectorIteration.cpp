#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    list<int> nums{1, 3, 6, 2, 5};

    nums.push_back(99); // add one item to the end

    for (auto index = 0; index < nums.size(); index++)
    {
        cout << nums[index] << endl;
    }


    cout << "Overflow is " << nums[10] << endl;
    cout << "Overflow is " << nums.at(10) << endl;

    return 0;
}