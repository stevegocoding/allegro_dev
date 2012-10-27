#include <string>
#include <sstream>
#include "utils.h"
#include "allegro5/allegro.h" 

class c_engine 
{
public: 
	c_engine(const std::string& config_file);
	~c_engine();

	/**
	 *	Initialize the system components
	 */
	int init_engine();

	/**
	 *	Destroy the engine
	 */
	void destroy_engine();


	/**
	 *	Start the main loop here
	 */ 
	int start_game();

	/**
	 *	End the main loop
	 */
	void end_game(); 

private: 
	
	ALLEGRO_DISPLAY *m_al_display;

	std::string m_config_file; 
	int m_display_width, m_display_height; 
	
};

c_engine::c_engine(const std::string& config_file)
	: m_al_display(NULL)
	, m_display_width(0), m_display_height(0)
	, m_config_file(config_file)
{

}

int c_engine::init_engine()
{
	if (!al_init())
	{
		error_abort("al_init() - Failed!");
	}

	/// Load the config file
	ALLEGRO_CONFIG *al_config = NULL; 
	al_config = al_load_config_file(m_config_file.c_str());
	if (!al_config)
		error_abort("Couldn't open config file!");
	else 
	{
		std::stringstream ss; 
		const char *value = NULL; 
		value = al_get_config_value(al_config, "Display", "width"); 
		ss << value; 
		ss >> m_display_width; 
		value = al_get_config_value(al_config, "Display", "height");
		ss.clear(); 
		ss << value; 
		ss >> m_display_height;
	}


	/// Initialize the display
	m_al_display = al_create_display(m_display_width, m_display_height);
	if (!m_al_display)
	{
		error_abort("al_create_display() - Failed!"); 
	}
	
	
	return 0; 
}

void c_engine::destroy_engine()
{ 
	if (m_al_display) 
	{
		al_destroy_display(m_al_display); 
	}
	
	al_uninstall_system(); 
}