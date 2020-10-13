#include <iostream>

class Herbivore abstract
{
protected:
	int weight;
	bool life = true;
public:
	int getWeight()
	{
		return weight;
	}

	bool getLife()
	{
		return life;
	}

	void setWeight(int newWeight)
	{
		weight = newWeight;
	}

	void setLife(bool newLife)
	{
		life = newLife;
	}

	virtual void Eat_Grass() abstract;
};

class Carnivore abstract
{
protected:
	int power;
public:
	int getPower()
	{
		return power;
	}

	void setPower(int newPower)
	{
		power = newPower;
	}

	virtual void Eat(Herbivore *Animal) abstract;
};

class Wildebeest : public Herbivore
{
public:
	void Eat_Grass() override
	{
		std::cout << "\nWilderbeest eat grass\n"
			<< "Weight - " << (weight += 10)
			<< "\nLife - " << (weight > 0 ? life = false : life = true);
	}
};

class Bison : public Herbivore
{
public:
	void Eat_Grass() override
	{
		std::cout << "\nBison eat grass\n"
			<< "Weight - " << (weight += 10)
			<< "\nLife - " << (weight > 0 ? life = false : life = true);
	}
};

class Elk : public Herbivore
{
	void Eat_Grass() override
	{
		std::cout << "\nElk eat grass\n"
			<< "Weight - " << (weight += 10)
			<< "\nLife - " << (weight > 0 ? life = false : life = true);
	}
};

class Lion : public Carnivore
{
public:
	void Eat(Herbivore *Animal) override
	{
		Animal->getWeight() > power ? power -= 10 : power += 10;
		std::cout << "\nLion try eat animal\n"
			<< "Current Power - " << power;
	}
};

class Wolf : public Carnivore
{
public:
	void Eat(Herbivore *Animal) override
	{
		Animal->getWeight() > power ? power -= 10 : power += 10;
		std::cout << "\nWolf try eat animal\n"
			<< "Current Power - " << power;
	}
};

class Tiger : public Carnivore
{
public:
	void Eat(Herbivore *Animal) override
	{
		Animal->getWeight() > power ? power -= 10 : power += 10;
		std::cout << "\nTiger try eat animal\n"
			<< "Current Power - " << power;
	}
};

class Continent abstract
{
public:
	virtual Herbivore* Create_Herbivore() abstract;
	virtual Carnivore* Create_Carnivore() abstract;
};

class Africa : public Continent
{
public:
	Herbivore* Create_Herbivore() override
	{
		return new Wildebeest();
	}

	Carnivore* Create_Carnivore() override
	{
		return new Lion();
	}
};

class North_America : public Continent
{
public:
	Herbivore* Create_Herbivore() override
	{
		return new Bison();
	}

	Carnivore* Create_Carnivore() override
	{
		return new Wolf();
	}
};

class Eurasia :public Continent
{
public:
	Herbivore* Create_Herbivore() override
	{
		return new Elk();
	}

	Carnivore* Create_Carnivore() override
	{
		return new Tiger();
	}
};

class Animal_World
{
	Herbivore *HAnimal;
	Carnivore *CAnimal;
public:
	Animal_World(Continent *p)
	{
		HAnimal = p->Create_Herbivore();
		CAnimal = p->Create_Carnivore();
	}

	void Meals_Herbivore()
	{
		HAnimal->Eat_Grass();
	}

	void Nutrition_Carnivores()
	{
		CAnimal->Eat(HAnimal);
	}
};

int main()
{
	Animal_World* World = new Animal_World(new North_America());
	World->Meals_Herbivore();
	World->Nutrition_Carnivores();
	World->Nutrition_Carnivores();
	std::cout << std :: endl;
	delete World;

	World = new Animal_World(new Africa());
	World->Nutrition_Carnivores();
	World->Meals_Herbivore();
	World->Nutrition_Carnivores();
	std::cout << std::endl;
	delete World;

	World = new Animal_World(new Eurasia());
	World->Meals_Herbivore();
	World->Nutrition_Carnivores();
	World->Meals_Herbivore();
	World->Nutrition_Carnivores();
	std::cout << std::endl;
	std::cout << std::endl;
	delete World;
}