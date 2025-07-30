#ifndef GFX_BOARD_H
#define GFX_BOARD_H

template<typename T>
class Board {
    public:
        Board(int r, int c);

    private:
        T** board;

};

#endif