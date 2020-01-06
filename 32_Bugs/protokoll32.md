# 1

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


