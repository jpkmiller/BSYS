jo391mue@ct-bsys-ws19-3:~/Documents/BSYS/17_Freespace$ python malloc.py -n 10 -H 0 -p BEST -s 0
seed 0
size 100
baseAddr 1000
headerSize 0
alignment -1
policy BEST
listOrder ADDRSORT
coalesce False
numOps 10
range 10
percentAlloc 50
allocList
compute False

ptr[0] = Alloc(3)  returned ?
List?

Free(ptr[0]) returned ?
List?

ptr[1] = Alloc(5)  returned ?
List?

Free(ptr[1]) returned ?
List?

ptr[2] = Alloc(8)  returned ?
List?

Free(ptr[2]) returned ?
List?

ptr[3] = Alloc(8)  returned ?
List?

Free(ptr[3]) returned ?
List?

ptr[4] = Alloc(2)  returned ?
List?

ptr[5] = Alloc(7)  returned ?
List?


Answer BEST

ptr[0] = Alloc(3)  returned 1000
Free List [Size 1]: [address: 1003 sz: 97]

Free(ptr[0]) returned 0
Free List [Size 2]: [address: 1000 sz: 3] [address: 1003 sz: 97]

ptr[1] = Alloc(5)  returned 1003
Free List [Size 2]: [address: 1000 sz: 3] [address: 1008 sz: 92]

Free(ptr[1]) returned 0
Free List [Size 3]: [address: 1000 sz: 3] [address: 1003 sz: 5] [address: 1008 sz: 92]

ptr[2] = Alloc(8)  returned 1008
Free List [Size 3]: [address: 1000 sz: 3] [address: 1003 sz: 5] [address: 1016 sz: 84]

Free(ptr[2]) returned 0
Free List [Size 4]: [address: 1000 sz: 3] [address: 1003 sz: 5] [address: 1008 sz: 8] [address: 1016 sz: 84]

ptr[3] = Alloc(8)  returned 1008
Free List [Size 3]: [address: 1000 sz: 3] [address: 1003 sz: 5] [address: 1016 sz: 84]

Free(ptr[3]) returned 0
Free List [Size 4]: [address: 1000 sz: 3] [address: 1003 sz: 5] [address: 1008 sz: 8] [address: 1016 sz: 84]

ptr[4] = Alloc(2)  returned 1000
Free List [Size 4]: [address: 1002 sz: 1] [address: 1003 sz: 5] [address: 1008 sz: 8] [address: 1016 sz: 84]

ptr[5] = Alloc(7)  returned 1008
Free List [Size 4]: [address: 1002 sz: 1] [address: 1003 sz: 5] [address: 1015 sz: 1] [address: 1016 sz: 84]

The free list is victim of external fragmentation. There are many small free segments that aren't coalsced

-------------------------------------------------------------------------------------------------------------

No. 2 WORST

ptr[0] = Alloc(3)  returned 1000
Free List [Size 1]: [address: 1003 sz: 97]

Free(ptr[0]) returned 0
Free List [Size 2]: [address: 1000 sz: 3] [address: 1003 sz: 97]

ptr[1] = Alloc(5)  returned 1003
Free List [Size 2]: [address: 1000 sz: 3] [address: 1008 sz: 92]

Free(ptr[1]) returned 0
Free List [Size 3]: [address: 1000 sz: 3] [address: 1003 sz: 5] [address: 1008 sz: 92]

ptr[2] = Alloc(8)  returned 1008
Free List [Size 3]: [address: 1000 sz: 3] [address: 1003 sz: 5] [address: 1016 sz: 84]

Free(ptr[2]) returned 0
Free List [Size 4]: [address: 1000 sz: 3] [address: 1003 sz: 5] [address: 1008 sz: 8] [address: 1016 sz: 84]

ptr[3] = Alloc(8)  returned 1016
Free List [Size 4]: [address: 1000 sz: 3] [address: 1003 sz: 5] [address: 1008 sz: 8] [address: 1024 sz: 76]

Free(ptr[3]) returned 0
Free List [Size 5]: [address: 1000 sz: 3] [address: 1003 sz: 5] [address: 1008 sz: 8] [address: 1016 sz: 8] [address: 1024 sz: 76]

ptr[4] = Alloc(2)  returned 1024
Free List [Size 5]: [address: 1000 sz: 3] [address: 1003 sz: 5] [address: 1008 sz: 8] [address: 1016 sz: 8] [address: 1026 sz: 74]

ptr[5] = Alloc(7)  returned 1026
Free List [Size 5]: [address: 1000 sz: 3] [address: 1003 sz: 5] [address: 1008 sz: 8] [address: 1016 sz: 8] [address: 1033 sz: 67]

There is more fragmentation because the allocator searches for the biggest chunk of memory. The difference is that there are more chunks with more memory than BEST fit. 
In summary: more ext. fragmentation with bigger segments

-------------------------------------------------------------------------------------------------------------

No. 3 FIRST

ptr[0] = Alloc(3)  returned 1000
Free List [Size 1]: [address: 1003 sz: 97]

Free(ptr[0]) returned 0
Free List [Size 1]: [address: 1000 sz: 3] [address: 1003 sz: 97]

ptr[1] = Alloc(5)  returned 1003
Free List [Size 1]: [address: 1000 sz: 3] [address: 1008 sz: 92]

Free(ptr[1]) returned 0
Free List [Size 1]: [address: 1000 sz: 3] [address: 1003 sz: 5] [address: 1008 sz: 92]

ptr[2] = Alloc(8)  returned 1008
Free List [Size 1]: [address: 1000 sz: 3] [address: 1003 sz: 5] [address: 1016 sz: 84]

Free(ptr[2]) returned 0
Free List [Size 1]: [address: 1000 sz: 3] [address: 1003 sz: 5] [address: 1008 sz: 8] [address: 1016 sz: 84]

ptr[3] = Alloc(8)  returned 1008
Free List [Size 1]: [address: 1000 sz: 3] [address: 1003 sz: 5] [address: 1016 sz: 84]

Free(ptr[3]) returned 0
Free List [Size 1]: [address: 1000 sz: 3] [address: 1003 sz: 5] [address: 1008 sz: 8] [address: 1016 sz: 84]

ptr[4] = Alloc(2)  returned 1000
Free List [Size 1]: [address: 1002 sz: 1] [address: 1003 sz: 5] [address: 1008 sz: 8] [address: 1016 sz: 84]

ptr[5] = Alloc(7)  returned 1008
Free List [Size 1]: [address: 1000 sz: 3] [address: 1003 sz: 5] [address: 1015 sz: 1] [address: 1016 sz: 84]

The allocator doesn't have to go through the whole list but just searches for the first fitting free segment


-------------------------------------------------------------------------------------------------------------

No. 4

When using ADDRSORT neither the WORST nor the BEST fit do perform differently than using SIZESORT+-, because the strategy of both allocations are to search for the one the chunk with the least waste at the end respectively the biggest chunk.
This should result in bigger chunks of free memory.

When using SIZESORT- FIRST fit has the best performance, because the biggest chunks are at the beginning of the list. External fragmentation therefore increases. 
Opposite results are achieved when SIZESORT+ is used. The FIRST fit has with big allocations worst case because the bigger chunks are at the end of the list
