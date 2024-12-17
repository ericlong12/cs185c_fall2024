# Tsunami Travel Speeds in the Chukchi Sea

This project investigates the speed at which a tsunami travels across the Chukchi Sea. The analysis involves building and running an ocean model configuration in MITgcm and analyzing the output to determine the tsunami's propagation speeds under specified conditions.

## Project Description
The science question addressed in this project is:

**How fast does a tsunami travel across the Chukchi Sea?**

To answer this question, I have constructed a regional model of the Chukchi Sea using MITgcm. The model domain is created by generating a structured grid with a resolution of 1/12 degrees in the longitudinal direction (`delX`) and 1/16 degrees in the latitudinal direction (`delY`), spanning 360 rows and 240 columns. The grid is anchored at a longitude of -158 degrees (`xgOrigin`) and a latitude of 65 degrees (`ygOrigin`), covering the shallow Chukchi Sea region. Bathymetric data from the GEBCO dataset is interpolated onto this grid using the `Creating the Bathymetry.ipynb` notebook, producing the file `ChukchiSea1.bin`. 

The boundary conditions for temperature, salinity, and velocity fields are prepared using the `Creating the Boundary Conditions.ipynb` notebook, which processes ECCO V5 Alpha state estimate data and outputs separate binary files for the east, north, and west boundaries. Similarly, external forcing conditions such as wind stress, atmospheric temperature, precipitation, and radiation fields are interpolated onto the model grid using the `Creating the External Conditions.ipynb` notebook. The initial conditions, including temperature, salinity, velocities, and surface pressure, are also generated using ECCO data with the `Creating the Initial Conditions.ipynb` notebook.

By running the model with and without tsunami forcing on the Spartan HPC cluster, I aim to estimate the tsunami's propagation speed and identify how it varies across the grid. I anticipate faster wave propagation in shallow regions and slower propagation in areas with complex bathymetry. The outputs of this project include wave speed calculations, time-series plots, and visualizations that illustrate the tsunami's progression across the Chukchi Sea.

## Reproducing Model Results
The following steps outline how to construct the model files, configure and run the model, and analyze the results.

### Step 1: Create the Model Files
Generate the required input files using appropriate tools or scripts (notebooks provided where applicable):
- **Model Grid:** Defines the resolution and extent of the Chukchi Sea region.
- **Bathymetry File:** Specifies the sea floor depth using realistic data (`ChukchiSea1.bin`).
- **Initial Conditions:** Provides starting conditions for ocean variables such as temperature, salinity, and velocity fields.
- **External Forcing Conditions:** Specifies external forcing such as surface pressure perturbations for the tsunami event.
- **Boundary Conditions:** Defines open boundary conditions for the regional model domain.

Place all input files in the `input/` directory.

### Step 2: Add Files to the Computing Cluster
To run the model on the Spartan HPC cluster:
1. Clone the MITgcm repository into your scratch directory:
   ```bash
   cd /scratch/[username]
   git clone https://github.com/MITgcm/MITgcm.git
   ```
2. Create a new configuration directory for this project:
   ```bash
   mkdir MITgcm/configurations/chukchi_tsunami
   ```
3. Transfer the following directories from your local system to the cluster using `scp`:
   - `code/`
   - `input/`
   - `namelist/`
   ```bash
   scp -r code/ input/ namelist/ [username]@spartan03.sjsu.edu:/scratch/[username]/MITgcm/configurations/chukchi_tsunami/
   ```

### Step 3: Compile the Model
Once all files are on the Spartan cluster, compile the model:
1. Navigate to the configuration directory:
   ```bash
   cd /scratch/[username]/MITgcm/configurations/chukchi_tsunami
   ```
2. Create a build directory and run the compilation commands:
   ```bash
   mkdir build
   cd build
   ../../../tools/genmake2 -of ../../../tools/build_options/linux_amd64_gfortran -mods ../code -mpi
   make depend
   make
   ```

### Step 4.1: Run the Model with Forcing
After the compilation is complete, run the model with the tsunami forcing. Move to the run directory, link everything from `input` and `code`, and submit the job script:
```bash
sbatch cs185c.slm
```

### Step 4.2: Run the Model without Forcing
To compare the propagation of the tsunami, run the model without forcing. First, create a new run directory:
```bash
mkdir run_no_forcing
cd run_no_forcing
ln -s ../input/* .
ln -s ../build/mitgcmuv .
```
Next, edit the `data.exf` file to remove the tsunami forcing inputs. For example, comment out or modify the forcing file paths:
```fortran
&EXF_NML_02
uwindfile = 'exf/UWIND',
vwindfile = 'exf/VWIND',
atempfile = 'exf/ATEMP',
aqhfile   = 'exf/AQH',
precipfile = 'exf/PRECIP',
swdownfile = 'exf/SWDOWN',
lwdownfile = 'exf/LWDOWN',
# runoffline = 'exf/RUNOFF',
```
Finally, submit the job script again:
```bash
sbatch cs185c.slm
```

### Step 5: Analyze the Results
Once the model run is complete, analyze the output files to determine tsunami propagation speeds:
1. **Notebook for Analysis:** Use the provided `notebooks/Analyze_Tsunami_Speed.ipynb` to:
   - Calculate tsunami wave speeds across the domain.
   - Generate time-series plots of water surface elevation.
   - Create visualizations of tsunami propagation across the Chukchi Sea.
2. **Output Files:** The key output files (diagnostics and surface elevation data) will be located in the `diags/` directory.

### Step 6: Visualize Results
Use the analysis notebook to generate:
- **Plots:** Visualize spatial and temporal changes in sea surface elevation.
- **Movies:** Create animations showing the progression of the tsunami wave across the Chukchi Sea.

## Directory Structure
```
chukchi_tsunami/
|-- code/               
|-- input/               
|-- namelist/            
|-- build/              
|-- run/                 
|-- run_no_forcing/      
|-- diags/              
|-- notebooks/          
|-- figures/             
|-- cs185c.slm          
```

