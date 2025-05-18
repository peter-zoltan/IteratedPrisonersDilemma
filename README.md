# Iterated Prisoner's Dilemma
### by Péter Zoltán

# Programmer's documentation

### Player

The program simulates a game of Iterated Prisoner's Dilemma, communicating with the user through the standard IO as well as optionally writing to a file. It contains players (also referred to as prisoners), each implementing their own strategies, with the goal of gaining the most points in the given game. These players are declared in **player.h** and defined in **player.cpp**, all inheriting the abstract Player class. The list of inheritors of Player implemented are as follows:

Selfish, Naive, Vengeful,  Copycat, Random, Majority.

Players are responsible for keeping their own score, and have methods for writing information about themselves to a given output stream. Each Player instance is identified by a unique integer ID beyond it's type. Each Player type has a strategy method, which returns a boolean value; true for cooperation, and false for defection. Players store the choices made by their opponents in a given match, which information they may or may not use to make their decision within their diferring strategies.

### GameManager

The players participating in a match are stored in the class GameManager, declared in **gameManager.h** and defined in **gameManager.cpp**. This class is also responsible for storing the parameters of the game, these parameters being the number of rounds played each match, and the score payouts for all four combinations of choices in a round. Other than storage, this class is responsible for the actual simulation of the game, iterating through it's list of players so that each player faces every other player once, and doling out their scores.

The **rounds** play out depending on the choices made as follows:
```
Both players cooperate: Both players receive points in amount R
Both players defect: Both players receive points in amount P
Player A defects while Player B cooperates: Player A receives points in amount T,
                                            Player B receives points in amount S
```

It also plays a supervisory role when information about the players is printed, it's static boolean variable concise being the deciding factor whether a shorter (name, ID, score) or longer (name, description of strategy) set of data is printed.

### FileManager

The direct action of writing to a file is handled by the class FileManager, declared in **fileManager.h** and defined in **fileManager.cpp**. The class takes an instance of GameManager and a filename, and writes a short version of the game's data to the file with the given name (appended with *.txt*), similar to the results displayed through the standard IO at the end of the game.

The *.txt* file uses the format showcased in the following example:
```
Number of rounds played: 50

#1 Vengeful (ID: 0) - 534 points
#2 Naive (ID: 1) - 512 points
#3 Naive (ID: 2) - 512 points
#4 Selfish (ID: 3) - 310 points
```

### Menu

The class Menu is what ties these together, declared in **menu.h** and
defined in **menu.cpp**, it is responsible for initializing the instance of GameManager for the game with the parameters gained from the user through the standard IO and is in general responsible for communicating with the user through it. After creating it within the context of the **main()** function in **main.cpp** the gets the participating players from the standard IO and adds them to the existing instance of GameManager, letting it run it's simulation next. After the simulation has run it's course the class displays the concise version of the game's data through the standard IO. It is at this point responsible for allowing the user to choose between writing the results to file, exiting, or continuing with another game (with writing to file naturally not disabling the other two options).

When the program takes input from the standard input, a line is read, and depending on what information is required at the moment, it takes that line's leading characters. (For example leading digits in the case that a number is expected.)

The following are examples of the standard output at the program's different stages:

Parameter menu:
```
Number of rounds to be played: 12

Value of mutual cooperation: 5

Value of mutual defection: 3

Value of one-sided defection: 7

Value of one-sided cooperation: _
```

**Player** selection:

	Choose players to participate:
	
	Selfish
	[Always defects.]
	
	Naive
	[Always cooperates.]
	
	Vengeful
	[Cooperates until the other player defects for the first time in the match.]
	
	Copycat
	[Copies the last choice made by their opponent, starts out with cooperation.]
	
	Random
	[Chooses between cooperation and defection at random.]
	
	Majority
	[Cooperates at first, then copies the choice their opponent has made more in the match.]
	
	Add player(s)   [1]
	Start game      [2]


**Game** complete:
```
Number of rounds played: 50

#1 Vengeful (ID: 0) - 534 points
#2 Naive (ID: 1) - 512 points
#3 Naive (ID: 2) - 512 points
#4 Selfish (ID: 3) - 310 points

Save to file and continue   [1]
Next game                   [2]
Exit                        [3]
_
```

Saving to file:
```
Filename: _
```

### Main

