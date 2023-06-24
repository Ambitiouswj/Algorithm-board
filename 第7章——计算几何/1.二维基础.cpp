��1����
struct Point {
    double x, y;
    Point() = default;
    Point(double x, double y) : x(x), y(y) {}
};
��2������
using Vector = Point;
�����Ļ�������
// ���� + ���� = �������� + ���� = ����
Vector operator + (Vector a, Vector b) {
    return Vector(a.x + b.x, a.y + b.y);
}
// �� - �� = ����(���� BC = C - B)
Vector operator - (Point A, Point B) {
    return Vector(A.x - B.x, A.y - B.y);
}
// ���� * �� = ����
Vector operator * (Vector a, double p) {
    return Vector(a.x * p, a.y * p);
}
// ���� / �� = ����
Vector operator / (Vector a, double p) {
return Vector(a.x / p, a.y / p);
}
// �� | �����ıȽ�
bool operator < (const Vector& a, const Vector& b) {
return (a.x < b.x || (a.x == b.x && a.y < b.y));
}
// �󼫽ǣ��ڼ�����ϵ�У�ƽ�����κ�һ�㵽��������ߺͼ���ļнǽ������ǡ�
// ��λ���� rad
double polarAngle(Vector A) {
return atan2(A.y, A.x);
}
// ���� == �����
bool operator == (const Point& A, const Point& B) {
    return !sgn(A.x - B.x) && !sgn(A.y - B.y);
}
// ���
double Dot(Vector a, Vector b) {
    return (a.x * b.x + a.y + b.y);
}
// ģ������
double Length(Vector a) {
    return sqrtl(Dot(a, a));
}
// ���������нǣ����ػ���
double Angle(Vector a, Vector b) {
    return acos(Dot(a, b) / Length(a) / Length(b));
}
// ��� | ���ص�����
double Cross(Vector a, Vector b) {
    return (a.x * b.y - a.y * b.x);
}
// �����������ɵ�ƽ���ı������
double Area(Point A, Point B, Point P) {
    return Cross(B - A, P - A);
}
To-Left�ж�
// To-Left���� | ��P�Ƿ������� AB ���
bool toLeft(Point A, Point B, Point P) {
    return (Cross(B - A, P - A) > 0);
}
������ת

// ���� a ��ʱ����ת theta(����) ��
Vector rotate(Vector a, double theta) {
    double xr = a.x * cos(theta) - a.y * sin(theta);
    double yr = a.x * sin(theta) + a.y * cos(theta);
    return Vector(xr, yr);
}
// �� A �� P ��ʱ����ת theta(����) ��
Point rotate(Point A, Point P, double theta) {
    Point V = A - P;
    double c = cos(theta), s = sin(theta);
    return Point(P.x + V.x * c - V.y * s, P.y + V.x * s + V.y * c);
}
// �����ĵ�λ����ʵ���Ͼ��ǽ�������������ת 90 ��
// ��Ϊ�ǵ�λ�������Գ��ȹ�һ������ǰ��ȷ�� a ����������
Vector Normal(const Vector& a) {
    double L = Length(a);
    return Vector(- a.y / L, a.x / L);
}
// ������ת
Vector Format(const Vector& a) {
    double L = Length(a);
    return Vector(a.x / L, a.y / L);
}
��3���߶�
struct Segment {
    Point A, B;
};
���Ƿ����߶���
// �жϵ� P �Ƿ����߶� AB ��
bool isOnTheSeg(Point P, Segment AB) {
    Point A = AB.A, B = AB.B;
    return fabs(Cross(A - P, B - P)) < eps && Dot(A - P, B - P) <= 0;
}
�߶��Ƿ��ཻ
// �ж��߶� AB �� CD �Ƿ��ཻ
bool isIntersect(Segment AB, Segment CD) {
    Point A = AB.A, B = AB.B, C = CD.A, D = CD.B;
    if (fabs(Cross(B - A, D - C)) < eps && (isOnTheSeg(C, AB) || isOnTheSeg(D, AB))) return true;
    if (isOnTheSeg(C, AB) || isOnTheSeg(D, AB)) return true;
    return Cross(B - A, C - A) * Cross(B - A, D - A) <= 0;
}

