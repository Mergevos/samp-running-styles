# samp-running-styles

[![sampctl](https://img.shields.io/badge/Mergevos-samp--running--styles-2f2f2f.svg?style=for-the-badge)](https://github.com/Mergevos/samp-running-styles)

Allows you to run in 13 styles.

## Installation

Simply install to your project:

```bash
sampctl package install Mergevos/samp-running-styles
```

Include in your code and begin using the library:

```pawn
#include <running_styles>
```

## Usage

If you've had included this into your script/gamemode etc... Start by using a simple function  
```pawn
Player_SetRunningStyle(const playerid, const style);
```
This is going to set you some of running styles below 
```pawn
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
```
And there is 
```pawn
Player_GetRunningStyle(const playerid);
```
This will return you the player's running style.

*Note*: If you've set the player's running style, to activate it, firstly press _W_ then _left alt_ key.

## Testing

<!--
Depending on whether your package is tested via in-game "demo tests" or
y_testing unit-tests, you should indicate to readers what to expect below here.
-->

To test, simply run the package:

```bash
sampctl package run
```
