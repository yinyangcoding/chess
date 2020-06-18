#include "../../include/objects/Move.hpp"

// ============= Methods =============
// Switch to decide which piece to operate on
void Move::update_moves(Board b, Piece p) {
    if(DEBUG) {
        printf("Move::update_moves()\n");
    }
    switch(p.get_type()) {
        case 1:
            update_pawn(b, p);
            break;
        case 2:
            update_knight(b, p);
            break;
        case 3:
            update_bishop(b, p);
            break;
        case 4:
            update_rook(b, p);
            break;
        case 5:
            update_queen(b, p);
            break;
        case 6:
            update_king(b, p);
            break;
        default:
            return;
    }
}

// pawn: 1, knight: 2, bishop: 3, Rook: 4, Queen: 5, King: 6
// Piece specific updates, private
void Move::update_pawn(Board board, Piece piece) {
    if(DEBUG) {
        printf("Move::update_pawn()\n");
    }
}
void Move::update_knight(Board board, Piece piece) {
    if(DEBUG) {
        printf("Move::update_knight()\n");
    }
}
void Move::update_bishop(Board board, Piece piece) {
    if(DEBUG) {
        printf("Move::update_bishop()\n");
    }
}
void Move::update_rook(Board board, Piece piece) {
    if(DEBUG) {
        printf("Move::update_rook()\n");
    }
}
void Move::update_queen(Board board, Piece piece) {
    if(DEBUG) {
        printf("Move::update_queen()\n");
    }
}
void Move::update_king(Board board, Piece piece) {
    if(DEBUG) {
        printf("Move::update_king()\n");
    }
}