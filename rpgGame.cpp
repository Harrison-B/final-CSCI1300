// Author: Harrison Bolin
// CSCI 1300 - Intro to Computer Programming
// Instructor: Fleming/Gupta
// Recitation: 106 – Ashwin Sankaralingam
// Cloud9 Workspace Editor Link: https://ide.c9.io/habo8408/csci1300
// Homework #


#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "rpgGame.h"


//------------------------------------------------------------------------
//    GAME MEMBER FUNCTIONS
//------------------------------------------------------------------------

Game::Game() {
    
    
    // Create Enemies - this system randomly generates 10 enemies for use during the game
    string lowEnemies[5] = {"slime","spider","wolf","ruffian","vagabond"};
    string mediumEnemies[5] = {"skeleton","goblin","ghost","werewolf","wolf pack"};
    string highEnemies[5] = {"undead warrior","black knight","unknown horror","zombie pack","goblin king"};
    
    for (int i = 0; i < 4; i++) {
        enemies[i].setName(lowEnemies[(rand() % 5)]);
        enemies[i].setHealth(40 + (rand() % 5));
        enemies[i].setStrength(5);
        enemies[i].setType(rand() % 5);
    }
    
    for (int i = 4; i < 8; i++) {
        enemies[i].setName(mediumEnemies[(rand() % 5)]);
        enemies[i].setHealth(80 + (rand() % 5));
        enemies[i].setStrength(10);
        enemies[i].setType(rand() % 5);
    }
    
    for (int i = 8; i < 10; i++) {
        enemies[i].setName(highEnemies[(rand() % 5)]);
        enemies[i].setHealth(120 + (rand() % 5));
        enemies[i].setStrength(15);
        enemies[i].setType(rand() % 5);
    }
    
    
    
    
}


// this function gets the correct graphic and prints it out for the user to see
void printGraphic(string graphicFile) {
    
    ifstream graphicsFile;
    graphicsFile.open(graphicFile);
    
    string lineb = "";
    
    if (graphicsFile.is_open()){
        while(!graphicsFile.eof()) {
            getline(graphicsFile, lineb); // get the current line
            cout << lineb << endl;
        }
        
        graphicsFile.close();
    }
    
    
}

// loads the save of the user
void loadSave(string inputName) {
    ifstream saveFile;
    saveFile.open("savefiles.txt");
    
    if (itemsFile.is_open() && spellsFile.is_open()){  // check to make sure files opened correctly
        
        
        string lineb = "";
        
        while (!itemsFile.eof()) { // while the file has not ended
            int position = 0;
            getline(itemsFile, lineb); // get the current line
            if (lineb.empty() == 0){ // check to make sure line is not empty
                int wordLength = 0;
                
                for (int i = 0; i < lineb.length() + 1; i++){ // for every character in the string as well as the null end character
                    
                    if (lineb[i] == ',' && position == 0) { // check to see if it is the delimiter or the end of the string
                        items[numItems].setName(lineb.substr(i - wordLength, wordLength));
                        position++;
                        wordLength = 0; // set the length of the word back to 0
                    } else if (lineb[i] == ',' && position == 1) {
                        items[numItems].setDescription(lineb.substr(i - wordLength, wordLength));
                        position++;
                        wordLength = 0; // set the length of the word back to 0
                    }
                }
                

            }
        }
        
            
    }
    
    
    
    
    
}


