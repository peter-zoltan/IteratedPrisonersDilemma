# Iterated Prisoner's Dilemma

The program simulates a game of Iterated Prisoner's Dilemma, communicating
with the user through the standard IO as well as optionally writing to a
file. It contains players (also referred to as prisoners), each implementing
their own strategies, with the goal of gaining the most points in the given
game. These players are declared in player.h and defined in player.cpp, all
inheriting the abstract Player class. As per the game's rules, their
strategy culminates in a choice between cooperation and defection,
represented by a boolean value. Players are able to remember their
opponents' choices within a match, and may base their strategy around that
information (VengefulPrisoner is one such example).

The players participating in a match are stored in the class GameManager,
declared in gameManager.h and defined in gameManager.cpp. This class is
also responsible for storing the parameters of the game, these parameters
being the number of rounds played each match, and the score payouts for all
four combinations of choices in a round. Other than storage, this class is
responsible for the actual simulation of the game, iterating through it's
list of players so that each player faces every other player once, and
doling out their scores. It also plays a supervisory role when information
about the players is printed, it's static boolean variable concise being the
deciding factor whether a shorter (name, ID, score) or longer (name,
description of strategy) set of data is printed.

The direct action of writing to a file is handled by the class FileManager,
declared in fileManager.h and defined in fileManager.cpp. The class takes
an instance if GameManager and a filename, and writes a short version of the
game's data to the file with the given name, similar to the results displayed
through the standard IO at the end of the game.

The class Menu is what ties these together, declared in menu.h and defined in
menu.cpp, it is responsible for initializing the instance of GameManager for
the game with the parameters gained from the user through the standard IO
and is in general responsible for communicating with the user through it.
After creating it, the class adds the participating players to the instance
of GameManager, letting it run it's simulation next. After the simulation has
run it's course the class can display the concise version of the game's data
through the standard IO. It is at this point responsible for allowing the user
to choose between writing the results to file, exiting, or continuing with
another game (with writing to file naturally not disabling the other two
options).

For the current state of user interaction and options, see the function main()
in main.cpp.

Apart from these the project contains the files memtrace.h and memtrace.cpp,
the former being included in every source file for the purposes of testing
memory management.