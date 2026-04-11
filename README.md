# Number Guessing Game (C)

## Description

A command-line number guessing game written in C where the player tries to guess a randomly generated number within a limited number of attempts.

The game includes multiple difficulty levels, a scoring system, and file-based storage to keep track of scores and the best result.

---

## Features

- 3 difficulty levels:
  - Easy (1–50, 10 attempts)
  - Medium (1–100, 7 attempts)
  - Hard (1–1000, 5 attempts)
- Score calculation system (/10)
- Best score tracking (saved in a file)
- Score history (last 10 games)
- Input validation (handles invalid inputs safely)
- Hint system (tells if you are close or far)

---

## Technologies Used

- C programming language
- Standard libraries:
  - stdio.h
  - stdlib.h
  - time.h
- File handling (fopen, fscanf, fprintf)

---

## How to Run

1. Compile the code:
   gcc main.c -o game.exe

2. Run the program:
   ./game.exe

## What I Learned

- How to use file handling in C to store data
- How to structure a program and reduce code duplication using functions
- How to handle invalid user input
- How to design a simple game loop
- Importance of code readability and refactoring

## Future Improvements

- Improve code structure with more modular functions
- Add a graphical interface (GUI)
- Store scores in a more advanced format (e.g., database)
- Add multiplayer mode
