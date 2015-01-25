# Copyright (c) 2015 Stefano Guglielmetti - jeko@jeko.net
# https://github.com/amicojeko
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.

# this script is based upon the official tweepy streamin example
# https://github.com/tweepy/tweepy/blob/master/examples/streaming.py

from __future__ import absolute_import, print_function

import os
from subprocess import call
from tweepy.streaming import StreamListener
from tweepy import OAuthHandler
from tweepy import Stream

script_path = os.path.dirname(os.path.realpath(__file__))

# Go to http://apps.twitter.com and create an app.
# The consumer key and secret will be generated for you after
consumer_key=""
consumer_secret=""

# After the step above, you will be redirected to your app's page.
# Create an access token under the the "Your access token" section
access_token=""
access_token_secret=""

# This is the string to search in the twitter feed
# May be  a word, an #hashtag or a @username

search_string = '#jekotest'

class StdOutListener(StreamListener):
    """
    A listener handles tweets are the received from the stream.
    This is a basic listener that just prints received tweets to stdout.
    """

    def on_data(self, data):
        # I call an external script because the Arduino's Bridge library
        # confilcts with the tweepy library
        call(["/usr/bin/python", script_path + "/go.py"])
        return True

    def on_error(self, status):
        # TODO: Put some error handling here
        return False

if __name__ == '__main__':
    l = StdOutListener()
    auth = OAuthHandler(consumer_key, consumer_secret)
    auth.set_access_token(access_token, access_token_secret)

    stream = Stream(auth, l)
    stream.filter(track=[search_string])
