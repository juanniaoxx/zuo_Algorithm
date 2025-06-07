# 编译器设置
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra

# 目标可执行文件
TARGET := program

# 源文件和对象文件
SRCS := main.cpp print_binary.cpp
OBJS := $(SRCS:.cpp=.o)

# 默认目标：构建可执行文件并自动清理 .o 文件
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "编译完成，自动清理中间文件..."
	rm -f $(OBJS)  # 链接后立即删除 .o 文件

# 生成 .o 文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 手动清理（可选）
clean:
	rm -f $(TARGET)

.PHONY: clean