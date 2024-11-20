// cuda_kernels.cu
#include <cuda_runtime.h>
#include "test_cuda_package/cuda_kernels.h"
#include <stdio.h>

__global__ void simple_cuda_kernel(float* data, int size) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < size) {
        data[idx] = idx + 2.0; // 예시 연산

        printf("Thread %d processed data[%d] = %f\n", idx, idx, data[idx]);
    }
}

void launch_simple_cuda_kernel(float* device_data, int size) {
    int threadsPerBlock = 256;
    int blocks = (size + threadsPerBlock - 1) / threadsPerBlock;
    simple_cuda_kernel<<<blocks, threadsPerBlock>>>(device_data, size);
    cudaDeviceSynchronize(); // 커널 실행 완료 대기
}
