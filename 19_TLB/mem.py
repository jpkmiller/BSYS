import subprocess

for x in xrange(0, 5000,5):

 	subprocess.call(["./tlb_mes", str(x), "100"])

