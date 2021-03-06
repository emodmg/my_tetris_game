#include "game.h"
#include "textdisplay.h"



void Game::newGame() {
    players.clear();
    std::unique_ptr<Board> b1 = std::unique_ptr<Board>(new Board{1});
    std::unique_ptr<Board> b2 = std::unique_ptr<Board>(new Board{2});
    players.push_back(std::move(b1));
    players.push_back(std::move(b2));
}


int main() {
    Game g1{};
    TextDisplay td{&g1};
    g1.newGame();

    g1.players[0]->currBlock = new Sblock{};// for testing purpose
    g1.players[0]->nextBlock = new Zblock{};
    g1.players[1]->currBlock = new Jblock{};
    g1.players[1]->nextBlock = new Oblock{};
    td.print();

    g1.players[1]->right();
    // g1.players[1]->right();
    // g1.players[1]->right();
    // g1.players[0]->right();
    g1.players[0]->down();
    // g1.players[1]->down();
    // g1.players[1]->right();
    // g1.players[1]->right();
    // g1.players[1]->right();

    
    td.print();
    g1.players[0]->rot_cw();

    td.print();
    // g1.players[0]->rot_cw();
    // td.print();

    // g1.players[0]->rot_cw();
    // td.print();

    // g1.players[0]->rot_cw();
    // td.print();



    g1.players[1]->rot_cw();
    td.print();
    // g1.players[1]->rot_cw();
    // td.print();
    // g1.players[1]->rot_cw();
    // td.print();
    // g1.players[1]->rot_cw();
    // td.print();
    g1.players[0]->drop();
    g1.players[1]->drop();
    td.print();
    // delete g1.players[0]->currBlock; to avoid memory leak
    // delete g1.players[0]->nextBlock;
    // delete g1.players[1]->currBlock;
    // delete g1.players[1]->nextBlock;
}

