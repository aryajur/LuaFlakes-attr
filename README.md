# LuaFlakes-attr
Information attributes storage for LuaFlakes module installation system

# Overview
This repository is the companion repository to the [LuaFlakes](https://github.com/aryajur/LuaFlakes) repository. THis repository contains all the attributes to the different modules that the LuaFlakes script accesses to fetch and install the modules.

The modules are organized in a following directory structure:
```
- index.lua
- all
|- all
| |- 5.3
|- x32
| |- 5.3
|- x64
| |- 5.3
- Windows
|- all
| |- 5.3
|- x32
| |- 5.3
| |- Lua
| |- luasocket
|- x64
| |- 5.3
- Linux
|- all
| |- 5.3
|- x32
| |- 5.3
|- x64
| |- 5.3
```
- So the first level specifies the OS level selection of the modules.
- The second level selects the architecture level and inside
- The third level specifies the Lua Version
- On the 4th level are the module directories themselves. Each module directory or the Lua directory contains a _attr.flakes file which describes the module and its associated files.

The index.lua file contains the list of all the _attr.flakes files location wrt to the root of the repository. A sample index.lua file is shown below:
```lua
return {
	modules = {
		"all/all/5.3/tableUtils",
		"Windows/x32/5.3/LuaSec",
		"Windows/x32/5.3/luasocket",
	},
	lua = {
		"Windows/x32/5.3/Lua"
	}
}
```
**Note all paths should be using the "/" separator always.**


# Attributes of a Module
1. Name - This should be the same as the directory name where this _attr.flakes file is placed
2. Description
3. Websites - Array of websites
4. Architecture - 32,64
5. OS - Windows, Linux
6. LuaVER - Version of Lua it works with
7. ModVER - Version number of the Mod
8. FileIndex - List of all files of the module. Each list item is a table with the following information:
	1. File name - At the first index. This contains the file name and path by which to save the file in the indicated place.
 	2. "FILE"/"DIR" string at the second index to indicate this entry describes a file or a directory
	3. At the third index, the place it has to be placed:
		Places can be:
		1. Module place - "MODULE"
		2. Common DLL - "COMMON"
	3. This entry describes where to copy the file from and is only present for "FILE" entries. This entry will be a array with 2 entries:
		1. Type or source:
			1. "WEB" - download from internet.
		2. Source info. For WEB it is the direct URL of the file
9. Dependencies and their versions
10. Comment - Any additional information

# To add a new Lua Version
1. Upload the binaries in the right LuaFlakes bin repository
2. Add the entry in index.lua in this repository root
3. Create a _attr.flakes file for the Lua or if already there update it. Note: To get the raw file link from github, see this post: https://github.com/orgs/community/discussions/44370#discussioncomment-4688431
4. Commit the changes to Github.
