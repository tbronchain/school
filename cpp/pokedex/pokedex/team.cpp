
#include "pokedex.h"

// CANONICAL CLASS

team::team(const QString& tname, const owner& oname)
: _tname(tname),
_owner(&oname)
{
}

team::team(const team& t)
: _tname(t._tname),
_owner(t._owner)
{
	_pok = t._pok;
}

team::~team(void)
{
}

team&					team::operator=(const team& t)
{
	if (this != &t)
	{
		this->_tname = t._tname;
		this->_owner = t._owner;
		this->_pok = t._pok;
	}
	return (*this);
}


// GETTERS

const QString&						team::getName(void) const
{
	return (this->_tname);
}

const owner*						team::getOwner(void) const
{
	return (this->_owner);
}

const std::list<const pokemon*>&	team::getPokemons(void) const
{
	return (this->_pok);
}


// SETTER

void					team::addPokemon(const pokemon& pok)
{
	this->_pok.push_back(&pok);
}
