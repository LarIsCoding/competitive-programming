#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long int ll;

#define mp(i, j) make_pair(i, j)
#define f first
#define s second

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;
const ll linf = (ll)1e17;

#define FOR(i, b) for(int i = 0; i < (b); i++)
using ld = double;
#define EPS 1e-9

const ld PI = atan2(0, -1.0L);

template< class T>
int sign(T val){
  return abs(val) < EPS ? 0 : (val > EPS ? 1 : -1);
}

template <class F>
struct Point {
  F x, y;
  Point() : x(0), y(0) {}
  Point(const F& x, const F& y) : x(x), y(y) {}

  operator Point<ld> (){return Point<ld>((ld)x, (ld)y);}

  Point<F> operator + (const Point<F>& ot) const{ return Point(x + ot.x, y + ot.y);}
  Point<F> operator - (const Point<F>& ot) const{ return Point(x - ot.x, y - ot.y);}
  template <class G> Point<G> operator * (const G& factor) const{ return Point<G>(x * factor, y * factor);}
  Point<ld> operator / (const ld& factor) const{ return Point<ld>(x / factor, y / factor);}
  bool operator == (const Point<F>& ot) const {return x == ot.x && y == ot.y; }
  bool operator != (const Point<F>& ot) const {return !(*this == ot); }
  bool operator < (const Point<F>& ot) const {return y < ot.y || (y == ot.y && x < ot.x); }
  bool operator > (const Point<F>& ot) const {return ot < *this; }

  // a * b = |a||b| cos c 
  F operator * (const Point<F>& ot) const { return x * ot.x + y * ot.y; }
  // a ^ b = |a||b| sin c 
  F operator ^ (const Point<F>& ot) const { return x * ot.y - y * ot.x; }

  // distances
  friend F abs(Point<F> v) { return v * v; }
  friend ld norm(Point<F> v) { return sqrt((ld)abs(v)); }
  friend ld dist(Point<F> lhs, Point<F> rhs) { return norm(lhs - rhs); }
  friend F dist2(Point<F> lhs, Point<F> rhs) {  return abs(lhs - rhs); }
  
  // < 0 if rhs <- lhs counter-clockwise, 0 if collinear, > 0 if clockwise.
  friend F ccw(const Point<F>& lhs, const Point<F>& rhs) { return rhs ^ lhs;}
  friend F ccw(const Point<F>& lhs, const Point<F>& rhs, const Point<F>& origin){
    return ccw(lhs - origin, rhs - origin);
  }

  // range [-pi, pi] - atan2(y, x) = arc tan (y / x)
  friend ld angle (Point<F> v) { return atan2(v.y, v.x); }

  friend ld angle (Point<F> lhs, Point<F> rhs) { return atan2(lhs ^ rhs, lhs * rhs); }

  friend Point<ld> bisector(Point<F> lhs, Point<F> rhs) { return lhs * norm(rhs) + rhs * norm(lhs); }

  friend Point<ld> transPoint(Point<F> p, Point<F> v, ld val){
    return v * (val / norm(v)) + p;
  }
};


template <class F>
struct Line {
  Point<F> a, ab;
  Line() : a(), ab() {}
  Line(const Point<F>& a, const Point<F>& b, bool twoPoints = true)
    : a(a), ab(twoPoints ? b - a : b) {}

  // Create line in parametric form using cartasian form coefficients
  Line(F A, F B, F C): a(B == 0 ? -C / A : 0, B == 0 ? 0 : -C / B), ab(-B, A){
    assert(typeid(A) == typeid(ld));
  }

  // Used to represent a line segment
  Point<F> b() const { return a + ab; }

  // transform from parametric form a + ab * t to cartesian form Ax + By + C = 0
  tuple<F, F, F> cartesianForm(){
    F A = ab.y, B = -ab.x, C = ab.x * a.y - ab.y * a.x;
    return tuple<F, F, F> (A, B, C);
  }

  // Use only if all coefficients are integers
  friend bool onLine(Line<F> line, Point<F> point) {
    return ((point - line.a) ^ line.ab) == 0;
  }

  friend ld distLine(Line<F> line, Point<F> point) {
    return abs(Point<ld>(point - line.a) ^ (line.ab/2)) / norm(line.ab/2);
  }
  
