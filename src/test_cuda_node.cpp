#include <rclcpp/rclcpp.hpp>
#include "test_cuda_package/cuda_kernels.h"

class TestCUDANode : public rclcpp::Node {
public:
    TestCUDANode() : Node("test_cuda_node") {
        RCLCPP_INFO(this->get_logger(), "CUDA Node Initialized");
        test_cuda_kernel();
    }

private:
    void test_cuda_kernel() {
        int size = 1024;
        float* device_data;

        // CUDA 메모리 할당
        cudaMalloc(&device_data, size * sizeof(float));
        cudaMemset(device_data, 0, size * sizeof(float));

        // CUDA 커널 실행
        int blocks = (size + 255) / 256;
        launch_simple_cuda_kernel(device_data, size);
        cudaDeviceSynchronize();

        // CUDA 메모리 해제
        cudaFree(device_data);
        RCLCPP_INFO(this->get_logger(), "CUDA Kernel Executed");
    }
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TestCUDANode>());
    rclcpp::shutdown();
    return 0;
}
