#include "DataRep.hpp"

using namespace zia::api;

DataRep::DataRep()
{
	this->mNullString = "";
}

DataRep::~DataRep()
{
	this->mValues.clear();
	this->mLists.clear();
}

bool														DataRep::hasValue(const std::string& key) const
{
	std::map< std::string, std::string >::const_iterator	it = this->mValues.begin();

	if ((it = this->mValues.find(key)) == this->mValues.end())
		return (false);
	else
		return (true);
}

bool																	DataRep::hasList(const std::string& key) const
{
	std::map< std::string, std::list< std::string > >::const_iterator	it = this->mLists.begin();

	if ((it = this->mLists.find(key)) == this->mLists.end())
		return (false);
	else
		return (true);
}

const std::string&											DataRep::value(const std::string& key) const
{
	std::map< std::string, std::string >::const_iterator	it = this->mValues.begin();

	if ((it = this->mValues.find(key)) == this->mValues.end())
		return (this->mNullString);
	else
		return (it->second);
}

void		DataRep::value(const std::string& key, const std::string& value)
{
	this->mValues.insert(std::pair< std::string, std::string >(key, value));
}

std::list< std::string >&															DataRep::list(const std::string& key)
{
	std::pair< std::map< std::string, std::list< std::string > >::iterator, bool >	ret;
	std::list< std::string >														toInsert;
	std::map< std::string, std::list< std::string > >::iterator						it = this->mLists.begin();

	if ((it = this->mLists.find(key)) == this->mLists.end())
	{
		ret = this->mLists.insert(std::pair<std::string, std::list< std::string > >(key, toInsert));
		return (ret.first->second);
	}
	else
		return ((*it).second);
}

const std::list< std::string >&											DataRep::const_list(const std::string& key) const
{
	std::map< std::string, std::list< std::string > >::const_iterator	it = this->mLists.begin();

	if ((it = this->mLists.find(key)) == this->mLists.end())
		return (this->mEmptyList);
	else
		return (it->second);
}

void		DataRep::clear()
{
	this->mLists.clear();
	this->mValues.clear();
}

void		DataRep::print(std::ostream&) const
{

}
