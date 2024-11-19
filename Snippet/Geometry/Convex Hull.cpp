vector<PT> convex_hull(vector<PT> &p) {
  if (p.size() <= 1) return p;
  vector<PT> v = p;
  sort(v.begin(), v.end());
  vector<PT> up, dn;
  for (auto& p : v) {
      while (up.size() > 1 && orientation(up[up.size() - 2], up.back(), p) >= 0) {
          up.pop_back();
      }
      while (dn.size() > 1 && orientation(dn[dn.size() - 2], dn.back(), p) <= 0) {
          dn.pop_back();
      }
      up.push_back(p);
      dn.push_back(p);
  }
  v = dn;
  if (v.size() > 1) v.pop_back();
  reverse(up.begin(), up.end());
  up.pop_back();
  for (auto& p : up) {
      v.push_back(p);
  }
 if (v.size() == 2 && v[0] == v[1]) v.pop_back();
  return v;
}
bool is_convex(vector<PT> &p) {
  bool s[3]; s[0] = s[1] = s[2] = 0;
  int n = p.size();
  for (int i = 0; i < n; i++) {
      int j = (i + 1) % n;
      int k = (j + 1) % n;
      s[sign(cross(p[j] - p[i], p[k] - p[i])) + 1] = 1;
      if (s[0] && s[2]) return 0;
  }
  return 1;
}
int is_point_in_convex(vector<PT> &p, const PT& x) {
  int n = p.size(); assert(n >= 3);
  int a = orientation(p[0], p[1], x), b = orientation(p[0], p[n - 1], x);
  if (a < 0 || b > 0) return 1;
  int l = 1, r = n - 1;
  while (l + 1 < r) {
      int mid = l + r >> 1;
      if (orientation(p[0], p[mid], x) >= 0) l = mid;
      else r = mid;
  }
  int k = orientation(p[l], p[r], x);
  if (k <= 0) return -k;
  if (l == 1 && a == 0) return 0;
  if (r == n - 1 && b == 0) return 0;
  return -1;
}
