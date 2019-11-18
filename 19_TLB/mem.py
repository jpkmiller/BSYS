import subprocess

def main():
	times = []
	repeat = 10
	print("repeats for " + str(100000 / repeat) + " times")
	for x in range(100000 / repeat):
		times.append(subprocess.call(["./tlb_mes", str(x + 1), str(repeat)]))
main()
