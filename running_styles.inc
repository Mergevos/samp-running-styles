/** 
    @ Author: Ben Jackster
    @ Date: 23th June
    @ Git: github.com/Mergevos/samp-running-styles
    @ Copyright (C) 2020
    @ About:
    	- This include gives you access to 14 running styles
    @ Credits: 
        Me - Forking this and transforming into include
**/

#if defined _running_Styles_inc
    #endinput
#endif

#include 				< a_samp >

#if !defined HOLDING 
	#define HOLDING(%0) \
		((newkeys & (%0)) == (%0))
#endif


// --
// Credits
// --

#if !defined RUNNING_STYLES_NO_CREDITS_MSG
	public OnGameModeInit() 
    {
		#if defined RS_OnGameModeInit
			RS_OnGameModeInit();
		#endif
		print("[1.0.0] Running styles loaded \n\
			Created by Mergevos");
		return 1;
	}
#endif

// --
// Running styles
// --


static const TIME_UPDATE_ANIMATION  = 300;


enum 
{
	RUNNING_STYLE_DEFAULT = 0,
	RUNNING_STYLE_ARMED1,
	RUNNING_STYLE_ARMED,
	RUNNING_STYLE_CIVIL,
	RUNNING_STYLE_CHAINSHAW,
    RUNNING_STYLE_FAT,
	RUNNING_STYLE_FAT_OLD,
    RUNNING_STYLE_GANG1,
	RUNNING_STYLE_LEFT,
	RUNNING_STYLE_OLD,
	RUNNING_STYLE_PLAYER,
	RUNNING_STYLE_RIGHT,
	RUNNING_STYLE_ROCKET,
	RUNNING_STYLE_BLIND
};

// --
// Vars
// --

static 
	timer_Running[MAX_PLAYERS], 
	style_Running[MAX_PLAYERS];

static const indexes_animations[] = {1222, 1223, 1224, 1225, 1226, 1227, 1228, 1229, 1230, 1232, 1233, 1236};
//indexes animations for checking running

static const NameAnimations[][] =
{
    "run_1armed",
    "run_armed",
    "run_civi",
    "run_csaw",
    "run_fat",
    "run_fatold",
    "run_gang1",
    "run_left",
    "run_old",
    "run_player",
    "run_right",
    "run_rocket",
    "Run_Wuzi"
};
// --
// OnPlayerConnect
// --

public OnPlayerConnect(playerid) 
{

	#if defined RS_OnPlayerConnect
        RS_OnPlayerConnect(playerid);
    #endif
	style_Running[playerid] = RUNNING_STYLE_DEFAULT;
    timer_Running[playerid] = -1;
	return 1;
}
// --
// OnPlayerDisconnect
// --
public OnPlayerDisconnect(playerid, reason) 
{

	#if defined RS_OnPlayerDisconnect
        RS_OnPlayerDisconnect(playerid, reason);
    #endif
    if(timer_Running[playerid] != -1)
        KillTimer(timer_Running[playerid]);
	return 1;
}

public OnPlayerUpdate(playerid)
{
    if(Player_GetRunningStyle(playerid) > 0 && timer_Running[playerid] == -1)
    {
        new keys, updown, leftright;
        GetPlayerKeys(playerid,keys,updown,leftright);
        if (((!!updown  || !!leftright) ))
        {
            new temp_index_anim = GetPlayerAnimationIndex(playerid);
            for(new i = 0; i < sizeof indexes_animations; i++)
            {
                if(temp_index_anim == indexes_animations[i])
                {   
                    ApplyAnimation(playerid,"PED",NameAnimations[style_Running[playerid]-1],4.1,1,1,1,1,1);
                    timer_RunAnimation(playerid);
                    break;
                }
            }
        }        
    }
    #if defined gf_OnPlayerUpdate
        return gf_OnPlayerUpdate(playerid);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate gf_OnPlayerUpdate
#if defined gf_OnPlayerUpdate
    forward gf_OnPlayerUpdate(playerid);
#endif


// --
// <summary> Handles timer_RunAnimation timer</summary>
// --



forward timer_RunAnimation(playerid);
public timer_RunAnimation(playerid)
{
    timer_Running[playerid] = -1;
    if(style_Running[playerid] <= 0) 
        return false;
    new keys, updown, leftright;
    GetPlayerKeys(playerid,keys,updown,leftright);
    if (((!!updown  || !!leftright) ))
    {
        new temp_index_anim = GetPlayerAnimationIndex(playerid);
        for(new i = 0; i < sizeof indexes_animations; i++)
        {
            if(temp_index_anim == indexes_animations[i])
            {   
                timer_Running[playerid] = SetTimerEx("timer_RunAnimation",TIME_UPDATE_ANIMATION,false,"d",playerid);
                return true;
            }
        }
    }
	return ApplyAnimation(playerid,"PED",NameAnimations[style_Running[playerid]-1],4.0,0,0,0,0,1); 
}

// --
// <summary> Sets player's Running style </summary>
// --

stock Player_SetRunningStyle(const playerid, const style) 
{
    if(style >= sizeof(NameAnimations))
        return false;
	style_Running[playerid] = style;
    return true;
}

// --
// <summary> Gets player's running style </summary>
// --


stock Player_GetRunningStyle(const playerid) 
{
	return style_Running[playerid];
}

// --
// ALS OnPlayerConnect
// --

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect RS_OnPlayerConnect
#if defined RS_OnPlayerConnect
    forward RS_OnPlayerConnect(playerid);
#endif


// --
// ALS OnPlayerDisonnect
// --

#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect RS_OnPlayerDisconnect
#if defined RS_OnPlayerDisconnect
    forward RS_OnPlayerDisconnect(playerid, reason);
#endif

// --
// ALS OnGameModeInit
// --

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit RS_OnGameModeInit
#if defined RS_OnGameModeInit
    forward RS_OnGameModeInit();
#endif
