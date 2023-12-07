#include "Mouse.h"
#include <random>
#include <stdexcept>

Mouse::Mouse() :  m_pos{}, m_field_size{} {}
Mouse::Mouse(size_t fieldSize) : m_field_size(fieldSize), m_pos(getRadomPos(0, getFieldSize() - 1)) {}
size_t Mouse::getFieldSize() const { return m_field_size; }
void Mouse::setFieldSize(size_t fs) { m_field_size = fs; }
size_t Mouse::position() const { return m_pos; }
void Mouse::setPosition(size_t pos) {
    if (pos >= getFieldSize()) {
        throw std::out_of_range("Mouse::setPosition(size_t) argument is out of bounds");
    }
    m_pos = pos; 
}
void Mouse::move() {
    static const char right = 0;
    static const char left = 1;
    if (getFieldSize() <= 1) {
        return;
    }
    if (!position() || position() <= getFieldSize() / 3) {
        ++m_pos;
    }
    else if (position() == getFieldSize() - 1 || position() >= getFieldSize() / 1.5) {
        --m_pos;
    }
    else {
        size_t pos = getRadomPos(right, left);
        if (pos == right) {
            --m_pos;
        }
        else {
            ++m_pos;
        }
    }
}
size_t Mouse::getRadomPos(size_t lb, size_t ub) const {
    if (lb >= ub) {
        return lb;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribution(lb, ub);
    size_t random_number = distribution(gen);
    return random_number;
}
 void Mouse::moveToRandomPosition() {
    setPosition(getRadomPos(0, getFieldSize() - 1));
 }