// Boyer-Moore Voting Algorithm.

int MajorityElement(const vector<int> &A) {
    int n = A.size();
    int Maxi = 0, count = 1;
    for (int num : A) {
        if (count == 0) Maxi = num;
        count += (num == Maxi) ? 1 : -1;
    }
    if (count <= 0) return 0;
    else return 1;
}