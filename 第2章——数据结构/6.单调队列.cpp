// ����һ����СΪ1e6�����顣��һ����СΪ�Ļ������ڣ����������������ƶ������ұߡ�
// ��ֻ���ڴ����п��������֡�ÿ�λ������������ƶ�һ��λ�á�
// ��ȷ����������λ��ÿ��λ��ʱ�����ڵ����ֵ��
#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;
int a[N], que[N], hh, tt;
int n, k;

int main() {
    scanf("%d%d" ,&n, &k);
    hh = 0, tt = -1;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        while (hh <= tt && i- k + 1 > que[hh]) hh++;
        while (hh <= tt && a[que[tt]] >= a[i]) tt--;
        que[++tt] = i;
        if (i >= k - 1) printf("%d ", a[que[hh]]);
    }
    printf("\n");
    return 0;
}
