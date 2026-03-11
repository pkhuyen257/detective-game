#include "notebook.h"
#include <iostream>

using namespace std;

void Notebook::addIdentity(const string& name, char type) {
    identities[name] = type;
}

void Notebook::addTestimony(const Testimony& testimony) {
    for (size_t i = 0; i < testimonies.size(); i++) {
        if (testimonies[i].speaker == testimony.speaker &&
            testimonies[i].text == testimony.text) {
            return;
        }
    }
    testimonies.push_back(testimony);
}

bool Notebook::hasIdentity(const string& name) const {
    return identities.find(name) != identities.end();
}

char Notebook::getIdentity(const string& name) const {
    map<string, char>::const_iterator it = identities.find(name);

    if (it != identities.end()) {
        return it->second;
    }

    return '?'; // Unknown
}

void Notebook::showIdentities() const {
    cout << "Identified roles:\n";

    if (identities.empty()) {
        cout << "  (none yet)\n";
        return;
    }

    for (map<string, char>::const_iterator it = identities.begin();
         it != identities.end(); ++it) {

        cout << "- " << it->first << ": ";

        if (it->second == 'K') {
            cout << "Knight";
        } else if (it->second == 'N') {
            cout << "Knave";
        }

        cout << "\n";
    }
}

void Notebook::showTestimonies() const {
    cout << "\nCollected testimonies:\n";

    if (testimonies.empty()) {
        cout << "  (none yet)\n";
        return;
    }

    for (size_t i = 0; i < testimonies.size(); i++) {
        cout << "- " << testimonies[i].speaker
             << " said: \"" << testimonies[i].text << "\"\n";
    }
}

void Notebook::showAll() const {
    cout << "\n========== DETECTIVE NOTEBOOK ==========\n\n";

    showIdentities();
    showTestimonies();

    cout << "\n========================================\n";
}