#ifndef SIMULATION_H
#define SIMULATION_H
#include "menu.h"
#include <vector>



// Classe définissant la simulation

class Simulation
{

public:

	bool				is_day;			// Définit si on prend en compte le jour de naissance
	sf::Text			text_total;		// Texte : "Nombre de cas :"
	sf::Text			text_denom;		// Texte : "L'un est un garçon :"
	sf::Text			text_num;		// Texte : "L'autre est un garçon :"
	sf::Text			text_ratio;		// Texte : "Probabilité :"
	int					nb_total;		// Nombre de cas étudiés 
	int					nb_denom;		// Nombre de cas où l'un est un garçon
	int					nb_num;			// Nombre de cas où l'autre est un garçon
	double				nb_ratio;		// Probabilité
	sf::Text			nb_text_total;	// Texte affichant le nombre de cas étudiés
	sf::Text			nb_text_denom;	// Texte affichant le nombre de cas où l'un est un garçon (ou est né un mardi)
	sf::Text			nb_text_num;	// Texte affichant le nombre de cas où l'autre est un garçon
	sf::Text			nb_text_ratio;	// Texte affichant la probabilité
	sf::RenderTexture	texture;		// La texture sur laquelle sont dessinés les pixels
	sf::Sprite			sprite;			// Le sprite servant à afficher la texture

	Simulation();
	Simulation(const Menu& menu);

	void restart(const Menu& menu);
	void draw_simulation(const Menu& menu);
	void update_without_day();
	void update_with_day();
	void update();
	void draw(sf::RenderWindow& window, const Menu& menu);
};

#endif