  // A ray is infinite only ab direction
  friend ld distRay(Line<F> ray, Point<F> point) {
    if (((point - ray.a) * ray.ab) <= 0) return dist(point, ray.a);
    return distLine(ray, point);
  }

  friend ld distSegment(Line<F> seg, Point<F> point) {
    if (((point - seg.a) * seg.ab) <= 0) return dist(point, seg.a);
    if (((point - seg.b()) * seg.ab) >= 0) return dist(point, seg.b());
    return distLine(seg, point);
  }

  friend bool intersectLines(Line<F> lhs, Line<F> rhs, Point<ld>& res) {
    // lhs = A + i * AB, rhs = C + j * CD
    F s = lhs.ab ^ rhs.ab; // AB ^ CD
    F ls = (rhs.a - lhs.a) ^ rhs.ab; // (C - A) ^ CD
    if (s == 0) // direction vectors are parallel
      return ls == 0 ? res = lhs.a, true : false;
    auto rs = (rhs.a - lhs.a) ^ lhs.ab;
    if (s < 0) s = -s, ls = -ls, rs = -rs;
    res = Point<ld>(lhs.a) + lhs.ab * ls / s;
    return true;
  }

   // Intersection of non-parallel lines, rays and segments
  friend bool intersectRays(Line<F> lhs, Line<F> rhs, Point<ld>& res) {
    // lhs = A + i * AB, rhs = C + j * CD
    F s = lhs.ab ^ rhs.ab; // AB ^ CD
    F ls = (rhs.a - lhs.a) ^ rhs.ab; // (C - A) ^ CD
    if (s == 0) // Ignore the parallel case
      return false;
    auto rs = (rhs.a - lhs.a) ^ lhs.ab;
    if (s < 0) s = -s, ls = -ls, rs = -rs;
    // 0 <= ls/rs -> closed endpoint in lhs.a/rhs.a 
    // ls/rs <= s -> closed endpoint in lhs.b/rhs.b
    // For open segment use inequality. For no endpoint remove them
    bool intersect = 0 <= ls && 0 <= rs; // 0 <= ls && ls <= s && 0 <= rs && rs <= s;
    if (intersect)
      res = Point<ld>(lhs.a) + lhs.ab * ls / s;
    return intersect;
  }

  // closed endpoints
  friend bool intersectSegments(Line<F> lhs, Line<F> rhs, Line<ld>& res) {
    // lhs = A + i * AB, rhs = C + j * CD
    F s = lhs.ab ^ rhs.ab; // AB ^ CD
    F ls = (rhs.a - lhs.a) ^ rhs.ab; // (C - A) ^ CD
    if (s == 0) { // direction vectors are parallel
      if (ls != 0) return false; // There is no common point
      Point<ld> lhsa = lhs.a, lhsb = lhs.b();
      Point<ld> rhsa = rhs.a, rhsb = rhs.b();
      if (lhsa > lhsb) swap(lhsa, lhsb);
      if (rhsa > rhsb) swap(rhsa, rhsb);
      res = Line<ld>(max(lhsa, rhsa), min(lhsb, rhsb)); // intersection segment
      return !(Point<ld>() < res.ab); // res.ab >= (0, 0)
    }
    auto rs = (rhs.a - lhs.a) ^ lhs.ab;
    if (s < 0) s = -s, ls = -ls, rs = -rs;
    // check if 0 <= i, j <= 1
    bool intersect = 0 <= ls && ls <= s && 0 <= rs && rs <= s;
    if (intersect) // res.a is intersection point
      res = Line<ld>(Point<ld>(lhs.a) + lhs.ab * ls / s, Point<ld>());
    return intersect;
  }

  friend ld distBetweenSegments(Line<F> segA, Line<F> segB) {
    Line<ld> tmp;
    if(intersectSegments(segA, segB, tmp))
      return 0;
    ld ret = min(distSegment(segA, segB.a), distSegment(segA, segB.b()));
    swap(segA, segB);
    return min({ret, distSegment(segA, segB.a), distSegment(segA, segB.b())});
  }

