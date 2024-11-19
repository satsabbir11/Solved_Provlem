#include <bits/stdc++.h>
using namespace std;

#define loj(i,j) "Case "<<i<<": "<<j

int main(){
    int t; 
    cin >> t;
    int i = 1;
    while (t--) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];

        sort(a, a + 3);

        bool f = false;

     
        if ((a[2] == 6 && a[1] == 3 && a[0] == 0) || 
            (a[2] == 6 && a[1] == 1 && a[0] == 1) || 
            (a[2] == 4 && a[1] == 4 && a[0] == 1) || 
            (a[2] == 4 && a[1] == 2 && a[0] == 2) || 
            (a[2] == 3 && a[1] == 3 && a[0] == 3) ||
            (a[2] == 2 && a[1] == 2 && a[0] == 2)) {
            f = true;
        }

        if (f) 
            cout << loj(i, "perfectus") << endl;
        else 
            cout << loj(i, "invalidum") << endl;

        i++;
    }
}
