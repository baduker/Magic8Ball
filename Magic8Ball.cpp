#include "Magic8Ball.h"
#include <iostream>

Magic8Ball::Magic8Ball () {};

void Magic8Ball::ShowLogo () {
    ClearScreen();
    std::cout << std::endl;
    std::cout << "\t  _____ _            __  __             _      \n";
    std::cout << "\t |_   _| |__   ___  |  \\/  | __ _  __ _(_) ___ \n";
    std::cout << "\t   | | | '_ \\ / _ \\ | |\\/| |/ _` |/ _` | |/ __|\n";
    std::cout << "\t   | | | | | |  __/ | |  | | (_| | (_| | | (__ \n";
    std::cout << "\t   |_| |_| |_ \\___| |_|  |_|\\__,_|\\__, |_|\\___|\n";
    std::cout << "\t                                   |___/       \n";
    std::cout << "\t\t         ____\n";
    std::cout << "\t\t     ,dP9CGG88@b,\n";
    std::cout << "\t\t   ,IP  _   Y888@@b,\n";
    std::cout << "\t\t  dIi  (_)   G8888@b\n";
    std::cout << "\t\t dCII  (_)   G8888@@b\n";
    std::cout << "\t\t GCCIi     ,GG8888@@@\n";
    std::cout << "\t\t GGCCCCCCCGGG88888@@@\n";
    std::cout << "\t\t GGGGCCCGGGG88888@@@@...\n";
    std::cout << "\t\t Y8GGGGGG8888888@@@@P.....\n";
    std::cout << "\t\t  Y88888888888@@@@@P......\n";
    std::cout << "\t\t  `Y8888888@@@@@@@P'......\n";
    std::cout << "\t\t     `@@@@@@@@@P'.......\n";
    std::cout << "\t\t        \"\"\"\"........\n";
    std::cout << "\t\t  ___    ____        _ _ \n";
    std::cout << "\t\t ( _ )  | __ )  __ _| | |\n";
    std::cout << "\t\t / _ \\  |  _ \\ / _` | | |\n";
    std::cout << "\t\t| (_) | | |_) | (_| | | |\n";
    std::cout << "\t\t \\___/  |____/ \\__,_|_|_|\n";
    std::cout << std::endl;
    std::cout << "\t\tNot sure about your future? Fear not!\n";
    std::cout << "\t\tThe Magic 8 Ball is hear to help you.\n";
    std::cout << "\n\t\tThink of a YES-NO question and\n" << "\t\tpress ENTER to shake the Magic 8 Ball.\n\n";
    PressEnter();
}

void Magic8Ball::ShowLogoOnExit () {
    ClearScreen();
    std::cout << "\n";
    std::cout << "\t           .-----------.\n";
    std::cout << "\t        ,-              '-.\n";
    std::cout << "\t     ,-'    The Magic      '-.\n";
    std::cout << "\t    /                         \\\n";
    std::cout << "\t  ,'         .d8888b.          `.\n";
    std::cout << "\t ;          d88P  Y88b           :\n";
    std::cout << "\t ;          Y88b. d88P           :\n";
    std::cout << "\t;            \"Y88888\"             :\n";
    std::cout << "\t|           .d8P\"\"Y8b.            |\n";
    std::cout << "\t|           888    888            |\n";
    std::cout << "\t:           Y88b  d88P            ;\n";
    std::cout << "\t :           \"Y8888P\"            ;\n";
    std::cout << "\t :                               ; \n";
    std::cout << "\t  \\            Ball              /\n";
    std::cout << "\t   `.                          ,'\n";
    std::cout << "\t     \\       Version:        /\n";
    std::cout << "\t      '-.      0.2.6      ,-'\n";
    std::cout << "\t        '-.            ,-'        \n";
    std::cout << "\t            `---------'            \n";
    std::cout << "\t\tMade with a keyboard & CLion\n";
    std::cout << "\t\t(c) Noob Code, 2017\n\n";
    std::cout << std::endl;
}

void Magic8Ball::Shake8Ball() {
    srand(time(NULL));
    int Random8BallAnswer; // local variable to run the mutator
    Random8BallAnswer = rand() % (0 - 33);
    /* The mutator "engine" picks a random number between 0 and 33 to match
     * the size of the array which stores the default 8 Ball answers. */
    The8BallAnswer = Default8BallAnswers[Random8BallAnswer];
    /* This converts the randomly selected array value
     * to the string and outputs it as the 8 Ball answer */
}

std::string Magic8Ball::GetTheReply() {
    ClearScreen();
    std::cout << "\t _____ _             ___                         \n";
    std::cout << "\t|_   _| |__   ___   ( _ )   ___  __ _ _   _ ___  \n";
    std::cout << "\t  | | | '_ \\ / _ \\  / _ \\  / __|/ _` | | | / __| \n";
    std::cout << "\t  | | | | | |  __/ | (_) | \\__ \\ (_| | |_| \\__ \\ \n";
    std::cout << "\t  |_| |_| |_|\\___|  \\___/  |___/\\__,_|\\__, |___/ \n";
    std::cout << "\t                                       |___/      \n";
    std::cout << "\n\t\t--> " << The8BallAnswer;
    std::cout << std::endl;
    return The8BallAnswer;
}

bool Magic8Ball::Ask8BallAgain() {
    std::cout << "\n\t\tShake the 8 Ball again?\n";
    std::cout << "\t\t[S]hake it again or [Q]uit it!\n";
    std::cout << "\t\t";
    std::string key;
    std::getline(std::cin, key);
    if (key[0] == 's' || key[0] == 'S')
    {
        ClearScreen();
        return (true);
    }
    else if (key[0] == 'q' || key[0] == 'Q') {
        ClearScreen();
        ShowLogoOnExit();
        return (false);
        }
    else
        ClearScreen();
        std::cout << "\n\tWARNING!\n";
        std::cout << "\n\tThe 8 Ball doesn't understand the command.\n";
        std::cout << "\tPlease, try again.\n";
    return Ask8BallAgain();
    }

void Magic8Ball::ClearScreen () { std::cout << "\033[2J\033[1;1H"; }

void Magic8Ball::PressEnter () {
    std::string temp;
    std::cout << "\t\tReady?";
    std::cin.ignore(std::numeric_limits<char>::max(), '\n');
    ClearScreen();
}

//This function encapsulates the entire program
void DoMagic () {
    Magic8Ball My8Ball;

    My8Ball.ShowLogo();
    do {
        My8Ball.Shake8Ball();
        My8Ball.GetTheReply();
    } while (My8Ball.Ask8BallAgain());
}