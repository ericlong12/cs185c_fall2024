My project simulation failed to start due to missing data namelist file 'data' in the run directory.


**Error Message:**
ERROR: Cannot find namelist file 'data' in run directory. 
Simulation terminated. 

To fix the issue I moved the data file into the input directory and used this command:
ln -s ../input/data . 
