#include "pokedex.h"
#include <QMessageBox>


typedef struct	s_mephptr
{
	const char* tag_Name;
	void (pokedex::*pMeth)(const QDomNode &noeud, pokemon &poke);
}				t_methptr;


t_methptr	_meth[] = {
	{"name", &pokedex::parse_name},
	{"type", &pokedex::parse_type},
	{"ability", &pokedex::parse_ability},
	{"exp", &pokedex::parse_exp},
	{"stats", &pokedex::parse_stats},
	{"evolutions", &pokedex::parse_evolutions},
	{"ratio", &pokedex::parse_ratio},
	{"egg-group", &pokedex::parse_eggGroup},
	{"species", &pokedex::parse_species},
	{"height", &pokedex::parse_height},
	{"weight", &pokedex::parse_weight},
	{"description", &pokedex::parse_description},
	{"moves", &pokedex::parse_moves},
	{NULL, NULL}
};


void	pokedex::parse_move(const QDomNode &noeud, pokemon &poke)
{
	TYPE type = TYPE_NULL;
	int	lvl = 0;
	QString name = NULL;
	MACHINE machine = MACHINE_NULL;

	if (noeud.toElement().attributeNode("id").value() == "level-up")
		type = LEVEL;
	else if (noeud.toElement().attributeNode("id").value() == "TM/HM")
		type = TH;
	else if (noeud.toElement().attributeNode("id").value() == "egg")
		type = EGG;

	if (noeud.hasChildNodes())
	{
		QDomNode noeud2 = noeud.firstChild();
		while (!noeud2.isNull())
		{	
			if (noeud2.nodeName() == "name")
				name = noeud2.toElement().text();
			else if (noeud2.nodeName() == "lvl")
				lvl = noeud2.toElement().text().toInt();
			else if (noeud2.nodeName() == "machine")
			{
				if (noeud2.toElement().text() == "TM")
					machine = TM;
				else if (noeud2.toElement().text() == "HM")
					machine = HM;
			}
			noeud2 = noeud2.nextSibling();
		}
	}

	poke.addMove(type, name, machine, lvl);
}

void	pokedex::parse_moves(const QDomNode &noeud, pokemon &poke)
{
	if (noeud.hasChildNodes())
	{
		QDomNode noeud2 = noeud.firstChild();
		while (!noeud2.isNull())
		{
			this->parse_move(noeud2, poke);
			noeud2 = noeud2.nextSibling();
		}
	}
}


void	pokedex::parse_description(const QDomNode &noeud, pokemon &poke)
{
	poke.setDescription(noeud.toElement().text());
}

void	pokedex::parse_weight(const QDomNode &noeud, pokemon &poke)
{
	poke.setWeight(noeud.toElement().text().toFloat());
}

void	pokedex::parse_height(const QDomNode &noeud, pokemon &poke)
{
	poke.setHeight(noeud.toElement().text().toFloat());
}

void	pokedex::parse_species(const QDomNode &noeud, pokemon &poke)
{
	poke.setSpecies(noeud.toElement().text());
}

void	pokedex::parse_eggGroup(const QDomNode &noeud, pokemon &poke)
{
	poke.addEggGroup(noeud.toElement().text());
}


void	pokedex::parse_ratio(const QDomNode &noeud, pokemon &poke)
{
	if (noeud.hasChildNodes())
	{
		QDomNode noeud2 = noeud.firstChild();
		while (!noeud2.isNull())
		{	
			if (noeud2.nodeName() == "male")
				poke.setRatioMale(noeud2.toElement().text().toFloat());
			else if (noeud2.nodeName() == "female")
				poke.setRatioFemale(noeud2.toElement().text().toFloat());
			noeud2 = noeud2.nextSibling();
		}
	}
}

