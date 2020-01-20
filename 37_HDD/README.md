# 37 HDD

_First, the rotational speed is by default set to 1 degree per time unit. Thus, to make a complete revolution, it takes 360 time units_

_Thus, to read a sector, it takes 30 time units (given our default speed of rotation_

_A seek from the outer track to the middle track takes 40 time units_

_You'd also have to know the scheduling policy. The default is FIFO, though, so for now you can just compute the request times assuming the processing order matches the list specified via the "-a" flag._

## 1

Compute the seek, rotation, and transfer times for the following sets of requests: -a 0, -a 6, -a 30, -a 7,30,8, and finally -a 10,11,12,13.


~~~
You have to calculate n - 1 rotations that have to be done, then add a quarter of a rotation which is 15 units and then add another 30 for the read
6 -> 0 = 150 + 15 + 30
6 -> 6 = 345 + 30 (quarter of rotation already calculated)
6 -> 30 = 375 (?)
6 -> 7,30,8 = [15 + 30] + [300 (bc 10 rotations going from 7 to 30) + 30] + [390 (bc 13 rotations going from 30 to 8) + 30]
6 -> 10,11,12,13 = [90 + 15 + 30] + [30] + [360 + 30] + [30]
~~~

## 2

Do the same requests above, but change the seek rate to different values: 
-S 2, -S 4, -S 8, -S 10, -S 40, -S 0.1. How do the times change?



## 3
## 4
## 5
## 6
## 7
## 8
## 9
## 10