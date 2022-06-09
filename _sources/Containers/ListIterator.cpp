        #include <iostream>
        #include <list>
        using namespace std;

        int main() {
            list<int> nums{1,3,6,2,5};
            nums.push_front(20);
            nums.push_back(99);

            for (auto ptr = nums.begin(); ptr != nums.end(); ptr++) {
                cout<< *ptr <<endl;
            }

            for (auto item : nums) {
                cout << item << endl;
            }

        return 0;
        }