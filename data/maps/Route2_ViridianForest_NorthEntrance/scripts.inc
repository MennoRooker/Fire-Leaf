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


# 13 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"

# 14 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
@ Local definitions of common movements (needed because this map is included before movement.inc)
# 15 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Local_Movement_ExclamationMark::
# 16 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	emote_exclamation_mark
# 17 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	step_end
# 18 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"

# 19 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Local_Movement_Delay48::
# 20 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	delay_16
# 21 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	delay_16
# 22 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	delay_16
# 23 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	step_end

Route2_ViridianForest_NorthEntrance_EventScript_Bugsy::
# 27 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	lockall
# 28 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	playse SE_PIN
# 29 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement LOCALID_BUGSY, Local_Movement_ExclamationMark
# 30 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	waitmovement 0
# 31 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement LOCALID_BUGSY, Local_Movement_Delay48
# 32 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	waitmovement 0
# 33 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement LOCALID_BUGSY, Route2_ViridianForest_NorthEntrance_Movement_BugsyApproach
# 34 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	waitmovement 0
# 35 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_BugsyGreeting, MSGBOX_DEFAULT
# 36 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	closemessage
# 37 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	setvar VAR_SPOKE_TO_BUGSY, 1
# 38 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route2_ViridianForest_NorthEntrance_PlayerLetsBugsyPass
# 39 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement LOCALID_BUGSY, Route2_ViridianForest_NorthEntrance_Movement_BugsyLeaves
# 40 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	waitmovement 0
# 41 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	removeobject LOCALID_BUGSY
# 42 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route2_ViridianForest_NorthEntrance_PlayerLeavesAfterBugsy
# 43 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	waitmovement 0
# 44 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	setvar VAR_BUGSY_VIRIDIAN_FOREST_SCENE, 1
# 45 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	warp MAP_VIRIDIAN_FOREST, 5, 10
# 46 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	waitstate
# 47 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	releaseall
	return


# 50 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_Movement_BugsyApproach:
# 51 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_down
# 52 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_down
	step_end

# 55 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_PlayerLetsBugsyPass:
# 56 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_left
# 57 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	face_right
	step_end

# 60 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_Movement_BugsyLeaves:
# 61 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_down
# 62 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_down
	step_end

# 65 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_PlayerLeavesAfterBugsy:
# 66 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_right
# 67 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	walk_down
	step_end

# 71 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"

# 72 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_EventScript_Youngster::
# 73 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_ManyMonsOnlyInForests, MSGBOX_NPC
# 74 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	end
# 75 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"

# 76 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_EventScript_OldMan::
# 77 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_CanCutSkinnyTrees, MSGBOX_NPC
# 78 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	end
# 79 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"

# 80 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
Route2_ViridianForest_NorthEntrance_EventScript_CooltrainerF::
# 81 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	msgbox Route2_ViridianForest_NorthEntrance_Text_CanCancelEvolution, MSGBOX_NPC
# 82 "data/maps/Route2_ViridianForest_NorthEntrance/scripts.pory"
	end
