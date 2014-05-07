#include "pokedex.h"

void	pokedex::displayPok()
{
	_ui.removeButton1->disconnect();
	connect(_ui.removeButton1, SIGNAL(clicked()), this, SLOT(slotReduce1()));
	_ui.removeButton2->disconnect();
	connect(_ui.removeButton2, SIGNAL(clicked()), this, SLOT(slotReduce2()));

	_ui.removeButton1->move(WIDTH_WIDGET, 0);
	_ui.removeButton2->move(2 * WIDTH_WIDGET + WIDTH_BUTTON, 0);
	_ui.widget1->move(0, 0);
	_ui.widget2->move(WIDTH_WIDGET + WIDTH_BUTTON, 0);

	_ui.widget1->setVisible(true);
	_ui.widget2->setVisible(true);
	
	_ui.widget3->setVisible(false);
	_ui.removeButton3->setVisible(false);
	_ui.widget4->setVisible(false);
	_ui.removeButton4->setVisible(false);
	
	_ui.createTeam->setVisible(false);
	_ui.createOwner->setVisible(false);
	
	this->resize(600, 600);
	this->setMinimumSize(QSize(600, 600));
	this->setMaximumSize(QSize(600, 600));
}

void	pokedex::displayTeams()
{
	_ui.removeButton1->disconnect();
	connect(_ui.removeButton1, SIGNAL(clicked()), this, SLOT(slotReduce1()));
	_ui.removeButton2->disconnect();
	connect(_ui.removeButton2, SIGNAL(clicked()), this, SLOT(slotReduce2()));
	_ui.removeButton3->disconnect();
	connect(_ui.removeButton3, SIGNAL(clicked()), this, SLOT(slotReduce3()));

	_ui.removeButton1->move(WIDTH_WIDGET, 0);
	_ui.removeButton2->move(2 * WIDTH_WIDGET + WIDTH_BUTTON, 0);
	_ui.removeButton3->move(3 * WIDTH_WIDGET + 2 * WIDTH_BUTTON, 0);
	_ui.widget1->move(0, 0);
	_ui.widget2->move(WIDTH_WIDGET + WIDTH_BUTTON, 0);
	_ui.widget3->move(2 * WIDTH_WIDGET + 2 * WIDTH_BUTTON, 0);

	_ui.widget1->setVisible(true);
	_ui.widget2->setVisible(true);
	_ui.widget3->setVisible(true);
	_ui.removeButton3->setVisible(true);

	_ui.widget4->setVisible(false);
	_ui.removeButton4->setVisible(false);

	_ui.createTeam->setVisible(true);
	_ui.createOwner->setVisible(false);

	//display

	this->resize(900, 600);
	this->setMinimumSize(QSize(900, 600));
	this->setMaximumSize(QSize(900, 600));
}

void	pokedex::displayOwners()
{
	_ui.removeButton1->disconnect();
	connect(_ui.removeButton1, SIGNAL(clicked()), this, SLOT(slotReduce1()));
	_ui.removeButton2->disconnect();
	connect(_ui.removeButton2, SIGNAL(clicked()), this, SLOT(slotReduce2()));
	_ui.removeButton3->disconnect();
	connect(_ui.removeButton3, SIGNAL(clicked()), this, SLOT(slotReduce3()));
	_ui.removeButton4->disconnect();
	connect(_ui.removeButton4, SIGNAL(clicked()), this, SLOT(slotReduce4()));

	_ui.removeButton1->move(WIDTH_WIDGET, 0);
	_ui.removeButton2->move(2 * WIDTH_WIDGET + WIDTH_BUTTON, 0);
	_ui.removeButton3->move(3 * WIDTH_WIDGET + 2 * WIDTH_BUTTON, 0);
	_ui.removeButton4->move(4 * WIDTH_WIDGET + 3 * WIDTH_BUTTON, 0);
	_ui.widget1->move(0, 0);
	_ui.widget2->move(WIDTH_WIDGET + WIDTH_BUTTON, 0);
	_ui.widget3->move(2 * WIDTH_WIDGET + 2 * WIDTH_BUTTON, 0);
	_ui.widget4->move(3 * WIDTH_WIDGET + 3 * WIDTH_BUTTON, 0);

	_ui.widget1->setVisible(true);
	_ui.widget2->setVisible(true);
	_ui.widget3->setVisible(true);
	_ui.removeButton3->setVisible(true);
	_ui.widget4->setVisible(true);
	_ui.removeButton4->setVisible(true);
	
	_ui.createTeam->setVisible(false);
	_ui.createOwner->setVisible(true);

	this->resize(1200, 600);
	this->setMinimumSize(QSize(1200, 600));
	this->setMaximumSize(QSize(1200, 600));
}

