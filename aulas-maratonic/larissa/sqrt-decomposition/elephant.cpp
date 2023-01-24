#include <bits/stdc++.h>

using namespace std;

vector<int> numeros;
map<int, int> vezes;
int resposta;

void remove(int idx) {
    int num = numeros[idx];
    if(vezes[num] == num) {
        resposta--;
    }
    vezes[numeros[idx]]--;
    if(vezes[num] == num) {
        resposta++;
    }
}

void add(int idx) {
    int num = numeros[idx];
    if(vezes[num] == num) {
        resposta--;
    }
    vezes[numeros[idx]]++;
    if(vezes[num] == num) {
        resposta++;
    }
}

int get_answer() {
    return resposta;
}

int block_size;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int aux;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        numeros.push_back(aux);
    }

    vector<Query> queries(m);
    int l, r;
    for(int i = 0; i < n; i++) {
        cin >> l >> r;
        Query query;
        query.l = l; query.r = r; query.idx = i;
        queries[i] = query;
    }

    mo_s_algorithm(queries);

    return 0;
}
