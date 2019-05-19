long RepeatedString(string s, long n) {
    long int count_a = 0;
    long int remainder = n % s.size();
    long int divs = n / s.size();
    if (s[0] == 'a' && s.size() == 1)
        return n;
    for (char i : s) {
        if (i == 'a') {
            ++count_a;
        }
    }
    count_a *= divs;
    for (int i(0); i < remainder; ++i) {
        if (s[i] == 'a')
            ++count_a;
    }
    if (count_a == 0)
        return 0;
    return count_a;
}
