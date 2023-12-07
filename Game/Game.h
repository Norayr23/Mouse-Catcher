#ifndef GAME_H
#define GAME_H

#include "../Buckets/Buckets.h"
#include "string"

class Game {
public:
    void run();
private:
    void setBucketsSize(size_t);
    size_t getBucketsSize() const;
    bool move(size_t);
    bool doMultiMoves();
    void printAllMoves() const;
    void print() const;
    bool isPosValid(size_t) const;
    size_t getSizeFromUser() const;
    bool askUserForReplay() const;
    Buckets m_buckets;
};

#endif