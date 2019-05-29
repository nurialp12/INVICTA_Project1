# Fatal Fury
Recreation of the the game Fatal Fury.
Fatal Fury is a fighting game series developed by SNK for the Neo Geo system which allowed player to choose one of three characters to fight against eight computer controlled characters.
The gameplay follows the typical formula of most fighting games: 
the player fights against their opponent in best two-out-of-three matches. 
Each of the playable characters has special techniques that are performed by inputting specific commands in combination with the joystick and buttons. 
Fatal Fury was developed around the same time as Street Fighter II but Fatal Fury focused more on the timing of special moves and storytelling instead of the combos which Street Fighter II emphasised.


## Installation
Download the .zip (which can be found in our Github Project -link below- in releases and in our github wewb page).
Go to the file "Game" and click "SDL5 Handout"
Enjoy!


## Usage

	PLAYER 1
	A move left
	S crouch
	D move right
	W jump
	F punch
	G kick
	H Power Wave
	

	PLAYER 2
	LEFT KEY move left
	DOWN KEY crouch
	RIGHT KEY move right
	UP KEY jump
	I punch
	O kick
	P Power Wave
	
Space to change screens
, to move up the camera
. to move down the camera
	7 to move left the camera
	8 to move right the camera
	9 to move up the camera
	0 to move down the camera
ESC to leave the game

DEBUG:
	F1 collisions
	F2 direct win (PLAYER 1)
	F3 direct lose (PLAYER 1)
	F4 direct tie (PLAYER 1 WINS)
	F5 god mode (PLAYER 1)

	F6 direct win (PLAYER 2)
	F7 direct lose (PLAYER 2)
	F8 god mode (PLAYER 2)

	F9 mute/unmute sound


## Contributing
1. Fork it!
2. Create your feature branch: 'git checkout -b my-new-feature'
3. Commit your changes: 'git commit -am 'Add some feature'
4. Push to the branch: 'git push origin my-new-feature'
5. Submit a pull request :D


## History
TODO: Write history
0.1
	Added:
		a) Scroll empty background
		b) Audio Module
		c) Music has a slow fade out / in
		d) The player (Terry) can throw a Punch, Kick and Jump (only upwards)
	Removed:
	Note: Base code already implemented (PreUpdate, Update, PostUdate, etc)
0.2
	Added:
		a) Welcome screen
		b) First level (Sound Beach - Street Fighter II)
		c) Second level (Pao Pao Cafe)
		d) Congrats screen
		e) Game over screen
		f) Back to Welcome screen
		e) Sound on
	Removed:
	Note: First level (Sound Beach - Street Fighter II) (b) is only to show the implementation of the scene change
0.3
	Added:
		a) The player (Terry) can move around with animations
		b) Power Wave (Terry) can be shot with FX
	Removed:
	Note: There aren't any collisions
0.4 
	Added:
		a) Camera limits for the Player (not Player 2)
		b) Colliders for the Player (not Player 2) and its particles
		c) Player (not Player 2) can collide with something in the environment 
		d) God Mode for Player (not Player 2)
	Removed:
	Note: The collider is going to be Player 2 in b).

0.45 
	Added:
		a) State Machine
		b) Player 2 (also Terry) mirrored
	Removed:
	Note: 
0.5
	Playable version of the game to try it out with Terry Bogard in the Stage Pao Pao Café. 
	This content (the player ans stage) shall be removed upon the next release.
1.0
	Attempt to make an exact copy of the game in the Stage Sound Beach with Andy Bogard as the only player
	CONTENT:
		Introduction sequence
		Andy Bogard as Player 1 and 2
		Sound Beach Stage
		Sound effects and mmusic
		Debug functionality
		Score
		Play in Full Screen
		Gamepad or keyboard to play
		


## Credits
Invicta Studios:

Tomás Carreras
Enric-Guillem Durán
Núria Lamonja
Alex Lopez

Github: https://github.com/nurialp12/INVICTA_Project1
Releases: https://github.com/nurialp12/INVICTA_Project1/releases
Wiki: https://github.com/nurialp12/INVICTA_Project1/wiki


## License
All rights reserved to the developers and publishers of the original release. 
The aim of this project (link to the github project can be found above) and respectively wiki is only educational. 
The content can only be used for non-commercial purposes.

