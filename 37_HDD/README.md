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
6 -> 6 = 330 + 15 + 30
6 -> 30 = 375 (?)
6 -> 7,30,8 = [15 + 30] + [300 (bc 10 rotations going from 7 to 30) + 30] + [390 (bc 13 rotations going from 30 to 8) + 30]
6 -> 10,11,12,13 = [90 + 15 + 30] + [30] + [360 + 30] + [30]
~~~

## 2

Do the same requests above, but change the seek rate to different values: 
-S 2, -S 4, -S 8, -S 10, -S 40, -S 0.1. How do the times change?

~~~
When there is a seek like 11 -> 12 even with seek 40 it has to do a full rotation. When there is a seek like 11 -> 13 with seek set to 2 no full revolution is needed anymore ;)


python ./disk.py -a 7,30,8 -S 2 -c -G has the same results as with -S 1 because a seek of total 40 units is not sufficent to switch from inner to outer track in the same revolution.

with -S 4 the seek time is for two seeks 10 units and can therefore satisfy the request
~~~

## 3

Do the same requests above, but change the rotation rate: -R 0.1, -R 0.5, -R 0.01. How do the times change?

~~~
Everything is really slow. Transfers take longer 1/R longer e.g. a transfer that took 30 with -R 1 takes about 300 with -R 0.1
~~~

## 4

FIFO is not always best, e.g., with the request stream -a 7,30,8, what order should the requests be processed in? Run the shortest seek-time first (SSTF) scheduler (-p SSTF) on this workload; how long should it take (seek, rotation, transfer) for each request to be served?

~~~
6 -> 7,30,8 = [45] + [30] + [300 (bc. 10 rotations)]
Order changes depending on the shortest seek time seek(8) < seek(30) -> therefore 8 first


~~~


## 5

Now use the shortest access-time first (SATF) scheduler (-p SATF). Does it
make any difference for -a 7,30,8 workload? Find a set of requests where
SATF outperforms SSTF; more generally, when is SATF better than SSTF?

~~~
Same results as with -p SATF (Shortest Access Time First) which also orders the queue depending on seek time
~~~

## 6
## 7
## 8
## 9
## 10