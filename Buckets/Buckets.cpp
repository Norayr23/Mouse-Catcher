#include "Buckets.h"
#include <iostream>

Buckets::Buckets() : m_fieldSize{} {}
Buckets::Buckets(size_t size) : m_fieldSize(size), m_mouse(size) {}
bool Buckets::tryCatch(size_t pos) {
    if (pos == m_mouse.position()) {
        m_moves.push_back({m_mouse.position(), pos});
        m_mouse.move();
        return true;
    }
    m_moves.push_back({m_mouse.position(), pos});
    m_mouse.move();
    return false;
}
void Buckets::printMoves() const {
    int linesCount = 0;
    int movesCount = 0;
    for (auto pair : m_moves) {
        if (movesCount >= 20) {
            std::cout << std::endl;
            movesCount = 0;
        }
        std::cout << linesCount + 1 << "th move: ";
        ++movesCount;
        ++linesCount;
        for (int i = 0; i < fieldSize(); ++i) {
            if (i == pair.first && i == pair.second) {
                std::cout << "[MA] ";
            }
            else if (i == pair.first) {
                std::cout << "[M ] ";
            }
            else if (i == pair.second) {
                std::cout << "[A ] ";
            }
            else {
                std::cout << "[  ] ";
            }    
        }
        std::cout << std::endl;
    }
}
void Buckets::setFieldSize(size_t size) { 
    m_mouse.setFieldSize(size);
    m_fieldSize = size;
    m_mouse.moveToRandomPosition(); 
}
size_t Buckets::fieldSize() const { return m_fieldSize; }
size_t Buckets::getMousePosition() const { return m_mouse.position(); }
void Buckets::updateMousePosition(size_t pos) { m_mouse.setPosition(pos); }
void Buckets::reset() { m_moves.clear(); }
 const std::vector<std::pair<size_t, size_t > >& Buckets::getMoves() const { return m_moves; }

