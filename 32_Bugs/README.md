# 1

How does the
output change from run to run?

./vector-deadlock -n 2 -l 1 -v
->add(0, 1)
<-add(0, 1)
              ->add(0, 1)
              <-add(0, 1)

./vector-deadlock -n 2 -l 1 -v
              ->add(0, 1)
              <-add(0, 1)
->add(0, 1)
<-add(0, 1)

Orders differ in which the threads run


# 2

Now add the -d flag, and change the number of loops (-l) from 1 to higher
numbers. What happens? Does the code (always) deadlock?

The code never deadlocks

# 3