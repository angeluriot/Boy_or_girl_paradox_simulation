#include "simulation.h"



// Crée une simulation

Simulation::Simulation()
{
	is_day = false;
	nb_total = 0;
	nb_denom = 0;
	nb_num = 0;
	nb_ratio = 0.;
}



// Crée une simulation à partir des données du menu

Simulation::Simulation(const Menu& menu)
{
	texture.create(WIDTH, HEIGHT);
	texture.clear(sf::Color(20, 20, 200));
	texture.display();
	sprite = sf::Sprite(texture.getTexture());

	is_day = menu.variables[0].bool_value;

	nb_total = 0;
	nb_denom = 0;
	nb_num = 0;
	nb_ratio = 0;

	text_total.setString("Nombre de cas :");
	text_total.setCharacterSize(50);
	text_total.setFont(menu.texts_font);
	text_total.setFillColor(sf::Color::White);
	text_total.setOrigin(text_total.getLocalBounds().width / 2., 50. / 1.35);
	text_total.setPosition(600., 200.);

	nb_text_total = text_total;
	nb_text_total.setString("0");
	nb_text_total.setOrigin(nb_text_total.getLocalBounds().width / 2., 50. / 1.35);
	nb_text_total.setPosition(600., 300.);

	text_denom = text_total;

	if (is_day)
		text_denom.setString("L'un est un garçon né un mardi :");

	else
		text_denom.setString("L'un est un garçon :");

	text_denom.setOrigin(text_denom.getLocalBounds().width / 2., 50. / 1.35);
	text_denom.setPosition(600., 500.);

	nb_text_denom = text_total;
	nb_text_denom.setString("0");
	nb_text_denom.setOrigin(nb_text_denom.getLocalBounds().width / 2., 50. / 1.35);
	nb_text_denom.setPosition(600., 600.);

	text_num = text_total;
	text_num.setString("L'autre est un garçon :");
	text_num.setOrigin(text_num.getLocalBounds().width / 2., 50. / 1.35);
	text_num.setPosition(600., 800.);

	nb_text_num = text_total;
	nb_text_num.setString("0");
	nb_text_num.setOrigin(nb_text_num.getLocalBounds().width / 2., 50. / 1.35);
	nb_text_num.setPosition(600., 900.);

	text_ratio = text_total;
	text_ratio.setString("Probabilité :");
	text_ratio.setOrigin(text_ratio.getLocalBounds().width / 2., 50. / 1.35);
	text_ratio.setPosition(1350., 450.);

	nb_text_ratio = text_total;
	nb_text_ratio.setString("0");
	nb_text_ratio.setOrigin(nb_text_ratio.getLocalBounds().width / 2., 50. / 1.35);
	nb_text_ratio.setPosition(1350., 550.);

	draw_simulation();
}



// Recrrée une simulation à partir des données du menu

