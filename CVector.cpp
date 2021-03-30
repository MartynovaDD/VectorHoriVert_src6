#include "CVector.h"
#include "Source.h"
#include <chrono>
#include <omp.h>


double CVector::operator*(const CVector& b) {
	if (n != b.n) {
		printf("Error. Incorrect length\n");
		return 0;
	}
	else {
		double res = 0;
		double wrk = 0;
		int N = n;
		auto start = std::chrono::system_clock::now();
#pragma omp parallel shared(res) private(wrk)
{
#pragma omp for reduction(+:res)
			for (int i = 0; i < N; i++) {
				wrk = s[i] * b[i];
				res += wrk;
			}
}
		auto end = std::chrono::system_clock::now();
		int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
		std::cout << "Addition operator runtime is " << elapsed_ms << " ms\n";
			return res;
		}
}
