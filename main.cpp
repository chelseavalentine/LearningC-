//
//  main.cpp
//  cp1
//
//  Created by Chelsea Valentine on 12/5/15.
//  Copyright © 2015 Chelsea Valentine. All rights reserved.
//

#include <iostream> // allows us to do input/output
#include <string> // if we want to use strings, we actually need to import it! unlike java
#include <cstdlib> // allows us to generate random numbers
#include <ctime> // allows us to work w/ time

using namespace std; // !!! this line lets us used shortened forms of the commands. Forget std::cout, just use cout.

int hi; // we have a global variable here

// we can declare functions before we define them, so we can define them anywhere;
// "function prototype"
void chapter2(), chapter3(), chapter4(), chapter5(), chapter7(), chapter8(), chapter10(), chapter11(), chapter13();


// our main function, which returns an integer
// it isn't necessary to have any arguments for it to still be our main function
int main(int argc, const char * argv[]) {
    chapter13();

    // cin.get(); // program waits for you to press a key before exiting, essentially C get input

    // In C++, you need to have your main function return something.
    // returning 0 because program successfully completed
    return 0;
}

void chapter13() {
    // using pointers
    int x = 5;
    int *p_x = & x;
    // memory address of x
    cout << p_x << endl;
    // value stored in x
    cout << *p_x;
    // change value stored at memory address
    *p_x = 7;
    cout << endl << "now it is " << *p_x << endl;
}

struct Person {
    string name;
    int age;
    double height;

    Person() {
        cout << "hello" << endl;
    }
};

// A copy of the structure's value is made. The actual structure isn't passed in, so we return the structure to get
// the changed version
Person makeOlder(Person person) {
    if (person.age > 150) return person;
    person.age++;
    return person;
}

void chapter11() {
    Person me;
    me.name = "Chelsea";
    me.age = 18;
    me.height = 162.56;

    cout << "Before my birtday, I was " << me.age << endl;
    cout << "After my birthday, I'm " <<  makeOlder(me).age << endl;
}

// for multi-dimensional arrays, you need to specify all sizes except for the 1st one
void changeThisArray(string array[][10], int firstSize);

// for single-dimensional arrays, you don't need to specify a size
void changeThisArray(string array[], int arraySize) {
    for (int i = 0; i < arraySize; i++)
        cout << array[i] + "." << endl;
}

void chapter10() {
    // array declarations:
    // type name[capacity]
    int array[10];

    // accessing an array:
    array[3] = 10;
    cout << array[3] << endl;

    // 2-dimensional array
    string strings[10];
    strings[0] = "hi";

    cout << strings[0] << endl;

    changeThisArray(strings, 10);
}

int randRange(int low, int high) {
    // random number b/t 0 & the number of values in the range + the lowest possible value
    // add 1 to high - low b/c 10-0 has 11 possible values, adding 1 gives us the total values in the range, not just
    // the difference
    return rand() % (high - low + 1) + low;
}

int randRange(int high) {
    return rand() % (high);
}

void chapter8() {
    // just call srand() once, at the very beginning
    // the current time is usually used as the seed for the random numbers
    // we're using an unsigned integer here because we always want it to be positive
    // unsigned integers are 2x as high in magnitude than signed integers, since the left-most bit,
    // which typically indicates positive or negative can be used to store a 1

    // range of int: –2,147,483,648 to 2,147,483,647
    // range of unsigned int: 0 to 4,294,967,295
    srand((unsigned int) time(NULL));

    cout << rand() << endl;
    cout << randRange(500) << endl;
    cout << randRange(100, 500) << endl;
}

void chapter7() {
    // We've created a custom variable type, Color, which has a
    // fixed ("enumerated") list of values

    // Each value is prefixed with a capital C in case the name is
    // used in another enum
    enum Color {
        C_RED = 1,
        C_ORANGE = 2,
        C_YELLOW = 3,
        C_GREEN = 4,
        C_BLUE = 5,
        C_INDIGO = 6,
        C_VIOLET = 7
    };

    // if we don't assign values, it'll assign them integers starting from 0
    enum Color2 {
        C2_RED,
        C2_ORANGE,
        C2_YELLOW,
        C2_GREEN,
        C2_BLUE,
        C2_INDIGO,
        C2_VIOLET
    };

    Color primaryColor = C_RED;

    // we can be sure that we're using all values that primaryColor could take on, since it is an enum
    switch (primaryColor) {
        case C_RED:
            primaryColor = C_ORANGE;
            cout << primaryColor << endl;
        case C_ORANGE:
            primaryColor = C_YELLOW;
            cout << primaryColor << endl;
        case C_YELLOW:
            primaryColor = C_GREEN;
            cout << primaryColor << endl;
        case C_GREEN:
            primaryColor = C_BLUE;
            cout << primaryColor << endl;
        case C_BLUE:
            primaryColor = C_INDIGO;
            cout << primaryColor << endl;
        case C_INDIGO:
            primaryColor = C_VIOLET;
        case C_VIOLET:
            cout << primaryColor << endl;
            cout << "and we're out of this switch statement~" << endl;
            break;
    }
}

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
