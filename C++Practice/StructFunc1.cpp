#include <iostream>
using namespace std;

struct Distance {
    int feet;
    float inches;
};

Distance addengl(Distance, Distance);
void engldisp(Distance);

int main() {
    Distance d1, d2, d3;

    cout << "Enter feet: "; cin >> d1.feet;
    cout << "Enter inches: "; cin >> d1.inches;

    cout << "Enter feet: "; cin >> d2.feet;
    cout << "Enter inches: "; cin >> d2.inches;

    d3 = addengl(d1, d2);

    engldisp(d3);
}

Distance addengl(Distance dd1, Distance dd2) {
    Distance dd3;

    dd3.inches = dd2.inches + dd1.inches;

    dd3.feet = 0;
    while (dd3.inches >= 12.0) {
        dd3.inches -= 12.0;
        dd3.feet++;
    }
    dd3.feet += dd2.feet + dd1.feet;
    return dd3;
}

void engldisp(Distance dd) {
    cout << dd.feet << "\'-" << dd.inches << "\"" << endl;
}


