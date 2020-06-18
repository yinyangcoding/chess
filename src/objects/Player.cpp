#include "../../include/objects/Player.hpp"


// ================ Constructors ================
// Sets given color
Player::Player(char c) {
    color = c;
}

// ================ Methods ================
// Removes piece from onBoard and puts it in taken. Returns if successful
bool Player::lose(Piece a) {
    if(Tools::contains(onBoard, a)) {
        int index = Tools::index(onBoard, a);

        Piece temp;
        temp.copy_from(onBoard[index]);

        vector<Piece>::iterator it = onBoard.begin() + index;
        vector<int>::iterator iit = ionBoard.begin() + index;

        onBoard.erase(it);
        lost.push_back(temp);

        ilost.push_back(ionBoard[index]);
        ionBoard.erase(iit);

        return true;
    }
    
    return false;
}