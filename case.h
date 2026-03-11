#ifndef CASE_H
#define CASE_H

#include <string>
#include <vector>
#include <map>

using namespace std;

struct Statement {
    string speaker;
    string text;
};

struct Testimony {
    string speaker;
    string text;
};

struct Puzzle {
    string title;
    string description;
    vector<Statement> logicStatements;
    map<string, char> solution;   // 'K' = Knight, 'N' = Knave
    vector<Testimony> testimonies;
    bool solved;
};

class Case {
private:
    string title;
    string intro;
    vector<string> suspects;
    vector<Puzzle> puzzles;
    string culprit;
    string ending;

public:
    Case();

    void loadDefaultCase();

    string getTitle() const;
    string getIntro() const;
    int getPuzzleCount() const;

    Puzzle& getPuzzle(int index);
    const Puzzle& getPuzzle(int index) const;

    vector<string> getSuspects() const;
    string getCulprit() const;
    string getEnding() const;
};

#endif