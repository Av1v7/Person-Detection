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
2. **Important: The data file must contain the columns "Person_ID," "First Name," and "Last Name" for the application to work correctly.**
3. Run the program: `./DetectPerson`
4. Follow the prompts to enter the first name, last name, and city of the person you want to search for.
5. The program will display the details of the matching person(s) if found

### Data File Format

The data file (CSV or text) should have the following format:
```csv
Person_ID,User Id,First Name,Last Name,City,Sex,Email,Phone,Date of birth,Job Title
1,Cb68eBe7FfDd15f,Nora,Castillo,Philadelphia,Female,nbrowning@example.net,1-527-173-5520x870,1955-11-01,Chef
2,3d5AD30A4cD38ed,Jo,Rivers,Tel Aviv,Female,fergusonkatherine@example.net,+1-950-759-8687,1931-07-26,Dancer
3,810Ce0F276Badec,Sheryl,Lowery,Los Angeles,Female,fhoward@example.org,(599)782-0605,2013-11-25,Copy
4,BF2a889C00f0cE1,Whitney,Hooper,Chicago,Male,zjohnston@example.com,+1-939-130-6258,2012-11-17,Counselling psychologist
5,9afFEafAe1CBBB9,Lindsey,Rice,Miami,Female,elin@example.net,(390)417-1635x3010,1923-04-15,Biomedical engineer
6,aF75e6dDEBC5b66,Sherry,Caldwell,Seattle,Male,kaitlin13@example.net,8537800927,1917-08-06,Higher education lecturer
7,efeb05c7Cc94EA3,Ernest,Hoffman,Boston,Male,jeffharvey@example.com,093.655.7480x7895,1984-12-22,Health visitor
8,fb1BF3FED57E9d7,Doris,Andersen,San Francisco,Male,alicia33@example.org,4709522945,2016-12-02,Air broker
9,421fAB9a3b98F30,Cheryl,Mays,Dallas,Male,jake50@example.com,013.820.4758,2012-12-16,"Designer, multimedia"
10,4A42Fe10dB717CB,Harry,Mitchell,Houston,Male,lanechristina@example.net,(560)903-5068x4985,1953-06-29,Insurance account manager
```

### Contributing

Contributions are welcome! If you find any issues or have suggestions for improvement, feel free to create an issue or submit a pull request.

### License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
