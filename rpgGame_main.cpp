// Author: Harrison Bolin
// CSCI 1300 - Intro to Computer Programming
// Instructor: Fleming/Gupta
// Recitation: 106 – Ashwin Sankaralingam
// Cloud9 Workspace Editor Link: https://ide.c9.io/habo8408/csci1300
// RPG Game Main File


#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#include "rpgGame.cpp"
// above ^ are the preprocessor directives


// above ^ are the prototypes for the functions used


int main()
{
    // seeds the random number generator used for the battle system
    srand(time(0));
    
    
    // create the game instance object
    
    // new game or load saved game?
        // use member function to create character
        // - or - 
        // use member function to load character save and jump to the correct position in the story
    
    // tutorial fight
    
    // first story interaction
    
    // main game loop
        
        // randomly generated fight. Gets harder each time
        
        // random story interaction or puzzle. Possibility to use or get item or status effect
        
        // enter shop, spend gold for items, effects, or upgrades
        
        // make a choice to face the next boss or go through the loop again. Checkpoint to save and quit game
        
    // first boss
    
    // story interaction
    
    // second iteration of main game loop - New setting and enemies. New puzzles
    
    // camp before main boss fight. Save or rest
    
    // final boss fight
        
        // final boss fight 2nd stage
        
    Game currentGame = Game();
        
    cout << "+--------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "                                            WELCOME TO AGE OF ATHEON" << endl;
    cout << "+--------------------------------------------------------------------------------------------------------------+" << endl;
    cout << endl;
    cout << "Would you like to create a (n)ew game or (l)oad an exsisting save?" << endl;

    
    string selection;
    cin >> selection; 
    int entryLevel = 0;
    
    if (selection == "n") {
        cout <<"!Entering the name of an exsisting save will overwrite that save!"
        currentGame.firstSetup();
        
        currentGame.parseItemList();
        
        
    } else if (selection == "l") {
        cout << "Please enter the name of your previous character: ";
        cin >> selection;
        
        currentGame.loadSave(selection);
        // check for name
            // if name exsists, load the save
        // if the name does not exsist, ask for the name again
        
    }
            
    // This forloop maintains the level number which manages the current level of the game. Used for saving and game progression
    for (int level = entryLevel; level < 12; level++) {
        
        // TUTORIAL LEVEL
        if (level == 0) {
            currentGame.tutorialEncounter();
            currentGame.campTutorial(level);
        }
        
    
        // REGULAR LEVELS
        if (level < 10 && level > 0) {
            currentGame.camp(level);
            if (currentGame.isDead() == true) {
                level--;
            }
        }
        
        // FINAL LEVEL
        if (level == 11) {
            currentGame.finalEncounter();
        }
        
    }
            

//------------------------------------------------------------------------
//    Self Made Tests
//------------------------------------------------------------------------
    
    
// test for graphics
    // printGraphic("graphics/skeleton.txt");
    
    // cout << "Test Complete";
    
// test for parsing items list
    // for (int h = 0; h < 10; h++) {
    //     cout << spells[h].getName() << " : " << spells[h].getDescription() << endl;
    // }
    
// test for making sure the puzzles worked
// cout << weaponLevel << endl; 

    
}

