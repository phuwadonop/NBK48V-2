#include<iostream>

using namespace std;
void solve();

int main()
{
    solve();
}
void solve()
{
    int N, Q;
    long coupon = 0,lastEPcoupon=0,loan = 0;

    cin >> N >> Q;

    int p[100000]; long q[100000];

    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
        if (p[i] < 0)
        {
            coupon += p[i];
            if (i > lastEPcoupon)
                lastEPcoupon = i;
        }
    }

    for (int i = 0 ; i < lastEPcoupon; i++)
    {
        if (p[i] > 0)
            loan += p[i];
    }

    for (int i = 0; i < Q; i++)
    {
        cin >> q[i];
        if (loan > (-1*coupon) + q[i])
            q[i] = -1;
    }

    long* qPtr = q;

    int i = 0;
    while (i < Q)
    {
        int totalPrice = coupon;
        int ep;
        for (ep = 0; ; ep++)
        {
            if (qPtr[i] == -1)
                break;

            if (p[ep] > 0)
                totalPrice += p[ep];

            if (totalPrice > qPtr[i])
                break;
        }
        qPtr[i] = ep;
        cout << qPtr[i] << endl;
        i++;
    }
}
