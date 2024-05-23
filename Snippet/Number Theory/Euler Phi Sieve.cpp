// P1k1 – 1(P1 – 1).P2k2 – 1(P2 – 1)....Prkr - 1(Pr - 1)
void computeTotient(int n)
{
    for (int i = 1; i <= n; i++) phi[i] = i;
    for (int j = 2; j <= n; j++)
    {
        if (phi[j] == j)
        {
            phi[j] = j - 1;
            for (int i = 2 * j; i <= n; i += j)
            {
                phi[i] = (phi[i] / j) * (j - 1);
            }
        }
    }
}
