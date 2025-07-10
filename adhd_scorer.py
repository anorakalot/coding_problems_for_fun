import time
import sys
import math
import pdb



multiplier = 1
expected_time = 1800 #30 min in seconds is the default
multi_input = input ("\r\nWhich type of task? 1. menial task 2. engineering task \r\n")


if (multi_input == '1'):
    multiplier = 1
else:
    multiplier = 10
    
expected_time_input = input("if want default (30 min) press enter ,else input in time in minutes\r\n")

if (expected_time_input !=  ""):
    expected_time = int(expected_time_input) * 60

num_of_retries = input("Input num of retries this is, (if it's the first enter 0) \r\n")


if (num_of_retries == ""):
    num_of_retries = 0
else:
    num_of_retries = int(num_of_retries)

print("expected_time (m) = ", expected_time / 60)
print("expected_time (s) = ", expected_time)
print("num_of_retries = ",num_of_retries);
print("starting time now")

starting_time = int(time.time())

input("press enter when done")

ending_time = int(time.time())

diff = ending_time - starting_time

if (diff == 0):
    sys.exit()

#points = multiplier*(3600/diff)

#if less than expected time give full points
if (diff <= expected_time):
    points = multiplier

else:
    #give up to double the time decreasing points as it goes 
    points = (multiplier * max(0.01, 1 - (diff / expected_time*2)))

points = points / (1+num_of_retries)
#epsilon = 1e-6

#points = (multiplier *  (1 / (math.log((diff / expected_time)+epsilon)+1)))


#if past the hour mark but I still get points for finishing a task
#if points == 0:
#    points += 1;

#multiplier * (ending_time - starting_time)

print("ending_time",ending_time)
print("starting_time",starting_time)
print("diff in sec",diff)
print("diff in min",diff / 60)
print("points (float) ",points)
print("points (int) ",int(points))