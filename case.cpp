#include "case.h"

Case::Case() {
    title = "";
    intro = "";
    culprit = "";
    ending = "";
}

void Case::loadDefaultCase() {
    title = "The Clocktower Conspiracy";

    intro =
        "Professor Alden, a famous logician, was found dead in the clocktower library.\n"
        "You have been summoned to Ravenshire Village to investigate the murder.\n"
        "The villagers live by a strange rule: each person is either a Knight,\n"
        "who always tells the truth, or a Knave, who always lies.\n\n"
        "To solve the case, you must determine who can be trusted.\n"
        "Each solved interrogation will unlock testimony related to the murder.\n"
        "Only after solving all puzzles can you conclude who the murderer is.";

    suspects.clear();
    suspects.push_back("Alice");
    suspects.push_back("Benedict");
    suspects.push_back("Clara");
    suspects.push_back("Daniel");

    puzzles.clear();

    // =========================
    // Puzzle 1
    // =========================
    Puzzle p1;
    p1.title = "The Garden Interrogation";
    p1.description =
        "You question Alice and Benedict in the garden behind the manor.";

    p1.logicStatements.push_back({"Alice", "Benedict is a knave."});
    p1.logicStatements.push_back({"Benedict", "Alice and I are of the same type."});

    p1.solution["Alice"] = 'K';
    p1.solution["Benedict"] = 'N';

    p1.testimonies.push_back({"Alice", "I saw Daniel near the library at 9:15 PM."});
    p1.testimonies.push_back({"Benedict", "Clara never entered the study that night."});

    p1.solved = false;
    puzzles.push_back(p1);

    // =========================
    // Puzzle 2
    // =========================
    Puzzle p2;
    p2.title = "The Servants' Hall Interrogation";
    p2.description =
        "You find Clara and Benedict arguing in the servants' hall.";

    p2.logicStatements.push_back({"Clara", "Benedict and I are different types."});
    p2.logicStatements.push_back({"Benedict", "Clara is a knave."});

    p2.solution["Clara"] = 'K';
    p2.solution["Benedict"] = 'N';

    p2.testimonies.push_back({"Clara", "The professor argued with Daniel shortly before the murder."});
    p2.testimonies.push_back({"Benedict", "The professor's study key was never taken."});

    p2.solved = false;
    puzzles.push_back(p2);

    // =========================
    // Puzzle 3
    // =========================
    Puzzle p3;
    p3.title = "The Final Interrogation";
    p3.description =
        "You confront Alice and Daniel in the clocktower foyer.";

    p3.logicStatements.push_back({"Alice", "Daniel is a knave."});
    p3.logicStatements.push_back({"Daniel", "Alice is a knave."});

    p3.solution["Alice"] = 'K';
    p3.solution["Daniel"] = 'N';

    p3.testimonies.push_back({"Alice", "Daniel had demanded the professor's research notes earlier that evening."});
    p3.testimonies.push_back({"Daniel", "I was in the garden all evening and never entered the library."});

    p3.solved = false;
    puzzles.push_back(p3);

    culprit = "Daniel";

    ending =
        "You lay out the facts before the villagers.\n"
        "Alice and Clara's testimonies, once filtered through the truth of their identities,\n"
        "place Daniel at the scene and reveal his motive.\n"
        "Benedict and Daniel both lied repeatedly to conceal the truth,\n"
        "but Daniel's contradictions were too strong to ignore.\n\n"
        "Cornered by logic, Daniel confesses.\n"
        "He murdered Professor Alden to steal his research notes.";
}

string Case::getTitle() const {
    return title;
}

string Case::getIntro() const {
    return intro;
}

int Case::getPuzzleCount() const {
    return static_cast<int>(puzzles.size());
}

Puzzle& Case::getPuzzle(int index) {
    return puzzles[index];
}

const Puzzle& Case::getPuzzle(int index) const {
    return puzzles[index];
}

vector<string> Case::getSuspects() const {
    return suspects;
}

string Case::getCulprit() const {
    return culprit;
}

string Case::getEnding() const {
    return ending;
}