void	pokedex::parse_evolution(const QDomNode &noeud, pokemon &poke)
{
	int	id = 0;
	int	lvl = 0;
	QString name = NULL;
	QString condition = NULL;

	id = noeud.toElement().attributeNode("id").value().toInt();
	if (noeud.hasChildNodes())
	{
		QDomNode noeud2 = noeud.firstChild();
		while (!noeud2.isNull())
		{	
			if (noeud2.nodeName() == "name")
				name = noeud2.toElement().text();
			else if (noeud2.nodeName() == "lvl")
				lvl = noeud2.toElement().text().toInt();
			else if (noeud2.nodeName() == "condition")
				condition = noeud2.toElement().text();
			noeud2 = noeud2.nextSibling();
		}
	}
	poke.addEvo(id, name, condition, lvl);
}

void	pokedex::parse_evolutions(const QDomNode &noeud, pokemon &poke)
{
	if (noeud.hasChildNodes())
	{
		QDomNode noeud2 = noeud.firstChild();
		while (!noeud2.isNull())
		{
			this->parse_evolution(noeud2, poke);
			noeud2 = noeud2.nextSibling();
		}
	}
}

void	pokedex::parse_stats(const QDomNode &noeud, pokemon &poke)
{
	if (noeud.hasChildNodes())
	{
		QDomNode noeud2 = noeud.firstChild();
		while (!noeud2.isNull())
		{	
			if (noeud2.nodeName() == "HP")
				poke.addStat(HP, noeud2.toElement().text().toInt());
			else if (noeud2.nodeName() == "ATK")
				poke.addStat(ATK, noeud2.toElement().text().toInt());
			else if (noeud2.nodeName() == "DEF")
				poke.addStat(DEF, noeud2.toElement().text().toInt());
			else if (noeud2.nodeName() == "SPD")
				poke.addStat(SPD, noeud2.toElement().text().toInt());
			else if (noeud2.nodeName() == "SAT")
				poke.addStat(SAT, noeud2.toElement().text().toInt());
			else if (noeud2.nodeName() == "SDF")
				poke.addStat(SDF, noeud2.toElement().text().toInt());
			noeud2 = noeud2.nextSibling();
		}
	}
}

void	pokedex::parse_exp(const QDomNode &noeud, pokemon &poke)
{
	poke.setExp(noeud.toElement().text().toInt());
}


void	pokedex::parse_ability(const QDomNode &noeud, pokemon &poke)
{
	poke.setAbility(noeud.toElement().text());
}

void	pokedex::parse_type(const QDomNode &noeud, pokemon &poke)
{
	poke.addType("../img/" + noeud.toElement().text() + ".png");
}


void	pokedex::parse_name(const QDomNode &noeud, pokemon &poke)
{
	poke.setName(noeud.toElement().text());
}




void		pokedex::parse()
{
	_dom = new QDomDocument("pokedata");
	_xml_doc = new QFile("../docs/pokedata.xml");
	if(!_xml_doc->open(QIODevice::ReadOnly))
	{
		QMessageBox::warning(this,"Error", "The XML's document can't be open.");
		return;
	}
	if (!_dom->setContent(_xml_doc))
	{
		_xml_doc->close();
		QMessageBox::warning(this,"Error", "The XML's document can't be open.");
		return;
	}

	QDomElement dom_element = _dom->documentElement();
	QDomNode noeud = dom_element.firstChild();
	while(!noeud.isNull())
	{
		if(!dom_element.isNull())
		{
			//QMessageBox::information(this, "Nom de la balise", "Le nom de la balise est " + noeud.nodeName());
			//QMessageBox::information(this, "Nom de la balise", "La valeur de la balise est " + noeud.toElement().attributeNode("id").value());
		}
		if (noeud.hasChildNodes())
		{
			pokemon poke(noeud.toElement().attributeNode("id").value().toInt());
			QDomNode noeud2 = noeud.firstChild();
			this->addPokemonAttributesRec(noeud2, poke);
			_pokemons.push_back(poke);
		}
		noeud = noeud.nextSibling();
	}
	_xml_doc->close();
}

void	pokedex::addPokemonAttributesRec(QDomNode &noeud, pokemon &poke)
{
	while(!noeud.isNull())
	{
		for (int i = 0; _meth[i].tag_Name != NULL; i++)
		{
			if (noeud.nodeName() == _meth[i].tag_Name)
			{
				(((*this).*(_meth[i].pMeth))(noeud, poke));
			}
		}
		noeud = noeud.nextSibling();
	}
}
