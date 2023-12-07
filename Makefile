CXX = g++
SRCDIR = .
BUILDDIR = .
TARGET = game.exe
SRCS = $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(SRCDIR)/Mouse/*.cpp) $(wildcard $(SRCDIR)/Buckets/*.cpp) $(wildcard $(SRCDIR)/Game/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))
$(TARGET): $(OBJS)
	$(CXX) $^ -o $@
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $< -o $@
.PHONY: clean
clean:
	rm -f $(BUILDDIR)/*.o $(TARGET) main.o
