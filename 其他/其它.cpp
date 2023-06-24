1.����ת��
//p����(2~36)תΪʮ���� | ��ĸ�Դ�д��ʾ
int p_to_ten(string s, int p) {
    //s[]Ϊ˳��洢��p�����ַ���
    int x = 0;
    for (int i = 0; i < s.size(); i++) {
        x *= p;
        if (s[i] >= 'A' && s[i] <= 'Z') x += (s[i] - 'A' + 10);
        else x += (s[i] - '0');
    }
    return x;
}

//ʮ����תΪp����
string ten_to_p(int x, int p) {
    string res;
    int tmp = 0;
    do {
        tmp = x % p;
        if (tmp < 10) res.push_back('0' + tmp);
        else res.push_back('A' + tmp - 10);
        x /= p;
    }while(x);
    // ת˳��
    reverse(res.begin(), res.end());
    return res;
}
2.�������ڼ�������������ķ����ɭ��ʽ
��ķ����ɭ��ʽ����õ�wֵ��ʾ��������0��6��������һ�������죩��
w = ( d + 2 * m + 3*(m + 1) / 5 + y + y / 4 - y / 100 + y / 400 ) % 7
3.100���ڵ�����(��25��)
int primes[25] = {
         2,  3,  5,  7, 11,
        13, 17, 19, 23, 29,
        31, 37, 41, 43, 47,
        53, 59, 61, 67, 71,
        73, 79, 83, 89, 97
};
4.1000���ڵ�����(��168��)
int primes[168] = {
          2,   3,   5,   7,  11,  13,  17,  19,
         23,  29,  31,  37,  41,  43,  47,  53,
         59,  61,  67,  71,  73,  79,  83,  89,
         97, 101, 103, 107, 109, 113, 127, 131,
        137, 139, 149, 151, 157, 163, 167, 173,
        179, 181, 191, 193, 197, 199, 211, 223,
        227, 229, 233, 239, 241, 251, 257, 263,
        269, 271, 277, 281, 283, 293, 307, 311,
        313, 317, 331, 337, 347, 349, 353, 359,
        367, 373, 379, 383, 389, 397, 401, 409,
        419, 421, 431, 433, 439, 443, 449, 457,
        461, 463, 467, 479, 487, 491, 499, 503,
        509, 521, 523, 541, 547, 557, 563, 569,
        571, 577, 587, 593, 599, 601, 607, 613,
        617, 619, 631, 641, 643, 647, 653, 659,
        661, 673, 677, 683, 691, 701, 709, 719,
        727, 733, 739, 743, 751, 757, 761, 769,
        773, 787, 797, 809, 811, 821, 823, 827,
        829, 839, 853, 857, 859, 863, 877, 881,
        883, 887, 907, 911, 919, 929, 937, 941,
        947, 953, 967, 971, 977, 983, 991, 997
};
5.ͷ�ļ�
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
cin.tie(0); cout.tie(0);

    return 0;
}
6.����STL
(1) vector<T>, �䳤���飬������˼��
    size()  ����Ԫ�ظ���
    empty()  �����Ƿ�Ϊ��
    clear()  ���
    front()/back()
    push_back()/pop_back()
    begin()/end()
    []
    ֧�ֱȽ����㣬���ֵ���

(2) pair<T,T>
    first, ��һ��Ԫ��
    second, �ڶ���Ԫ��
    ֧�ֱȽ����㣬��firstΪ��һ�ؼ��֣�
	��secondΪ�ڶ��ؼ��֣��ֵ���

(3) string���ַ���
    size()/length()  �����ַ�������
    empty()
    clear()
    substr(��ʼ�±꣬(�Ӵ�����))  �����Ӵ�
    c_str()  �����ַ��������ַ��������ʼ��ַ

(4) queue<T>, ����
    size()
    empty()
    push()  ���β����һ��Ԫ��
    front()  ���ض�ͷԪ��
    back()  ���ض�βԪ��
    pop()  ������ͷԪ��

(5) priority_queue<T>, ���ȶ��У�Ĭ���Ǵ����
    size()
    empty()
    push()  ����һ��Ԫ��
    top()  ���ضѶ�Ԫ��
    pop()  �����Ѷ�Ԫ��
    �����С���ѵķ�ʽ��
		priority_queue<T,vector<T>,greater<T>>

(6) stack<T>, ջ
    size()
    empty()
    push()  ��ջ������һ��Ԫ��
    top()  ����ջ��Ԫ��
    pop()  ����ջ��Ԫ��

(7) deque<T>, ˫�˶���
    size()
    empty()
    clear()
    front()/back()
    push_back()/pop_back()
    push_front()/pop_front()
    begin()/end()
    []

(8) set<T>, map<T,T>, multiset<T>, multimap<T,T>,
  ����ƽ��������������������̬ά����������
    size()
    empty()
    clear()
    begin()/end()
    ++, -- ����ǰ���ͺ�̣�ʱ�临�Ӷ� O(logn)

    set<T>/multiset<T>
        insert()  ����һ����
        find()  ����һ����
        count()  ����ĳһ�����ĸ���
        erase()
            (1) ������һ����x��ɾ������x   O(k + logn)
            (2) ����һ����������ɾ�����������
        lower_bound()/upper_bound()
            lower_bound(x)  ���ش��ڵ���x����С�����ĵ�����
            upper_bound(x)  ���ش���x����С�����ĵ�����
    map<T,T>/multimap<T,T>
        insert()  ���������һ��pair
        erase()  ����Ĳ�����pair���ߵ�����
        find()
        []  ע��multimap��֧�ִ˲����� ʱ�临�Ӷ��� O(logn)
        lower_bound()/upper_bound()

(9) unordered_set<T>, unordered_map<T,T>,
  unordered_multiset<T>, unordered_multimap<T,T>, ��ϣ��
    ���������ƣ���ɾ�Ĳ��ʱ�临�Ӷ��� O(1)
    ��֧�� lower_bound()/upper_bound()�� ��������++��--

(10) bitset, �Rλ
    bitset<10000> s;
    ~, &, |, ^
    >>, <<
    ==, !=
    []

    count()  �����ж��ٸ�1
    any()  �ж��Ƿ�������һ��1
    none()  �ж��Ƿ�ȫΪ0
    set()  ������λ�ó�1
    set(k, v)  ����kλ���v
    reset()  ������λ���0
    flip()  �ȼ���~
    flip(k) �ѵ�kλȡ��
