#include "Magic8Ball.h"
#include <iostream>
#include <thread>

Magic8Ball::Magic8Ball () = default;

void Magic8Ball::ShowLogo () {

    ClearScreen();
    TheMagic();
    The8();
    TheBall();

    wait_for = 1200;
    Sleep(wait_for);
    TheInfo_Part_One();

    wait_for = 2000;
    Sleep(wait_for);
    TheInfo_Part_Two();

    wait_for = 2400;
    Sleep(wait_for);
    PressEnter();
}

void Magic8Ball::ShowLogoOnExit () {
    ClearScreen();
    std::cout << "\t+---------------------------------+\n";
    std::cout << "\t|               the               |\n";
    std::cout << "\t|    __  __             _         |\n";
    std::cout << "\t|   |  \\/  | __ _  __ _(_) ___    |\n";
    std::cout << "\t|   | |\\/| |/ _` |/ _` | |/ __|   |\n";
    std::cout << "\t|   | |  | | (_| | (_| | | (__    |\n";
    std::cout << "\t|   |_|  |_|\\__,_|\\__, |_|\\___|   |\n";
    std::cout << "\t|                 |___/           |\n";
    std::cout << "\t|      ___    _           _ _     |\n";
    std::cout << "\t|     ( _ )  | |__   __ _| | |    |\n";
    std::cout << "\t|     / _ \\  | '_ \\ / _` | | |    |\n";
    std::cout << "\t|    | (_) | | |_) | (_| | | |    |\n";
    std::cout << "\t|     \\___/  |_.__/ \\__,_|_|_|    |\n";
    std::cout << "\t|                                 |\n";
    std::cout << "\t|  +-+-+-+-+-+-+-+-+ +-+-+-+-+-+  |\n";
    std::cout << "\t|  |V|E|R|S|I|O|N|:| |0|.|3|.|0|  |\n";
    std::cout << "\t|  +-+-+-+-+-+-+-+-+ +-+-+-+-+-+  |\n";
    std::cout << "\t|                                 |\n";
    std::cout << "\t|  made with a keyboard and CLion |\n";
    std::cout << "\t|       by NoobCode (c) 2017      |\n";
    std::cout << "\t|                                 |\n";
    std::cout << "\t+---------------------------------+\n";
    std::cout << std::endl;
}

void Magic8Ball::Shake8Ball () {
    srand(time(NULL));
    int Random8BallAnswer; // local variable to run the mutator
    Random8BallAnswer = rand() % (0 - 33);
    /* The mutator "engine" picks a random number between 0 and 33 to match
     * the size of the array which stores the default 8 Ball answers. */
    The8BallAnswer = Default8BallAnswers[Random8BallAnswer];
    /* This converts the randomly selected array value
     * to the string and outputs it as the 8 Ball answer */
    }

std::string Magic8Ball::GetTheReply () {
    ClearScreen();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\t#---the Magic 8 Ball says: ---#\n";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\t " << The8BallAnswer << " \n";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\t+---Shake the 8 Ball again?---+\n";
    std::cout << "\t|                             |\n";
    std::cout << "\t| [S]hake it again or [Q]uit! |\n";
    std::cout << "\t|                             |\n";
    std::cout << "\t+-----------------------------+\n";
    std::cout << std::endl;
    return The8BallAnswer;
}

bool Magic8Ball::Ask8BallAgain () {

    std::cout << "\t";
    char key;
    bool reply;

    std::cin >> key;

    while (std::cin.fail() || ((key != 's' && key != 'S') && (key != 'q' && key != 'Q'))) {
        std::cout << "\tThis looks like a typo. Try again.\n";
        std::cin.clear();
        std::cout << "\t";
        std::cin >> key;
    }

    if (key == 's' || key == 'S')
    {
        ClearScreen();
        reply = true;
    }
    else if (key == 'q' || key == 'Q') {
        ClearScreen();
        ShowLogoOnExit();
        reply = false;
    }

    return (reply);
    }

void Magic8Ball::ClearScreen () { std::cout << "\033[2J\033[1;1H"; }

void Magic8Ball::PressEnter () {
    std::string temp;
    std::cout << "\t\tAre you ready?\n\n";
    wait_for = 2000;
    Sleep (wait_for);
    std::cout << "\t\tPress ENTER to shake the Magic 8 Ball.\n";
    std::cout << "\t\t";
    std::cin.ignore(std::numeric_limits<char>::max(), '\n');
    ClearScreen();
}

void Magic8Ball::Sleep (int x) {
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

void Magic8Ball::TheMagic () {
    std::cout << std::endl;
    std::cout << "\t  _____ _            __  __             _      \n";
    std::cout << "\t |_   _| |__   ___  |  \\/  | __ _  __ _(_) ___ \n";
    std::cout << "\t   | | | '_ \\ / _ \\ | |\\/| |/ _` |/ _` | |/ __|\n";
    std::cout << "\t   | | | | | |  __/ | |  | | (_| | (_| | | (__ \n";
    std::cout << "\t   |_| |_| |_ \\___| |_|  |_|\\__,_|\\__, |_|\\___|\n";
    std::cout << "\t                                   |___/       \n";
}

void Magic8Ball::The8 () {
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
}

void Magic8Ball::TheBall () {
    std::cout << "\t\t  ___    ____        _ _ \n";
    std::cout << "\t\t ( _ )  | __ )  __ _| | |\n";
    std::cout << "\t\t / _ \\  |  _ \\ / _` | | |\n";
    std::cout << "\t\t| (_) | | |_) | (_| | | |\n";
    std::cout << "\t\t \\___/  |____/ \\__,_|_|_|\n";
    std::cout << std::endl;
}

void Magic8Ball::TheInfo_Part_One () {
    std::cout << "\t\tNot sure about your future? Fear not!\n";
    std::cout << "\t\tThe Magic 8 Ball is hear to help you.\n";
}

void Magic8Ball::TheInfo_Part_Two () {
    std::cout << "\n\t\tThink of a YES-NO question.\n\n";
}

//This function encapsulates the entire program
void DoMagic () {
    Magic8Ball My8Ball;

    bool reply;
    My8Ball.ShowLogo();
    do {
        My8Ball.Shake8Ball();
        My8Ball.GetTheReply();
        reply = My8Ball.Ask8BallAgain();
    } while (reply);
}
