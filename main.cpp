/*----------------------------------------------
 * Program 1: Proj 1: Building
 *
 * Class: CS 141, Spring 2020. Tue 4pm lab
 * System: CLion on Windows 10
 * Author: Shawn Klein
 *
 * Custom ascii: Douglas Engelbart during his 1968 demonstration.
 *
 * p[je.w                  |         gggggg__
 * dwa, p;pw8j             |        R7FFFFFF77R
 *    apwf adjmwo          |       P ___  ___  R
 * wd wdajplu              |      P  <@>  <@>  P
 * wd apkcduie             |    ||      |      |
 * dwad                    |      \-+ ====   J
 * dwpaokef                |       `--------`
 * dwapwoah1               |       /         \
 *
 * Reference:
 * https://arstechnica.com/gaming/2015/04/from-the-vault-watching-and-re-watching-the-mother-of-all-demos/
 *
 * ---------------------------------------------
 */

#include <iostream>
using namespace std;

// Takes a number and character, and returns a string of
// that charater the number of times as the given number
string repeatChar(int n, char ch){
    string str;
    string s(1, ch);

    for (int i = 0; i < n; ++i) {
        str.append(s);
    }

    return str;
}

// Output to terminal Doug Engelbart at his famous 1968 demonstration.
void demoDougEngelbart() {
    string doug[8] =  {"pdje.w                  |         gggggg__         ",
                       "dwa, plpw8j             |        R7FFFFFF77R       ",
                       "  apwf adj@mwo          |       P ___  ___  R      ",
                       "wd wdajplu              |      P  <@>  <@>  P      ",
                       "ke a2kcduie             |    ||      |      |      ",
                       "rw#d                    |      \\-+ ====   J       ",
                       "lsmao9ef                |       `--------`         ",
                       "p7np%woh1               |       /         \\       "};

    // This is a demand from the client to use one loop
    for (int i = 0; i < 8; ++i) {
         cout << doug[i] << endl;
    }
}

// Takes number of sections in spire and
// outputs to terminal the top of the spire
void spireTop(int sections) {
    string whitespace = repeatChar(sections + 1, ' ');

    cout << whitespace << " /\\\n"
         << whitespace << " ||\n"
         << whitespace << " ||\n"
         << whitespace << " --\n"
         << whitespace << "|++|\n"
         << whitespace << "====" << endl;
}

// Takes the current section number and total number of sections,
// and outputs that section to the appropriate place in text
void spireMid(int section, int sections) {
    int width = section * 2;
    int height = section * 2;
    string extSpaces = repeatChar((sections - section + 2), ' ');

    for (int h = 0; h < height; ++h) {
        cout << extSpaces << "|";
        string intSpaces = repeatChar(width, ':');
        intSpaces[h] = '\\';
        intSpaces[height-1-h] = '/';
        cout << intSpaces;
        cout << "|" << endl;
    }
    cout << extSpaces << "/" << repeatChar(width, '-') << "\\" << endl;
}

// Takes total number of sections and outputs
// to terminal the correct size base
void spireBase(int sections) {
    int numDots = (sections * 2) + 4;
    int numDashes = (sections * 2) + 6;

    cout << " " << repeatChar(numDots, '.') << "\n"
         << repeatChar(numDashes, '+') << endl;
}

// Prompts user from list of options, and
// displays the selected ascii to the terminal
int main() {
    int sections = 0;
    int asciiType = 0;

    cout << "Choose from among the following options:  \n"
         << "1. Display original graphic  \n"
         << "2. Display building          \n"
         << "3. Exit the program          \n"
         << "Your choice ->";
    cin >> asciiType;

    if (asciiType == 1) {
        demoDougEngelbart();
    } else if (asciiType == 2) {
        cout << "Number of building sections ->";
        cin >> sections;

        spireTop(sections);
        for (int i = 1; i < (sections + 1); ++i) {
            spireMid(i, sections);
        }
        spireBase(sections);
    }

    return 0;
}

