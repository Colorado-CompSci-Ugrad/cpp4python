#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
  list<int> nums{1,3,6,2,5};

    for (auto item : nums ) {
        cout<< item <<endl;
    }

  return 0;
}