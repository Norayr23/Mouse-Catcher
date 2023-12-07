#ifndef MOUSE_H
#define MOUSE_H

#include <cstddef>

class Mouse {
public:
    Mouse();
    explicit Mouse(size_t);
    void move();
    size_t position() const;
    void setFieldSize(size_t size);
    size_t getFieldSize() const;
    void setPosition(size_t);
    void moveToRandomPosition();
private:
    size_t getRadomPos(size_t, size_t) const;
    size_t m_field_size;
    size_t m_pos;

        
};

#endif