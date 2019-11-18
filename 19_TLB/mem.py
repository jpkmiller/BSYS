import subprocess

for x in xrange(0, 3000,5):

 	subprocess.call(["./tlb_mes", str(x), "100"])

