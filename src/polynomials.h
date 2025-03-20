#include <bits/algorithmfwd.h>

class Polynomial
{
private:
    double *c;
    int N;

public:
    Polynomial(double *c, int N) : c(c), N(N) {}

    Polynomial operator+(const Polynomial& obj)
    {
        int M = std::max(N, obj.N);
        double *new_c = new double[M];
        for (int i = 0; i < M; i++)
        {
            new_c[i] = (i < N ? c[i] : 0) + (i < obj.N ? obj.c[i] : 0);
        }
        return Polynomial(new_c, M);
    }

    Polynomial operator-()
    {
        double *new_c = new double[N];
        for (int i = 0; i < N; i++)
        {
            new_c[i] = -c[i];
        }
        return Polynomial(new_c, N);
    }

    Polynomial operator-(const Polynomial& obj)
    {
        return *this + (-Polynomial(obj.c, obj.N));
    }

    Polynomial operator*(const Polynomial& obj)
    {
        int M = N + obj.N - 1;
        double *new_c = new double[M];

        for (int i = 0; i < M; i++)
            new_c[i] = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < obj.N; j++)
                new_c[i + j] += c[i] * obj.c[j];

        return Polynomial(new_c, M);
    }
};
