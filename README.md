# Arduino Yún + Twitter Streaming API blink example

This is a simple example on how to run some code on the Arduino side of the Arduino Yún on specific events fired through the Twitter Streaming API

i.e. when a tweet containing a specific #hashtag is twitted, Arduino blinks an LED

I love this experiment because it's near real time and it gives a lot of possibilities, and it's very easy to set up

## Requirements

* An Arduino Yún (obviously) with an external SD card (required for hosting the Python libraries you'll need)
* A [twitter app](https://apps.twitter.com/) you own
* The [Tweepy library](https://github.com/tweepy/tweepy) for Python 

## Instructions

> "I love instructions, they give me confidence."
> -- <cite>me</cite>

1. In case you haven't done it yet, [upgrade](http://arduino.cc/en/Tutorial/YunSysupgrade) your Arduino Yún to the latest version and [expand](http://arduino.cc/en/Tutorial/ExpandingYunDiskSpace) it's disk space using the SD card
2. Log to your Arduino using ssh
3. Install a bunch of useful stuff

		$ opkg update
		$ opkg install git
		$ opkg install python-expat
		$ opkg install python-openssl
		$ opkg install python-bzip2
#### easy_install
		$ opkg install distribute
#### pip
		$ easy_install pip
####[tweepy](https://github.com/tweepy/tweepy)
		$ pip install tweepy
or install it manually cloning it from github
		
		$ git clone https://github.com/tweepy/tweepy.git
		$ cd tweepy
		$ python setup.py install

4. If you don't have one, create your [twitter app](https://apps.twitter.com/) 
and get your consumer key and consumer secret. Then, generate an access token and get your access token and access token secret

5. Create a working folder for all the scripts (i.e. /root/python)
		
		$ mkdir /root/python
		$ cd /root/python
and, while in the python folder, clone the Twitter Blink example

		$ git clone git@github.com:amicojeko/TwitterBlink.git
don't forget to make the kill_processes.sh script executable!
		
		$ chmod +x kill_processes.sh

6. Then use vi or nano (I personally installed vim) to put your twitter app configuration data into the streaming.py script, and to configure the string to be searched inside the Twitter Stream Maelstrom

		$ nano streaming.py

	now everything should be ready. 

7. Open the Arduino IDE and load the TwitterBlink.ino script that is in the Arduino folder (you can download it from GitHub )

8. Configure the script folder (in case you created a folder different from root/python/ in the previuos steps)
	
	You can customize the script for your needings, in it's initial configuration it will blink the LED attached to pin 13 (and the built in LED as well) so it's perfect for testing

9. Upload the script to Arduino, it should start working as soon as it's uploaded

10. Have fun!!

cheers!

Jeko 