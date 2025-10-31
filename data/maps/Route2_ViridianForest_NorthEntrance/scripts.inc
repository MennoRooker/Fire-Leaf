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


Route2_ViridianForest_NorthEntrance_EventScript_Bugsy::
# 11 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	lockall
# 13 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	playse SE_PIN
# 15 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement LOCALID_BUGSY, Common_Movement_ExclamationMark
# 16 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	waitmovement 0
# 18 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement LOCALID_BUGSY, Common_Movement_Delay48
# 19 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	waitmovement 0
# 21 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement LOCALID_BUGSY, Route2_ViridianForest_NorthEntrance_Movement_BugsyApproach
# 22 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	waitmovement 0
# 24 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_BugsyGreeting, MSGBOX_DEFAULT
# 25 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	closemessage
# 26 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovePlayerDown
# 27 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	releaseall
	return


# 31 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_Movement_BugsyApproach:
# 32 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_down
# 33 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_down
# 34 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_down
	step_end

# 37 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
MovePlayerDown:
# 38 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_down
	step_end

# 42 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"

# 43 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_EventScript_Youngster::
# 44 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_ManyMonsOnlyInForests, MSGBOX_NPC
# 45 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	end
# 46 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"

# 47 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_EventScript_OldMan::
# 48 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_CanCutSkinnyTrees, MSGBOX_NPC
# 49 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	end
# 50 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"

# 51 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_EventScript_CooltrainerF::
# 52 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_CanCancelEvolution, MSGBOX_NPC
# 53 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	end
