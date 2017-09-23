//
// Created by Baduker on 04/09/2017.
//

#include "Magic8Ball.h"
#include <iostream>

Magic8Ball::Magic8Ball() {}

void Magic8Ball::ShowLogo () {
    ClearScreen();
    std::cout << "\n";
    std::cout << "\tThe Magic 8 ball predicts the future!\n";
    std::cout << "\t         ____\n";
    std::cout << "\t     ,dP9CGG88@b,\n";
    std::cout << "\t   ,IP  _   Y888@@b,\n";
    std::cout << "\t  dIi  (_)   G8888@b\n";
    std::cout << "\t dCII  (_)   G8888@@b\n";
    std::cout << "\t GCCIi     ,GG8888@@@\n";
    std::cout << "\t GGCCCCCCCGGG88888@@@\n";
    std::cout << "\t GGGGCCCGGGG88888@@@@...\n";
    std::cout << "\t Y8GGGGGG8888888@@@@P.....\n";
    std::cout << "\t  Y88888888888@@@@@P......\n";
    std::cout << "\t  `Y8888888@@@@@@@P'......\n";
    std::cout << "\t     `@@@@@@@@@P'.......\n";
    std::cout << "\t        \"\"\"\"........\n";
    std::cout << "\n";
    std::cout << "\tThe Magic 8 Ball v. 0.2.2\n";
    std::cout << "\t(c) Noob Code, 2017\n\n";

    PressEnter();

}

void Magic8Ball::Shake8Ball() { // TODO if more 'answer' arrays added write a feature to pick them
    srand((unsigned) time(NULL));
    int Random8BallAnswer; // local variable to run the mutator
    Random8BallAnswer = rand() % Default8BallAnswers->size(); // the mutator "engine"
    The8BallAnswer = Default8BallAnswers[Random8BallAnswer]; // converts the array value to the string
}

std::string Magic8Ball::GetTheReply() {
    ClearScreen();
    std::cout << "\n\t" << The8BallAnswer; // TODO in future versions reformat the answer in form of an ASCII art
    std::cout << std::endl;
    return The8BallAnswer;
}

bool Magic8Ball::Ask8BallAgain() {
    std::cout << "\n\tShake the 8 Ball again?\n";
    std::cout << "\t[S]hake it again or [Q]uit it!\n";
    std::cout << "\t";
    std::string key;
    std::getline(std::cin, key);
    if (key[0] == 's' || key[0] == 'S')
    {
        ClearScreen();
        return (true);
    }
    else if (key[0] == 'q' || key[0] == 'Q') {
        ClearScreen();
        std::cout << "\n\tTHANK YOU!\n";
        std::cout << "\tThe Magic 8 Ball wishes you luck!\n";
        std::cout << "\n\tPress any key to exit.\n";
        std::cin.ignore();
        return (false);
        }
    else
        std::cout << "\tThe 8 Ball doesn't understand the command.\n";
        std::cout << "\tTry again.";
    return Ask8BallAgain();
    }


void Magic8Ball::ClearScreen () { std::cout << "\033[2J\033[1;1H"; }

void Magic8Ball::PressEnter () {
    std::string temp;
    std::cout << "\tPress ENTER to continue...";
    std::cin.ignore(std::numeric_limits<char>::max(), '\n');
    ClearScreen();
}

void Magic8Ball::PrintInfo () {

    std::cout << "\tNot sure about your future? Fear not!\n";
    std::cout << "\tThe Magic 8 Ball is hear to help you!\n";
    std::cout << "\n\tThink of a yes-no question and press ENTER to shake the 8 Ball\n\n";
    PressEnter();
    ClearScreen();
}

