import subprocess
print "start"



for x in xrange(0, 50000,50):
	subprocess.call(["./tlb_mes", str(x+1), "100"])
	print x
