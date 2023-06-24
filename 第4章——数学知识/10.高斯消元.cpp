��˹��Ԫ�����Է�����
ö��ÿһ��
1 �ҵ�����Ԫ�ؾ���ֵ������
2 �����л���������
3 ������Ԫ�ر�Ϊ1

const int N = 110, INF = 0x3f3f3f3f;
const double eps = 1e-7;
int n;
double a[N][N]; //�������

int gauss() {
    int c, r; //�к���
    for (c = 0, r = 0; c < n; c++) {
        //�ҵ�����Ԫ�ؾ���ֵ������
        int t = r;
        for (int i = r; i < n; i++) {
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
        }
        //����������Ԫ��Ϊ0��ֱ����һ��
        if (fabs(a[t][c]) < eps) continue;
        //�����л���������
        for (int i = c; i <= n; i++)
            swap(a[t][i], a[r][i]);

        //��ǰ��ϵ����Ϊ1
        for (int i = n; i >= c; i--)
            a[r][i] /= a[r][c];

        //���·�Ԫ�ػ�Ϊ0
        for (int i = r + 1; i < n; i++) {
            if (fabs(a[i][c]) > eps) {
                for (int j = n; j >= c; j--) {
                    a[i][j] -= a[r][j] * a[i][c];
                }
            }
        }
        r++;
    }
    if (r < n) { //��0�е�����С��n��������������С��n
        for (int i = r; i < n; i++) {
            if (fabs(a[i][n]) > eps) return 0; //�޽�
        }
        return INF; //������
    }
    //��Ψһ�����a[0 ~ n-1][n]��
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            a[i][n] -= a[i][j] * a[j][n];
        }
    }
    return 1; //��Ψһ��
}

