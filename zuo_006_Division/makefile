# 编译器设置
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra

# 目标程序
PROGRAMS := binary_search_1 binary_search_2 binary_search_3

# 默认目标：编译所有程序
all: $(PROGRAMS)
	@echo "所有程序编译完成，正在清理中间文件..."
	@$(MAKE) clean_objs

# 每个程序的编译规则
binary_search_1: binary_search_1.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "$@ 编译成功"

binary_search_2: binary_search_2.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "$@ 编译成功"

binary_search_3: binary_search_3.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "$@ 编译成功"


# 从.cpp文件生成.o文件的通用规则
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# 仅清理.o文件（保留可执行程序）
clean_objs:
	@rm -f *.o
	@echo "已清理所有中间文件(.o)"

# 完全清理（包括可执行程序）
clean:
	@rm -f $(PROGRAMS) *.o
	@echo "已清理所有生成文件"

.PHONY: all clean clean_objs