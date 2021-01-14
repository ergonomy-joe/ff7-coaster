# ff7-coaster

You know "Final Fantasy VII" and you know one of its minigame: the jet-coaster shooting game.
So here is the decompiled code of the windows version. This is just a small part of the FF7 game, but I think you can have fun trying to build it to a more recent version of windows, or seeing how it was coded.
I also included a "Visual Studio 2008" project file so you can build it/run it easely.
I didn't put the source to part of the original games which I call "FF7LIB" and "FF7SND" but included a library version of both.
You can get rid of "FF7SND" easily if you want to put your on sound/music driver here.
"FF7LIB" maybe a challenge but I guess it is feasible.
I also invite you to change the "REGISTRY" related files to something more suitable to you environment.

In order to run the game, all you need is the file "coaster.lgp" from FF7 (the windows version), and a correct registry so that the program can find it.

Have decompiled-fun !
ergonomy_joe

addendum 2020/12/16
-------------------
for those who successfuly build the EXE but have problems running it you should try to modify the EXE's compatibility properties: set it to "Reduced color mode: 16-bit".

addendum 2021/01/14
-------------------
I made a slight change in FF7LIB.LIB: now the application tries to run with whatever the desktop pixel depth is.
With a FF7 registry configured to run on D3D hardware rendering and a 32bpp desktop, the application should run fine now.
However, the software renderer works only in 16bit mode, so expect a crash if you run in anything else than 16bpp mode.

