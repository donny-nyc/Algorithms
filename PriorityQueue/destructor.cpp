#include <iostream>

using namespace std;

class sample {
    public:
        sample() {
            cout << "constructor" << endl;
        }
        ~sample() {
            cout << "destructor" << endl;
        }
};

int main() {
    sample* s = new sample();

    delete s;
}
