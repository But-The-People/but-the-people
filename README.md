# But The People - civ4col mod

Fork of excellent [We The People](https://github.com/We-the-People-civ4col-mod/Mod/), intended to keep expectations from ages old engine, junk code base, and busy developers, low.

## Changes

### Yield reduction

The systems present cannot really handle that many yields. Each yield needs a spot in menus, dedicated tile (which often do not really make sense), a specialist, a quest, storage space, more slots for the ships, etc. Thus, playing with this many yields is a headache both for player and AIs. Moreso, many of the WTP yields don't really offer any interesting gameplay choices.

BTP cuts down the number of resources to the minumum, to avoid clutter and complicated code. Yields that introduce interesting chains to set up, or function in an unique way, are retained.

The following yields are removed:

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
* * Trade goods: replace with household goods
* * Vanilla pods
* * Wild Bird Feathers
* * Yerba leaves, Yerba mate

Empty places are generally taken by similar goods, produced at worse rates.

Full intended (not everything is already implemented) [./doc/production-tree.pdf](production tree).

## Important Installation Instructions
This mod uses Intel Threading Building blocks to achieve concurrent AI calculations in order to speed up the AI (inter)turn. 
Before you start:

**copy tbb.dll and tbbmalloc.dll from "Project Files\tbb" to the directory where Colonization.exe resides!**

Otherwise the mod will not work!

## Known Issues

oh boy.

