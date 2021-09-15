/*
 * Copyright 2021 by Xidian University Programming Contest Training Base
 * Licensed under the GPL v2
 *
 * Author: Xi Ruoyao <xry111@mengyan1223.wang>
 */

#include "gcc-common.h"

__visible int plugin_is_GPL_compatible;

static struct plugin_info no_opt_attr_plugin_info = {
	.version = "20210915",
	.help = "",
};

static unsigned int no_opt_attr_execute(void)
{
	if (lookup_attribute("optimize", DECL_ATTRIBUTES(cfun->decl))) {
		error(G_("optimize attribute or pragma is not allowed"));
		return 1;
	}
	return 0;
}

#define PASS_NAME no_opt_attr
#define NO_GATE
#include "gcc-generate-gimple-pass.h"

__visible int plugin_init(struct plugin_name_args *plugin_info,
                          struct plugin_gcc_version *version)
{
	const char * const plugin_name = plugin_info->base_name;

	PASS_INFO(no_opt_attr, "optimized", 1, PASS_POS_INSERT_BEFORE);

	if (!plugin_default_version_check(version, &gcc_version)) {
		error(G_("incompatible gcc/plugin versions"));
		return 1;
	}

	register_callback(plugin_name, PLUGIN_PASS_MANAGER_SETUP, NULL,
	                  &no_opt_attr_pass_info);

	return 0;
}
