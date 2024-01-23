class Creatures
{
protected:
	std::string m_name{};
	char m_symbol{};
	int m_health{};
	int m_dmg{};
	int m_gold{};

public:
	Creatures(const std::string& name = "", const char& symbol = 'a',
		const int& health = 0, const int& dmg = 0
		, const int& gold = 0)
		: m_name{ name }
		, m_symbol{ symbol }
		, m_health{ health }
		, m_dmg{ dmg }
		, m_gold{ gold }
	{
	}
	const std::string& getName() const { return m_name; }
	const char getSymbol() const { return m_symbol; }
	const int getHealth() const { return m_health; }
	const int getDmg() const { return m_dmg; }
	const int getGold() const { return m_gold; }
	void addGold(int gold) {
		m_gold += gold;
	}
	void reduceHealth(int dmg) {
		m_health -= dmg;
	}
	bool isDead() {
		return { m_health <= 0 };
	}

};

class Monster : public Creatures
{
public:
	enum class Type {
		dragon,
		orc,
		slime,
		maxtypes
	};
	static const Creatures& getDefaultCreature(Type type)
	{
		static const std::array<Creatures, static_cast<std::size_t>(Type::maxtypes)>monsterData{
			{{"dragon",'D',20,4,100},
			{"orc",'O',4,2,25},
			{"slime",'s',1,1,10}}
		};
		return monsterData.at(static_cast<std::size_t>(type));
	}

	Monster(Type type)
		: Creatures{ getDefaultCreature(type) }
	{
	}



	int attack() {

	}
};

class player : public Creatures
{
private:
	int m_level{};
public:

	player(const std::string& a)
		: Creatures{ a,'@',10,1,0 }
	{
	}

	int getLevel() {
		return m_level;
	}
	bool hasWon() {
		return m_level >= 20;
	}
	void levelUp(Monster& m) {
		m_level += 1;
		m_dmg += 1;
		m_gold += m.getGold();
	}

};




static const Monster getRandomMonster() {

	std::mt19937 mt{ static_cast<unsigned int>(
	std::chrono::steady_clock::now().time_since_epoch().count()
	) };
	std::uniform_int_distribution monstertypes{ 0, (static_cast<int>(Monster::Type::maxtypes) - 1) };

	return Monster{ static_cast<Monster::Type>(monstertypes(mt)) };
}


Monster nextmonster() {


	Monster x{ getRandomMonster() };
	std::cout << "the next monster is a " << x.getName();
	return { x };
}

bool playerfight(player& p, Monster& m) {

	m.reduceHealth(p.getDmg());
	std::cout << "you dealt " << p.getDmg() << " to the " << m.getName() << "\n";
	if (m.isDead())
	{
		std::cout << "and killed it! \n";
		p.levelUp(m);
		m = nextmonster();
		return true;
	}
	return false;

}

void endGame() {

	std::cout << "you died ";
	exit;
}

void monsterfight(player& p, Monster& m) {

	p.reduceHealth(m.getDmg());
	if (p.isDead()) {

	}
	std::cout << "you took " << m.getDmg() << " your health is now " << p.getHealth() << "\n";
}

bool cointoss() {

	std::mt19937 mt{ static_cast<unsigned int>(
	std::chrono::steady_clock::now().time_since_epoch().count()
	) };
	std::uniform_int_distribution x{ 0, 1 };

	return static_cast<int>(x(mt));

}

void turn(player& p, Monster& m) {
	std::cout << "what do you want to do f to fight or r to run\n";
	char x{};
	std::cin >> x;
	if (x == 'f')
	{
		if (playerfight(p, m) != true)
		{
			monsterfight(p, m);
		}
	}
	else if (x == 'r')
	{
		if (cointoss()) {
			m = { nextmonster() };
		}
		else
			monsterfight(p, m);
	}
}



int main()
{
	std::cout << "what is your name";
	std::string x{};
	std::cin >> x;
	player p{ x };
	Monster currentMonster{ getRandomMonster() };
	std::cout << "you encountered a " << currentMonster.getName();
	while (p.hasWon() != true && p.isDead() != true)
	{
		turn(p, currentMonster);
	}
	if (p.isDead()) {
		std::cout << "you died :/ \n you were level " << p.getLevel() << "and you had " << p.getGold();
	}
	else
		std::cout << "you Won! \n" << "and you had " << p.getGold();
	return 0;
}