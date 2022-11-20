#include <iostream>
#include <queue>

using namespace std;

pair<long long int, long long int> calcula_quantidade(priority_queue<long long int> *h, long long int acc) {
    long long int num = h->top();

    while(!h->empty() && h->top() == num) {
        acc++;
        h->pop();
    }

    return make_pair(num, acc);
}

pair<long long int, long long int> calcula_quantidade(priority_queue<long long int, vector<long long int>, greater<long long int> > *h, long long int acc) {
    long long int num = h->top();

    while(!h->empty() && h->top() == num) {
        acc++;
        h->pop();
    }

    return make_pair(num, acc);
}

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long int n;
    cin >> n;

    priority_queue<long long int> heap_max;
    priority_queue<long long int, vector<long long int>, greater<long long int> > heap_min;

    for(long long int i = 0; i < n; i++) {
        long long int p;
        cin >> p;
        heap_max.push(p);
        heap_min.push(p);
    }

    pair<long long int, long long int> max = calcula_quantidade(&heap_max, 0);
    pair<long long int, long long int> min = calcula_quantidade(&heap_min, 0);
    long long int custo = 0;

    while(max.first != min.first) {
        if(max.second < min.second) {
            custo += (max.first - heap_max.top()) * max.second;
            max = calcula_quantidade(&heap_max, max.second);
        } else {
            custo += (heap_min.top() - min.first) * min.second;
            min = calcula_quantidade(&heap_min, min.second);
        }
    }

    cout << custo << endl;

    return 0;
}