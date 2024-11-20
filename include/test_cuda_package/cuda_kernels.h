#ifndef TEST_CUDA_PACKAGE_CUDA_KERNELS_H_
#define TEST_CUDA_PACKAGE_CUDA_KERNELS_H_

#include <cuda_runtime.h>  // CUDA 런타임 헤더

#ifdef __cplusplus
extern "C" {
#endif

void launch_simple_cuda_kernel(float* data, int size);

#ifdef __cplusplus
}
#endif

#endif  // TEST_CUDA_PACKAGE_CUDA_KERNELS_H_
