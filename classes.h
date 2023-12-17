#define _CRT_SECURE_NO_WARNINGS
#define LEN 32
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <vector>





class Equip {

private:

	std::string weaponName;
	std::string helmetName;
	std::string armorName;

public:

	Equip() = default;

	Equip(
		std::string setWeaponName,
		std::string setHelmetName,
		std::string setArmorName
	) {
		weaponName = setWeaponName;
		helmetName = setHelmetName;
		armorName = setArmorName;
	}

	void setWeaponName(
		std::string newWeaponName
	) {
		if (newWeaponName == "") {
			throw std::string{ "Вы ввели пустую строку!"};
		}
		this->weaponName = newWeaponName;
	}

	void setHelmetName(
		std::string newHelmetName
	) {
		this->helmetName = newHelmetName;
	}

	void setArmorName(
		std::string newArmorName
	) {
		this->armorName = newArmorName;
	}

	std::string getWeaponName() {
		return weaponName;
	}

	std::string getHelmetName() {
		return helmetName;
	}

	std::string getArmorName() {
		return armorName;
	}

	void createEquipKit(Equip* equipKitStorage) {
		std::string weaponNameStorage;
		std::string helmetNameStorage;
		std::string armorNameStorage;

		std::cout << "Введите комлект снаряжения:" << std::endl;
		std::cout << std::endl;

		std::cout << "Введите название оружия: ";
		std::cin >> weaponNameStorage;
		std::cout << std::endl;

		std::cout << "Введите название бронешлема: ";
		std::cin >> helmetNameStorage;
		std::cout << std::endl;


		std::cout << "Введите название бронежилета: ";
		std::cin >> armorNameStorage;
		std::cout << std::endl;

		equipKitStorage->weaponName = weaponNameStorage;
		equipKitStorage->helmetName = helmetNameStorage;
		equipKitStorage->armorName = armorNameStorage;

	}

	void printEquipKit() {
		std::cout << "Оружие: " << weaponName << std::endl;
		std::cout << "Бронешлем: " << helmetName << std::endl;
		std::cout << "Бронежилет: " << armorName << std::endl;
		std::cout << std::endl;
	}
};

class Soldier {

private:

	std::string callSign;
	int equipNumber;
	Equip equipKit;
	static int soldierNumber;

public:

	Soldier() {
		soldierNumber++;
	};

	Soldier(
		std::string setCallSign,
		int setEquipNumber,
		Equip setEquipKit
	) {
		soldierNumber++;
		callSign = setCallSign;
		equipNumber = setEquipNumber;
		equipKit = setEquipKit;
	}

	static void getSoldierNumber() {
		printf("Общее количество солдат: %d\n", soldierNumber);
	}

	void setCallSign(
		std::string newCallSign
	) {
		callSign = newCallSign;
	}

	void setNewEquip(
		int newEquipNumber,
		Equip newEquipKit
	) {
		equipNumber = newEquipNumber;
		equipKit = newEquipKit;
	}

	std::string getCallSign() {
		return callSign;
	}

	int getEquipNumber() {
		return equipNumber;
	}

	Equip getEquipKit() {
		return equipKit;
	}

	void createSoldier(Soldier& soldierDataStorage) {
		std::string callSignStorage;
		int equipNumberStorage;
		Equip equipKitStorage;

		std::cout << "Введите позывной солдата: ";
		std::cin >> callSignStorage;
		std::cout << std::endl;

		std::cout << "Введите номер комплекта снаряжения: ";
		std::cin >> equipNumberStorage;
		std::cout << std::endl;

		equipKitStorage.createEquipKit(&equipKitStorage);

		soldierDataStorage.callSign = callSignStorage;
		soldierDataStorage.equipNumber = equipNumberStorage;
		soldierDataStorage.equipKit = equipKitStorage;

	}

	void printSoldier() {
		std::cout << "Позывной солдата: " << callSign << std::endl;
		std::cout << "Номер комплекта снаряжения: " << equipNumber << std::endl;
		std::cout << "Комлпект снаряжения: " << std::endl;
		equipKit.printEquipKit();
	}

};

class Troop {

private:

	int troopNumber;
	std::string troopType;
	int soldiersCount;
	std::vector<Soldier> soldiersList;

public:

