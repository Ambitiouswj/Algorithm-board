typedef pair<int, int> PII;
vector<PII> nums;
void divide(int x) { //���������ֽ����nums��ǰ���С
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) { //���ﱣ֤iһ������������Ϊ����ѭ��x��ı�
            int s = 0;
            while (x % i == 0) {
                x /= i;
                s++;
            }
            nums.push_back({i, s});
        }
    }
    if (x > 1) nums.push_back({x, 1});
}
