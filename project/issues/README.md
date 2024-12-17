# **Issues Log**

### 1. Missing `data` Namelist File

**Error Message:**  
ERROR: Cannot find namelist file 'data' in run directory. Simulation terminated.

**Line of Code I Use to Fix:**  
ln -s ../input/data .

**Below Is the Error I Get Whenever I Try to Run It:**  
ERROR: Cannot find namelist file 'data' in run directory.  
Simulation terminated.

---

### 2. SCP Transfer Failure

**Error Message:**  
ssh: connect to host sjsu.edu port 22: Connection timed out  
scp: Connection closed  

**Line of Code I Use to Transfer Data from Local Computer to Spartan:**  
scp AQH_2008 cs185c06@spartan03@sjsu.edu:/scratch/cs185c06/MITgcm/configurations/chukchi_tsunami/input/exf

---

### 3. Build Directory Empty After `make`

**Error Message:**  
No targets specified and no makefile found. Stop.

**Steps to Reproduce:**  
1. Ran:  
   rm -rf *  
   ../../../tools/genmake2 -mods ../code -mpi  
   make depend  
   make  
2. Result:  
   ls -> Directory empty except `genmake.log`.

---

### 4. MPI Error - Incorrect Processor Count

**Error Message:**  
EEBOOT_MINIMAL: No. of procs=     1 not equal to nPx*nPy=     8  
EEDIE: earlier error in multi-proc/thread setting  
PROGRAM MAIN: ends with fatal Error  
STOP ABNORMAL END: PROGRAM MAIN  

**Steps Taken:**  
- Tried modifying `SIZE.h` to:  
  nPx = 1, nPy = 1  
- Result: Error persists.  

---

### 5. Cannot Rebuild from Source

**Error Message:**  
Error: can't read OPTFILE="../../../tools/build_options/linux_amd64_/usr/bin/gfortran"

**Steps to Reproduce:**  
1. Cleaned build directory:  
   rm -rf *  
2. Ran:  
   ../../../tools/genmake2 -mods ../code  
   make depend  
   make  
3. Result: Build process fails due to missing `OPTFILE`.

---

### 6. Copied Executable Fails

**Error Message:**  
EEBOOT_MINIMAL: No. of procs=     1 not equal to nPx*nPy=     8  

---

### 7. Connection Timeout to Spartan Cluster

**Error Message:**  
ssh: connect to host sjsu.edu port 22: Connection timed out  
scp: Connection closed  

**Line of Code I Use to Transfer Data:**  
scp AQH_2008 cs185c06@spartan03@sjsu.edu:/scratch/cs185c06/MITgcm/configurations/chukchi_tsunami/input/exf
