#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

string names[505][505];
int lineSize[505];
int nameSize[505];

class HashedString {
  private:
	// change M and B if you want
	static const long long M = 1e9 + 9;
	static const long long B = 9973;

	// pow[i] contains B^i % M
	static vector<long long> pow;

	// p_hash[i] is the hash of the first i characters of the given string
	vector<long long> p_hash;

  public:
	HashedString(const string &s) : p_hash(s.size() + 1) {
		while (pow.size() < s.size()) { pow.push_back((pow.back() * B) % M); }

		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
		}
	}

	long long getHash(int start, int end) {
		long long raw_val =
		    (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
		return (raw_val % M + M) % M;
	}
};
vector<long long> HashedString::pow = {1};

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int total;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> names[i][j];
            if(i != j) lineSize[i] += names[i][j].length();
        }
        total += lineSize[i];
    }

    if(n == 2) {
        if(names[0][1].length() != names[1][0].length()) {
            cout << "NONE\n";
            return 0;
        }

        string s1 = names[0][1] + names[0][1];
        string s2 = names[1][0];
        HashedString h1 = HashedString(s1);
        HashedString h2 = HashedString(s2);
        int len1 = s1.length();
        int len2 = s2.length();

        int found = 0;
        int index;
        for(int i = 1; i < len1 - len2; i++) {
            if(h1.getHash(i, i + len2 - 1) == h2.getHash(0, len2 - 1)) {
                found++;
                index = i;
                if(found == 2) break;
            }
        }

        if(found == 0) {
            cout << "NONE\n";
        } else if(found >= 2) {
            cout << "MANY\n";
        } else {
            cout << "UNIQUE\n";

            for(int i = 0; i < index; i++) {
                cout << s1[i];
            }
            cout << "\n";

            for(int i = index; i < len2; i++) {
                cout << s1[i];
            }
            cout << "\n";
        }

        return 0;
    }

    int sumNames = total / (2 * (n - 1));

    for(int i = 0; i < n; i++) {
        nameSize[i] = (lineSize[i] - sumNames) / (n - 2);

        if(nameSize[i] == 0) {
            cout << "NONE\n";
            return 0;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;

            if(nameSize[i] + nameSize[j] != names[i][j].length()) {
                cout << "NONE\n";
                return 0;
            }

            int startI = (i == 0) ? 1 : 0;
            int startJ = (j == 0) ? 1 : 0;

            for(int k = 0; k < nameSize[i]; k++) {
                if(names[i][j][k] != names[i][startI][k]) {
                    cout << "NONE\n";
                    return 0;
                }
            }
            for(int k = 0; k < nameSize[j]; k++) {
                if(names[i][j][nameSize[i] + k] != names[j][startJ][k]) {
                    cout << "NONE\n";
                    return 0;
                }
            }
        }
    }

    cout << "UNIQUE\n";

    for(int i = 0; i < n; i++) {
        int first = (i == 0) ? 1 : 0;
        for(int k = 0; k < nameSize[i]; k++) {
            cout << names[i][first][k];
        }
        cout << "\n";
    }

    return 0;
}