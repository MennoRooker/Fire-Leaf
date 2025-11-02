ViridianForest_MapScripts::
# 2 "data/maps/ViridianForest/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
# 3 "data/maps/ViridianForest/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ViridianForest_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

ViridianForest_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/ViridianForest/scripts.pory"
	map_script_2 VAR_BUGSY_VIRIDIAN_FOREST_SCENE, 1, ViridianForest_EventScript_BugsyCutscene
	.2byte 0


ViridianForest_OnTransition::
# 9 "data/maps/ViridianForest/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_FOREST
	return


ViridianForest_EventScript_BugsyCutscene::
# 13 "data/maps/ViridianForest/scripts.pory"
	lockall
# 14 "data/maps/ViridianForest/scripts.pory"
	applymovement LOCALID_BUGSY_VIRIDIAN_FOREST, ViridianForest_Movement_BugsyLooksAround
# 15 "data/maps/ViridianForest/scripts.pory"
	waitmovement 0
# 16 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_BugsyLooksForNet, MSGBOX_DEFAULT
# 17 "data/maps/ViridianForest/scripts.pory"
	applymovement LOCALID_BUGSY_VIRIDIAN_FOREST, ViridianForest_Movement_BugsyFacesPlayer
# 18 "data/maps/ViridianForest/scripts.pory"
	waitmovement 0
# 19 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_BugsySendsPlayerToRoute22, MSGBOX_DEFAULT
# 20 "data/maps/ViridianForest/scripts.pory"
	applymovement LOCALID_BUGSY_VIRIDIAN_FOREST, ViridianForest_Movement_BugsyLeaves
# 21 "data/maps/ViridianForest/scripts.pory"
	waitmovement 0
# 22 "data/maps/ViridianForest/scripts.pory"
	removeobject LOCALID_BUGSY_VIRIDIAN_FOREST
# 23 "data/maps/ViridianForest/scripts.pory"
	setvar VAR_BUGSY_VIRIDIAN_FOREST_SCENE, 0
# 24 "data/maps/ViridianForest/scripts.pory"
	setflag FLAG_HIDE_BUGSY_VIRIDIAN_FOREST
# 25 "data/maps/ViridianForest/scripts.pory"
	releaseall
	return


# 28 "data/maps/ViridianForest/scripts.pory"
ViridianForest_Movement_BugsyLeaves:
# 29 "data/maps/ViridianForest/scripts.pory"
	walk_left
# 30 "data/maps/ViridianForest/scripts.pory"
	walk_up
# 31 "data/maps/ViridianForest/scripts.pory"
	walk_up
	step_end

# 34 "data/maps/ViridianForest/scripts.pory"
ViridianForest_Movement_BugsyFacesPlayer:
# 35 "data/maps/ViridianForest/scripts.pory"
	face_up
	step_end

# 38 "data/maps/ViridianForest/scripts.pory"
ViridianForest_Movement_BugsyLooksAround:
# 39 "data/maps/ViridianForest/scripts.pory"
	face_right
# 40 "data/maps/ViridianForest/scripts.pory"
	delay_16
# 41 "data/maps/ViridianForest/scripts.pory"
	face_down
# 42 "data/maps/ViridianForest/scripts.pory"
	delay_16
# 43 "data/maps/ViridianForest/scripts.pory"
	face_left
# 44 "data/maps/ViridianForest/scripts.pory"
	delay_16
# 45 "data/maps/ViridianForest/scripts.pory"
	face_down
# 46 "data/maps/ViridianForest/scripts.pory"
	delay_16
	step_end

# 49 "data/maps/ViridianForest/scripts.pory"

# 50 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Youngster::
# 51 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
# 52 "data/maps/ViridianForest/scripts.pory"
	end
# 53 "data/maps/ViridianForest/scripts.pory"

# 54 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Boy::
# 55 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
# 56 "data/maps/ViridianForest/scripts.pory"
	end
# 57 "data/maps/ViridianForest/scripts.pory"

# 58 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_TrainerTips1::
# 59 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
# 60 "data/maps/ViridianForest/scripts.pory"
	end
# 61 "data/maps/ViridianForest/scripts.pory"

# 62 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_TrainerTips2::
# 63 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
# 64 "data/maps/ViridianForest/scripts.pory"
	end
# 65 "data/maps/ViridianForest/scripts.pory"

# 66 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_TrainerTips3::
# 67 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
# 68 "data/maps/ViridianForest/scripts.pory"
	end
# 69 "data/maps/ViridianForest/scripts.pory"

# 70 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_TrainerTips4::
# 71 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
# 72 "data/maps/ViridianForest/scripts.pory"
	end
# 73 "data/maps/ViridianForest/scripts.pory"

# 74 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_TrainerTips5::
# 75 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
# 76 "data/maps/ViridianForest/scripts.pory"
	end
# 77 "data/maps/ViridianForest/scripts.pory"

# 78 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_ExitSign::
# 79 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
# 80 "data/maps/ViridianForest/scripts.pory"
	end
# 81 "data/maps/ViridianForest/scripts.pory"

# 82 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Rick::
# 83 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
# 84 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
# 85 "data/maps/ViridianForest/scripts.pory"
	end
# 86 "data/maps/ViridianForest/scripts.pory"

# 87 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Doug::
# 88 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
# 89 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
# 90 "data/maps/ViridianForest/scripts.pory"
	end
# 91 "data/maps/ViridianForest/scripts.pory"

# 92 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Sammy::
# 93 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
# 94 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
# 95 "data/maps/ViridianForest/scripts.pory"
	end
# 96 "data/maps/ViridianForest/scripts.pory"

# 97 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Anthony::
# 98 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
# 99 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
# 100 "data/maps/ViridianForest/scripts.pory"
	end
# 101 "data/maps/ViridianForest/scripts.pory"

# 102 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Charlie::
# 103 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
# 104 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
# 105 "data/maps/ViridianForest/scripts.pory"
	end
