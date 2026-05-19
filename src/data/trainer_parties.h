// Trainer party data exists for all of the RS trainer classes, but
// are only filled with one of the following placeholder pokemon.
// The actual FRLG trainer party data starts after these.
#define DUMMY_TRAINER_MON           \
    {                               \
        .lvl = 5,                   \
        .species = SPECIES_EKANS,   \
    }

#define DUMMY_TRAINER_MON_IV        \
    {                               \
        .iv = 10,                   \
        .lvl = 5,                   \
        .species = SPECIES_EKANS,   \
    }

// Copy of Swimmer Male Finn's party
#define DUMMY_TRAINER_STARMIE       \
    {                               \
        .lvl = 38,                  \
        .species = SPECIES_STARMIE, \
    }

static const struct TrainerMonNoItemDefaultMoves sParty_AquaLeader[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_AquaGruntM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_AquaGruntF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSAromaLady[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSRuinManiac[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_Interviewer[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSTuberF[] = {DUMMY_TRAINER_STARMIE};
static const struct TrainerMonNoItemDefaultMoves sParty_RSTuberM[] = {DUMMY_TRAINER_STARMIE};
static const struct TrainerMonNoItemDefaultMoves sParty_RSCooltrainerM[] = {DUMMY_TRAINER_MON_IV};
static const struct TrainerMonNoItemDefaultMoves sParty_RSCooltrainerF[] = {DUMMY_TRAINER_MON_IV};
static const struct TrainerMonNoItemDefaultMoves sParty_HexManiac[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSLady[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSBeauty[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RichBoy[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSPokemaniac[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSSwimmerM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSBlackBelt[] = {DUMMY_TRAINER_MON_IV};
static const struct TrainerMonNoItemDefaultMoves sParty_Guitarist[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_Kindler[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSCamper[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_BugManiac[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSPsychicM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSPsychicF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSGentleman[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_EliteFourSidney[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_EliteFourPhoebe[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_LeaderRoxanne[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_LeaderBrawly[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_LeaderTateLiza[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_SchoolKidM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_SchoolKidF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_SrAndJr[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_PokefanM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_PokefanF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_ExpertM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_ExpertF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSYoungster[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSChampion[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSFisherman[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_CyclingTriathleteM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_CyclingTriathleteF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RunningTriathleteM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RunningTriathleteF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_SwimmingTriathleteM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_SwimmingTriathleteF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_DragonTamer[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSBirdKeeper[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_NinjaBoy[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_BattleGirl[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_ParasolLady[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSSwimmerF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSPicnicker[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSTwins[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSSailor[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_BoarderM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_BoarderF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_Collector[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_Wally[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_Brendan[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_Brendan2[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_Brendan3[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_May[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_May2[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_May3[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSPkmnBreederM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSPkmnBreederF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSPkmnRangerM[] = {DUMMY_TRAINER_MON_IV};
static const struct TrainerMonNoItemDefaultMoves sParty_RSPkmnRangerF[] = {DUMMY_TRAINER_MON_IV};
static const struct TrainerMonNoItemDefaultMoves sParty_MagmaLeader[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_MagmaGruntM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_MagmaGruntF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSLass[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSBugCatcher[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSHiker[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSYoungCouple[] = {DUMMY_TRAINER_MON, DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_OldCouple[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_RSSisAndBro[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_AquaAdminMatt[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_AquaAdminShelly[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_MagmaAdminTabitha[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_MagmaAdminCourtney[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_LeaderWattson[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_LeaderFlannery[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_LeaderNorman[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_LeaderWinona[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_LeaderWallace[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_EliteFourGlacia[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_EliteFourDrake[] = {DUMMY_TRAINER_MON};

// Unused FRLG
static const struct TrainerMonNoItemDefaultMoves sParty_Camper2[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_Biker1[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_Biker2[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_Gamer1[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_Lass2[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerHannah[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_SuperNerd1[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_SuperNerd2[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_SuperNerd3[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_Burglar1[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_Burglar2[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_Burglar3[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_Burglar4[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt22[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcher2[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcher3[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcher4[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcher5[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcher6[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcher7[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcher8[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_PkmnProfProfOak[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_PlayerBrendan[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_PlayerMay[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_PlayerRed[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_PlayerLeaf[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_GentlemanWalter[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_ChannelerPatricia[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_ChannelerCarly[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_ChannelerPaula[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_ChannelerTammy[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_ChannelerKarina[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonNoItemDefaultMoves sParty_ChannelerJanae[] = {DUMMY_TRAINER_MON};


// Start of actual trainer data

// ======================================================================================== //
// ======================================= Oak's Lab ======================================= //
// ======================================================================================== //
static const struct TrainerMonNoItemDefaultMoves sParty_RivalOaksLabSquirtle[] = {
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_SQUIRTLE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_RivalOaksLabBulbasaur[] = {
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_BULBASAUR,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_RivalOaksLabCharmander[] = {
    {
        .iv = 0,
        .lvl = 5,
        .species = SPECIES_CHARMANDER,
    },
};


// ======================================================================================= //
// ======================================= Route 2 ======================================= //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_CamperMax[] = {
    {
        .iv = 0,
        .lvl = 6,
        .species = SPECIES_ZIGZAGOON,
    },
};


// =========================================================================================== //
// ===================================== Viridian Forest ===================================== //
// =========================================================================================== //
static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherRick[] = {
    {
        .iv = 0,
        .lvl = 6,
        .species = SPECIES_SPINARAK,
    },
    {
        .iv = 0,
        .lvl = 6,
        .species = SPECIES_CATERPIE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherDoug[] = {
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_WEEDLE,
    },
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_KAKUNA,
    },
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_METAPOD,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherAnthony[] = {
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_WURMPLE,
    },
    {
        .iv = 0,
        .lvl = 8,
        .species = SPECIES_SILCOON,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherCharlie[] = {
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_LEDYBA,
    },
    {
        .iv = 0,
        .lvl = 7,
        .species = SPECIES_CASCOON,
    },
    {
        .iv = 0,
        .lvl = 8,
        .species = SPECIES_VOLBEAT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherSammy[] = {
    {
        .iv = 0,
        .lvl = 8,
        .species = SPECIES_ILLUMISE,
    },
};


// ======================================================================================== //
// ======================================= Route 22 ======================================= //
// ======================================================================================== //
static const struct TrainerMonNoItemCustomMoves sParty_RivalRoute22EarlySquirtle[] = {
    {
        .iv = 5,
        .lvl = 9,
        .species = SPECIES_PIDGEY,
        .moves = {MOVE_GUST, MOVE_TACKLE, MOVE_SAND_ATTACK, MOVE_NONE},
    },
    {
        .iv = 5,
        .lvl = 10,
        .species = SPECIES_SQUIRTLE,
        .moves = {MOVE_BUBBLE, MOVE_TACKLE, MOVE_TAIL_WHIP, MOVE_NONE},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_RivalRoute22EarlyBulbasaur[] = {
    {
        .iv = 5,
        .lvl = 9,
        .species = SPECIES_PIDGEY,
        .moves = {MOVE_GUST, MOVE_TACKLE, MOVE_SAND_ATTACK, MOVE_NONE},
    },
    {
        .iv = 5,
        .lvl = 10,
        .species = SPECIES_BULBASAUR,
        .moves = {MOVE_VINE_WHIP, MOVE_TACKLE, MOVE_GROWL, MOVE_LEECH_SEED},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_RivalRoute22EarlyCharmander[] = {
    {
        .iv = 5,
        .lvl = 9,
        .species = SPECIES_PIDGEY,
        .moves = {MOVE_GUST, MOVE_TACKLE, MOVE_SAND_ATTACK, MOVE_NONE},
    },
    {
        .iv = 5,
        .lvl = 10,
        .species = SPECIES_CHARMANDER,
        .moves = {MOVE_EMBER, MOVE_SCRATCH, MOVE_GROWL, MOVE_NONE},
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_RivalRoute22LateSquirtle[] = {
    {
        .iv = 30,
        .lvl = 57,
        .species = SPECIES_PIDGEOT,
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_FEATHER_DANCE, MOVE_WING_ATTACK, MOVE_DOUBLE_EDGE, MOVE_QUICK_ATTACK},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 56,
        .species = SPECIES_SNORLAX,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_ROCK_SLIDE, MOVE_BODY_SLAM, MOVE_YAWN, MOVE_CURSE},
        .nature = NATURE_IMPISH,
        .abilitySlot = 1,
    },
    {
        .iv = 30,
        .lvl = 57,
        .species = SPECIES_EXEGGUTOR,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_GIGA_DRAIN, MOVE_PSYBEAM},
        .nature = NATURE_BOLD,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 57,
        .species = SPECIES_ARCANINE,
        .heldItem = ITEM_CHARCOAL,
        .moves = {MOVE_FLAMETHROWER, MOVE_EXTREME_SPEED, MOVE_BITE, MOVE_AGILITY},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 57,
        .species = SPECIES_HERACROSS,
        .heldItem = ITEM_BLACK_BELT,
        .moves = {MOVE_BRICK_BREAK, MOVE_MEGAHORN, MOVE_AERIAL_ACE, MOVE_STRENGTH},
        .nature = NATURE_JOLLY,
        .abilitySlot = 1,
    },
    {
        .iv = 30,
        .lvl = 60,
        .species = SPECIES_BLASTOISE,
        .heldItem = ITEM_MYSTIC_WATER,
        .moves = {MOVE_WATER_PULSE, MOVE_RAIN_DANCE, MOVE_ICE_BEAM, MOVE_BITE},
        .nature = NATURE_HARDY,
        .abilitySlot = 1,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_RivalRoute22LateBulbasaur[] = {
    {
        .iv = 30,
        .lvl = 57,
        .species = SPECIES_PIDGEOT,
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_FEATHER_DANCE, MOVE_WING_ATTACK, MOVE_DOUBLE_EDGE, MOVE_QUICK_ATTACK},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 56,
        .species = SPECIES_SNORLAX,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_ROCK_SLIDE, MOVE_BODY_SLAM, MOVE_YAWN, MOVE_CURSE},
        .nature = NATURE_IMPISH,
        .abilitySlot = 1,
    },
    {
        .iv = 30,
        .lvl = 57,
        .species = SPECIES_ALAKAZAM,
        .heldItem = ITEM_TWISTED_SPOON,
        .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_SHOCK_WAVE, MOVE_DISABLE},
        .nature = NATURE_MODEST,
        .abilitySlot = 1,
    },
    {
        .iv = 30,
        .lvl = 57,
        .species = SPECIES_ARCANINE,
        .heldItem = ITEM_CHARCOAL,
        .moves = {MOVE_FLAMETHROWER, MOVE_EXTREME_SPEED, MOVE_BITE, MOVE_AGILITY},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 57,
        .species = SPECIES_GYARADOS,
        .heldItem = ITEM_MYSTIC_WATER,
        .moves = {MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_TWISTER, MOVE_RAIN_DANCE},
        .nature = NATURE_NAUGHTY,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 60,
        .species = SPECIES_VENUSAUR,
        .heldItem = ITEM_MIRACLE_SEED,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_GROWTH, MOVE_SYNTHESIS},
        .nature = NATURE_HARDY,
        .abilitySlot = 1,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_RivalRoute22LateCharmander[] = {
    {
        .iv = 30,
        .lvl = 57,
        .species = SPECIES_PIDGEOT,
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_FEATHER_DANCE, MOVE_WING_ATTACK, MOVE_DOUBLE_EDGE, MOVE_QUICK_ATTACK},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 56,
        .species = SPECIES_SNORLAX,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_ROCK_SLIDE, MOVE_BODY_SLAM, MOVE_YAWN, MOVE_CURSE},
        .nature = NATURE_IMPISH,
        .abilitySlot = 1,
    },
    {
        .iv = 30,
        .lvl = 57,
        .species = SPECIES_EXEGGUTOR,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_GIGA_DRAIN, MOVE_PSYBEAM},
        .nature = NATURE_BOLD,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 57,
        .species = SPECIES_ALAKAZAM,
        .heldItem = ITEM_TWISTED_SPOON,
        .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_SHOCK_WAVE, MOVE_DISABLE},
        .nature = NATURE_MODEST,
        .abilitySlot = 1,
    },
    {
        .iv = 30,
        .lvl = 57,
        .species = SPECIES_GYARADOS,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_TWISTER, MOVE_RAIN_DANCE},
        .nature = NATURE_NAUGHTY,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 60,
        .species = SPECIES_CHARIZARD,
        .heldItem = ITEM_CHARCOAL,
        .moves = {MOVE_FLAMETHROWER, MOVE_WING_ATTACK, MOVE_DRAGON_BREATH, MOVE_SMOKESCREEN},
        .nature = NATURE_HARDY,
        .abilitySlot = 1,
    },
};

// ============================================================================================= //
// ======================================== Pewter City ======================================== //
// ============================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_BurglarKelvin[] = {
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_POOCHYENA,
    },
};


// ============================================================================================= //
// ====================================== Pewter City Gym ====================================== //
// ============================================================================================= //
static const struct TrainerMonNoItemCustomMoves sParty_CamperLiam[] = {
    {
        .iv = 3,
        .lvl = 10,
        .species = SPECIES_SANDSHREW,
        .moves = {MOVE_SCRATCH, MOVE_DEFENSE_CURL, MOVE_SAND_ATTACK, MOVE_NONE},
    },
    {
        .iv = 3,
        .lvl = 11,
        .species = SPECIES_GEODUDE,
        .moves = {MOVE_TACKLE, MOVE_DEFENSE_CURL, MOVE_NONE, MOVE_NONE},
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_LeaderBrock[] = {
    {
        .iv = 3,
        .lvl = 12,
        .species = SPECIES_GEODUDE,
        .moves = {MOVE_ROCK_THROW, MOVE_DEFENSE_CURL, MOVE_TACKLE, MOVE_MUD_SPORT},
        .heldItem = ITEM_NONE,
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 3,
        .lvl = 12,
        .species = SPECIES_NOSEPASS,
        .moves = {MOVE_ROCK_TOMB, MOVE_TACKLE, MOVE_HARDEN, MOVE_BLOCK},
        .heldItem = ITEM_NONE,
        .nature = NATURE_MILD,
        .abilitySlot = 1,
    },
    {
        .iv = 3,
        .lvl = 14,
        .species = SPECIES_ONIX,
        .moves = {MOVE_ROCK_TOMB, MOVE_TACKLE, MOVE_BIND, MOVE_SCREECH},
        .heldItem = ITEM_NONE,
        .nature = NATURE_CALM,
        .abilitySlot = 1,
    },
};


// ======================================================================================= //
// ======================================= Route 3 ======================================= //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_LassJanice[] = {
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_PIDGEY,
    },
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_CUBONE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassJaniceRematch[] = {
    {
        .iv = 2,
        .lvl = 20,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .iv = 2,
        .lvl = 20,
        .species = SPECIES_CUBONE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassJaniceRematchAfterFuchsia[] = {
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_PIDGEOT,
    },
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_MAROWAK,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherColton[] = {
    {
        .iv = 0,
        .lvl = 8,
        .species = SPECIES_WEEDLE,
    },
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_PINECO,
    },
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_LEDYBA,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherColtonRematch[] = {
    {
        .iv = 2,
        .lvl = 20,
        .species = SPECIES_BEEDRILL,
    },
    {
        .iv = 2,
        .lvl = 20,
        .species = SPECIES_PINECO,
    },
    {
        .iv = 2,
        .lvl = 22,
        .species = SPECIES_LEDIAN,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherColtonRematchAfterFuchsia[] = {
    {
        .iv = 6,
        .lvl = 37,
        .species = SPECIES_BEEDRILL,
    },
    {
        .iv = 6,
        .lvl = 37,
        .species = SPECIES_FORRETRESS,
    },
    {
        .iv = 6,
        .lvl = 37,
        .species = SPECIES_LEDIAN,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherColtonRematchAfterSapphire[] = {
    {
        .iv = 12,
        .lvl = 51,
        .species = SPECIES_BEEDRILL,
    },
    {
        .iv = 12,
        .lvl = 54,
        .species = SPECIES_FORRETRESS,
    },
    {
        .iv = 12,
        .lvl = 56,
        .species = SPECIES_LEDIAN,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterBen[] = {
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_RATTATA,
    },
    {
        .iv = 0,
        .lvl = 10,
        .species = SPECIES_EKANS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterBenRematch[] = {
    {
        .iv = 2,
        .lvl = 21,
        .species = SPECIES_RATICATE,
    },
    {
        .iv = 2,
        .lvl = 21,
        .species = SPECIES_EKANS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterBenRematchAfterFuchsia[] = {
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_RATICATE,
    },
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_ARBOK,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterBenRematchAfterLeague[] = {
    {
        .iv = 12,
        .lvl = 58,
        .species = SPECIES_RATICATE,
    },
    {
        .iv = 12,
        .lvl = 58,
        .species = SPECIES_ARBOK,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherGreg[] = {
    {
        .iv = 0,
        .lvl = 8,
        .species = SPECIES_CATERPIE,
    },
    {
        .iv = 0,
        .lvl = 9,
        .species = SPECIES_METAPOD,
    },
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_BUTTERFREE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterCalvin[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_SPEAROW,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassSally[] = {
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_CHARMANDER,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_SQUIRTLE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherJames[] = {
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_PARAS,
    },
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_SHUCKLE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassRobin[] = {
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_JIGGLYPUFF,
    },
};


// ======================================================================================== //
// ======================================= Mt. Moon ======================================= //
// ======================================================================================== //
static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherKent[] = {
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_NINCADA,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_ANORITH,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassIris[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_CLEFAIRY,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SuperNerdAron[] = {
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_ARON,
    },
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_JIGGLYPUFF,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherRobby[] = {
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_PARAS,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_METAPOD,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_VENONAT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassMiriam[] = {
    {
        .iv = 5,
        .lvl = 13,
        .species = SPECIES_ODDISH,
    },
    {
        .iv = 5,
        .lvl = 13,
        .species = SPECIES_BULBASAUR,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterJosh[] = {
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_AIPOM,
    },
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_EEVEE,
    },
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_TAILLOW,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_HikerMarcos[] = {
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_GEODUDE,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_TRAPINCH,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_ONIX,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt[] = {
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_HOOTHOOT,
    },
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_MEOWTH,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt2[] = {
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_WHISMUR,
    },
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_RATTATA,
    },
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_WYNAUT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt3[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_SLAKOTH,
    },
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_EKANS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt4[] = {
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_ZUBAT,
    },
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_SABLEYE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SuperNerdMiguel[] = {
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_GRIMER,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_VOLTORB,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_KOFFING,
    },
};


// ======================================================================================== //
// ==================================== Cerulean City ===================================== //
// ======================================================================================== //
static const struct TrainerMonNoItemCustomMoves sParty_RivalCeruleanSquirtle[] = {
    {
        .iv = 10,
        .lvl = 17,
        .species = SPECIES_PIDGEOTTO,
        .moves = {MOVE_TACKLE, MOVE_SAND_ATTACK, MOVE_GUST, MOVE_QUICK_ATTACK},
    },
    {
        .iv = 10,
        .lvl = 16,
        .species = SPECIES_ABRA,
        .moves = {MOVE_CONFUSION, MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE}, // Hidden Power FIGHTING
    },
    {
        .iv = 10,
        .lvl = 16,
        .species = SPECIES_RATTATA,
        .moves = {MOVE_TACKLE, MOVE_TAIL_WHIP, MOVE_QUICK_ATTACK, MOVE_NONE},
    },
    {
        .iv = 10,
        .lvl = 18,
        .species = SPECIES_WARTORTLE,
        .moves = {MOVE_TACKLE, MOVE_TAIL_WHIP, MOVE_WITHDRAW, MOVE_WATER_GUN},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_RivalCeruleanBulbasaur[] = {
    {
        .iv = 10,
        .lvl = 17,
        .species = SPECIES_PIDGEOTTO,
        .moves = {MOVE_TACKLE, MOVE_SAND_ATTACK, MOVE_GUST, MOVE_QUICK_ATTACK},
    },
    {
        .iv = 10,
        .lvl = 16,
        .species = SPECIES_ABRA,
        .moves = {MOVE_CONFUSION, MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE}, // Hidden Power FIGHTING
    },
    {
        .iv = 10,
        .lvl = 16,
        .species = SPECIES_RATTATA,
        .moves = {MOVE_TACKLE, MOVE_TAIL_WHIP, MOVE_QUICK_ATTACK, MOVE_NONE},
    },
    {
        .iv = 10,
        .lvl = 18,
        .species = SPECIES_IVYSAUR,
        .moves = {MOVE_SLEEP_POWDER, MOVE_POISON_POWDER, MOVE_VINE_WHIP, MOVE_LEECH_SEED},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_RivalCeruleanCharmander[] = {
    {
        .iv = 10,
        .lvl = 17,
        .species = SPECIES_PIDGEOTTO,
        .moves = {MOVE_TACKLE, MOVE_SAND_ATTACK, MOVE_GUST, MOVE_QUICK_ATTACK},
    },
    {
        .iv = 10,
        .lvl = 16,
        .species = SPECIES_ABRA,
        .moves = {MOVE_CONFUSION, MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE}, // Hidden Power FIGHTING
    },
    {
        .iv = 10,
        .lvl = 16,
        .species = SPECIES_RATTATA,
        .moves = {MOVE_TACKLE, MOVE_TAIL_WHIP, MOVE_QUICK_ATTACK, MOVE_NONE},
    },
    {
        .iv = 10,
        .lvl = 18,
        .species = SPECIES_CHARMELEON,
        .moves = {MOVE_METAL_CLAW, MOVE_EMBER, MOVE_GROWL, MOVE_SCRATCH},
    },
};


// ======================================================================================== //
// ======================================= Route 24 ======================================= //
// ======================================================================================== //
static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherCale[] = {
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_LEDYBA,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_YANMA,
    },
    {
        .iv = 0,
        .lvl = 11,
        .species = SPECIES_DUSTOX,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassAli[] = {
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_PIDGEY,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_ODDISH,
    },
    {
        .iv = 0,
        .lvl = 12,
        .species = SPECIES_BELLSPROUT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterTimmy[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_SENTRET,
    },
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_EKANS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterTimmyRematch[] = {
    {
        .iv = 2,
        .lvl = 19,
        .species = SPECIES_FURRET,
    },
    {
        .iv = 2,
        .lvl = 19,
        .species = SPECIES_EKANS,
    },
    {
        .iv = 2,
        .lvl = 19,
        .species = SPECIES_ZUBAT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterTimmyRematchAfterFuchsia[] = {
    {
        .iv = 6,
        .lvl = 37,
        .species = SPECIES_FURRET,
    },
    {
        .iv = 6,
        .lvl = 37,
        .species = SPECIES_ARBOK,
    },
    {
        .iv = 6,
        .lvl = 37,
        .species = SPECIES_GOLBAT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterTimmyRematchAfterSapphire[] = {
    {
        .iv = 12,
        .lvl = 52,
        .species = SPECIES_FURRET,
    },
    {
        .iv = 12,
        .lvl = 52,
        .species = SPECIES_ARBOK,
    },
    {
        .iv = 12,
        .lvl = 52,
        .species = SPECIES_CROBAT,
    },
};
static const struct TrainerMonNoItemDefaultMoves sParty_LassReli[] = {
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_NIDORAN_M,
    },
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_NIDORINA,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassReliRematch[] = {
    {
        .iv = 2,
        .lvl = 20,
        .species = SPECIES_NIDORINO,
    },
    {
        .iv = 2,
        .lvl = 20,
        .species = SPECIES_NIDORINA,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassReliRematchAfterFuchsia[] = {
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_NIDORINO,
    },
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_NIDOQUEEN,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperEthan[] = {
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_MANKEY,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_SUNKERN,
    }
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt6[] = {
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_EKANS,
    },
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_ZUBAT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperShane[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_ZIGZAGOON,
    },
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_MAGBY,
    },
};


// ======================================================================================== //
// ======================================= Route 25 ======================================= //
// ======================================================================================== //
static const struct TrainerMonNoItemDefaultMoves sParty_HikerFranklin[] = {
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_SWINUB,
    },
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_GEODUDE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_HikerFranklinRematchAfterCeladon[] = {
    {
        .iv = 8,
        .lvl = 31,
        .species = SPECIES_PILOSWINE,
    },
    {
        .iv = 8,
        .lvl = 31,
        .species = SPECIES_GRAVELER,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_HikerWayne[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_ONIX,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterJoey[] = {
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_RALTS,
    },
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_SPEAROW,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterDan[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_SLOWPOKE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerKelsey[] = {
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_NIDORAN_F,
    },
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_NIDORINO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerKelseyRematch[] = {
    {
        .iv = 4,
        .lvl = 21,
        .species = SPECIES_NIDORINA,
    },
    {
        .iv = 4,
        .lvl = 21,
        .species = SPECIES_NIDORINO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerKelseyRematchAfterFuchsia[] = {
    {
        .iv = 12,
        .lvl = 39,
        .species = SPECIES_NIDORINA,
    },
    {
        .iv = 12,
        .lvl = 39,
        .species = SPECIES_NIDOKING,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerKelseyRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_NIDORINO,
    },
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_NIDORINA,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_HikerNob[] = {
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_SLAKOTH,
    },
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_RHYHORN,
    },
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_NUMEL,
    },
    {
        .iv = 0,
        .lvl = 13,
        .species = SPECIES_GEODUDE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperFlint[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_POOCHYENA,
    },
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_EKANS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterChad[] = {
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_CACNEA,
    },
    {
        .iv = 0,
        .lvl = 14,
        .species = SPECIES_MEDITITE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterChadRematch[] = {
    {
        .iv = 4,
        .lvl = 20,
        .species = SPECIES_CACNEA,
    },
    {
        .iv = 4,
        .lvl = 20,
        .species = SPECIES_MEDITITE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterChadRematchAfterFuchsia[] = {
    {
        .iv = 12,
        .lvl = 39,
        .species = SPECIES_CACTURNE,
    },
    {
        .iv = 12,
        .lvl = 39,
        .species = SPECIES_MEDICHAM,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterChadRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 61,
        .species = SPECIES_CACTURNE,
    },
    {
        .iv = 18,
        .lvl = 61,
        .species = SPECIES_MEDICHAM,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassHaley[] = {
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_ODDISH,
    },
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_CLEFAIRY,
    },
    {
        .iv = 0,
        .lvl = 15,
        .species = SPECIES_LOMBRE,
    },
};

// ======================================================================================== //
// ================================== Cerulean City Gym =================================== //
// ======================================================================================== //
static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleLuis[] = {
    {
        .iv = 6,
        .lvl = 20,
        .species = SPECIES_PSYDUCK,
    },
    {
        .iv = 6,
        .lvl = 20,
        .species = SPECIES_CLAMPERL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerDiana[] = {
    {
        .iv = 6,
        .lvl = 20,
        .species = SPECIES_GOLDEEN,
    },
    {
        .iv = 6,
        .lvl = 20,
        .species = SPECIES_TENTACOOL,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_LeaderMisty[] = {
    {
        .iv = 6,
        .lvl = 21,
        .species = SPECIES_STARYU,
        .moves = {MOVE_CONFUSION, MOVE_HARDEN, MOVE_RECOVER, MOVE_WATER_PULSE},
    },
    {
        .iv = 6,
        .lvl = 21,
        .species = SPECIES_POLIWHIRL,
        .moves = {MOVE_POUND, MOVE_HYPNOSIS, MOVE_BUBBLE_BEAM, MOVE_DOUBLE_SLAP},
    },
    {
        .iv = 6,
        .lvl = 23,
        .species = SPECIES_STARMIE,
        .moves = {MOVE_CONFUSION, MOVE_RECOVER, MOVE_RAPID_SPIN, MOVE_WATER_PULSE},
    },
};

// ======================================================================================== //
// ================================== Cerulean City East ================================== //
// ======================================================================================== //
static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt5[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_NUZLEAF,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_DROWZEE,
    },
};


// ======================================================================================= //
// ======================================= Route 5 ======================================= //
// ======================================================================================= //
static const struct TrainerMonNoItemCustomMoves sParty_YoungsterThomas[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_GROWLITHE,
        .moves = {MOVE_EMBER, MOVE_BITE, MOVE_TACKLE, MOVE_GROWL},
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_TEDDIURSA,
        .moves = {MOVE_SCRATCH, MOVE_LICK, MOVE_YAWN, MOVE_METAL_CLAW},
    },
};


// ======================================================================================= //
// ======================================= Route 6 ======================================= //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherKeigo[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_EXEGGCUTE,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_CASCOON,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_BEEDRILL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperRicky[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_WARTORTLE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperRickyRematch[] = {
    {
        .iv = 2,
        .lvl = 27,
        .species = SPECIES_WARTORTLE,
    },
    {
        .iv = 2,
        .lvl = 27,
        .species = SPECIES_GRAVELER,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperRickyRematchAfterFuchsia[] = {
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_BLASTOISE,
    },
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_GOLEM,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperRickyRematchAfterSapphire[] = {
    {
        .iv = 12,
        .lvl = 65,
        .species = SPECIES_BLASTOISE,
    },
    {
        .iv = 12,
        .lvl = 65,
        .species = SPECIES_GOLEM,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerNancy[] = {
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_FURRET,
    },
    {
        .iv = 0,
        .lvl = 16,
        .species = SPECIES_PIKACHU,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherElijah[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_BUTTERFREE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerIsabelle[] = {
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_EEVEE,
    },
    {
        .iv = 0,
        .lvl = 17,
        .species = SPECIES_PHANPY,
    },
    {
        .iv = 0,
        .lvl = 18,
        .species = SPECIES_PIDGEOTTO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerIsabelleRematch[] = {
    {
        .iv = 2,
        .lvl = 24,
        .species = SPECIES_EEVEE,
    },
    {
        .iv = 2,
        .lvl = 24,
        .species = SPECIES_PHANPY,
    },
    {
        .iv = 2,
        .lvl = 24,
        .species = SPECIES_PIDGEOTTO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerIsabelleRematchAfterFuchsia[] = {
    {
        .iv = 6,
        .lvl = 37,
        .species = SPECIES_ESPEON,
    },
    {
        .iv = 6,
        .lvl = 37,
        .species = SPECIES_DONPHAN,
    },
    {
        .iv = 6,
        .lvl = 37,
        .species = SPECIES_PIDGEOT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerIsabelleRematchAfterLeague[] = {
    {
        .iv = 8,
        .lvl = 58,
        .species = SPECIES_ESPEON,
    },
    {
        .iv = 8,
        .lvl = 58,
        .species = SPECIES_DONPHAN,
    },
    {
        .iv = 8,
        .lvl = 58,
        .species = SPECIES_PIDGEOT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperJeff[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_SPEAROW,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_RATICATE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperJeffRematch[] = {
    {
        .iv = 2,
        .lvl = 25,
        .species = SPECIES_FEAROW,
    },
    {
        .iv = 2,
        .lvl = 25,
        .species = SPECIES_RATICATE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperJeffRematchAfterFuchsia[] = {
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_FEAROW,
    },
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_RATICATE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperJeffRematchAfterSapphire[] = {
    {
        .iv = 12,
        .lvl = 56,
        .species = SPECIES_FEAROW,
    },
    {
        .iv = 12,
        .lvl = 56,
        .species = SPECIES_RATICATE,
    },
};


// ======================================================================================= //
// ======================================= Route 11 ====================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterEddie[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_MARSHTOMP,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_GamerHugo[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_KRABBY,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_CORSOLA,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_EngineerBernie[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_MAGNEMITE,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_MAGNEMITE,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_PINECO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_EngineerBernieRematchAfterFuchsia[] = {
    {
        .iv = 6,
        .lvl = 37,
        .species = SPECIES_MAGNETON,
    },
    {
        .iv = 6,
        .lvl = 37,
        .species = SPECIES_MAGNETON,
    },
    {
        .iv = 6,
        .lvl = 37,
        .species = SPECIES_FORRETRESS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterDave[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_NIDORINO,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_NIDORINA,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterDillon[] = {
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_PLUSLE,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_MINUN,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_GamerJasper[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_GROWLITHE,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_VULPIX,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_EngineerBraxton[] = {
    {
        .iv = 0,
        .lvl = 21,
        .species = SPECIES_MAGNEMITE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_GamerDarian[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_BELLSPROUT,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_ODDISH,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_GamerDarianRematchAfterFuchsia[] = {
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_VICTREEBEL,
    },
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_BELLOSSOM,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterYasu[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_QUILAVA,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_CROCONAW,
    },
    {
        .iv = 0,
        .lvl = 20,
        .species = SPECIES_RATICATE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterYasuRematchAfterCeladon[] = {
    {
        .iv = 4,
        .lvl = 28,
        .species = SPECIES_QUILAVA
    },
    {
        .iv = 4,
        .lvl = 28,
        .species = SPECIES_CROCONAW,
    },
    {
        .iv = 4,
        .lvl = 29,
        .species = SPECIES_RATICATE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterYasuRematchAfterLeague[] = {
    {
        .iv = 8,
        .lvl = 57,
        .species = SPECIES_TYPHLOSION,
    },
    {
        .iv = 8,
        .lvl = 57,
        .species = SPECIES_FERALIGATR,
    },
    {
        .iv = 8,
        .lvl = 57,
        .species = SPECIES_RATICATE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_GamerDirk[] = {
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_VOLTORB,
    },
    {
        .iv = 0,
        .lvl = 19,
        .species = SPECIES_PIKACHU,
    },
};

// ======================================================================================= //
// ======================================= S.S. Anne ===================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_GentlemanHenderson[] = {
    {
        .iv = 3,
        .lvl = 19,
        .species = SPECIES_HOUNDOUR,
    },
    {
        .iv = 3,
        .lvl = 19,
        .species = SPECIES_GROWLITHE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_GentlemanArthur[] = {
    {
        .iv = 3,
        .lvl = 19,
        .species = SPECIES_BAGON,
    },
    {
        .iv = 3,
        .lvl = 19,
        .species = SPECIES_LILEEP,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassAnn[] = {
    {
        .iv = 3,
        .lvl = 19,
        .species = SPECIES_SWABLU,
    },
    {
        .iv = 3,
        .lvl = 19,
        .species = SPECIES_DELCATTY,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterTyler[] = {
    {
        .iv = 3,
        .lvl = 21,
        .species = SPECIES_CORPHISH,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_FishermanBarny[] = {
    {
        .iv = 3,
        .lvl = 18,
        .species = SPECIES_TENTACOOL,
    },
    {
        .iv = 3,
        .lvl = 18,
        .species = SPECIES_STARYU,
    },
    {
        .iv = 3,
        .lvl = 18,
        .species = SPECIES_SHELLDER,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SailorPhillip[] = {
    {
        .iv = 3,
        .lvl = 20,
        .species = SPECIES_MACHOP,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SailorHuey[] = {
    {
        .iv = 3,
        .lvl = 19,
        .species = SPECIES_PSYDUCK
    },
    {
        .iv = 3,
        .lvl = 19,
        .species = SPECIES_MANTINE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SailorDylan[] = {
    {
        .iv = 3,
        .lvl = 18,
        .species = SPECIES_LUVDISC,
    },
    {
        .iv = 3,
        .lvl = 18,
        .species = SPECIES_CHINCHOU,
    },
    {
        .iv = 3,
        .lvl = 18,
        .species = SPECIES_LOMBRE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SailorDuncan[] = {
    {
        .iv = 3,
        .lvl = 18,
        .species = SPECIES_HORSEA,
    },
    {
        .iv = 3,
        .lvl = 18,
        .species = SPECIES_SURSKIT,
    },
    {
        .iv = 3,
        .lvl = 18,
        .species = SPECIES_OMANYTE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SailorLeonard[] = {
    {
        .iv = 3,
        .lvl = 21,
        .species = SPECIES_VAPOREON,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SailorTrevor[] = {
    {
        .iv = 3,
        .lvl = 17,
        .species = SPECIES_WINGULL,
    },
    {
        .iv = 3,
        .lvl = 17,
        .species = SPECIES_CLAMPERL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SailorEdmond[] = {
    {
        .iv = 3,
        .lvl = 18,
        .species = SPECIES_SPHEAL,
    },
    {
        .iv = 3,
        .lvl = 18,
        .species = SPECIES_SHELLDER,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_FishermanDale[] = {
    {
        .iv = 3,
        .lvl = 18,
        .species = SPECIES_REMORAID,
    },
    {
        .iv = 3,
        .lvl = 18,
        .species = SPECIES_BARBOACH,
    },
    {
        .iv = 3,
        .lvl = 18,
        .species = SPECIES_GOLDEEN,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_GentlemanBrooks[] = {
    {
        .iv = 3,
        .lvl = 23,
        .species = SPECIES_PIKACHU,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassDawn[] = {
    {
        .iv = 3,
        .lvl = 18,
        .species = SPECIES_ROSELIA,
    },
    {
        .iv = 3,
        .lvl = 18,
        .species = SPECIES_FARFETCHD,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_GentlemanLamar[] = {
    {
        .iv = 3,
        .lvl = 19,
        .species = SPECIES_PONYTA,
    },
    {
        .iv = 3,
        .lvl = 19,
        .species = SPECIES_DODUO,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_RivalSsAnneSquirtle[] = {
    {
        .iv = 15,
        .lvl = 24,
        .species = SPECIES_PIDGEOTTO,
        .heldItem = ITEM_WHITE_HERB,
        .moves = {MOVE_WING_ATTACK, MOVE_QUICK_ATTACK, MOVE_SAND_ATTACK, MOVE_FAINT_ATTACK},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,    
    },
    {
        .iv = 15,
        .lvl = 26,
        .species = SPECIES_PIKACHU,
        .heldItem = ITEM_SHUCA_BERRY,
        .moves = {MOVE_THUNDERBOLT, MOVE_QUICK_ATTACK, MOVE_THUNDER_WAVE, MOVE_SURF},
        .nature = NATURE_BOLD,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 24,
        .species = SPECIES_RATICATE,
        .heldItem = ITEM_ORAN_BERRY,
        .moves = {MOVE_HYPER_FANG, MOVE_QUICK_ATTACK, MOVE_BITE, MOVE_BRICK_BREAK},
        .nature = NATURE_ADAMANT,
        .abilitySlot = 1,    
    },
    {
        .iv = 15,
        .lvl = 25,
        .species = SPECIES_KADABRA,
        .heldItem = ITEM_TWISTED_SPOON,
        .moves = {MOVE_CONFUSION, MOVE_HIDDEN_POWER, MOVE_SNATCH, MOVE_REFLECT},
        .nature = NATURE_MODEST,
        .abilitySlot = 0,    
    },
    {
        .iv = 15,
        .lvl = 27,
        .species = SPECIES_WARTORTLE,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_WATER_PULSE, MOVE_AURORA_BEAM, MOVE_BITE, MOVE_WITHDRAW},
        .nature = NATURE_HARDY,
        .abilitySlot = 1,    
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_RivalSsAnneBulbasaur[] = {
    {
        .iv = 15,
        .lvl = 24,
        .species = SPECIES_PIDGEOTTO,
        .heldItem = ITEM_WHITE_HERB,
        .moves = {MOVE_WING_ATTACK, MOVE_QUICK_ATTACK, MOVE_SAND_ATTACK, MOVE_FAINT_ATTACK},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,    
    },
    {
        .iv = 15,
        .lvl = 26,
        .species = SPECIES_PIKACHU,
        .heldItem = ITEM_SHUCA_BERRY,
        .moves = {MOVE_THUNDERBOLT, MOVE_QUICK_ATTACK, MOVE_THUNDER_WAVE, MOVE_SURF},
        .nature = NATURE_BOLD,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 24,
        .species = SPECIES_RATICATE,
        .heldItem = ITEM_ORAN_BERRY,
        .moves = {MOVE_HYPER_FANG, MOVE_QUICK_ATTACK, MOVE_BITE, MOVE_BRICK_BREAK},
        .nature = NATURE_ADAMANT,
        .abilitySlot = 1,     
    },
    {
        .iv = 15,
        .lvl = 25,
        .species = SPECIES_KADABRA,
        .heldItem = ITEM_TWISTED_SPOON,
        .moves = {MOVE_CONFUSION, MOVE_HIDDEN_POWER, MOVE_SNATCH, MOVE_REFLECT},
        .nature = NATURE_MODEST,
        .abilitySlot = 0,    
    },
    {
        .iv = 15,
        .lvl = 27,
        .species = SPECIES_IVYSAUR,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_MAGICAL_LEAF, MOVE_LEECH_SEED, MOVE_SLUDGE, MOVE_SLEEP_POWDER},
        .nature = NATURE_HARDY,
        .abilitySlot = 1,    
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_RivalSsAnneCharmander[] = {
    {
        .iv = 15,
        .lvl = 24,
        .species = SPECIES_PIDGEOTTO,
        .heldItem = ITEM_WHITE_HERB,
        .moves = {MOVE_WING_ATTACK, MOVE_QUICK_ATTACK, MOVE_SAND_ATTACK, MOVE_FAINT_ATTACK},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 26,
        .species = SPECIES_PIKACHU,
        .heldItem = ITEM_SHUCA_BERRY,
        .moves = {MOVE_THUNDERBOLT, MOVE_QUICK_ATTACK, MOVE_THUNDER_WAVE, MOVE_SURF},
        .nature = NATURE_BOLD,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 24,
        .species = SPECIES_RATICATE,
        .heldItem = ITEM_ORAN_BERRY,
        .moves = {MOVE_HYPER_FANG, MOVE_QUICK_ATTACK, MOVE_BITE, MOVE_BRICK_BREAK},
        .nature = NATURE_ADAMANT,
        .abilitySlot = 1,      
    },
    {
        .iv = 15,
        .lvl = 25,
        .species = SPECIES_KADABRA,
        .heldItem = ITEM_TWISTED_SPOON,
        .moves = {MOVE_CONFUSION, MOVE_HIDDEN_POWER, MOVE_SNATCH, MOVE_REFLECT},
        .nature = NATURE_MODEST,
        .abilitySlot = 0,    
    },
    {
        .iv = 15,
        .lvl = 27,
        .species = SPECIES_CHARMELEON,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_FLAME_WHEEL, MOVE_SCARY_FACE, MOVE_METAL_CLAW, MOVE_DRAGON_RAGE},
        .nature = NATURE_HARDY,
        .abilitySlot = 1,    
    },
};


// ============================================================================================= //
// ==================================== Vermillion City Gym ==================================== //
// ============================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_SailorDwayne[] = {
    {
        .iv = 3,
        .lvl = 24,
        .species = SPECIES_ELECTRIKE,
    },
    {
        .iv = 3,
        .lvl = 24,
        .species = SPECIES_ELEKID,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_EngineerBaily[] = {
    {
        .iv = 3,
        .lvl = 24,
        .species = SPECIES_VOLTORB,
    },
    {
        .iv = 3,
        .lvl = 24,
        .species = SPECIES_MAGNEMITE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_GentlemanTucker[] = {
    {
        .iv = 3,
        .lvl = 27,
        .species = SPECIES_JOLTEON,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_LeaderLtSurge[] = {
    {
        .iv = 9,
        .lvl = 24,
        .species = SPECIES_VOLTORB,
        .heldItem = ITEM_TM24,
        .moves = {MOVE_SONIC_BOOM, MOVE_TACKLE, MOVE_SCREECH, MOVE_SHOCK_WAVE},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 9,
        .lvl = 24,
        .species = SPECIES_PIKACHU,
        .heldItem = ITEM_LIGHT_BALL,
        .moves = {MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER, MOVE_QUICK_ATTACK, MOVE_SURF},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,
    },
    {
        .iv = 9,
        .lvl = 26,
        .species = SPECIES_RAICHU,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_QUICK_ATTACK, MOVE_THUNDER_WAVE, MOVE_DOUBLE_TEAM, MOVE_SHOCK_WAVE},
        .nature = NATURE_LONELY,
        .abilitySlot = 0,
    },
    {
        .iv = 9,
        .lvl = 26,
        .species = SPECIES_MANECTRIC,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SHOCK_WAVE, MOVE_FLAMETHROWER, MOVE_BITE, MOVE_ROAR},
        .nature = NATURE_MILD,
        .abilitySlot = 0,
    },
    {
        .iv = 9,
        .lvl = 30,
        .species = SPECIES_MAGNETON,
        .heldItem = ITEM_MAGNET,
        .moves = {MOVE_TRI_ATTACK, MOVE_THUNDER_WAVE, MOVE_METAL_SOUND, MOVE_SHOCK_WAVE},
        .nature = NATURE_GENTLE,
        .abilitySlot = 0,    
    },
};


// ======================================================================================= //
// ======================================= Route 9 ======================================= //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerAlicia[] = {
    {
        .iv = 3,
        .lvl = 21,
        .species = SPECIES_MEOWTH,
    },
    {
        .iv = 3,
        .lvl = 21,
        .species = SPECIES_BELLSPROUT,
    },
    {
        .iv = 3,
        .lvl = 21,
        .species = SPECIES_ODDISH,
    },
    {
        .iv = 3,
        .lvl = 21,
        .species = SPECIES_NUMEL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerAliciaRematchAfterCeladon[] = {
    {
        .iv = 4,
        .lvl = 30,
        .species = SPECIES_MEOWTH,
    },
    {
        .iv = 4,
        .lvl = 30,
        .species = SPECIES_WEEPINBELL,
    },
    {
        .iv = 4,
        .lvl = 30,
        .species = SPECIES_GLOOM,
    },
    {
        .iv = 4,
        .lvl = 30,
        .species = SPECIES_CAMERUPT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerAliciaRematchAfterFuchsia[] = {
    {
        .iv = 6,
        .lvl = 36,
        .species = SPECIES_PERSIAN,
    },
    {
        .iv = 6,
        .lvl = 36,
        .species = SPECIES_VICTREEBEL,
    },
    {
        .iv = 6,
        .lvl = 36,
        .species = SPECIES_VILEPLUME,
    },
    {
        .iv = 6,
        .lvl = 36,
        .species = SPECIES_CAMERUPT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerAliciaRematchAfterSapphire[] = {
    {
        .iv = 12,
        .lvl = 61,
        .species = SPECIES_PERSIAN,
    },
    {
        .iv = 12,
        .lvl = 61,
        .species = SPECIES_VICTREEBEL,
    },
    {
        .iv = 12,
        .lvl = 61,
        .species = SPECIES_VILEPLUME,
    },
    {
        .iv = 12,
        .lvl = 61,
        .species = SPECIES_CAMERUPT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_HikerJeremy[] = {
    {
        .iv = 3,
        .lvl = 24,
        .species = SPECIES_MACHOP,
    },
    {
        .iv = 3,
        .lvl = 24,
        .species = SPECIES_ONIX,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_HikerJeremyRematchAfterFuchsia[] = {
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_MACHOKE,
    },
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_ONIX,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperChris[] = {
    {
        .iv = 3,
        .lvl = 23,
        .species = SPECIES_GROWLITHE,
    },
    {
        .iv = 3,
        .lvl = 24,
        .species = SPECIES_CHARMELEON,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperChrisRematchAfterCeladon[] = {
    {
        .iv = 4,
        .lvl = 31,
        .species = SPECIES_GROWLITHE,
    },
    {
        .iv = 4,
        .lvl = 32,
        .species = SPECIES_CHARMELEON,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperChrisRematchAfterFuchsia[] = {
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_ARCANINE,
    },
    {
        .iv = 6,
        .lvl = 40,
        .species = SPECIES_CHARIZARD,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperChrisRematchAfterSapphire[] = {
    {
        .iv = 12,
        .lvl = 63,
        .species = SPECIES_ARCANINE,
    },
    {
        .iv = 12,
        .lvl = 64,
        .species = SPECIES_CHARIZARD,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherBrent[] = {
    {
        .iv = 3,
        .lvl = 23,
        .species = SPECIES_BEEDRILL,
    },
    {
        .iv = 3,
        .lvl = 23,
        .species = SPECIES_PINSIR,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_HikerAlan[] = {
    {
        .iv = 3,
        .lvl = 24,
        .species = SPECIES_TRAPINCH,
        .moves = {MOVE_BITE, MOVE_SAND_ATTACK, MOVE_MUD_SLAP, MOVE_SAND_TOMB},
    },
    {
        .iv = 3,
        .lvl = 24,
        .species = SPECIES_SUDOWOODO,
        .moves = {MOVE_MIMIC, MOVE_ROCK_THROW, MOVE_FLAIL, MOVE_LOW_KICK},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherConner[] = {
    {
        .iv = 3,
        .lvl = 24,
        .species = SPECIES_VENONAT,
    },
    {
        .iv = 3,
        .lvl = 24,
        .species = SPECIES_ARIADOS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperDrew[] = {
    {
        .iv = 3,
        .lvl = 23,
        .species = SPECIES_EXEGGCUTE,
    },
    {
        .iv = 3,
        .lvl = 22,
        .species = SPECIES_EEVEE,
    },
    {
        .iv = 3,
        .lvl = 22,
        .species = SPECIES_VIGOROTH,
    },
    {
        .iv = 3,
        .lvl = 23,
        .species = SPECIES_LOUDRED,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_HikerBrice[] = {
    {
        .iv = 3,
        .lvl = 22,
        .species = SPECIES_RHYHORN,
    },
    {
        .iv = 3,
        .lvl = 22,
        .species = SPECIES_GLIGAR,
    },
    {
        .iv = 3,
        .lvl = 22,
        .species = SPECIES_NOCTOWL
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerCaitlin[] = {
    {
        .iv = 3,
        .lvl = 28,
        .species = SPECIES_ZANGOOSE,
    },
};


// ======================================================================================= //
// ==================================== Route 10 North =================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerHeidi[] = {
    {
        .iv = 3,
        .lvl = 25,
        .species = SPECIES_PIKACHU,
    },
    {
        .iv = 3,
        .lvl = 25,
        .species = SPECIES_CLEFAIRY,
    },
};

// ======================================================================================= //
// ===================================== Rock Tunnel ===================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_PokemaniacAbe[] = {
    {
        .iv = 3,
        .lvl = 30,
        .species = SPECIES_DONPHAN,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PokemaniacWinston[] = {
    {
        .iv = 3,
        .lvl = 30,
        .species = SPECIES_CHANSEY,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerMartha[] = {
    {
        .iv = 3,
        .lvl = 26,
        .species = SPECIES_TOGETIC,
    },
    {
        .iv = 3,
        .lvl = 26,
        .species = SPECIES_IVYSAUR,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PokemaniacSteve[] = {
    {
        .iv = 3,
        .lvl = 26,
        .species = SPECIES_CHARMELEON,
    },
    {
        .iv = 3,
        .lvl = 27,
        .species = SPECIES_LARVITAR,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_HikerAllen[] = {
    {
        .iv = 3,
        .lvl = 32,
        .species = SPECIES_LAIRON,
        .moves = {MOVE_MAGNITUDE, MOVE_ROCK_THROW, MOVE_METAL_CLAW, MOVE_HARDEN},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_HikerEric[] = {
    {
        .iv = 3,
        .lvl = 26,
        .species = SPECIES_MACHOP,
    },
    {
        .iv = 3,
        .lvl = 27,
        .species = SPECIES_ONIX,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_HikerLenny[] = {
    {
        .iv = 3,
        .lvl = 24,
        .species = SPECIES_BALTOY,
    },
    {
        .iv = 3,
        .lvl = 24,
        .species = SPECIES_BELDUM,
    },
    {
        .iv = 3,
        .lvl = 24,
        .species = SPECIES_SUDOWOODO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_HikerOliver[] = {
    {
        .iv = 3,
        .lvl = 24,
        .species = SPECIES_MAKUHITA,
    },
    {
        .iv = 3,
        .lvl = 25,
        .species = SPECIES_ONIX,
    },
    {
        .iv = 3,
        .lvl = 25,
        .species = SPECIES_HITMONLEE,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_HikerLucas[] = {
    {
        .iv = 3,
        .lvl = 29,
        .species = SPECIES_DUGTRIO,
        .moves = {MOVE_MAGNITUDE, MOVE_DIG, MOVE_FURY_SWIPES, MOVE_TRI_ATTACK},
    },
    {
        .iv = 3,
        .lvl = 29,
        .species = SPECIES_GRAVELER,
        .moves = {MOVE_MAGNITUDE, MOVE_ROCK_THROW, MOVE_MUD_SPORT, MOVE_DEFENSE_CURL},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PicnickerSofia[] = {
    {
        .iv = 3,
        .lvl = 29,
        .species = SPECIES_CLEFAIRY,
        .moves = {MOVE_ENCORE, MOVE_MIMIC, MOVE_DOUBLE_SLAP, MOVE_METRONOME},
    },
    {
        .iv = 3,
        .lvl = 29,
        .species = SPECIES_MILTANK,
        .moves = {MOVE_STOMP, MOVE_ATTRACT, MOVE_MILK_DRINK, MOVE_ROLLOUT},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_HikerDudley[] = {
    {
        .iv = 3,
        .lvl = 25,
        .species = SPECIES_GRAVELER,
        .moves = {MOVE_MAGNITUDE, MOVE_ROCK_THROW, MOVE_MUD_SPORT, MOVE_DEFENSE_CURL},
    },
    {
        .iv = 3,
        .lvl = 25,
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_MUD_SHOT, MOVE_TAIL_WHIP, MOVE_SLAM},
    },
    {
        .iv = 3,
        .lvl = 25,
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_BITE, MOVE_CHARM, MOVE_SCARY_FACE, MOVE_TAKE_DOWN},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PokemaniacCooper[] = {
    {
        .iv = 3,
        .lvl = 24,
        .species = SPECIES_SLOWPOKE,
    },
    {
        .iv = 3,
        .lvl = 24,
        .species = SPECIES_KIRLIA,
    },
    {
        .iv = 3,
        .lvl = 24,
        .species = SPECIES_GRIMER,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerLeah[] = {
    {
        .iv = 3,
        .lvl = 28,
        .species = SPECIES_COMBUSKEN,
    },
    {
        .iv = 3,
        .lvl = 28,
        .species = SPECIES_SWELLOW,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerAriana[] = {
    {
        .iv = 3,
        .lvl = 26,
        .species = SPECIES_TEDDIURSA,
    },
    {
        .iv = 3,
        .lvl = 25,
        .species = SPECIES_GIRAFARIG,
    },
    {
        .iv = 3,
        .lvl = 26,
        .species = SPECIES_BAYLEEF,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerDana[] = {
    {
        .iv = 3,
        .lvl = 26,
        .species = SPECIES_DRATINI,
    },
    {
        .iv = 3,
        .lvl = 26,
        .species = SPECIES_GLOOM,
    },
    {
        .iv = 3,
        .lvl = 26,
        .species = SPECIES_DODUO,
    },
};


// ======================================================================================= //
// ==================================== Route 10 South =================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerCarol[] = {
    {
        .iv = 3,
        .lvl = 27,
        .species = SPECIES_KADABRA,
    },
    {
        .iv = 3,
        .lvl = 26,
        .species = SPECIES_WOBBUFFET,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_HikerClark[] = {
    {
        .iv = 3,
        .lvl = 25,
        .species = SPECIES_GRAVELER,
        .moves = {MOVE_MAGNITUDE, MOVE_ROCK_THROW, MOVE_MUD_SPORT, MOVE_DEFENSE_CURL},
    },
    {
        .iv = 3,
        .lvl = 25,
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_CONSTRICT, MOVE_SAFEGUARD, MOVE_ENCORE, MOVE_WITHDRAW},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_HikerTrent[] = {
    {
        .iv = 3,
        .lvl = 26,
        .species = SPECIES_LUNATONE,
    },
    {
        .iv = 3,
        .lvl = 26,
        .species = SPECIES_SOLROCK,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_HikerTrentRematchAfterFuchsia[] = {
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_ONIX,
    },
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_GRAVELER,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PokemaniacHerman[] = {
    {
        .iv = 3,
        .lvl = 25,
        .species = SPECIES_SNEASEL,
    },
    {
        .iv = 3,
        .lvl = 26,
        .species = SPECIES_MASQUERAIN,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PokemaniacHermanRematchAfterFuchsia[] = {
    {
        .iv = 9,
        .lvl = 39,
        .species = SPECIES_SNEASEL,
    },
    {
        .iv = 9,
        .lvl = 39,
        .species = SPECIES_MASQUERAIN,
    },
};


// ======================================================================================= //
// ======================================= Route 8 ======================================= //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_LassJulia[] = {
    {
        .iv = 5,
        .lvl = 28,
        .species = SPECIES_SMOOCHUM,
    },
    {
        .iv = 5,
        .lvl = 28,
        .species = SPECIES_SUNFLORA,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_GamerRich[] = {
    {
        .iv = 5,
        .lvl = 28,
        .species = SPECIES_GROWLITHE,
    },
    {
        .iv = 5,
        .lvl = 28,
        .species = SPECIES_VULPIX,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_GamerRichRematchAfterFuchsia[] = {
    {
        .iv = 12,
        .lvl = 39,
        .species = SPECIES_ARCANINE,
    },
    {
        .iv = 12,
        .lvl = 39,
        .species = SPECIES_NINETALES,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SuperNerdGlenn[] = {
    {
        .iv = 5,
        .lvl = 27,
        .species = SPECIES_GRIMER,
    },
    {
        .iv = 5,
        .lvl = 27,
        .species = SPECIES_SEVIPER,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SuperNerdGlennRematchAfterFuchsia[] = {
    {
        .iv = 12,
        .lvl = 37,
        .species = SPECIES_MUK,
    },
    {
        .iv = 12,
        .lvl = 37,
        .species = SPECIES_SEVIPER,
    },
    {
        .iv = 12,
        .lvl = 37,
        .species = SPECIES_URSARING,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_TwinsEliAnne[] = {
    {
        .iv = 5,
        .lvl = 28,
        .species = SPECIES_CHIMECHO,
        .heldItem = ITEM_TWISTED_SPOON,
        .moves = {MOVE_CONFUSION, MOVE_ASTONISH, MOVE_YAWN, MOVE_REFLECT},
        .nature = NATURE_MODEST,
        .abilitySlot = 0,
    },
    {
        .iv = 5,
        .lvl = 28,
        .species = SPECIES_TROPIUS,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_RAZOR_LEAF, MOVE_WHIRLWIND, MOVE_GROWTH, MOVE_STOMP},
        .nature = NATURE_SERIOUS,
        .abilitySlot = 1,
    },
    {
        .iv = 5,
        .lvl = 28,
        .species = SPECIES_OCTILLERY,
        .heldItem = ITEM_LOADED_DICE,
        .moves = {MOVE_OCTAZOOKA, MOVE_BULLET_SEED, MOVE_AURORA_BEAM, MOVE_ROCK_BLAST},
        .nature = NATURE_TIMID,
        .abilitySlot = 0,
    },
    {
        .iv = 5,
        .lvl = 28,
        .species = SPECIES_NINJASK,
        .heldItem = ITEM_SILVER_POWDER,
        .moves = {MOVE_LEECH_LIFE, MOVE_AERIAL_ACE, MOVE_SLASH, MOVE_SWORDS_DANCE},
        .nature = NATURE_IMPISH,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_TwinsEliAnneRematchAfterFuchsia[] = {
    {
        .iv = 12,
        .lvl = 37,
        .species = SPECIES_CHIMECHO,
        .heldItem = ITEM_TWISTED_SPOON,
        .moves = {MOVE_CONFUSION, MOVE_ASTONISH, MOVE_YAWN, MOVE_REFLECT},
        .nature = NATURE_MODEST,
        .abilitySlot = 0,
    },
    {
        .iv = 12,
        .lvl = 37,
        .species = SPECIES_TROPIUS,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_RAZOR_LEAF, MOVE_WHIRLWIND, MOVE_GROWTH, MOVE_STOMP},
        .nature = NATURE_SERIOUS,
        .abilitySlot = 1,
    },
    {
        .iv = 12,
        .lvl = 37,
        .species = SPECIES_OCTILLERY,
        .heldItem = ITEM_LOADED_DICE,
        .moves = {MOVE_OCTAZOOKA, MOVE_BULLET_SEED, MOVE_AURORA_BEAM, MOVE_ROCK_BLAST},
        .nature = NATURE_TIMID,
        .abilitySlot = 0,
    },
    {
        .iv = 12,
        .lvl = 37,
        .species = SPECIES_NINJASK,
        .heldItem = ITEM_SILVER_POWDER,
        .moves = {MOVE_LEECH_LIFE, MOVE_AERIAL_ACE, MOVE_SLASH, MOVE_SWORDS_DANCE},
        .nature = NATURE_IMPISH,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassPaige[] = {
    {
        .iv = 5,
        .lvl = 28,
        .species = SPECIES_NIDORINA,
    },    
    {
        .iv = 5,
        .lvl = 28,
        .species = SPECIES_MIGHTYENA,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_SuperNerdLeslie[] = {
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_WEEZING,
        .moves = {MOVE_SLUDGE, MOVE_SMOKESCREEN, MOVE_SMOG, MOVE_SELF_DESTRUCT},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassAndrea[] = {
    {
        .iv = 5,
        .lvl = 27,
        .species = SPECIES_MEOWTH,
    },    
    {
        .iv = 5,
        .lvl = 27,
        .species = SPECIES_BAYLEEF,
    },
    {
        .iv = 5,
        .lvl = 28,
        .species = SPECIES_WEEPINBELL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassMegan[] = {
    {
        .iv = 5,
        .lvl = 26,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .iv = 5,
        .lvl = 26,
        .species = SPECIES_MARILL,
    },
    {
        .iv = 5,
        .lvl = 26,
        .species = SPECIES_SNUBBULL,
    },
    {
        .iv = 5,
        .lvl = 26,
        .species = SPECIES_SPOINK,
    },
    {
        .iv = 5,
        .lvl = 26,
        .species = SPECIES_KECLEON,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassMeganRematchAfterCeladon[] = {
    {
        .iv = 8,
        .lvl = 31,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .iv = 8,
        .lvl = 31,
        .species = SPECIES_MARILL,
    },
    {
        .iv = 8,
        .lvl = 31,
        .species = SPECIES_GRANBULL,
    },
    {
        .iv = 8,
        .lvl = 31,
        .species = SPECIES_SPOINK,
    },
    {
        .iv = 8,
        .lvl = 32,
        .species = SPECIES_KECLEON,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassMeganRematchAfterLeague[] = {
    {
        .iv = 28,
        .lvl = 48,
        .species = SPECIES_PIDGEOT,
    },
    {
        .iv = 28,
        .lvl = 48,
        .species = SPECIES_AZUMARILL,
    },
    {
        .iv = 28,
        .lvl = 47,
        .species = SPECIES_GRANBULL,
    },
    {
        .iv = 28,
        .lvl = 47,
        .species = SPECIES_GRUMPIG,
    },
    {
        .iv = 28,
        .lvl = 50,
        .species = SPECIES_KECLEON,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BikerJaren[] = {
    {
        .iv = 5,
        .lvl = 29,
        .species = SPECIES_GRIMER,
    },
    {
        .iv = 5,
        .lvl = 29,
        .species = SPECIES_LUNATONE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BikerJarenRematchAfterFuchsia[] = {
    {
        .iv = 12,
        .lvl = 39,
        .species = SPECIES_MUK,
    },
    {
        .iv = 12,
        .lvl = 39,
        .species = SPECIES_LUNATONE,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_BikerRicardo[] = {
    {
        .iv = 5,
        .lvl = 27,
        .species = SPECIES_KOFFING,
        .moves = {MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE, MOVE_POISON_GAS},
    },
    {
        .iv = 5,
        .lvl = 28,
        .species = SPECIES_CARVANHA,
        .moves = {MOVE_CRUNCH, MOVE_WATERFALL, MOVE_RAGE, MOVE_FOCUS_ENERGY},
    },
    {
        .iv = 5,
        .lvl = 28,
        .species = SPECIES_SWALOT,
        .moves = {MOVE_POUND, MOVE_SLUDGE, MOVE_YAWN, MOVE_ENCORE},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_GamerStan[] = {
    {
        .iv = 5,
        .lvl = 27,
        .species = SPECIES_CHINCHOU,
    },
    {
        .iv = 5,
        .lvl = 28,
        .species = SPECIES_WAILMER,
    },
    {
        .iv = 5,
        .lvl = 28,
        .species = SPECIES_POLIWHIRL,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SuperNerdAidan[] = {
    {
        .iv = 5,
        .lvl = 31,
        .species = SPECIES_GRAVELER,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MAGNITUDE, MOVE_DEFENSE_CURL, MOVE_NONE, MOVE_NONE},
    },
    {
        .iv = 5,
        .lvl = 31,
        .species = SPECIES_GOLBAT,
        .heldItem = ITEM_BLACK_GLASSES,
        .moves = {MOVE_WING_ATTACK, MOVE_BITE, MOVE_TAUNT, MOVE_SUPERSONIC},
    },
    {
        .iv = 5,
        .lvl = 32,
        .species = SPECIES_MAGNETON,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SPARK, MOVE_CHARGE, MOVE_SONIC_BOOM, MOVE_SUPERSONIC},
    },

    {
        .iv = 5,
        .lvl = 32,
        .species = SPECIES_METANG,
        .heldItem = ITEM_ORAN_BERRY,
        .moves = {MOVE_CONFUSION, MOVE_METAL_CLAW, MOVE_TAKE_DOWN, MOVE_ROCK_SMASH},
    },
};


// ======================================================================================= //
// =================================== Route 12 North ==================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_FishermanNed[] = {
    {
        .iv = 5,
        .lvl = 27,
        .species = SPECIES_GOLDEEN,
    },
    {
        .iv = 5,
        .lvl = 27,
        .species = SPECIES_POLIWHIRL,
    },
    {
        .iv = 5,
        .lvl = 27,
        .species = SPECIES_WAILMER,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_FishermanLuc[] = {
    {
        .iv = 5,
        .lvl = 30,
        .species = SPECIES_GYARADOS,
        .heldItem = ITEM_NONE,
    },
    {
        .iv = 5,
        .lvl = 30,
        .species = SPECIES_WHISCASH,
        .heldItem = ITEM_CHESTO_BERRY,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_FishermanLucRematch[] = {
    {
        .iv = 15,
        .lvl = 38,
        .species = SPECIES_GYARADOS,
    },
    {
        .iv = 15,
        .lvl = 38,
        .species = SPECIES_WHISCASH,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_FishermanHank[] = {
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_SEAKING,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_FishermanElliot[] = {
    {
        .iv = 5,
        .lvl = 26,
        .species = SPECIES_TENTACOOL,
    },
    {
        .iv = 5,
        .lvl = 26,
        .species = SPECIES_SHELLDER,
    },
    {
        .iv = 5,
        .lvl = 26,
        .species = SPECIES_SPHEAL,
    },
    {
        .iv = 5,
        .lvl = 26,
        .species = SPECIES_MARSHTOMP,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_FishermanElliotRematchAfterFuchsia[] = {
    {
        .iv = 16,
        .lvl = 36,
        .species = SPECIES_TENTACRUEL,
    },
    {
        .iv = 16,
        .lvl = 36,
        .species = SPECIES_CLOYSTER,
    },
    {
        .iv = 16,
        .lvl = 36,
        .species = SPECIES_SEALEO,
    },
    {
        .iv = 16,
        .lvl = 36,
        .species = SPECIES_SWAMPERT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungCoupleGiaJes[] = {
    {
        .iv = 5,
        .lvl = 30,
        .species = SPECIES_NIDORINO,
    },
    {
        .iv = 5,
        .lvl = 30,
        .species = SPECIES_NIDORINA,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungCoupleGiaJesRematchAfterFuchsia[] = {
    {
        .iv = 6,
        .lvl = 38,
        .species = SPECIES_NIDOQUEEN,
    },
    {
        .iv = 6,
        .lvl = 38,
        .species = SPECIES_NIDOKING,
    },
};


// ======================================================================================= //
// ==================================== Pokémon Tower ==================================== //
// ======================================================================================= //
static const struct TrainerMonItemCustomMovesNatureAbility sParty_RivalPokemonTowerSquirtle[] = {
    {
        .iv = 20,
        .lvl = 34,
        .species = SPECIES_PIDGEOTTO,
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_WING_ATTACK, MOVE_SAND_ATTACK, MOVE_QUICK_ATTACK, MOVE_FEATHER_DANCE},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 33,
        .species = SPECIES_HOUNDOOM,
        .heldItem = ITEM_BLACK_GLASSES,
        .moves = {MOVE_BITE, MOVE_FLAME_WHEEL, MOVE_WILL_O_WISP, MOVE_HOWL},
        .nature = NATURE_NAUGHTY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 34,
        .species = SPECIES_EXEGGUTOR,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_GIGA_DRAIN, MOVE_PSYBEAM, MOVE_STOMP, MOVE_HYPNOSIS},
        .nature = NATURE_DOCILE,
        .abilitySlot = 1,
    },
    {
        .iv = 20,
        .lvl = 33,
        .species = SPECIES_URSARING,
        .heldItem = ITEM_SILK_SCARF,
        .moves = {MOVE_FURY_SWIPES, MOVE_FAINT_ATTACK, MOVE_METAL_CLAW, MOVE_BULK_UP},
        .nature = NATURE_ADAMANT,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 35,
        .species = SPECIES_WARTORTLE,
        .heldItem = ITEM_MYSTIC_WATER,
        .moves = {MOVE_WATERFALL, MOVE_BITE, MOVE_ICE_BEAM, MOVE_WITHDRAW},
        .nature = NATURE_HARDY,
        .abilitySlot = 1,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_RivalPokemonTowerBulbasaur[] = {
    {
        .iv = 20,
        .lvl = 34,
        .species = SPECIES_PIDGEOTTO,
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_WING_ATTACK, MOVE_SAND_ATTACK, MOVE_QUICK_ATTACK, MOVE_FEATHER_DANCE},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 33,
        .species = SPECIES_HOUNDOOM,
        .heldItem = ITEM_BLACK_GLASSES,
        .moves = {MOVE_BITE, MOVE_FLAME_WHEEL, MOVE_WILL_O_WISP, MOVE_HOWL},
        .nature = NATURE_NAUGHTY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 33,
        .species = SPECIES_TENTACRUEL,
        .heldItem = ITEM_POISON_BARB,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_SLUDGE, MOVE_AURORA_BEAM, MOVE_HAZE},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 33,
        .species = SPECIES_URSARING,
        .heldItem = ITEM_SILK_SCARF,
        .moves = {MOVE_FURY_SWIPES, MOVE_FAINT_ATTACK, MOVE_METAL_CLAW, MOVE_BULK_UP},
        .nature = NATURE_ADAMANT,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 35,
        .species = SPECIES_IVYSAUR,
        .heldItem = ITEM_MIRACLE_SEED,
        .moves = {MOVE_MAGICAL_LEAF, MOVE_SLUDGE, MOVE_LEECH_SEED, MOVE_SLEEP_POWDER},
        .nature = NATURE_HARDY,
        .abilitySlot = 1,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_RivalPokemonTowerCharmander[] = {
    {
        .iv = 20,
        .lvl = 34,
        .species = SPECIES_PIDGEOTTO,
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_WING_ATTACK, MOVE_SAND_ATTACK, MOVE_QUICK_ATTACK, MOVE_FEATHER_DANCE},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 34,
        .species = SPECIES_EXEGGUTOR,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_GIGA_DRAIN, MOVE_PSYBEAM, MOVE_STOMP, MOVE_HYPNOSIS},
        .nature = NATURE_DOCILE,
        .abilitySlot = 1,
    },
    {
        .iv = 20,
        .lvl = 33,
        .species = SPECIES_TENTACRUEL,
        .heldItem = ITEM_POISON_BARB,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_SLUDGE, MOVE_AURORA_BEAM, MOVE_HAZE},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 33,
        .species = SPECIES_URSARING,
        .heldItem = ITEM_SILK_SCARF,
        .moves = {MOVE_FURY_SWIPES, MOVE_FAINT_ATTACK, MOVE_METAL_CLAW, MOVE_BULK_UP},
        .nature = NATURE_ADAMANT,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 35,
        .species = SPECIES_CHARMELEON,
        .heldItem = ITEM_CHARCOAL,
        .moves = {MOVE_FLAMETHROWER, MOVE_METAL_CLAW, MOVE_DRAGON_CLAW, MOVE_SMOKESCREEN},
        .nature = NATURE_HARDY,
        .abilitySlot = 1,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_ChannelerHope[] = {
    {
        .iv = 5,
        .lvl = 34,
        .species = SPECIES_HAUNTER,
        .heldItem = ITEM_SPELL_TAG,
        .moves = {MOVE_SHADOW_PUNCH, MOVE_GIGA_DRAIN, MOVE_HYPNOSIS, MOVE_DREAM_EATER},
        .nature = NATURE_BOLD,
        .abilitySlot = 0,
    },
    {
        .iv = 5,
        .lvl = 35,
        .species = SPECIES_MURKROW,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_FAINT_ATTACK, MOVE_AERIAL_ACE, MOVE_NIGHT_SHADE, MOVE_PURSUIT},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_ChannelerLaurel[] = {
    {
        .iv = 5,
        .lvl = 32,
        .species = SPECIES_XATU,
        .heldItem = ITEM_FOCUS_BAND,
        .moves = {MOVE_PSYCHIC, MOVE_DRILL_PECK, MOVE_FEATHER_DANCE, MOVE_HAZE},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 5,
        .lvl = 34,
        .species = SPECIES_SNEASEL,
        .heldItem = ITEM_LOADED_DICE,
        .moves = {MOVE_FAINT_ATTACK, MOVE_ICICLE_SPEAR, MOVE_FAKE_OUT, MOVE_SWORDS_DANCE},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_ChannelerJody[] = {
    {
        .iv = 5,
        .lvl = 34,
        .species = SPECIES_GOLDUCK,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WATER_PULSE, MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_CALM_MIND},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_CHIMECHO,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_PSYWAVE, MOVE_ASTONISH, MOVE_YAWN, MOVE_REFLECT},
        .nature = NATURE_QUIRKY,
        .abilitySlot = 0,
    },
    {
        .iv = 5,
        .lvl = 34,
        .species = SPECIES_MISDREAVUS,
        .heldItem = ITEM_SPELL_TAG,
        .moves = {MOVE_SHADOW_BALL, MOVE_PSYBEAM, MOVE_CONFUSE_RAY, MOVE_DESTINY_BOND},
        .nature = NATURE_MODEST,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_ChannelerRuth[] = {
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_GIRAFARIG,
        .heldItem = ITEM_SILK_SCARF,
        .moves = {MOVE_STOMP, MOVE_AGILITY, MOVE_STRENGTH, MOVE_BEAT_UP},
        .nature = NATURE_ADAMANT,
        .abilitySlot = 0,
    },
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_HAUNTER,
        .heldItem = ITEM_SPELL_TAG,
        .moves = {MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_PSYCHIC, MOVE_SLUDGE_BOMB},
        .nature = NATURE_TIMID,
        .abilitySlot = 0,
    },
    {
        .iv = 5,
        .lvl = 34,
        .species = SPECIES_WOBBUFFET,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_MIRROR_COAT, MOVE_COUNTER, MOVE_SAFEGUARD, MOVE_ENCORE},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_ChannelerAngelica[] = {
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_DUSKULL,
        .heldItem = ITEM_WHITE_HERB,
        .moves = {MOVE_DESTINY_BOND, MOVE_NIGHT_SHADE, MOVE_WILL_O_WISP, MOVE_RETURN},
        .nature = NATURE_IMPISH,
        .abilitySlot = 0,
    },
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_CLAYDOL,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_EARTHQUAKE, MOVE_PSYWAVE, MOVE_ANCIENT_POWER, MOVE_ICE_BEAM},
        .nature = NATURE_LONELY,
        .abilitySlot = 0,
    },
    {
        .iv = 5,
        .lvl = 34,
        .species = SPECIES_SABLEYE,
        .heldItem = ITEM_LUM_BERRY,
        .moves = {MOVE_FAKE_OUT, MOVE_CONFUSE_RAY, MOVE_KNOCK_OFF, MOVE_ROCK_SMASH},
        .nature = NATURE_CAREFUL,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_ChannelerJennifer[] = {
    {
        .iv = 5,
        .lvl = 35,
        .species = SPECIES_UMBREON,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_CHARM, MOVE_PURSUIT, MOVE_FACADE, MOVE_WISH},
        .nature = NATURE_ADAMANT,
        .abilitySlot = 0,
    },
    {
        .iv = 5,
        .lvl = 35,
        .species = SPECIES_ESPEON,
        .heldItem = ITEM_TWISTED_SPOON,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_CALM_MIND, MOVE_QUICK_ATTACK},
        .nature = NATURE_MODEST,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_ChannelerEmilia[] = {
    {
        .iv = 5,
        .lvl = 35,
        .species = SPECIES_SHIFTRY,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_LEAF_BLADE, MOVE_THIEF, MOVE_QUICK_ATTACK, MOVE_GROWTH},
        .nature = NATURE_HARDY,
        .abilitySlot = 1,
    },
    {
        .iv = 5,
        .lvl = 36,
        .species = SPECIES_BANETTE,
        .heldItem = ITEM_SPELL_TAG,
        .moves = {MOVE_SHADOW_PUNCH, MOVE_KNOCK_OFF, MOVE_WILL_O_WISP, MOVE_FACADE},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt19[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_GOLBAT,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_HOUNDOOM,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_WHISCASH,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt20[] = {
    {
        .iv = 10,
        .lvl = 37,
        .species = SPECIES_ARIADOS,
    },
    {
        .iv = 10,
        .lvl = 37,
        .species = SPECIES_AMPHAROS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt21[] = {
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_GLALIE,
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_SHELGON
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_RATICATE,
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_MIGHTYENA,
    },
};


// ======================================================================================= //
// ==================================== Route 16 North =================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_YoungCoupleLeaJed[] = {
    {
        .iv = 15,
        .lvl = 37,
        .species = SPECIES_RAPIDASH,
    },
    {
        .iv = 15,
        .lvl = 37,
        .species = SPECIES_NINETALES,
    },
    {
        .iv = 15,
        .lvl = 37,
        .species = SPECIES_EXEGGUTOR,
    },
    {
        .iv = 15,
        .lvl = 37,
        .species = SPECIES_HYPNO,
    },
};


// ======================================================================================= //
// ===================================== Game Corner ===================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt7[] = {
    {
        .iv = 5,
        .lvl = 30,
        .species = SPECIES_RATICATE,
    },
    {
        .iv = 5,
        .lvl = 30,
        .species = SPECIES_GOLBAT,
    },
};

// ======================================================================================= //
// ==================================== Rocket Hideout =================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt8[] = {
    {
        .iv = 5,
        .lvl = 31,
        .species = SPECIES_MACHOKE,
    },
    {
        .iv = 5,
        .lvl = 31,
        .species = SPECIES_DODRIO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt9[] = {
    {
        .iv = 5,
        .lvl = 31,
        .species = SPECIES_MAROWAK,
    },
    {
        .iv = 5,
        .lvl = 31,
        .species = SPECIES_TENTACRUEL,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_TeamRocketGrunt10[] = {
    {
        .iv = 5,
        .lvl = 30,
        .species = SPECIES_GRIMER,
        .moves = {MOVE_BODY_SLAM, MOVE_SLUDGE, MOVE_DISABLE, MOVE_HARDEN},
    },
    {
        .iv = 5,
        .lvl = 30,
        .species = SPECIES_KOFFING,
        .moves = {MOVE_SLUDGE, MOVE_HEADBUTT, MOVE_POISON_GAS, MOVE_WILL_O_WISP},
    },
    {
        .iv = 5,
        .lvl = 32,
        .species = SPECIES_GRUMPIG,
        .moves = {MOVE_PSYBEAM, MOVE_TACKLE, MOVE_POISON_GAS, MOVE_NONE},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_TeamRocketGrunt11[] = {
    {
        .iv = 5,
        .lvl = 32,
        .species = SPECIES_SOLROCK,
        .moves = {MOVE_ROCK_SLIDE, MOVE_SOLAR_BEAM, MOVE_SHADOW_BALL, MOVE_COSMIC_POWER},
    },
    {
        .iv = 5,
        .lvl = 32,
        .species = SPECIES_LUNATONE,
        .moves = {MOVE_ROCK_TOMB, MOVE_HIDDEN_POWER, MOVE_FUTURE_SIGHT, MOVE_COSMIC_POWER},
    },
    {
        .iv = 5,
        .lvl = 32,
        .species = SPECIES_SEVIPER,
        .moves = {MOVE_POISON_FANG, MOVE_SNATCH, MOVE_BITE, MOVE_GLARE},
    },
    {
        .iv = 5,
        .lvl = 32,
        .species = SPECIES_CRAWDAUNT,
        .moves = {MOVE_CRABHAMMER, MOVE_KNOCK_OFF, MOVE_ANCIENT_POWER, MOVE_BRICK_BREAK},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_TeamRocketGrunt12[] = {
    {
        .iv = 5,
        .lvl = 32,
        .species = SPECIES_ZANGOOSE,
        .moves = {MOVE_SLASH, MOVE_AERIAL_ACE, MOVE_BRICK_BREAK, MOVE_PURSUIT},
    },
    {
        .iv = 5,
        .lvl = 32,
        .species = SPECIES_CACTURNE,
        .moves = {MOVE_FAINT_ATTACK, MOVE_NEEDLE_ARM, MOVE_PIN_MISSILE, MOVE_DYNAMIC_PUNCH},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_TeamRocketGrunt13[] = {
    {
        .iv = 5,
        .lvl = 29,
        .species = SPECIES_GOLBAT,
        .moves = {MOVE_BITE, MOVE_ASTONISH, MOVE_SUPERSONIC, MOVE_LEECH_LIFE},
    },
    {
        .iv = 5,
        .lvl = 29,
        .species = SPECIES_CROCONAW,
        .moves = {MOVE_BITE, MOVE_WATER_PULSE, MOVE_DRAGON_CLAW, MOVE_COUNTER},
    },
    {
        .iv = 5,
        .lvl = 29,
        .species = SPECIES_KADABRA,
        .moves = {MOVE_PSYBEAM, MOVE_CALM_MIND, MOVE_HIDDEN_POWER, MOVE_SHOCK_WAVE},
    },
    {
        .iv = 5,
        .lvl = 29,
        .species = SPECIES_ELECTABUZZ,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_BRICK_BREAK},
    },
    {
        .iv = 5,
        .lvl = 29,
        .species = SPECIES_MAGMAR,
        .moves = {MOVE_FLAMETHROWER, MOVE_SMOKESCREEN, MOVE_SMOG, MOVE_PSYCHIC},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_TeamRocketGrunt14[] = {
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_NOCTOWL,
        .moves = {MOVE_CONFUSION, MOVE_HYPNOSIS, MOVE_REFLECT, MOVE_TAKE_DOWN},
    },
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_SHARPEDO,
        .moves = {MOVE_CRUNCH, MOVE_WATERFALL, MOVE_SLASH, MOVE_SCARY_FACE},
    },
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_PILOSWINE,
        .moves = {MOVE_BULLDOZE, MOVE_ICICLE_SPEAR, MOVE_TAKE_DOWN, MOVE_ROCK_SLIDE},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt15[] = {
    {
        .iv = 5,
        .lvl = 32,
        .species = SPECIES_DUGTRIO,
    },
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_QWILFISH,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt16[] = {
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_PINSIR,
    },
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_DONPHAN,
    },
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_URSARING,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt17[] = {
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_PRIMEAPE,
    },
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_SANDSLASH,
    },
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_ARBOK,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt18[] = {
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_PUPITAR,
    },
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_GOLDUCK,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BossGiovanniRocketHideout[] = {
    {
        .iv = 8,
        .lvl = 34,
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_THIEF, MOVE_ASSIST, MOVE_PAY_DAY, MOVE_FAKE_OUT},
        .heldItem = ITEM_NONE,
    },
    {
        .iv = 8,
        .lvl = 34,
        .species = SPECIES_ONIX,
        .moves = {MOVE_BULLDOZE, MOVE_ROCK_SLIDE, MOVE_DRAGON_BREATH, MOVE_SCREECH},
        .heldItem = ITEM_HARD_STONE,
    },
    {
        .iv = 8,
        .lvl = 35,
        .species = SPECIES_WEEZING,
        .moves = {MOVE_SLUDGE, MOVE_HAZE, MOVE_FLAMETHROWER, MOVE_SELF_DESTRUCT},
        .heldItem = ITEM_POISON_BARB,
    },
    {
        .iv = 8,
        .lvl = 36,
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_PSYBEAM, MOVE_ANCIENT_POWER, MOVE_SANDSTORM, MOVE_RAPID_SPIN},
        .heldItem = ITEM_LEFTOVERS,
    },
    {
        .iv = 8,
        .lvl = 36,
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_MEGA_PUNCH, MOVE_BITE, MOVE_ROCK_SMASH, MOVE_FAKE_OUT},
        .heldItem = ITEM_SITRUS_BERRY,
    },
};


// ============================================================================================= //
// ====================================== Celadon City Gym ===================================== //
// ============================================================================================= //
static const struct TrainerMonNoItemCustomMoves sParty_LassKay[] = {
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_SPORE, MOVE_GROWTH, MOVE_BATON_PASS, MOVE_DOUBLE_EDGE},
    },
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_WEEPINBELL,
        .moves = {MOVE_SLUDGE, MOVE_MEGA_DRAIN, MOVE_LEECH_LIFE, MOVE_SUNNY_DAY},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BeautyBridget[] = {
    {
        .iv = 5,
        .lvl = 31,
        .species = SPECIES_GLOOM,
    },
    {
        .iv = 5,
        .lvl = 31,
        .species = SPECIES_NUZLEAF,
    },
    {
        .iv = 5,
        .lvl = 31,
        .species = SPECIES_KIRLIA,
    },
    {
        .iv = 5,
        .lvl = 31,
        .species = SPECIES_KECLEON,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_CooltrainerMary[] = {
    {
        .iv = 10,
        .lvl = 32,
        .species = SPECIES_GROVYLE,
        .moves = {MOVE_LEAF_BLADE, MOVE_PURSUIT, MOVE_QUICK_ATTACK, MOVE_FURY_CUTTER},
    },
    {
        .iv = 10,
        .lvl = 32,
        .species = SPECIES_BELLOSSOM,
        .moves = {MOVE_MAGICAL_LEAF, MOVE_STUN_SPORE, MOVE_INGRAIN, MOVE_ACID},
    },
    {
        .iv = 10,
        .lvl = 32,
        .species = SPECIES_JUMPLUFF,
        .moves = {MOVE_AERIAL_ACE, MOVE_MEGA_DRAIN, MOVE_TOXIC, MOVE_LEECH_SEED},
    },
    {
        .iv = 10,
        .lvl = 32,
        .species = SPECIES_SUNFLORA,
        .moves = {MOVE_BULLET_SEED, MOVE_GROWTH, MOVE_REST, MOVE_INGRAIN},
    },
    {
        .iv = 10,
        .lvl = 32,
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_RAZOR_LEAF, MOVE_SYNTHESIS, MOVE_LIGHT_SCREEN, MOVE_ANCIENT_POWER},
    },
};


static const struct TrainerMonNoItemDefaultMoves sParty_LassLisa[] = {
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_SHIFTRY,
    },
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_BEAUTIFLY,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerTina[] = {
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_FARFETCHD,
    },
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_IVYSAUR,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BeautyLori[] = {
    {
        .iv = 5,
        .lvl = 34,
        .species = SPECIES_TROPIUS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BeautyTamia[] = {
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_POLITOED,
    },
    {
        .iv = 5,
        .lvl = 33,
        .species = SPECIES_CRADILY,
    },
};

static const struct TrainerMonItemCustomMoves sParty_LeaderErika[] = {
    {
        .iv = 12,
        .lvl = 35,
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_STUN_SPORE, MOVE_POISON_FANG, MOVE_GROWTH, MOVE_GIGA_DRAIN},
        .heldItem = ITEM_LEFTOVERS,
    },
    {
        .iv = 12,
        .lvl = 36,
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_SPORE, MOVE_SKY_UPPERCUT, MOVE_BULLET_SEED, MOVE_MACH_PUNCH},
        .heldItem = ITEM_FOCUS_SASH,
    },
    {
        .iv = 12,
        .lvl = 36,
        .species = SPECIES_SUDOWOODO,
        .moves = {MOVE_ROCK_SLIDE, MOVE_LOW_KICK, MOVE_BODY_SLAM, MOVE_EARTHQUAKE},
        .heldItem = ITEM_KINGS_ROCK,
    },
    {
        .iv = 12,
        .lvl = 36,
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_WATER_PULSE, MOVE_GIGA_DRAIN, MOVE_RAIN_DANCE, MOVE_ICE_BEAM},
        .heldItem = ITEM_MYSTIC_WATER,
    },
    {
        .iv = 12,
        .lvl = 39,
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_SLEEP_POWDER, MOVE_SLUDGE_BOMB, MOVE_STUN_SPORE, MOVE_GIGA_DRAIN},
        .heldItem = ITEM_MIRACLE_SEED,
    },
};


// ============================================================================================= //
// ===================================== Saffron City Dojo ===================================== //
// ============================================================================================= //
static const struct TrainerMonItemDefaultMoves sParty_BlackBeltYouri[] = {
    {
        .iv = 10,
        .lvl = 37,
        .species = SPECIES_MACHOKE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 10,
        .lvl = 37,
        .species = SPECIES_HARIYAMA,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_BlackBeltHitoshi[] = {
    {
        .iv = 10,
        .lvl = 36,
        .species = SPECIES_HERACROSS,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 10,
        .lvl = 36,
        .species = SPECIES_BLAZIKEN,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 10,
        .lvl = 36,
        .species = SPECIES_PRIMEAPE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_BlackBeltMike[] = {
    {
        .iv = 10,
        .lvl = 37,
        .species = SPECIES_MEDICHAM,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 10,
        .lvl = 37,
        .species = SPECIES_POLIWRATH,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_BlackBeltAaron[] = {
    {
        .iv = 10,
        .lvl = 39,
        .species = SPECIES_MACHAMP,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_BlackBeltKoichi[] = {
    {
        .iv = 10,
        .lvl = 40,
        .species = SPECIES_HITMONLEE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 10,
        .lvl = 40,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 10,
        .lvl = 40,
        .species = SPECIES_HITMONTOP,
        .heldItem = ITEM_BLACK_BELT,
    },
};


// ======================================================================================= //
// =================================== Route 12 South ==================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_RockerLuca[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_ELECTRODE,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_ELECTABUZZ,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_RockerLucaRematchAfterFuchsia[] = {
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_ELECTRODE,
    },
    {
        .iv = 6,
        .lvl = 39,
        .species = SPECIES_ELECTABUZZ,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperJustin[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_VIBRAVA,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_SEALEO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_FishermanAndrew[] = {
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_LANTURN,
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_SEADRA,
    },
};


// ======================================================================================= //
// ======================================= Route 13 ====================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerAlma[] = {
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_TANGELA,
    },
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_VENOMOTH,
    },
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_AZUMARILL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperSebastian[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_NOCTOWL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerSusie[] = {
    {
        .iv = 10,
        .lvl = 32,
        .species = SPECIES_HAUNTER,
    },
    {
        .iv = 10,
        .lvl = 32,
        .species = SPECIES_LAIRON,
    },
    {
        .iv = 10,
        .lvl = 32,
        .species = SPECIES_DRATINI,
    },
    {
        .iv = 10,
        .lvl = 32,
        .species = SPECIES_PIKACHU,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_PicnickerSusieRematchAfterFuchsia[] = {
    {
        .iv = 12,
        .lvl = 37,
        .species = SPECIES_HAUNTER,
        .heldItem = ITEM_NONE,
    },
    {
        .iv = 12,
        .lvl = 37,
        .species = SPECIES_LAIRON,
        .heldItem = ITEM_NONE,
    },
    {
        .iv = 12,
        .lvl = 37,
        .species = SPECIES_DRAGONAIR,
        .heldItem = ITEM_NONE,
    },
    {
        .iv = 12,
        .lvl = 37,
        .species = SPECIES_PIKACHU,
        .heldItem = ITEM_LIGHT_BALL,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerSusieRematchAfterLeague[] = {
    {
        .iv = 16,
        .lvl = 52,
        .species = SPECIES_GENGAR,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOW_PUNCH, MOVE_SLUDGE_BOMB, MOVE_WILL_O_WISP, MOVE_CURSE},
    },
    {
        .iv = 16,
        .lvl = 52,
        .species = SPECIES_AGGRON,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BULLDOZE, MOVE_IRON_TAIL, MOVE_HEADBUTT, MOVE_PROTECT},
    },
    {
        .iv = 16,
        .lvl = 52,
        .species = SPECIES_DRAGONAIR,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_THUNDER_WAVE, MOVE_SLAM, MOVE_DRAGON_BREATH, MOVE_AGILITY},
    },
    {
        .iv = 16,
        .lvl = 52,
        .species = SPECIES_RAICHU,
        .heldItem = ITEM_MAGNET,
        .moves = {MOVE_QUICK_ATTACK, MOVE_THUNDERBOLT, MOVE_ENCORE, MOVE_BRICK_BREAK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerSusieRematchAfterSapphire[] = {
    {
        .iv = 22,
        .lvl = 58,
        .species = SPECIES_GENGAR,
        .heldItem = ITEM_SPELL_TAG,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_BOMB, MOVE_WILL_O_WISP, MOVE_PSYCHIC},
    },
    {
        .iv = 22,
        .lvl = 58,
        .species = SPECIES_AGGRON,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_TAIL, MOVE_ROCK_SLIDE, MOVE_PROTECT},
    },
    {
        .iv = 22,
        .lvl = 58,
        .species = SPECIES_DRAGONITE,
        .heldItem = ITEM_SILK_SCARF,
        .moves = {MOVE_DRAGON_CLAW, MOVE_EXTREME_SPEED, MOVE_THUNDER_WAVE, MOVE_WING_ATTACK},
    },
    {
        .iv = 22,
        .lvl = 58,
        .species = SPECIES_RAICHU,
        .heldItem = ITEM_MAGNET,
        .moves = {MOVE_THUNDER, MOVE_THUNDERBOLT, MOVE_ENCORE, MOVE_BRICK_BREAK},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BeautyLola[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_ALTARIA,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_PIKACHU,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BeautySheila[] = {
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_CLEFABLE,
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_PERSIAN,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BeautySheilaRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 49,
        .species = SPECIES_CLEFABLE,
    },
    {
        .iv = 18,
        .lvl = 49,
        .species = SPECIES_PERSIAN,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerValerie[] = {
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_POLITOED,
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_CASTFORM,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerGwen[] = {
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_SANDSLASH,
    },
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_MR_MIME,
    },
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_MIGHTYENA,
    },
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_DELCATTY,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperRobert[] = {
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_SWELLOW,
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperRobertRematchAfterFuchsia[] = {
    {
        .iv = 16,
        .lvl = 38,
        .species = SPECIES_PIDGEOT,
    },
    {
        .iv = 16,
        .lvl = 38,
        .species = SPECIES_SWELLOW,
    },
    {
        .iv = 16,
        .lvl = 38,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperRobertRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 47,
        .species = SPECIES_PIDGEOT,
    },
    {
        .iv = 18,
        .lvl = 47,
        .species = SPECIES_SWELLOW,
    },
    {
        .iv = 18,
        .lvl = 47,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperPerry[] = {
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_TOGETIC,
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_XATU,
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_DODRIO,
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_MURKROW,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_BikerJared[] = {
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_KOFFING,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SHADOW_BALL, MOVE_POISON_GAS},
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_BITE, MOVE_TAUNT, MOVE_TOXIC, MOVE_BODY_SLAM},
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_WEEZING,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_THUNDERBOLT, MOVE_HEADBUTT},
    },
};


// ======================================================================================= //
// ======================================= Route 14 ====================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperCarter[] = {
    {
        .iv = 10,
        .lvl = 38,
        .species = SPECIES_SKARMORY,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperMitch[] = {
    {
        .iv = 10,
        .lvl = 38,
        .species = SPECIES_PIDGEOT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperMarlon[] = {
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_FARFETCHD,
    },
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_DELIBIRD,
    },
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_GLIGAR,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperMarlonRematchAfterFuchsia[] = {
    {
        .iv = 13,
        .lvl = 38,
        .species = SPECIES_FARFETCHD,
    },
    {
        .iv = 13,
        .lvl = 38,
        .species = SPECIES_DELIBIRD,
    },
    {
        .iv = 13,
        .lvl = 38,
        .species = SPECIES_GLIGAR,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperMarlonRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 58,
        .species = SPECIES_FARFETCHD,
    },
    {
        .iv = 18,
        .lvl = 58,
        .species = SPECIES_DELIBIRD,
    },
    // {
    //     .iv = 18,
    //     .lvl = 58,
    //     .species = SPECIES_GLISCOR, 
    // },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperBeck[] = {
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_PELIPPER,
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_MASQUERAIN,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperDonald[] = {
    {
        .iv = 10,
        .lvl = 38,
        .species = SPECIES_FLYGON,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperBenny[] = {
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_COMBUSKEN,
    },
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperBennyRematchAfterFuchsia[] = {
    {
        .iv = 16,
        .lvl = 38,
        .species = SPECIES_BLAZIKEN,
    },
    {
        .iv = 16,
        .lvl = 38,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperBennyRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_BLAZIKEN,
    },
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TwinsKiriJan[] = {
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_CHARMELEON,
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_WARTORTLE,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_BikerGerald[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_BITE, MOVE_FLAME_WHEEL, MOVE_SMOG, MOVE_HOWL},
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_QWILFISH,
        .moves = {MOVE_PIN_MISSILE, MOVE_BUBBLE_BEAM, MOVE_REVENGE, MOVE_POISON_STING},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_BikerMalik[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_WATERFALL, MOVE_BITE, MOVE_SCARY_FACE, MOVE_MEGA_PUNCH},
    },
    {
        .iv = 10,
        .lvl = 36,
        .species = SPECIES_SLAKING,
        .moves = {MOVE_YAWN, MOVE_SLACK_OFF, MOVE_FAINT_ATTACK, MOVE_CRUSH_CLAW},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_BikerIsaac[] = {
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_MAGCARGO,
        .moves = {MOVE_ROCK_TOMB, MOVE_HEAT_WAVE, MOVE_YAWN, MOVE_SMOG}
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_CACTURNE,
        .moves = {MOVE_FAINT_ATTACK, MOVE_NEEDLE_ARM, MOVE_GROWTH, MOVE_REVENGE},
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_CLOYSTER,
        .moves = {MOVE_ICICLE_SPEAR, MOVE_PROTECT, MOVE_RAPID_SPIN, MOVE_BUBBLE_BEAM},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_BikerLukas[] = {
    {
        .iv = 10,
        .lvl = 38,
        .species = SPECIES_WEEZING,
        .moves = {MOVE_REST, MOVE_SLUDGE, MOVE_TOXIC, MOVE_SHOCK_WAVE},
    },
    {
        .iv = 10,
        .lvl = 38,
        .species = SPECIES_MUK,
        .moves = {MOVE_STRENGTH, MOVE_GIGA_DRAIN, MOVE_SLUDGE, MOVE_DISABLE},
    },
    {
        .iv = 10,
        .lvl = 38,
        .species = SPECIES_MAGMAR,
        .moves = {MOVE_FLAMETHROWER, MOVE_SLUDGE_BOMB, MOVE_SMOG, MOVE_LEER},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_BikerLukasRematchAfterLeague[] = {
    {
        .iv = 20,
        .lvl = 58,
        .species = SPECIES_WEEZING,
        .moves = {MOVE_REST, MOVE_SLUDGE_BOMB, MOVE_TOXIC, MOVE_THUNDERBOLT},
    },
    {
        .iv = 20,
        .lvl = 58,
        .species = SPECIES_MUK,
        .moves = {MOVE_STRENGTH, MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_DISABLE},
    },
    // {
    //     .iv = 20,
    //     .lvl = 58,
    //     .species = SPECIES_MAGMORTAR,
    //     .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    // },
};


// ======================================================================================= //
// ==================================== Route 15 North =================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerBecky[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_MAWILE,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_RAICHU,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerBeckyRematchAfterFuchsia[] = {
    {
        .iv = 16,
        .lvl = 40,
        .species = SPECIES_MAWILE,
    },
    {
        .iv = 16,
        .lvl = 40,
        .species = SPECIES_RAICHU,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerBeckyRematchAfterLeague[] = {
    {
        .iv = 20,
        .lvl = 59,
        .species = SPECIES_MAWILE,
    },
    {
        .iv = 20,
        .lvl = 59,
        .species = SPECIES_RAICHU,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerBeckyRematchAfterSapphire[] = {
    {
        .iv = 22,
        .lvl = 64,
        .species = SPECIES_MAWILE,
    },
    {
        .iv = 22,
        .lvl = 64,
        .species = SPECIES_RAICHU,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_CrushKinRonMya[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_HITMONLEE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_CrushKinRonMyaRematchAfterFuchsia[] = {
    {
        .iv = 11,
        .lvl = 39,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 11,
        .lvl = 39,
        .species = SPECIES_HITMONLEE,
        .heldItem = ITEM_BLACK_BELT,
    },
};


static const struct TrainerMonItemDefaultMoves sParty_CrushKinRonMyaRematchAfterLeague[] = {
    {
        .iv = 13,
        .lvl = 59,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 13,
        .lvl = 59,
        .species = SPECIES_HITMONLEE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_CrushKinRonMyaRematchAfterSapphire[] = {
    {
        .iv = 17,
        .lvl = 66,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 17,
        .lvl = 66,
        .species = SPECIES_HITMONLEE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerCelia[] = {
    {
        .iv = 10,
        .lvl = 38,
        .species = SPECIES_CLEFABLE,
    },
};

// ======================================================================================= //
// ==================================== Route 15 South =================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemCustomMoves sParty_BikerErnest[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH},
    },
    {
        .iv = 10,
        .lvl = 36,
        .species = SPECIES_ABSOL,
        .moves = {MOVE_TAUNT, MOVE_SLASH, MOVE_SWORDS_DANCE, MOVE_FAINT_ATTACK},
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_FIRE_SPIN, MOVE_QUICK_ATTACK, MOVE_FLAME_WHEEL, MOVE_THRASH},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_BikerAlex[] = {
    {
        .iv = 10,
        .lvl = 38,
        .species = SPECIES_GOLBAT,
        .moves = {MOVE_POISON_FANG, MOVE_WING_ATTACK, MOVE_SUPERSONIC, MOVE_BITE},
    },
    {
        .iv = 10,
        .lvl = 40,
        .species = SPECIES_EXPLOUD,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_REST, MOVE_STRENGTH, MOVE_ICE_BEAM},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BeautyGrace[] = {
    {
        .iv = 10,
        .lvl = 37,
        .species = SPECIES_JYNX,
    },
    {
        .iv = 10,
        .lvl = 37,
        .species = SPECIES_WIGGLYTUFF,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BeautyGraceRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_JYNX,
    },
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_WIGGLYTUFF,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BeautyOlivia[] = {
    {
        .iv = 10,
        .lvl = 37,
        .species = SPECIES_LAPRAS,
    },
    {
        .iv = 10,
        .lvl = 37,
        .species = SPECIES_VENUSAUR,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerKindra[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_GLOOM,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_VILEPLUME,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_BELLOSSOM,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperChester[] = {
    {
        .iv = 10,
        .lvl = 38,
        .species = SPECIES_DODRIO,
    },
    {
        .iv = 10,
        .lvl = 38,
        .species = SPECIES_SKARMORY,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperChesterRematchAfterFuchsia[] = {
    {
        .iv = 16,
        .lvl = 41,
        .species = SPECIES_DODRIO,
    },
    {
        .iv = 16,
        .lvl = 41,
        .species = SPECIES_SKARMORY,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperChesterRematchAfterLeague[] = {
    {
        .iv = 28,
        .lvl = 61,
        .species = SPECIES_DODRIO,
    },
    {
        .iv = 28,
        .lvl = 61,
        .species = SPECIES_SKARMORY,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperEdwin[] = {
    {
        .iv = 10,
        .lvl = 36,
        .species = SPECIES_DELIBIRD,
    },
    {
        .iv = 10,
        .lvl = 36,
        .species = SPECIES_AERODACTYL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerYazmin[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_PERSIAN,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_PARASECT,
    },
    {
        .iv = 10,
        .lvl = 36,
        .species = SPECIES_NIDOQUEEN,
    },
};

// ======================================================================================= //
// ==================================== Route 16 South =================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemCustomMoves sParty_BikerLao[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_NOSEPASS,
        .moves = {MOVE_ROCK_TOMB, MOVE_THUNDER_WAVE, MOVE_MAGNITUDE, MOVE_SHOCK_WAVE},
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_KOFFING,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_HEADBUTT},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CueBallKoji[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_LOUDRED,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_METANG,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_URSARING,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CueBallLuke[] = {
    {
        .iv = 10,
        .lvl = 36,
        .species = SPECIES_MACHOKE,
    },
    {
        .iv = 10,
        .lvl = 36,
        .species = SPECIES_POLIWRATH,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BikerHideo[] = {
    {
        .iv = 10,
        .lvl = 39,
        .species = SPECIES_WEEZING,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_BikerRuben[] = {
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_KOFFING,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 10,
        .lvl = 37,
        .species = SPECIES_GRIMER,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BikerRubenRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 58,
        .species = SPECIES_WEEZING,
    },
    {
        .iv = 18,
        .lvl = 58,
        .species = SPECIES_MUK,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CueBallCamron[] = {
    {
        .iv = 10,
        .lvl = 36,
        .species = SPECIES_PRIMEAPE,
    },
    {
        .iv = 10,
        .lvl = 36,
        .species = SPECIES_MACHOKE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CueBallCamronRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_PRIMEAPE,
    },
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_MACHAMP,
    },
};


// ======================================================================================= //
// ====================================== Route 17 ======================================= //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_CueBallIsaiah[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_TAUROS,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_MACHAMP,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CueBallIsaiahRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_TAUROS,
    },
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_MACHAMP,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_BikerVirgil[] = {
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_BONEMERANG, MOVE_HEADBUTT, MOVE_SEISMIC_TOSS, MOVE_SANDSTORM},
    },
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_RAPID_SPIN, MOVE_TAKE_DOWN, MOVE_ZAP_CANNON, MOVE_SAND_TOMB},
    },
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_BITE, MOVE_MEGA_PUNCH, MOVE_SEISMIC_TOSS, MOVE_ROCK_TOMB},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CueBallRaul[] = {
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_ARIADOS,
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_FLAREON,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BikerBilly[] = {
    {
        .iv = 10,
        .lvl = 38,
        .species = SPECIES_MUK,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CueBallJamal[] = {
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_JOLTEON,
    },
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_KINGLER,
    },
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_NIDOKING,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_BikerNikolas[] = {
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_THUNDERBOLT, MOVE_SONIC_BOOM, MOVE_SCREECH, MOVE_CHARGE},
    },
    {
        .iv = 10,
        .lvl = 34,
        .species = SPECIES_CAMERUPT,
        .moves = {MOVE_MAGNITUDE, MOVE_ROCK_SLIDE, MOVE_OVERHEAT, MOVE_AMNESIA},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CueBallZeek[] = {
    {
        .iv = 10,
        .lvl = 37,
        .species = SPECIES_SLOWBRO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CueBallCorey[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_PRIMEAPE,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_MACHOKE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CueBallCoreyRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_PRIMEAPE,
    },
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_MACHAMP,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_BikerJaxon[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_WEEZING,
        .moves = {MOVE_SLUDGE, MOVE_SMOKESCREEN, MOVE_SMOG, MOVE_HEADBUTT},
    },
    {
        .iv = 10,
        .lvl = 38,
        .species = SPECIES_MUK,
        .moves = {MOVE_SCREECH, MOVE_FACADE, MOVE_SLUDGE, MOVE_DISABLE},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BikerJaxonRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_WEEZING,
    },
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_MUK,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_BikerWilliam[] = {
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_ELECTABUZZ,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_LIGHT_SCREEN, MOVE_QUICK_ATTACK, MOVE_PSYCHIC},
    },
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_MAGMAR,
        .moves = {MOVE_FIRE_PUNCH, MOVE_SLUDGE_BOMB, MOVE_SMOG, MOVE_KARATE_CHOP},
    },
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_PINSIR,
        .moves = {MOVE_MEGAHORN, MOVE_BRICK_BREAK, MOVE_CUT, MOVE_BULK_UP},
    },
    {
        .iv = 10,
        .lvl = 33,
        .species = SPECIES_TAUROS,
        .moves = {MOVE_HORN_ATTACK, MOVE_TAIL_WHIP, MOVE_ROCK_SMASH, MOVE_IRON_TAIL},
    },
};


// ======================================================================================= //
// ====================================== Route 18 ======================================= //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperJacob[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_COMBUSKEN,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_FEAROW,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperJacobRematchAfterFuchsia[] = {
    {
        .iv = 16,
        .lvl = 38,
        .species = SPECIES_BLAZIKEN,
    },
    {
        .iv = 16,
        .lvl = 38,
        .species = SPECIES_FEAROW,
    },
    {
        .iv = 16,
        .lvl = 38,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperJacobRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 57,
        .species = SPECIES_BLAZIKEN
    },
    {
        .iv = 18,
        .lvl = 57,
        .species = SPECIES_FEAROW,
    },
    {
        .iv = 18,
        .lvl = 57,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperWilton[] = {
    {
        .iv = 10,
        .lvl = 36,
        .species = SPECIES_PELIPPER,
    },
    {
        .iv = 10,
        .lvl = 36,
        .species = SPECIES_PIDGEOT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperRamiro[] = {
    {
        .iv = 10,
        .lvl = 39,
        .species = SPECIES_DODRIO,
    },
};


// ======================================================================================= //
// ==================================== Route 19 Land ==================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleRichard[] = {
    {
        .iv = 10,
        .lvl = 37,
        .species = SPECIES_TENTACRUEL,
    },
    {
        .iv = 10,
        .lvl = 37,
        .species = SPECIES_CLOYSTER,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleReece[] = {
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_STARYU,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_SEADRA,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_SEAKING,
    },
};


// ======================================================================================= //
// =================================== Fuchsia City Gym ================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_JugglerKayden[] = {
    {
        .iv = 10,
        .lvl = 40,
        .species = SPECIES_ZANGOOSE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_JugglerNate[] = {
    {
        .iv = 10,
        .lvl = 39,
        .species = SPECIES_NIDOQUEEN,
    },
    {
        .iv = 10,
        .lvl = 39,
        .species = SPECIES_NIDOKING,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_JugglerKirk[] = {
    {
        .iv = 10,
        .lvl = 36,
        .species = SPECIES_VENOMOTH,
    },
    {
        .iv = 10,
        .lvl = 36,
        .species = SPECIES_SABLEYE,
    },
    {
        .iv = 10,
        .lvl = 35,
        .species = SPECIES_KADABRA,
    },
    {
        .iv = 10,
        .lvl = 36,
        .species = SPECIES_TENTACRUEL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TamerEdgar[] = {
    {
        .iv = 10,
        .lvl = 37,
        .species = SPECIES_ARBOK,
    },
    {
        .iv = 10,
        .lvl = 36,
        .species = SPECIES_SEVIPER,
    },
    {
        .iv = 10,
        .lvl = 37,
        .species = SPECIES_DONPHAN,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TamerPhil[] = {
    {
        .iv = 10,
        .lvl = 40,
        .species = SPECIES_QWILFISH,
    },
    {
        .iv = 10,
        .lvl = 40,
        .species = SPECIES_ARBOK,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_JugglerShawn[] = {
    {
        .iv = 10,
        .lvl = 40,
        .species = SPECIES_EXPLOUD,
    },
    {
        .iv = 10,
        .lvl = 40,
        .species = SPECIES_HYPNO,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_LeaderKoga[] = {
    {
        .iv = 15,
        .lvl = 43,
        .species = SPECIES_ARIADOS,
        .heldItem = ITEM_FOCUS_SASH,
        .moves = {MOVE_POISON_FANG, MOVE_LEECH_LIFE, MOVE_PURSUIT, MOVE_SPIDER_WEB},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 44,
        .species = SPECIES_MUK,
        .heldItem = ITEM_POISON_BARB,
        .moves = {MOVE_MINIMIZE, MOVE_SLUDGE_BOMB, MOVE_FLAMETHROWER, MOVE_TOXIC},
        .nature = NATURE_SERIOUS,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 44,
        .species = SPECIES_CROBAT,
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_POISON_FANG, MOVE_AERIAL_ACE, MOVE_LEECH_LIFE, MOVE_CONFUSE_RAY},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_WEEZING,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_FIRE_BLAST, MOVE_SLUDGE_BOMB, MOVE_THUNDER, MOVE_WILL_O_WISP},
        .nature = NATURE_MODEST,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_TENTACRUEL,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_MIRROR_COAT, MOVE_GIGA_DRAIN},
        .nature = NATURE_BOLD,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_ARBOK,
        .heldItem = ITEM_BLACK_GLASSES,
        .moves = {MOVE_CRUNCH, MOVE_POISON_FANG, MOVE_GLARE, MOVE_EARTHQUAKE},
        .nature = NATURE_IMPISH,
        .abilitySlot = 1,
    },
}; 


// ======================================================================================= //
// ======================================= Silph Co. ===================================== //
// ========================================= 2F ========================================== //
static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt24[] = {
    {
        .iv = 15,
        .lvl = 37,
        .species = SPECIES_GOLBAT,
    },
    {
        .iv = 15,
        .lvl = 37,
        .species = SPECIES_METANG,
    },
    {
        .iv = 15,
        .lvl = 37,
        .species = SPECIES_CLAYDOL,
    },
    {
        .iv = 15,
        .lvl = 37,
        .species = SPECIES_RATICATE,
    },
    {
        .iv = 15,
        .lvl = 37,
        .species = SPECIES_FORRETRESS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_ScientistJerry[] = {
    {
        .iv = 15,
        .lvl = 38,
        .species = SPECIES_MAGNETON,
    },
    {
        .iv = 15,
        .lvl = 38,
        .species = SPECIES_UMBREON,
    },
    {
        .iv = 15,
        .lvl = 38,
        .species = SPECIES_KABUTOPS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt23[] = {
    {
        .iv = 15,
        .lvl = 39,
        .species = SPECIES_MAROWAK,
    },
    {
        .iv = 15,
        .lvl = 39,
        .species = SPECIES_DODRIO,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_ScientistConnor[] = {
    {
        .iv = 15,
        .lvl = 38,
        .species = SPECIES_MUK,
        .moves = {MOVE_ROCK_SMASH, MOVE_BODY_SLAM, MOVE_SLUDGE, MOVE_DISABLE},
    },
    {
        .iv = 15,
        .lvl = 38,
        .species = SPECIES_WEEZING,
        .moves = {MOVE_FLAMETHROWER, MOVE_SLUDGE_BOMB, MOVE_SHOCK_WAVE, MOVE_HEADBUTT},
    },
    {
        .iv = 15,
        .lvl = 38,
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_LEAF_BLADE, MOVE_GIGA_DRAIN, MOVE_ROCK_TOMB, MOVE_BRICK_BREAK},
    },
    {
        .iv = 15,
        .lvl = 38,
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_FLAME_WHEEL, MOVE_BOUNCE, MOVE_STOMP, MOVE_IRON_TAIL},
    },
};

// ========================================= 3F ========================================== //
static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt25[] = {
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_GYARADOS,
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_HYPNO,
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_GOLEM,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_ScientistJose[] = {
    {
        .iv = 15,
        .lvl = 44,
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_SPARK, MOVE_QUICK_ATTACK, MOVE_SCREECH, MOVE_FACADE},
    },
    {
        .iv = 15,
        .lvl = 44,
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_TRI_ATTACK, MOVE_THUNDERBOLT, MOVE_PSYCHIC, MOVE_ICE_BEAM},
    },
};

// ========================================= 4F ========================================== //
static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt26[] = {
    {
        .iv = 15,
        .lvl = 42,
        .species = SPECIES_MACHAMP,
    },
    {
        .iv = 15,
        .lvl = 42,
        .species = SPECIES_CLOYSTER,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt27[] = {
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_ARBOK,
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_POLIWRATH,
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_EXPLOUD,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_ScientistRodney[] = {
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_FLYGON,
    },
};

// ========================================= 5F ========================================== //
static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt28[] = {
    {
        .iv = 15,
        .lvl = 43,
        .species = SPECIES_ARBOK,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt29[] = {
    {
        .iv = 15,
        .lvl = 43,
        .species = SPECIES_SCIZOR,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_JugglerDalton[] = {
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_KADABRA,
    },
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_MR_MIME,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_ScientistBeau[] = {
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_SPARK, MOVE_THUNDER_WAVE, MOVE_SONIC_BOOM, MOVE_SUPERSONIC},
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_ESPEON,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SMOG, MOVE_TACKLE},
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_MAGNETON,
        .moves = {MOVE_SPARK, MOVE_THUNDER_WAVE, MOVE_SONIC_BOOM, MOVE_SUPERSONIC},
    },
};

// ========================================= 6F ========================================== //
static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt30[] = {
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_CAMERUPT,
    },
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_CROBAT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt31[] = {
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_NOCTOWL,
    },
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_QUAGSIRE,
    },
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_ARMALDO,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_ScientistTaylor[] = {
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_ARIADOS,
        .moves = {MOVE_SPIDER_WEB, MOVE_LEECH_LIFE, MOVE_POISON_FANG, MOVE_PSYBEAM},
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_ABSOL,
        .moves = {MOVE_FAINT_ATTACK, MOVE_AERIAL_ACE, MOVE_QUICK_ATTACK, MOVE_DOUBLE_EDGE},
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_SHELGON,
        .moves = {MOVE_THUNDER_WAVE, MOVE_SONIC_BOOM, MOVE_SUPERSONIC, MOVE_THUNDER_SHOCK},
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_LANTURN,
        .moves = {MOVE_THUNDER_WAVE, MOVE_CONFUSE_RAY, MOVE_BUBBLE_BEAM, MOVE_THUNDERBOLT},
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_FLAREON,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_BITE, MOVE_QUICK_ATTACK, MOVE_OVERHEAT},
    },
};

// ========================================= 7F ========================================== //
static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt33[] = {
    {
        .iv = 15,
        .lvl = 42,
        .species = SPECIES_HITMONCHAN,
    },
    {
        .iv = 15,
        .lvl = 42,
        .species = SPECIES_SABLEYE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt35[] = {
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_POLITOED,
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_SHARPEDO,
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_TANGELA,
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_BEEDRILL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_ScientistJoshua[] = {
    {
        .iv = 15,
        .lvl = 42,
        .species = SPECIES_VILEPLUME,
    },
    {
        .iv = 15,
        .lvl = 42,
        .species = SPECIES_MANTINE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt34[] = {
    {
        .iv = 15,
        .lvl = 42,
        .species = SPECIES_GLALIE,
    },
    {
        .iv = 15,
        .lvl = 42,
        .species = SPECIES_SANDSLASH,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_RivalSilphSquirtle[] = {
    {
        .iv = 25,
        .lvl = 45,
        .species = SPECIES_PIDGEOT,
        .heldItem = ITEM_SILK_SCARF,
        .moves = {MOVE_FRUSTRATION, MOVE_WING_ATTACK, MOVE_QUICK_ATTACK, MOVE_STEEL_WING},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,
    },
    {
        .iv = 25,
        .lvl = 45,
        .species = SPECIES_ARCANINE,
        .heldItem = ITEM_SHELL_BELL,
        .moves = {MOVE_FLAMETHROWER, MOVE_CRUNCH, MOVE_AGILITY, MOVE_IRON_TAIL},
        .nature = NATURE_BASHFUL,
        .abilitySlot = 0,
    },
    {
        .iv = 25,
        .lvl = 45,
        .species = SPECIES_EXEGGUTOR,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM, MOVE_PSYCHIC, MOVE_GIGA_DRAIN},
        .nature = NATURE_MILD,
        .abilitySlot = 1,
    },
    {
        .iv = 25,
        .lvl = 45,
        .species = SPECIES_SNORLAX,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_SEISMIC_TOSS},
        .nature = NATURE_RELAXED,
        .abilitySlot = 0,
    },
    {
        .iv = 25,
        .lvl = 48,
        .species = SPECIES_BLASTOISE,
        .heldItem = ITEM_MYSTIC_WATER,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_RAPID_SPIN, MOVE_BRICK_BREAK},
        .nature = NATURE_CALM,
        .abilitySlot = 1,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_RivalSilphBulbasaur[] = {
    {
        .iv = 25,
        .lvl = 45,
        .species = SPECIES_PIDGEOT,
        .heldItem = ITEM_SILK_SCARF,
        .moves = {MOVE_FRUSTRATION, MOVE_WING_ATTACK, MOVE_QUICK_ATTACK, MOVE_STEEL_WING},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,
    },
    {
        .iv = 25,
        .lvl = 45,
        .species = SPECIES_GYARADOS,
        .heldItem = ITEM_LUM_BERRY,
        .moves = {MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_THRASH, MOVE_THUNDER_WAVE},
        .nature = NATURE_IMPISH,
        .abilitySlot = 1,
    },
    {
        .iv = 25,
        .lvl = 45,
        .species = SPECIES_ARCANINE,
        .heldItem = ITEM_SHELL_BELL,
        .moves = {MOVE_FLAMETHROWER, MOVE_CRUNCH, MOVE_AGILITY, MOVE_IRON_TAIL},
        .nature = NATURE_BASHFUL,
        .abilitySlot = 0,
    },
    {
        .iv = 25,
        .lvl = 45,
        .species = SPECIES_SNORLAX,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_SEISMIC_TOSS},
        .nature = NATURE_RELAXED,
        .abilitySlot = 0,
    },
    {
        .iv = 25,
        .lvl = 48,
        .species = SPECIES_VENUSAUR,
        .heldItem = ITEM_MIRACLE_SEED,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_GROWTH, MOVE_BODY_SLAM},
        .nature = NATURE_SERIOUS,
        .abilitySlot = 1,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_RivalSilphCharmander[] = {
    {
        .iv = 25,
        .lvl = 45,
        .species = SPECIES_PIDGEOT,
        .heldItem = ITEM_SILK_SCARF,
        .moves = {MOVE_FRUSTRATION, MOVE_WING_ATTACK, MOVE_QUICK_ATTACK, MOVE_STEEL_WING},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,
    },
    {
        .iv = 25,
        .lvl = 45,
        .species = SPECIES_EXEGGUTOR,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM, MOVE_PSYCHIC, MOVE_GIGA_DRAIN},
        .nature = NATURE_MILD,
        .abilitySlot = 1,
    },
    {
        .iv = 25,
        .lvl = 45,
        .species = SPECIES_GYARADOS,
        .heldItem = ITEM_LUM_BERRY,
        .moves = {MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_THRASH, MOVE_THUNDER_WAVE},
        .nature = NATURE_IMPISH,
        .abilitySlot = 0,
    },
    {
        .iv = 25,
        .lvl = 45,
        .species = SPECIES_SNORLAX,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_SEISMIC_TOSS},
        .nature = NATURE_RELAXED,
        .abilitySlot = 0,
    },
    {
        .iv = 25,
        .lvl = 48,
        .species = SPECIES_CHARIZARD,
        .heldItem = ITEM_CHARCOAL,
        .moves = {MOVE_FIRE_BLAST, MOVE_WING_ATTACK, MOVE_STEEL_WING, MOVE_DRAGON_CLAW},
        .nature = NATURE_LONELY,
        .abilitySlot = 1,
    },
};

// ========================================= 8F ========================================== //
static const struct TrainerMonNoItemCustomMoves sParty_TeamRocketGrunt32[] = {
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_LEDIAN,
        .moves = {MOVE_PSYBEAM, MOVE_SILVER_WIND, MOVE_COMET_PUNCH, MOVE_BRICK_BREAK},
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_MURKROW,
        .moves = {MOVE_DRILL_PECK, MOVE_FAINT_ATTACK, MOVE_TAUNT, MOVE_HAZE},
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_GRUMPIG,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_SHOCK_WAVE, MOVE_REFLECT},
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_HUNTAIL,
        .moves = {MOVE_CRUNCH, MOVE_WATERFALL, MOVE_CONFUSE_RAY, MOVE_IRON_DEFENSE},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt36[] = {
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_WEEZING,
    },
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_KECLEON,
    },
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_PRIMEAPE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_ScientistParker[] = {
    {
        .iv = 15,
        .lvl = 42,
        .species = SPECIES_GIRAFARIG,
    },
    {
        .iv = 15,
        .lvl = 42,
        .species = SPECIES_PILOSWINE,
    },
};

// ========================================= 9F ========================================== //
static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt37[] = {
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_MIGHTYENA,
    },
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_HARIYAMA,
    },
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_MANECTRIC,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt38[] = {
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_GRANBULL,
    },
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_FERALIGATR,
    },
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_ONIX,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_ScientistEd[] = {
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_HAUNTER,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_BOMB, MOVE_WILL_O_WISP, MOVE_DESTINY_BOND},
    },
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_BODY_SLAM, MOVE_REST, MOVE_CURSE, MOVE_STRENGTH},
    },
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_KINGLER,
        .moves = {MOVE_WATERFALL, MOVE_VICE_GRIP, MOVE_ROCK_SMASH, MOVE_ROCK_TOMB},
    },
};

// ======================================== 10F ========================================== //
static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt39[] = {
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_SLAKING,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_ScientistTravis[] = {
    {
        .iv = 15,
        .lvl = 43,
        .species = SPECIES_AGGRON,
    },
    {
        .iv = 15,
        .lvl = 43,
        .species = SPECIES_TYPHLOSION,
    },
};

// ======================================== 11F ========================================== //
static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt40[] = {
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_CLAYDOL,
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_POLIWRATH,
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_DUGTRIO,
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_MILTANK,
    },
    {
        .iv = 15,
        .lvl = 40,
        .species = SPECIES_CACTURNE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt41[] = {
    {
        .iv = 15,
        .lvl = 42,
        .species = SPECIES_SEVIPER,
    },
    {
        .iv = 15,
        .lvl = 42,
        .species = SPECIES_ZANGOOSE,
    },
    {
        .iv = 15,
        .lvl = 42,
        .species = SPECIES_MAROWAK,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_BossGiovanniSilphCo[] = {
    {
        .iv = 16,
        .lvl = 47,
        .species = SPECIES_NIDOKING,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DIG, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_FLAMETHROWER},
        .nature = NATURE_RASH,
        .abilitySlot = 1,
    },
    {
        .iv = 16,
        .lvl = 48,
        .species = SPECIES_NIDOQUEEN,
        .heldItem = ITEM_CHESTO_BERRY,
        .moves = {MOVE_SUPERPOWER, MOVE_REST, MOVE_CRUNCH, MOVE_SLUDGE_BOMB},
        .nature = NATURE_CAREFUL,
        .abilitySlot = 1,
    },
    {
        .iv = 16,
        .lvl = 50,
        .species = SPECIES_KANGASKHAN,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_MEGA_PUNCH, MOVE_FAKE_OUT, MOVE_STRENGTH, MOVE_BRICK_BREAK},
        .nature = NATURE_ADAMANT,
        .abilitySlot = 0,
    },
    {
        .iv = 16,
        .lvl = 47,
        .species = SPECIES_RHYDON,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ROCK_BLAST, MOVE_SANDSTORM, MOVE_FACADE, MOVE_SWORDS_DANCE},
        .nature = NATURE_SERIOUS,
        .abilitySlot = 0,
    },
    {
        .iv = 16,
        .lvl = 48,
        .species = SPECIES_DUGTRIO,
        .heldItem = ITEM_SOFT_SAND,
        .moves = {MOVE_EARTHQUAKE, MOVE_TRI_ATTACK, MOVE_PURSUIT, MOVE_AERIAL_ACE},
        .nature = NATURE_IMPISH,
        .abilitySlot = 0,
    },
    {
        .iv = 16,
        .lvl = 47,
        .species = SPECIES_PERSIAN,
        .heldItem = ITEM_AMULET_COIN,
        .moves = {MOVE_BODY_SLAM, MOVE_FAKE_OUT, MOVE_FAINT_ATTACK, MOVE_SCREECH},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,
    },
};


// ======================================================================================= //
// =================================== Saffron City Gym ================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_PsychicCameron[] = {
    {
        .iv = 15,
        .lvl = 43,
        .species = SPECIES_WOBBUFFET,
    },
    {
        .iv = 15,
        .lvl = 43,
        .species = SPECIES_CLAYDOL,
    },
    {
        .iv = 15,
        .lvl = 43,
        .species = SPECIES_SLOWBRO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PsychicTyron[] = {
    {
        .iv = 15,
        .lvl = 44,
        .species = SPECIES_MR_MIME,
    },
    {
        .iv = 15,
        .lvl = 44,
        .species = SPECIES_KADABRA,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_ChannelerStacy[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_GENGAR,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PsychicPreston[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_SLOWKING,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_ChannelerAmanda[] = {
    {
        .iv = 15,
        .lvl = 44,
        .species = SPECIES_HAUNTER,
    },
    {
        .iv = 15,
        .lvl = 44,
        .species = SPECIES_DUSCLOPS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_ChannelerTasha[] = {
    {
        .iv = 15,
        .lvl = 43,
        .species = SPECIES_SABLEYE,
    },
    {
        .iv = 15,
        .lvl = 43,
        .species = SPECIES_MISDREAVUS,
    },
    {
        .iv = 15,
        .lvl = 43,
        .species = SPECIES_SEVIPER,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PsychicJohan[] = {
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_GIRAFARIG,
    },
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_LICKITUNG,
    },
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_ABSOL,
    },
    {
        .iv = 15,
        .lvl = 41,
        .species = SPECIES_METANG,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_LeaderSabrina[] = {
    {
        .iv = 18,
        .lvl = 48,
        .species = SPECIES_JYNX,
        .heldItem = ITEM_NEVER_MELT_ICE,
        .moves = {MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_LOVELY_KISS, MOVE_ATTRACT},
        .nature = NATURE_TIMID,
        .abilitySlot = 0,
    },
    {
        .iv = 18,
        .lvl = 49,
        .species = SPECIES_SLOWBRO,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_PSYCHIC, MOVE_CURSE, MOVE_BODY_SLAM, MOVE_BRICK_BREAK},
        .nature = NATURE_BRAVE,
        .abilitySlot = 1,
    },
    {
        .iv = 18,
        .lvl = 49,
        .species = SPECIES_MEDICHAM,
        .heldItem = ITEM_STARF_BERRY,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_BULK_UP},
        .nature = NATURE_DOCILE,
        .abilitySlot = 0,
    },
    {
        .iv = 18,
        .lvl = 49,
        .species = SPECIES_VENOMOTH,
        .heldItem = ITEM_SILVER_POWDER,
        .moves = {MOVE_PSYCHIC, MOVE_SILVER_WIND, MOVE_LEECH_LIFE, MOVE_SLUDGE_BOMB},
        .nature = NATURE_RASH,
        .abilitySlot = 0,
    },
    {
        .iv = 25,
        .lvl = 49,
        .species = SPECIES_EXEGGUTOR,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM, MOVE_PSYCHIC, MOVE_SLUDGE_BOMB},
        .nature = NATURE_QUIET,
        .abilitySlot = 1,
    },
    {
        .iv = 18,
        .lvl = 51,
        .species = SPECIES_ALAKAZAM,
        .heldItem = ITEM_TWISTED_SPOON,
        .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_DISABLE, MOVE_SHADOW_BALL},
        .nature = NATURE_MODEST,
        .abilitySlot = 0,
    },
};


// ======================================================================================= //
// ======================================== Route 4 ====================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_LassCrissy[] = {
    {
        .iv = 15,
        .lvl = 44,
        .species = SPECIES_PARASECT,
    },
    {
        .iv = 15,
        .lvl = 44,
        .species = SPECIES_MASQUERAIN,
    },
    {
        .iv = 15,
        .lvl = 44,
        .species = SPECIES_CORSOLA,
    },
};


// ======================================================================================= //
// ==================================== Route 10 Surf ==================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_PokemaniacMark[] = {
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_RHYDON,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_LICKITUNG,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PokemaniacMarkRematchAfterLeague[] = {
    {
        .iv = 19,
        .lvl = 61,
        .species = SPECIES_RHYDON,
    },
    {
        .iv = 19,
        .lvl = 61,
        .species = SPECIES_LICKITUNG,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PokemaniacMarkRematchAfterSapphire[] = {
    {
        .iv = 25,
        .lvl = 69,
        .species = SPECIES_RHYDON,
    },
    {
        .iv = 25,
        .lvl = 69,
        .species = SPECIES_LICKITUNG,
    },
};


// ======================================================================================= //
// ==================================== Route 19 Water =================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleTony[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_SEALEO,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_KINGDRA,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleTonyRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 62,
        .species = SPECIES_WALREIN,
    },
    {
        .iv = 18,
        .lvl = 62,
        .species = SPECIES_KINGDRA,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleDavid[] = {
    {
        .iv = 15,
        .lvl = 46,
        .species = SPECIES_PELIPPER,
    },
    {
        .iv = 15,
        .lvl = 46,
        .species = SPECIES_WHISCASH,
    },
    {
        .iv = 15,
        .lvl = 46,
        .species = SPECIES_SHARPEDO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleDouglas[] = {
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_GOLDUCK,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_BLASTOISE,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_MANTINE,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_CRAWDAUNT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleMatthew[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_POLITOED,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_LUDICOLO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleMatthewRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 61,
        .species = SPECIES_POLITOED,
    },
    {
        .iv = 18,
        .lvl = 61,
        .species = SPECIES_LUDICOLO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SisAndBroLiaLuc[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_MILOTIC,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_SEAKING,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleAxle[] = {
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_VAPOREON,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_GYARADOS,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_FERALIGATR,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_LANTURN,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_TENTACRUEL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleAlice[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_POLIWRATH,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_DRAGONAIR,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleAliceRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 61,
        .species = SPECIES_POLIWRATH,
    },
    {
        .iv = 18,
        .lvl = 61,
        .species = SPECIES_DRAGONITE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleAnya[] = {
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_AZUMARILL,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_MASQUERAIN,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_SEAKING,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_SWAMPERT,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_WOBBUFFET,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleConnie[] = {
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_QWILFISH,
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_QUAGSIRE,
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_STARMIE,
    },
};


// ======================================================================================= //
// ==================================== Route 20 East ==================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleBarry[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_CLOYSTER,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_OCTILLERY,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleDarrin[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_TENTACRUEL,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_WAILORD,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_DEWGONG,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_SEALEO
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleDarrinRematchAfterSapphire[] = {
    {
        .iv = 22,
        .lvl = 65,
        .species = SPECIES_TENTACRUEL,
    },
    {
        .iv = 22,
        .lvl = 65,
        .species = SPECIES_WAILORD,
    },
    {
        .iv = 22,
        .lvl = 65,
        .species = SPECIES_DEWGONG,
    },
    {
        .iv = 22,
        .lvl = 65,
        .species = SPECIES_WALREIN,
    },
};

static const struct TrainerMonNoItemDefaultMovesNatureAbility sParty_SwimmerFemaleShirley[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_PELIPPER,
        .nature = NATURE_DOCILE,
        .abilitySlot = 1,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_HUNTAIL,
        .nature = NATURE_DOCILE,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_GOREBYSS,
        .nature = NATURE_DOCILE,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleTiffany[] = {
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_LAPRAS,
    },
};


// ======================================================================================= //
// ======================================= Route 21 ====================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_FishermanWade[] = {
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_GYARADOS,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_DRAGONAIR,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_SLOWBRO,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_KINGLER,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_LUVDISC,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_FishermanWadeRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 58,
        .species = SPECIES_GYARADOS,
    },
    {
        .iv = 18,
        .lvl = 58,
        .species = SPECIES_DRAGONAIR,
    },
    {
        .iv = 18,
        .lvl = 58,
        .species = SPECIES_SLOWBRO,
    },
    {
        .iv = 18,
        .lvl = 58,
        .species = SPECIES_KINGLER,
    },
    {
        .iv = 18,
        .lvl = 58,
        .species = SPECIES_LUVDISC,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_FishermanRonald[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_SEAKING,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_OMASTAR,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_KABUTOPS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SisAndBroLilIan[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_KINGDRA,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_STARMIE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SisAndBroLilIanRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 61,
        .species = SPECIES_KINGDRA,
    },
    {
        .iv = 18,
        .lvl = 61,
        .species = SPECIES_STARMIE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SisAndBroLilIanRematchAfterSapphire[] = {
    {
        .iv = 22,
        .lvl = 72,
        .species = SPECIES_KINGDRA,
    },
    {
        .iv = 22,
        .lvl = 72,
        .species = SPECIES_STARMIE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleSpencer[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_CORSOLA,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_SLOWKING,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_FishermanClaude[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_HUNTAIL,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_CLOYSTER,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_FishermanNolan[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_RELICANTH,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_GOLDUCK,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleJack[] = {
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_STARMIE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleJackRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 67,
        .species = SPECIES_STARMIE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleRoland[] = {
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_POLITOED,
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_TENTACRUEL,
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_GYARADOS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleJerome[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_POLIWRATH,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_BLASTOISE,
    },
};


// ======================================================================================= //
// ==================================== Route 20 West ==================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleMelissa[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_MANTINE,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_SHARPEDO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleMelissaRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 61,
        .species = SPECIES_MANTINE,
    },
    {
        .iv = 18,
        .lvl = 61,
        .species = SPECIES_SHARPEDO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerMissy[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_MANECTRIC,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_GOLEM,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerMissyRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 61,
        .species = SPECIES_MANECTRIC,
    },
    {
        .iv = 18,
        .lvl = 61,
        .species = SPECIES_GOLEM,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerMissyRematchAfterSapphire[] = {
    {
        .iv = 22,
        .lvl = 70,
        .species = SPECIES_MANECTRIC,
    },
    {
        .iv = 22,
        .lvl = 70,
        .species = SPECIES_GOLEM,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleDean[] = {
    {
        .iv = 15,
        .lvl = 54,
        .species = SPECIES_CRAWDAUNT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleNora[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_CLAMPERL,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_MILOTIC,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_CLOYSTER,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperRoger[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_FEAROW,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_SKARMORY,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_PIDGEOT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerIrene[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_AGGRON,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_DEWGONG,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_MEDICHAM,
    },
};


// ======================================================================================= //
// =================================== Pokémon Mansion =================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterJohnson[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_ARBOK,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_LINOONE,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_NINJASK,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BurglarArnie[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_NINETALES,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_CHARIZARD,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BurglarSimon[] = {
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_MIGHTYENA,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_ScientistBraydon[] = {
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_MAGNETON,
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_CRADILY,
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_PORYGON2,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_ScientistTed[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_ELECTRODE,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_WEEZING,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BurglarLewis[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_BLAZIKEN,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_RAPIDASH,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_ScientistIvan[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_KECLEON,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_CAMERUPT,
    },
};


// ======================================================================================= //
// ===================================== Cinnabar Gym ==================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_BurglarQuinn[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_FLAREON,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_ESPEON,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_NINETALES,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SuperNerdErik[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_TORKOAL,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_CAMERUPT
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_KANGASKHAN,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SuperNerdAvery[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_MAGCARGO,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_CHARIZARD,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_TAUROS,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_ELECTABUZZ,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BurglarRamon[] = {
    {
        .iv = 15,
        .lvl = 52,
        .species = SPECIES_RAPIDASH,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SuperNerdDerek[] = {
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_ALAKAZAM,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BurglarDusty[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_PERSIAN,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_DODRIO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SuperNerdZac[] = {
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_FLYGON,
    },
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_HOUNDOOM,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_LeaderBlaine[] = {
    {
        .iv = 21,
        .lvl = 53,
        .species = SPECIES_NINETALES,
        .moves = {MOVE_FLAMETHROWER, MOVE_PSYCHIC, MOVE_FIRE_SPIN, MOVE_SAFEGUARD},
        .heldItem = ITEM_HEAT_ROCK,
        .nature = NATURE_TIMID,
        .abilitySlot = 1,
    },
    {
        .iv = 21,
        .lvl = 53,
        .species = SPECIES_MAGMAR,
        .moves = {MOVE_FLAMETHROWER, MOVE_CONFUSE_RAY, MOVE_SLUDGE_BOMB, MOVE_THUNDER_PUNCH},
        .heldItem = ITEM_LEFTOVERS,
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 21,
        .lvl = 53,
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_SOLAR_BEAM, MOVE_FIRE_SPIN, MOVE_SUNNY_DAY, MOVE_IRON_TAIL},
        .heldItem = ITEM_BRIGHT_POWDER,
        .nature = NATURE_HASTY,
        .abilitySlot = 1,
    },
    {
        .iv = 21,
        .lvl = 54,
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_SKY_UPPERCUT, MOVE_BLAZE_KICK, MOVE_SUNNY_DAY, MOVE_PROTECT},
        .heldItem = ITEM_BLACK_BELT,
        .nature = NATURE_LONELY,
        .abilitySlot = 1,
    },
    {
        .iv = 21,
        .lvl = 54,
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_ERUPTION, MOVE_FLAMETHROWER, MOVE_EARTHQUAKE, MOVE_SMOKESCREEN},
        .heldItem = ITEM_CHARCOAL,
        .nature = NATURE_HASTY,
        .abilitySlot = 0,
    },
    {
        .iv = 21,
        .lvl = 57,
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_EXTREME_SPEED, MOVE_STRENGTH, MOVE_AGILITY, MOVE_FIRE_BLAST},
        .heldItem = ITEM_LUM_BERRY,
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
};


// ======================================================================================= //
// ==================================== Treasure Beach =================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleAmara[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_DEWGONG,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_WALREIN,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_LAPRAS,
    },
};


// ======================================================================================= //
// ===================================== Kindle Road ===================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleAbigail[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_GOLDUCK,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_LANTURN,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_ALTARIA,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerClaire[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_PERSIAN,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_RAPIDASH,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_VENOMOTH,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_CLEFABLE,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_CrushGirlTanya[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_HITMONLEE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_CrushGirlTanyaRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 62,
        .species = SPECIES_HITMONLEE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 18,
        .lvl = 62,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_CrushGirlTanyaRematchAfterSapphire[] = {
    {
        .iv = 27,
        .lvl = 71,
        .species = SPECIES_HITMONLEE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 27,
        .lvl = 71,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperBryce[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_NIDOKING,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_SNORLAX,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_SANDSLASH,
    },
};

static const struct TrainerMonNoItemDefaultMovesNatureAbility sParty_SwimmerMaleGarrett[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_PELIPPER,
        .nature = NATURE_MODEST,
        .abilitySlot = 1,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_CLOYSTER,
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_BLASTOISE,
        .nature = NATURE_QUIRKY,
        .abilitySlot = 1,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_CrushKinMikKia[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_MACHAMP,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_PRIMEAPE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_CrushKinMikKiaRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 61,
        .species = SPECIES_MACHAMP,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 18,
        .lvl = 61,
        .species = SPECIES_PRIMEAPE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_CrushKinMikKiaRematchAfterSapphire[] = {
    {
        .iv = 21,
        .lvl = 71,
        .species = SPECIES_MACHAMP,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 21,
        .lvl = 71,
        .species = SPECIES_PRIMEAPE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_BlackBeltHugh[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_ZANGOOSE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_MACHAMP,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_BlackBeltHughRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_ZANGOOSE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_MACHAMP,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_BlackBeltHughRematchAfterSapphire[] = {
    {
        .iv = 22,
        .lvl = 70,
        .species = SPECIES_ZANGOOSE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 22,
        .lvl = 72,
        .species = SPECIES_MACHAMP,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_BlackBeltShea[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_BRELOOM,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_CRAWDAUNT,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_BlackBeltSheaRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 60,
        .species = SPECIES_BRELOOM,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 18,
        .lvl = 60,
        .species = SPECIES_CRAWDAUNT,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_BlackBeltSheaRematchAfterSapphire[] = {
    {
        .iv = 22,
        .lvl = 68,
        .species = SPECIES_BRELOOM,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 22,
        .lvl = 68,
        .species = SPECIES_CRAWDAUNT,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_CrushGirlSharon[] = {
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_BLAZIKEN,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_SHIFTRY,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_CrushGirlSharonRematchAfterLeague[] = {
    {
        .iv = 13,
        .lvl = 59,
        .species = SPECIES_BLAZIKEN,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 13,
        .lvl = 59,
        .species = SPECIES_SHIFTRY,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_CrushGirlSharonRematchAfterSapphire[] = {
    {
        .iv = 17,
        .lvl = 66,
        .species = SPECIES_BLAZIKEN,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 17,
        .lvl = 66,
        .species = SPECIES_SHIFTRY,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleFinn[] = {
    {
        .iv = 15,
        .lvl = 55,
        .species = SPECIES_STARMIE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleFinnRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 65,
        .species = SPECIES_STARMIE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleMaria[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_TENTACRUEL,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_KINGDRA,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_FishermanTommy[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_SEAKING,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_GYARADOS,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_FERALIGATR,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_SWAMPERT,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_SHARPEDO,
    },
};


// ======================================================================================== //
// ====================================== Mt. Ember ======================================= //
// ======================================================================================== //
static const struct TrainerMonNoItemDefaultMoves sParty_PkmnRangerBeth[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_BELLOSSOM,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_MANECTRIC,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_FLYGON,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_CrushGirlJocelyn[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_HITMONTOP,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PkmnRangerLogan[] = {
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_PSYCHIC, MOVE_GIGA_DRAIN, MOVE_STUN_SPORE, MOVE_EGG_BOMB},
    },
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_AERIAL_ACE, MOVE_FURY_CUTTER, MOVE_METAL_CLAW, MOVE_SWORDS_DANCE},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt43[] = {
    {
        .iv = 20,
        .lvl = 59,
        .species = SPECIES_MAROWAK,
    },
    {
        .iv = 15,
        .lvl = 59,
        .species = SPECIES_ARBOK,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt44[] = {
    {
        .iv = 20,
        .lvl = 58,
        .species = SPECIES_RATICATE,
    },
    {
        .iv = 20,
        .lvl = 58,
        .species = SPECIES_SANDSLASH,
    },
    {
        .iv = 20,
        .lvl = 58,
        .species = SPECIES_CRAWDAUNT,
    },
    {
        .iv = 20,
        .lvl = 58,
        .species = SPECIES_DODRIO,
    },
};


// ======================================================================================== //
// ===================================== Three Island ===================================== //
// ======================================================================================== //
static const struct TrainerMonNoItemCustomMoves sParty_BikerGoon[] = {
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_WEEZING,
        .moves = {MOVE_HAZE, MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_HEADBUTT},
    },
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_MUK,
        .moves = {MOVE_ACID_ARMOR, MOVE_SCREECH, MOVE_MUD_SHOT, MOVE_SLUDGE},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_BikerGoon2[] = {
    {
        .iv = 15,
        .lvl = 54,
        .species = SPECIES_ARBOK,
        .moves = {MOVE_BULLDOZE, MOVE_POISON_FANG, MOVE_CRUNCH, MOVE_GLARE},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BikerGoon3[] = {
    {
        .iv = 15,
        .lvl = 54,
        .species = SPECIES_GRANBULL,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_CueBallPaxton[] = {
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_ROCK_SLIDE, MOVE_STEEL_WING, MOVE_WING_ATTACK},
        .heldItem = ITEM_SHARP_BEAK,
        .nature = NATURE_HASTY,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_FLAMETHROWER, MOVE_SLUDGE_BOMB, MOVE_CRUNCH, MOVE_REVERSAL},
        .heldItem = ITEM_BLACK_GLASSES,
        .nature = NATURE_TIMID,
        .abilitySlot = 1,
    },
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_AGGRON,
        .moves = {MOVE_ROCK_TOMB, MOVE_BODY_SLAM, MOVE_BRICK_BREAK, MOVE_IRON_TAIL},
        .heldItem = ITEM_HARD_STONE,
        .nature = NATURE_ADAMANT,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_ARM_THRUST, MOVE_STRENGTH, MOVE_BULK_UP, MOVE_FACADE},
        .heldItem = ITEM_LOADED_DICE,
        .nature = NATURE_BRAVE,
        .abilitySlot = 1,
    },
};


// ======================================================================================== //
// ===================================== Bond Bridge ====================================== //
// ======================================================================================== //
static const struct TrainerMonNoItemDefaultMoves sParty_TwinsJoyMeg[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_CLEFABLE,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_MAWILE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TwinsJoyMegRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 61,
        .species = SPECIES_CLEFABLE,
    },
    {
        .iv = 18,
        .lvl = 61,
        .species = SPECIES_MAWILE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_AromaLadyViolet[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_SUNFLORA,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_MEGANIUM,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_VENUSAUR,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TuberAlexis[] = {
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_POLITOED,
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_STARMIE,
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_LUDICOLO,
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_KINGLER,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleTisha[] = {
    {
        .iv = 15,
        .lvl = 54,
        .species = SPECIES_OCTILLERY,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TuberAmira[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_WHISCASH,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_POLIWRATH,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_WAILORD,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TuberAmiraRematchAfterLeague[] = {
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_WHISCASH,
    },
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_POLIWRATH,
    },
    {
        .iv = 18,
        .lvl = 59,
        .species = SPECIES_WAILORD,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_AromaLadyNikki[] = {
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_VILEPLUME,
    },
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_VICTREEBEL,
    },
};


// ======================================================================================= //
// ================================== Viridian City Gym ================================== //
// ======================================================================================= //
static const struct TrainerMonNoItemDefaultMoves sParty_TamerCole[] = {
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_ARBOK,
    },
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_TAUROS,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_BlackBeltKiyo[] = {
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_MACHAMP,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_CooltrainerSamuel[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_SANDSLASH,
        .moves = {MOVE_SLASH, MOVE_EARTHQUAKE, MOVE_SAND_ATTACK, MOVE_TOXIC},
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_THUNDERBOLT, MOVE_LIGHT_SCREEN, MOVE_SCREECH, MOVE_REFLECT},
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_WATER_PULSE, MOVE_PSYCHIC, MOVE_BRICK_BREAK, MOVE_SHADOW_BALL},
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_MEGAHORN, MOVE_SKY_UPPERCUT, MOVE_EARTHQUAKE, MOVE_BULK_UP},
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_THRASH, MOVE_DOUBLE_KICK, MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_CooltrainerYuji[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_SUNNY_DAY},
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_GOLEM,
        .moves = {MOVE_ROCK_BLAST, MOVE_MAGNITUDE, MOVE_FIRE_BLAST, MOVE_DEFENSE_CURL},
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_BOMB, MOVE_THUNDERBOLT, MOVE_PSYCHIC},
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_DODRIO,
        .moves = {MOVE_TRI_ATTACK, MOVE_DRILL_PECK, MOVE_QUICK_ATTACK, MOVE_PURSUIT},
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_DRAGON_DANCE, MOVE_WATER_PULSE, MOVE_DRAGON_BREATH, MOVE_ICE_BEAM},
    },
};

static const struct TrainerMonItemDefaultMoves sParty_BlackBeltAtsushi[] = {
    {
        .iv = 15,
        .lvl = 52,
        .species = SPECIES_BRELOOM,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 15,
        .lvl = 52,
        .species = SPECIES_POLIWRATH,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TamerJason[] = {
    {
        .iv = 15,
        .lvl = 54,
        .species = SPECIES_ABSOL,
    },
    {
        .iv = 15,
        .lvl = 54,
        .species = SPECIES_UMBREON,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_CooltrainerWarren[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_BONEMERANG, MOVE_HEADBUTT, MOVE_ROCK_SLIDE, MOVE_ROCK_SMASH},
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_WALREIN,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_REST, MOVE_SURF, MOVE_BLIZZARD},
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_PSYCHIC, MOVE_SHOCK_WAVE, MOVE_CALM_MIND, MOVE_MAGICAL_LEAF},
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_MIGHTYENA,
        .moves = {MOVE_CRUNCH, MOVE_POISON_FANG, MOVE_BODY_SLAM, MOVE_SCARY_FACE},
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_BODY_SLAM, MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_DOUBLE_KICK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BlackBeltTakashi[] = {
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
        .moves = {MOVE_SKY_UPPERCUT, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH},
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_ONIX,
        .heldItem = ITEM_HARD_STONE,
        .moves = {MOVE_DRAGON_BREATH, MOVE_SANDSTORM, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE},
    },
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_HITMONLEE,
        .heldItem = ITEM_BLACK_BELT,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_MEGA_KICK, MOVE_BULK_UP, MOVE_EARTHQUAKE},
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_LeaderGiovanni[] = {
    {
        .iv = 24,
        .lvl = 55,
        .species = SPECIES_TYRANITAR,
        .heldItem = ITEM_SMOOTH_ROCK,
        .moves = {MOVE_ROCK_SLIDE, MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,
    },
    {
        .iv = 24,
        .lvl = 55,
        .species = SPECIES_AERODACTYL,
        .heldItem = ITEM_MUSCLE_BAND,
        .moves = {MOVE_ROCK_SLIDE, MOVE_WING_ATTACK, MOVE_STEEL_WING, MOVE_DRAGON_CLAW},
        .nature = NATURE_ADAMANT,
        .abilitySlot = 1,
    },
    {
        .iv = 24,
        .lvl = 55,
        .species = SPECIES_RHYDON,
        .heldItem = ITEM_PASSHO_BERRY,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_ROCK_BLAST, MOVE_SCARY_FACE, MOVE_EARTHQUAKE},
        .nature = NATURE_RELAXED,
        .abilitySlot = 1,
    },
    {
        .iv = 24,
        .lvl = 57,
        .species = SPECIES_NIDOQUEEN,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_BODY_SLAM, MOVE_DOUBLE_KICK, MOVE_PROTECT, MOVE_EARTHQUAKE},
        .nature = NATURE_IMPISH,
        .abilitySlot = 0,
    },
    {
        .iv = 24,
        .lvl = 57,
        .species = SPECIES_NIDOKING,
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_THRASH, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_FLAMETHROWER},
        .nature = NATURE_RASH,
        .abilitySlot = 0,
    },
    {
        .iv = 24,
        .lvl = 58,
        .species = SPECIES_STEELIX,
        .heldItem = ITEM_LUM_BERRY,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_IRON_TAIL, MOVE_REST, MOVE_CRUNCH},
        .nature = NATURE_CAREFUL,
        .abilitySlot = 0,
    },
};


// ======================================================================================= //
// ==================================== Victory Road ===================================== //
// ======================================================================================= //
static const struct TrainerMonItemCustomMovesNatureAbility sParty_CooltrainerNaomi[] = {
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_PERSIAN,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FURY_SWIPES, MOVE_SCREECH, MOVE_FAINT_ATTACK, MOVE_PAY_DAY},
        .nature = NATURE_HASTY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_SCEPTILE,
        .heldItem = ITEM_MIRACLE_SEED,
        .moves = {MOVE_LEAF_BLADE, MOVE_DRAGON_BREATH, MOVE_GIGA_DRAIN, MOVE_ROCK_TOMB},
        .nature = NATURE_LONELY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_RAPIDASH,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FLAME_WHEEL, MOVE_AGILITY, MOVE_BOUNCE, MOVE_SOLAR_BEAM},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_JOLTEON,
        .heldItem = ITEM_MAGNET,
        .moves = {MOVE_THUNDER, MOVE_SHADOW_BALL, MOVE_THUNDER_WAVE, MOVE_RAIN_DANCE},
        .nature = NATURE_TIMID,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_POLIWRATH,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_WATERFALL, MOVE_SUBMISSION, MOVE_EARTHQUAKE, MOVE_HAZE},
        .nature = NATURE_SASSY,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_CooltrainerRolando[] = {
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_KANGASKHAN,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_MEGA_PUNCH, MOVE_ROCK_SLIDE, MOVE_ICE_BEAM, MOVE_BRICK_BREAK},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_SHIFTRY,
        .heldItem = ITEM_BLACK_GLASSES,
        .moves = {MOVE_LEAF_BLADE, MOVE_PURSUIT, MOVE_RAZOR_WIND, MOVE_EXTRASENSORY},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_MILOTIC,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_WATER_PULSE, MOVE_TOXIC, MOVE_RECOVER, MOVE_DRAGON_BREATH},
        .nature = NATURE_BOLD,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_SCYTHER,
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_AERIAL_ACE, MOVE_QUICK_ATTACK, MOVE_FURY_CUTTER, MOVE_BRICK_BREAK},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_CHARIZARD,
        .heldItem = ITEM_CHARCOAL,
        .moves = {MOVE_FLAMETHROWER, MOVE_WING_ATTACK, MOVE_SMOKESCREEN, MOVE_DRAGON_BREATH},
        .nature = NATURE_RASH,
        .abilitySlot = 1,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_BlackBeltDaisuke[] = {
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_SKARMORY,
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_DRILL_PECK, MOVE_STEEL_WING, MOVE_ROCK_SLIDE, MOVE_SPIKES},
        .nature = NATURE_CAREFUL,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_PRIMEAPE,
        .heldItem = ITEM_SILK_SCARF,
        .moves = {MOVE_THRASH, MOVE_BRICK_BREAK, MOVE_BULK_UP, MOVE_STRENGTH},
        .nature = NATURE_ADAMANT,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_MACHAMP,
        .heldItem = ITEM_BLACK_BELT,
        .moves = {MOVE_CROSS_CHOP, MOVE_STRENGTH, MOVE_EARTHQUAKE, MOVE_SMELLING_SALT},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_JugglerNelson[] = {
    {
        .iv = 15,
        .lvl = 52,
        .species = SPECIES_HYPNO,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH},
        .nature = NATURE_QUIRKY,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 52,
        .species = SPECIES_DONPHAN,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_EARTHQUAKE, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 52,
        .species = SPECIES_ALAKAZAM,
        .heldItem = ITEM_LUM_BERRY,
        .moves = {MOVE_PSYBEAM, MOVE_CALM_MIND, MOVE_SHOCK_WAVE, MOVE_TAUNT},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_FARFETCHD,
        .heldItem = ITEM_STICK,
        .moves = {MOVE_SLASH, MOVE_CUT, MOVE_CROSS_CHOP, MOVE_AIR_CUTTER},
        .nature = NATURE_ADAMANT,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_TamerVincent[] = {
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_PERSIAN,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CUT, MOVE_DOUBLE_EDGE, MOVE_PAY_DAY, MOVE_FAKE_OUT},
        .nature = NATURE_DOCILE,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_GOLDUCK,
        .heldItem = ITEM_MYSTIC_WATER,
        .moves = {MOVE_SURF, MOVE_STRENGTH, MOVE_ROCK_SMASH, MOVE_FLASH},
        .nature = NATURE_DOCILE,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_MIGHTYENA,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BITE, MOVE_DIG, MOVE_TAKE_DOWN, MOVE_THIEF},
        .nature = NATURE_DOCILE,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_NOCTOWL,
        .heldItem = ITEM_SILK_SCARF,
        .moves = {MOVE_PSYBEAM, MOVE_DOUBLE_EDGE, MOVE_WING_ATTACK, MOVE_FLY},
        .nature = NATURE_DOCILE,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_JugglerGregory[] = {
    {
        .iv = 15,
        .lvl = 54,
        .species = SPECIES_MR_MIME,
        .heldItem = ITEM_PERSIM_BERRY,
        .moves = {MOVE_PSYCHIC, MOVE_ROLE_PLAY, MOVE_DOUBLE_SLAP, MOVE_ENCORE},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 54,
        .species = SPECIES_LUDICOLO,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_FAKE_OUT, MOVE_RAIN_DANCE, MOVE_SURF, MOVE_GIGA_DRAIN},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 54,
        .species = SPECIES_ARCANINE,
        .heldItem = ITEM_CHARCOAL,
        .moves = {MOVE_FIRE_BLAST, MOVE_EXTREME_SPEED, MOVE_FIRE_SPIN, MOVE_ROCK_SMASH},
        .nature = NATURE_NAUGHTY,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 54,
        .species = SPECIES_EXEGGUTOR,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_SUNNY_DAY, MOVE_GIGA_DRAIN, MOVE_PSYCHIC, MOVE_SHADOW_BALL},
        .nature = NATURE_QUIET,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_CooltrainerGeorge[] = {
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_RAICHU,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_THUNDERBOLT, MOVE_AGILITY, MOVE_SURF, MOVE_THIEF},
        .nature = NATURE_MODEST,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_PINSIR,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_PIN_MISSILE, MOVE_STRENGTH, MOVE_BRICK_BREAK, MOVE_SWORDS_DANCE},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_CLOYSTER,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_ICICLE_SPEAR, MOVE_WATER_PULSE, MOVE_FACADE, MOVE_PROTECT},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_CRADILY,
        .heldItem = ITEM_SHELL_BELL,
        .moves = {MOVE_GIGA_DRAIN, MOVE_ANCIENT_POWER, MOVE_ACID, MOVE_GROWTH},
        .nature = NATURE_QUIRKY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 53,
        .species = SPECIES_ALTARIA,
        .heldItem = ITEM_LUM_BERRY,
        .moves = {MOVE_EARTHQUAKE, MOVE_DRAGON_CLAW, MOVE_AERIAL_ACE, MOVE_DRAGON_DANCE},
        .nature = NATURE_ADAMANT,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_PokemaniacDawson[] = {
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_XATU,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHIC, MOVE_DRILL_PECK, MOVE_SHADOW_BALL, MOVE_WISH},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_LAPRAS,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_BODY_SLAM, MOVE_CONFUSE_RAY},
        .nature = NATURE_LONELY,
        .abilitySlot = 0,
    },
    {
        .iv = 15,
        .lvl = 52,
        .species = SPECIES_EXPLOUD,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_STOMP, MOVE_STRENGTH, MOVE_EXTRASENSORY, MOVE_FIRE_BLAST},
        .nature = NATURE_SERIOUS,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_CooltrainerAlexa[] = {
    {
        .iv = 20,
        .lvl = 53,
        .species = SPECIES_CLEFABLE,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_MAGICAL_LEAF, MOVE_COSMIC_POWER, MOVE_METEOR_MASH, MOVE_ENCORE},
        .nature = NATURE_CALM,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_DODRIO,
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_TRI_ATTACK, MOVE_DRILL_PECK, MOVE_QUICK_ATTACK, MOVE_PURSUIT},
        .nature = NATURE_NAUGHTY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_KANGASKHAN,
        .heldItem = ITEM_SHELL_BELL,
        .moves = {MOVE_MEGA_PUNCH, MOVE_STRENGTH, MOVE_BITE, MOVE_BRICK_BREAK},
        .nature = NATURE_BRAVE,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_DEWGONG,
        .heldItem = ITEM_CHESTO_BERRY,
        .moves = {MOVE_BLIZZARD, MOVE_WATER_PULSE, MOVE_REST, MOVE_AURORA_BEAM},
        .nature = NATURE_TIMID,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 54,
        .species = SPECIES_MANECTRIC,
        .heldItem = ITEM_PERSIM_BERRY,
        .moves = {MOVE_THUNDER, MOVE_FLAMETHROWER, MOVE_IRON_TAIL, MOVE_FLASH},
        .nature = NATURE_MILD,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_CooltrainerColby[] = {
    {
        .iv = 20,
        .lvl = 51,
        .species = SPECIES_KINGLER,
        .heldItem = ITEM_MYSTIC_WATER,
        .moves = {MOVE_GUILLOTINE, MOVE_STOMP, MOVE_MUD_SHOT, MOVE_BUBBLE_BEAM},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_CHANSEY,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_THUNDER_WAVE, MOVE_SEISMIC_TOSS, MOVE_ICE_BEAM, MOVE_SOFT_BOILED},
        .nature = NATURE_BOLD,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 53,
        .species = SPECIES_TENTACRUEL,
        .heldItem = ITEM_SHELL_BELL,
        .moves = {MOVE_GIGA_DRAIN, MOVE_TOXIC, MOVE_BUBBLE_BEAM, MOVE_SLUDGE_BOMB},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_KINGDRA,
        .heldItem = ITEM_CHESTO_BERRY,
        .moves = {MOVE_SURF, MOVE_DRAGON_BREATH, MOVE_REST, MOVE_RAIN_DANCE},
        .nature = NATURE_MODEST,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 53,
        .species = SPECIES_GARDEVOIR,
        .heldItem = ITEM_TWISTED_SPOON,
        .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_MAGICAL_LEAF, MOVE_SHOCK_WAVE},
        .nature = NATURE_TIMID,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_CooltrainerCaroline[] = {
    {
        .iv = 20,
        .lvl = 53,
        .species = SPECIES_SWELLOW,
        .heldItem = ITEM_SILK_SCARF,
        .moves = {MOVE_FACADE, MOVE_AERIAL_ACE, MOVE_QUICK_ATTACK, MOVE_STEEL_WING},
        .nature = NATURE_JOLLY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 54,
        .species = SPECIES_ELECTRODE,
        .heldItem = ITEM_MAGNET,
        .moves = {MOVE_THUNDERBOLT, MOVE_LIGHT_SCREEN, MOVE_HIDDEN_POWER, MOVE_EXPLOSION},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_VICTREEBEL,
        .heldItem = ITEM_SCOPE_LENS,
        .moves = {MOVE_RAZOR_LEAF, MOVE_SLUDGE_BOMB, MOVE_STUN_SPORE, MOVE_SLEEP_POWDER},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 52,
        .species = SPECIES_NINETALES,
        .heldItem = ITEM_BERRY_JUICE,
        .moves = {MOVE_FLAMETHROWER, MOVE_PSYCHIC, MOVE_SAFEGUARD, MOVE_WILL_O_WISP},
        .nature = NATURE_MODEST,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 54,
        .species = SPECIES_DUGTRIO,
        .heldItem = ITEM_SOFT_SAND,
        .moves = {MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_FAINT_ATTACK, MOVE_ROCK_SLIDE},
        .nature = NATURE_ADAMANT,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_CoolCoupleRayTyra[] = {
    {
        .iv = 20,
        .lvl = 55,
        .species = SPECIES_NIDOQUEEN,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SUPERPOWER, MOVE_BODY_SLAM, MOVE_DOUBLE_KICK, MOVE_PROTECT},
        .nature = NATURE_IMPISH,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 55,
        .species = SPECIES_NIDOKING,
        .heldItem = ITEM_SOFT_SAND,
        .moves = {MOVE_MEGAHORN, MOVE_THRASH, MOVE_DOUBLE_KICK, MOVE_BULLDOZE},
        .nature = NATURE_ADAMANT,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 55,
        .species = SPECIES_GYARADOS,
        .heldItem = ITEM_LUM_BERRY,
        .moves = {MOVE_CRUNCH, MOVE_BODY_SLAM, MOVE_BOUNCE, MOVE_DRAGON_DANCE},
        .nature = NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 20,
        .lvl = 55,
        .species = SPECIES_HOUNDOOM,
        .heldItem = ITEM_BLACK_GLASSES,
        .moves = {MOVE_FIRE_BLAST, MOVE_SLUDGE_BOMB, MOVE_FAINT_ATTACK, MOVE_QUICK_ATTACK},
        .nature = NATURE_HARDY,
        .abilitySlot = 1,
    },
};


// ======================================================================================= //
// ==================================== Indigo League ==================================== //
// ======================================== E4-1 ========================================= //
static const struct TrainerMonItemCustomMovesNatureAbility sParty_EliteFourLorelei[] = {
    {
        .iv = 30,
        .lvl = 61,
        .species = SPECIES_DEWGONG,
        .heldItem = ITEM_MYSTIC_WATER,
        .moves = {MOVE_BLIZZARD, MOVE_SURF, MOVE_BODY_SLAM, MOVE_SAFEGUARD},
        .nature =  NATURE_BASHFUL,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 60,
        .species = SPECIES_PILOSWINE,
        .heldItem = ITEM_SOFT_SAND,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICICLE_SPEAR, MOVE_BULLDOZE, MOVE_ROCK_SLIDE},
        .nature =  NATURE_JOLLY,
        .abilitySlot = 1,
    },
    {
        .iv = 30,
        .lvl = 61,
        .species = SPECIES_CASTFORM,
        .heldItem = ITEM_SHELL_BELL,
        .moves = {MOVE_WEATHER_BALL, MOVE_HAIL, MOVE_RAIN_DANCE, MOVE_BLIZZARD},
        .nature =  NATURE_MODEST,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 62,
        .species = SPECIES_JYNX,
        .heldItem = ITEM_NEVER_MELT_ICE,
        .moves = {MOVE_ICE_BEAM, MOVE_PSYCHIC, MOVE_LOVELY_KISS, MOVE_ATTRACT},
        .nature =  NATURE_TIMID,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 62,
        .species = SPECIES_LAPRAS,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_BLIZZARD, MOVE_CONFUSE_RAY, MOVE_SURF, MOVE_BODY_SLAM},
        .nature =  NATURE_QUIRKY,
        .abilitySlot = 1,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_EliteFourLorelei2[] = {
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_DEWGONG,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ICE_BEAM, MOVE_SURF, MOVE_SIGNAL_BEAM, MOVE_DOUBLE_TEAM},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 75,
        .species = SPECIES_CLOYSTER,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_ICICLE_SPEAR, MOVE_PROTECT, MOVE_BUBBLE_BEAM, MOVE_SPIKES},
        .nature =  NATURE_SASSY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_PILOSWINE,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BLIZZARD, MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE, MOVE_ROCK_SLIDE},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_JYNX,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ICE_BEAM, MOVE_PSYCHIC, MOVE_LOVELY_KISS, MOVE_ATTRACT},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_LAPRAS,
        .heldItem = ITEM_CHERI_BERRY,
        .moves = {MOVE_ICE_BEAM, MOVE_SURF, MOVE_PSYCHIC, MOVE_THUNDER},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
};

// ======================================== E4-2 ========================================= //
static const struct TrainerMonItemCustomMovesNatureAbility sParty_EliteFourBruno[] = {
    {
        .iv = 30,
        .lvl = 61,
        .species = SPECIES_ONIX,
        .heldItem = ITEM_HARD_STONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_TOMB, MOVE_DRAGON_BREATH, MOVE_ROAR},
        .nature =  NATURE_CAREFUL,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 62,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
        .moves = {MOVE_SKY_UPPERCUT, MOVE_MACH_PUNCH, MOVE_ROCK_TOMB, MOVE_BULK_UP},
        .nature =  NATURE_ADAMANT,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 61,
        .species = SPECIES_SCIZOR,
        .heldItem = ITEM_LUM_BERRY,
        .moves = {MOVE_STEEL_WING, MOVE_STRENGTH, MOVE_QUICK_ATTACK, MOVE_SWORDS_DANCE},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 63,
        .species = SPECIES_BLAZIKEN,
        .heldItem = ITEM_CHARCOAL,
        .moves = {MOVE_OVERHEAT, MOVE_BRICK_BREAK, MOVE_ROCK_SLIDE, MOVE_BLAZE_KICK},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 64,
        .species = SPECIES_MACHAMP,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_CROSS_CHOP, MOVE_BULK_UP, MOVE_EARTHQUAKE, MOVE_STRENGTH},
        .nature =  NATURE_IMPISH,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_EliteFourBruno2[] = {
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_STEELIX,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_TAIL, MOVE_CRUNCH, MOVE_ROCK_TOMB},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SKY_UPPERCUT, MOVE_MACH_PUNCH, MOVE_ROCK_SLIDE, MOVE_COUNTER},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_HITMONLEE,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MEGA_KICK, MOVE_FORESIGHT, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_STEELIX,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_TAIL, MOVE_CRUNCH, MOVE_DRAGON_BREATH},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_MACHAMP,
        .heldItem = ITEM_PERSIM_BERRY,
        .moves = {MOVE_CROSS_CHOP, MOVE_EARTHQUAKE, MOVE_BRICK_BREAK, MOVE_ROCK_SLIDE},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
};

// ======================================== E4-3 ========================================= //
static const struct TrainerMonItemCustomMovesNatureAbility sParty_EliteFourAgatha[] = {
    {
        .iv = 30,
        .lvl = 62,
        .species = SPECIES_BANETTE,
        .heldItem = ITEM_BLACK_GLASSES,
        .moves = {MOVE_FAINT_ATTACK, MOVE_KNOCK_OFF, MOVE_CURSE, MOVE_WILL_O_WISP},
        .nature =  NATURE_ADAMANT,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 63,
        .species = SPECIES_SABLEYE,
        .heldItem = ITEM_SCOPE_LENS,
        .moves = {MOVE_HYPNOSIS, MOVE_DREAM_EATER, MOVE_SHADOW_BALL, MOVE_WATER_PULSE},
        .nature =  NATURE_MODEST,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 62,
        .species = SPECIES_DUSCLOPS,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SHADOW_PUNCH, MOVE_PURSUIT, MOVE_DISABLE, MOVE_PAIN_SPLIT},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 65,
        .species = SPECIES_ARBOK,
        .heldItem = ITEM_POISON_BARB,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_CRUNCH, MOVE_IRON_TAIL, MOVE_GLARE},
        .nature =  NATURE_JOLLY,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 66,
        .species = SPECIES_GENGAR,
        .heldItem = ITEM_SPELL_TAG,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_BOMB, MOVE_THUNDERBOLT, MOVE_HYPNOSIS},
        .nature =  NATURE_RASH,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_EliteFourAgatha2[] = {
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_GENGAR,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOW_BALL, MOVE_PSYCHIC, MOVE_CONFUSE_RAY, MOVE_HYPNOSIS},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_CROBAT,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_AIR_CUTTER, MOVE_SHADOW_BALL, MOVE_CONFUSE_RAY},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_MISDREAVUS,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOW_BALL, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ATTRACT},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_ARBOK,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_GIGA_DRAIN, MOVE_DOUBLE_TEAM},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_GENGAR,
        .heldItem = ITEM_CHESTO_BERRY,
        .moves = {MOVE_SHADOW_BALL, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_SLUDGE_BOMB},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
};

// ======================================== E4-4 ========================================= //
static const struct TrainerMonItemCustomMovesNatureAbility sParty_EliteFourLance[] = {
    {
        .iv = 30,
        .lvl = 62,
        .species = SPECIES_LATIAS,
        .heldItem = ITEM_SOUL_DEW,
        .moves = {MOVE_DRAGON_BREATH, MOVE_SURF, MOVE_CHARM, MOVE_RECOVER},
        .nature =  NATURE_TIMID,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 62,
        .species = SPECIES_LATIOS,
        .heldItem = ITEM_SOUL_ORB,
        .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_DRAGON_CLAW, MOVE_SHADOW_BALL},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 63,
        .species = SPECIES_GYARADOS,
        .heldItem = ITEM_LUM_BERRY,
        .moves = {MOVE_EARTHQUAKE, MOVE_WATERFALL, MOVE_HYPER_BEAM, MOVE_DRAGON_DANCE},
        .nature =  NATURE_LONELY,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 63,
        .species = SPECIES_SALAMENCE,
        .heldItem = ITEM_DRAGON_FANG,
        .moves = {MOVE_DRAGON_CLAW, MOVE_FLAMETHROWER, MOVE_FLY, MOVE_CRUNCH},
        .nature =  NATURE_SERIOUS,
        .abilitySlot = 0,
    },
    {
        .iv = 30,
        .lvl = 65,
        .species = SPECIES_AERODACTYL,
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER, MOVE_WING_ATTACK, MOVE_SCARY_FACE},
        .nature =  NATURE_IMPISH,
        .abilitySlot = 1,
    },
    {
        .iv = 30,
        .lvl = 67,
        .species = SPECIES_DRAGONITE,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_SAFEGUARD, MOVE_OUTRAGE, MOVE_WING_ATTACK},
        .nature =  NATURE_JOLLY,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_EliteFourLance2[] = {
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_LATIAS,
        .heldItem = ITEM_SOUL_DEW,
        .moves = {MOVE_HYPER_BEAM, MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE, MOVE_THUNDER_WAVE},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_LATIOS,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPER_BEAM, MOVE_EARTHQUAKE, MOVE_DRAGON_CLAW, MOVE_FLAMETHROWER},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_KINGDRA,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPER_BEAM, MOVE_DRAGON_DANCE, MOVE_SURF, MOVE_ICE_BEAM},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_AERODACTYL,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPER_BEAM, MOVE_ANCIENT_POWER, MOVE_AERIAL_ACE, MOVE_EARTHQUAKE},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_DRAGONITE,
        .heldItem = ITEM_PERSIM_BERRY,
        .moves = {MOVE_HYPER_BEAM, MOVE_OUTRAGE, MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
};

// ====================================== CHAMPION ======================================= //
static const struct TrainerMonItemCustomMovesNatureAbility sParty_ChampionFirstSquirtle[] = {
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 65,
        .species = SPECIES_ZAPDOS,
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_DRILL_PECK, MOVE_LIGHT_SCREEN, MOVE_THUNDER, MOVE_THUNDER_WAVE},
        .nature =  NATURE_SERIOUS,
        .abilitySlot = 1,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 66,
        .species = SPECIES_EXEGGUTOR,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_PSYCHIC, MOVE_SOLAR_BEAM, MOVE_GIGA_DRAIN, MOVE_SUNNY_DAY},
        .nature =  NATURE_BOLD,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 64,
        .species = SPECIES_SNORLAX,
        .heldItem = ITEM_CHESTO_BERRY,
        .moves = {MOVE_ROCK_SLIDE, MOVE_BODY_SLAM, MOVE_BRICK_BREAK, MOVE_REST},
        .nature =  NATURE_IMPISH,
        .abilitySlot = 1,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 63,
        .species = SPECIES_ENTEI,
        .heldItem = ITEM_CHARCOAL,
        .moves = {MOVE_EXTREME_SPEED, MOVE_SACRED_FIRE, MOVE_ROAR, MOVE_BITE},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 65,
        .species = SPECIES_HERACROSS,
        .heldItem = ITEM_BLACK_BELT,
        .moves = {MOVE_SKY_UPPERCUT, MOVE_MEGAHORN, MOVE_AERIAL_ACE, MOVE_STRENGTH},
        .nature =  NATURE_JOLLY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 68,
        .species = SPECIES_BLASTOISE,
        .heldItem = ITEM_SHELL_BELL,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_SKULL_BASH, MOVE_RAIN_DANCE},
        .nature =  NATURE_HARDY,
        .abilitySlot = 1,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_ChampionFirstBulbasaur[] = {
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 65,
        .species = SPECIES_MOLTRES,
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_DRILL_PECK, MOVE_STEEL_WING, MOVE_FLAMETHROWER, MOVE_SOLAR_BEAM},
        .nature =  NATURE_SERIOUS,
        .abilitySlot = 1,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 66,
        .species = SPECIES_ALAKAZAM,
        .heldItem = ITEM_TWISTED_SPOON,
        .moves = {MOVE_PSYCHIC, MOVE_SHOCK_WAVE, MOVE_CALM_MIND, MOVE_SHADOW_BALL},
        .nature =  NATURE_MODEST,
        .abilitySlot = 1,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 64,
        .species = SPECIES_SNORLAX,
        .heldItem = ITEM_CHESTO_BERRY,
        .moves = {MOVE_ROCK_SLIDE, MOVE_BODY_SLAM, MOVE_BRICK_BREAK, MOVE_REST},
        .nature =  NATURE_IMPISH,
        .abilitySlot = 1,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 63,
        .species = SPECIES_SUICUNE,
        .heldItem = ITEM_MYSTIC_WATER,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_BITE},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 65,
        .species = SPECIES_ARCANINE,
        .heldItem = ITEM_SILK_SCARF,
        .moves = {MOVE_EXTREME_SPEED, MOVE_FLAMETHROWER, MOVE_ROAR, MOVE_BITE},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 68,
        .species = SPECIES_VENUSAUR,
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_GROWTH},
        .nature =  NATURE_HARDY,
        .abilitySlot = 1,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_ChampionFirstCharmander[] = {
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 65,
        .species = SPECIES_ARTICUNO,
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_DRILL_PECK, MOVE_REFLECT, MOVE_WATER_PULSE, MOVE_BLIZZARD},
        .nature =  NATURE_SERIOUS,
        .abilitySlot = 1,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 66,
        .species = SPECIES_EXEGGUTOR,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_PSYCHIC, MOVE_SOLAR_BEAM, MOVE_GIGA_DRAIN, MOVE_SUNNY_DAY},
        .nature =  NATURE_BOLD,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 64,
        .species = SPECIES_SNORLAX,
        .heldItem = ITEM_CHESTO_BERRY,
        .moves = {MOVE_ROCK_SLIDE, MOVE_BODY_SLAM, MOVE_BRICK_BREAK, MOVE_REST},
        .nature =  NATURE_IMPISH,
        .abilitySlot = 1,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 63,
        .species = SPECIES_RAIKOU,
        .heldItem = ITEM_MAGNET,
        .moves = {MOVE_THUNDERBOLT, MOVE_QUICK_ATTACK, MOVE_ROAR, MOVE_CRUNCH},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 65,
        .species = SPECIES_GYARADOS,
        .heldItem = ITEM_LUM_BERRY,
        .moves = {MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_THRASH},
        .nature =  NATURE_NAUGHTY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 68,
        .species = SPECIES_CHARIZARD,
        .heldItem = ITEM_SCOPE_LENS,
        .moves = {MOVE_FIRE_BLAST, MOVE_AERIAL_ACE, MOVE_DRAGON_BREATH, MOVE_STEEL_WING},
        .nature =  NATURE_HARDY,
        .abilitySlot = 1,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_ChampionRematchSquirtle[] = {
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 72,
        .species = SPECIES_HERACROSS,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_COUNTER, MOVE_ROCK_TOMB},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 73,
        .species = SPECIES_ALAKAZAM,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_CALM_MIND, MOVE_REFLECT},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 72,
        .species = SPECIES_TYRANITAR,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_THUNDERBOLT, MOVE_AERIAL_ACE},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 73,
        .species = SPECIES_ARCANINE,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EXTREME_SPEED, MOVE_OVERHEAT, MOVE_AERIAL_ACE, MOVE_IRON_TAIL},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 73,
        .species = SPECIES_EXEGGUTOR,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GIGA_DRAIN, MOVE_PSYCHIC, MOVE_SLEEP_POWDER, MOVE_LIGHT_SCREEN},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_BLASTOISE,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_EARTHQUAKE, MOVE_RAIN_DANCE},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_ChampionRematchBulbasaur[] = {
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 72,
        .species = SPECIES_HERACROSS,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_COUNTER, MOVE_ROCK_TOMB},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 73,
        .species = SPECIES_ALAKAZAM,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_CALM_MIND, MOVE_REFLECT},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 72,
        .species = SPECIES_TYRANITAR,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_THUNDERBOLT, MOVE_AERIAL_ACE},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 73,
        .species = SPECIES_GYARADOS,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE, MOVE_HYPER_BEAM},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 73,
        .species = SPECIES_ARCANINE,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EXTREME_SPEED, MOVE_OVERHEAT, MOVE_AERIAL_ACE, MOVE_IRON_TAIL},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_VENUSAUR,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_SUNNY_DAY},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
};

static const struct TrainerMonItemCustomMovesNatureAbility sParty_ChampionRematchCharmander[] = {
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 72,
        .species = SPECIES_HERACROSS,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_COUNTER, MOVE_ROCK_TOMB},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 73,
        .species = SPECIES_ALAKAZAM,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_CALM_MIND, MOVE_REFLECT},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 72,
        .species = SPECIES_TYRANITAR,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_THUNDERBOLT, MOVE_AERIAL_ACE},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 73,
        .species = SPECIES_EXEGGUTOR,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GIGA_DRAIN, MOVE_PSYCHIC, MOVE_SLEEP_POWDER, MOVE_LIGHT_SCREEN},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 73,
        .species = SPECIES_GYARADOS,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE, MOVE_HYPER_BEAM},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
    {
        .iv = MAX_PER_STAT_IVS,
        .lvl = 75,
        .species = SPECIES_CHARIZARD,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_FIRE_BLAST, MOVE_DRAGON_CLAW, MOVE_AERIAL_ACE, MOVE_EARTHQUAKE},
        .nature =  NATURE_HARDY,
        .abilitySlot = 0,
    },
};





































































static const struct TrainerMonNoItemDefaultMoves sParty_CueBallChase[] = {
    {
        .iv = 15,
        .lvl = 31,
        .species = SPECIES_TENTACOOL,
    },
    {
        .iv = 15,
        .lvl = 31,
        .species = SPECIES_TENTACOOL,
    },
    {
        .iv = 15,
        .lvl = 31,
        .species = SPECIES_TENTACRUEL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BeautyLauren[] = {
    {
        .iv = 15,
        .lvl = 33,
        .species = SPECIES_WEEPINBELL,
    },
    {
        .iv = 15,
        .lvl = 33,
        .species = SPECIES_BELLSPROUT,
    },
    {
        .iv = 15,
        .lvl = 33,
        .species = SPECIES_WEEPINBELL,
    },
};







static const struct TrainerMonNoItemDefaultMoves sParty_RockerRandall[] = {
    {
        .iv = 15,
        .lvl = 20,
        .species = SPECIES_VOLTORB,
    },
    {
        .iv = 15,
        .lvl = 20,
        .species = SPECIES_MAGNEMITE,
    },
    {
        .iv = 15,
        .lvl = 20,
        .species = SPECIES_VOLTORB,
    },
};





static const struct TrainerMonNoItemCustomMoves sParty_JugglerEdward[] = {
    {
        .iv = 15,
        .lvl = 46,
        .species = SPECIES_VOLTORB,
        .moves = {MOVE_SWIFT, MOVE_LIGHT_SCREEN, MOVE_SPARK, MOVE_SONIC_BOOM},
    },
    {
        .iv = 15,
        .lvl = 46,
        .species = SPECIES_VOLTORB,
        .moves = {MOVE_SWIFT, MOVE_LIGHT_SCREEN, MOVE_SPARK, MOVE_SONIC_BOOM},
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_SWIFT, MOVE_SPARK, MOVE_SELF_DESTRUCT, MOVE_SONIC_BOOM},
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_MR_MIME,
        .moves = {MOVE_PSYCHIC, MOVE_ROLE_PLAY, MOVE_REFLECT, MOVE_ENCORE},
    },
};



static const struct TrainerMonNoItemDefaultMoves sParty_TamerJohn[] = {
    {
        .iv = 15,
        .lvl = 42,
        .species = SPECIES_RHYHORN,
    },
    {
        .iv = 15,
        .lvl = 42,
        .species = SPECIES_PRIMEAPE,
    },
    {
        .iv = 15,
        .lvl = 42,
        .species = SPECIES_ARBOK,
    },
    {
        .iv = 15,
        .lvl = 42,
        .species = SPECIES_TAUROS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperReed[] = {
    {
        .iv = 15,
        .lvl = 39,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .iv = 15,
        .lvl = 39,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .iv = 15,
        .lvl = 39,
        .species = SPECIES_PIDGEY,
    },
    {
        .iv = 15,
        .lvl = 39,
        .species = SPECIES_PIDGEOTTO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperKeith[] = {
    {
        .iv = 15,
        .lvl = 39,
        .species = SPECIES_FARFETCHD,
    },
    {
        .iv = 15,
        .lvl = 39,
        .species = SPECIES_FEAROW,
    },
};





static const struct TrainerMonNoItemCustomMoves sParty_CooltrainerPaul[] = {
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_SLOWPOKE,
        .moves = {MOVE_HEADBUTT, MOVE_CONFUSION, MOVE_WATER_GUN, MOVE_DISABLE},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_SHELLDER,
        .moves = {MOVE_AURORA_BEAM, MOVE_CLAMP, MOVE_SUPERSONIC, MOVE_LEER},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_KINGLER,
        .moves = {MOVE_GUILLOTINE, MOVE_STOMP, MOVE_MUD_SHOT, MOVE_BUBBLE},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_STARMIE,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_SWIFT, MOVE_RECOVER, MOVE_RAPID_SPIN},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_CONFUSION, MOVE_SCRATCH, MOVE_SCREECH, MOVE_DISABLE},
    },
};



static const struct TrainerMonNoItemCustomMoves sParty_CooltrainerGilbert[] = {
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_PIDGEOTTO,
        .moves = {MOVE_WING_ATTACK, MOVE_FEATHER_DANCE, MOVE_WHIRLWIND, MOVE_QUICK_ATTACK},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_FEAROW,
        .moves = {MOVE_DRILL_PECK, MOVE_MIRROR_MOVE, MOVE_PURSUIT, MOVE_LEER},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_PAY_DAY, MOVE_FAINT_ATTACK, MOVE_SCREECH, MOVE_BITE},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_LICKITUNG,
        .moves = {MOVE_SLAM, MOVE_DISABLE, MOVE_WRAP, MOVE_SUPERSONIC},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_TAUROS,
        .moves = {MOVE_HORN_ATTACK, MOVE_SCARY_FACE, MOVE_SWAGGER, MOVE_TAIL_WHIP},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_CooltrainerOwen[] = {
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_NIDORINO,
        .moves = {MOVE_SCRATCH, MOVE_POISON_STING, MOVE_DOUBLE_KICK, MOVE_BITE},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_NIDORINA,
        .moves = {MOVE_HORN_ATTACK, MOVE_POISON_STING, MOVE_DOUBLE_KICK, MOVE_LEER},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_RATICATE,
        .moves = {MOVE_SUPER_FANG, MOVE_PURSUIT, MOVE_SCARY_FACE, MOVE_QUICK_ATTACK},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_SANDSLASH,
        .moves = {MOVE_FURY_SWIPES, MOVE_SWIFT, MOVE_SLASH, MOVE_POISON_STING},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_RHYHORN,
        .moves = {MOVE_ROCK_BLAST, MOVE_SCARY_FACE, MOVE_STOMP, MOVE_TAIL_WHIP},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_CooltrainerBerke[] = {
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_SEEL,
        .moves = {MOVE_TAKE_DOWN, MOVE_AURORA_BEAM, MOVE_ICY_WIND, MOVE_GROWL},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_GRAVELER,
        .moves = {MOVE_ROCK_BLAST, MOVE_MAGNITUDE, MOVE_ROCK_THROW, MOVE_MUD_SPORT},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_KINGLER,
        .moves = {MOVE_GUILLOTINE, MOVE_STOMP, MOVE_MUD_SHOT, MOVE_BUBBLE},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_ONIX,
        .moves = {MOVE_SLAM, MOVE_SANDSTORM, MOVE_DRAGON_BREATH, MOVE_ROCK_THROW},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_CLOYSTER,
        .moves = {MOVE_SPIKE_CANNON, MOVE_AURORA_BEAM, MOVE_SUPERSONIC, MOVE_PROTECT},
    },
};





static const struct TrainerMonNoItemCustomMoves sParty_CooltrainerShannon[] = {
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_BEEDRILL,
        .moves = {MOVE_PIN_MISSILE, MOVE_TWINEEDLE, MOVE_AGILITY, MOVE_PURSUIT},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_BUTTERFREE,
        .moves = {MOVE_SAFEGUARD, MOVE_PSYBEAM, MOVE_GUST, MOVE_SUPERSONIC},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_PARASECT,
        .moves = {MOVE_SPORE, MOVE_LEECH_LIFE, MOVE_SLASH, MOVE_GROWTH},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_VENONAT,
        .moves = {MOVE_PSYBEAM, MOVE_STUN_SPORE, MOVE_LEECH_LIFE, MOVE_DISABLE},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_VENOMOTH,
        .moves = {MOVE_PSYBEAM, MOVE_GUST, MOVE_SUPERSONIC, MOVE_LEECH_LIFE},
    },
};



static const struct TrainerMonNoItemCustomMoves sParty_CooltrainerBrooke[] = {
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_TANGELA,
        .moves = {MOVE_SLAM, MOVE_BIND, MOVE_MEGA_DRAIN, MOVE_INGRAIN},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_GLOOM,
        .moves = {MOVE_ACID, MOVE_MOONLIGHT, MOVE_SLEEP_POWDER, MOVE_STUN_SPORE},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_MEGA_DRAIN, MOVE_ACID, MOVE_STUN_SPORE, MOVE_AROMATHERAPY},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_IVYSAUR,
        .moves = {MOVE_RAZOR_LEAF, MOVE_SWEET_SCENT, MOVE_GROWL, MOVE_LEECH_SEED},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_RAZOR_LEAF, MOVE_GROWTH, MOVE_SLEEP_POWDER, MOVE_POISON_POWDER},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_CooltrainerAustina[] = {
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_RHYHORN,
        .moves = {MOVE_HORN_DRILL, MOVE_ROCK_BLAST, MOVE_SCARY_FACE, MOVE_STOMP},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_NIDORINA,
        .moves = {MOVE_DOUBLE_KICK, MOVE_FURY_SWIPES, MOVE_BITE, MOVE_FLATTER},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_BODY_SLAM, MOVE_DOUBLE_KICK, MOVE_BITE, MOVE_GROWL},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_NIDORINO,
        .moves = {MOVE_HORN_ATTACK, MOVE_POISON_STING, MOVE_FOCUS_ENERGY, MOVE_LEER},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_THRASH, MOVE_DOUBLE_KICK, MOVE_POISON_STING, MOVE_PECK},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_CooltrainerJulie[] = {
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_FURY_SWIPES, MOVE_BITE, MOVE_SCREECH, MOVE_FAINT_ATTACK},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_NINETALES,
        .moves = {MOVE_FLAMETHROWER, MOVE_WILL_O_WISP, MOVE_CONFUSE_RAY, MOVE_GRUDGE},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_FURY_ATTACK, MOVE_FIRE_SPIN, MOVE_TAKE_DOWN, MOVE_AGILITY},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_PIKACHU,
        .moves = {MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_DOUBLE_TEAM, MOVE_QUICK_ATTACK},
    },
    {
        .iv = 20,
        .lvl = 42,
        .species = SPECIES_RAICHU,
        .moves = {MOVE_THUNDER, MOVE_THUNDER_WAVE, MOVE_SLAM, MOVE_DOUBLE_TEAM},
    },
};










static const struct TrainerMonNoItemDefaultMoves sParty_GentlemanNorton[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_PERSIAN,
    },
};



static const struct TrainerMonNoItemDefaultMoves sParty_Channeler1[] = {
    {
        .iv = 15,
        .lvl = 23,
        .species = SPECIES_HAUNTER,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_Channeler2[] = {
    {
        .iv = 15,
        .lvl = 24,
        .species = SPECIES_GASTLY,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_Channeler3[] = {
    {
        .iv = 15,
        .lvl = 22,
        .species = SPECIES_GASTLY,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_Channeler4[] = {
    {
        .iv = 15,
        .lvl = 24,
        .species = SPECIES_GASTLY,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_Channeler5[] = {
    {
        .iv = 15,
        .lvl = 22,
        .species = SPECIES_HAUNTER,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_Channeler6[] = {
    {
        .iv = 15,
        .lvl = 22,
        .species = SPECIES_GASTLY,
    },
    {
        .iv = 15,
        .lvl = 22,
        .species = SPECIES_GASTLY,
    },
    {
        .iv = 15,
        .lvl = 22,
        .species = SPECIES_GASTLY,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_Channeler7[] = {
    {
        .iv = 15,
        .lvl = 24,
        .species = SPECIES_GASTLY,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_Channeler8[] = {
    {
        .iv = 15,
        .lvl = 24,
        .species = SPECIES_GASTLY,
    },
};















static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt42[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_HOUNDOUR,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_HOUNDOUR,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PsychicJaclyn[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_NATU,
        .moves = {MOVE_NIGHT_SHADE, MOVE_CONFUSE_RAY, MOVE_FUTURE_SIGHT, MOVE_WISH},
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_PSYCHIC, MOVE_HEADBUTT, MOVE_AMNESIA, MOVE_YAWN},
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_KADABRA,
        .moves = {MOVE_PSYCHIC, MOVE_FUTURE_SIGHT, MOVE_RECOVER, MOVE_REFLECT},
    },
};





static const struct TrainerMonNoItemDefaultMoves sParty_PkmnBreederAlize[] = {
    {
        .iv = 3,
        .lvl = 48,
        .species = SPECIES_PIKACHU,
    },
    {
        .iv = 3,
        .lvl = 48,
        .species = SPECIES_CLEFAIRY,
    },
    {
        .iv = 3,
        .lvl = 48,
        .species = SPECIES_MARILL,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PkmnRangerNicolas[] = {
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_WEEPINBELL,
        .moves = {MOVE_RAZOR_LEAF, MOVE_ACID, MOVE_SWEET_SCENT, MOVE_WRAP},
    },
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_RAZOR_LEAF, MOVE_ACID, MOVE_SLEEP_POWDER, MOVE_STUN_SPORE},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PkmnRangerMadeline[] = {
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_GLOOM,
        .moves = {MOVE_PETAL_DANCE, MOVE_ACID, MOVE_SWEET_SCENT, MOVE_POISON_POWDER},
    },
    {
        .iv = 15,
        .lvl = 51,
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_PETAL_DANCE, MOVE_MOONLIGHT, MOVE_ACID, MOVE_STUN_SPORE},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_RuinManiacStanly[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_GRAVELER,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_ONIX,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_GRAVELER,
    },
};

static const struct TrainerMonItemDefaultMoves sParty_LadyJacki[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_HOPPIP,
        .heldItem = ITEM_STARDUST,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_SKIPLOOM,
        .heldItem = ITEM_STARDUST,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PainterDaisy[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_DIZZY_PUNCH, MOVE_FOCUS_PUNCH, MOVE_MEGA_PUNCH},
    },
};





static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt45[] = {
    {
        .iv = 15,
        .lvl = 38,
        .species = SPECIES_ZUBAT,
    },
    {
        .iv = 15,
        .lvl = 38,
        .species = SPECIES_ZUBAT,
    },
    {
        .iv = 15,
        .lvl = 38,
        .species = SPECIES_GOLBAT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt46[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_MUK,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_GOLBAT,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_RATICATE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt47[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_MACHOP,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_MACHOP,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_MACHOKE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt48[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_HYPNO,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_HYPNO,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_TeamRocketAdmin[] = {
    {
        .iv = 15,
        .lvl = 52,
        .species = SPECIES_MUK,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_SCREECH, MOVE_MINIMIZE, MOVE_ROCK_TOMB},
    },
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_ARBOK,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_BITE, MOVE_EARTHQUAKE, MOVE_IRON_TAIL},
    },
    {
        .iv = 15,
        .lvl = 54,
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN, MOVE_SLEEP_POWDER, MOVE_STUN_SPORE},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_TeamRocketAdmin2[] = {
    {
        .iv = 20,
        .lvl = 53,
        .species = SPECIES_GOLBAT,
        .moves = {MOVE_CONFUSE_RAY, MOVE_SLUDGE_BOMB, MOVE_AIR_CUTTER, MOVE_SHADOW_BALL},
    },
    {
        .iv = 20,
        .lvl = 54,
        .species = SPECIES_WEEZING,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_THUNDERBOLT, MOVE_EXPLOSION, MOVE_SHADOW_BALL},
    },
    {
        .iv = 20,
        .lvl = 55,
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_FLAMETHROWER, MOVE_CRUNCH, MOVE_IRON_TAIL, MOVE_SHADOW_BALL},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_ScientistGideon[] = {
    {
        .iv = 15,
        .lvl = 46,
        .species = SPECIES_VOLTORB,
        .moves = {MOVE_SWIFT, MOVE_SCREECH, MOVE_SPARK, MOVE_SONIC_BOOM},
    },
    {
        .iv = 15,
        .lvl = 46,
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_SPARK, MOVE_SONIC_BOOM, MOVE_SCREECH, MOVE_CHARGE},
    },
    {
        .iv = 15,
        .lvl = 46,
        .species = SPECIES_MAGNEMITE,
        .moves = {MOVE_SCREECH, MOVE_SWIFT, MOVE_SPARK, MOVE_THUNDER_WAVE},
    },
    {
        .iv = 15,
        .lvl = 46,
        .species = SPECIES_MAGNETON,
        .moves = {MOVE_TRI_ATTACK, MOVE_SPARK, MOVE_THUNDER_WAVE, MOVE_SONIC_BOOM},
    },
    {
        .iv = 15,
        .lvl = 46,
        .species = SPECIES_PORYGON,
        .moves = {MOVE_TRI_ATTACK, MOVE_CONVERSION, MOVE_RECOVER, MOVE_PSYBEAM},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PainterCelina[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_FLY, MOVE_DIG, MOVE_DIVE, MOVE_BOUNCE},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PainterRayna[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_CROSS_CHOP, MOVE_MEGAHORN, MOVE_DOUBLE_EDGE, MOVE_SELF_DESTRUCT},
    },
};

static const struct TrainerMonItemDefaultMoves sParty_LadyGillian[] = {
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_MAREEP,
        .heldItem = ITEM_STARDUST,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_MAREEP,
        .heldItem = ITEM_STARDUST,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_FLAAFFY,
        .heldItem = ITEM_NUGGET,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterDestin[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_RATICATE,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_PIDGEOTTO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleToby[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_POLIWHIRL,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_TENTACOOL,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_TENTACRUEL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt49[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_RATTATA,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_GRIMER,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_MUK,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_TeamRocketGrunt50[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_KOFFING,
        .moves = {MOVE_MEMENTO, MOVE_HAZE, MOVE_SMOKESCREEN, MOVE_SLUDGE},
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_WEEZING,
        .moves = {MOVE_HAZE, MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SELF_DESTRUCT},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TeamRocketGrunt51[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_EKANS,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_GLOOM,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_GLOOM,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperMilo[] = {
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_PIDGEY,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_PIDGEOTTO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperChaz[] = {
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_SPEAROW,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperHarold[] = {
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_HOOTHOOT,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_NOCTOWL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_FishermanTylor[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_QWILFISH,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_QWILFISH,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleMymo[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_KINGLER,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_WARTORTLE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleNicole[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_MARILL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SisAndBroAvaGeb[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_POLIWHIRL,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_STARMIE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_AromaLadyRose[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_SUNKERN,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_SUNFLORA,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleSamir[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_GYARADOS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleDenise[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_CHINCHOU,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_LANTURN,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TwinsMiuMia[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_PIKACHU,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_PIKACHU,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_HikerEarl[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_ONIX,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_MACHOKE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_RuinManiacFoster[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_GOLEM,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_RuinManiacLarry[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_MACHOKE,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_MACHOKE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_HikerDaryl[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_SUDOWOODO,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PokemaniacHector[] = {
    {
        .iv = 3,
        .lvl = 49,
        .species = SPECIES_RHYHORN,
    },
    {
        .iv = 3,
        .lvl = 49,
        .species = SPECIES_KANGASKHAN,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PsychicDario[] = {
    {
        .iv = 15,
        .lvl = 52,
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_CRUNCH, MOVE_PSYBEAM, MOVE_ODOR_SLEUTH, MOVE_AGILITY},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PsychicRodette[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_NATU,
        .moves = {MOVE_NIGHT_SHADE, MOVE_CONFUSE_RAY, MOVE_WISH, MOVE_FUTURE_SIGHT},
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_DROWZEE,
        .moves = {MOVE_PSYCHIC, MOVE_DISABLE, MOVE_PSYCH_UP, MOVE_FUTURE_SIGHT},
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_HYPNO,
        .moves = {MOVE_PSYCHIC, MOVE_HYPNOSIS, MOVE_PSYCH_UP, MOVE_FUTURE_SIGHT},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_AromaLadyMiah[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_BELLOSSOM,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_BELLOSSOM,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungCoupleEveJon[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_GOLDUCK,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_PSYDUCK,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_JugglerMason[] = {
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_VOLTORB,
        .moves = {MOVE_SWIFT, MOVE_LIGHT_SCREEN, MOVE_SPARK, MOVE_SONIC_BOOM},
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_PINECO,
        .moves = {MOVE_SPIKES, MOVE_BIDE, MOVE_RAPID_SPIN, MOVE_TAKE_DOWN},
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_VOLTORB,
        .moves = {MOVE_SWIFT, MOVE_LIGHT_SCREEN, MOVE_SPARK, MOVE_SONIC_BOOM},
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_PINECO,
        .moves = {MOVE_SPIKES, MOVE_BIDE, MOVE_RAPID_SPIN, MOVE_EXPLOSION},
    },
};

static const struct TrainerMonItemDefaultMoves sParty_CrushGirlCyndy[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_PRIMEAPE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_HITMONTOP,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_MACHOKE,
        .heldItem = ITEM_BLACK_BELT,
    },
};



static const struct TrainerMonNoItemDefaultMoves sParty_TamerEvan[] = {
    {
        .iv = 4,
        .lvl = 48,
        .species = SPECIES_SANDSLASH,
    },
    {
        .iv = 4,
        .lvl = 48,
        .species = SPECIES_LICKITUNG,
    },
    {
        .iv = 4,
        .lvl = 49,
        .species = SPECIES_URSARING,
    },
};


static const struct TrainerMonNoItemCustomMoves sParty_PkmnRangerJackson[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_TANGELA,
        .moves = {MOVE_SLAM, MOVE_MEGA_DRAIN, MOVE_BIND, MOVE_INGRAIN},
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_EXEGGCUTE,
        .moves = {MOVE_CONFUSION, MOVE_POISON_POWDER, MOVE_BARRAGE, MOVE_REFLECT},
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_CONFUSION, MOVE_EGG_BOMB, MOVE_SLEEP_POWDER, MOVE_STOMP},
    },
};



static const struct TrainerMonNoItemCustomMoves sParty_PkmnRangerKatelyn[] = {
    {
        .iv = 15,
        .lvl = 52,
        .species = SPECIES_CHANSEY,
        .moves = {MOVE_EGG_BOMB, MOVE_DEFENSE_CURL, MOVE_MINIMIZE, MOVE_SOFT_BOILED},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_CooltrainerLeroy[] = {
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_RHYDON,
        .moves = {MOVE_TAKE_DOWN, MOVE_HORN_DRILL, MOVE_ROCK_BLAST, MOVE_SCARY_FACE},
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_PSYCHIC, MOVE_HEADBUTT, MOVE_AMNESIA, MOVE_DISABLE},
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_DIZZY_PUNCH, MOVE_BITE, MOVE_ENDURE, MOVE_REVERSAL},
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_MACHOKE,
        .moves = {MOVE_CROSS_CHOP, MOVE_VITAL_THROW, MOVE_REVENGE, MOVE_SEISMIC_TOSS},
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_URSARING,
        .moves = {MOVE_SLASH, MOVE_FAINT_ATTACK, MOVE_SNORE, MOVE_REST},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_CooltrainerMichelle[] = {
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_SLASH, MOVE_SCREECH, MOVE_FAINT_ATTACK, MOVE_BITE},
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_ICE_BEAM, MOVE_TAKE_DOWN, MOVE_ICY_WIND, MOVE_GROWL},
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_NINETALES,
        .moves = {MOVE_FLAMETHROWER, MOVE_CONFUSE_RAY, MOVE_WILL_O_WISP, MOVE_GRUDGE},
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_BOUNCE, MOVE_AGILITY, MOVE_FIRE_SPIN, MOVE_TAKE_DOWN},
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_CRUNCH, MOVE_PSYBEAM, MOVE_STOMP, MOVE_ODOR_SLEUTH},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_CoolCoupleLexNya[] = {
    {
        .iv = 15,
        .lvl = 52,
        .species = SPECIES_MILTANK,
        .moves = {MOVE_BODY_SLAM, MOVE_MILK_DRINK, MOVE_GROWL, MOVE_DEFENSE_CURL},
    },
    {
        .iv = 15,
        .lvl = 52,
        .species = SPECIES_TAUROS,
        .moves = {MOVE_THRASH, MOVE_HORN_ATTACK, MOVE_PURSUIT, MOVE_SWAGGER},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_RuinManiacBrandon[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_ONIX,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_RuinManiacBenjamin[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_GEODUDE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_BLAST, MOVE_ROLLOUT, MOVE_SELF_DESTRUCT},
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_GRAVELER,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_BLAST, MOVE_ROCK_THROW, MOVE_SELF_DESTRUCT},
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_GRAVELER,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_BLAST, MOVE_ROCK_THROW, MOVE_SELF_DESTRUCT},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PainterEdna[] = {
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_FAKE_OUT, MOVE_EXTREME_SPEED, MOVE_PROTECT, MOVE_QUICK_ATTACK},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_GentlemanClifford[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_MAROWAK,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_GOLDUCK,
    },
};

static const struct TrainerMonItemCustomMoves sParty_LadySelphy[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_PERSIAN,
        .heldItem = ITEM_NUGGET,
        .moves = {MOVE_PAY_DAY, MOVE_BITE, MOVE_TAUNT, MOVE_TORMENT},
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_PERSIAN,
        .heldItem = ITEM_NUGGET,
        .moves = {MOVE_PAY_DAY, MOVE_SCRATCH, MOVE_TORMENT, MOVE_TAUNT},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_RuinManiacLawson[] = {
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_ONIX,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_GRAVELER,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_MAROWAK,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PsychicLaura[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_NATU,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_NATU,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_XATU,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PkmnBreederBethany[] = {
    {
        .iv = 3,
        .lvl = 50,
        .species = SPECIES_CHANSEY,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PkmnBreederAllison[] = {
    {
        .iv = 3,
        .lvl = 48,
        .species = SPECIES_CLEFAIRY,
    },
    {
        .iv = 3,
        .lvl = 48,
        .species = SPECIES_CLEFAIRY,
    },
    {
        .iv = 3,
        .lvl = 48,
        .species = SPECIES_CLEFABLE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherGarret[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_HERACROSS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherJonah[] = {
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_YANMA,
    },
    {
        .iv = 15,
        .lvl = 45,
        .species = SPECIES_BEEDRILL,
    },
    {
        .iv = 15,
        .lvl = 46,
        .species = SPECIES_YANMA,
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_BEEDRILL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BugCatcherVance[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_VENONAT,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_VENOMOTH,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterNash[] = {
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_WEEPINBELL,
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_WEEPINBELL,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_VICTREEBEL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterCordell[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_FARFETCHD,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_FARFETCHD,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassDalia[] = {
    {
        .iv = 15,
        .lvl = 46,
        .species = SPECIES_HOPPIP,
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_HOPPIP,
    },
    {
        .iv = 15,
        .lvl = 47,
        .species = SPECIES_SKIPLOOM,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_SKIPLOOM,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_LassJoana[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_SNUBBULL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_CamperRiley[] = {
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_PINSIR,
    },
    {
        .iv = 15,
        .lvl = 50,
        .species = SPECIES_HERACROSS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PicnickerMarcy[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_PARAS,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_PARAS,
    },
    {
        .iv = 15,
        .lvl = 49,
        .species = SPECIES_PARASECT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_RuinManiacLayton[] = {
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_SANDSLASH,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_ONIX,
    },
    {
        .iv = 15,
        .lvl = 48,
        .species = SPECIES_SANDSLASH,
    },
};



static const struct TrainerMonNoItemDefaultMoves sParty_PokemaniacHermanRematchAfterSapphire[] = {
    {
        .iv = 15,
        .lvl = 54,
        .species = SPECIES_MAROWAK,
    },
    {
        .iv = 15,
        .lvl = 54,
        .species = SPECIES_SLOWBRO,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PainterRaynaRematchAfterSapphire[] = {
    {
        .iv = 12,
        .lvl = 54,
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_CROSS_CHOP, MOVE_MEGAHORN, MOVE_DOUBLE_EDGE, MOVE_SELF_DESTRUCT},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungsterDestinRematchAfterSapphire[] = {
    {
        .iv = 12,
        .lvl = 53,
        .species = SPECIES_RATICATE,
    },
    {
        .iv = 12,
        .lvl = 53,
        .species = SPECIES_PIDGEOT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PkmnBreederAlizeRematchAfterSapphire[] = {
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_PIKACHU,
    },
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_CLEFAIRY,
    },
    {
        .iv = 15,
        .lvl = 53,
        .species = SPECIES_MARILL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_YoungCoupleGiaJesRematchAfterSapphire[] = {
    {
        .iv = 12,
        .lvl = 55,
        .species = SPECIES_NIDOKING,
    },
    {
        .iv = 12,
        .lvl = 55,
        .species = SPECIES_NIDOQUEEN,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperMiloRematchAfterSapphire[] = {
    {
        .iv = 12,
        .lvl = 53,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .iv = 12,
        .lvl = 55,
        .species = SPECIES_PIDGEOT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperChazRematchAfterSapphire[] = {
    {
        .iv = 12,
        .lvl = 53,
        .species = SPECIES_FEAROW,
    },
    {
        .iv = 12,
        .lvl = 55,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_BirdKeeperHaroldRematchAfterSapphire[] = {
    {
        .iv = 12,
        .lvl = 53,
        .species = SPECIES_NOCTOWL,
    },
    {
        .iv = 12,
        .lvl = 55,
        .species = SPECIES_NOCTOWL,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerFemaleNicoleRematchAfterSapphire[] = {
    {
        .iv = 12,
        .lvl = 54,
        .species = SPECIES_MARILL,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PsychicJaclynRematchAfterSapphire[] = {
    {
        .iv = 22,
        .lvl = 52,
        .species = SPECIES_NATU,
        .moves = {MOVE_PSYCHIC, MOVE_CONFUSE_RAY, MOVE_FUTURE_SIGHT, MOVE_WISH},
    },
    {
        .iv = 22,
        .lvl = 52,
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_PSYCHIC, MOVE_HEADBUTT, MOVE_AMNESIA, MOVE_YAWN},
    },
    {
        .iv = 22,
        .lvl = 54,
        .species = SPECIES_KADABRA,
        .moves = {MOVE_PSYCHIC, MOVE_FUTURE_SIGHT, MOVE_RECOVER, MOVE_REFLECT},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_SwimmerMaleSamirRematchAfterSapphire[] = {
    {
        .iv = 12,
        .lvl = 55,
        .species = SPECIES_GYARADOS,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_HikerEarlRematchAfterSapphire[] = {
    {
        .iv = 12,
        .lvl = 54,
        .species = SPECIES_ONIX,
    },
    {
        .iv = 12,
        .lvl = 54,
        .species = SPECIES_MACHAMP,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_RuinManiacLarryRematchAfterSapphire[] = {
    {
        .iv = 12,
        .lvl = 54,
        .species = SPECIES_MACHOKE,
    },
    {
        .iv = 12,
        .lvl = 54,
        .species = SPECIES_MACHOKE,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_PokemaniacHectorRematchAfterSapphire[] = {
    {
        .iv = 15,
        .lvl = 55,
        .species = SPECIES_RHYDON,
    },
    {
        .iv = 15,
        .lvl = 55,
        .species = SPECIES_KANGASKHAN,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PsychicDarioRematchAfterSapphire[] = {
    {
        .iv = 22,
        .lvl = 56,
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_CRUNCH, MOVE_PSYBEAM, MOVE_ODOR_SLEUTH, MOVE_AGILITY},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PsychicRodetteRematchAfterSapphire[] = {
    {
        .iv = 22,
        .lvl = 53,
        .species = SPECIES_NATU,
        .moves = {MOVE_PSYCHIC, MOVE_CONFUSE_RAY, MOVE_WISH, MOVE_FUTURE_SIGHT},
    },
    {
        .iv = 22,
        .lvl = 53,
        .species = SPECIES_HYPNO,
        .moves = {MOVE_PSYCHIC, MOVE_DISABLE, MOVE_PSYCH_UP, MOVE_FUTURE_SIGHT},
    },
    {
        .iv = 22,
        .lvl = 53,
        .species = SPECIES_HYPNO,
        .moves = {MOVE_PSYCHIC, MOVE_HYPNOSIS, MOVE_PSYCH_UP, MOVE_FUTURE_SIGHT},
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_JugglerMasonRematchAfterSapphire[] = {
    {
        .iv = 12,
        .lvl = 52,
        .species = SPECIES_ELECTRODE,
    },
    {
        .iv = 12,
        .lvl = 52,
        .species = SPECIES_PINECO,
    },
    {
        .iv = 12,
        .lvl = 52,
        .species = SPECIES_ELECTRODE,
    },
    {
        .iv = 12,
        .lvl = 52,
        .species = SPECIES_PINECO,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PkmnRangerNicolasRematchAfterSapphire[] = {
    {
        .iv = 22,
        .lvl = 55,
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_RAZOR_LEAF, MOVE_ACID, MOVE_STUN_SPORE, MOVE_WRAP},
    },
    {
        .iv = 22,
        .lvl = 55,
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_RAZOR_LEAF, MOVE_ACID, MOVE_SLEEP_POWDER, MOVE_SLAM},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PkmnRangerMadelineRematchAfterSapphire[] = {
    {
        .iv = 22,
        .lvl = 55,
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_PETAL_DANCE, MOVE_MOONLIGHT, MOVE_ACID, MOVE_SLEEP_POWDER},
    },
    {
        .iv = 22,
        .lvl = 55,
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_PETAL_DANCE, MOVE_MOONLIGHT, MOVE_ACID, MOVE_STUN_SPORE},
    },
};

static const struct TrainerMonItemDefaultMoves sParty_CrushGirlCyndyRematchAfterSapphire[] = {
    {
        .iv = 17,
        .lvl = 54,
        .species = SPECIES_PRIMEAPE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 17,
        .lvl = 54,
        .species = SPECIES_HITMONTOP,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .iv = 17,
        .lvl = 54,
        .species = SPECIES_MACHAMP,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonNoItemDefaultMoves sParty_TamerEvanRematchAfterSapphire[] = {
    {
        .iv = 16,
        .lvl = 52,
        .species = SPECIES_SANDSLASH,
    },
    {
        .iv = 16,
        .lvl = 52,
        .species = SPECIES_LICKITUNG,
    },
    {
        .iv = 16,
        .lvl = 55,
        .species = SPECIES_URSARING,
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PkmnRangerJacksonRematchAfterSapphire[] = {
    {
        .iv = 22,
        .lvl = 53,
        .species = SPECIES_TANGELA,
        .moves = {MOVE_SLAM, MOVE_MEGA_DRAIN, MOVE_BIND, MOVE_INGRAIN},
    },
    {
        .iv = 22,
        .lvl = 54,
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_CONFUSION, MOVE_EGG_BOMB, MOVE_STUN_SPORE, MOVE_REFLECT},
    },
    {
        .iv = 22,
        .lvl = 55,
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_CONFUSION, MOVE_EGG_BOMB, MOVE_SLEEP_POWDER, MOVE_STOMP},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_PkmnRangerKatelynRematchAfterSapphire[] = {
    {
        .iv = 22,
        .lvl = 56,
        .species = SPECIES_CHANSEY,
        .moves = {MOVE_EGG_BOMB, MOVE_DEFENSE_CURL, MOVE_MINIMIZE, MOVE_SOFT_BOILED},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_CooltrainerLeroyRematchAfterSapphire[] = {
    {
        .iv = 22,
        .lvl = 52,
        .species = SPECIES_RHYDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_HORN_DRILL, MOVE_ROCK_BLAST, MOVE_SCARY_FACE},
    },
    {
        .iv = 22,
        .lvl = 54,
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_PSYCHIC, MOVE_HEADBUTT, MOVE_AMNESIA, MOVE_DISABLE},
    },
    {
        .iv = 22,
        .lvl = 52,
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_DIZZY_PUNCH, MOVE_BITE, MOVE_ENDURE, MOVE_REVERSAL},
    },
    {
        .iv = 22,
        .lvl = 52,
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_CROSS_CHOP, MOVE_VITAL_THROW, MOVE_REVENGE, MOVE_SEISMIC_TOSS},
    },
    {
        .iv = 22,
        .lvl = 55,
        .species = SPECIES_URSARING,
        .moves = {MOVE_SLASH, MOVE_FAINT_ATTACK, MOVE_SNORE, MOVE_REST},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_CooltrainerMichelleRematchAfterSapphire[] = {
    {
        .iv = 22,
        .lvl = 53,
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_SLASH, MOVE_SCREECH, MOVE_FAINT_ATTACK, MOVE_BITE},
    },
    {
        .iv = 22,
        .lvl = 53,
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_ICE_BEAM, MOVE_TAKE_DOWN, MOVE_ICY_WIND, MOVE_SHEER_COLD},
    },
    {
        .iv = 22,
        .lvl = 54,
        .species = SPECIES_NINETALES,
        .moves = {MOVE_FLAMETHROWER, MOVE_CONFUSE_RAY, MOVE_WILL_O_WISP, MOVE_GRUDGE},
    },
    {
        .iv = 22,
        .lvl = 54,
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_BOUNCE, MOVE_AGILITY, MOVE_FIRE_SPIN, MOVE_TAKE_DOWN},
    },
    {
        .iv = 22,
        .lvl = 56,
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_CRUNCH, MOVE_PSYBEAM, MOVE_STOMP, MOVE_ODOR_SLEUTH},
    },
};

static const struct TrainerMonNoItemCustomMoves sParty_CoolCoupleLexNyaRematchAfterSapphire[] = {
    {
        .iv = 22,
        .lvl = 57,
        .species = SPECIES_MILTANK,
        .moves = {MOVE_BODY_SLAM, MOVE_MILK_DRINK, MOVE_GROWL, MOVE_DEFENSE_CURL},
    },
    {
        .iv = 22,
        .lvl = 57,
        .species = SPECIES_TAUROS,
        .moves = {MOVE_TAKE_DOWN, MOVE_SCARY_FACE, MOVE_PURSUIT, MOVE_SWAGGER},
    },
};


