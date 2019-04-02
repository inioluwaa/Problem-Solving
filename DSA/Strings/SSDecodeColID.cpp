#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
int SSDecodeColID(const string &);

int main() {
    cout << SSDecodeColID("ZZ");
}

int SSDecodeColID(const string &col) {
    int result = 0;
    for (char c : col) {
        result = result * 26 + c - 'A' + 1;
    }
    return result;
}

string SSDecodeColID2(int x) {

}