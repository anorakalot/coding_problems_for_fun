import time
import sys
import math
import pdb



multiplier = 1
expected_time = 1800 #30 min in seconds is the default
multi_input = input ("\r\nWhich type of task? 1. menial task 2. engineering task \r\n")


if (multi_input == '1'):
    multiplier = 5
else:
    multiplier = 10
    
expected_time_input = input("if want default (30 min) press enter ,else input in time in minutes\r\n")

if (expected_time_input !=  ""):
    expected_time = int(expected_time_input) * 60

print("starting time now")

starting_time = int(time.time())

input("press enter when done")

ending_time = int(time.time())

diff = ending_time - starting_time

if (diff == 0):
    sys.exit()

#points = multiplier*(3600/diff)

#points = (multiplier * max(0, 1 - (diff / 1800)))

points = (multiplier *  (1 / (math.log(diff / expected_time)+1)))


#if past the hour mark but I still get points for finishing a task
#if points == 0:
#    points += 1;

#multiplier * (ending_time - starting_time)

print("ending_time",ending_time)
print("starting_time",starting_time)
print("diff in sec",diff)
print("diff in min",diff / 60)
print("points non int",points)
print("points",int(points))