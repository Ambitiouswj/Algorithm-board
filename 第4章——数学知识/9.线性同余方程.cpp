��չŷ������㷨

//��x,y��ʹ��ax+by==gcd(a,b)
int exgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

//������ͬ�෽�̣�ʹ��(ax-b)%m==0����ax+my=b
int d = exgcd(a, mod, x, y);
if (b % d != 0) //�޽�
else (b/d)*x%mod Ϊx��һ����

