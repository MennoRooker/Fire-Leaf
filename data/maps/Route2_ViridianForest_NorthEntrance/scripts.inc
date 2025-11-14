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
	applymovement LOCALID_BUGSY_NORTH_GATE, Common_Movement_ExclamationMark
# 17 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	waitmovement 0
# 18 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement LOCALID_BUGSY_NORTH_GATE, Common_Movement_Delay48
# 19 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	waitmovement 0
# 20 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement LOCALID_BUGSY_NORTH_GATE, Route2_ViridianForest_NorthEntrance_Movement_BugsyApproach
# 21 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	waitmovement 0
# 22 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_BugsyGreeting, MSGBOX_DEFAULT
# 23 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	closemessage
# 24 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	setvar VAR_SPOKE_TO_BUGSY, 1
# 25 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route2_ViridianForest_NorthEntrance_PlayerLetsBugsyPass
# 26 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement LOCALID_BUGSY_NORTH_GATE, Route2_ViridianForest_NorthEntrance_Movement_BugsyLeaves
# 27 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	waitmovement 0
# 28 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	removeobject LOCALID_BUGSY_NORTH_GATE
# 29 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route2_ViridianForest_NorthEntrance_PlayerLeavesAfterBugsy
# 30 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	waitmovement 0
# 31 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	setflag FLAG_HIDE_BUGSY_NORTH_GATE
# 32 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	clearflag FLAG_HIDE_BUGSY_VIRIDIAN_FOREST
# 33 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	setvar VAR_BUGSY_VIRIDIAN_FOREST_SCENE, 1
# 34 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	warp MAP_VIRIDIAN_FOREST, 5, 10
# 35 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	waitstate
# 36 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	releaseall
	return


# 39 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_Movement_BugsyApproach:
# 40 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_down
# 41 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_down
	step_end

# 44 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_PlayerLetsBugsyPass:
# 45 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_left
# 46 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	face_right
	step_end

# 49 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_Movement_BugsyLeaves:
# 50 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_down
# 51 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_down
	step_end

# 54 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_PlayerLeavesAfterBugsy:
# 55 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_right
# 56 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_down
	step_end

# 60 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"

# 61 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_EventScript_Youngster::
# 62 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_ManyMonsOnlyInForests, MSGBOX_NPC
# 63 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	end
# 64 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"

# 65 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_EventScript_OldMan::
# 66 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_CanCutSkinnyTrees, MSGBOX_NPC
# 67 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	end
# 68 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"

# 69 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_EventScript_CooltrainerF::
# 70 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_CanCancelEvolution, MSGBOX_NPC
# 71 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	end
