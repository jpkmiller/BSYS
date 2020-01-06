# 1

<<<<<<< HEAD
How does the
output change from run to run?

=======
>>>>>>> 4823ec20f192aaa6b5ebcfc3d7699e03af4ca7fd
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

<<<<<<< HEAD
Now add the -d flag, and change the number of loops (-l) from 1 to higher
numbers. What happens? Does the code (always) deadlock?

The code never deadlocks

# 3
=======

>>>>>>> 4823ec20f192aaa6b5ebcfc3d7699e03af4ca7fd
