#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

   for(int i=1; i<=t; i++) {
        float perimeter;
        int x1,x2,y1,y2;

        cin >> perimeter >> x1 >> y1 >> x2 >> y2;

        float distance = sqrt(pow(x2-x1,2) + pow(y2-y1,2));

        float radius = perimeter/(2*3.14);

        float theta = 2*asin(distance/(2*radius));

        float angle = theta*180/3.14;

        cout <<"Case #"<<i<<": Possible : "<< fixed << setprecision(4) << 2*angle << endl;

    }
}