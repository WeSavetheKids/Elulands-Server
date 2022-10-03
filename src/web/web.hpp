// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#ifndef WEB_HPP
#define WEB_HPP

#include <string>

#include "../common/cbasetypes.hpp"
#include "../common/core.hpp" // CORE_ST_LAST
#include "../common/mmo.hpp" // NAME_LENGTH,SEX_*
#include "../common/timer.hpp"
#include "../config/core.hpp"


#ifndef SQL_BUFFER_SIZE
	#define SQL_BUFFER_SIZE 65535
#endif

enum E_WEBSERVER_ST {
	WEBSERVER_ST_RUNNING = CORE_ST_LAST,
	WEBSERVER_ST_STARTING,
	WEBSERVER_ST_SHUTDOWN,
	WEBSERVER_ST_LAST
};

struct Web_Config {
	std::string web_ip;								// the address to bind to
	uint16 web_port;								// the port to bind to
	bool print_req_res;								// Whether or not to print requests/responses

	char webconf_name[256];						/// name of main config file
	char msgconf_name[256];							/// name of msg_conf config file
	bool allow_gifs;
};

struct Inter_Config {
	int emblem_transparency_limit;					// Emblem transparency limit
	bool emblem_woe_change;							// allow emblem change during woe
};

enum e_http_status{
	HTTP_BAD_REQUEST = 400,
	HTTP_NOT_FOUND = 404,
};

extern struct Web_Config web_config;
extern struct Inter_Config inter_config;

extern char login_table[32];
extern char guild_emblems_table[32];
extern char user_configs_table[32];
extern char char_configs_table[32];
extern char guild_db_table[32];
extern char char_db_table[32];
extern char merchant_configs_table[32];

#define msg_config_read(cfgName) web_msg_config_read(cfgName)
#define msg_txt(msg_number) web_msg_txt(msg_number)
#define do_final_msg() web_do_final_msg()
int web_msg_config_read(char *cfgName);
const char* web_msg_txt(int msg_number);
void web_do_final_msg(void);
bool web_config_read(const char* cfgName, bool normal);

#endif /* WEB_HPP */