// goes through items.txt and adds them to the main array for items and spells
void Game::parseItemList() {
    
// create streams and import the filenames
    ifstream itemsFile;
    itemsFile.open("items.txt");
    ifstream spellsFile;
    spellsFile.open("spells.txt");
    
    // create variables to determine author and items
    string name;
    string description;
    string names[100];
    string descriptions[100];
    int damages[100];
    int effects[100];
    int elementals[100];
    int numItems = 0;
    int numSpells = 0;

    if (itemsFile.is_open() && spellsFile.is_open()){  // check to make sure files opened correctly
        
        
        string lineb = "";
        
        while (!itemsFile.eof()) { // while the file has not ended
            int position = 0;
            getline(itemsFile, lineb); // get the current line
            if (lineb.empty() == 0){ // check to make sure line is not empty
                int wordLength = 0;
                
                for (int i = 0; i < lineb.length() + 1; i++){ // for every character in the string as well as the null end character
                    
                    if (lineb[i] == ',' && position == 0) { // check to see if it is the delimiter or the end of the string
                        items[numItems].setName(lineb.substr(i - wordLength, wordLength));
                        position++;
                        wordLength = 0; // set the length of the word back to 0
                    } else if (lineb[i] == ',' && position == 1) {
                        items[numItems].setDescription(lineb.substr(i - wordLength, wordLength));
                        position++;
                        wordLength = 0; // set the length of the word back to 0
                    } else if (lineb[i] == ',' && position == 2) {
                        items[numItems].setDamage(stoi(lineb.substr(i - wordLength, wordLength)));
                        position++;
                        wordLength = 0; // set the length of the word back to 0
                    } else if (lineb[i] == ',' && position == 3) {
                        items[numItems].setEffect(stoi(lineb.substr(i - wordLength, wordLength)));
                        position++;
                        wordLength = 0; // set the length of the word back to 0
                    } else if (lineb[i] == ',' && position == 4) {
                        items[numItems].setElemental(stoi(lineb.substr(i - wordLength, wordLength)));
                        wordLength = 0; // set the length of the word back to 0
                    } else {
                        wordLength++;
                    }
                }
                

                numItems++;
            }
            
        }
        
        
        while (!spellsFile.eof()) { // while the file has not ended
            int position = 0;
            getline(spellsFile, lineb); // get the current line
            if (lineb.empty() == 0){ // check to make sure line is not empty
                int wordLength = 0;
                
                for (int i = 0; i < lineb.length() + 1; i++){ // for every character in the string as well as the null end character
                    
                    if (lineb[i] == ',' && position == 0) { // check to see if it is the delimiter or the end of the string
                        spells[numSpells].setName(lineb.substr(i - wordLength, wordLength));
                        position++;
                        wordLength = 0; // set the length of the word back to 0
                    } else if (lineb[i] == ',' && position == 1) {
                        spells[numSpells].setDescription(lineb.substr(i - wordLength, wordLength));
                        position++;
                        wordLength = 0; // set the length of the word back to 0
                    } else if (lineb[i] == ',' && position == 2) {
                        spells[numSpells].setDamage(stoi(lineb.substr(i - wordLength, wordLength)));
                        position++;
                        wordLength = 0; // set the length of the word back to 0
                    } else if (lineb[i] == ',' && position == 3) {
                        spells[numSpells].setEffect(stoi(lineb.substr(i - wordLength, wordLength)));
                        position++;
                        wordLength = 0; // set the length of the word back to 0
                    } else if (lineb[i] == ',' && position == 4) {
                        spells[numSpells].setElemental(stoi(lineb.substr(i - wordLength, wordLength)));
                        wordLength = 0; // set the length of the word back to 0
                    } else {
                        wordLength++;
                    }
                }
                

                numSpells++;
            }
            
        }
    
    
        cout << endl; // successful data load message
        

        
    
    // set the data in the Library object to the data that has been calculated (this step is redundant)

    } else { // failure case 
        cout << "Launch unsuccessful" << endl;
        cout << "Error! items or ratings file could not be found." << endl;
        exit (EXIT_FAILURE); // make sure to exit the program without executing the rest of the program
    }
    
    
    itemsFile.close();
    
}

// NAME : DESCRIPTION : DAMAGE : EFFECR : ELEMENTAL : MANA COST

// Effects:
// 0 = No effect
// 1 = Blood drain

// Elemental:
// 0 = No elemental power
// 1 = Fire
// 2 = Ice
// 3 = Electricity 
// 4 = Healing

void Game::setMainName(string inputName) {
    mainName = inputName;
}

string Game::getMainName() {
    return mainName;
}

void Game::firstSetup() {
    string input;
    bool classChosen = false;
    died = false;
    cout << "Please choose a name for your character: ";
    cin >> mainName;
    
    do {
        cout << "What class would you like your character to be? [r]ouge, [f]ighter, or [w]izard: ";
        cin >> input;
        input[0] = tolower(input[0]);
        
        if (input[0] == 'r') {
            mainCharacter.setup(1,25,10,2,15,5);
            classChosen = true;
        } else if (input[0] == 'f') {
            mainCharacter.setup(2,30,5,3,5,5);
            classChosen = true;
        } else if (input[0] == 'w') {
            mainCharacter.setup(3,20,15,2,5,15);
            classChosen = true;
        } 
    } while (classChosen == false);
    
    
}


// Private Datamembers
// string mainName;    // the main character's name
// Item items[50];     // all the items used in the game
// Item spells[50];    // all the spells used in the game
        
//------------------------------------------------------------------------
//    CHARACTER MEMBER FUNCTIONS
//------------------------------------------------------------------------
Character::Character() {
    type = 0;
    health = 0;
    mana = 0;
    strength = 0;
    speed = 0;
    magic = 0;
}

Character::Character(int inputType, int inputHealth, int inputMana, int inputStrength, int inputSpeed, int inputMagic) {
    type = inputType;
    health = inputHealth;
    mana = inputMana;
    strength = inputStrength;
    speed = inputSpeed;
    magic = inputMagic;
    maxHealth = inputHealth;
}

void Character::setup(int inputType, int inputHealth, int inputMana, int inputStrength, int inputSpeed, int inputMagic) {
    type = inputType;
    health = inputHealth;
    mana = inputMana;
    strength = inputStrength;
    speed = inputSpeed;
    magic = inputMagic;
    maxHealth = inputHealth;
}

void Character::damage(int inputDamage, int inputType) {
    if (inputType == type) {
        cout << "> " << name << " is weak to this element, extra damage is dealt" << endl;
        health = health - inputDamage - (inputDamage / 5);
    } else {
        health = health - inputDamage;
    }
}

