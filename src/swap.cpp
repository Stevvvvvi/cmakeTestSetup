#include "swap.h"
#include <jsoncpp/json/json.h>
#include <fstream>

void swap::run()
{
    int temp;
    temp = m_a;
    m_a = m_b;
    m_b = temp;
}


void swap::printInfo()
{
    std::cout << "m_a is " << m_a << std::endl;
    std::cout << "m_b is " << m_b << std::endl;
}

void swap::processJson()
{
    std::ifstream people_file("people.json", std::ifstream::binary);
    Json::Value people;
    people_file >> people;
    std::cout << people; //This will print the entire json object.
    //The following lines will let you access the indexed objects.
    std::cout<< "value of Anna : " << people["Anna"] << std::endl; //Prints the value for "Anna"
    std::cout<< "value of ben : " <<people["ben"] << std::endl; //Prints the value for "Ben"
    std::cout<< "value of Anna profession : " <<people["Anna"]["profession"] << std::endl; //Prints the value corresponding to "profession" in the json for "Anna"

    std::cout<< "value of profession : " <<people["profession"]<< std::endl; //NULL! There is no element with key "profession". Hence a new empty element will be created.
}