If the macro "CPORTA" is not defined, the course of the program is about as described above under **Menu**: the main() function handles the application loop, with a game constituting a cycle. Each game goes through the following motions:
> Adding the parameters of the game,
> adding the participating Players,
> running the simulation,
> optionally writing to file,
> and either exiting or starting again.

In the case that "CPORTA" is defined tests are ran instead. For details, see the **Tests** paragraph below.

### Memory management

The project contains **memtrace.cpp** and **memtrace.h**, the latter being included in every source file, to check that there are no memory leaks within the program. These require that the macro "MEMTRACE" be defined.

### Tests

Tests are found in the files **test.cpp** and **test.h** and are separated into four functions, one for each of the classes Player, GameManager, FileManager and Menu. These use the gtest_lite package for testiing, included with **gtest_lite.h**

### Dependencies

Other than the afforementioned files, the following are included within the code:
\<iostream>, \<Random>, \<iomanip>, \<fstream>, \<vector>

### Starting the program

The program can be ran by navigating to the directory containing it' source files, and creating an executable with the following command (for example):
```
g++ -o <executable_name> *.cpp --static -DMEMTRACE
```
Afterwards the program should start upon running the resulting *.exe* file. Handling of the program from this point in is detailed in the user's manual.

# User manual

Upon starting up the program the following text should greet us:

	Number of rounds to be played:_

Here the user is expected to type a number to assign to this value. In the case that the number typed is less than 1, or not a number at all, the program warns the user that the input is invalid, and make them try again.

Note that here and from here on out, when the user is expected to type something, processing happens after they hit enter, with the program selecting the leading characters of the line they entered as long as they are eligible in the given context, discarding the rest. In this example:

"23" is a valid input, and so is "23skfafsfsy", both resulting in the number 23 being assigned.

When the user is successful, the next line is displayed:

	Value of mutual cooperation:_

The only difference here from before, is that negative numbers starting with a minus sign (dash) are also valid.

Next:

	Value of mutual defection:_

Negative numbers are valid, with the constraint that this value has to be lower than the value of mutual cooperation.

Next:

	Value of one-sided defection:_

Negative numbers are valid, with the constraint that this value has to be higher than the value of mutual cooperation.

Next:

	Value of one-sided cooperation:_

Negative numbers are valid, with the constraint that this value has to be lower than the value of mutual defection, and the added value of this and one-sided defection has to be higher than than twice the value of mutual cooperation.

Once the game is successfully given it's basic parameters, the program displays the type of players:

	Choose players to participate:
	
	Selfish
	[Always defects.]
	
	Naive
	[Always cooperates.]
	
	Vengeful
	[Cooperates until the other player defects for the first time in the match.]
	
	Copycat
	[Copies the last choice made by their opponent, starts out with cooperation.]
	
	Random
	[Chooses between cooperation and defection at random.]
	
	Majority
	[Cooperates at first, then copies the choice their opponent has made more in the match.]
	
	Add player(s)   [1]
	Start game      [2]

If the user types 1, they are able to add players to participate in the game:

	Add player(s):_

Here the user is expected to type the player types' name once for each instance they want added, or type "all" for one of each type to be added. Capitalisation as well as any other input than the names are ignored. For example:

the input "njsakdkMajority randOMselfish" will result in an instance of Majority, Random and Selfish being added to the game which the program also conveys to the user:

	Selfish prisoner added.
	Random prisoner added.
	Majority prisoner added.

The user is then presented with the option again:

	Add player(s)   [1]
	Start game      [2]

They may keep adding players for as long as they like, but once they type 2, the simulation runs, and the results are displayed:

	Rounds played: 12
	
	#1 Selfish      (ID: 0) - 240 points
	#2 Random       (ID: 1) - 160 points
	#3 Majority     (ID: 2) - 152 points
	
	Save results to file    [1]
	Next game               [2]
	Exit                    [3]

If they type 1, the user has to type a name, which will be the name of the *.txt* file where to program saves the results, in the same format as they are displayed above.

(Note that both here and in the case above, if there were no players participating, the displayed text will instead be "No matches were played." instead of the rounds and scores.)

	Filename:_

The user will then be presented with the options again:

	Save results to file    [1]
	Next game               [2]
	Exit                    [3]

If they type 2, a new game is started, for this, refer back to the very beginning of this manual. If they type 3, the program exits.