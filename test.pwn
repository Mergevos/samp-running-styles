#include <a_samp>
#include "running_styles.inc"

#include <YSI_Visual\y_commands> // use y_commands by Y_LESS
#include <YSI_Coding\y_va> // For va_ funcs by Y_LESS
#include <sscanf2> // For commands by Y_LESS

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

YCMD:style(playerid, params[], help)
{

    new style;
    if(sscanf(params, "i", style)) return SendClientMessage(playerid, -1, "Usage: /style <id>");
    va_SendClientMessage(playerid, -1, "Successfully set running style to: %i", style);
    Player_SetRunningStyle(playerid, e_RUNNING_STYLES: style );
    return 1;
}