#ifndef GAME_H
#define GAME_H

#include "case.h"
#include "notebook.h"

class Game {
private:
    Case currentCase;
    Notebook notebook;
    bool running;

    void showIntro() const;
    void playCase();
    void runPuzzle(int puzzleIndex);
    void revealTestimoniesForPuzzle(Puzzle& puzzle);
    void showNotebook() const;
    void makeAccusation();
    bool allPuzzlesSolved() const;

public:
    Game();
    void start();
};

#endif