# Memory tests

The data were tracked by HTOP and BTOP commands on Ubuntu 22.04 system with ROS2 Humble installed.

## Uninitialised box

- Master:
    - 60.2 MiB @ 19 Threads; 24.2 Mib (/usr/bin/python3 /opt/ros/humble/bin/ros2 run dronehive box_node )
        - /usr/bin/python3 /home/fildo/EIT/EiRT-AscenD-Robotics/ros2_ws/install/dronehive/lib/dronehive/box_node
        - Main Thread: 41156 KiB
        - Worker Threads: 1089 KiB

- Slave:
    - 58.1 MiB @ 12 Threads
        - Main Thread: 41136 KiB
        - Worker Threads: 732 KiB

## Initialised box


- Master:
**NO salve box connected/initialised**
    - 70.2 MiB @ 20 Threads
        - Main Thread: 41156 KiB
        - Worker Threads: 1226M KiB

Lexicology:
- VIRT(MiB): Virtual Memory Size
    - Includes python interpreter, shared libraries, Memory-mapped files, unused reserved regions.
    - Not all of this exists in Ram

- RES(MiB): Resident Memory Size
    - Physical RAM currently occupied by this process
    - Excludes swapped-out pages and includes shared memory
    - This is the main number to consider when evaluating memory usage

- SHR(MiB): Shared Memory Size
    - Portion of a process's memory that is shared with other processes
    - Includes shared libraries and other shared resources

- VmRSS: Resident Set Size == RES(MiB) in KiB
    - The non-swapped physical memory a task has used (in KiB)

- RssAnon: Anonymous Resident Set Size
    - Portion of VmRSS that is not backed by any file
    - Includes heap, stack, and memory allocated via mmap without a file

With HMI started
|BOX|INIT|nSlaves|nDrones|VIRT(MiB)|RES(MiB)|SHR(MiB)|THREADS|TOTAL(MiB)|
|---|----|-------|-------|---------|--------|--------|-------|----------|
|Master|0|0|0|1152|60.18|27.36|19|60.1|
|Master|1|0|0|1226|68.43|27.36|20|68.4|
|Slave1|0|-|0| 796|56.63|22.58|12|24.2|
|Slave1|1|-|0| 868|58.26|22.83|13|24.2|

1 Slave box 1 drone connected/initialised
|BOX|INIT|nSlaves|nDrones|VIRT(MiB)|RES(MiB)|SHR(MiB)|THREADS|TOTAL(MiB)|
|---|----|-------|-------|---------|--------|--------|-------|----------|
|Master1|1|1|0|1227|73.66|28.84|20|68.4|
|Slave01|1|-|1| 868|58.26|22.83|11|24.2|

2 Slave box 1 drone connected/initialised
|BOX|INIT|nSlaves|nDrones|VIRT(MiB)|RES(MiB)|SHR(MiB)|THREADS|TOTAL(MiB)|
|---|----|-------|-------|---------|--------|--------|-------|----------|
|Master1|1|2|0|1229|74.16|29.09|20|74.1|
|Slave01|1|-|1| 870|62.62|23.82|13|62.6|
|Slave02|1|-|0| 734|57.67|22.87|12|57.6|

5 Slave box 1 drone connected/initialised
|BOX|INIT|nSlaves|nDrones|VIRT(MiB)|RES(MiB)|SHR(MiB)|THREADS|TOTAL(MiB)|
|---|----|-------|-------|---------|--------|--------|-------|----------|
|Master1|1|5|0|1230|74.53|29920|20|74.5|
|Slave01|1|-|1| 872|58.25|24648|13|62.8|
|Slave02|1|-|0| 736|59.61|24164|12|58.9|
|Slave03|1|-|0| 736|59.30|23808|12|59.3|
|Slave04|1|-|0| 736|60444|23680|12|59.0|
|Slave05|1|-|0| 736|60336|23676|12|59.6|

5 Slave box 1 drone connected/initialised
|BOX|INIT|nSlaves|nDrones|VIRT(MiB)|RES(MiB)|SHR(MiB)|THREADS|TOTAL(MiB)|
|---|----|-------|-------|---------|--------|--------|-------|----------|
|Master1|1|20|0|1240.04|73.91|22.61|20|73.9|
|Slave01|1|- |1| 881.97|66.62|22.08|13|62.8|
|Slave02|1|- |1| 745.77|65.05|21.87|12|58.9|
|Slave03|1|- |1| 745.75|65.30|21.88|12|59.3|
|Slave04|1|- |1| 745.71|65.15|21.75|12|59.0|
|Slave05|1|- |1| 746.11|65.73|21.97|12|59.6|
|Slave06|1|- |1| 818.02|65.91|21.85|13|62.8|
|Slave07|1|- |1| 817.80|66.17|21.98|12|58.9|
|Slave08|1|- |1| 817.97|66.05|21.94|12|59.3|
|Slave09|1|- |1| 817.70|66.16|22.09|12|59.0|
|Slave10|1|- |1| 818.25|65.98|21.97|12|59.6|
|Slave11|1|- |1| 818.23|65.84|21.83|13|62.8|
|Slave12|1|- |1| 817.82|66.18|22.25|12|58.9|
|Slave13|1|- |1| 817.79|65.77|21.85|12|59.3|
|Slave14|1|- |1| 817.77|65.93|21.99|12|59.0|
|Slave15|1|- |1| 746.06|65.34|21.82|12|59.6|
|Slave16|1|- |1| 817.82|65.66|22.00|13|62.8|
|Slave17|1|- |1| 817.88|65.64|21.85|12|58.9|
|Slave18|1|- |1| 818.11|65.57|21.71|12|59.3|
|Slave19|1|- |1| 817.79|65.83|21.86|12|59.0|
|Slave20|1|- |1| 817.75|65.56|21.96|12|59.6|

1176.59 77.91
 817.99 66.00
 817.18 66.21
 817.07 65.96
 745.09 66.02
 817.05 65.92
 817.14 65.63
 817.11 65.67
 817.14 66.23
 817.19 65.82
 817.38 66.37
 817.06 65.81
 817.20 65.92
 817.64 66.13
 817.05 65.88
 817.17 65.25
 817.04 66.14
 817.19 66.20
 817.05 66.35
 817.19 66.03
 817.09 66.11

1181.75 82.04
822.87 70.23
822.83 70.39
822.60 70.05
822.80 69.63
822.59 69.82
822.62 70.12
822.51 69.91
822.68 70.39
823.51 70.00
822.46 70.37
822.57 70.33
822.57 69.93
822.57 70.23
822.70 70.27
822.57 70.18
822.77 69.82
822.59 70.50
822.64 70.14
822.41 69.33
822.75 70.16
822.57 70.17
822.71 70.03
822.52 69.77
822.78 70.39
822.70 69.83
822.59 69.80
822.56 70.41
822.54 70.07
822.56 70.55






















**ONE salve box connected/initialised**
    - 71 MiB @ 20 Threads
        - Main Thread: 41156 KiB
        - Worker Threads: 1227M KiB

> **NOTE:** This value stays also with 2 more uninitialised slave boxes the memory size per worker thread is increased to 1228 KiB

**TWO salve boxes connected/initialised**
    - 71 MiB @ 20 Threads
        - Main Thread: 41156 KiB
        - Worker Threads: 1227M KiB

- Slave:
    - 59.5 MiB @ 13 Threads
        - Main Thread: 41136 KiB
        - Worker Threads: 869 KiB
