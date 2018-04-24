// Author: Harrison Bolin
// CSCI 1300 - Intro to Computer Programming
// Instructor: Fleming/Gupta
// Recitation: 106 – Ashwin Sankaralingam
// Cloud9 Workspace Editor Link: https://ide.c9.io/habo8408/csci1300
// RPG Game Header File

// https://www.youtube.com/watch?v=4xLVySuwbOo

#include <iostream>
#include <string>
using namespace std;
// above ^ are the preprocessor directives

// This class is used for all the items in the game, from consumables to spells to weapons. This also includes spells and weapons that are unable to be aquired by the player and are used by characters or enemies
class Item {
    public:
        Item();
        Item(int inputDamage, int inputEffect, int inputElemental, string inputName, string inputDescription);
        void setDamage(int inputDamage);
        void setEffect(int inputEffect);
        void setElemental(int inputElemental);
        void setName(string inputName);
        void setDescription(string inputDescription);
        int getDamage();
        int getEffect();
        int getElemental();
        string getName();
        string getDescription();
    private:
        int damage;
        int effect;
        int elemental;
        string description;
        string name;
} ;

// This class is for both the main character and enemies in the game. Using the same class allows battles to be planned better
class Character {
    public:
        Character();
        Character(int inputType, int inputHealth, int inputMana, int inputStrength, int inputSpeed, int inputMagic);
        void setup(int inputType, int inputHealth, int inputMana, int inputStrength, int inputSpeed, int inputMagic);
        void setType(int inputType);
        void setHealth(int inputHealth);
        void setMaxHealth(int inputHealth);
        void damage(int inputDamage, int inputType);
        void heal(int inputHeal);
        void setMana(int inputMana);
        void setStrength(int inputStrength);
        void setSpeed(int inputSpeed);
        void setMagic(int inputMagic);
        void setGraphic (string graphicFilename);
        void setName (string inputName);
        Item setCharacterItem(Item inputItem);
        Item setCharacterSpell(Item inputSpell);
        int getType();
        int getHealth();
        int getMaxHealth();
        int getMana();
        int getStrength();
        int getSpeed();
        int getMagic();
        string getName();
        string getGraphic();
        Item getCharacterItem(Item inputItem);
        Item getCharacterSpell(Item inputSpell);
    private:
        int type;           // which race the player selects
        int health;         // how much health the character has
        int maxHealth;      // maximum amount of health this character can have
        int mana;           // how much mana they have
        int strength;       // how strong the character is
        int speed;          // how fast the character is
        int magic;          // how strong the character is in magic
        string graphic;     // the filename of the characters graphic image
        string name;
} ;

class Game {
    public:
        Game();
        void firstSetup();
        void setMainName(string inputName);
        string getMainName();
        //void printGraphic(string graphicFile); // this function gets the correct graphic and prints it out for the user to see
        void parseItemList();   // goes through items.txt and adds them to the main array for items and spells
        void giveItem(int selection, int inputItem);   // gives the player the item or spell 
        void tutorialEncounter(); // beginning encounter teaching how to fight
        void campTutorial(int level);
        void regularEncounter(int level);
        void puzzle(int level);
        void camp(int level);
        void finalEncounter();
        bool isDead();
        void loadSave(string inputName);
    private:
        bool died;
        string mainName;    // the main character's name
        int gameStage;
        Character mainCharacter;
        int weaponLevel;
        Item weapon;
        Item spell1;
        Item spell2;
        Item spell3;
        Item items[50];     // all the items used in the game
        Item spells[50];    // all the spells used in the game
        Character enemies[10];
        
} ;


// class Encounter {
//     public:
//         Encounter(int inputDifficulty, int level);
        
//     private:
//         int difficulty;     // how difficult the encounter should be
//         Character enemy;    // the enemy in the encounter
// }

bool checkInput(char input);
void printGraphic(string graphicFile);
void pressSpace();