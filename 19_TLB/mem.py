import subprocess

for x in xrange(0, 9000,100):

 	subprocess.call(["./tlb_mes", str(x), "100"])

