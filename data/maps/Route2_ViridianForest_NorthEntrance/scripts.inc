Route2_ViridianForest_NorthEntrance_MapScripts::
# 2 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route2_ViridianForest_NorthEntrance_OnLoad
# 3 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route2_ViridianForest_NorthEntrance_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route2_ViridianForest_NorthEntrance_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	map_script_2 VAR_SPOKE_TO_BUGSY, 0, Route2_ViridianForest_NorthEntrance_EventScript_Bugsy
	.2byte 0


Route2_ViridianForest_NorthEntrance_OnLoad::
# 9 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	setvar VAR_REACHED_VIRIDIAN_FOREST_NORTH_GATE, 1
# 10 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	setflag FLAG_ROUTE22_POLICEMAN_GONE
	return


Route2_ViridianForest_NorthEntrance_EventScript_Bugsy::
# 14 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	lockall
# 15 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	playse SE_PIN
# 16 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement LOCALID_BUGSY, Common_Movement_ExclamationMark
# 17 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	waitmovement 0
# 18 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement LOCALID_BUGSY, Common_Movement_Delay48
# 19 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	waitmovement 0
# 20 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement LOCALID_BUGSY, Route2_ViridianForest_NorthEntrance_Movement_BugsyApproach
# 21 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	waitmovement 0
# 22 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_BugsyGreeting, MSGBOX_DEFAULT
# 23 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	closemessage
# 24 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	setvar VAR_SPOKE_TO_BUGSY, 1
# 25 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovePlayerDown
# 26 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	warp MAP_VIRIDIAN_FOREST, 5, 10
# 27 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	releaseall
	return


# 30 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_Movement_BugsyApproach:
# 31 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_down
# 32 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_down
	step_end

# 35 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
MovePlayerDown:
# 36 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_down
	step_end

# 40 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"

# 41 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_EventScript_Youngster::
# 42 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_ManyMonsOnlyInForests, MSGBOX_NPC
# 43 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	end
# 44 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"

# 45 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_EventScript_OldMan::
# 46 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_CanCutSkinnyTrees, MSGBOX_NPC
# 47 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	end
# 48 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"

# 49 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_EventScript_CooltrainerF::
# 50 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_CanCancelEvolution, MSGBOX_NPC
# 51 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	end
