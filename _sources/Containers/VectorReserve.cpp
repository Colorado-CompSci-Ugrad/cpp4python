// function that uses a vector to square
// every number from 0 to 49
// and does not use reserve.
// shows amount of space used
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> intvector;
    // without intvector.reserve(50);

    for (int i = 0; i < 50; i++)
    {
        intvector.push_back(i * i);
        cout << intvector.at(i) << endl;
        cout << "capacity: " << intvector.capacity() << endl;
    }
    return 0;
}