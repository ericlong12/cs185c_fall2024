# External Forcing Files (EXF) for Tsunami Propagation Model

This directory contains **external forcing files** required to run the Chukchi Sea tsunami propagation model in MITgcm. These files provide atmospheric forcing conditions such as wind, temperature, and radiation fields for the year 2008.

---

## **Purpose of EXF Files**
The external forcing files are essential for prescribing time-dependent surface forcing in the ocean model. These include wind stress, atmospheric temperature, precipitation, and radiation fields.

### **File List**
| File Name          | Description                                      |
|--------------------|--------------------------------------------------|
| `VWIND_2008`       | Meridional (v) wind stress for 2008              |
| `UWIND_2008`       | Zonal (u) wind stress for 2008                   |
| `AQH_2008`         | Atmospheric specific humidity for 2008           |
| `ATEMP_2008`       | Atmospheric temperature for 2008                 |
| `LWDOWN_2008`      | Downward longwave radiation for 2008             |
| `PRECIP_2008`      | Precipitation rate for 2008                      |
| `SWDOWN_2008`      | Downward shortwave radiation for 2008            |
| `VWIND_zero`       | Zero meridional (v) wind stress                  |
| `UWIND_zero`       | Zero zonal (u) wind stress                       |

---

## **Why These Files Are Not Uploaded**
These binary files are not included in this repository because **GitHub is not intended for large data storage**. Instead, they should be stored on Spartan(HPC).

---

## **Generating EXF Files**
If you do not already have these files, they can be generated as follows:

1. **Source Data**:  
   Download atmospheric forcing data for the year **2008** from the **ECCO Drive**:
   - Link: [ECCO Drive - Version 5 Alpha ERA Data](https://ecco.jpl.nasa.gov/drive/files/Version5/Alpha/era_xx)

2. **Selecting the Year**:  
   For this project, choose the folder corresponding to **2008** under `era_xx`. This folder contains monthly atmospheric forcing data, which can be processed for the model.

3. **Account Requirement**:  
   If this is your first time accessing ECCO Drive, you will need to **create an account**:
   - Go to the ECCO Drive link above.
   - Click on **"Sign Up"** and follow the instructions.
   - Once logged in, navigate to the `era_xx` folder and download the files for 2008.

4. **Processing Notebooks**:  
   Use the provided **`Creating the External Conditions.ipynb`** notebook to:
   - Process the downloaded ECCO files.
   - Interpolate the data onto the MITgcm grid.
   - Generate the forcing files required for the model.

---

## **Directory Structure**
To ensure the model runs correctly, organize these files as follows:

input/
├── exf/
│   ├── VWIND_2008    
│   ├── UWIND_2008    
│   ├── AQH_2008      
│   ├── ATEMP_2008    
│   ├── LWDOWN_2008   
│   ├── PRECIP_2008     
│   ├── SWDOWN_2008    
│   ├── VWIND_zero     
│   └── UWIND_zero     

---

## **How to Use These Files**
1. Place all EXF files in the `input/exf/` directory.
2. Update the **`data.exf`** configuration file to point to these files:
   ```fortran
   &EXF_NML_02
   uwindfile  = 'exf/UWIND_2008',
   vwindfile  = 'exf/VWIND_2008',
   atempfile  = 'exf/ATEMP_2008',
   aqhfile    = 'exf/AQH_2008',
   precipfile = 'exf/PRECIP_2008',
   swdownfile = 'exf/SWDOWN_2008',
   lwdownfile = 'exf/LWDOWN_2008',


## If using zero wind forcing, replace UWIND_2008 and VWIND_2008 with UWIND_zero and VWIND_zero:

uwindfile  = 'exf/UWIND_zero',
vwindfile  = 'exf/VWIND_zero',

