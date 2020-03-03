#include "simulation.h"

int main()
{
	int width;
	int height;

	if (sf::VideoMode::getDesktopMode().width > (16. / 9.) * sf::VideoMode::getDesktopMode().height)
	{
		height = (sf::VideoMode::getDesktopMode().height * 3) / 4;
		width = (height * 16) / 9;
	}

	else if (sf::VideoMode::getDesktopMode().width < (16. / 9.) * sf::VideoMode::getDesktopMode().height)
	{
		width = (sf::VideoMode::getDesktopMode().width * 3) / 4;
		height = (width * 9) / 16;
	}

	else
	{
		width = (sf::VideoMode::getDesktopMode().width * 3) / 4;
		height = (sf::VideoMode::getDesktopMode().height * 3) / 4;
	}

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(width, height), "Boy or girl paradox", sf::Style::Close | sf::Style::Titlebar, settings);

	sf::Image icon;
	icon.loadFromFile("dependencies/resources/icon.png");

	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	std::vector<Variable> variables;
	variables.push_back(Variable("Préciser le jour de naissance", Bool, false));
	variables.push_back(Variable("FPS (0 = pas de limite)", Int, 0, 0, 1000));
	
	Menu menu = Menu(variables, sf::Color(20, 20, 200), width, height);
	menu.init_names(50, 750, sf::Color::White, 400);
	menu.init_lines(600, 15, 1200, sf::Color(75, 75, 255));
	menu.init_circles(20, sf::Color::White);
	menu.init_values(40, 50, sf::Color::White);
	menu.init_boxes(45, 900, sf::Color::White);
	menu.init_start(150, 1920 - 150, 1080 - 150, sf::Color::White);

	Restart restart_button = Restart(150, 1920 - 150, 1080 - 150, sf::Color::White, width, height);

	bool simulation_end = false;
	bool end = false;

	Cursor_type cursor_type = arrow;
	sf::Vector2i mouse_position;
	sf::Vector2i previous_mouse_position;

	sf::Mouse mouse;
	sf::Cursor cursor;
	sf::Event sf_event;
	sf::Clock clock;

	cursor.loadFromSystem(sf::Cursor::Arrow);
	window.setMouseCursor(cursor);

	Simulation simulation(menu);

	while (window.isOpen() and !end)
	{
		while (!menu.end and !end)
		{
			while (window.pollEvent(sf_event))
			{
				switch (sf_event.type)
				{

				case sf::Event::Closed:

					window.close();
					end = true;
					break;
				}
			}

			previous_mouse_position = mouse_position;
			mouse_position = mouse.getPosition(window);

			menu.update(previous_mouse_position, mouse_position, mouse.isButtonPressed(mouse.Left), cursor, cursor_type, window);
			menu.draw(window);
		}

		cursor.loadFromSystem(sf::Cursor::Wait);
		window.setMouseCursor(cursor);

		menu.end = false;
		menu.grabbed = false;
		menu.grab_forbiden = false;

		simulation.restart(menu);

		if (restart_button.is_in(sf::Vector2f(mouse_position)))
			cursor.loadFromSystem(sf::Cursor::Hand);

		else
			cursor.loadFromSystem(sf::Cursor::Arrow);

		window.setMouseCursor(cursor);

		while (!simulation_end and !end)
		{
			while (window.pollEvent(sf_event))
			{
				switch (sf_event.type)
				{

				case sf::Event::Closed:

					window.close();
					end = true;
					break;
				}
			}

			window.clear(sf::Color::Black);

			if (menu.variables[1].int_value != 0)
			{
				if (clock.getElapsedTime() >= sf::seconds(1. / (double)menu.variables[1].int_value))
				{
					simulation.update();
					clock.restart();
				}
			}

			else
				simulation.update();

			simulation.draw(window, menu);

			previous_mouse_position = mouse_position;
			mouse_position = mouse.getPosition(window);
			simulation_end = restart_button.update(mouse_position, mouse.isButtonPressed(mouse.Left), cursor, cursor_type, window);
			restart_button.draw(window);

			window.display();
		}

		simulation_end = false;
		restart_button.grabbed = false;
		restart_button.grab_forbiden = false;
	}

	return 0;
}