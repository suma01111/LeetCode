class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long val;
        long long sum;
        int len;

        Node(long long v = 0, long long s = 0, int l = 0) {
            val = v;
            sum = s;
            len = l;
        }
    };

    vector<Node> seg;
    vector<long long> pow10;

    Node merge(Node &left, Node &right) {

        Node res;

        res.len = left.len + right.len;
        res.sum = left.sum + right.sum;
        res.val = (left.val * pow10[right.len] + right.val) % MOD;

        return res;
    }

    void build(int idx, int l, int r, string &s) {

        if (l == r) {

            if (s[l] == '0')
                seg[idx] = Node(0, 0, 0);

            else {
                int d = s[l] - '0';
                seg[idx] = Node(d, d, 1);
            }

            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid, s);
        build(2 * idx + 1, mid + 1, r, s);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {

        if (qr < l || r < ql)
            return Node();

        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        Node left = query(2 * idx, l, mid, ql, qr);
        Node right = query(2 * idx + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        seg.assign(4 * n, Node());

        pow10.resize(n + 1);
        pow10[0] = 1;

        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (auto &q : queries) {

            Node cur = query(1, 0, n - 1, q[0], q[1]);

            ans.push_back((cur.val * cur.sum) % MOD);
        }

        return ans;
    }
};