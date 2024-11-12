# The Producer-Consumer Problem: A Solution in C++

![C++](https://img.shields.io/badge/C++-20%2B-green?logo=c++)
![Build](https://img.shields.io/badge/build-manual-lightgrey)
[![Docs](https://img.shields.io/badge/doc-Doxygen-purple)](./doc/index.html)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

This project implements a solution to the well-known [producer-consumer](https://en.wikipedia.org/wiki/Producer–consumer_problem) problem using synchronized methods. In Java, synchronized methods implement monitors to ensure mutual exclusion among concurrent threads when executing methods. These threads are also condition-synchronized; they can be suspended or notified to resume execution under certain conditions.

## 📝 The Producer-Consumer Problem

The producer-consumer problem refers to a data area (a bounded buffer) shared by two types of processes, producers and consumers. Producers generate and insert new elements into the shared buffer, while consumers remove and consume elements from it. The following constraints must also be satisfied:

* Only one operation (insertion or removal of elements into/from the buffer) can be performed at a time
* Producers cannot insert new elements when the buffer is full: they must be suspended
* Consumers cannot remove elements when the buffer is empty: they must be suspended
* Elements must be removed in the same order in which they were inserted

This solution implements the insertion and removal operations as synchronized methods, ensuring they execute under mutual exclusion. When the buffer is full, suspend producer threads. If it is possible to add a new element to the buffer, notify a suspended consumer thread to resume execution. Conversely, when the buffer is empty, consumer threads should be suspended. If it is possible to remove an element from the buffer, notify a suspended producer thread to resume execution.

## 📂 Repository structure

Source code in this repository is organized as follows:

```text
+─cpp-producerconsumer
  ├─── doc                  # Directory where HTML documentation will be generated
  ├─── Doxyfile             # Doxygen configuration
  └─── include              # Directory with header files
       └─── buffer.h        # Definition of the shared buffer
       └─── consumer.h      # Definition of the consumer thread
       └─── producer.h      # Definition of the producer thread
  └─── src                  # Directory with source code files
       └─── buffer.cpp      # Implementation of the shared buffer and the synchronized operations on it
       └─── consumer.cpp    # Implementation of the consumer thread
       └─── producer.cpp    # Implementation of the producer thread
  └─── main.cpp             # Main program
  └─── Makefile
    
```

## 🚀 Getting Started

### ✅ Prerequisites

* A C++ compiler with C++20 support, such as GCC 15 or a recent Clang
* A terminal or IDE
* GNU Make for the Makefile targets
* [Doxygen](https://www.doxygen.nl), only if you want to generate the HTML documentation

The Makefile currently sets `CC=g++-15`, so that command must exist on `PATH` when building C++ examples through `make`.

### 🔧 Compilation

Inside the project root, compile all sources from the [Makefile](Makefile):

```bash
make
```

This creates the compiled object files in the `build/` directory and the `producerconsumer` executable in the `bin` directory.

### ▶️ Running

```bash
./bin/producerconsumer
```

## Generate documentation

The [`Doxyfile`](Doxyfile) specifies `src` as the input and `doc/` as the HTML output directory. Use this configuration rather than running `doxygen -g`, which creates a new default configuration file.

With Doxygen installed, regenerate the documentation with either command:

```bash
make doc
# or
doxygen Doxyfile
```

Open [`doc/index.html`](doc/index.html). The generated `doc/` files are build artifacts; Doxygen comments in the source files provide the documentation content.

## Clean generated files

Remove compiled objects and executables with:

```bash
make clean
```

This removes compiled objects and the executables.

## 🤝 Contributing

Contributions are welcome! Fork this repository and submit a pull request 🚀