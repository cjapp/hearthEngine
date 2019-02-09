# Hearth Engine
Simple 2DGame Engine

Colby Japp

Uses SDL and C++. The CMakeFiles currently in the project are to help in testing and compiling.

The Hearth Game engine is a simple 2DGame Engine I wrote for a CSCI Senior Project. The main
Goals of the project were to go through the process and understanding of how a game engine 
works as well as have something I can work with further down the line.

The engine currently features:

* A Resource Manager for handling textures, and fonts.
* An Input Manager that acts like a wrapper around SDL input handling events.
* An Application Manager, where the main game loop runs as well as managing initializing the systems used with the application and different states within the game
* The state class, that behaves like a scene in unity. These manage their own gameobjects and ui elements.
* The game objects themselves handle their own logic and movement.
* A camera system that is capable of transforming the state/scene instead of keeping it static as before
* Alarm events have now been implemented(start, setDuration, and check are current functionality)
* Framerate is capable of being capped
* SoundSystem that loops music and plays sound, behaves more like a wrapper for SDL/_mixer

The core functions that are needed by states and game objects are the init(), update(), and clear().
* **init()** is the virtual function that is run before the frames are set up(behaves like the start and awake functions in unity)
* **update()** is the function taht is called everyframe, and usually contains the logic affiliated with that particular object or state
* **clear()** is what deinitializes a state, usually by removing gameobject references from the vectors and cleaning up when a state is finished running

Some future features I would like to include later are
* Animated Sprites
* Saving and loading system


