https://github.com/ThomasDNguyen/AppDev

#This is version 1 of git Example.

---------------------------------------------
	Acoustic Sensor using RPi3
---------------------------------------------

Table of Content:
1. Configuration Instructions
2. Installation Instructions
3. Operating Instructions
4. List of Project files
5. Known bugs
6. Contact information of the Programmer
7. Credits and acknowledments 

---------------------------------------------

1. Configuration Instructions

This section contains 2 parts: Hardware configuration and software configuration.

This project is built on a Raspberry Pi3, with a USB sound card and a microphone. 
Ethernet connection is recommended. If an older version of Raspberry Pi is used,
certain change might be necessary.

	First you have to set USB sound card as default audio device:
a> Boot up RPi and apply USB sound card.
b> RPi onboard sound card doesn't have microphone interface -> change the default audio
device to USB sound card
c> Use command "lsusb" to check whether USB sound card is mounted.

d> Use “sudo nano /etc/asound.conf”command and put following content to the file:
pcm.!default {
	type plug
 	slave {
		pcm "hw:1,0"
 	}
}
ctl.!default {
    type hw
    card 1
}

e> Go to your home directory. Use “nano .asoundrc” command and put the same content to 
the file.

==> Run “alsamixer” and you should be able to see that USB sound card is the default 
audio device.  

*****************

	Second you need to downgrade the alsa-utils from 1.0.28 to 1.0.25 :
a> Use “sudo nano /etc/apt/sources.list” command and add the last line:
pi@raspberrypi:~ $ sudo aptitude versions alsa-utils

Package alsa-utils:
i   1.0.25-4                          oldstable                                 500
p   1.0.28-1                          stable                                    500

b> Run “sudo apt-get install alsa-utils=1.0.25-4” to downgrade.

c> Reboot (if necessary)

d> Run “arecord -r44100 -c1 -f S16_LE -d5 test.wav” to test that your microphone is working.
You should see a “test.wav” file in the current folder.

e>  Put earphone on. Run “aplay test.wav” to check that your recording is okay.

---------------------------------------------

2. Installation Instructions

2.1> Download all the source file from this URL : https://github.com/

2.2> Open a computer with Linux OS

2.3> Go to the folder contain all the source file and type "make"  (others command can be seen in makefile)

---------------------------------------------

3. Operation Instructions

- After the installation, simply execute "./wave.a" in the project folder.
- The screen will display the waveform (remember to change setting language UTF-8  of the Linux terminal for the bar character)
- The screen will also show the duration ,bits per sample and sample rate's values
- A log file has been made in order to record all the previous data and can be viewed in here :http://www.cc.puv.fi/~e1601122/php/sound.log 

---------------------------------------------

4. List of project files 

The projects contains following files:

--README.md     :       this file

--makefile      :       the makefile of this project

--wave.c        :       the module containing functions about wave processing

--wave.h        :       the header of wave.c

--screen.c      :       the module containing functions about screen manipulation

--screen.h      :       the header of screen.c

--comm.c        :       the communication module using libcurl

--comm.h        :       the header file of comm.c

--main.c        :       contains main() function

--raspsound.php     :       the server page to receive data

--------------------------------------------- 

5. Known Bugs 

- No known bugs detected. Program runs smoothly

---------------------------------------------

6. Contact information of the Programmer

- Name: Nguyen Duy Thanh
- email: yohowdoyoudo@gmail.com
- face book: https://www.facebook.com/thanh.nguyenduy.148

---------------------------------------------

7. Credits and acknowledgments

1> Mr. Gao Chao -- Email: gao.chao@vamk.fi
2> References : https://en.wikipedia.org/wiki/README
3> Curl library -- Webpage: https://curl.haxx.se/

---------------------------------------------

		# THE END #
=======
# AppDev
