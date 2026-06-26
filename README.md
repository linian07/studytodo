# StudyTodo

StudyTodo is a simple command-line todo list program written in C++.

This is my first C++ project. I built it to practice basic C++ programming, file organization, classes, vectors, file I/O, and simple project structure.

## Features

- Add tasks
- View all tasks
- Mark tasks as done
- Delete tasks
- Set task priority
- View tasks by priority
- Save tasks to a local file
- Load saved tasks when the program starts
- Validate menu input

## Priority Levels

StudyTodo supports three priority levels:

```text
1 = Low
2 = Medium
3 = High
```

Example task list:

```text
My Task List
1. [ ] [High] Finish C++ homework
2. [x] [Medium] Review English words
3. [ ] [Low] Read a book
```

## Project Structure

```text
StudyTodo/
├── main.cpp
├── Task.h
├── TaskManager.h
├── TaskManager.cpp
├── Menu.h
├── Menu.cpp
├── README.md
└── .gitignore
```

## Build

Use a C++ compiler such as `g++`:

```bash
g++ main.cpp TaskManager.cpp Menu.cpp -o StudyTodo
```

## Run

On Windows:

```bash
StudyTodo.exe
```

On macOS/Linux:

```bash
./StudyTodo
```

## Data Storage

Tasks are saved in a local file named:

```text
tasks.txt
```

This file is generated automatically when the program runs. It is not included in the GitHub repository because it contains user-specific data.

## What I Learned

Through this project, I practiced:

- `struct`
- `class`
- `vector`
- `string`
- file input and output
- functions
- header files and source files
- simple input validation
- basic project organization

## Future Improvements

- Search tasks by keyword
- Edit existing tasks
- Clear completed tasks
- Add due dates
- Add categories
- Use CMake to build the project
- Add simple unit tests

## About

This project is a beginner-friendly C++ command-line application. It was created as my first GitHub project to practice turning small pieces of code into a structured project.
