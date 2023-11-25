-- Flakes file list

return {
	modules = {
		-- Lua Only Modules
		"all/all/5.1/tableUtils",
		"all/all/5.2/tableUtils",
		"all/all/5.3/tableUtils",
		"all/all/5.3/diskOP",
		"all/all/5.3/oauth2",
		"all/all/5.3/json",
		"all/all/5.3/net.url",
		-- Modules that include binary files
		"Windows/x32/5.3/luafilesystem",
		"Windows/x32/5.3/LuaSec",
		"Windows/x32/5.3/luasocket",
	},
	lua = {
		"Windows/x32/5.3/Lua"
	}
}