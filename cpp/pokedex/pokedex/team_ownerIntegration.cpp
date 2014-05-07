
#include "pokedex.h"

// TEAMS

void						pokedex::addTeam(const QString& tname, const owner& o)
{
	std::list<team>::iterator i;

	for(i = this->_teams.begin(); i != this->_teams.end(); ++i)
	{
		if (i->getName() == tname)
		{
			QMessageBox::warning(this, "Error", "Team name already used.");
			return;
		}
	}

	team	t(tname, o);

	this->_teams.push_back(t);
}

void						pokedex::delTeam(const QString& tname)
{
	std::list<team>::iterator i;

	for(i = this->_teams.begin(); i != this->_teams.end(); ++i)
	{
		if (i->getName() == tname)
		{
			this->_teams.erase(i);
			return ;
		}
	}
}

const team&					pokedex::getTeam(const QString& tname)
{
	std::list<team>::iterator i;

	for(i = this->_teams.begin(); i != this->_teams.end(); ++i)
	{
		if (i->getName() == tname)
			return (*i);
	}
	QMessageBox::warning(this, "Error", "Team not found.");
	return (*(this->_teams.begin()));
}

const std::list<team>&		pokedex::getTeams(void) const
{
	return (this->_teams);
}

const std::list<team>		pokedex::getTeamsOwner(const owner& o)
{
	std::list<team>			teams;
	std::list<team>::iterator i;

	for(i = this->_teams.begin(); i != this->_teams.end(); ++i)
	{
		if (i->getOwner()->getName() == o.getName())
			teams.push_back(*i);
	}
	return (teams);
}


// OWNERS

void						pokedex::addOwner(const QString& oname, const QString& avatar)
{
	std::list<owner>::iterator i;

	for(i = this->_owners.begin(); i != this->_owners.end(); ++i)
	{
		if (i->getName() == oname)
		{
			QMessageBox::warning(this, "Error", "Username already used.");
			return;
		}
	}

	owner	o(oname, avatar);

	this->_owners.push_back(o);
}

void						pokedex::delOwner(const QString& oname)
{
	std::list<team>::iterator i;

	for(i = this->_teams.begin(); i != this->_teams.end(); ++i)
	{
		if (i->getOwner()->getName() == oname)
			delTeam(i->getName());
	}

	std::list<owner>::iterator it;

	for(it = this->_owners.begin(); it != this->_owners.end(); ++it)
	{
		if (it->getName() == oname)
		{
			this->_owners.erase(it);
			return ;
		}
	}
}

const std::list<owner>&		pokedex::getOwners(void) const
{
	return (this->_owners);
}

const owner&				pokedex::getOwner(const QString& oname)
{
	std::list<owner>::iterator it;

	for (it = this->_owners.begin(); it != this->_owners.end(); ++it)
	{
		if (it->getName() == oname)
		{
			return (*it);
		}
	}
	QMessageBox::warning(this, "Error", "Owner not found.");
	return (*(this->_owners.begin()));
}
