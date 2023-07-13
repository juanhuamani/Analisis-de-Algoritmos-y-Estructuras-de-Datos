#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct INTERVALO
{
    int bajo, alto;
    bool operator < (const INTERVALO &a)
    {
        return bajo < a.bajo;
    }
} r[100000];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int M, a, b, n = 0;
        scanf("%d", &M);
        while (scanf("%d%d", &a, &b), !(a == 0 && b == 0))
            r[n++] = {a, b};
        sort(r, &r[n]);
        int m = -1, res = 0, k = 0;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (r[i].bajo <= k)
                if (r[i].alto > r[m].alto)
                    m = i;
            if ((r[i].bajo > k) && r[m].alto > k)
            {
                k = r[m].alto, res++;
                q.push(m);
                i--;
                if (k >= M)
                    break;
            }
        }
        if (k < M && r[M].alto >= M)
        {
            k = r[m].alto, res++;
            q.push(m);
        }
        if (k < M)
            printf("0\n");
        else
        {
            printf("%d\n", res);
            while (!q.empty())
            {
                int t = q.front();
                q.pop();
                printf("%d %d\n", r[t].bajo, r[t].alto);
            }
        }
        if (T)
            printf("\n");
    }
    return 0;
}