void Simulation::restart(const Menu& menu)
{
	texture.create(WIDTH, HEIGHT);
	texture.clear(sf::Color(20, 20, 200));
	texture.display();
	sprite = sf::Sprite(texture.getTexture());

	is_day = menu.variables[0].bool_value;

	nb_total = 0;
	nb_denom = 0;
	nb_num = 0;
	nb_ratio = 0;

	text_total.setString("Nombre de cas :");
	text_total.setCharacterSize(50);
	text_total.setFont(menu.texts_font);
	text_total.setFillColor(sf::Color::White);
	text_total.setOrigin(text_total.getLocalBounds().width / 2., 50. / 1.35);
	text_total.setPosition(600., 200.);

	nb_text_total = text_total;
	nb_text_total.setString("0");
	nb_text_total.setOrigin(nb_text_total.getLocalBounds().width / 2., 50. / 1.35);
	nb_text_total.setPosition(600., 300.);

	text_denom = text_total;

	if (is_day)
		text_denom.setString("L'un est un garçon né un mardi :");

	else
		text_denom.setString("L'un est un garçon :");

	text_denom.setOrigin(text_denom.getLocalBounds().width / 2., 50. / 1.35);
	text_denom.setPosition(600., 500.);

	nb_text_denom = text_total;
	nb_text_denom.setString("0");
	nb_text_denom.setOrigin(nb_text_denom.getLocalBounds().width / 2., 50. / 1.35);
	nb_text_denom.setPosition(600., 600.);

	text_num = text_total;
	text_num.setString("L'autre est un garçon :");
	text_num.setOrigin(text_num.getLocalBounds().width / 2., 50. / 1.35);
	text_num.setPosition(600., 800.);

	nb_text_num = text_total;
	nb_text_num.setString("0");
	nb_text_num.setOrigin(nb_text_num.getLocalBounds().width / 2., 50. / 1.35);
	nb_text_num.setPosition(600., 900.);

	text_ratio = text_total;
	text_ratio.setString("Probabilité :");
	text_ratio.setOrigin(text_ratio.getLocalBounds().width / 2., 50. / 1.35);
	text_ratio.setPosition(1350., 450.);

	nb_text_ratio = text_total;
	nb_text_ratio.setString("0");
	nb_text_ratio.setOrigin(nb_text_ratio.getLocalBounds().width / 2., 50. / 1.35);
	nb_text_ratio.setPosition(1350., 550.);

	draw_simulation();
}



// Affiche la simulation

void Simulation::draw_simulation()
{
	texture.draw(text_total);
	texture.draw(text_denom);
	texture.draw(text_num);
	texture.draw(text_ratio);

	nb_text_total.setString(std::to_string(nb_total));
	nb_text_denom.setString(std::to_string(nb_denom));
	nb_text_num.setString(std::to_string(nb_num));
	nb_text_ratio.setString(std::to_string(nb_ratio));

	nb_text_total.setOrigin(nb_text_total.getLocalBounds().width / 2., 50. / 1.35);
	nb_text_denom.setOrigin(nb_text_denom.getLocalBounds().width / 2., 50. / 1.35);
	nb_text_num.setOrigin(nb_text_num.getLocalBounds().width / 2., 50. / 1.35);
	nb_text_ratio.setOrigin(nb_text_ratio.getLocalBounds().width / 2., 50. / 1.35);

	texture.draw(nb_text_total);
	texture.draw(nb_text_denom);
	texture.draw(nb_text_num);
	texture.draw(nb_text_ratio);
}



// Met à jour la simulation dans le cas où le jour de naissance n'est pas spécifié

void Simulation::update_without_day()
{
	bool child_1_sex = rand() % 2;
	bool child_2_sex = rand() % 2;

	if (!child_1_sex or !child_2_sex)
	{
		nb_denom++;

		if (!child_1_sex and !child_2_sex)
			nb_num++;
	}

	nb_ratio = (double)nb_num / (double)nb_denom;

	nb_total++;
}



// Met à jour la simulation dans le cas où le jour de naissance est spécifié

void Simulation::update_with_day()
{
	bool child_1_sex = rand() % 2;
	bool child_2_sex = rand() % 2;
	int child_1_day = rand() % 7;
	int child_2_day = rand() % 7;

	if ((!child_1_sex and !child_1_day) or (!child_2_sex and !child_2_day))
	{
		nb_denom++;

		if (!child_1_sex and !child_2_sex)
			nb_num++;
	}

	nb_ratio = (double)nb_num / (double)nb_denom;

	nb_total++;
}



// Met à jour la simulation

void Simulation::update()
{
	if (is_day)
		update_with_day();

	else
		update_without_day();
}



// Affiche la simulation

void Simulation::draw(sf::RenderWindow& window)
{
	texture.clear(sf::Color(20, 20, 200));

	draw_simulation();

	texture.display();
	sprite = sf::Sprite(texture.getTexture());
	window.draw(sprite);
}