#include <iostream>
#include <cstdlib>
#include <immintrin.h>
#include <chrono>

int main()
{
    std::cout << "Method " << "input-size " << "Time " << "Time_Complexity" <<  "\n";   
    for (int r = 1 << 15; r < 2 << 27; r = r * 2)
    {
        const int N = r; // testing with 2^26
        // allocate in memory space for 2^26 floats, and get a pointer to it.
        auto *A = (float *)_mm_malloc(N * sizeof(float), 64);
        auto *B = (float *)_mm_malloc(N * sizeof(float), 64);

        
        srand(0);
        for (int i = 0; i < N; i++)
        {
            float ra = (2.0f * ((float)rand()) / RAND_MAX) - 1.0f;
            float rb = (2.0f * ((float)rand()) / RAND_MAX) - 1.0f;
            A[i] = ra; // A[i] to a pointer weird..
            B[i] = rb;
        }
        
        std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
        float sumR = 0;

        for (int i = 0; i < N; i++)
        {
            float Ar = A[i];
            float Br = B[i];
            float Cr = Ar * Br;
            sumR += Cr;
        }

        std::chrono::steady_clock::time_point stopTime = std::chrono::steady_clock::now();

        double dt = (std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime)).count();

        std::cout << "RegularFor "<< N << " " << dt << " " << dt/N << "\n";

        startTime = std::chrono::steady_clock::now();

        // 256 bit / 8 = 32 a float is 4 bytes or 32 bits.
        __m256 sumr = _mm256_set1_ps(0.0); // stores 8 floats.

        auto *a = (__m256 *)A; // interpret the block of memory for A, as __m256.
        auto *b = (__m256 *)B;

        const int n = N / 8;
        // sum is done using blocks of eight floats by instruction, this is what
        // the SIMD instructions allow.
        for (int j = 0; j < n; j++)
        {
            __m256 cr = _mm256_mul_ps(a[j], b[j]);
            sumr = _mm256_add_ps(sumr, cr);
        }

        auto *sr = (float *)&sumr;

        sumr = _mm256_hadd_ps(sumr, sumr);
        sumr = _mm256_hadd_ps(sumr, sumr);
        sumr = _mm256_add_ps(sumr, _mm256_permute2f128_ps(sumr, sumr, 1));

        stopTime = std::chrono::steady_clock::now();

        dt = (std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime)).count();
        std::cout << "SIMD " << N << " " << dt << " " << dt/N << "\n";
    }
}
