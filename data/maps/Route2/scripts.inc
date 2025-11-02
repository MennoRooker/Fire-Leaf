Route2_MapScripts::
# 2 "data/maps/Route2/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route2_OnTransition
# 3 "data/maps/Route2/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/Route2/scripts.pory"
	map_script_2 VAR_BUGSY_ROUTE2_SCENE, 0, Route2_EventScript_BugsyCutscene
	.2byte 0


Route2_OnTransition::
# 9 "data/maps/Route2/scripts.pory"
	goto_if_unset FLAG_BUGSY_ITEM_EXCHANGED, Route2_OnTransition_1
	return

Route2_OnTransition_1:
# 10 "data/maps/Route2/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 11 "data/maps/Route2/scripts.pory"
	compare VAR_TEMP_2, 15
	goto_if_ge Route2_OnTransition_3
# 14 "data/maps/Route2/scripts.pory"
	setvar VAR_BUGSY_ROUTE2_SCENE, 0
	return

Route2_OnTransition_3:
# 12 "data/maps/Route2/scripts.pory"
	setvar VAR_BUGSY_ROUTE2_SCENE, 1
	return


Route2_EventScript_BugsyCutscene::
# 21 "data/maps/Route2/scripts.pory"
	lockall
# 22 "data/maps/Route2/scripts.pory"
	applymovement LOCALID_BUGSY_ROUTE2, Route2_Movement_BugsyFacesPlayer
# 23 "data/maps/Route2/scripts.pory"
	waitmovement 0
# 24 "data/maps/Route2/scripts.pory"
	playse SE_PIN
# 25 "data/maps/Route2/scripts.pory"
	applymovement LOCALID_BUGSY_ROUTE2, Common_Movement_ExclamationMark
# 26 "data/maps/Route2/scripts.pory"
	waitmovement 0
# 27 "data/maps/Route2/scripts.pory"
	applymovement LOCALID_BUGSY_ROUTE2, Common_Movement_Delay48
# 28 "data/maps/Route2/scripts.pory"
	waitmovement 0
# 29 "data/maps/Route2/scripts.pory"
	applymovement LOCALID_BUGSY_ROUTE2, Route2_Movement_BugsyApproach
# 30 "data/maps/Route2/scripts.pory"
	waitmovement 0
# 31 "data/maps/Route2/scripts.pory"
	msgbox Route2_Text_BugsyNetNotInInventory, MSGBOX_DEFAULT
# 32 "data/maps/Route2/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route2_Movement_PlayerLeaves
# 33 "data/maps/Route2/scripts.pory"
	warp MAP_ROUTE2_VIRIDIAN_FOREST_NORTH_ENTRANCE, 7, 2
# 34 "data/maps/Route2/scripts.pory"
	setvar VAR_BUGSY_ROUTE2_SCENE, 1
# 35 "data/maps/Route2/scripts.pory"
	setflag FLAG_BUGSY_ITEM_EXCHANGED
# 36 "data/maps/Route2/scripts.pory"
	releaseall
	return


# 39 "data/maps/Route2/scripts.pory"
Route2_Movement_BugsyFacesPlayer:
# 40 "data/maps/Route2/scripts.pory"
	face_down
	step_end

# 43 "data/maps/Route2/scripts.pory"
Route2_Movement_BugsyApproach:
# 44 "data/maps/Route2/scripts.pory"
	walk_down
# 45 "data/maps/Route2/scripts.pory"
	walk_down
	step_end

# 48 "data/maps/Route2/scripts.pory"
Route2_Movement_PlayerLeaves:
# 49 "data/maps/Route2/scripts.pory"
	walk_down
# 50 "data/maps/Route2/scripts.pory"
	walk_down
	step_end

# 53 "data/maps/Route2/scripts.pory"

# 54 "data/maps/Route2/scripts.pory"
Route2_EventScript_RouteSign::
# 55 "data/maps/Route2/scripts.pory"
	msgbox Route2_Text_RouteSign, MSGBOX_SIGN
# 56 "data/maps/Route2/scripts.pory"
	end
# 57 "data/maps/Route2/scripts.pory"

# 58 "data/maps/Route2/scripts.pory"
Route2_EventScript_DiglettsCaveSign::
# 59 "data/maps/Route2/scripts.pory"
	msgbox Route2_Text_DiglettsCave, MSGBOX_SIGN
# 60 "data/maps/Route2/scripts.pory"
	end
