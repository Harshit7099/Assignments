#include <iostream>
using namespace std;
class DynamicArray {
private:
    int *arr;
    int size;
    int capacity;
public:
    DynamicArray(int initialCapacity) {
        size = 0;
        capacity = initialCapacity;
        arr = new int[capacity];
    }
    ~DynamicArray() {
        delete[] arr;
    }
    void add(int element) {
        if (size == capacity) {
            int *tempArr = new int[2 * capacity];
            for (int i = 0; i < size; ++i) {
                tempArr[i] = arr[i];
            }
            delete[] arr;
            arr = tempArr;
            capacity *= 2;
        }
        arr[size++] = element;
    }
    int getSize() {
        return size;
    }
    int get(int index) {
        if (index >= 0 && index < size)
            return arr[index];
        else {
            cout << "Error: Index out of bounds!" <<endl;
            return -1;
        }
    }
};
int main() {
    DynamicArray dynArray(5);
    for (int i = 0; i < 10; ++i) {
        dynArray.add(i);
    }
    cout << "Dynamic Array: ";
    for (int i = 0; i < dynArray.getSize(); ++i) {
        cout << dynArray.get(i) << " ";
    }
    cout<<endl;
    return 0;
}
