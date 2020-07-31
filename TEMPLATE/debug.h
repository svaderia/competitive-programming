    // TO_STRING
    string to_string(char c) { return string(1,c); }
    string to_string(const char* s) { return (string)s; }
    string to_string(string s) { return s; }
    string to_string(bool b) {
        #ifdef DEBUG
            return b ? "true" : "false";
        #else
            return to_string((int)b);
        #endif
    }
    template<class A> string to_string(complex<A> c) {
        stringstream ss; ss << c; return ss.str(); }
    string to_string(vector<bool> v) {
        string res = "{"; rep(i,sz(v)) res += char('0'+v[i]);
        res += "}"; return res; }
    template<size_t SZ> string to_string(bitset<SZ> b) {
        string res = ""; rep(i,SZ) res += char('0'+b[i]);
        return res; }
    template<class A, class B> string to_string(pair<A,B> p);
    template<class T> string to_string(T v) { // containers with begin(), end()
        #ifdef DEBUG
            bool fst = 1; string res = "{";
            for (const auto& x: v) {
                if (!fst) res += ", ";
                fst = 0; res += to_string(x);
            }
            res += "}"; return res;
        #else
            bool fst = 1; string res = "";
            for (const auto& x: v) {
                if (!fst) res += " ";
                fst = 0; res += to_string(x);
            }
            return res;

        #endif
    }
    template<class A, class B> string to_string(pair<A,B> p) {
        #ifdef DEBUG
            return "("+to_string(p.f)+", "+to_string(p.s)+")";
        #else
            return to_string(p.f)+" "+to_string(p.s);
        #endif
    }

    // DEBUG
    void DBG() { cerr << "]" << endl; }
    template<class H, class... T> void DBG(H h, T... t) {
        cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
        DBG(t...); }
#ifdef DEBUG // compile with -DDEBUG
    #define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
    #define dbg(...) 0
#endif
