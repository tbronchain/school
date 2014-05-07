#ifndef TEAM_H
# define TEAM_H

class	team
{
public:
	// canonical class
								team(const QString&, const owner&);
								team(const team&);
								~team(void);
	team&						operator=(const team&);

	// getters
	const QString&				getName(void) const;
	const owner*				getOwner(void) const;
	const std::list<const pokemon*>&
								getPokemons(void) const;

	// setter
	void						addPokemon(const pokemon&);

private:
	QString						_tname;
	const owner*				_owner;
	std::list<const pokemon*>	_pok;
};

#endif // TEAM_H
