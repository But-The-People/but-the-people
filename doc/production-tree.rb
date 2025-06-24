# a reference for the intended production tree
# this scripts generates the graph in graphviz format

tiles = {
	# hill bonuses: 3 ore,3 coal, -1 raw salt, -1 organics
	# rivers add +1 to most organics and -1 to ore/coal


	# forests

	"coniferous forest" => "3 lumber,2 fur",
	"decidious forest" => "2 lumber,2 fur",
	# not so good for wildlife
	"dense forest" => "4 lumber,1 fur",
	# more on exotic side
	"jungle" => "2 lumber,2 exotic wood,3 coffee berries,2 premium fur",
	# good for wildlife
	"light forest" => "1 lumber,3 fur",
	# even more exotic
	"mangroves" => "1 lumber,3 exotic wood",
	# woodcutter's paradise
	"northern forest" => "3 lumber,3 exotic wood,3 fur,3 premium fur",
	"tropical grove" => "3 lumber,3 exotic wood",
	"thicket" => "3 fur,1 lumber",
	"ancient northern forest" => "4 lumber,3 exotic wood,3 fur,3 premium fur",

	# kinda overloaded but it's a lush biome. No cattle to avoid yield overload.
	"grassland" => "2 food,3 hemp,3 horses,3 sheep,3 tobacco",
	"grassland hills" => "2 ore,2 coal,1 food,3 grapes,2 sheep,2 horses",

	# a bit less lush than grassland but more friendly to crops
	"plains" => "3 food,2 horses,2 cattle,3 barley",
	"plains hills" => "3 olives,2 food,1 cattle,1 horses,3 ore,3 coal",

	# lots of exposed  rock
	"rock steppes" => "3 stone,1 ore,1 coal",
	"rock steppes hills" => "3 stone,4 ore,4 coal",

	# chicken can be here ok, clay is available, some food
	"wetland" => "2 chicken,1 clay,2 food",
	"wetland hills" => "1 food,1 chicken,2 clay",

	# cattle heaven, no sheep because well you know. Best for bushes.
	"prairie" => "2 food,2 horses,3 cattle,3 cotton,3 indigo",
	"prairie hills" => "3 red pepper,3 ore,3 coal",

	# salt pans, small exotic animals
	"desert" => "3 rock salt,1 premium fur",
	"desert hills" => "3 ore,2 rock salt,3 coal",

	# not much going on here but one can farm and even ranch a bit
	"shrubland" => "1 food,1 cattle,1 chicken",
	"shrubland hills" => "3 ore,3 coal",

	# ok for animals, unique crops
	"savannah" => "2 food,2 cattle,2 sheep,3 coffee berries,3 sugar",
	# a bit too overgrown for mining
	"savannah hills" => "3 coca,1 sheep,2 coal,2 ore,1 food",

	# should be some food like rice, and chicken don't need much space
	"marsh" => "2 chicken,2 food,2 clay",
	"marsh hills" => "1 food,1 chicken,3 clay",

	# sheep can tough it out, and chicken are small
	"taiga" => "1 food,1 chicken,1 sheep",
	"taiga hills" => "2 ore,2 coal,3 maple syrup",

	# furry animals around, otherwise not much
	"tundra" => "1 fur,1 premium fur",
	"tundra hills" => "2 ore,1 fur,1 premium fur,2 coal",

	# furry, hardy animals and rugged terrain good for mining
	"permafrost" => "1 ore,1 coal,1 premium fur",
	"permafrost hills" => "4 ore,1 premium fur,4 coal",

	"ice lake" => "1 food",

	"lake" => "2 food",
	"large river" => "2 food",

	# this mostly overwrites stuff
	"peak" => "3 ore,3 coal,3 stone",
	"whales" => "3 whale fat",
	"ocean" => "2 food",
}

$prodchains = []
def chain(*args)
	(0..args.size-2).each do |i|
		$prodchains << [args[i], args[i+1]]
	end
end


	chain("fur", "coats")
	chain("premium fur", "premium coats")
	chain("lumber", "gunpowder")
	chain("coal", "gunpowder")

	chain("food", "provisions")
	chain("rock salt", "salt")
	chain("salt", "provisions")

	chain("chicken", "food")
	chain("chicken", "down")

	chain("olives", "olive oil")

	chain("ore", 'tools')
	chain("coal", 'tools')

	chain("ore", 'muskets')
	chain("coal", 'muskets')

	chain("ore", 'cannons')
	chain("coal", 'cannons')

	chain("cattle", 'food')
	chain("cattle", 'leather')

	chain("leather", "leather goods")
	chain("leather", "lined leather coats")
	chain("down", "lined leather coats")

	chain("red pepper", 'spices')

	chain("cotton", 'cloth', "colored cloth", "everyday clothes")

	chain("indigo", "colored cloth")
	chain("indigo", "colored wool cloth")

	chain("sheep", 'wool')
	chain("sheep", 'food')
	chain("sheep", 'cheese')
	chain("cattle", 'cheese')

	chain("wool", "wool cloth", "colored wool cloth", "festive clothes")

	chain("exotic wood", 'furniture')
	chain("exotic wood", "upholstered furniture")
	chain("down", "upholstered furniture")
	chain("exotic wood", "household goods")
	chain("leather", "household goods")

	chain("lumber", "fieldworker goods")
	chain("leather", "fieldworker goods")

	chain("barley", 'beer')

	chain("grapes", 'wine')

	chain("sugar", 'rum')

	chain("coffee berries", "coffee")

	chain("tobacco", "cigars")

	chain("hemp", "sailcloth")

	chain("whale fat", "train oil")

	puts "digraph {"

	tiles.keys.each do |k|
		puts "\"#{k}\" [color=green,shape=box]"
	end
	tiles.each do |k, v|
		yields = v.split(",").map{|yi| yi.scan(/^(\d+)\s+(.+)/)[0]}
		puts "\"#{k}\" [color=green,label=\"#{k}\\n\\n#{yields.map{|yi| yi.join(" ")}.join("\\n")}\"]"
		yields.each do |yi|
			if yi[1] == "food"
			else
				puts "\"#{k}\" -> \"#{yi[1]}\""
			end
		end
	end

	$prodchains.each do |a|
		puts "\"#{a[0]}\" -> \"#{a[1]}\""
	end

	tiles.each do |k, v|
		if k =~ / hills$/
			basename = k.gsub(/ hills$/,"")
			puts "subgraph \"cluster #{basename}\" { \"#{k}\"; \"#{basename}\" }"
		end
	end

	puts "}"
