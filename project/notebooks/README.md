# **Ocean Model Initialization and Setup**

## **Overview**

This directory contains Jupyter Notebooks for preparing the input data and configurations to run the experiment. These notebooks generate **bathymetry**, **boundary conditions**, **external forcing conditions**, **initial conditions**, and the **model grid**. 
---

## **Contents**

### 1. **Creating the Model Grid.ipynb**
- **Purpose**:  
  - Defines and visualizes the model grid for the domain of interest.  
  - Quantifies grid spacing and visualizes inter-point distances using great-circle calculations.  
- **Outputs**:  
  - Visualization of grid spacing and domain.  
- **Contribution**:  
  Sets up the structured grid that the model will use to perform calculations, ensuring proper domain representation.

---

### 2. **Creating the Bathymetry.ipynb**
- **Purpose**:  
  - Interpolates **GEBCO bathymetry** data onto the model grid.  
  - Identifies and fills isolated regions to avoid errors in model simulations.  
- **Outputs**:  
  - `ChukchiSea1.bin` (bathymetry file for the model).  
- **Contribution**:  
  Ensures that ocean depths are accurately represented, which is crucial for simulating realistic ocean dynamics.

---

### 3. **Creating the Boundary Conditions.ipynb**
- **Purpose**:  
  - Prepares **boundary conditions** (e.g., temperature, salinity, zonal and meridional velocities) by interpolating data from the **ECCO V5 Alpha state estimate** onto the model grid.  
  - Splits the fields into **east**, **north**, and **west** boundaries for model input.  
- **Outputs**:  
  The notebook generates the following binary files:  
  - Temperature (`THETA`):  
    - `THETA_east_2008`, `THETA_north_2008`, `THETA_west_2008`  
  - Salinity (`SALT`):  
    - `SALT_east_2008`, `SALT_north_2008`, `SALT_west_2008`  
  - Zonal velocity (`UVEL`):  
    - `UVEL_east_2008`, `UVEL_north_2008`, `UVEL_west_2008`  
  - Meridional velocity (`VVEL`):  
    - `VVEL_east_2008`, `VVEL_north_2008`, `VVEL_west_2008`  

- **Contribution**:  
  Provides boundary conditions required to maintain realistic ocean circulation at the domain edges. These files drive the inflow and outflow of key model fields (temperature, salinity, and velocity) at the specified boundaries.

---

### 4. **Creating the External Conditions.ipynb**
- **Purpose**:  
  - Prepares **external forcing conditions** such as wind stress, atmospheric temperature, precipitation, and radiation fields.  
  - Interpolates **ECCO external fields** onto the model grid to match the domain's spatial resolution.  
- **Outputs**:  
  The notebook generates the following binary files:  
  - `AQH_2008`: Specific humidity  
  - `ATEMP_2008`: Atmospheric temperature  
  - `LWDOWN_2008`: Longwave downward radiation  
  - `PRECIP_2008`: Precipitation  
  - `SWDOWN_2008`: Shortwave downward radiation  
  - `UWIND_2008`: Zonal wind stress  
  - `VWIND_2008`: Meridional wind stress  

- **Contribution**:  
  Simulates realistic atmospheric forcing over the ocean surface, including heat fluxes, freshwater fluxes, and wind-driven dynamics. These fields are critical for forcing surface boundary conditions in the model.

---

### 5. **Creating the Initial Conditions.ipynb**
- **Purpose**:  
  - Prepares **initial conditions** for the ocean model, including temperature, salinity, and velocities.  
  - Interpolates ECCO fields onto the model grid to initialize the model state.  
- **Outputs**:  
  The notebook generates the following binary files:  
  - `THETA_IC.bin`
