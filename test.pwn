// RESULTS

// Failed. Noone of styles worked

#include <running_styles> // Import the include, as i saw in the code running_styles.inc automatically includes a_samp so no need to include it myself
#include <YSI_Visual\y_commands> // use y_commands

main()
{
    print("running_styles tests by Mergevos loaded ");
}

public OnPlayerConnect(playerid)
{
    SetSpawnInfo(playerid, 0, 0, 811.1299,-1616.0647,13.5469, 0, 0,0,0,0,0,0);
    SpawnPlayer(playerid);
    return 1;    
}

public OnPlayerSpawn(playerid)
{
    TogglePlayerControllable(playerid, true);
    return 1;
}

YCMD:1(playerid, params[], help)
{
    Player_SetRunningStyle(playerid, RUNNING_STYLE_DEFAULT );
    return 1;
}
YCMD:2(playerid, params[], help)
{
    Player_SetRunningStyle(playerid,     RUNNING_STYLE_ARMED1 );
    return 1;
}
YCMD:3(playerid, params[], help)
{
    Player_SetRunningStyle(playerid, RUNNING_STYLE_ARMED );
    return 1;
}
YCMD:4(playerid, params[], help)
{
    Player_SetRunningStyle(playerid, RUNNING_STYLE_CIVIL );
    return 1;
}
YCMD:5(playerid, params[], help)
{
    Player_SetRunningStyle(playerid, RUNNING_STYLE_CHAINSHAW );
    return 1;
}
YCMD:6(playerid, params[], help)
{
    Player_SetRunningStyle(playerid, RUNNING_STYLE_FAT );
    return 1;
}
YCMD:7(playerid, params[], help)
{
    Player_SetRunningStyle(playerid, RUNNING_STYLE_FAT_OLD );
    return 1;
}
YCMD:8(playerid, params[], help)
{
    Player_SetRunningStyle(playerid, RUNNING_STYLE_GANG1 );
    return 1;
}
YCMD:9(playerid, params[], help)
{
    Player_SetRunningStyle(playerid, RUNNING_STYLE_LEFT );
    return 1;
}
YCMD:10(playerid, params[], help)
{
    Player_SetRunningStyle(playerid, RUNNING_STYLE_OLD );
    return 1;
}
YCMD:11(playerid, params[], help)
{
    Player_SetRunningStyle(playerid, RUNNING_STYLE_PLAYER );
    return 1;
}
YCMD:12(playerid, params[], help)
{
    Player_SetRunningStyle(playerid, RUNNING_STYLE_RIGHT );
    return 1;
}
YCMD:13(playerid, params[], help)
{
    Player_SetRunningStyle(playerid, RUNNING_STYLE_ROCKET );
    return 1;
}
YCMD:14(playerid, params[], help)
{
    Player_SetRunningStyle(playerid, RUNNING_STYLE_BLIND );
    return 1;
}
