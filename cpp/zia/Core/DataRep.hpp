#ifndef _ZIA_API_DATAREP_H_
#define _ZIA_API_DATAREP_H_

#include <iostream>
#include <string>
#include <map>
#include <list>

#include "defines.hpp"

_BOF_ZIA_API_

        class DataRep
{
public:
    DataRep();
    virtual ~DataRep();
    bool									hasValue(const std::string& key) const;
    bool									hasList(const std::string& key) const;
    const std::string&                                                          value(const std::string& key) const;
    void                                                        		value(const std::string& key, const std::string& value);
    std::list< std::string >&							list(const std::string& key);
    const std::list< std::string >&						const_list(const std::string& key) const;
    void									clear();
    void									print(std::ostream& out) const;

protected:

    std::map< std::string, std::string >				mValues;
    std::map< std::string, std::list< std::string > >                   mLists;
    std::string								mNullString;
    std::list< std::string >						mEmptyList;
};

_EOF_ZIA_API_

#endif /* _ZIA_API_DATAREP_H_ */
