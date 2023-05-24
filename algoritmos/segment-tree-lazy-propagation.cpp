#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

// Sum
class SegmentTree {

    private:
    vi tree, A, lazy; // st -> indice do menor valor; A -> vetor com valores
    int n;

    void build(int node, int start, int end) {
        if(start == end) {
            tree[node] = A[start];
            return;
        }

        int mid = (start + end) / 2;

        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void updateNode(int node, int start, int end) {
        // If this node needs to be updated
        if(lazy[node] != 0) {

            tree[node] += (end - start + 1) * lazy[node];    // Update it

            if(start != end) {
                lazy[node * 2] += lazy[node];                // Mark child as lazy
                lazy[node * 2 + 1] += lazy[node];            // Mark child as lazy
            }

            lazy[node] = 0;                                  // Reset it
        }
    }

    void updateRange(int node, int start, int end, int l, int r, int val) {

        updateNode(node, start, end);

        // Current segment is not within range [l, r]
        if(start > end or start > r or end < l) return;

        // Segment is fully within range
        if(start >= l and end <= r) {

            tree[node] += (end - start + 1) * val;

            // Not leaf node
            if(start != end) {
                lazy[node * 2] += val;
                lazy[node * 2 + 1] += val;
            }
            return;
        }

        int mid = (start + end) / 2;

        updateRange(node * 2, start, mid, l, r, val);         // Updating left child
        updateRange(node * 2 + 1, mid + 1, end, l, r, val);   // Updating right child

        tree[node] = tree[node * 2] + tree[node * 2 + 1];     // Updating root with max value 
    }


    int queryRange(int node, int start, int end, int l, int r) {

        // Out of range
        if(start > end or start > r or end < l) return 0;

        updateNode(node, start, end);

        // Current segment is totally within range [l, r]
        if(start >= l and end <= r)
            return tree[node];

        int mid = (start + end) / 2;

        int p1 = queryRange(node * 2, start, mid, l, r);         // Query left child
        int p2 = queryRange(node * 2 + 1, mid + 1, end, l, r);   // Query right child

        return (p1 + p2);
    }

    public:
    SegmentTree(const vi &_A) {
        A = _A;
        n = (int)A.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    void updateRange(int i, int j, int v) {
        updateRange(1, 0, n - 1, i, j, v);
    }

    int queryRange(int i, int j) {
        return queryRange(1, 0, n - 1, i, j);
    }
};

int main() {
    int arr[] = {18, 17, 13, 19, 15, 11, 20};
    vi A(arr, arr + 7);
    SegmentTree st(A);
    cout << st.queryRange(0, 6) << endl; // printa 5
}
