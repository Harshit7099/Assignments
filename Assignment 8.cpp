#include <iostream>
using namespace std;

int computeSum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += (i * (i + 1)) / 2;
    }
    return sum;
}
int main() {
    int n;
    cout << "Enter a positive integer (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." <<endl;
        return 1;
    }
    int result = computeSum(n);
    cout << "Sum of the series where i-th term is the sum of first i natural numbers: " <<result <<endl;
    return 0;
}
