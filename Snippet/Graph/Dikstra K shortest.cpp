const ll mx = 1e6;
ll n, m, k;
map<pair<ll, ll>, ll> mp;
void dijkstra(ll src, vector<pair<ll, ll>> adj[])
{
    vector<vector<ll>> dist(n + 10, vector<ll>(k, LONG_LONG_MAX));
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});
    while (pq.size() > 0)
    {
        pair<ll, ll> cur = pq.top();
        pq.pop();
        ll u = cur.second;
        ll d = cur.first;

        if (d > dist[u][k - 1])
        {
            continue;
        }
        for (ll i = 0; i < adj[u].size(); i++)
        {
            ll v = adj[u][i].first;
            ll d1 = adj[u][i].second;
            if (d + d1 < dist[v][k - 1])
            {
                dist[v][k - 1] = d + d1;
                pq.push({dist[v][k - 1], v});
                srt(dist[v]);
            }
        }
    }
    for (ll i = 0; i < k; i++)
    {
        cout << dist[n][i] << " ";
    }
    cout << endl;
}
