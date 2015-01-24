# go.py by Stefano Guglielmetti 2015 - jeko@jeko.net

import sys    
sys.path.insert(0, '/usr/lib/python2.7/bridge/')
from bridgeclient import BridgeClient as bridgeclient
value = bridgeclient()                              
value.put('go','1') 
