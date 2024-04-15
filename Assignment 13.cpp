#include <iostream>
using namespace std;
class ArraySumCompare {
private:
    int arr1[5]; 
    int arr2[5]; 
public:
    ArraySumCompare() {
        for (int i = 0; i < 5; ++i) {
            arr1[i] = 0;
            arr2[i] = 0;
        }
    }
    void inputValues() {
        cout << "Enter 5 integers for the first array: ";
        for (int i = 0; i < 5; ++i) {
            cin >> arr1[i];
        }
        cout << "Enter 5 integers for the second array: ";
        for (int i = 0; i < 5; ++i) {
            cin >> arr2[i];
        }
    }
    int calculateSum(const int arr[]) {
        int sum = 0;
        for (int i = 0; i < 5; ++i) {
            sum += arr[i];
        }
        return sum;
    }
    void compareSums() {
        int sum1 = calculateSum(arr1);
        int sum2 = calculateSum(arr2);

        if (sum1 > sum2) {
            cout << "The first array has a higher sum." <<endl;
        } else if (sum2 > sum1) {
            cout << "The second array has a higher sum." <<endl;
        } else {
            cout << "Both arrays have the same sum." << endl;
        }
    }
};
int main() {
    ArraySumCompare compare;
    compare.inputValues();
    compare.compareSums();
    return 0;
}
