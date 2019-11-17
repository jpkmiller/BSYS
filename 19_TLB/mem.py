import subprocess

def main():
	times = []
	for x in range(80):
		subprocess.Popen(["./tlb_mes", str(x + 1), "1000000"])
main()
