#ifndef _ZIA_API_DATATREE_H_
#define _ZIA_API_DATATREE_H_

#include <map>
#include <string>
#include <iostream>
#include <list>

#include "defines.hpp"

_BOF_ZIA_API_

/*!
 * \brief Data Tree representation.
 *
 *
 * <h2> Zia core implementations: </h2>
 * \code

//
// DataRep implementation:
//

DataTree::DataTree();
DataTree::~DataTree();
DataTree::operator const std::string& () const;
DataTree&               DataTree::operator = (const DataTree& dataTree);
DataTree&               DataTree::operator = (const std::string& value);
DataTree&               DataTree::operator += (const DataTree& dataTree);
const DataTree&         DataTree::operator [] (const std::string& key) const;
DataTree&               DataTree::operator [] (const std::string& key);
bool                    DataTree::operator == (const std::string& right) const;
bool                    DataTree::operator != (const std::string& right) const;
const DataTree&         DataTree::c() const;
const std::string&      DataTree::v() const;
bool                    DataTree::has(const std::string& key) const;
const DataTree&         DataTree::get(const std::string& key) const;
void                    DataTree::clear();
void                    DataTree::print(std::ostream& out, int indentLevel = 0) const;

 * \endcode
 *
 */
class DataTree
{
public:
    /*!
     * \brief Sub DataTrees.
     */
    std::map<std::string, DataTree>     mSubs;
    /*!
     * \brief Value.
     */
    std::string                         mValue;
    /*!
     * \brief List of value.
     */
    std::list<std::string>              mList;

    /*!
     * \brief Constructor.
     */
    DataTree();
    /*!
     * \brief Desctructor.
     */
    virtual ~DataTree();

    /*!
     * \brief Return mValue.
     */
    operator const std::string& () const;
    /*!
     * \brief Operator =.
     */
    DataTree&               operator = (const DataTree& dataTree);
    /*!
     * \brief Set mValue.
     */
    DataTree&               operator = (const std::string& value);
    /*!
     * \brief Merge.
     *
     * \a this is a priority.
     */
    DataTree&               operator += (const DataTree& dataTree);
    /*!
     * \brief Get mSubs key const.
     */
    const DataTree&         operator [] (const std::string& key) const;
    /*!
     * \brief Get mSubs[key].
     */
    DataTree&               operator [] (const std::string& key);
    /*!
     * \brief Test mValue.
     */
    bool                    operator == (const std::string& right) const;
    /*!
     * \brief Test mValue.
     */
    bool                    operator != (const std::string& right) const;

    /*!
     * \brief Get constant this.
     */
    const DataTree&         c() const;
    /*!
     * \brief Get mValue;
     */
    const std::string&      v() const;
    /*!
     * \brief Check has mSubs key.
     */
    bool                    has(const std::string& key) const;
    /*!
     * \brief Get mSubs key.
     */
    const DataTree&         get(const std::string& key) const;
    /*!
     * \brief Clear all.
     */
    void                    clear();
    /*!
     * \brief Print datas in out.
     */
    void                    print(std::ostream& out, int indentLevel = 0) const;

};

_EOF_ZIA_API_

#endif /* _ZIA_API_DATATREE_H_ */