void	pokedex::reduceSize(int i)
{
	if (i == 1)
	{
		_ui.widget1->setVisible(false);
		_ui.removeButton1->move(_ui.removeButton1->x() - WIDTH_WIDGET, 0);
		_ui.removeButton2->move(_ui.removeButton2->x() - WIDTH_WIDGET, 0);
		_ui.widget2->move(_ui.widget2->x() - WIDTH_WIDGET, 0);
		_ui.removeButton3->move(_ui.removeButton3->x() - WIDTH_WIDGET, 0);
		_ui.widget3->move(_ui.widget3->x() - WIDTH_WIDGET, 0);
		_ui.removeButton4->move(_ui.removeButton4->x() - WIDTH_WIDGET, 0);
		_ui.widget4->move(_ui.widget4->x() - WIDTH_WIDGET, 0);
		_ui.removeButton1->disconnect();
		connect(_ui.removeButton1, SIGNAL(clicked()), this, SLOT(slotIncrease1()));

	}
	if (i == 2)
	{
		_ui.widget2->setVisible(false);
		_ui.removeButton2->move(_ui.removeButton2->x() - WIDTH_WIDGET, 0);
		_ui.removeButton3->move(_ui.removeButton3->x() - WIDTH_WIDGET, 0);
		_ui.widget3->move(_ui.widget3->x() - WIDTH_WIDGET, 0);
		_ui.removeButton4->move(_ui.removeButton4->x() - WIDTH_WIDGET, 0);
		_ui.widget4->move(_ui.widget4->x() - WIDTH_WIDGET, 0);
		_ui.removeButton2->disconnect();
		connect(_ui.removeButton2, SIGNAL(clicked()), this, SLOT(slotIncrease2()));

	}
	if (i == 3)
	{
		_ui.widget3->setVisible(false);
		_ui.removeButton3->move(_ui.removeButton3->x() - WIDTH_WIDGET, 0);
		_ui.removeButton4->move(_ui.removeButton4->x() - WIDTH_WIDGET, 0);
		_ui.widget4->move(_ui.widget4->x() - WIDTH_WIDGET, 0);
		_ui.removeButton3->disconnect();
		connect(_ui.removeButton3, SIGNAL(clicked()), this, SLOT(slotIncrease3()));

	}
	if (i == 4)
	{
		_ui.widget4->setVisible(false);
		_ui.removeButton4->move(_ui.removeButton4->x() - WIDTH_WIDGET, 0);
		_ui.removeButton4->disconnect();
		connect(_ui.removeButton4, SIGNAL(clicked()), this, SLOT(slotIncrease4()));

	}
	this->setMinimumSize(QSize(this->width() - WIDTH_WIDGET, 600));
	this->setMaximumSize(QSize(this->width() - WIDTH_WIDGET, 600));
}

void	pokedex::increaseSize(int i)
{
	this->setMinimumSize(QSize(this->width() + WIDTH_WIDGET, 600));
	this->setMaximumSize(QSize(this->width() + WIDTH_WIDGET, 600));
	if (i == 1)
	{
		_ui.widget1->setVisible(true);
		_ui.removeButton1->move(_ui.removeButton1->x() + WIDTH_WIDGET, 0);
		_ui.removeButton2->move(_ui.removeButton2->x() + WIDTH_WIDGET, 0);
		_ui.widget2->move(_ui.widget2->x() + WIDTH_WIDGET, 0);
		_ui.removeButton3->move(_ui.removeButton3->x() + WIDTH_WIDGET, 0);
		_ui.widget3->move(_ui.widget3->x() + WIDTH_WIDGET, 0);
		_ui.removeButton4->move(_ui.removeButton4->x() + WIDTH_WIDGET, 0);
		_ui.widget4->move(_ui.widget4->x() + WIDTH_WIDGET, 0);
		_ui.removeButton1->disconnect();
		connect(_ui.removeButton1, SIGNAL(clicked()), this, SLOT(slotReduce1()));

	}
	if (i == 2)
	{
		_ui.widget2->setVisible(true);
		_ui.removeButton2->move(_ui.removeButton2->x() + WIDTH_WIDGET, 0);
		_ui.widget3->move(_ui.widget3->x() + WIDTH_WIDGET, 0);
		_ui.removeButton3->move(_ui.removeButton3->x() + WIDTH_WIDGET, 0);
		_ui.widget4->move(_ui.widget4->x() + WIDTH_WIDGET, 0);
		_ui.removeButton4->move(_ui.removeButton4->x() + WIDTH_WIDGET, 0);
		_ui.removeButton2->disconnect();
		connect(_ui.removeButton2, SIGNAL(clicked()), this, SLOT(slotReduce2()));

	}
	if (i == 3)
	{
		_ui.widget3->setVisible(true);
		_ui.removeButton3->move(_ui.removeButton3->x() + WIDTH_WIDGET, 0);
		_ui.widget4->move(_ui.widget4->x() + WIDTH_WIDGET, 0);
		_ui.removeButton4->move(_ui.removeButton4->x() + WIDTH_WIDGET, 0);
		_ui.removeButton3->disconnect();
		connect(_ui.removeButton3, SIGNAL(clicked()), this, SLOT(slotReduce3()));

	}
	if (i == 4)
	{
		_ui.widget4->setVisible(true);
		_ui.removeButton4->move(_ui.removeButton4->x() + WIDTH_WIDGET, 0);
		_ui.removeButton4->disconnect();
		connect(_ui.removeButton4, SIGNAL(clicked()), this, SLOT(slotReduce4()));
	}
}

