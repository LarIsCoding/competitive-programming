vector<int> nextBigger(vector<int> k) {
    vector<int> next(k.size());
    stack<pair<int, int> > s;

    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && k[i] > s.top().first) {
            next[s.top().second] = i;
            s.pop();
        }

        s.push(make_pair(k[i], i));
    }
}