vector<int> divs;
void divisor(int n) {
    for (int i = 1; i <= n / i; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i != n / i) divs.push_back(n / i);
        }
    }
    // ��С���󷵻�
    sort(divs.begin(), divs.end());
}
