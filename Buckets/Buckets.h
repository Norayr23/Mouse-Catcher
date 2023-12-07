#ifndef BUCKETS_H
#define BUCKETS_H

#include "../Mouse/Mouse.h"
#include <vector>
#include <utility>

class Buckets {
public:
    Buckets();
    explicit Buckets(size_t);
    bool tryCatch(size_t);
    void printMoves() const;
    void setFieldSize(size_t);
    size_t fieldSize() const;
    size_t getMousePosition() const;
    void updateMousePosition(size_t);
    void reset();
    const std::vector<std::pair<size_t, size_t>>& getMoves() const;
private:
    size_t m_fieldSize;
    std::vector<std::pair<size_t, size_t>> m_moves;
    Mouse m_mouse;    
};

#endif