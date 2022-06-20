#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include "Harvest.hpp"
#include "Plant.hpp"
#include "Tree.hpp"
#include "Bush.hpp"
#include "Grass.hpp"
#include "BackPack.hpp"

using Environment = std::shared_ptr<std::vector<std::unique_ptr<Plant>>>;

Environment Init() {
	Environment result{std::make_shared<std::vector<std::unique_ptr<Plant>>>()};
	for (size_t i = 0; i < 10; i++) {
		result->emplace_back(std::make_unique<Tree>());
	}
	for (size_t i = 0; i < 7; i++) {
		result->emplace_back(std::make_unique<Bush>());
	}
	for (size_t i = 0; i < 5; i++) {
		result->emplace_back(std::make_unique<Grass>());
	}
	std::random_shuffle(result->begin(), result->end());
	return result;
}


using Backpack = std::vector<std::unique_ptr<Harvest>>;

int main()
{
    //получить список растений
	auto place = Init();
	
	Backpack playerBackpack;

	//перебрать все растения
	for (auto &plant : *place) {
		std::cout << "i'm near of " << plant->getName() << '\n';
		while (plant->muchHarvest()) {
			playerBackpack.push_back(plant->harvest());
		}
		std::cout << "now i have " << playerBackpack.size() << " items\n";
		std::cout << "harvest in world - " << Harvest::howMuch() << '\n';
	}

	//ну мы же на абум скидывали всё в рюкзак
	std::random_shuffle(playerBackpack.begin(), playerBackpack.end());
	
	//сообщить что нашёл
	for (const auto &item:playerBackpack) {
		std::cout << "i found " << item->getName() << " it's " <<
			item->type() << '\n';
	}

}