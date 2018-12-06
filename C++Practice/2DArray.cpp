#include <iostream>
#include <array>

using namespace std;

const size_t rows{2};
const size_t columns{3};
void printArray(const array<array<int, columns>, rows> &);

int main() {
    array<array<int, columns>, rows> array1{1, 2, 3, 4, 5, 6};
    array<array<int, columns>, rows> array2{1, 2, 3, 4, 5};

    printArray(array1);
    printArray(array2);

}

void printArray(const array<array<int, columns>, rows>& a) {
    for (auto const& row : a) {
        for (auto const& element: row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

void printArray2(const array<array<int, columns>, rows>& array1) {
    for (size_t row{0}; row < array1.size(); ++row) {
        for (size_t column{0}; column < array1[row].size(); ++column) {
            cout << array1[row][column] << ' ';
        }
        cout << endl;
    }
}