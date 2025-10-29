Route2_ViridianForest_NorthEntrance_MapScripts::
# 2 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route2_ViridianForest_NorthEntrance_OnLoad
	.byte 0


Route2_ViridianForest_NorthEntrance_OnLoad::
# 6 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	setvar VAR_REACHED_VIRIDIAN_FOREST_NORTH_GATE, 1
# 7 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	setflag FLAG_ROUTE22_POLICEMAN_GONE
	return


# 11 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"

# 12 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_EventScript_Youngster::
# 13 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_ManyMonsOnlyInForests, MSGBOX_NPC
# 14 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	end
# 15 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"

# 16 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_EventScript_OldMan::
# 17 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_CanCutSkinnyTrees, MSGBOX_NPC
# 18 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	end
# 19 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"

# 20 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_EventScript_CooltrainerF::
# 21 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_CanCancelEvolution, MSGBOX_NPC
# 22 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	end
