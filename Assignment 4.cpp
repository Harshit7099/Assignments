#include <iostream>
using namespace std;

class computation {
public:
    int compute(int a, int b) {
        return a + b;
    }

    float compute(int a, float b) {
        return a + b;
    }

    double compute(int a, double b) {
        return a + b;
    }

    int compute(char a, char b) {
        return int(a) + int(b);
    }

    int compute(char a, int b) {
        return int(a) + b; 
    }

    int compute() {
        return 1;
    }
};

    computation obj;
int main() {
    cout << "answer 1: " << obj.compute(2, 4) << endl;
    cout << "answer 2: " << obj.compute(2, 4.5f) << endl;
    cout << "answer 3: " << obj.compute(2, 4.5) << endl;
    cout << "answer 4: " << obj.compute('a', 'b') << endl;
    cout << "answer 5: " << obj.compute('a', 4) << endl;
    cout << "answer 6: " << obj.compute() << endl;
    return 0;
}