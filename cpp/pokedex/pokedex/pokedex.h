#ifndef POKEDEX_H
#define POKEDEX_H

#include <iostream>
#include <vector>
#include <list>
#include <QApplication>
#include <QtGui>
#include <QtXml>
#include <QWidget>
#include <QMainWindow>

#include "ui_pokedex.h"
#include "pokemon.h"
#include "owner.h"
#include "team.h"

//typedef void (pokedex::*pMeth)(QDomNode noeud, pokemon &poke);

#define	NB_WIDGET 4
#define	NB_BUTTON 4
#define WIDTH_WIDGET 275
#define	WIDTH_BUTTON 25

class pokedex : public QMainWindow
{
	Q_OBJECT

public:	
							pokedex(QWidget *parent = 0, Qt::WFlags flags = 0);
							pokedex(const pokedex&);
							~pokedex();
	pokedex&				operator=(const pokedex&);

	// parser
	void					addPokemonAttributesRec(QDomNode &noeud, pokemon &poke);
	void					parse();
	void					parse_name(const QDomNode &noeud, pokemon &poke);
	void					parse_type(const QDomNode &noeud, pokemon &poke);
	void					parse_ability(const QDomNode &noeud, pokemon &poke);
	void					parse_exp(const QDomNode &noeud, pokemon &poke);
	void					parse_stats(const QDomNode &noeud, pokemon &poke);
	void					parse_evolutions(const QDomNode &noeud, pokemon &poke);
	void					parse_evolution(const QDomNode &noeud, pokemon &poke);
	void					parse_ratio(const QDomNode &noeud, pokemon &poke);
	void					parse_eggGroup(const QDomNode &noeud, pokemon &poke);
	void					parse_species(const QDomNode &noeud, pokemon &poke);
	void					parse_height(const QDomNode &noeud, pokemon &poke);
	void					parse_weight(const QDomNode &noeud, pokemon &poke);
	void					parse_description(const QDomNode &noeud, pokemon &poke);
	void					parse_moves(const QDomNode &noeud, pokemon &poke);
	void					parse_move(const QDomNode &noeud, pokemon &poke);

	// teams
	void					addTeam(const QString&, const owner&);
	void					delTeam(const QString&);
	const team&				getTeam(const QString&);
	const std::list<team>&	getTeams(void) const;
	const std::list<team>	getTeamsOwner(const owner&);

	// owners
	void					addOwner(const QString&, const QString&);
	void					delOwner(const QString&);
	const std::list<owner>&	getOwners(void) const;
	const owner&			getOwner(const QString&);

private slots:
	void					slotReduce1();
	void					slotReduce2();
	void					slotReduce3();
	void					slotReduce4();
	void					slotIncrease1();
	void					slotIncrease2();
	void					slotIncrease3();
	void					slotIncrease4();
	void					reduceSize(int i);
	void					increaseSize(int i);
	void					displayPok();
	void					displayTeams();
	void					displayOwners();
	void					displayListPok();
	void					displayInfoPok(QListWidgetItem* current, QListWidgetItem* previous);

private:
	Ui::pokedexClass		_ui;
	QDomDocument*			_dom;
	QFile*					_xml_doc;
	std::vector<pokemon>	_pokemons;
	std::list<owner>		_owners;
	std::list<team>			_teams;
};



#endif // POKEDEX_H
