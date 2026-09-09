# Heuristic Algorithm for the TSP

Implementation of a constructive heuristic for the Asymmetric Traveling Salesman Problem (ATSP), written in C, with result visualization graphs generated in Python.

## About the project

The Traveling Salesman Problem (TSP) consists of finding the lowest cost route that visits a set of cities exactly once, returning to the starting point. This project addresses the asymmetric variant (ATSP), where the cost of traveling from city A to B may differ from the cost of traveling from B to A.

Since the TSP is an NP hard problem, an exact solution becomes infeasible for large instances. This project implements a constructive heuristic, which generates good quality approximate solutions in reduced computational time.

## Project structure

- `atsp.c` and `atsp.h`: implementation of the heuristic and the problem's data structures
- `main.c`: entry point and algorithm execution
- `atsp`: compiled binary of the program
- `grafico.py`: graph generation for visualizing the results
- `Algoritmo Heuristico para Solucionar o TSP.pdf`: project documentation and report

## Tech Stack

- C
- Python (for results visualization)

## How to run

Compile the C code and run the generated binary:

```
gcc main.c atsp.c -o atsp -lm
./atsp
```

The results can then be visualized by running the Python script:

```
python grafico.py
```
