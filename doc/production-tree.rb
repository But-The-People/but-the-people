# a reference for the intended production tree
# this scripts generates the graph in graphviz format

tiles = {
	"coniferous forest" => "3 lumber,2 fur",
	"decidious forest" => "2 lumber,2 fur",
	"dense forest" => "4 lumber,1 fur",
	"jungle" => "4 lumber,2 exotic wood,3 coffee berries,2 premium fur",
	"light forest" => "1 lumber,3 fur",
	"mangroves" => "1 lumber,3 exotic wood",
	"northern forest" => "3 lumber,3 exotic wood,3 fur,3 premium fur",
	"tropical grove" => "3 lumber,3 exotic wood",
	"thicket" => "3 fur,1 lumber",
	"ancient northern forest" => "4 lumber,3 exotic wood,3 fur,3 premium fur",

	# plains
	"desert" => "3 rock salt",

	"grassland" => "2 food,3 hemp,2 horses,3 cattle,1 chicken,3 tobacco",

	"ice lake" => "1 food",

	"lake" => "2 food",
	"large river" => "2 food",
	"marsh" => "3 chicken,3 food",
	"permafrost" => "1 ore,1 fur",

	"plains" => "3 food,1 horses,1 cattle,3 barley",
	"prairie" => "2 food,3 horses,2 cattle,3 cotton,3 indigo",

	"rock steppes" => "3 stone,1 ore",

	"savanna" => "2 food,2 cattle,1 chicken,3 coffee berries,3 sugar",

	"shrubland" => "1 food,2 chicken",

	"taiga" => "1 food",

	"tundra" => "1 fur,1 premium fur",

	"wetland" => "1 chicken,3 clay,2 food",

	# hills

	"desert hills" => "3 ore,2 rock salt,3 ore",

	"grassland hills" => "2 ore,2 coal,1 food,3 grapes,3 sheep",

	"marsh hills" => "1 food,2 chicken,2 clay",

	"permafrost hills" => "1 ore,1 fur,1 coal",

	"tundra hills" => "2 ore,2 fur,2 coal",

	"taiga hills" => "2 ore,2 coal,1 sheep,3 maple syrup",

	"plains hills" => "3 olives,1 food,2 sheep,3 ore,3 coal",

	"prairie hills" => "3 red pepper,2 sheep,3 ore,3 coal",

	"rock steppes hills" => "3 stone,3 ore,2 coal",

	"savanna hills" => "3 coca,2 sheep,2 coal,2 ore,1 food",

	"shrubland hills" => "1 food,1 sheep,3 ore,3 coal",

	"wetland hills" => "1 food,2 chicken,2 clay",

	"peak" => "3 ore,3 coal,3 stone",
	"whales" => "3 whale fat",
	"ocean" => "2 food",
	}

	# tier 1

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
