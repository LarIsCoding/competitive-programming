#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

// Time Complexity: O(NLogN)
// Auxiliary Space: O(N)

/*  n --> No. of elements present in input array.
	BITree[0..n] --> Array that represents Binary Indexed Tree.
	arr[0..n-1] --> Input array for which prefix sum is evaluated. */

// Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[].
int getSum(int BITree[], int index) {
	int sum = 0;

	// index in BITree[] is 1 more than the index in arr[]
	index = index + 1;

	// Traverse ancestors of BITree[index]
	while(index > 0) {
		sum += BITree[index];
		index -= index & (-index); // Move index to parent node in getSum View
	}
	return sum;
}

// Updates a node in Binary Index Tree (BITree) at given index
// in BITree. The given value 'val' is added to BITree[i] and
// all of its ancestors in tree.
void updateBIT(int BITree[], int n, int index, int val) {
	// index in BITree[] is 1 more than the index in arr[]
	index = index + 1;

	// Traverse all ancestors and add 'val'
	while(index <= n) {
        BITree[index] += val;
        index += index & (-index); // Update index to that of parent in update View
	}
}

// Constructs and returns a Binary Indexed Tree for given
// array of size n.
int *constructBITree(vector<int> arr, int n) {
	// Create and initialize BITree[] as 0
	int *BITree = new int[n + 1];
	for (int i = 1; i <= n; i++)
		BITree[i] = 0;

	// Store the actual values in BITree[] using update()
	for (int i = 0; i < n; i++)
		updateBIT(BITree, n, i, arr[i]);

	// Uncomment below lines to see contents of BITree[]
	//for (int i=1; i<=n; i++)
	//	 cout << BITree[i] << " ";

	return BITree;
}

class CoordinateCompression {
    private:
    vi space;

    public:
    CoordinateCompression(vi &_v) {
        space = _v;
        sort(space.begin(), space.end());
        space.resize(unique(space.begin(), space.end()) - space.begin());
    }

    int convert(int x) {
        auto it = lower_bound(space.begin(), space.end(), x);
        return it - space.begin();
    }
};

struct Query {
    int type;
    int a;
    int b;
};

vi allNumbers;
vi list;
vector<Query> queries;
vi quantity;
set<int> collection;

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    list.assign(n, 0);

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        allNumbers.push_back(a);
        list[i] = a;
    }

    queries.reserve(q);

    for(int i = 0; i < q; i++) {
        int op;
        cin >> op;

        if(op == 1) {
            int k;
            cin >> k;

            allNumbers.push_back(k);
            Query query;
            query.type = 1;
            query.a = k;
            query.b = -1;
            queries.push_back(query);

        } else {
            int a, b;
            cin >> a >> b;

            allNumbers.push_back(a);
            allNumbers.push_back(b);

            Query query;
            query.type = 2;
            query.a = a;
            query.b = b;

            queries.push_back(query);
        }
    }

    CoordinateCompression cc = CoordinateCompression(allNumbers);

    int size = allNumbers.size();
    quantity.assign(size, 0);

    for(auto it = list.begin(); it != list.end(); it++) {
        quantity[cc.convert(*it)]++;
        collection.insert(*it);
    }

    int* bit = constructBITree(quantity, size);

    for(int i = 0; i < q; i++) {
        Query query = queries[i];
        if(query.type == 1) {
            if(quantity[cc.convert(query.a)]) continue;

            int index = cc.convert(query.a);
            quantity[index]++;
            if(quantity[index] == 1) {
                collection.insert(query.a);
            }
            updateBIT(bit, size, index, 1);

            auto nextNumber = collection.upper_bound(query.a);

            if(nextNumber != collection.end()) {
                int index = cc.convert(*nextNumber);
                quantity[index]--;
                updateBIT(bit, size, index, -1);

                if(quantity[index] == 0) {
                    collection.erase(*nextNumber);
                }
            }

        } else {
            int indexA = cc.convert(query.a);
            int indexB = cc.convert(query.b);
            cout << getSum(bit, indexB) - getSum(bit, indexA - 1) << endl;
        }
    }

    return 0;
}