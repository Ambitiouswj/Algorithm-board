//���򲻵�ʽ
//�ŶӴ�ˮ

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100010;
LL n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    LL sum = 0,ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        sum += a[i];
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}

//�ù�ʽ
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100010;
LL n, a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    LL ans = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        ans += a[i] * (n - i);
    }
    cout << ans << endl;
    return 0;
}

