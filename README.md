# simple-timer
Minimal CLI Timer Program, Which plays an AudioFile When time is up. User enters the total time they wish the timer to countdown from. Used for my own productivity. Can close the terminal Once executed, as it's running in the background, just make sure the volume is high enough to hear the alarm sound. 

More lightweight & battery friendly compared to using a timer in a browser or with a graphical user interface.

# usage
run without arguments to see the usage instructions.

"./timer"



# Config

The config.h definition values will need to be changed for the own user's operating system. So before using the simple timer you will need to edit the config.h
file to point towards the soundfile you wish to play as well as the software used to play the sound when the timer is up. As the Program is being run as a daemon
in the '/' directory, be sure to provide full paths for the definitions. And make sure not to change the defiition names, as the program relies on reading
the config. As an example my config has been provided.

But obviously you may want to change the software choice and point to your own soundfile. I have provided the soundfile I use. I created it myself using an analog moog sub 25 hardware synthesizer. Deliberately have a short soundfile so it ends quickly without having to manually stop it yourself.


# Improvements

The ability to see the elapsed time. To see how much time is left of the timer.
