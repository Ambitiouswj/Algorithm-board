(1)Լ������

unordered_map<int, int> prime;
//�ֽ�������
void divide(int x) {
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
                prime[i]++;
            }
        }
    }
    if (x > 1) prime[x]++;
}
//��Լ������
int num() {
    int ans = 1;
    for (auto it: prime) {
        int c = it.second;
        ans = ans * (c + 1); //��ʱ��Ҫȡģ
    }
    return ans;
}
(2)Լ��֮��
int sum() {
    int ans = 1;
    for (auto it: prime) {
        int sum = 1;
        int p = it.first, c = it.second;
        for (int i = 1; i <= c; i++) sum = sum * p + 1; //��ʱ��Ҫȡģ
        ans = ans * sum; //��ʱ��Ҫȡģ
    }
    return ans;
}
