class Solution {
public:
  vector<string> subdomainVisits(vector<string> &cpdomains) {
    map<string, int> m;

    vector<string> res;

    for (auto e : cpdomains) {
      stringstream ss(e);

      string dom, t;
      int ct;
      ss >> ct >> dom;

      vector<string> v;
      for (int i = dom.size(); i >= 0; i--) {
        if (dom[i] == '.') {
          v.push_back(dom.substr(i + 1, dom.size() - i - 1));
        }
      }
      v.push_back(dom);

      for (auto e : v) {
        m[e] += ct;
      }
    }

    for (auto e : m) {
      res.push_back(to_string(e.second) + ' ' + e.first);
    }

    return res;
  }
};
