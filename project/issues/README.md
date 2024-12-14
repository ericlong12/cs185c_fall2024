My project simulation failed to start due to missing data namelist file 'data' in the run directory.


**Error Message:**
ERROR: Cannot find namelist file 'data' in run directory. 
Simulation terminated. 

To fix the issue I moved the data file into the input directory and used this command:
ln -s ../input/data . 

**Error Message:**
new error message 12/13/2024

Line of code I use to transfer data from local computer to Spartan
$ scp AQH_2008 cs185c06@spartan03@sjsu.edu:/scratch/cs185c06/MITgcm/configurations/chukchi_tsunami/input/exf

Below Is the error I get whenever I try to load it in.
ssh: connect to host sjsu.edu port 22: Connection timed out
scp: Connection closed