  friend ld distBetweenRays(Line<F> segA, Line<F> segB) {
    Point<ld> tmp;
    if(intersectRays(segA, segB, tmp))
      return 0;
    return min(distRay(segA, segB.a), distRay(segB, segA.a));
  }

  // translation the line in the normal direction by R units
  friend Line<ld> transLine(Line<F> line, ld R){
    Point<ld> normal(-line.ab.y, line.ab.x);
    return Line<ld>(transPoint(line.a, normal, R), line.ab, false);
  }

  friend bool isInTheSameSide(Line<F> line, Point<F> A, Point<F> B){
    return sign(ccw(line.b(), A, line.a)) == sign(ccw(line.b(), B, line.a));
  }  
};

struct Circle {
    Point<ld> center;
    int r;

    Circle(int x, int y, int r) : center({x,y}), r(r) {}
};

struct Square {
    int x1,y1,x2,y2;

    //Line side1, side2, side3, side4;

    Square(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {
    }
};

struct Triangle {
    Point<ld> p1,p2,p3;

    Line<ld> side1,side2,side3;

    Triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
        p1={x1,y1};
        p2={x2,y2};
        p3={x3,y3};
        side1 = {p1,p2};
        side2 = {p2,p3};
        side3 = {p1,p3};
    }
};

vector<Circle> vc;
vector<Square> vs;
vector<Triangle> vt;

double distCircleCircle(Circle c1, Circle c2) {
    return dist(c1.center, c2.center) - c1.r - c2.r;
}

double distSquareCircle(Square s, Circle c) {

}

double distTriangleCircle(Triangle t, Circle c) {
    double d1=distSegment(t.side1,c.center);
    double d2=distSegment(t.side2,c.center);
    double d3=distSegment(t.side3,c.center);
    return min(d1,min(d2,d3)) - c.r;
}

double distSquareTriangle(Square s, Triangle t) {

}

vector<pair<int,double> > adj[(int)1e6+10];

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c,q,t;
    cin >> c >> q >>t;

    for(int i=0;i<c;i++) {
        int x,y,r;
        cin>>x>>y>>r;
        vc.push_back((Circle){x,y,r});
    }

    for(int i=0;i<q;i++) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        vs.push_back((Square){x1,y1,x2,y2});
    }

    for(int i=0;i<t;i++) {
        int x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        vt.push_back((Triangle){x1,y1,x2,y2,x3,y3});
    }

    for(int i=0;i<c;i++) {
        for(int j=i+1;j<c;j++) {
            double dist=distCircleCircle(vc[i],vc[j]);
            adj[i].push_back({j,dist});
            adj[j].push_back({i,dist});
        }
    }

    for(int i=0;i<c;i++) {
        for(int j=0;j<q;j++) {
            double dist=distSquareCircle(vs[j],vc[i]);
            adj[c+j].push_back({i,dist});
            adj[i].push_back({c+j,dist});
        }
    }

    for(int i=0;i<c;i++) {
        for(int j=0;j<t;j++) {
            double dist=distTriangleCircle(vt[j],vc[i]);
            adj[c+q+j].push_back({i,dist});
            adj[i].push_back({c+q+j,dist});
        }
    }

    for(int i=0;i<q;i++) {
        for(int j=0;j<t;j++) {
            double dist=distSquareTriangle(vs[i],vt[j]);
            adj[c+i].push_back({c+q+j,dist});
            adj[c+q+j].push_back({c+i,dist});
        }
    }

    for(int i=0;i<q;i++) {
        adj[c+q+t].push_back({c+i,0});
        adj[c+i].push_back({c+q+t,0});
    }

    for(int i=0;i<t;i++) {
        adj[c+q+t+1].push_back({c+q+i,0});
        adj[c+q+i].push_back({c+q+t+1,0});
    }

    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;
    pq.push({0,c+q+t});

    bool visited[c+q+t+2];
    memset(visited,false, sizeof visited);

    while(pq.top().second!=c+q+t+1) {
        visited[pq.top().s]=true;
        for(auto it:adj[pq.top().second]) {
            if(visited[it.first]) continue;
            pq.push({pq.top().f+it.s,it.f});
        }
    }

    cout<<setprecision(6)<<fixed<<pq.top().f<<endl;

    return 0;
}