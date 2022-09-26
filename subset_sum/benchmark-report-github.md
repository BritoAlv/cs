``` ini

BenchmarkDotNet=v0.13.2, OS=ubuntu 22.04
Intel Core i5-7200U CPU 2.50GHz (Kaby Lake), 1 CPU, 4 logical and 2 physical cores
.NET SDK=6.0.400
  [Host]     : .NET 6.0.8 (6.0.822.36306), X64 RyuJIT AVX2
  DefaultJob : .NET 6.0.8 (6.0.822.36306), X64 RyuJIT AVX2


```
|               Method | size |       Mean |    Error |   StdDev | Allocated |
|--------------------- |----- |-----------:|---------:|---------:|----------:|
| **without_extra_params** |    **5** |   **121.7 ns** |  **0.22 ns** |  **0.19 ns** |         **-** |
| **without_extra_params** |    **6** |   **247.8 ns** |  **1.03 ns** |  **0.86 ns** |         **-** |
| **without_extra_params** |    **7** |   **497.4 ns** |  **1.34 ns** |  **1.12 ns** |         **-** |
| **without_extra_params** |    **8** | **1,025.8 ns** |  **3.79 ns** |  **3.36 ns** |         **-** |
| **without_extra_params** |    **9** | **2,108.0 ns** |  **2.94 ns** |  **2.30 ns** |         **-** |
| **without_extra_params** |   **10** | **4,276.7 ns** |  **3.60 ns** |  **3.01 ns** |         **-** |
| **without_extra_params** |   **11** | **8,678.4 ns** | **37.08 ns** | **34.69 ns** |         **-** |
