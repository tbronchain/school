#include "pokedex.h"
#include <QString>
#include <algorithm>

bool	sort(const pokemon& i, const pokemon& j)
{
	return (i.getId() < j.getId());
}

pokedex::pokedex(QWidget *parent, Qt::WFlags flags)
: QMainWindow(parent, flags)
{
	_ui.setupUi(this);
	this->parse();
	std::sort(this->_pokemons.begin(), this->_pokemons.end(), sort);
	this->displayListPok();

	_ui.widget3->setVisible(false);
	_ui.widget4->setVisible(false);
	_ui.removeButton3->setVisible(false);
	_ui.removeButton4->setVisible(false);
	_ui.createTeam->setVisible(false);
	_ui.createOwner->setVisible(false);

	this->resize(600, 600);
	this->setMinimumSize(QSize(600, 600));
	this->setMaximumSize(QSize(600, 600));

	connect(_ui.bPokedex, SIGNAL(clicked()), this, SLOT(displayPok()));
	connect(_ui.bTeams, SIGNAL(clicked()), this, SLOT(displayTeams()));
	connect(_ui.bOwners, SIGNAL(clicked()), this, SLOT(displayOwners()));

	connect(_ui.removeButton1, SIGNAL(clicked()), this, SLOT(slotReduce1()));
	connect(_ui.removeButton2, SIGNAL(clicked()), this, SLOT(slotReduce2()));
	connect(_ui.removeButton3, SIGNAL(clicked()), this, SLOT(slotReduce3()));
	connect(_ui.removeButton4, SIGNAL(clicked()), this, SLOT(slotReduce4()));

	if (connect(_ui.listPok, SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)), this, SLOT(displayInfoPok(QListWidgetItem*, QListWidgetItem *))) == false)
		QMessageBox::information(this, "toto", "true");
}

pokedex::~pokedex()
{
}

pokedex::pokedex(const pokedex& p) : QMainWindow()
{
	_ui = p._ui;
	_dom = p._dom;
	_xml_doc = p._xml_doc;
	_pokemons = p._pokemons;
}

pokedex&	pokedex::operator=(const pokedex& p)
{
	if (this != &p)
	{
		this->_ui = p._ui;
		this->_dom = p._dom;
		this->_xml_doc = p._xml_doc;
		this->_pokemons = p._pokemons;
	}
	return (*this);
}

void	pokedex::displayListPok()
{
	for (unsigned int i = 0; i <  this->_pokemons.size(); ++i)
	{
		_ui.listPok->addItem(QString::number(this->_pokemons[i].getId()) + " :	" + this->_pokemons[i].getName());
	}
}
