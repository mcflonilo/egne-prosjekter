/* class Monster
{

public:

	enum class MonsterType {

		dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,
		max_monster_types
	};




private:
	MonsterType m_type{};
	std::string m_name{};
	std::string m_roar{};
	int m_health{};

public:

	Monster() = default;

	Monster(MonsterType type, std::string name, std::string sound, int health)
	{
		m_type = type;
		m_name = name;
		m_roar = sound;
		m_health = health;
	}

	void print() {
		std::cout << m_name << " the " << getTypeString() << " has " << m_health << " hit points and says " << m_roar;
	}

	std::string_view getTypeString() {
		switch (m_type)
		{
		case Monster::MonsterType::dragon:
			return "dragon";
		case Monster::MonsterType::goblin:
			return "goblin";
		case Monster::MonsterType::ogre:
			return "ogre";
		case Monster::MonsterType::orc:
			return "orc";
		case Monster::MonsterType::skeleton:
			return "skeleton";
		case Monster::MonsterType::troll:
			return "troll";
		case Monster::MonsterType::vampire:
			return "vampire";
		case Monster::MonsterType::zombie:
			return "zombie";
		default:
			return "???";
		}
	}
};

class MonsterGenerator
{
private:
	static constexpr std::array s_names{ "Bones", "Jones", "jimmy", "rex", "glenn", "fido" };
	static constexpr std::array s_roars{ "grrr", "jangly bones", "i have snaids", "presidential aids", "rawr", "boooo" };
public:
	static int getRandomNumber(int min, int max)
	{
		static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };
		return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
	}

	static Monster generateMonster() {
		Monster::MonsterType type{ getRandomNumber(0,8) };
		std::string name{ s_names[getRandomNumber(0,5)] };
		std::string roar{ s_roars[getRandomNumber(0,5)] };
		int health{ getRandomNumber(1,100) };
		Monster randomMonster{ type,name,roar,health };
		return { type,name,roar,health };
	}
};


int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::rand(); // If using Visual Studio, discard first random value

	Monster m{ MonsterGenerator::generateMonster() };
	m.print();

	return 0;
}*/