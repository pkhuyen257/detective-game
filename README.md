# 🕵️ The Clocktower Conspiracy

**A text-based detective game built in C++ where players solve Knights and Knaves logic puzzles to uncover a murder.**

> Interrogate suspects, determine who tells the truth, collect testimonies, and deduce the killer.

---

## 📖 Story

Professor Alden, a renowned logician, has been found dead in the **clocktower library of Ravenshire Village**.

The villagers follow a strange rule:

- **Knights** always tell the truth  
- **Knaves** always lie  

As the detective assigned to the case, you must interrogate the suspects and determine who is lying. Each solved logic puzzle unlocks new testimonies that help reconstruct the events of the night.

Only after solving all interrogations can you accuse the murderer.

---

## 🎮 Gameplay

The investigation progresses through a series of logic-based interrogations.

### Investigation Flow

1. Suspects make statements about each other  
2. Determine whether each suspect is a **Knight** or **Knave**  
3. Correct answers unlock **testimonies**  
4. Record discoveries in your **detective notebook**  
5. Use the information to identify the murderer  

Example puzzle:
Alice says: "Benedict is a knave."
Benedict says: "Alice and I are the same type."

Who is the Knight and who is the Knave?

---

## 🧠 Game Features

- 🧩 **Knights and Knaves logic puzzles**
- 📓 **Detective notebook system**
- 🔎 **Story-driven investigation**
- 💬 **Character testimonies**
- 🖥 **Command-line interactive gameplay**
- 🧠 **Deduction-based murder mystery**

---

## 🛠 Built With

- **C++**
- **GNU Make**
- **Ubuntu / WSL**
- **VS Code**

---

## 📂 Project Structure

```text
detective-game/
│
├── main.cpp
│   └── Program entry point
│
├── game.cpp / game.h
│   └── Controls game flow, puzzle solving, and accusation logic
│
├── case.cpp / case.h
│   └── Stores the murder case, suspects, and logic puzzles
│
├── notebook.cpp / notebook.h
│   └── Tracks discovered identities and testimonies
│
└── Makefile
    └── Builds the project using g++
