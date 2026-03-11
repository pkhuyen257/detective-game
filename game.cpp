#include "game.h"
#include <limits>
#include <sstream>
#include <iostream>
#include <cctype>

using namespace std;

Game::Game() : running(true) {
    currentCase.loadDefaultCase();
}

void Game::start() {
    showIntro();
    playCase();
}

void Game::showIntro() const {
    cout << "=========================================\n";
    cout << "         THE CLOCKTOWER CONSPIRACY       \n";
    cout << "=========================================\n\n";

    cout << currentCase.getIntro() << "\n";

    cout << "\nPress Enter to begin the investigation...";
    cin.ignore(10000, '\n');
}

void Game::playCase() {
    int totalPuzzles = currentCase.getPuzzleCount();

    for (int i = 0; i < totalPuzzles; i++) {
        runPuzzle(i);

        cout << "\n========== NOTEBOOK ==========\n";
        showNotebook();
        cout << "==============================\n\n";
    }

    if (allPuzzlesSolved()) {
        cout << "\nYou have solved all interrogations.\n";
        cout << "You now have enough information to conclude the case.\n\n";
        makeAccusation();
    }
}

void Game::runPuzzle(int puzzleIndex) {
    Puzzle& puzzle = currentCase.getPuzzle(puzzleIndex);

    if (puzzle.solved) {
        return;
    }

    cout << "\n-----------------------------------------\n";
    cout << "Puzzle " << puzzleIndex + 1 << ": " << puzzle.title << "\n";
    cout << "-----------------------------------------\n";
    cout << puzzle.description << "\n\n";

    cout << "Statements:\n";
    for (size_t i = 0; i < puzzle.logicStatements.size(); i++) {
        cout << "- " << puzzle.logicStatements[i].speaker
             << " says: \"" << puzzle.logicStatements[i].text << "\"\n";
    }

    cout << "\nDetermine whether each character is a Knight (K) or a Knave (N).\n";

    bool correct = false;

    while (!correct) {
        map<string, char> playerAnswer;

        for (map<string, char>::const_iterator it = puzzle.solution.begin();
             it != puzzle.solution.end(); ++it) {

            char answer;

            while (true) {
                cout << it->first << " (K/N): ";

                if (!(cin >> answer)) {
                    cout << "Invalid input. Please enter K or N.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                answer = toupper(answer);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (answer == 'K' || answer == 'N') {
                    break;
                }

                cout << "Invalid input. Please enter K or N.\n";
            }

            playerAnswer[it->first] = answer;
        }

        correct = true;

        for (map<string, char>::const_iterator it = puzzle.solution.begin();
             it != puzzle.solution.end(); ++it) {
            if (playerAnswer[it->first] != it->second) {
                correct = false;
                break;
            }
        }

        if (!correct) {
            cout << "\nThat is not correct. Review the statements and try again.\n\n";
        } else {
            cout << "\nCorrect! You identified their roles.\n";

            for (map<string, char>::const_iterator it = puzzle.solution.begin();
                 it != puzzle.solution.end(); ++it) {
                notebook.addIdentity(it->first, it->second);
            }

            puzzle.solved = true;
            revealTestimoniesForPuzzle(puzzle);
        }
    }
}

void Game::revealTestimoniesForPuzzle(Puzzle& puzzle) {
    if (puzzle.testimonies.empty()) {
        return;
    }

    cout << "\nUnlocked testimonies:\n";
    for (size_t i = 0; i < puzzle.testimonies.size(); i++) {
        notebook.addTestimony(puzzle.testimonies[i]);

        cout << "- " << puzzle.testimonies[i].speaker
             << " said: \"" << puzzle.testimonies[i].text << "\"\n";
    }

    cout << "\nUse the identities you discovered to decide whether each testimony is true.\n";
}

void Game::showNotebook() const {
    notebook.showAll();
}

void Game::makeAccusation() {
    vector<string> suspects = currentCase.getSuspects();

    cout << "Suspects:\n";
    for (size_t i = 0; i < suspects.size(); i++) {
        cout << i + 1 << ". " << suspects[i] << "\n";
    }

    int choice;

    while (true) {
        cout << "\nWho is the murderer? Enter the suspect number: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice < 1 || choice > static_cast<int>(suspects.size())) {
            cout << "Invalid choice. Enter a valid suspect number.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    }

    string guess = suspects[choice - 1];

    cout << "\nYou accuse " << guess << ".\n\n";

    if (guess == currentCase.getCulprit()) {
        cout << "Your accusation is correct.\n\n";
        cout << currentCase.getEnding() << "\n";
    } else {
        cout << "Your accusation is wrong.\n";
        cout << "The real murderer was " << currentCase.getCulprit() << ".\n\n";
        cout << currentCase.getEnding() << "\n";
    }

    running = false;
}

bool Game::allPuzzlesSolved() const {
    for (int i = 0; i < currentCase.getPuzzleCount(); i++) {
        const Puzzle& puzzle = currentCase.getPuzzle(i);
        if (!puzzle.solved) {
            return false;
        }
    }
    return true;
}