	Troop() {
		this->troopNumber = 0;
		this->troopType = "";
		this->soldiersCount = 0;

	};

	Troop(
		int setTroopNumber,
		std::string setTroopType,
		int setSoldiersCount,
		std::vector<Soldier> setSoldiersList
	) {
		troopNumber = setTroopNumber;
		troopType = setTroopType;
		soldiersCount = setSoldiersCount;
		soldiersList = setSoldiersList;

	}

	friend Troop operator+(Troop troopDataStorage, int troopNumberChange) {
		return Troop(troopDataStorage.troopNumber + troopNumberChange,
			troopDataStorage.troopType,
			troopDataStorage.soldiersCount,
			troopDataStorage.soldiersList);
	}

	Troop& operator++() {
		this->troopNumber++;
		return *this;
	}

	friend Troop operator++(Troop troopDataStorage, int) {
		Troop tempTroop = troopDataStorage;
		++tempTroop.troopNumber;
		return tempTroop;
	}

	void setTroopNumber(
		int newTroopNumber
	) {
		troopNumber = newTroopNumber;
	}

	void setTroopType(
		std::string newTroopType
	) {
		troopType = newTroopType;
	}

	void setSoldiersList(
		int newSoldiersCount,
		std::vector<Soldier> newSoldiersList
	) {
		soldiersCount = newSoldiersCount;
		soldiersList = newSoldiersList;
	}

	int getTroopNumber() {
		return troopNumber;
	}

	std::string getTroopType() {
		return troopType;
	}

	int getSoldiersCount() {
		return soldiersCount;
	}

	std::vector<Soldier> getSoldiersList() {
		return soldiersList;
	}

	void createTroop() {

		int troopNumberStorage;
		std::string troopTypeStorage;
		int soldiersCountStorage;
		std::vector<Soldier> soldiersListStorage;
		Soldier soldierDataStorage;

		std::cout << "Введите номер взвода: ";
		std::cin >> troopNumberStorage;
		std::cout << std::endl;

		std::cout << "Введите тип взвода: ";
		std::cin >> troopTypeStorage;
		std::cout << std::endl;

		std::cout << "Введите количество солдат во взводе: ";
		std::cin >> soldiersCountStorage;
		std::cout << std::endl;

		for (int i = 0; i < soldiersCountStorage; i++) {
			soldierDataStorage.createSoldier(soldierDataStorage);
			soldiersListStorage.push_back(soldierDataStorage);
		}

		this->troopNumber = troopNumberStorage;
		this->troopType = troopTypeStorage;
		this->soldiersCount = soldiersCountStorage;
		this->soldiersList = soldiersListStorage;

	}

	void printTroop() {

		std::cout << "Номер взвода: " << troopNumber << std::endl;
		std::cout << "Тип взвода: " << troopType << std::endl;
		std::cout << "Количество солдат во взводе: " << soldiersCount << std::endl;
		std::cout << "Список солдат: " << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < soldiersCount; i++) {
			soldiersList[i].printSoldier();
		}
	}

	void addSoldier(Soldier soldierDataStorage) {
		soldiersCount++;
		soldiersList.push_back(soldierDataStorage);
	}

	void deleteSoldier() {
		int deleteSoldierNumber;

		std::cout << "Список солдат: " << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < soldiersCount; i++) {
			std::cout << "Солдат " << i + 1 << ":" << std::endl;
			soldiersList[i].printSoldier();
		}

		std::cout << "Введите номер солдата, которого хотите удалить:" << std::endl;
		do {

			std::cin >> deleteSoldierNumber;

			if (deleteSoldierNumber > soldiersCount) {
				std::cout << "Солдата с таким номером не существует. Повторите ввод" << std::endl;
			}
		} while (deleteSoldierNumber > soldiersCount);
		soldiersList.erase(soldiersList.begin() + deleteSoldierNumber - 1);
		soldiersCount--;
	}
};

class Company {

private:

	int companyNumber;
	std::string companyType;
	int troopsCount;
	std::vector<Troop> troopsList;

public:

	Company() = default;

	Company(
		int setCompanyNumber,
		std::string setCompanyType,
		int setTroopsCount,
		std::vector<Troop> setTroopsList
	) {
		companyNumber = setCompanyNumber;
		companyType = setCompanyType;
		troopsCount = setTroopsCount;
		troopsList = setTroopsList;
	}

