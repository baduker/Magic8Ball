//
// Created by Baduker on 04/09/2017.
//

#include "Magic8Ball.h"
#include <iostream>

Magic8Ball::Magic8Ball() {}

void Magic8Ball::PrintInfo() {
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
    std::cout << "\tThe Magic 8 Ball v. 0.2\n";
    std::cout << "\t(c) Noob Code, 2017\n\n";
    std::cout << "\tNot sure about your future? Fear not!\n";
    std::cout << "\tThe Magic 8 Ball is hear to help you!\n";
}

void Magic8Ball::AskTheUser() {
    std::string user_question;
    std::cout << "\n\tAsk the 8 Ball a YES-NO question: ";
    std::getline(std::cin, user_question); // TODO Add user input error handling
}

void Magic8Ball::Shake8Ball() {
    srand((unsigned) time(NULL));
    int Random8BallAnswer; // local variable to run the mutator
    Random8BallAnswer = rand() % Default8BallAnswers->size(); // the mutator "engine"
    The8BallAnswer = Default8BallAnswers[Random8BallAnswer]; // converts the array value to the string
}

std::string Magic8Ball::GetTheReply() {
    std::cout << "\n\t" << The8BallAnswer; // TODO in future versions reformat the answer in form of an ASCII art
    std::cout << std::endl;
    return The8BallAnswer;
}

bool Magic8Ball::Ask8BallAgain() {
    std::cout << "\n\tWould you like to ask the Magic 8 Ball again? (YES / NO) ";
    std::string response;
    std::getline(std::cin, response);
    if (response[0] == 'y' || response[0] == 'Y')
    {
        return (true);
    }
    else if (response[0] == 'n' || response[0] == 'N')
    {
        std::cout << "\n\tTHANK YOU!\n";
        std::cout << "\tThe Magic 8 Ball wishes you luck!\n";
        std::cout << "\n\tPress any key to exit.\n";
        std::cin.ignore();
        return (false);
    }
    else {
        std::cout << "\n\tWrong answer! Please type YES or NO";
        return (Magic8Ball::Ask8BallAgain());
    }
}

