#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <string>
#include <vector>
#include <map>
#include "case.h"

using namespace std;

class Notebook {
private:
    // Stores identities: Alice -> 'K', Benedict -> 'N'
    map<string, char> identities;

    // Stores all testimonies revealed so far
    vector<Testimony> testimonies;

public:
    // Add identity of a character
    void addIdentity(const string& name, char type);

    // Add a testimony clue
    void addTestimony(const Testimony& testimony);

    // Check if we know someone's identity
    bool hasIdentity(const string& name) const;

    // Get identity of a character
    char getIdentity(const string& name) const;

    // Display identities section
    void showIdentities() const;

    // Display testimony clues
    void showTestimonies() const;

    // Show the entire notebook
    void showAll() const;
};

#endif