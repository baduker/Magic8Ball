#include "Magic8Ball.h"
#include <iostream>
#include <thread>

Magic8Ball::Magic8Ball () = default;

// ASCII art for the word 'the Magic'
void Magic8Ball::TheMagic () {
    std::cout << std::endl;
    std::cout << "\t  _____ _            __  __             _      \n";
    std::cout << "\t |_   _| |__   ___  |  \\/  | __ _  __ _(_) ___ \n";
    std::cout << "\t   | | | '_ \\ / _ \\ | |\\/| |/ _` |/ _` | |/ __|\n";
    std::cout << "\t   | | | | | |  __/ | |  | | (_| | (_| | | (__ \n";
    std::cout << "\t   |_| |_| |_ \\___| |_|  |_|\\__,_|\\__, |_|\\___|\n";
    std::cout << "\t                                   |___/       \n";
}

// ASCII art for the 8 Ball
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

// ASCII art for the word 'Ball'
void Magic8Ball::TheBall () {
    std::cout << "\t\t  ___    ____        _ _ \n";
    std::cout << "\t\t ( _ )  | __ )  __ _| | |\n";
    std::cout << "\t\t / _ \\  |  _ \\ / _` | | |\n";
    std::cout << "\t\t| (_) | | |_) | (_| | | |\n";
    std::cout << "\t\t \\___/  |____/ \\__,_|_|_|\n";
    std::cout << std::endl;
}

// A short intro to the game split into two parts for timing effect
void Magic8Ball::The_Info_Part_One () {
    std::cout << "\t\tNot sure about your future? Fear not!\n";
    std::cout << "\t\tThe Magic 8 Ball is hear to help you.\n";
}
void Magic8Ball::The_Info_Part_Two () {
    std::cout << "\n\t\tThink of a YES-NO question.\n\n";
}

// Puts together all the ASCII art functions
void Magic8Ball::ShowLogo () {

    ClearScreen();
    TheMagic();
    The8();
    TheBall();
    // Pause for the first part of the introduction
    wait_for = 1200;
    Sleep(wait_for);
    The_Info_Part_One();
    // Pause for the second part of the introduction
    wait_for = 1800;
    Sleep(wait_for);
    The_Info_Part_Two();
    // Finally, ask if the user is ready to shake the ball
    wait_for = 2200;
    Sleep(wait_for);
    PressEnter();
}

// This is the engine for generating a random 8 Ball answer
int Magic8Ball::Shake8Ball () {

    /* The mutator "engine" picks a random number between 0 and 40 to match
    * the size of the array which stores the default 8 Ball answers. */
    srand(time(NULL));
    Random8BallAnswer = rand() % (0 - 40); // The range matches the size of the Default8BallAnswers array
    return Random8BallAnswer;
}

// The getter function that retrieves the randomly selected string from the Default8BallAnswer array
void Magic8Ball::GetTheReply () {

    /* This converts the randomly selected array value
     * to the string and outputs it as the 8 Ball answer */
    The8BallAnswer = pDefault8BallAnswers[*(pRandom8BallAnswer)];
}

// Displays randomly selected 8 ball answer
void Magic8Ball::ShowWhatThe8BallSays () {

    std::cout << std::endl;
    std::cout << "\t#---the Magic 8 Ball says: ---#\n";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\t " << *(pThe8BallAnswer) << " \n";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\t+---Shake the 8 Ball again?---+\n";
    std::cout << "\t|                             |\n";
    std::cout << "\t| [S]hake it again or [Q]uit! |\n";
    std::cout << "\t|                             |\n";
    std::cout << "\t+-----------------------------+\n";
    std::cout << std::endl;
}

// Checks if the user wants to continue shaking the ball for more answers
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
        ClearScreen ();
        reply = true; // Continue to shake the ball
    }
    else if (key == 'q' || key == 'Q') {
        ClearScreen ();
        ShowLogoOnExit ();
        reply = false; // Quits the program
    }
    return (reply);
}

// Displays credits screen on exit
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
    std::cout << "\t|  |V|E|R|S|I|O|N|:| |0|.|3|.|2|  |\n";
    std::cout << "\t|  +-+-+-+-+-+-+-+-+ +-+-+-+-+-+  |\n";
    std::cout << "\t|                                 |\n";
    std::cout << "\t|  made with a keyboard and CLion |\n";
    std::cout << "\t|       by NoobCode (c) 2017      |\n";
    std::cout << "\t|                                 |\n";
    std::cout << "\t+---------------------------------+\n";
    std::cout << std::endl;
}

// Clear the terminal screen for better readability
void Magic8Ball::ClearScreen () { std::cout << "\033[2J\033[1;1H"; }

void Magic8Ball::PressEnter () {

    std::string temp;
    std::cout << "\t\tAre you ready?\n\n";
    wait_for = 2000;
    Sleep (wait_for);
    std::cout << "\t\tPress ENTER to shake the Magic 8 Ball.\n";
    std::cout << "\t\t";
    std::cin.ignore(std::numeric_limits<char>::max(), '\n');
}

// Pauses the ASCII elements of the logo in ShowLogo()
void Magic8Ball::Sleep (int pause) {
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
}

//This function encapsulates the entire program
void DoMagic () {

    Magic8Ball My8Ball;
    bool reply;
    My8Ball.ShowLogo();
    do {
        My8Ball.Shake8Ball();
        My8Ball.GetTheReply();
        My8Ball.ShowWhatThe8BallSays();
        reply = My8Ball.Ask8BallAgain();
    } while (reply);
}
