#include "classes.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include <vector>
int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
    std::cout << "Введите название оружия: " << std::endl;
        std::string weaponName;
        Equip equipKit1;
        getline(std::cin, weaponName);
        try {
            equipKit1.setWeaponName(weaponName);
            std::cout << "Оружие: " << equipKit1.getWeaponName() << std::endl;
        }
        catch (...) {
            std::cout << "Ошибка!" << std::endl;
        }

        Equip stormtrooperKit("AK-47", "6B33", "6B11-M");
        Equip sniperKit("ВСК-94", "6B47", "Модуль-5М");
        Equip artillerymanKit("Абакан", "П7", "6B13");

        std::vector<std::vector<Equip>> gearList(3);
        gearList[0].push_back(stormtrooperKit);
        gearList[1].push_back(sniperKit);
        gearList[2].push_back(artillerymanKit);

        Equip stormtrooperKit2 = Equip("VAL", "6B37", "6B11-M");
        Armory armory1 = Armory(2, 1, 1, gearList);
        armory1.addGearToArmory(stormtrooperKit2, 1);
        armory1.printGearInArmory();

        
    


}
