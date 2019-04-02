#include <iostream>
#include <string>

using namespace std;
int main() {

}

int ReplaceAndRemove(char s[], int TrueSize) {
    int write_idx = 0, a_count = 0;
    for (int i{0}; i < TrueSize; ++i) {
        if (s[i] == 'b') {
            s[write_idx] = s[i];
            write_idx++;
        }
        if(s[i] == 'a') {
            ++a_count;
        }
    }

    cout << "write index is " << write_idx << endl;
    cout << "a count is " << write_idx << endl;

    int cur_idx = write_idx - 1;
    write_idx = write_idx + a_count - 1;
    int final_size = write_idx + 1;

    while (cur_idx >= 0) {
        if (s[cur_idx == 'a']) {
            s[write_idx--] = 'd';
            s[write_idx--] = 'd';
        }
        else {
            s[write_idx--] = s[cur_idx];
        }
        cur_idx--;
    }
    return final_size;
}