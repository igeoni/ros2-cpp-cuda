cmake_minimum_required(VERSION 3.5)
project(test_cuda_package LANGUAGES CXX CUDA)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(CUDA REQUIRED)

# CUDA 헤더와 소스 경로 설정
include_directories(
    include
    /usr/local/cuda/include
)

# CUDA 아키텍처 설정 (GPU에 맞게 설정)
set(CMAKE_CUDA_ARCHITECTURES 75) # 예: NVIDIA Turing 아키텍처 (RTX 20/30 시리즈)

# CUDA 라이브러리 생성
cuda_add_library(cuda_kernels_lib STATIC
    src/cuda_kernels.cu
)
target_include_directories(cuda_kernels_lib PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
set_target_properties(cuda_kernels_lib PROPERTIES
    CUDA_SEPARABLE_COMPILATION ON
)

# C++ 실행 파일 생성
add_executable(test_cuda_node src/test_cuda_node.cpp)
ament_target_dependencies(test_cuda_node rclcpp)

# CUDA 라이브러리 연결
target_link_libraries(test_cuda_node cuda_kernels_lib)

# 설치 설정
install(TARGETS
    test_cuda_node
    DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
    DESTINATION include/
)
install(FILES package.xml
    DESTINATION share/${PROJECT_NAME}
)


# ament 설정
ament_package()