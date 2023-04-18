#include <algorithm>

using namespace std;

typedef struct {
    int id;
    int solved;
    int penalty;
} team;

bool icpc_cmp(team a, team b) {
    if (a.solved != b.solved)
        return a.solved > b.solved;
    else if (a.penalty != b.penalty)
        return a.penalty < b.penalty;
    else
        return a.id < b.id;
}

int main() {

    team nus[4] = {
        { 1, 1, 10},
        {2, 3, 60},
        {3, 1, 20},
        {4, 3, 60}
    };

    sort(nus, nus + 4, icpc_cmp);

    int arr[] = {10, 7, 2, 15, 4};
    sort(arr, arr + 5); 
    next_permutation(arr, arr + 5); // 2, 4, 7, 10, 15 −> 2, 4, 7, 15, 10
    next_permutation(arr, arr + 5); // 2, 4, 7, 15, 10 −> 2, 4, 10, 7, 15

    memset(arr , 0, sizeof(arr));

    return 0;
}