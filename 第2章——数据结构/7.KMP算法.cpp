int ne[], n, m;
char p[], s[];
// p[]: ģ�崮��s[]: ��ƥ����ַ���
// ne[]: next���飬n: ģ�崮���ȣ�m: ��ƥ��Ĵ�����
// �ַ������±�1��ʼ��
// ����next����: ʹ��ne[i] = j��p[1] ~ p[j]��p[i - j + 1] ~ p[i]���
for (int i = 2, j = 0; i <= n; i++) {
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) j++;
    ne[i] = j;
}

// �ȶ�
for (int i = 1, j = 0; i <= m; i++) {
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j++;
    if (j == n) {
        j = ne[j];
        ......
        // ƥ��ɹ���Ĵ���
    }
}
