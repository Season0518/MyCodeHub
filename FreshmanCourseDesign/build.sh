#!/bin/bash

# 定义构建目录的名称
BUILD_DIR="build"

# 检查构建目录是否存在
if [ -d "$BUILD_DIR" ]; then
    # 如果目录存在，则删除
    echo "Removing existing build directory..."
    rm -rf "$BUILD_DIR"
fi

# 创建新的构建目录
echo "Creating build directory..."
mkdir "$BUILD_DIR"

# 进入构建目录
cd "$BUILD_DIR"

# 运行 CMake 配置和构建命令
echo "Configuring and building project..."
cmake .. && cmake --build .

# 返回到原始目录（可选）
cd ..