	void setCompanyNumber(
		int newCompanyNumber
	) {
		companyNumber = newCompanyNumber;
	}

	void setCompanyType(
		std::string newCompanyType
	) {
		companyType = newCompanyType;
	}

	void setTroopsList(
		int newTroopsCount,
		std::vector<Troop> newTroopsList
	) {
		troopsCount = newTroopsCount;
		troopsList = newTroopsList;
	}

	void createCompany(){

		int companyNumberStorage;
		std::string companyTypeStorage;
		int troopsCountStorage;
		std::vector<Troop> troopsListStorage;
		Troop troopDataStorage;

		std::cout << "Введите номер роты: ";
		std::cin >> companyNumberStorage;
		std::cout << std::endl;

		std::cout << "Введите тип роты: ";
		std::cin >> companyTypeStorage;
		std::cout << std::endl;

		std::cout << "Введите количество взводов в роте: ";
		std::cin >> troopsCountStorage;
		std::cout << std::endl;

		for (int i = 0; i < troopsCountStorage; i++) {
			troopDataStorage.createTroop();
			troopsListStorage.push_back(troopDataStorage);
		}

		this->companyNumber = companyNumberStorage;
		this->companyType = companyTypeStorage;
		this->troopsCount = troopsCountStorage;
		this->troopsList = troopsListStorage;
	}

	void printCompany() {

		std::cout << "Номер роты: " << companyNumber << std::endl;
		std::cout << "Тип роты: " << companyType << std::endl;
		std::cout << "Количество взводов в роте: " << troopsCount << std::endl;
		std::cout << "Список взводов: " << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < troopsCount; i++) {
			troopsList[i].printTroop();
		}
	}

	void addTroop(Troop troopDataStorage) {
		troopsCount++;
		troopsList.push_back(troopDataStorage);
	}

	void deleteTroop() {
		int deleteTroopNumber;

		std::cout << "Список взводов: " << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < troopsCount; i++) {
			std::cout << "Взвод " << i + 1 << ":" << std::endl;
			troopsList[i].printTroop();
		}

		std::cout << "Введите номер взвода, которого хотите удалить:" << std::endl;
		do {

			std::cin >> deleteTroopNumber;

			if (deleteTroopNumber > troopsCount) {
				std::cout << "Солдата с таким номером не существует. Повторите ввод" << std::endl;
			}
		} while (deleteTroopNumber > troopsCount);
		troopsList.erase(troopsList.begin() + deleteTroopNumber - 1);
		troopsCount--;
	}

};

class Battalion {

private:

	int battalionNumber;
	std::string battalionType;
	int companiesCount;
	std::vector<Company> companiesList;

public:

	Battalion() = default;

	Battalion(
		int setBattalionNumber,
		std::string setBattalionType,
		int setCompaniesCount,
		std::vector<Company> setCompaniesList
	) {
		battalionNumber = setBattalionNumber;
		battalionType = setBattalionType;
		companiesCount = setCompaniesCount;
		companiesList = setCompaniesList;
	}

	void setBattalionNumber(
		int newBattalionNumber
	) {
		battalionNumber = newBattalionNumber;
	}

	void setBattalionType(
		std::string newBattalionType
	) {
		battalionType = newBattalionType;
	}

	void setCompaniesList(
		int newCompaniesCount,
		std::vector<Company> newCompaniesList
	) {
		companiesCount = newCompaniesCount;
		companiesList = newCompaniesList;
	}

	void createBattalion() {

		int battalionNumberStorage;
		std::string battalionTypeStorage;
		int companiesCountStorage;
		std::vector<Company> companiesListStorage;
		Company companyDataStorage;

		std::cout << "Введите номер батальона: ";
		std::cin >> battalionNumberStorage;
		std::cout << std::endl;

		std::cout << "Введите тип батальона: ";
		std::cin >> battalionTypeStorage;
		std::cout << std::endl;

		std::cout << "Введите количество рот в батальоне: ";
		std::cin >> companiesCountStorage;
		std::cout << std::endl;

		for (int i = 0; i < companiesCountStorage; i++) {
			companyDataStorage.createCompany();
			companiesListStorage.push_back(companyDataStorage);
		}

		this->battalionNumber = battalionNumberStorage;
		this->battalionType = battalionTypeStorage;
		this->companiesCount = companiesCountStorage;
		this->companiesList = companiesListStorage;
	}

