#include <bits/stdc++.h>
using namespace std;


struct dt
{
    string name;
    int g;
    int p;
    int t;
    int in;
};

void printA(string title, vector<string> s)
{
    cout<<title;
    int n = s.size()-1;
    for(int i=0;i<=n;i++){
        if(i==n) cout<<" "<<s[i]<<".";
        else cout<<" "<<s[i]<<",";
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    dt data[t];
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cin >> data[i].name;
        data[i].in =i;

        data[i].p = data[i].t = data[i].g = 0;

        while (n--)
        {
            string s;
            cin >> s;
            if (s[0] == s[1] && s[3] == s[1] && s[3] == s[4] && s[6] == s[1] && s[7] == s[1])
            {
                data[i].t++;
                continue;
            }
            char ch = s[0];
            int cnt = 0;
            for (int j = 1; j < 8; j++)
            {
                if (s[j] == '-')
                    continue;
                if (ch > s[j])
                {
                    cnt++;
                    ch = s[j];
                }
            }
            if (cnt == 5)
            {
                data[i].p++;
                continue;
            }

            data[i].g++;
        }
    }

    vector<string> v;
    int n;

 
     sort(data, data + t, [](dt x, dt y){ 
           if(x.t == y.t){
            return x.in <= y.in; 
           }else return x.t > y.t;
    });

    for (int i = 0; i < t; i++)
    {
        if (data[0].t == data[i].t)
            v.push_back(data[i].name);
    }
    printA("If you want to call a taxi, you should call:", v);
    v.clear();





    sort(data, data + t, [](dt x, dt y){ 
           if(x.p == y.p){
            return x.in <= y.in; 
           }else return x.p > y.p;
    });

    for (int i = 0; i < t; i++)
    {
        if (data[0].p == data[i].p)
            v.push_back(data[i].name);
    }
    printA("If you want to order a pizza, you should call:", v);
    v.clear();



    sort(data, data + t, [](dt x, dt y){ 
           if(x.g == y.g){
            return x.in <= y.in; 
           }else return x.g > y.g;
    });

    for (int i = 0; i < t; i++)
    {
        if (data[0].g == data[i].g)
            v.push_back(data[i].name);
    }
    printA("If you want to go to a cafe with a wonderful girl, you should call:", v);
}