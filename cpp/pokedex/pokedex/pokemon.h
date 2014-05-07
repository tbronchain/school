#ifndef POKEMON_H
# define POKEMON_H

enum TYPE
{
	TYPE_NULL,
	LEVEL,
	TH,
	EGG
};

enum MACHINE
{
	MACHINE_NULL,
	TM,
	HM
};

enum STATS
{
	STATS_NULL,
	HP,
	ATK,
	DEF,
	SPD,
	SAT,
	SDF
};

struct				s_move
{
	TYPE			type;
	QString			name;
	MACHINE			machine;
	int				lvl;
};

struct				s_evo
{
	int				id;
	QString			name;
	QString			condition;
	int				lvl;
};

class								pokemon
{
public:
	// canonical class
									pokemon(int);
									~pokemon(void);
									pokemon(const pokemon&);
	pokemon&						operator=(const pokemon&);

	// getters
	int								getId(void) const;
	const QString&					getName(void) const;
	const std::vector<QString>&		getType(void) const;
	const QString&					getAbility(void) const;
	float							getRatioMale(void) const;
	float							getRatioFemale(void) const;
	const std::vector<QString>&		getEggGroup(void) const;
	const QString&					getSpecies(void) const;
	float							getHeight(void) const;
	float							getWeight(void) const;
	const QString&					getDescription(void) const;
	int								getExp(void) const;
	const std::vector<int>&			getStats(void) const;
	const std::vector<s_evo>&		getEvo(void) const;
	const std::vector<s_move>&		getMove(void) const;
	const QString&					getImage(void) const;

	// special getters
	const QString					getEvoByLevel(const int&) const;
	const std::vector<s_evo>		getEvoLevels(void) const;
	const std::vector<s_evo>		getEvoSpecials(void) const;
	const std::vector<s_move>		getMoveByLevel(const int&) const;
	int								getStatsSome(const STATS&) const;

	// setters
	void							setName(const QString&);
	void							setType(const std::vector<QString>&);
	void							setAbility(const QString&);
	void							setRatioMale(const float&);
	void							setRatioFemale(const float&);
	void							setEggGroup(const std::vector<QString>&);
	void							setSpecies(const QString&);
	void							setHeight(const float&);
	void							setWeight(const float&);
	void							setDescription(const QString&);
	void							setExp(const int&);
	void							setStats(const std::vector<int>&);
	void							setEvo(const std::vector<s_evo>&);
	void							setMove(const std::vector<s_move>&);

	// special setters
	void							addType(const QString&);
	void							addEggGroup(const QString&);
	void							addStat(const STATS& stat, const int &value);
	void							addEvo(const int&, const QString&);
	void							addEvo(const int&, const QString&, const int&);
	void							addEvo(const int&, const QString&, const QString&);
	void							addEvo(const int&, const QString&, const QString&, const int&);
	void							addMove(const TYPE&, const QString&);
	void							addMove(const TYPE&, const QString&, const MACHINE&, const int&);

private:
	int								_id;
	QString							_name;
	std::vector<QString>			_type;
	QString							_ability;
	std::vector<s_evo>				_evo;
	float							_ratio_male;
	float							_ratio_female;
	std::vector<QString>			_egg_group;
	QString							_species;
	float							_height;
	float							_weight;
	QString							_description;
	std::vector<s_move>				_move;
	int								_exp;
	std::vector<int>				_stats;
	QString							_image;
};

#endif // POKEMON_H
