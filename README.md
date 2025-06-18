# But The People - civ4col mod

Fork of excellent [We The People](https://github.com/We-the-People-civ4col-mod/Mod/), intended to keep expectations from ages old engine, junk code base, and busy developers, low.

## Changes

### Yield reduction

The systems present cannot really handle that many yields. Each yield needs a spot in menus, dedicated tile (which often do not really make sense), a specialist, a quest, storage space, more slots for the ships, etc. Thus, playing with this many yields is a headache for players, AIs, and developers. Moreso, many of the existing WTP yields don't really offer any interesting gameplay choices.

BTP cuts down the number of resources to the minumum, to avoid clutter and complicated code. Yields that introduce interesting chains to set up, or function in an unique way, are retained.

The following yields are removed:

* * Blades
* * Cassava -> Food
* * Charcoal -> Lumber is used directly for charcoal
* * Chocolate
* * Cochineal
* * Cocoa
* * Flax
* * Fruit, Fruit Brandy
* * Geese
* * Goats and goat accessories
* * Hardwood
* * Logwood
* * Milk: cheese is produced directly (shipping milk over Atlantic? What a great idea!)
* * Peanuts, roasted peanuts
* * Peat
* * Pigs
* * Pottery
* * Rapeseed/oil
* * Rice -> Food
* * Ropes
* * Rubber
* * Silver
* * Trade goods: replace with household goods
* * Vanilla pods
* * Wild Bird Feathers
* * Yerba leaves, Yerba mate

Empty places are generally taken by similar goods, produced at different rates.

Full intended (not everything is already implemented) [production tree](./doc/production-tree.pdf).

### Further plans

The fork is going to focus on improving code quality and maintainance. New features are possible, but not if they are going to be implemented in a way that dramatically affects the maintenance (like filling XML files with megabytes of copypasted code to add few more mostly decorative things).

## Installation

### Using an automatic build

1. First make sure that your colonization game is patched to official patch 1.01f. (Everything else will cause heavy problems.)
1. Navigate to [releases](https://github.com/But-The-People/but-the-people/releases) page
2. Choose a pre-release or release, click "assets", download the file that starts with "ButThePeople" (not "Source code" ones)
3. Go to the game directory. It's the one with Colonization.exe.
4. Create a folder called Mods if it's not already there.
5. Create "ButThePeople" folder there
6. Unpack the archive you downloaded in ButThePeople folder
7. Doubleclick setup.bat inside (windows might display it as simply setup)
8. Run Civilization 4 Colonization, choose "Advanced" and "Load Mod", choose "ButThePeople"
9. Enjoy!

### Building yourself

Download the source code either from a release page or via git, follow [WTP building guide](https://github.com/We-the-People-civ4col-mod/Mod/wiki/How-to-play-the-development-version) roughly.

### Important Installation Instructions

This mod uses Intel Threading Building blocks to achieve concurrent AI calculations in order to speed up the AI (inter)turn.
Setup.bat should take care of this, but before you start ensure this is done:

**copy tbb.dll and tbbmalloc.dll from "Project Files\tbb" to the directory where Colonization.exe resides!**

Otherwise the mod will not work!

## Known Issues

oh boy.
