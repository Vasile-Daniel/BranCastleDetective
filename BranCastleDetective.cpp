// BranCastleDetective.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Room.h"
#include "Character.h"
#include "Assets.h"

int main()
{
    std::cout << "GAME NAME: Catle Dracula Murder mistery\n";

    ///////////   Set up GAME OBJECTS    //////////////////////////////////////////////////// 



    // ROOMS: name, description 
    // CHARACTER:  name, pronoun, description, keywords, promted line, speaking line 

    // Set up LIST OF ROOMS (9 rooms)
    Room entranceWay;
    Room courtyard;
    Room throneRoom;
    Room library;
    Room queenMariesApt;
    Room observatory;
    Room restaurant;
    Room weaponRoom;
    Room orientalRoom;

    //Set up LIST OF CHARACTERS ( 5 characters)
    Character inspector;
    Character princess;
    Character baroness;
    Character worker;
    Character madame;

    // ************ START SET UP ROOMS ******************************************

    // Set up NAMES OF THE ROOMS 
    entranceWay.setName("The Grand Entrance");
    courtyard.setName("Castle Courtyard");
    throneRoom.setName("The Throne Room");
    library.setName("King Ferdinand's Library");
    queenMariesApt.setName("Queen Marie's Apartment");
    observatory.setName("The Prince Vlad's Observatory");
    restaurant.setName("Dracula's Restaurant");
    weaponRoom.setName("The weapon room 'King Carol the First' ");
    orientalRoom.setName("The Oriental Room");



    // Set up DESCRIPTION OF ROOMS 
    entranceWay.setDescription(descriptionRoom["entrance_room"]);
    courtyard.setDescription(descriptionRoom["court_room"]);
    throneRoom.setDescription(descriptionRoom["throne_room"]);
    library.setDescription(descriptionRoom[""]);
    queenMariesApt.setDescription(descriptionRoom[""]);
    observatory.setDescription(descriptionRoom[""]);
    restaurant.setDescription(descriptionRoom[""]);
    weaponRoom.setDescription(descriptionRoom[""]);
    orientalRoom.setDescription(descriptionRoom[""]);

    // ********** END SET UP ROOMS *********************************************


    // ************ START SET UP CHARACTERS  ******************************************
    //Set up CHARACTER NAME  
    inspector.setName("Inspector");
    princess.setName("Penelope");
    baroness.setName("Helena Van Arsdale");
    worker.setName("Andrzej");
    madame.setName("Madame Ionescu");

    //Set up CHARACTER PRONOUN 
    inspector.setPronoun({ "he", "him" });
    princess.setPronoun({ "she", "her" });
    baroness.setPronoun({ "she", "her" });
    worker.setPronoun({"he", "him"});
    madame.setPronoun({"she", "her"});


    //Set up CHARACTER DESCRIPTION 
    inspector.setDescription(desChar["inspector"]);
    princess.setDescription(desChar["princess"]);
    baroness.setDescription(desChar["baroness"]);
    worker.setDescription(desChar["worker"]);
    madame.setDescription(desChar["madame"]);

    //Set up CHARACTER KEYWORDS 
    inspector.setKeyWords({"1","2"});
    princess.setKeyWords({ "knife","flower" });
    baroness.setKeyWords({ "1","2" });
    worker.setKeyWords({ "1","2" });
    madame.setKeyWords({ "1","2" });


    //Set up CHARACTER PROMPTED LINE
    inspector.setPromptedLine({ "1","2" });
    princess.setPromptedLine({ "1","2" });
    baroness.setPromptedLine({ "1","2" });
    worker.setPromptedLine({ "1","2" });
    madame.setPromptedLine({ "1","2" });

    //Set up CHARACTER SPEAKING LINE 
    inspector.setSpeakingLine({ "1","2" });
    princess.setSpeakingLine({ "1","2" });
    baroness.setSpeakingLine({ "1","2" });
    worker.setSpeakingLine({ "1","2" });
    madame.setSpeakingLine({ "1","2" });

    // ************ END SET UP CHARACTERS ******************************************

    // **************** START LINK THE ROOMS ******************************************* 
   
    // middle map 
    courtyard.linked_rooms["north"] = &throneRoom;
    courtyard.linked_rooms["east"] = &restaurant;
    courtyard.linked_rooms["south"] = &entranceWay;
    courtyard.linked_rooms["east"] = &queenMariesApt;

    // left side - middle 
    queenMariesApt.linked_rooms["east"] = &courtyard;
    queenMariesApt.linked_rooms["north"] = &library;
    queenMariesApt.linked_rooms["south"] = &observatory;
    
    // right side - middle 
    restaurant.linked_rooms["west"] = &courtyard;
    restaurant.linked_rooms["north"] = &weaponRoom;
    restaurant.linked_rooms["south"] = &orientalRoom;



    // rooms top map (left to right, soth)
    library.linked_rooms["south"] = &queenMariesApt;
    throneRoom.linked_rooms["south"] = &courtyard;
    weaponRoom.linked_rooms["south"] = &restaurant;

    // rooms bottom map (left to right, north) 
    observatory.linked_rooms["north"] = &queenMariesApt;
    entranceWay.linked_rooms["north"] = &courtyard;

    // ************ END LINK THE ROOMS  *******************************************



    // ************* START LINK THE CHARACTERS TO THE ROOMS **************************
    
    entranceWay.linked_Characters["princess"] = &princess;
    entranceWay.linked_Characters["madame"] = &madame;

    restaurant.linked_Characters["worker"] = &worker;

    queenMariesApt.linked_Characters["baroness"] = &baroness;

    // ************* END  LINK THE CHARACTERS TO THE ROOMS **************************
    // 
    // 
    // 
    // 
    // ************* START LINK THE CLUES TO THE ROOMS *************************************
     // ************* END LINK THE CLUES TO THE ROOMS *************************************

    Room* currentRoom = &entranceWay;
    Character* currentChar = &inspector;
    std::string command;
    bool changeRoom = true;
    do
    {
        //if you change rooms you get a description, this only runs the first time you enter a room
        if (changeRoom == true)
        {
            //giving you a description of the room
            std::cout << "Looking around "
                + currentRoom->getName()
                + " you see "
                + currentRoom->getDescription()
                + "\n";
            changeRoom = false;
            //telling you what characters are in the room
            if (!currentRoom->linked_Characters.empty())
            {
                // Get an iterator pointing to the first element in the map

                std::map<std::string, Character*>::iterator it = currentRoom->linked_Characters.begin();

                // Iterate through the map and print the elements
                std::cout << "in this room you see:\n";
                while (it != currentRoom->linked_Characters.end())
                {
                    std::cout << it->first << "\n";
                    ++it;
                }
            }
        }


        std::cout << "> ";
        std::cin >> command;
        //add commands here
            //adding the capability to talk to a character in the room
        if (currentRoom->linked_Characters.find(command) != currentRoom->linked_Characters.end())
        {
            currentChar = currentRoom->linked_Characters[command];
            std::cout << "As you approach "
                + currentChar->getPronoun()[1]
                + " you see "
                + currentChar->getDescription()
                + "\n\n";
            if (!currentChar->getSpeakingLine().empty())
            {
                std::cout << currentChar->getSpeakingLine()[0];
            }
        }
        //specific key word used?
        else if (currentChar != &inspector)
        {
            for (int i = 0; i < currentChar->getKeyWords().size(); i++)
            {
                if (command == currentChar->getKeyWords()[i])
                {
                    std::cout << currentChar->getPromptedLine()[i] << "\n";
                }
            }
        }
        //the command to change rooms
        else if (currentRoom->linked_rooms.find(command) != currentRoom->linked_rooms.end())
        {
            currentRoom = currentRoom->linked_rooms[command];
            currentChar = &inspector; //when leaving a room the character focus returns to the inspector
            changeRoom = true;
        }
        //a map command
        else if (command == "map")
        {
            std::cout << "----------------------------------------------------------\n"
                "|                  |                  |                  |\n"
                "|   Library        |   Throne         |    Weapon        |\n"
                "|                  |       Room       |        Room      |\n"
                "|                  |                  |                  |\n"
                "|                  |                  |                  |\n"
                "|                  |                  |                  |\n"
                "---------  -----------------  -----------------  ---------\n"
                "|                  |                  |                  |\n"
                "|   Queen Marie's  |   Courtyard      |    Dining        |\n"
                "|    apartments                                Room      |\n"
                "|                                                        |\n"
                "|                  |                  |                  |\n"
                "|                  |                  |                  |\n"
                "---------  -----------------  -----------------  ---------\n"
                "|                  |                  |                  |\n"
                "|   Observatory    |    Entrance      |    Oriental      |\n"
                "|                  |        Hall      |        Room      |\n"
                "|                  |                  |                  |\n"
                "|                  |                  |                  |\n"
                "|                  |                  |                  |\n"
                "----------------------------------------------------------\n";
        }
        else
        {
            std::cout << "You can't do that\n";
        }
    } while (command != "exit");


}




    



