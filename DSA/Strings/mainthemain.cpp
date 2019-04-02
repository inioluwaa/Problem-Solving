#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1{"cat"};
    string s2;
    string s3;

    s2.assign(s1);
    s3 = s1;

    cout << s1 << " " << s2 << " " << s3 << endl;
    s2[0] = s3[2] = 'r';
    cout << s1 << " " << s2 << " " << s3 << endl;

    for (size_t i{0}; i < s3.size(); ++i) {
        cout << s3.at(i);
    }
    cout << endl;

    string s4{s1 + "apult"};
    string s5;
    cout << s4 << endl;

    s3 += "pet";
    cout << s3 << endl;
    s1.append("acomb");
    cout << s1 << endl;

    s5.append(s1, 4, s1.size() - 4);

    cout << s5 << endl;
}



#include <iostream>
#include <string>
using namespace std;

int main() {
    string string1{"Testing the comparison functions"};
    string string2{"Hello"};
    string string3{"stinger"};
    string string4{string2};
    cout << string1 << endl;
    cout << string2 << endl;
    cout << string3 << endl;
    cout << string4 << endl;

    if (string2 < string3) {
        cout << "string 2 < string 3" << endl;
    }

    int result{string1.compare(string2)};
    if (result == 0) cout << "= 0";
    else if (result > 0) cout << "> 0";
    else cout << "< 0";

    result = string1.compare(2, 5, string3, 0, 5);
}