void Character::heal(int inputHeal) {
    if (health + inputHeal > maxHealth) {
        health = maxHealth;
    } else {
        health = health + inputHeal;
    }
}

void Character::setType(int inputType) {
    type = inputType;
}

void Character::setHealth(int inputHealth) {
    health = inputHealth;
}

void Character::setMaxHealth(int inputHealth) {
    maxHealth = inputHealth;
}

void Character::setMana(int inputMana) {
    mana = inputMana;
}

void Character::setStrength(int inputStrength) {
    strength = inputStrength;
}

void Character::setSpeed(int inputSpeed) {
    speed = inputSpeed;
}

void Character::setMagic(int inputMagic) {
    magic = inputMagic;
}

void Character::setGraphic (string graphicFilename) {
    graphic = graphicFilename;
}

void Character::setName (string inputName) {
    name = inputName;
}

int Character::getType() {
    return type;
}

int Character::getHealth() {
    return health;
}

int Character::getMaxHealth() {
    return maxHealth;
}

int Character::getMana() {
    return mana;
}

int Character::getStrength() {
    return strength;
}

int Character::getSpeed() {
    return speed;
}

int Character::getMagic() {
    return magic;
}

string Character::getGraphic() {
    return graphic;
}

string Character::getName() {
    return name;
}

        
// Private Datamembers
// int health;         // how much health the character has
// int mana;           // how much mana they have
// int strength;       // how strong the character is
// int speed;          // how fast the character is
// int magic;          // how strong the character is in magic
// string graphic;     // the filename of the characters graphic image
// Item characterItems[10];   // an array of the items the character has
// Item characterSpells[10];  // an array of the spells the character can use


//------------------------------------------------------------------------
//    ITEM MEMBER FUNCTIONS
//------------------------------------------------------------------------

// This class is used for all the items in the game, from consumables to spells to weapons. This also includes spells and weapons that are unable to be aquired by the player and are used by characters or enemies

Item::Item() {
    name = "empty";
    damage = -1;
}

Item::Item(int inputDamage, int inputEffect, int inputElemental, string inputName, string inputDescription) {
    
}

void Item::setDamage(int inputDamage) {
    damage = inputDamage;
}

void Item::setEffect(int inputEffect) {
    effect = inputEffect;
}

void Item::setElemental(int inputElemental) {
    elemental = inputElemental;
}

void Item::setName(string inputName) {
    name = inputName;
}

void Item::setDescription(string inputDescription) {
    description = inputDescription;
}

int Item::getDamage() {
    return damage;
}

int Item::getEffect() {
    return effect;
}

int Item::getElemental() {
    return elemental;
}

string Item::getName() {
    return name;
}

string Item::getDescription() {
    return description;
}


// Private Datamembers
// int damage;
// int effect;
// int elemental;
// string description;
// string name;


//------------------------------------------------------------------------
//    MISC. MEMBER FUNCTIONS
//------------------------------------------------------------------------
void pressSpace() {
 bool enter = false;
 char input;
 
 do 
 {
   cout << "Press [c] then enter to continue...";
   cin >> input;
   
   if (input == 'c') {
       enter = true;
   }
   
 } while (enter == false);
 cout << endl;
}

bool Game::isDead() {
    if (died == true) {
        died = false;
        mainCharacter.setHealth(mainCharacter.getMaxHealth() / 2);
        return true;
    } else {
        return false;
    }
}

void Game::camp(int level) {
    int interactions = 0;
    char selection;
    bool optionChosen = false;
    cout << "Welcome to your camp. Rest a while, work on a puzzle from a traveller, or view your stats" << endl;
    cout << "There are " << 10 - level << " days left until you face the Demon King" << endl;
    printGraphic("graphics/campfire.txt");
    
    do {
            cout << "[B]attle another creature  :  [P]uzzle from a traveller  :  [V]iew your stats  :  [S]ave your game" << endl;
            cin >> selection;
            selection = tolower(selection);
            // PUZZLE
            if (selection == 'p') {
                puzzle(level);
                optionChosen = true;
            // STATS
            } else if (selection == 'v') {
                    cout << "STATS: Health: " << mainCharacter.getHealth() << "  Mana: " << mainCharacter.getMana() << "  Weapon: " << weapon.getName() << ": " << weapon.getDescription() << endl;
                    selection = '0';
            // REGULAR BATTLE
            } else if (selection == 'b'){
                // cout << level << endl;
                optionChosen = true;
                regularEncounter(level);
            } else if (selection == 's'){
                
            } else {
                cout << "Please enter a valid input" << endl;
            }
            
            
        } while (optionChosen == false);
    
}