void	pokedex::slotReduce1()
{
	reduceSize(1);
}

void	pokedex::slotReduce2()
{
	reduceSize(2);
}

void	pokedex::slotReduce3()
{
	reduceSize(3);
}

void	pokedex::slotReduce4()
{
	reduceSize(4);
}

void	pokedex::slotIncrease1()
{
	increaseSize(1);
}

void	pokedex::slotIncrease2()
{
	increaseSize(2);
}

void	pokedex::slotIncrease3()
{
	increaseSize(3);
}

void	pokedex::slotIncrease4()
{
	increaseSize(4);
}

void	pokedex::displayInfoPok(QListWidgetItem* current, QListWidgetItem* previous)
{
	QLabel	*imgPok = new QLabel();
	QLabel	*imgType1 = new QLabel();
	QLabel	*imgType2 = new QLabel();
	QLabel	*idPok = new QLabel();
	QLabel	*stat1 = new QLabel();
	QLabel	*stat2 = new QLabel();
	QLabel	*stat3 = new QLabel();
	QLabel	*abilities = new QLabel();
	QLabel	*description = new QLabel();
	QLabel	*eggGroup = new QLabel();
	QLabel	*species = new QLabel();
	QLabel	*height = new QLabel();
	QLabel	*weight = new QLabel();
	QLabel	*male = new QLabel();
	QLabel	*female = new QLabel();
	QLabel	*evolution = new QLabel();
	QLabel	*moves = new QLabel();
	static QLabel	*savemoves = NULL;
	static QLabel	*saveevolution = NULL;
	static QLabel	*saveweight = NULL;
	static QLabel	*savemale = NULL;
	static QLabel	*savefemale = NULL;
	static QLabel	*saveheight = NULL;
	static QLabel	*saveabilities = NULL;
	static QLabel	*savedescription = NULL;
	static QLabel	*saveeggGroup = NULL;
	static QLabel	*savespecies = NULL;
	static QLabel	*savestat1 = NULL;
	static QLabel	*savestat2 = NULL;
	static QLabel	*savestat3 = NULL;
	static QLabel	*saveidPok = NULL;
	static QLabel	*saveimgPok = NULL;
	static QLabel	*saveimgType1 = NULL;
	static QLabel	*saveimgType2 = NULL;
	QString	*id = new QString();
	unsigned int		i;

	(void)previous;
	if (saveidPok != NULL)
	{
		_ui.namePokLayout->removeWidget(saveidPok);
		_ui.imgPokLayout->removeWidget(saveimgPok);
		_ui.imgType1Layout->removeWidget(saveimgType1);
		_ui.imgType2Layout->removeWidget(saveimgType2);
		_ui.stats1Layout->removeWidget(savestat1);
		_ui.stats2Layout->removeWidget(savestat2);
		_ui.stats3Layout->removeWidget(savestat3);
		_ui.abilitiesLayout->removeWidget(saveabilities);
		_ui.descriptionLayout->removeWidget(savedescription);
		_ui.eggGroupLayout->removeWidget(saveeggGroup);
		_ui.speciesLayout->removeWidget(savespecies);
		_ui.weightLayout->removeWidget(saveweight);
		_ui.maleLayout->removeWidget(savemale);
		_ui.femaleLayout->removeWidget(savefemale);
		_ui.heightLayout->removeWidget(saveheight);
		_ui.evolutionLayout->removeWidget(saveevolution);
		_ui.movesLayout->removeWidget(savemoves);
	}

	*id = current->text().split(':')[0];
	i = id->toInt() - 1;

	idPok->setText("#" + QString::number(this->_pokemons[i].getId()) + " :	" + this->_pokemons[i].getName());
	idPok->setFont(QFont("Jokerman", 12, QFont::Bold, false));
	_ui.namePokLayout->addWidget(idPok);
	imgPok->setPixmap(QPixmap(this->_pokemons[i].getImage()));
	_ui.imgPokLayout->addWidget(imgPok);

	imgType1->setPixmap(QPixmap(this->_pokemons[i].getType()[0]));
	_ui.imgType1Layout->addWidget(imgType1);
	if (this->_pokemons[i].getType().size() == 2)
	{
		imgType2->setPixmap(QPixmap(this->_pokemons[i].getType()[1]));
		_ui.imgType2Layout->addWidget(imgType2);
	}

	stat1->setText("HP " + QString::number(this->_pokemons[i].getStatsSome(HP)) + " SPD " + QString::number(this->_pokemons[i].getStatsSome(SPD)));
	stat1->setFont(QFont("Jokerman", 8, QFont::Bold, false));
	_ui.stats1Layout->addWidget(stat1);

	stat2->setText("ATK " + QString::number(this->_pokemons[i].getStatsSome(ATK)) + " SAT " + QString::number(this->_pokemons[i].getStatsSome(SAT)));
	stat2->setFont(QFont("Jokerman", 8, QFont::Bold, false));
	_ui.stats2Layout->addWidget(stat2);

	stat3->setText("DEF " + QString::number(this->_pokemons[i].getStatsSome(DEF)) + " SDF " + QString::number(this->_pokemons[i].getStatsSome(SDF)));
	stat3->setFont(QFont("Jokerman", 8, QFont::Bold, false));
	_ui.stats3Layout->addWidget(stat3);

	abilities->setText("Ability : " + this->_pokemons[i].getAbility());
	abilities->setFont(QFont("Jokerman", 8, QFont::Bold, false));
	abilities->setWordWrap(true);
	_ui.abilitiesLayout->addWidget(abilities);

	description->setText(this->_pokemons[i].getDescription());
	description->setFont(QFont("Jokerman", 8, QFont::Bold, false));
	description->setWordWrap(true);
	_ui.descriptionLayout->addWidget(description);

	QString	tmp = NULL;
	for (unsigned int y = 0; y != this->_pokemons[i].getEggGroup().size(); y++)
	{
		if (y != 0)
			tmp = tmp + ", ";
		tmp = tmp + this->_pokemons[i].getEggGroup()[y];
	}

	eggGroup->setText(tmp);
	eggGroup->setFont(QFont("Jokerman", 8, QFont::Bold, false));
	eggGroup->setWordWrap(true);
	_ui.eggGroupLayout->addWidget(eggGroup);

	tmp = "";
	for	(unsigned int y2 = 0; y2 != this->_pokemons[i].getEvo().size(); y2++)
	{
		if (y2 != 0)
			tmp = tmp + "<br />";
		tmp = tmp + QString::number(this->_pokemons[i].getEvo()[y2].lvl) + " " + this->_pokemons[i].getEvo()[y2].name;
	}

	evolution->setText(tmp);
	evolution->setFont(QFont("Jokerman", 8, QFont::Bold, false));
	eggGroup->setWordWrap(true);
	_ui.evolutionLayout->addWidget(evolution);


	tmp = "";
	for (unsigned int y3 = 0; y3 != this->_pokemons[i].getMove().size(); y3++)
	{
		if (y3 != 0)
			tmp = tmp + "<br />";
		tmp = tmp + QString::number(this->_pokemons[i].getMove()[y3].lvl) + " " + this->_pokemons[i].getMove()[y3].name;
	}

	moves->setText(tmp);
	moves->setFont(QFont("Jokerman", 8, QFont::Bold, false));
	moves->setWordWrap(true);
	_ui.movesLayout->addWidget(moves);

	species->setText(this->_pokemons[i].getSpecies());
	species->setFont(QFont("Jokerman", 8, QFont::Bold, false));
	species->setWordWrap(true);
	_ui.speciesLayout->addWidget(species);


	height->setText("Height : " + QString::number(this->_pokemons[i].getHeight()));
	height->setFont(QFont("Jokerman", 8, QFont::Bold, false));
	_ui.heightLayout->addWidget(height);

	weight->setText("Weight : " + QString::number(this->_pokemons[i].getWeight()));
	weight->setFont(QFont("Jokerman", 8, QFont::Bold, false));
	_ui.weightLayout->addWidget(weight);

	male->setText("male : " + QString::number(this->_pokemons[i].getRatioMale()));
	male->setFont(QFont("Jokerman", 8, QFont::Bold, false));
	_ui.maleLayout->addWidget(male);

	female->setText("female : " + QString::number(this->_pokemons[i].getRatioFemale()));
	female->setFont(QFont("Jokerman", 8, QFont::Bold, false));
	_ui.femaleLayout->addWidget(female);

	saveweight = weight;
	savemale = male;
	savefemale = female;
	saveheight = height;
	saveabilities = abilities;
	savedescription = description;
	saveeggGroup = eggGroup;
	savespecies = species;
	savestat1 = stat1;
	savestat2 = stat2;
	savestat3 = stat3;
	saveidPok = idPok;
	saveimgPok = imgPok;
	saveimgType1 = imgType1;
	saveimgType2 = imgType2;
	saveevolution = evolution;
	savemoves = moves;
}
