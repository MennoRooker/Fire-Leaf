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
	delay_16
# 36 "data/maps/ViridianForest/scripts.pory"
	face_up
	step_end

# 39 "data/maps/ViridianForest/scripts.pory"
ViridianForest_Movement_BugsyLooksAround:
# 40 "data/maps/ViridianForest/scripts.pory"
	face_right
# 41 "data/maps/ViridianForest/scripts.pory"
	delay_16
# 42 "data/maps/ViridianForest/scripts.pory"
	face_down
# 43 "data/maps/ViridianForest/scripts.pory"
	delay_16
# 44 "data/maps/ViridianForest/scripts.pory"
	face_left
# 45 "data/maps/ViridianForest/scripts.pory"
	delay_16
# 46 "data/maps/ViridianForest/scripts.pory"
	face_down
# 47 "data/maps/ViridianForest/scripts.pory"
	delay_16
# 48 "data/maps/ViridianForest/scripts.pory"
	delay_16
	step_end

# 51 "data/maps/ViridianForest/scripts.pory"

# 52 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Youngster::
# 53 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
# 54 "data/maps/ViridianForest/scripts.pory"
	end
# 55 "data/maps/ViridianForest/scripts.pory"

# 56 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Boy::
# 57 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
# 58 "data/maps/ViridianForest/scripts.pory"
	end
# 59 "data/maps/ViridianForest/scripts.pory"

# 60 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_TrainerTips1::
# 61 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
# 62 "data/maps/ViridianForest/scripts.pory"
	end
# 63 "data/maps/ViridianForest/scripts.pory"

# 64 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_TrainerTips2::
# 65 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
# 66 "data/maps/ViridianForest/scripts.pory"
	end
# 67 "data/maps/ViridianForest/scripts.pory"

# 68 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_TrainerTips3::
# 69 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
# 70 "data/maps/ViridianForest/scripts.pory"
	end
# 71 "data/maps/ViridianForest/scripts.pory"

# 72 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_TrainerTips4::
# 73 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
# 74 "data/maps/ViridianForest/scripts.pory"
	end
# 75 "data/maps/ViridianForest/scripts.pory"

# 76 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_TrainerTips5::
# 77 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
# 78 "data/maps/ViridianForest/scripts.pory"
	end
# 79 "data/maps/ViridianForest/scripts.pory"

# 80 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_ExitSign::
# 81 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
# 82 "data/maps/ViridianForest/scripts.pory"
	end
# 83 "data/maps/ViridianForest/scripts.pory"

# 84 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Rick::
# 85 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
# 86 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
# 87 "data/maps/ViridianForest/scripts.pory"
	end
# 88 "data/maps/ViridianForest/scripts.pory"

# 89 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Doug::
# 90 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
# 91 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
# 92 "data/maps/ViridianForest/scripts.pory"
	end
# 93 "data/maps/ViridianForest/scripts.pory"

# 94 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Sammy::
# 95 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
# 96 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
# 97 "data/maps/ViridianForest/scripts.pory"
	end
# 98 "data/maps/ViridianForest/scripts.pory"

# 99 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Anthony::
# 100 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
# 101 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
# 102 "data/maps/ViridianForest/scripts.pory"
	end
# 103 "data/maps/ViridianForest/scripts.pory"

# 104 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Charlie::
# 105 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
# 106 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
# 107 "data/maps/ViridianForest/scripts.pory"
	end
