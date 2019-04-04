#include "GameConfiguration.h"

map<const char*, double>* GameConfiguration::globalsConfigurationDouble = 0;
map<const char*, const char*>* GameConfiguration::globalsConfigurationString = 0;


double GameConfiguration::GetConfiguration(const char * key)
{
	if (globalsConfigurationDouble == 0)
	{
		globalsConfigurationDouble = new map<const char*, double>();

		globalsConfigurationDouble->insert(pair<const char*, double>("window_width", 512));
		globalsConfigurationDouble->insert(pair<const char*, double>("window_height", 448));

		globalsConfigurationDouble->insert(pair<const char*, double>("backbuffer_width", 256));
		globalsConfigurationDouble->insert(pair<const char*, double>("backbuffer_height", 224));

		globalsConfigurationDouble->insert(pair<const char*, double>("fps", 70));


	}
	return globalsConfigurationDouble->at(key);
}

const char * GameConfiguration::GetConfigurationString(const char * key)
{
	if (globalsConfigurationString == 0)
	{
		globalsConfigurationString = new map<const char*, const char*>();

		globalsConfigurationString->insert(pair<const char*,const char*>("window_title", "Dat ten game cua ban tai day"));
		globalsConfigurationString->insert(pair<const char*, const  char*>("window_class", "win_game"));

		
	}
	return globalsConfigurationString->at(key);
}

GameConfiguration::GameConfiguration()
{
}

GameConfiguration::~GameConfiguration()
{
}