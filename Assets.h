#pragma once
#include <string>
#include <map>

std::map<std::string, std::string> story = {

{"paragraph1", "In the Grand Castle ___, set in Romania, the Bram Castle Museum has been closed for a private event held by Sir Alexandru Albescu.A lavish banquet was in full swing.Distinguished nobles such as an old countess from Sweden and the Baroness from Holland had gathered to celebrate."
},
    {"paragraph2" , "As the night progressed, some of the guests as well as the butlers and the maids would disappear and unease was settled among the revellers.Suddenly, Sir Alexandru Albescu collapsed and held onto the castle's large silk banners as the goblet he held in his hand dropped creating a large sound which echoed through the room. The wine in the goblet spilled everywhere and panic rippled through the crowd as all the guests and all the maids and butlers stood in silence."
},
    {"paragraph3", "Luckily, a young couple who were on their honeymoon, one of them happened to be a doctor.Dr.Ella Newton was called to the body and declared that Sir Alexandru had been poisoned."},
{"paragraph4", "hispers of conspiracy spread like wildfire amongst the hall.Suspicion fell upon all of the guests, each harbouring secrets and motives of their own."}
};



std::map<std::string, std::string> desChar = {
      {"inspector", "description inspector"},
    {
        "princess","a young, very beautiful woman with bright red hair that is cut short into a fashionable bob. She wears a sleek blue dress with subtle rhinestones.",
    },
      {"baroness", "description baroness"},
      {"worker", "description worker"},
      {"madame", "description madame"},
};

std::map<std::string, std::string> descriptionRoom = {
    {"library_room", "King Ferdinand's Library"},
    {"throne_room", "Throne Room description"},
    {"weapon_room", "The weapon room 'King Carol the First' "},

	{"marie_room", "Queen Marie's Apartment"},
    {"court_room", "Throne room description"},
    {"restaurant_room", "Dracula's Restaurant"},

	{"observatory_room", " library description"},
    {"entrance_room", "throne description"},
    {"oriental_room", "The Oriental Room"},

};

std::map<std::string, std::string> nameRooms = {
	{"library_room", "King Ferdinand's Library"},
    {"throne_room", "Throne Room description"},
    {"weapon_room", "The weapon room 'King Carol the First' "},

    {"marie_room", "Queen Marie's Apartment"},
    {"court_room", "Throne room description"},
    {"restaurant_room", "Dracula's Restaurant"},

    {"observatory_room", " library description"},
    {"entrance_room", "throne description"},
    {"oriental_room", "The Oriental Room"},

}

/*

entranceWay.setDescription(descriptionRoom["entrance_room"]);
courtyard.setDescription(descriptionRoom["court_room"]);
throneRoom.setDescription(descriptionRoom["throne_room"]);
library.setDescription("King Ferdinand's Library");
queenMariesApt.setDescription("Queen Marie's Apartment");
observatory.setDescription("The Prince Vlad's Observatory");
restaurant.setDescription("Dracula's Restaurant");
weaponRoom.setDescription("The weapon room 'King Carol the First' ");
orientalRoom.setDescription("The Oriental Room");
*/