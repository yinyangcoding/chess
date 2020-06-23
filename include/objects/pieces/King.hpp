#ifndef KING_GUARD
#define KING_GUARD

#include "../../resources/Constants.h"
#include "../../resources/BlandTools.hpp"
#include "../Piece.hpp"
#include "../Board.hpp"


class King : public Piece {
    public:
        King(char c);
};

#endif