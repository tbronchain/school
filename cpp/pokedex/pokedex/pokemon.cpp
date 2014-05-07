
#include "pokedex.h"


// CANONICAL CLASS

pokemon::pokemon(int id)
: _id(id)
{
	_image = "../img/" + QString::number(_id) + ".png";
	_stats.insert(_stats.begin(), 7, 0);
}

pokemon::~pokemon(void)
{
}

pokemon::pokemon(const pokemon& p)
{
	_id = p._id;
	_name = p._name;
	_type = p._type;
	_ability = p._ability;
	_evo = p._evo;
	_ratio_male = p._ratio_male;
	_ratio_female = p._ratio_female;
	_egg_group = p._egg_group;
	_species = p._species;
	_height = p._height;
	_weight = p._weight;
	_description = p._description;
	_move = p._move;
	_exp = p._exp;
	_stats = p._stats;
	_image = p._image;
}

pokemon&	pokemon::operator=(const pokemon& p)
{
	if (this != &p)
	{
		this->_id = p._id;
		this->_name = p._name;
		this->_type = p._type;
		this->_ability = p._ability;
		this->_evo = p._evo;
		this->_ratio_male = p._ratio_male;
		this->_ratio_female = p._ratio_female;
		this->_egg_group = p._egg_group;
		this->_species = p._species;
		this->_height = p._height;
		this->_weight = p._weight;
		this->_description = p._description;
		this->_move = p._move;
		this->_exp = p._exp;
		this->_stats = p._stats;
		this->_image = p._image;
	}
	return (*this);
}


// GETTERS

int							pokemon::getId(void) const
{
	return (this->_id);
}

const QString&				pokemon::getName(void) const
{
	return (this->_name);
}

const std::vector<QString>&	pokemon::getType(void) const
{
	return (this->_type);
}

const QString&				pokemon::getAbility(void) const
{
	return (this->_ability);
}

const std::vector<s_evo>&	pokemon::getEvo(void) const
{
	return (this->_evo);
}

float						pokemon::getRatioMale(void) const
{
	return (this->_ratio_male);
}

float						pokemon::getRatioFemale(void) const
{
	return (this->_ratio_female);
}

const std::vector<QString>&	pokemon::getEggGroup(void) const
{
	return (this->_egg_group);
}

const QString&				pokemon::getSpecies(void) const
{
	return (this->_species);
}

float						pokemon::getHeight(void) const
{
	return (this->_height);
}

float						pokemon::getWeight(void) const
{
	return (this->_weight);
}

const QString&				pokemon::getDescription(void) const
{
	return (this->_description);
}

const std::vector<s_move>&	pokemon::getMove(void) const
{
	return (this->_move);
}

int							pokemon::getExp(void) const
{
	return (this->_exp);
}

const std::vector<int>&		pokemon::getStats(void) const
{
	return (this->_stats);
}

const QString&				pokemon::getImage(void) const
{
	return (this->_image);
}


// SPECIAL GETTERS

const QString				pokemon::getEvoByLevel(const int& lvl) const
{
	for (unsigned int i = 0; i < this->_evo.size(); ++i)
	{
		if (this->_evo[i].lvl == lvl)
			return (this->_evo[i].name);
	}
	return (NULL);
}

const std::vector<s_evo>	pokemon::getEvoLevels(void) const
{
	std::vector<s_evo>		evo;

	for (unsigned int i = 0; i < this->_evo.size(); ++i)
	{
		if (this->_evo[i].lvl)
			evo.push_back(this->_evo[i]);
	}
	return (evo);
}

const std::vector<s_evo>	pokemon::getEvoSpecials(void) const
{
	std::vector<s_evo>		evo;

	for (unsigned int i = 0; i < this->_evo.size(); ++i)
	{
		if (!this->_evo[i].lvl)
			evo.push_back(this->_evo[i]);
	}
	return (evo);
}

const std::vector<s_move>	pokemon::getMoveByLevel(const int& lvl) const
{
	std::vector<s_move>		move;

	for (unsigned int i = 0; i < this->_move.size(); ++i)
	{
		if (this->_move[i].lvl == lvl)
			move.push_back(this->_move[i]);
	}
	return (move);
}

int							pokemon::getStatsSome(const STATS& stat) const
{
	return (this->_stats[stat]);
}


// SETTERS

void		pokemon::setName(const QString& name)
{
	this->_name = name;
}

void		pokemon::setType(const std::vector<QString>& type)
{
	this->_type = type;
}

void		pokemon::setAbility(const QString& ability)
{
	this->_ability = ability;
}

void		pokemon::setRatioMale(const float& ratio)
{
	this->_ratio_male = ratio;
}

void		pokemon::setRatioFemale(const float& ratio)
{
	this->_ratio_female = ratio;
}

void		pokemon::setEggGroup(const std::vector<QString>& egg)
{
	this->_egg_group = egg;
}

void		pokemon::setSpecies(const QString& sp)
{
	this->_species = sp;
}

void		pokemon::setHeight(const float& f)
{
	this->_height = f;
}

void		pokemon::setWeight(const float& f)
{
	this->_weight = f;
}

void		pokemon::setDescription(const QString& s)
{
	this->_description = s;
}

void		pokemon::setExp(const int& exp)
{
	this->_exp = exp;
}

void		pokemon::setStats(const std::vector<int>& stats)
{
	this->_stats = stats;
}

void		pokemon::setEvo(const std::vector<s_evo>& evolution)
{
	this->_evo = evolution;
}

void		pokemon::setMove(const std::vector<s_move>& a)
{
	this->_move = a;
}


// SPECIAL SETTERS

void		pokemon::addType(const QString& type)
{
	this->_type.push_back(type);
}

void		pokemon::addEggGroup(const QString& egg)
{
	this->_egg_group.push_back(egg);
}

void		pokemon::addStat(const STATS& stat, const int &value)
{
	this->_stats.at(stat) = value;
}

void		pokemon::addEvo(const int& id, const QString& name)
{
	this->addEvo(id, name, NULL, 0);
}

void		pokemon::addEvo(const int& id, const QString& name, const int& lvl)
{
	this->addEvo(id, name, NULL, lvl);
}

void		pokemon::addEvo(const int& id, const QString& name, const QString& condition)
{
	this->addEvo(id, name, condition, 0);
}

void		pokemon::addEvo(const int& id, const QString& name, const QString& condition, const int& lvl)
{
	s_evo	evo;

	evo.id = id;
	evo.name = name;
	evo.condition = condition;
	evo.lvl = lvl;
	this->_evo.push_back(evo);
}

void		pokemon::addMove(const TYPE& type, const QString& name)
{
	this->addMove(type, name, MACHINE_NULL, 0);
}

void		pokemon::addMove(const TYPE& type, const QString& name, const MACHINE& machine, const int& lvl)
{
	s_move	move;

	move.type = type;
	move.name = name;
	move.machine = machine;
	move.lvl = lvl;
	this->_move.push_back(move);
}
