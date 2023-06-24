(1)���巨��ʱ�临�Ӷȣ�O(n * sqrt(n))
int phi(int n) { //�ֽ����������
    int ans = n;
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}
(2)���Է�����ÿ������ŷ��������ʱ�临�Ӷȣ�O(n)
int e[N]; //ÿ������ŷ������
bool st[N]; //�Ƿ�ɸ��
vector<int> prime; //�洢����

void phi(int n) {
    e[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            prime.push_back(i);
            e[i] = i - 1;
        }
        for (int j = 0; prime[j] <= n / i; j++) {
            int t = prime[j] * i;
            st[t] = true;
            if (i % prime[j] == 0) {
                e[t] = e[i] * prime[j];
                break;
            }
            e[t] = e[i] * (prime[j] - 1);
        }
    }
}