void Game::regularEncounter(int level) {
    cout << "As you walk through the woods your character is suddenly attacked by a " << enemies[level].getName() << ". Prepare for battle!" << endl;
    
    int attack = 0;
    int dmgWeapon = mainCharacter.getStrength() * weapon.getDamage();
    
    // cout << enemies[level].getHealth() << endl;
    
    
    // MAIN ATTACK LOOP
    while (enemies[level].getHealth() > 0) {
        char selection;
        int dodge = mainCharacter.getSpeed();
        bool dodgeSuccessful = false;
        bool spellChosen = false;
        
        do {
            cout << "[W]eapon  :  [S]pell  :  [D]odge  :  [V]iew Stats ";
            cin >> selection;
                    
            // ATTACK WITH WEAPON
            if (selection == 'w') {
                
                attack = (mainCharacter.getStrength() * weapon.getDamage() * (rand() % 10)) / 10;
                enemies[level].setHealth(enemies[level].getHealth() - attack);
                
                // tests for battle system
                // cout << attack << endl;
                // cout << (dmgWeapon - (dmgWeapon / 4)) << endl;
                
                if (attack > (dmgWeapon - (dmgWeapon / 4))) {
                    cout << "> " << mainName << " special attacks with a weapon dealing " << attack << " damage" << endl;
                } else {
                    cout << "> " << mainName << " attacks with a weapon dealing " << attack << " damage" << endl;
                }
                
            // CAST A SPELL
            } else if (selection == 's') {
                if (spell1.getDamage() + spell1.getDamage() + spell1.getDamage() == -3) {
                    cout << "You have no spells to cast" << endl;
                    selection = '0';
                } else {
                    cout << "Pick the spell you would like to cast: [1]" <<  spell1.getName() << "  [2]" << spell2.getName() << "  [3]" << spell3.getName() << endl;
                    
                    while (spellChosen == false) {
                        cin >> selection;
                        if (selection == '1') {
                            mainCharacter.heal(spell1.getDamage());
                            cout << "> " << mainName << " has healed and gained " << spell1.getDamage() << " health. You now have " << mainCharacter.getHealth() << " total health" << endl;
                            spellChosen = true;
                        } else if (selection == '2') {
                            enemies[level].damage(spell2.getDamage(),spell1.getElemental());
                            cout << "> " << mainName << " attacks with " << spell2.getName() << " spell " << spell2.getDamage() << " damage" << endl;
                            spellChosen = true;
                        } else if (selection == '3') {
                            enemies[level].damage(spell2.getDamage(),spell1.getElemental());
                            cout << "> " << mainName << " attacks with " << spell3.getName() << " spell " << spell3.getDamage() << " damage" << endl;
                            spellChosen = true;
                        } 
                    }
                    selection = 's';
                }
                
                
            // ATTEMPT TO DODGE ATTACK
            } else if (selection == 'd') {
                dodge = dodge + 60;
                
                
            // VIEW YOUR HEALTH AND WEAPON
            } else if (selection == 'v') {
                    cout << "STATS: Health: " << mainCharacter.getHealth() << "  Mana: " << mainCharacter.getMana() << "  Weapon: " << weapon.getName() << endl;
                    selection = '0';
            } else {
                cout << "Please enter a valid input" << endl;
            }
            
            
        } while (checkInput(selection) == false);
        
        // decide if the player dodged the attack or not
        if (dodge > (rand() % 100)) {
            dodgeSuccessful = true;
        }
        
        
        // this computes whether the player dodges the attack
        if (dodgeSuccessful == false) {
            attack = (enemies[level].getStrength() * (rand() % 10)) / 10;
            mainCharacter.setHealth(mainCharacter.getHealth() - attack);
            cout << "> " << enemies[level].getName() << " attacks dealing " << attack << " damage. You now have " << mainCharacter.getHealth() << endl;
            
        } else {
            cout << "> You successfully dodged the enemy attack and gained " << mainCharacter.getMaxHealth() / 10 << " health" << endl;
            mainCharacter.heal(mainCharacter.getMaxHealth() / 10);
        }

        if (mainCharacter.getHealth() < 0) {
            printGraphic("graphics/dead.txt");
            cout << endl;
            cout << "                YOU DIED            " << endl;
            cout << "You will be returned to your last campsite" << endl;
            died = true;
            pressSpace();
            break;
        } 
        
        
    }
    
    if (mainCharacter.getHealth() >= 0) {
        cout << endl;
        cout << "+-+-+-+-+-+-+-+-+-+-+-+-+ VICTORY! +-+-+-+-+-+-+-+-+-+-+-+" << endl;
        mainCharacter.setMaxHealth(mainCharacter.getMaxHealth() + 2);
        cout << "You have gained 2 max health points and have been healed by " << mainCharacter.getMaxHealth() / 4 << endl;
        cout << "As a reward you now get a " << items[weaponLevel].getName() << " to help you with your quest" << endl;
        weapon = items[weaponLevel];
        mainCharacter.heal((mainCharacter.getMaxHealth() / 3));
        
        weaponLevel++;
        pressSpace();
    }

}

