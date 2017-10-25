#ifndef MAGIC8BALL_MAGIC8BALL_H
#define MAGIC8BALL_MAGIC8BALL_H

#include <string>

extern void DoMagic ();

class Magic8Ball {
public:

    Magic8Ball (); // This is the constructor

    void ShowLogo (); // Prints the 8 Ball ASCII art
    void ShowLogoOnExit ();

    int Shake8Ball (); // This is the Magic 8 Ball mutator

    void GetTheReply (); // Gets the answers from the mutator (8 Ball)
    bool Ask8BallAgain (); // Checks if the user wants to shake the 8 Ball again


    void ClearScreen ();
    void PressEnter ();
    int wait_for;
    void Sleep (int time);

    void TheMagic ();
    void The8 ();
    void TheBall ();
    void TheInfo_Part_One ();
    void TheInfo_Part_Two ();

    int Random8BallAnswer; // global variable to run the mutator
    int * pRandom8BallAnswer = &Random8BallAnswer;

    std::string The8BallAnswer; // The return variable from the mutator
    const std::string * pThe8BallAnswer = &The8BallAnswer;

    const std::string * pDefault8BallAnswers = Default8BallAnswers;

private:

    // The collections of built-in 8 Ball answers //
    std::string Default8BallAnswers [40]= {"As I see it.", "Yes.", "Ask again later.", "Better not tell you now.",
                                    "Cannot predict now.", "Concentrate and ask again.", "Don’t count on it.",
                                    "It is certain.", "It is decidedly so.", "Most likely.", "My reply is no.",
                                    "My sources say no.", "Outlook good.", "Outlook not so good.",
                                    "Reply hazy, try again.", "Signs point to yes.", "Very doubtful.",
                                    "Without a doubt.", "Yes, definitely.", "You may rely on it.",
                                    "You've got to be kidding...", "That's ridiculous.", "Well, maybe.",
                                    "Dumb Question. Ask another.", "In your dreams!", "I've got a headache. Ask later.",
                                    "Oh, please.", "What do you think?", "Cannot predict now.", "You can count on it!",
                                    "You wish.", "It's in the mail.", "The voices told me to say nothing.",
                                    "Honestly, I wish I knew that.", "No idea. You're on your own.",
                                    "Ask again later. I can’t… I just can’t deal with this right now.",
                                    "Why do you bother me if you know the answer already?", "Come back tomorrow.",
                                    "You ask for too much.", "Why would I know? I'm just an 8 ball."};
};

#endif //MAGIC8BALL_MAGIC8BALL_H
