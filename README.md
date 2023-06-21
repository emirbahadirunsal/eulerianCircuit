# Binary Operation Parenthesization Project

This C++ program implements a dynamic programming algorithm that examines a string of symbols and decides whether or not it is possible to parenthesize the string in such a way that the value of the resulting expression is a certain goal symbol. The program also outputs a parenthesized expression that fulfills the goal or states that no such parenthesization exists if that's the case.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

You will need a C++ compiler (like g++ or clang++) installed on your system to run this code. If you don't have one already installed, you can get it by downloading from the official websites.

### Installing

1. Clone the repo or download the .cpp file to your local system.
2. Navigate to the directory containing the .cpp file in your terminal.
3. Compile the file using your C++ compiler.

For example, if you're using g++, type the following command and press enter:

```bash
g++ parenthesization.cpp -o parenthesization
```

### Usage

You can then run the program using the following command:

```bash
./parenthesization
```

#### Input

The first line contains a positive integer which defines the number of symbols. The second line contains these symbols. The following n lines make an nxn matrix that represents the results of the operations. The last line contains a sequence of characters for which you have to seek for a parenthesization.

Sample input:

```text
3
abc
aac
baa
caa
caaccb
```

#### Output

The output will be a parenthesized expression yielding the goal if one exists. If no such parenthesization exists, it outputs "No parenthesization is possible."

Sample outputs for the above input:

```text
(c((aa)((cc)b))
(c(a(a((cc)b))))
(((ca)a)((cc)b))
(((ca)a)((cc)b))
```

## Code Description

The code contains an `Operation` class that holds the data and methods needed to solve the problem. It reads the input, processes it, and outputs the result. The `showTime()` function implements the main part of the dynamic programming algorithm.

The function `parenthesization()` outputs the final result: a parenthesized expression yielding the goal, or "No parenthesization possible." if no such parenthesization exists.