void Game::campTutorial(int level) {
    int interactions = 0;
    char selection;
    
    cout << "Welcome to your camp. Rest a while, work on a puzzle from a traveller, or view your stats" << endl;
    printGraphic("graphics/campfire.txt");
    
    bool optionChosen = false;
    do {
            cout << "[P]uzzle from a traveller  :  [V]iew your stats" << endl;
            cin >> selection;
            selection = tolower(selection);
            // PUZZLE
            if (selection == 'p') {
                puzzle(level);
                optionChosen = true;
            // STATS
            } else if (selection == 'v') {
                    cout << "STATS: Health: " << mainCharacter.getHealth() << "  Mana: " << mainCharacter.getMana() << "  Weapon: " << weapon.getName() << ": " << weapon.getDescription() << endl;
                    selection = '0';
            } else {
                cout << "Please enter a valid input" << endl;
            }
            
            
        } while (optionChosen == false);
    
}

void Game::tutorialEncounter() {
    
    // Equip Beginning Weapons and Spells
    weapon = items[0];
    spell1 = spells[12];
    
    if (mainCharacter.getType() == 3) {
        spell1 = spells[13];
        spell2 = spells[1];
        spell3 = spells[5];
    }
    
    
    cout << "Your character awakes from their slumber, surprised to see a " << enemies[0].getName() << " emerge from the woods around their camp" << endl;
    // cout << "TIP: Use the [Spacebar] throughout the game to progress lines of text" << endl;
    cout << "You will now go through your first battle. Below you see your character screen which features your current stats, weapons, and spells" << '\n' << endl;
    
    cout << "+ Health: " << mainCharacter.getHealth() << "  Mana: " << mainCharacter.getMana() << "  Weapon: " << weapon.getName() << endl;
    cout << endl;
    
    cout << "You are now offered a choice. You can attack using a weapon, use a magic spell, or attempt to dodge the next attack" << endl;
    
    
    int attack = 0;
    int dmgWeapon = mainCharacter.getStrength() * weapon.getDamage();
    
    // MAIN ATTACK LOOP
    while (enemies[0].getHealth() > 0) {
        char selection;
        int dodge = mainCharacter.getSpeed();
        bool dodgeSuccessful = false;
        bool spellChosen = false;
        
        do {
            cout << "[W]eapon  :  [S]pell  :  [D]odge  :  [V]iew Stats ";
            cin >> selection;
                    
            // ATTACK WITH WEAPON
            if (selection == 'w') {
                
                attack = (mainCharacter.getStrength() * weapon.getDamage() * (rand() % 10)) / 10;
                enemies[0].setHealth(enemies[0].getHealth() - attack);
                
                // tests for battle system
                // cout << attack << endl;
                // cout << (dmgWeapon - (dmgWeapon / 4)) << endl;
                
                if (attack > (dmgWeapon - (dmgWeapon / 4))) {
                    cout << "> " << mainName << " special attacks with a weapon dealing " << attack << " damage" << endl;
                } else {
                    cout << "> " << mainName << " attacks with a weapon dealing " << attack << " damage" << endl;
                }
                
            // CAST A SPELL
            } else if (selection == 's') {
                if (spell1.getDamage() + spell1.getDamage() + spell1.getDamage() == -3) {
                    cout << "You have no spells to cast" << endl;
                    selection = '0';
                } else {
                    cout << "Pick the spell you would like to cast: [1]" <<  spell1.getName() << "  [2]" << spell2.getName() << "  [3]" << spell3.getName() << endl;
                    
                    while (spellChosen == false) {
                        cin >> selection;
                        if (selection == '1') {
                            mainCharacter.heal(spell1.getDamage());
                            cout << "> " << mainName << " has healed and gained " << spell1.getDamage() << " health. You now have " << mainCharacter.getHealth() << " total health" << endl;
                            spellChosen = true;
                        } else if (selection == '2') {
                            enemies[0].damage(spell2.getDamage(),spell1.getElemental());
                            cout << "> " << mainName << " attacks with " << spell2.getName() << " spell " << spell2.getDamage() << " damage" << endl;
                            spellChosen = true;
                        } else if (selection == '3') {
                            enemies[0].damage(spell2.getDamage(),spell1.getElemental());
                            cout << "> " << mainName << " attacks with " << spell3.getName() << " spell " << spell3.getDamage() << " damage" << endl;
                            spellChosen = true;
                        } 
                    }
                    selection = 's';
                }
                
                
            // ATTEMPT TO DODGE ATTACK
            } else if (selection == 'd') {
                dodge = dodge + 60;
                
                
            // VIEW YOUR HEALTH AND WEAPON
            } else if (selection == 'v') {
                    cout << "STATS: Health: " << mainCharacter.getHealth() << "  Mana: " << mainCharacter.getMana() << "  Weapon: " << weapon.getName() << endl;
                    selection = '0';
            } else {
                cout << "Please enter a valid input" << endl;
            }
            
            
        } while (checkInput(selection) == false);
        
        
        if (dodge > (rand() % 100)) {
            dodgeSuccessful = true;
        }
        
        
        // this computes whether the player dodges the attack
        if (dodgeSuccessful == false) {
            attack = (enemies[0].getStrength() * (rand() % 10)) / 10;
            mainCharacter.setHealth(mainCharacter.getHealth() - attack);
            cout << "> " << enemies[0].getName() << " attacks dealing " << attack << " damage. You now have " << mainCharacter.getHealth() << endl;
            
        } else {
            cout << "> You successfully dodged the enemy attack and gained " << mainCharacter.getMaxHealth() / 10 << " health" << endl;
            mainCharacter.heal(mainCharacter.getMaxHealth() / 10);
        }

        
        
        
    }
    
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+ VICTORY! +-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << endl;
    cout << "Congrats adventurer on your first victory, although beware there are many more battles to come" << endl;
    mainCharacter.setMaxHealth(mainCharacter.getMaxHealth() + 2);
    mainCharacter.setHealth(mainCharacter.getMaxHealth());
    cout << "You have gained 2 max health points and have been completly healed" << endl;
    cout << "As a reward you now get a " << items[1].getName() << " to help you with your quest" << endl;
    weapon = items[1];
    
    weaponLevel++;
    pressSpace();
}


