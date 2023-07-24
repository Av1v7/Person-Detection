# Letting you 
- **This project was carefully designed to efficiently search for people within Israel's comprehensive database, using the .csv file format. However, the software's versatility allows for seamless integration with any preferred database. Enjoy the smooth experience!**

---

# DetectPerson

DetectPerson is a C++ command-line application that reads data from a CSV or text file containing information about individuals and allows the user to search for specific persons based on their first name, last name, and city. The application displays the details of the matching person(s) if found.

## Getting Started

### Prerequisites

- C++ compiler (GCC or Clang recommended)
- CMake (optional but recommended for building)

### How to Build

You can build the project using CMake or any C++ compiler that supports C++11 or later.

#### Using CMake (Recommended)

1. Make sure you have CMake installed on your system.
2. Clone this repository.
3. Navigate to the project directory.
4. Create a `build` directory: `mkdir build`
5. Enter the `build` directory: `cd build`
6. Generate the build files: `cmake ..`
7. Build the project: `cmake --build .`

#### Using C++ Compiler

1. Clone this repository.
2. Navigate to the project directory.
3. Compile the source files: `g++ -std=c++11 main.cpp detectInfo.cpp -o DetectPerson`

### Usage

1. Make sure the data file (`Details.csv` or `Details.txt`) is in the same directory as the executable.
2. Run the program: `./DetectPerson`
3. Follow the prompts to enter the first name, last name, and city of the person you want to search for.
4. The program will display the details of the matching person(s) if found.

### Data File Format

The data file (CSV or text) should have the following format:
```csv
Age,First Name,Last Name,City,Profession,NumberOfKids
16,Aviv,Shemesh,Ganei Tikva,Studant,2
30,John,Doe,New York,Engineer,1
28,Jane,Smith,Los Angeles,Teacher,3
35,Michael,Johnson,Chicago,Doctor,3
25,Emily,Brown,New York,Artist,4
42,David,Miller,Seattle,Architect,2
37,Susan,Williams,Miami,Lawyer,0
22,Andrew,Lee,San Francisco,Software Engineer,0
45,Linda,Clark,Dallas,Accountant,2
```

### Contributing

Contributions are welcome! If you find any issues or have suggestions for improvement, feel free to create an issue or submit a pull request.

### License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
