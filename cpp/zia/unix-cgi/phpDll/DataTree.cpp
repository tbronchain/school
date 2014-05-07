#include "DataTree.hpp"

zia::api::DataTree::DataTree()
{

}

zia::api::DataTree::~DataTree()
{

}

zia::api::DataTree::operator const std::string & () const
{
	return (this->mValue);
}

zia::api::DataTree&		zia::api::DataTree::operator = (const DataTree& dataTree)
{
	this->mList = dataTree.mList;
	this->mValue = dataTree.mValue;
	this->mSubs = dataTree.mSubs;
	return (*this);
}

zia::api::DataTree&		zia::api::DataTree::operator = (const std::string& value)
{
	this->mValue = value;
	return (*this);
}

const zia::api::DataTree&											zia::api::DataTree::operator [] (const std::string& key) const
{
	DataTree														toInsert;
	std::map<std::string, DataTree >::const_iterator				it = this->mSubs.begin();
	std::pair< std::map< std::string, DataTree >::iterator, bool >	ret;

	if ((it = this->mSubs.find(key)) == this->mSubs.end())
	{
	}
	return ((*it).second);
}

zia::api::DataTree&													zia::api::DataTree::operator [] (const std::string& key)
{
	DataTree														toInsert;
	std::map<std::string, DataTree >::iterator						it = this->mSubs.begin();
	std::pair< std::map< std::string, DataTree >::iterator, bool >	ret;

	if ((it = this->mSubs.find(key)) == this->mSubs.end())
	{
		ret = this->mSubs.insert(std::pair<std::string, DataTree >(key, toInsert));
		return (ret.first->second);
	}
	return ((*it).second);
}

bool		zia::api::DataTree::operator == (const std::string& right) const
{
	if (this->mValue == right)
		return (true);
	return (false);
}

bool		zia::api::DataTree::operator != (const std::string& right) const
{
	if (this->mValue != right)
		return (true);
	return (false);
}

bool		zia::api::DataTree::has(const std::string& key) const
{
	std::map<std::string, DataTree >::const_iterator	it = this->mSubs.begin();

	if ((it = this->mSubs.find(key)) == this->mSubs.end())
		return (false);
	else
		return (true);
}

const zia::api::DataTree&		zia::api::DataTree::get(const std::string& key) const
{
	std::map<std::string, DataTree >::const_iterator	it = this->mSubs.begin();
	std::pair< std::map< std::string, std::list< std::string > >::iterator, bool >	ret;

	it = this->mSubs.find(key);
	if (it == this->mSubs.end())
		;
	return (it->second);
}

const zia::api::DataTree&		zia::api::DataTree::c() const
{
	return (*this);
}

const std::string&		zia::api::DataTree::v() const
{
	return (this->mValue);
}

void		zia::api::DataTree::clear()
{
	this->mSubs.clear();
	this->mValue = "";
	this->mList.clear();
}