void Game::puzzle(int level) {
    int randomPuzzle = rand() % 10;
    char selection;
    
    
    if (randomPuzzle == 0) {
        cout << "In the morning I walk on two legs, in the afternoon I walk on two lefs, and in the evening I walk on three legs. What am I?" << endl;
        cout << "[a] Insect  [b] Animal  [c] Human  [d] Nothing" << endl;
        cin >> selection;
        selection = tolower(selection);
        if (selection == 'c') {
            cout << "Congratulations, you are correct. Please accept this " << items[weaponLevel + 2].getName() << " as your reward." << endl;
            weapon = items[weaponLevel + 2];
            weaponLevel = weaponLevel + 2;
        } else {
            cout << "Oh I'm sorry, that was not the correct answer." << endl;
        }
    } else if (randomPuzzle == 1) {
        cout << "I’m born from dripping drops in soggy sky and grow in swelling froth where rivers flow, but no hand sways me while I’m swimming by or else my guts are spilled out everywhere and fragile breath disperses in thin air. I lead my team downstream with throngs in tow, since many friends have birthdates that we share." << endl;
        cout << "[a] Bubble  [b] Tadpole  [c] Leaf  [d] Fish" << endl;
        cin >> selection;
        selection = tolower(selection);
        if (selection == 'a') {
            cout << "Congratulations, you are correct. Please accept this " << items[weaponLevel + 2].getName() << " as your reward." << endl;
            weapon = items[weaponLevel + 2];
            weaponLevel = weaponLevel + 2;
        } else {
            cout << "Oh I'm sorry, that was not the correct answer." << endl;
        }
    } else if (randomPuzzle == 2) {
        cout << "Im made, a willow-wood shaved-leather blend, for taking battles to the bitter end. A body’s safety is my body’s job so Orcus will not have a life to rob. What other soldier bears such a hardship or so many fatal injuries in war?" << endl;
        cout << "[a] Sword  [b] General  [c] Peace  [d] Sheild" << endl;
        cin >> selection;
        selection = tolower(selection);
        if (selection == 'd') {
            cout << "Congratulations, you are correct. Please accept this " << items[weaponLevel + 2].getName() << " as your reward." << endl;
            weapon = items[weaponLevel + 2];
            weaponLevel = weaponLevel + 2;
        } else {
            cout << "Oh I'm sorry, that was not the correct answer." << endl;
        }
    } else if (randomPuzzle == 3) {
        cout << "Spawned without seed, produced in ways of wonder, I load my sweetened breast with floral plunder; kings’ honeyed fare grows gilded through my flair. Sharp spears of fearsome war are what I bear, and I beat - handless! - the craftsmen’s metalware." << endl;
        cout << "[a] Bee  [b] Crown  [c] Throne  [d] Anvil and Hammer" << endl;
        cin >> selection;
        selection = tolower(selection);
        if (selection == 'a') {
            cout << "Congratulations, you are correct. Please accept this " << items[weaponLevel + 2].getName() << " as your reward." << endl;
            weapon = items[weaponLevel + 2];
            weaponLevel = weaponLevel + 2;
        } else {
            cout << "Oh I'm sorry, that was not the correct answer." << endl;
        }
    } else if (randomPuzzle == 4) {
        cout << "Who is not stunned by my amazing fate when with great strength I prop up countless trees? Soon, though, a slender spike relieves great weight. Birds in the sky and fish that swim in seas began their life from me in yesteryear; my hold on one third of the world is clear." << endl;
        cout << "[a] Mountains  [b] Roots  [c] Water  [d] Eggs" << endl;
        cin >> selection;
        selection = tolower(selection);
        if (selection == 'c') {
            cout << "Congratulations, you are correct. Please accept this " << items[weaponLevel + 2].getName() << " as your reward." << endl;
            weapon = items[weaponLevel + 2];
            weaponLevel = weaponLevel + 2;
        } else {
            cout << "Oh I'm sorry, that was not the correct answer." << endl;
        }
    } else if (randomPuzzle == 5) {
        cout << "No one can hold me in his palms or sight: I scatter sudden clatter far and wide. I want to hammer oaks with mournful might; yes, I strike sky and scour countryside." << endl;
        cout << "[a] Hammers  [b] Lightning  [c] Wind  [d] Fire" << endl;
        cin >> selection;
        selection = tolower(selection);
        if (selection == 'c') {
            cout << "Congratulations, you are correct. Please accept this " << items[weaponLevel + 2].getName() << " as your reward." << endl;
            weapon = items[weaponLevel + 2]; weaponLevel = weaponLevel + 2;
        } else {
            cout << "Oh I'm sorry, that was not the correct answer." << endl;
        }
    } else if (randomPuzzle == 6) {
        cout << "First I was finely crafted from Earth’s breast; from brutal bulls he made up all the rest - or, rather, made from goats with their foul smell! For many of the dead, I close their eyes as he who guards my lord (though I’m undressed). Yes, home is made of leather to cut to size and shaved-down wood from lumber that they fell." << endl;
        cout << "[a] Tree  [b] Lock  [c] Dagger  [d] Coffin" << endl;
        cin >> selection;
        selection = tolower(selection);
        if (selection == 'c') {
            cout << "Congratulations, you are correct. Please accept this " << items[weaponLevel + 2].getName() << " as your reward." << endl;
            weapon = items[weaponLevel + 2];
            weaponLevel = weaponLevel + 2;
        } else {
            cout << "Oh I'm sorry, that was not the correct answer." << endl;
        }
    } else if (randomPuzzle == 7) {
        cout << "I share now with the surf one destiny in rolling cycles when each month repeats. As beauty in my brilliant form retreats, so too the surges fade in the cresting sea." << endl;
        cout << "[a] Fish  [b] Mirror  [c] Waves  [d] Moon" << endl;
        cin >> selection;
        selection = tolower(selection);
        if (selection == 'd') {
            cout << "Congratulations, you are correct. Please accept this " << items[weaponLevel + 2].getName() << " as your reward." << endl;
            weapon = items[weaponLevel + 2];
            weaponLevel = weaponLevel + 2;
        } else {
            cout << "Oh I'm sorry, that was not the correct answer." << endl;
        }
    } else if (randomPuzzle == 8) {
        cout << "Where ocean pounds the craggy cliffs in the sky and surging surf is rising with the tide, A scaffold built my mighty structure high So I could point out sea-routes like a guide. I do not roam calm oceans with an oar nor plow the deep with rowers as they lurch, yet lead lost boats, pushed by huge waves, to shore while signalling from my exalted perch in lofty towers, setting inflagrations, as clouds of winter shroud bright constellations." << endl;
        cout << "[a] Moon  [b] Iceberg  [c] Lighthouse  [d] Stars" << endl;
        cin >> selection;
        selection = tolower(selection);
        if (selection == 'c') {
            cout << "Congratulations, you are correct. Please accept this " << items[weaponLevel + 2].getName() << " as your reward." << endl;
            weapon = items[weaponLevel + 2];
            weaponLevel = weaponLevel + 2;
        } else {
            cout << "Oh I'm sorry, that was not the correct answer." << endl;
        }
    } else if (randomPuzzle == 9) {
        cout << "From two materials, palms molded me. My insides glow; these guts - for sure a looting of flax or some thin reed - shine brilliantly, though flesh produced from flowers yellow now. They’re belching fire as flames and sparks are shooting, and maudlin tears keep dripping down my brow, so I still clear night’s shadows that I feared; they leave ash smudges where my guts were seared." << endl;
        cout << "[a] Battle  [b] Sword  [c] Blood  [d] Candle" << endl;
        cin >> selection;
        selection = tolower(selection);
        if (selection == 'd') {
            cout << "Congratulations, you are correct. Please accept this " << items[weaponLevel + 2].getName() << " as your reward." << endl;
            weapon = items[weaponLevel + 2];
            weaponLevel = weaponLevel + 2;
        } else {
            cout << "Oh I'm sorry, that was not the correct answer." << endl;
        }
    } else if (randomPuzzle == 10) {
        cout << "From the frozen bowels of dewy earth I’m bred; from woolen fleece with bristles I’m not made. They pull no yarn, no humming threads cascade, no Chinese silkworms weave their yellow thread, I am not plucked from wheel, no stiff combs beat, and yet I’m labelled “clothing” on the street. Long quivers’ arrows do not stir my dread." << endl;
        cout << "[a] Armour  [b] Fur  [c] Cloak  [d] Tree Bark" << endl;
        cin >> selection;
        selection = tolower(selection);
        if (selection == 'a') {
            cout << "Congratulations, you are correct. Please accept this " << items[weaponLevel + 2].getName() << " as your reward." << endl;
            weapon = items[weaponLevel + 2];
            weaponLevel = weaponLevel + 2;
        } else {
            cout << "Oh I'm sorry, that was not the correct answer." << endl;
        }
    } else {
        cout << "You don't see any travellers on the road right now, check back later" << endl;
    }
    
    pressSpace();
}


