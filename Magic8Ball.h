//
// Created by Baduker on 04/09/2017.
//

#ifndef MAGIC8BALL_MAGIC8BALL_H
#define MAGIC8BALL_MAGIC8BALL_H

#include <string>

class Magic8Ball {
public:

    Magic8Ball(); // This is the constructor

    void ShowLogo (); // Prints the 8 Ball ASCII art
    void Shake8Ball(); // This is the Magic 8 Ball mutator
    std::string GetTheReply(); // Gets the answers from the mutator (8 Ball)
    bool Ask8BallAgain(); // Checks if the user wants to shake the 8 Ball again

    void PrintInfo();

    void ClearScreen();
    void PressEnter();

private:
    // The collections of built-in 8 Ball answers // TODO Add variations of answers (maybe 2-3 different arrays)
    std::string Default8BallAnswers [33]= {"As I see it.", "Yes.", "Ask again later.", "Better not tell you now.",
                                    "Cannot predict now.", "Concentrate and ask again.", "Don’t count on it.",
                                    "It is certain.", "It is decidedly so.", "Most likely.", "My reply is no.",
                                    "My sources say no.", "Outlook good.", "Outlook not so good.",
                                    "Reply hazy, try again.", "Signs point to yes.", "Very doubtful.",
                                    "Without a doubt.", "Yes, definitely.", "You may rely on it.",
                                    "You've got to be kidding...", "That's ridiculous.", "Well, maybe.",
                                    "Dumb Question. Ask another.", "In your dreams!", "I've got a headache. Ask later.",
                                    "Oh, please.", "What do you think?", "Cannot predict now.", "You can count on it!",
                                    "You wish.", "It's in the mail.", "The voices told me to say nothing."};
    std::string The8BallAnswer; // The return variable from the mutator
};

#endif //MAGIC8BALL_MAGIC8BALL_H
