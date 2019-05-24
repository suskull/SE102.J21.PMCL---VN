#include "GameConfiguration.h"

map<const char*, double>* GameConfiguration::globalsConfigurationDouble = 0;
map<const char*, const char*>* GameConfiguration::globalsConfigurationString = 0;


double GameConfiguration::GetConfiguration(const char * key)
{
	if (globalsConfigurationDouble == 0)
	{
		globalsConfigurationDouble = new map<const char*, double>();

		globalsConfigurationDouble->insert(pair<const char*, double>("window_width", 512));
		globalsConfigurationDouble->insert(pair<const char*, double>("window_height", 440));

		globalsConfigurationDouble->insert(pair<const char*, double>("backbuffer_width", 256));
		globalsConfigurationDouble->insert(pair<const char*, double>("backbuffer_height", 220));

		globalsConfigurationDouble->insert(pair<const char*, double>("fps", 70));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_vx", 200));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_roll", 250));
		globalsConfigurationDouble->insert(pair<const char*, double>("gravity_ay", -500));
		globalsConfigurationDouble->insert(pair<const char*, double>("object_animation_time_default", 100));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_health", 16));
		//climb
		globalsConfigurationDouble->insert(pair<const char*, double>("player_climb_vy", 60));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_climb_jump_vy", 70));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_climb_jump_vx", 20));
		//injured
		globalsConfigurationDouble->insert(pair<const char*, double>("player_injured_vx", 80));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_injured_vy", 150));
		
		//injured_boss
		globalsConfigurationDouble->insert(pair<const char*, double>("player_injured_boss", 4));
		//injured_enemy
		globalsConfigurationDouble->insert(pair<const char*, double>("player_injured_enemy", 2));

		//shurien
		globalsConfigurationDouble->insert(pair<const char*, double>("shuriken_vx", 150));
		globalsConfigurationDouble->insert(pair<const char*, double>("spriritual_strenght_per_shuriken", 3));
		//flame
		globalsConfigurationDouble->insert(pair<const char*, double>("flame_vx", 70));
		globalsConfigurationDouble->insert(pair<const char*, double>("flame_vy", 70));
		//enemy
		//panther
		globalsConfigurationDouble->insert(pair<const char*, double>("panther_vx", 100));
		globalsConfigurationDouble->insert(pair<const char*, double>("panther_score", 100));
		//running man
		globalsConfigurationDouble->insert(pair<const char*, double>("running_man_vx", 100));
		globalsConfigurationDouble->insert(pair<const char*, double>("running_man_vy", 100));
		globalsConfigurationDouble->insert(pair<const char*, double>("running_man_score", 100));

		//sitting man
		globalsConfigurationDouble->insert(pair<const char*, double>("sittingman_player", 50));
		globalsConfigurationDouble->insert(pair<const char*, double>("sitting_man_bullet_vx", 100));
		globalsConfigurationDouble->insert(pair<const char*, double>("sitting_man_time_prepare_attack", 5));
		globalsConfigurationDouble->insert(pair<const char*, double>("sitting_man_score", 150));
		globalsConfigurationDouble->insert(pair<const char*, double>("sitting_man_bullet_count", 1));
		//soldier
		globalsConfigurationDouble->insert(pair<const char*, double>("soldier_vx", 20));
		globalsConfigurationDouble->insert(pair<const char*, double>("soldier_bullet_vx", 60));
		globalsConfigurationDouble->insert(pair<const char*, double>("soldier_time_prepare_attack", 5));
		globalsConfigurationDouble->insert(pair<const char*, double>("soldier_bullet_count", 3));
		globalsConfigurationDouble->insert(pair<const char*, double>("soldier_score", 150));

		//swordman
		globalsConfigurationDouble->insert(pair<const char*, double>("swordman_vx", 40));
		globalsConfigurationDouble->insert(pair<const char*, double>("swordman_score", 100));

		//throwman
		globalsConfigurationDouble->insert(pair<const char*, double>("throw_man_vx", 10));
		globalsConfigurationDouble->insert(pair<const char*, double>("throw_man_score", 200));
		globalsConfigurationDouble->insert(pair<const char*, double>("throw_man_time_prepare_attack", 5));
		globalsConfigurationDouble->insert(pair<const char*, double>("throw_man_knife_count", 1));
		globalsConfigurationDouble->insert(pair<const char*, double>("throw_man_knife_vy", 70));
		globalsConfigurationDouble->insert(pair<const char*, double>("throw_man_knife_ay", 300));

		//boss
		globalsConfigurationDouble->insert(pair<const char*, double>("boss_vy", 300));
		globalsConfigurationDouble->insert(pair<const char*, double>("boss_vx", 120));
		globalsConfigurationDouble->insert(pair<const char*, double>("boss_time_per_jump", 5));
		globalsConfigurationDouble->insert(pair<const char*, double>("boss_weapon_vx", 80));
		globalsConfigurationDouble->insert(pair<const char*, double>("boss_decrease_health_per_attack", 1));

		//bird
		globalsConfigurationDouble->insert(pair<const char*, double>("bird_score", 300));

		//item
		//item_bonus_blue
		globalsConfigurationDouble->insert(pair<const char*, double>("item_bonus_blue_score", 500));
		//item_bonus_red
		globalsConfigurationDouble->insert(pair<const char*, double>("item_bonus_red_score", 1000));

		//item_restore_physical_strenght
		globalsConfigurationDouble->insert(pair<const char*, double>("item_restore_physical_strenght", 16));

		//item_spriritual_strenght_blue
		globalsConfigurationDouble->insert(pair<const char*, double>("item_spriritual_strenght_blue_mana", 5));
		//item_spriritual_strenght_red
		globalsConfigurationDouble->insert(pair<const char*, double>("item_spriritual_strenght_red_mana", 10));
		//item_clock_time
		globalsConfigurationDouble->insert(pair<const char*, double>("item_clock_time", 5));
	
	
	}
	return globalsConfigurationDouble->at(key);
}

const char * GameConfiguration::GetConfigurationString(const char * key)
{
	if (globalsConfigurationString == 0)
	{
		globalsConfigurationString = new map<const char*, const char*>();

		globalsConfigurationString->insert(pair<const char*,const char*>("window_title", "Game Ninja Gaiden"));
		globalsConfigurationString->insert(pair<const char*, const  char*>("window_class", "Ninja Gaiden"));

		
	}
	return globalsConfigurationString->at(key);
}

GameConfiguration::GameConfiguration()
{
}

GameConfiguration::~GameConfiguration()
{
}
