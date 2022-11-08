int N = 1e7;
vector<bool> is_prime(N+1, true);
void calculate()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
}