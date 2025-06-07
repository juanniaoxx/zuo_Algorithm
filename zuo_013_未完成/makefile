# 项目根目录下的Makefile
# 文件结构说明：
# .
# ├── Makefile          ← 本文件位置
# ├── include
# │   ├── stack.h
# │   ├── queue.h
# │   └── main.h
# ├── src
# │   ├── stack.cpp
# │   ├── queue.cpp
# │   └── test.cpp
# └── program          ← 生成的可执行文件
# 编译器设置
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++11 -Iinclude
LDFLAGS := 

# 文件路径设置
SRC_DIR := src
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,%.o,$(SRCS))
TARGET := program

# 伪目标声明
.PHONY: all clean

# 默认构建目标
all: $(TARGET)

# 主构建规则
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@
	@echo "\n=== 清理中间文件 ==="
	rm -f $(OBJS)

# 编译规则
%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理规则
clean:
	@echo "=== 清理构建文件 ==="
	rm -f $(TARGET) $(OBJS)

