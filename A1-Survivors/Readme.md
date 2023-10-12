# A1 - Survivors

There are many bugs and incomplete features in this game.

Do your best to make it match up with the version in the "Example" folder.

### Incomplete list of broken things:

- It doesn't compile.
- Player doesn't move.
- Weapons don't work.
- Reset is broken. Press 'R' to reset.
- Enemies aren't spawning or moving towards the player
	- I tossed 2 hard-coded enemies into the Game::Reset function just to show something happens
		- You should remove those when you're done.
- Some HUD text is missing.

Also, check the code for "TODO"s, but watch out for the ones in the GameDev2D code.

### New feature to add:

- A new weapon of your choice.
	- The new weapon can't shoot objects of the current Bullet class
	- Grab some new graphics from the web, or make your own
	- It doesn't matter if it ends up OP, but try to start it off fairly weak
	- Make sure it levels up as you gain xp
	- The new weapon must require multiple hits to kill an enemy
		- The current gun applied a ton of damage so enemies died in one hit
		- Some code for enemy HP is written, but it needs testing and possibly fixing

### Other:

Take your time and try to understand as much of the code as you can while fixing these issues.
If you spot more problems, and there are some, fix those as well.

Also, try to use the debugger to step through the code to see how it flows.

### Important debugging keys:

- F9 - Enable/Disable a breakpoint on the current line
- Ctrl-Shift-F9 - Remove all breakpoints
- F10 - Step over function calls
- F11 - Step into function calls, allowing you to follow the code into the function
- Shift+F11 - Step out of the current function and back to the calling function
- F5 - Continue running the program until the next breakpoint is hit
