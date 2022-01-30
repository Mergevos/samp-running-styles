/** 
@ Author: Mergevos
@ Date: 23rd June
@ Git: github.com/Mergevos/samp-running-styles
@ Copyright (C) 2020
@ About:
- This include gives you access to 14 running styles
**/

#if defined _running_Styles_inc
    #endinput
#endif

#define _running_Styles_inc

#include <a_samp>

// --
// Credits
// --

#if !defined RUNNING_STYLES_NO_CREDITS_MSG
    public OnGameModeInit() 
    {
        #if defined RS_OnGameModeInit
            RS_OnGameModeInit();
        #endif
        print("[1.0.1] Running styles loaded \nCreated by Mergevos");
        return 1;
    }
#endif

// --
// Running styles
// --


static const TIME_UPDATE_ANIMATION  = 300;

enum e_RUNNING_STYLES
{
    E_RUNNING_STYLE_DEFAULT = 0,
    E_RUNNING_STYLE_ARMED1,
    E_RUNNING_STYLE_ARMED,
    E_RUNNING_STYLE_CIVIL,
    E_RUNNING_STYLE_CHAINSHAW,
    E_RUNNING_STYLE_FAT,
    E_RUNNING_STYLE_FAT_OLD,
    E_RUNNING_STYLE_GANG1,
    E_RUNNING_STYLE_LEFT,
    E_RUNNING_STYLE_OLD,
    E_RUNNING_STYLE_PLAYER,
    E_RUNNING_STYLE_RIGHT,
    E_RUNNING_STYLE_ROCKET,
    E_RUNNING_STYLE_BLIND
};

// --
// Vars
// --

static 
    Running_gsTimer[MAX_PLAYERS], 
    e_RUNNING_STYLES: Running_gsStyle[MAX_PLAYERS];

static const Running_gsAnimIndices[] = {1222, 1223, 1224, 1225, 1226, 1227, 1228, 1229, 1230, 1232, 1233, 1236};
//indices animations for checking running

static const Running_gsAnimations[][] =
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
    Running_gsStyle[playerid] = E_RUNNING_STYLE_DEFAULT;
    Running_gsTimer[playerid] = -1;
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
    if(Running_gsTimer[playerid] != -1)
    {
        KillTimer(Running_gsTimer[playerid]);
    }
    return 1;
}
// --
// OnPlayerUpdate
// --
public OnPlayerUpdate(playerid)
{
    #if defined RS_OnPlayerUpdate
        RS_OnPlayerUpdate(playerid);
    #endif
    if(Player_GetRunningStyle(playerid) > 0 && Running_gsTimer[playerid] == -1)
    {
        new keys, updown, leftright;
        GetPlayerKeys(playerid,keys,updown,leftright);
        if (((!!updown  || !!leftright) ))
        {
            new temp_index_anim = GetPlayerAnimationIndex(playerid);
            for(new i = 0; i < sizeof Running_gsAnimIndices; i++)
            {
                if(temp_index_anim == Running_gsAnimIndices[i])
                {   
                    ApplyAnimation(playerid,"PED",Running_gsAnimations[_:Running_gsStyle[playerid]-1],4.1,1,1,1,1,1);
                    timer_RunAnimation(playerid);
                    break;
                }
            }
        }        
    }
    return 1;
}

// --
// <summary> Handles timer_RunAnimation timer</summary>
// --

forward timer_RunAnimation(playerid);
public timer_RunAnimation(playerid)
{
    Running_gsTimer[playerid] = -1;
    if(Running_gsStyle[playerid] <= E_RUNNING_STYLE_DEFAULT) 
    {
        return 0;
    }
    new keys, updown, leftright;
    GetPlayerKeys(playerid,keys,updown,leftright);
    if (((!!updown  || !!leftright) ))
    {
        new temp_index_anim = GetPlayerAnimationIndex(playerid);
        for(new i = 0; i < sizeof Running_gsAnimIndices; i++)
        {
            if(temp_index_anim == Running_gsAnimIndices[i])
            {   
                Running_gsTimer[playerid] = SetTimerEx("timer_RunAnimation",TIME_UPDATE_ANIMATION,false,"d",playerid);
                return 1;
            }
        }
    }
    return ApplyAnimation(playerid,"PED",Running_gsAnimations[_:Running_gsStyle[playerid]-1],4.0,0,0,0,0,1); 
}

// --
// <summary> Sets player's running style </summary>
// --

stock Player_SetRunningStyle(playerid, e_RUNNING_STYLES: style) 
{
    if(_:style >= sizeof(Running_gsAnimations))
    {
        return 0;
    }
    Running_gsStyle[playerid] = style;
    return 1;
}

// --
// <summary> Gets player's running style </summary>
// --


stock Player_GetRunningStyle(playerid) 
{
    return Running_gsStyle[playerid];
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
// ALS OnPlayerDisconnect
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


// --
// ALS OnPlayerUpdate
// --

#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate RS_OnPlayerUpdate
#if defined RS_OnPlayerUpdate
    forward RS_OnPlayerUpdate(playerid);
#endif
