// DCP 74
int NumberOfTimes(int N, int X) {
    int count = 0;
    for (int i(1); i <= N; ++i) {
        if (X % i == 0 && (X / i) <= N) {
            count++;
        }
    }
    return count;
}