void Game::finalEncounter() {
        cout << "+--------------------------------------------------------------------------------------------------------------+" << endl;
   
    cout << "You have come far warrior, and you have upgraded your skills. But you stand before the DEMON KING whom you must slay to save the land" << endl;
        cout << "+--------------------------------------------------------------------------------------------------------------+" << endl;
   
    
    Character demonKing = Character();
    demonKing.setName("DEMON KING");
    demonKing.setHealth(120);
    demonKing.setStrength(20);
    demonKing.setType(0);
    
    pressSpace();
    printGraphic("graphics/demonking.txt");
    
    
    
    
    int attack = 0;
    int dmgWeapon = mainCharacter.getStrength() * weapon.getDamage();
    
    // cout << demonKing.getHealth() << endl;
    
    
    // MAIN ATTACK LOOP
    while (demonKing.getHealth() > 0) {
        char selection;
        int dodge = mainCharacter.getSpeed();
        bool dodgeSuccessful = false;
        bool spellChosen = false;
        
        do {
            cout << "[W]eapon  :  [S]pell  :  [D]odge  :  [V]iew Stats ";
            cin >> selection;
                    
            // ATTACK WITH WEAPON
            if (selection == 'w') {
                
                attack = (mainCharacter.getStrength() * weapon.getDamage() * (rand() % 10)) / 10;
                demonKing.setHealth(demonKing.getHealth() - attack);
                
                // tests for battle system
                // cout << attack << endl;
                // cout << (dmgWeapon - (dmgWeapon / 4)) << endl;
                
                if (attack > (dmgWeapon - (dmgWeapon / 4))) {
                    cout << "> " << mainName << " special attacks with a weapon dealing " << attack << " damage" << endl;
                } else {
                    cout << "> " << mainName << " attacks with a weapon dealing " << attack << " damage" << endl;
                }
                
            // CAST A SPELL
            } else if (selection == 's') {
                if (spell1.getDamage() + spell1.getDamage() + spell1.getDamage() == -3) {
                    cout << "You have no spells to cast" << endl;
                    selection = '0';
                } else {
                    cout << "Pick the spell you would like to cast: [1]" <<  spell1.getName() << "  [2]" << spell2.getName() << "  [3]" << spell3.getName() << endl;
                    
                    while (spellChosen == false) {
                        cin >> selection;
                        if (selection == '1') {
                            mainCharacter.heal(spell1.getDamage());
                            cout << "> " << mainName << " has healed and gained " << spell1.getDamage() << " health. You now have " << mainCharacter.getHealth() << " total health" << endl;
                            spellChosen = true;
                        } else if (selection == '2') {
                            demonKing.damage(spell2.getDamage(),spell1.getElemental());
                            cout << "> " << mainName << " attacks with " << spell2.getName() << " spell " << spell2.getDamage() << " damage" << endl;
                            spellChosen = true;
                        } else if (selection == '3') {
                            demonKing.damage(spell2.getDamage(),spell1.getElemental());
                            cout << "> " << mainName << " attacks with " << spell3.getName() << " spell " << spell3.getDamage() << " damage" << endl;
                            spellChosen = true;
                        } 
                    }
                    selection = 's';
                }
                
                
            // ATTEMPT TO DODGE ATTACK
            } else if (selection == 'd') {
                dodge = dodge + 60;
                
                
            // VIEW YOUR HEALTH AND WEAPON
            } else if (selection == 'v') {
                    cout << "STATS: Health: " << mainCharacter.getHealth() << "  Mana: " << mainCharacter.getMana() << "  Weapon: " << weapon.getName() << endl;
                    selection = '0';
            } else {
                cout << "Please enter a valid input" << endl;
            }
            
            
        } while (checkInput(selection) == false);
        
        // decide if the player dodged the attack or not
        if (dodge > (rand() % 100)) {
            dodgeSuccessful = true;
        }
        
        
        // this computes whether the player dodges the attack
        if (dodgeSuccessful == false) {
            attack = (demonKing.getStrength() * (rand() % 10)) / 10;
            mainCharacter.setHealth(mainCharacter.getHealth() - attack);
            cout << "> " << demonKing.getName() << " attacks dealing " << attack << " damage. You now have " << mainCharacter.getHealth() << endl;
            
        } else {
            cout << "> You successfully dodged the enemy attack and gained " << mainCharacter.getMaxHealth() / 10 << " health" << endl;
            mainCharacter.heal(mainCharacter.getMaxHealth() / 10);
        }

        if (mainCharacter.getHealth() < 0) {
            printGraphic("graphics/dead.txt");
            cout << endl;
            cout << "                YOU DIED            " << endl;
            cout << "You will be returned to your last campsite" << endl;
            died = true;
            pressSpace();
            break;
        } 
        
        
    }
    
    printGraphic("graphics/banner.txt");
    cout << endl;
    cout << "Thank you for playing!" << endl;
    
    
    
    
    pressSpace();
    
    
    
}











// --------------------------------------------------------------

bool checkInput(char input) {
    bool valid = false;
    
    if (input == 'w') {
        valid = true;
    } else if (input == 's') {
        valid = true;
    } else if (input == 'd') {
        valid = true;
    } else if (input == 'v') {
        valid = true;
    }
    return valid;
}