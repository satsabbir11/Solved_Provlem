void dfs_euler(int src, int par)
{
    euler_path.push_back(src);
    int f = 0;
    for (auto i : graph[src])
    {
        if (i == par)
            continue;
        f = 1;
        dfs_euler(i, src);
    }
    if (f)
        euler_path.push_back(src);
}

void init_euler_path()
{
    dfs_euler(1, 0);
    int idx = 1;
    for (auto i : euler_path)
    {
        if (st[i] == 0)
            st[i] = idx;
        en[i] = idx;
        idx++;
    }
}