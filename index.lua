-- Flakes file list

return {
	modules = {
		"all/all/5.1/tableUtils",
		"all/all/5.2/tableUtils",
		"all/all/5.3/tableUtils",
		"all/all/5.3/diskOP",
		"Windows/x32/5.3/luafilesystem",
		"Windows/x32/5.3/LuaSec",
		"Windows/x32/5.3/luasocket",
	},
	lua = {
		"Windows/x32/5.3/Lua"
	}
}