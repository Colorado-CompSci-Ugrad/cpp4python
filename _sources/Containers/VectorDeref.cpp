#include <iostream>
#include <vector>
#include <list>
using namespace std;


int main() {
  list<int> nums{1,3,6,2,5};

    for (auto index = nums.begin(); index != nums.end(); index++) {
        cout<< *index <<endl;
    }

  return 0;
}