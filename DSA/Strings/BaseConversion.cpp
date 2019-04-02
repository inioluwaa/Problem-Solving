#include <iostream>
#include <string>

using namespace std;
string ConvertBase(const string &, int, int);
string ConstructFromBase(int, int);
int main() {
    cout << ConvertBase("615", 7, 13);

}

string ConvertBase(const string &NumAsString, int b1, int b2) {
    bool is_negative = NumAsString.front() == '-';
    int NumAsInt = 0;
    for (size_t i = (is_negative ? 1 : 0); i < NumAsString.size(); ++i) {
        NumAsInt *= b1;
        NumAsInt += isdigit(NumAsString[i]) ? NumAsString[i] - '0'
                                            : NumAsString[i] - 'A' + 10;
    }
    return (is_negative ? "-" : "") +
           (NumAsInt == 0 ? "" : ConstructFromBase(NumAsInt, b2));

}

string ConstructFromBase(int NumAsInt, int base) {
    return NumAsInt == 0
           ? ""
           : ConstructFromBase(NumAsInt / base, base) +
             (char)(NumAsInt % base >= 10 ? 'A' + NumAsInt % base - 10
                                          : '0' + NumAsInt % base);

}