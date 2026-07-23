Route7_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route7_OnLoad
	.byte 0

Route7_OnLoad::
	goto_if_eq VAR_TEAM_ROCKET_SCENE_COMPLETE, 1, Route7_OnLoad_SetFaceDown
	end

Route7_OnLoad_SetFaceDown::
	setobjectmovementtype LOCALID_JESSIE, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_JAMES, MOVEMENT_TYPE_FACE_DOWN
	end

Route7_EventScript_UndergroundPathSign::
	msgbox Route7_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route7_EventScript_TeamRocketSceneTop::
	lockall
	playbgm MUS_ENCOUNTER_ROCKET, 0
	applymovement OBJ_EVENT_ID_PLAYER, Route7_Movement_LooksUp
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Route7_Movement_CameraPanUp1
	waitmovement 0
	delay 30
	call Route7_EventScript_TeamRocketArgues
	applymovement LOCALID_CAMERA, Route7_Movement_CameraPanDown1
	waitmovement 0
	setvar VAR_TEAM_ROCKET_SCENE_COMPLETE, 1
	special RemoveCameraObject
	fadedefaultbgm
	delay 100
	release
	end

Route7_EventScript_TeamRocketSceneMiddle::
	lockall
	playbgm MUS_ENCOUNTER_ROCKET, 0
	applymovement OBJ_EVENT_ID_PLAYER, Route7_Movement_LooksUp
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Route7_Movement_CameraPanUp2
	waitmovement 0
	delay 30
	call Route7_EventScript_TeamRocketArgues
	applymovement LOCALID_CAMERA, Route7_Movement_CameraPanDown2
	waitmovement 0
	setvar VAR_TEAM_ROCKET_SCENE_COMPLETE, 1
	special RemoveCameraObject
	fadedefaultbgm
	delay 100
	release
	end

Route7_EventScript_TeamRocketSceneBottom::
	lockall
	playbgm MUS_ENCOUNTER_ROCKET, 0
	applymovement OBJ_EVENT_ID_PLAYER, Route7_Movement_WalksUp
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Route7_Movement_CameraPanUp2
	waitmovement 0
	delay 30
	call Route7_EventScript_TeamRocketArgues
	applymovement LOCALID_CAMERA, Route7_Movement_CameraPanDown2
	waitmovement 0
	setvar VAR_TEAM_ROCKET_SCENE_COMPLETE, 1
	special RemoveCameraObject
	fadedefaultbgm
	delay 100
	release
	end

Route7_EventScript_TeamRocketArgues::
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox Route7_Text_Jessie1
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Route7_Text_James1
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox Route7_Text_Jessie2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	applymovement LOCALID_CAMERA, Route7_Movement_CameraPanUp1
	waitmovement 0
	delay 10
	msgbox Route7_Text_Meowth1
	applymovement LOCALID_JAMES, Route7_Movement_LooksUp
	waitmovement 0
	delay 10
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Route7_Text_James2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Route7_Text_Meowth2
	applymovement LOCALID_CAMERA, Route7_Movement_CameraPanDown1
	waitmovement 0
	applymovement LOCALID_JESSIE, Route7_Movement_LooksDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_JESSIE, Common_Movement_ExclamationMark
	waitmovement 0
	delay 40
	applymovement LOCALID_JESSIE, Route7_Movement_LooksLeft
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox Route7_Text_Jessie3
	applymovement LOCALID_JAMES, Route7_Movement_LooksRight
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Route7_Text_James3
	applymovement LOCALID_JAMES, Route7_Movement_LooksDown
	applymovement LOCALID_JESSIE, Route7_Movement_LooksDown
	waitmovement 0
	msgbox Route7_Text_James4
	applymovement LOCALID_CAMERA, Route7_Movement_CameraPanUp1
	waitmovement 0
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Route7_Text_Meowth3
	applymovement LOCALID_JAMES, Route7_Movement_LooksUp
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Route7_Text_James5
	applymovement LOCALID_JESSIE, Route7_Movement_LooksLeft
	waitmovement 0
	applymovement LOCALID_CAMERA, Route7_Movement_CameraPanDown1
	applymovement LOCALID_JAMES, Route7_Movement_LooksRight
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox Route7_Text_Jessie4
	applymovement LOCALID_JESSIE, Route7_Movement_LooksDown
	waitmovement 0
	applymovement LOCALID_JAMES, Route7_Movement_LooksDown
	waitmovement 0
	msgbox Route7_Text_Jessie5
	closemessage
	return

Route7_Movement_LooksUp::
	face_up
	step_end

Route7_Movement_LooksDown::
	face_down
	step_end

Route7_Movement_LooksLeft::
	face_left
	step_end

Route7_Movement_LooksRight::
	face_right
	step_end

Route7_Movement_WalksUp::
	walk_up
	step_end

Route7_Movement_CameraPanUp1::
	walk_up
	step_end

Route7_Movement_CameraPanUp2::
	walk_up
	walk_up
	step_end

Route7_Movement_CameraPanDown1::
	walk_down
	step_end

Route7_Movement_CameraPanDown2::
	walk_down
	walk_down
	step_end

Route7_EventScript_James::
	msgbox PewterCity_Text_JamesPostScene, MSGBOX_NPC
	end

Route7_EventScript_Jessie::
	msgbox PewterCity_Text_JessiePostScene, MSGBOX_NPC
	end
