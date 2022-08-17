// manipulating the files with iostream
#include <iostream>
#include <fstream>
using namespace std;

// IOstreams can also be used with files.
// It's really quite straightforward.

int main(int argc, char **argv)
{
    static int lineno = 0;
    static const char *filename = "test.txt";
    static const char *textstring = "This is the test file.";

    // write a file
    // We open an output file for write, using "ofstream".
    // and we can notice that we included here "fstream" header.
    cout << "write the file " << endl;
    // And we're creating this object ofile,
    // and we give it the file name,
    // which is a cstring file name.
    ofstream ofile(filename);
    // And our textstring here is also a cstring,
    // and so we have an integer line number
    // that starts at one because it's been initialized to zero
    // and we're using pre-increment here.
    ofile << ++lineno << " " << textstring << endl;
    ofile << ++lineno << " " << textstring << endl;
    ofile << ++lineno << " " << textstring << endl;
    // We're writing it to this outfile,
    // and then we close the file with ofile.close().
    ofile.close();

    // read a file
    static char buf[128];
    cout << "read the file:" << endl;
    // And then we open the file for reading,
    // using "ifstream", and we create an ifstreamobject called infile
    // with the same file name.
    ifstream infile(filename);
    // And we use infile.good() to tell us
    // that we can still read from the file.
    // So, as long as we can read from the file and
    // we haven't got to the end of the file, that will remain true.
    while (infile.good())
    {
        // And then we're using getline()
        // to read into the static character buffer.
        infile.getline(buf, sizeof(buf));
        // And then "cout" the result.
        cout << buf << endl;
    }
    // And we close the infile.
    infile.close();

    // delete file
    // And then we delete the file
    // with the standard library "remove()" function.
    cout << "delete file." << endl;
    remove(filename); // delete file

    // So, this is really really simple and straightforward.
    // And all of the formatting works
    // exactly the same with the ofstream as it does with cout.

    // So, the iostream library is very useful for
    // basic generalized IO, including interfacing
    // with the console and writing to and reading files.
    // For more control, we may use the C standard
    // library functions for reading and writing files.

    return 0;
}
