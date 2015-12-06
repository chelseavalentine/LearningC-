//
//  main.cpp
//  cp1
//
//  Created by Chelsea Valentine on 12/5/15.
//  Copyright © 2015 Chelsea Valentine. All rights reserved.
//

#include <iostream> // allows us to do input/output
#include <string> // if we want to use strings, we actually need to import it! unlike java

using namespace std; // !!! this line lets us used shortened forms of the commands. Forget std::cout, just use cout.

int hi; // we have a global variable here

// we can declare functions before we define them, so we can define them anywhere;
// "function prototype"
void chapter2(), chapter3(), chapter4(), chapter5(), chapter7();


// our main function, which returns an integer
// it isn't necessary to have any arguments for it to still be our main function
int main(int argc, const char * argv[]) {
    chapter7();
    // cin.get(); // program waits for you to press a key before exiting, essentially C get input

    // In C++, you need to have your main function return something.
    // returning 0 because program successfully completed
    return 0;
}

void chapter7() {}

void chapter5() {
    // do-while loops are ended w/ a semicolon
    do {
        cout << "hi";
    } while (false);
}

void chapter4() {
    if (1) cout << "out" << endl << endl;
    if (/* DISABLES CODE */ (0)) cout << "this will never execute~"; // the comment is there to silence the warning.

    // in c++, booleans are called:
    bool to_be_or_not_to_be = 0 == 1;
    if (to_be_or_not_to_be) cout << "hi" << endl << endl;
    else if (to_be_or_not_to_be == false) cout << "uhh" << endl << endl;
    else cout << "bye" << endl << endl;
}

void chapter3() {
    int basic1, soBasic;
    char basic2, multiple, variables, declared, onThe, sameLine;
    double basic3 = 10.1;

    cout << "Give the user some instructions of what to enter." << endl << endl << "In this case, please enter an integer.";
    cin >> basic1;

    // this code will never execute, because the data is always interpreted as some integer
    if (basic1 == 'e') {
        cout << "Lol they gave the wrong info";

        // just going to use these variables to surpress warnings
        soBasic = 0;
        basic2 = multiple = variables = declared = onThe = sameLine = 0;
        basic3 = 0.0;
    }

    cout << "As we can see, the user entered " << basic1 << endl;

    // Even if the user doesn't enter info of the correct data type, it'll default to a value.
    // Eg. entering 'e' when asked for a
    // number was interpreted as entering 0. So you should check that they're entering the right thing.

    soBasic = 0;
    cout << "Original value of variable 'soBasic' " << soBasic << endl;
    cout << "When we print soBasic++ " << soBasic++ << endl;
    cout << "After trying to print that and getting the same number, we can see that soBasic has actually changed to "
    << soBasic << endl << endl;

    cout << "Why? the ++ is executed after getting the value of the variable." << endl;
    cout << "Doing ++soBasic will give us 1 right away" << endl;

    string stringalicious;
    cout << "Enter a string:";
    cin >> stringalicious;

    // What did the user enter? Let's see...
    // a source of input, the string to read in, the character to break at
    getline(cin, stringalicious, ',');

    cout << "Let's redefine our string to be 'Hey\nThere', and then try getting lines w/ the new line separator" << endl << endl;

//    stringalicious = "Hey\nThere";

    string string1;
    cout << "Let's get string1" << endl;
    getline(cin, string1, '\n');
    cin.get();

    /*
     * That didn't work, because getline as we have it right now doesn't read a string we already have stored,
     * it is waiting for a new input and breaks it at the \n. It's looking for input twice, and uses the same
     * string to put them in, so stringalicious is overwritten.
     *
     * it waits for two lines of input because there are two calls to the getline function made.
     * Let's see the last thing we wrote:
     */

    cout << "Stringalicious is now...." << stringalicious;

    /*
     * Even though we sequentially are trying to get input for stringalicious, and then string1, because
     * we aren't using whatever stringalicious was assigned to yet, the code between using getline & actually
     * using what is gotten is not executed.
     * Once we've finished getting the line, wherever stringalicious is used is executed, then the code
     * in-between is executed
     */

    // this doesn't work as expected, so handle whatever you got from one input source close to where you got it
    // don't ask for multiple inputs at once
    cout << "Now we can see what string1 was " << string1 << endl;

    float floaty = 1.2;
    cout << floaty << " floating point numbers have 15 digits of precision. That's the most the computer stores for you";
    cout << "\n it can store a number w/ 308 zeros though. But it uses scientific notation." << endl << endl;

    // just like java, '/' allows does integer division or floating point division depending on what you input
    cout << " 5 / 2 is " << 5/2 << endl;
    cout << " 5 / 2.0 is " << 5/2.0 << endl;
    cout << " 5.0 / 2 is " << 5.0/2 << endl;

    /* reads and discards a character (eg. user pressing the enter key)
     * Why is this useful? Because we want to keep cin.get() available to keep the program from exiting before
     * the user inputs something
     */
    cin.ignore();
    cin.get();
}

void chapter2() {
    std::cout << "Why are there two angled brackets?\n";
    std::cout << "Weird. If I don't include the angled brackets, then it marks it as an error.\n\n";

    std::cout << "Surely there has to be a way to display strings as multiline strings within the text editor?\n";

    /* C out
     * insertion operators << to make a function  call w/ the "yay for namespaces" text w/ a new line
     */
    cout << "Yay for namespaces.\n";

    // equivalently,
    cout << "Yay for namespaces." << endl;
    cout << endl << "Yay for namespaces." << endl << "with your second line here";
}

