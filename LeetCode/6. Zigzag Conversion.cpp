class Solution
{
public:
    string convert(string s, int numRows)
    {
        int len = s.length();
        if (numRows == 1)
            return s;

        char m[numRows + 5][len + 5];

        for (int i = 0; i < numRows + 5; i++)
        {
            for (int j = 0; j < (len + 5); j++)
                m[i][j] = '0';
        }

        int j = 0, k = 0;

        while (1)
        {
            if (k >= len)
                break;
            int i;
            for (i = 0; i < numRows; i++)
            {
                m[i][j] = s[k++];
                if (k >= len)
                    break;
            }
            i--;
            if (k >= len)
                break;
            while (1)
            {
                j++;
                i--;
                if (i == 0)
                    break;
                m[i][j] = s[k++];
                if (k >= len)
                    break;
            }
            if (k >= len)
                break;
        }

        string ans;

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < len; j++)
                if (m[i][j] != '0')
                    ans += m[i][j];
        }
        return ans;
    }
};