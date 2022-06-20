#ifndef GRASS_HPP
#define GRASS_HPP

#include "Plant.hpp"
#include "Seeds.hpp"

class Grass : public Plant {
public:
	Grass() :Plant("Grass", 20) {
	}
	Harvest::uPoiner harvest() {
		decreaseHarvest();
		return std::make_unique<Seeds>(); 
	}
	
};

#endif