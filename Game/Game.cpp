#include "Game.h"

#include <iostream>
#include <thread>

void Game::run() {
    system("clear");
    std::cout << "Welcome to 'Mouse Catcher Game'!!" << std::endl;
    std::cout << "In this game, your objective is to catch the mouse as it scurries between buckets.\n" << 
    "By entering the bucket positions, you can attempt to capture the elusive mouse. \n" <<
    "After each attempt, the mouse moves to a neighboring bucket." << std::endl;
    const_cast<Game*>(this)->setBucketsSize(getSizeFromUser());
    std::cout << "Lets Start!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    while (true) {
        system("clear");
        print();
        std::cout << "To end the game, enter a non-numeric value." << std::endl;
        std::cout << "Please enter your Attempt (Enter 0 for multiple moves): ";        
        size_t pos = 0;
        std::cin >> pos;
        if (!std::cin) {
            std::cout << "End of Game" << std::endl;
            m_buckets.printMoves();
            if (askUserForReplay()) {
                m_buckets.reset();
                setBucketsSize(getSizeFromUser());
                continue;
            }
            return;    
        }
        if (!pos) {
            bool res = doMultiMoves();
            if (res) {
                std::cout << "You Win!!" << std::endl;
                m_buckets.printMoves();
                if (askUserForReplay()) {
                    m_buckets.reset();
                    setBucketsSize(getSizeFromUser());
                    continue;
                }
                return;    
            }
        }
        if (move(pos)) {
            std::cout << "You Win!!" << std::endl;
            m_buckets.printMoves();
            if (askUserForReplay()) {
                m_buckets.reset();
                setBucketsSize(getSizeFromUser());
                continue;
            }
            return;    
        }
    }
}

void Game::setBucketsSize(size_t size) { m_buckets.setFieldSize(size); }
size_t Game::getBucketsSize() const { return m_buckets.fieldSize(); }
bool Game::move(size_t pos) {
    if (!isPosValid(pos)) {
         std::cout << "Invalid Move" << std::endl;
         std::this_thread::sleep_for(std::chrono::seconds(1));
         return false;
    }
    if (m_buckets.tryCatch(pos - 1)) {
        return true;
    }
    return false;
    
}
bool Game::doMultiMoves() {
    std::cout << "\nEnter a move and press enter. To terminate, enter -1." << std::endl;
    size_t pos = 0;
    bool res = false;
    while (std::cin >> pos) {
        if (pos == -1) {
            break;
        }
        res = move(pos) ? true : res;
    }
    return res;
}
void Game::printAllMoves() const {
    const auto moves = m_buckets.getMoves();
    int lineCount = 0;
    for (int i = 0; i < moves.size(); ++i, ++lineCount) {
        if (lineCount >= 20) {
            std::cout << std::endl;
            lineCount = 0;
        }
        if (moves[i].first != moves[i].second) {
            std::cout << i + 1 << ": " << "fail "; 
        }
        else {
            std::cout << i + 1 << ": " << "win!! ";
        }
    }
    std::cout << std::endl;
}
void Game::print() const {
    int linesCount = 0;
    for (int i = 1; i <= m_buckets.fieldSize(); ++i, ++linesCount) {
          if (linesCount >= 20) {
            linesCount = 0;
            std::cout << std::endl;
        }
        std::cout << "[ " << i << "  ] ";
    }
    std::cout << "\n" << std::endl;
    printAllMoves();
}
bool Game::isPosValid(size_t pos) const {
    return pos > 0 && pos <= getBucketsSize();
}
size_t Game::getSizeFromUser() const {
    std::cout << "Please enter the size of the buckets you'd like to play with (Maximum size: 20): ";
    size_t size = 0;
    std::cin >> size; 
    while (!size || size > 20) {
        std::cout << "Invalid size. The size should be greater than 0 and less than or equal to 20. Please try again: ";
        std::cin >> size;
    }
    return size;
}
bool Game::askUserForReplay() const {
    std::cout << "Do you want to replay the game?(y/n): ";
    char c = 'n';
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> c;
    if (!std::cin || c != 'y') {
        return false;
    }
    return true;
} 