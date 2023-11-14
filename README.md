
# Memory Access Scheduler

Operating Systems 2 work, simulator of a memory access scheduler made in C++;

#### To be able to run the program, the Linux operating system must be used.

On start:

![image](https://github.com/lucasfriedrichh/memoryAccessScheduler/assets/91904246/76f2a8f8-ef9c-4d8a-aa0b-d4cbf643896c)


Separated into 5 different algorithms:
### FCFS:
FCFS (First Come, First Served) is a straightforward scheduling algorithm in computing. It prioritizes tasks based on their arrival order, with the first task to arrive being the first to be executed. While easy to implement, it may not be the most efficient, as shorter tasks can get delayed behind longer ones.

![image](https://github.com/lucasfriedrichh/memoryAccessScheduler/assets/91904246/e8caf50b-825f-45f4-9601-5272a269aac5)



### SSTF:
SSTF, or Shortest Seek Time First, is a disk scheduling algorithm that optimizes disk arm movement by selecting the request with the shortest seek time. In simpler terms, it prioritizes the data request that is closest to the current position of the disk arm. This minimizes the time it takes to access data and reduces overall disk latency. However, SSTF may lead to a potential issue called "starvation," where some requests are continually neglected if there's a constant influx of closer requests.

![image](https://github.com/lucasfriedrichh/memoryAccessScheduler/assets/91904246/539b31a2-0d80-42f6-a20f-4c87f740174a)


### Scan (Elevator):
Scan, also known as the Elevator algorithm, is a disk scheduling method that mimics an elevator's movement. The disk arm serves requests in one direction until it reaches the end, then reverses. This minimizes seek time but can lead to "head starvation" for requests at disk extremes.

![image](https://github.com/lucasfriedrichh/memoryAccessScheduler/assets/91904246/d7665a88-3dd8-4d86-8d93-69acd5fe7949)


### Circular SCAN:
Circular SCAN, or C-SCAN, is a disk scheduling algorithm that forms a circular path, eliminating head starvation seen in SCAN. It efficiently services requests along this path, but delays may occur for requests on the outer track, requiring a full disk revolution.

![image](https://github.com/lucasfriedrichh/memoryAccessScheduler/assets/91904246/05f2eb6a-ccb1-4a7c-a9be-40adf00d67ee)

### C-look:
C-Look is a disk scheduling algorithm similar to C-SCAN. It services requests only in the direction of the disk arm's current movement, without the circular back-and-forth motion of C-SCAN. This eliminates delays for requests on the outer track since there is no need to traverse the entire disk. C-Look provides efficient disk I/O with reduced seek time and is particularly useful when there is a predictable and continuous request pattern.

![image](https://github.com/lucasfriedrichh/memoryAccessScheduler/assets/91904246/fc0ac978-df45-4833-a822-ce4a04a63852)
