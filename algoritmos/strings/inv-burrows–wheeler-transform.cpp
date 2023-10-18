#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        char Data;
        Node* Next;
 
        Node(char data) {
            Data = data;
            Next = NULL;
        }
};
 
class InvertBWT {
public:
    static void invert(string bwtArr) {
        int lenBwt = bwtArr.length();
        string sortedBwt = bwtArr;
        sort(sortedBwt.begin(), sortedBwt.end());
        int* lShift = new int[lenBwt];
 
        // Index at which original string appears
        // in the sorted rotations list
        int x = 4;
 
        // Array of lists to compute l_shift
        queue<int>* arr = new queue<int>[128];
 
        // Adds each character of bwtArr to a linked list
        // and appends to it the new node whose data part
        // contains index at which character occurs in bwtArr
        for (int i = 0; i < lenBwt; i++) {
            arr[bwtArr[i]].push(i);
        }
 
        // Adds each character of sortedBwt to a linked list
        // and finds lShift
        for (int i = 0; i < lenBwt; i++) {
            lShift[i] = arr[sortedBwt[i]].front();
            arr[sortedBwt[i]].pop();
        }
 
        // Decodes the bwt
        char* decoded = new char[lenBwt];
        for (int i = 0; i < lenBwt; i++) {
            x = lShift[x];
            decoded[lenBwt-1-i] = bwtArr[x];
        }
        string decodedStr(decoded, lenBwt);
        string reversedDecodedStr = string(decodedStr.rbegin(), decodedStr.rend());
 
        int ini=0;
        for(int i=0; i<lenBwt; i++) {
            if(reversedDecodedStr[i]=='#') {
                ini=i+1;
                break;
            }
        }

        for(int i=0;i<lenBwt-1; i++) {
            cout<<reversedDecodedStr[(ini+i)%lenBwt];
        }
        cout<<endl;
    }
};

int main() {
    // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);

    string st;
    cin >> st;

    InvertBWT::invert(st);

    return 0;
}
