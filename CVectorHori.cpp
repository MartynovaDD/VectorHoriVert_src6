#include "CVectorHori.h"
#include <chrono>
#include <omp.h>


CVector1 operator+(const CVector& a, const CVector& b)
{
    if (a.n != b.n)
    {
        cout << "Error: vectors have different dimensions." << endl;
        exit(-1);
    }
    else
    {
        vector<double> q(a.n);
        vector<double> s(a.n);
        auto start = std::chrono::system_clock::now();
#pragma omp parallel for
        for (int i = 0; i < a.n; i++)
        {
            s[i] = a.s[i] + b[i];
        }
        auto end = std::chrono::system_clock::now();
        int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
        std::cout << "Addition operator runtime is " << elapsed_ms << " ms\n";
        CVector1 res(b.filename, q, a.n);
        q.clear();
        return res;
    }
}

CVector1 operator-(const CVector& a, const CVector& b)
{
    if (a.n != b.n)
    {
        cout << "Error: vectors have different dimensions." << endl;
        exit(-1);
    }
    else
    {
        vector<double> q(a.n);
        auto start = std::chrono::system_clock::now();
#pragma omp parallel for
        for (int i = 0; i < a.n; i++)
        {
            q[i] = a.s[i] - b[i];
        }
        auto end = std::chrono::system_clock::now();
        int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
        std::cout << "Addition operator runtime is " << elapsed_ms << " ms\n";
        CVector1 res(b.filename, q, a.n);
        return res;
    }
}


int CVector1::output(string FileName) {
    ofstream output(FileName, ios_base::app);
    for (auto i = s.begin(); i != s.end(); ++i) {
        output << *i << ' ';
        cout << *i << ' ';
    }
    output << '\n';
    output.close();
    return 0;
}