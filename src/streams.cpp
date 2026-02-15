/*
streams converts objects to streams of bytes, and vice versa.
The arrow goes from the direction of the stream to the object, or vice-versa. The stream is always on the left.
fs >> s; from file stream to buffer
fs << s; from s to file stream


1. file streams
    are by default input file streams.
    to make it output file streams (that is, write to a file), use std::ios::out.

2. string streams
*/

#include <iostream>
#include <fstream> /*file stream.  ifstream - input file stream, ofstream - output file stream. fstream - input + output*/

using namespace std;

int main() {
    fstream fs {"streams.cpp"};
    string buffer;
    while ( getline(fs, buffer)) {
        cout << buffer << endl;
    }

    cout << "======================" << endl;
    fstream fs2 {"streams.cpp"};
    char c;
    while ( fs2 >> noskipws >> c) {
        cout << c;
    }

    fstream outfile{ "sample.txt", ios::out };
    outfile << "hello mark" << endl;
    outfile << "hello marla";
    outfile << endl;
    


    return 0;
}