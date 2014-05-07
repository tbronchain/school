
#include "pokedex.h"

// CANONICAL CLASS

owner::owner(const QString& name, const QString& avatar)
: _oname(name),
_avatar(avatar)
{

}

owner::owner(const owner& t)
: _oname(t._oname),
_avatar(t._avatar)
{
}

owner::~owner(void)
{
}

owner&					owner::operator=(const owner& t)
{
	if (this != &t)
	{
		this->_oname = t._oname;
		this->_avatar = t._avatar;
	}
	return (*this);
}


// GETTERS

const QString&			owner::getName(void) const
{
	return (this->_oname);
}

const QString&			owner::getAvatar(void) const
{
	return (this->_avatar);
}


// SETTER

void					owner::setAvatar(const QString& avatar)
{
	this->_avatar = avatar;
}
