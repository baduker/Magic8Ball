#include <iostream>
#include "Magic8Ball.h"

int main()
{
    Magic8Ball My8Ball;

    My8Ball.ShowLogo();
    My8Ball.PrintInfo();
    do {
        My8Ball.Shake8Ball();
        My8Ball.GetTheReply();
    } while (My8Ball.Ask8BallAgain());
    return 0;
}