	void printBattalion() {

		std::cout << "Номер батальона: " << battalionNumber << std::endl;
		std::cout << "Тип батальона: " << battalionType << std::endl;
		std::cout << "Количество рот в батальоне: " << companiesCount << std::endl;
		std::cout << "Список рот: " << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < companiesCount; i++) {
			companiesList[i].printCompany();
		}
	}

	void addCompany(Company companyDataStorage) {
		companiesCount++;
		companiesList.push_back(companyDataStorage);
	}

	void deleteCompany() {
		int deleteCompanyNumber;

		std::cout << "Список рот: " << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < companiesCount; i++) {
			std::cout << "Рота " << i + 1 << ":" << std::endl;
			companiesList[i].printCompany();
		}

		std::cout << "Введите номер роты, которую хотите удалить:" << std::endl;
		do {

			std::cin >> deleteCompanyNumber;

			if (deleteCompanyNumber > companiesCount) {
				std::cout << "Роты с таким номером не существует. Повторите ввод" << std::endl;
			}
		} while (deleteCompanyNumber > companiesCount);
		companiesList.erase(companiesList.begin() + deleteCompanyNumber - 1);
		companiesCount--;
	}

};

class Armory {
private:
	int stormtrooperGearCount;
	int sniperGearCount;
	int artilleryGearCount;
	std::vector<std::vector<Equip>> gearList;

public:
	Armory() {
		this->stormtrooperGearCount = 0;
		this->sniperGearCount = 0;
		this->artilleryGearCount = 0;
		this->gearList.resize(3);
	}

	Armory(int stormtrooperGearCount,
		int sniperGearCount,
		int artilleryGearCount,
		std::vector<std::vector<Equip>> gearList) {
		this->stormtrooperGearCount = stormtrooperGearCount;
		this->sniperGearCount = sniperGearCount;
		this->artilleryGearCount = artilleryGearCount;
		this->gearList = gearList;
	}

	int getStormtrooperGearCount() {
		return stormtrooperGearCount;
	}

	int getSniperGearCount() {
		return sniperGearCount;
	}

	int getArtilleryGearCount() {
		return artilleryGearCount;
	}

	std::vector<std::vector<Equip>> getGearList() {
		return gearList;
	}

	void setStormtrooperGearCount(int setStormtrooperGearCount) {
		this->stormtrooperGearCount = setStormtrooperGearCount;
	}

	void setSniperGearCount(int setSniperGearCount) {
		this->sniperGearCount = setSniperGearCount;
	}

	void setArtilleryGearCount(int setArtilleryGearCount) {
		this->artilleryGearCount = setArtilleryGearCount;
	}

	void setGearList(std::vector<std::vector<Equip>> setGearList) {
		this->gearList = setGearList;
	}

	void addGearToArmory(Equip newEquipKit, int gearType) {
		int gearTypeCount = 0;
		if (gearType < 1 || gearType > 3) {
			throw std::runtime_error("Введён неверный тип снаряжения!");
		}
		switch (gearType) {
		case 1:
			gearTypeCount = this->getStormtrooperGearCount();
			break;
		case 2:
			gearTypeCount = this->getSniperGearCount();
			break;
		case 3:
			gearTypeCount = this->getArtilleryGearCount();
			break;
		}
		this->gearList[gearType - 1].push_back(newEquipKit);
	}

	void printGearInArmory() {
		int gearTypeCount;
		for (int i = 0; i < 3; i++) {
			gearTypeCount = this->gearList[i].size();
			if (i == 0) {
				std::cout << "Снаряжение штурмовиков:" << std::endl;
			}
			else if (i == 1) {
				std::cout << "Снаряжение снайперов:" << std::endl;
			}
			else if (i == 2) {
				std::cout << "Снаряжение артиллеристов:" << std::endl;
			}
			for (int j = 0; j < gearTypeCount; j++) {
				std::cout << "Комплект " << (j + 1) << ":" << std::endl;
				this->gearList[i][j].printEquipKit();
			}
		}
	}
};