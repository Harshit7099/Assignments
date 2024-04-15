#include <iostream>
using namespace std;
int maximum(int* a, int* b, int* c) {
    int max_val = *a;
    if (*b > max_val) {
        max_val = *b;
    }
    if (*c > max_val) {
        max_val = *c;
    }
    return max_val;
}
int main() {
    int num1, num2, num3;

    cout << "Enter three integers: ";
    cin >> num1 >> num2 >> num3;
    int result = maximum(&num1, &num2, &num3);
    cout << "The maximum value is:"<<result<<endl;
    return 0;
}