��4��ֱ��
struct Line {
    Point P;
    Vector v;
    Line(Point P, Vector v) : P(P), v(v){}
};
�㵽ֱ�߾���

// �� A ��ֱ�� (p,v) ���룬��֪ P, v, A
double distOfPointToLine(Line le, Point A) {
    Point P = le.P, v = le.v;
    return fabs(Cross(v, A - P) / Length(v));
}
// �� P ��ֱ�� AB ���룬��֪ P, A, B
double distOfPointToLine(Point A, Point B, Point P) {
    Vector v1 = B - A, v2 = P - A;
    return fabs(Cross(v1, v1) / Length(v1));
}
����ֱ��ͶӰ
// �� A ��ֱ�� (p,v) ��ͶӰ����֪ P, v, A
Point projectionOfPointLine(Line le, Point A) {
    Point P = le.P, v = le.v;
    return P + v * (Dot(v, A - P) / Dot(v, v));
}
// �� P ��ֱ�� AB ��ͶӰ����֪ P, A, B
Point projectionOfPointLine(Point A, Point B, Point P) {
    Vector v = B - A;
    return A + v * (Dot(v, P - A) / Dot(v, v));
}
����ֱ�߽���
Point intersectionOfLines(Line le1, Line le2) {
    Point P1 = le1.P, v1 = le1.v;
    Point P2 = le2.P, v2 = le2.v;
    return P1 + v1 * (Cross(v2, P1 - P2) / Cross(v1, v2));
}
��5�������
struct Polygon {
    vector<Point> points;
    Polygon() = default;
    Polygon(int n, Point points[]) { // ��һ���������
        for (int i = 0; i < n; i++) {
            this->points.push_back({points[i].x, points[i].y});
        }
        this->points.push_back({points[0].x, points[0].y});
    }
};
��������
���ڲ���Ĺ�ʽ���������Σ�
double area(Polygon poly) {
    double s = 0;
    vector<Point>& p = poly.points;
    int n = p.size();
    for (int i = 0; i < n; i++) {
        s += p[i].x * p[i + 1].y - p[(i + 1) % n].x * p[i].y;
    }
    return fabs(s / 2);
}
�жϵ��Ƿ��ڶ�����ڣ����⣩
// ���Ƿ��ڶ������ | �ڲ�����1���ⲿ����-1��������Ϸ���0
int isPointInPoly(Point P, Polygon poly){
    int wn = 0;
    vector<Point>& pnt = poly.points;
    int n = pnt.size();
    for (int i = 0; i < n; i++) {
        if (isOnTheSeg(P, Segment(pnt[i], pnt[(i + 1) % n]))) return 0;
        int k = sgn(Cross(pnt[(i + 1) % n] - pnt[i], P - pnt[i]));
        int d1 = sgn(pnt[i].y - P.y);
        int d2 = sgn(pnt[(i + 1) % n].y - P.y);
        if (k > 0 && d1 <= 0 && d2 > 0) wn++;
        if (k > 0 && d2 <= 0 && d1 > 0) wn--;
    }
    if (wn == 0) return -1;
    return 1;
}
�жϵ��Ƿ��ڶ�����ڣ�͹����Σ�
n��To-Left����
// ���Ƿ���͹������� | �ڲ�����1���ⲿ����-1��������Ϸ���0
int isPointInTuPoly(Point P, Polygon poly) {
    vector<Point>& pnt = poly.points;
    int n = pnt.size();
    for (int i = 0; i < n; i++) {
        Point A = pnt[i], B = pnt[(i + 1) % n];
        if (Cross(B - A, P - A) < 0) return -1;
        if (Cross(B - A, P - A) < eps) return 0;
    }
    return 1;
}
