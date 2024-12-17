# **Ocean Model Initialization and Setup**

## **Overview**

This directory contains Jupyter Notebooks for preparing the input data and configurations to run the experiment. These notebooks generate **bathymetry**, **boundary conditions**, **external forcing conditions**, **initial conditions**, and the **model grid**.

---

## **Contents**

### 1. **Creating the Model Grid.ipynb**
- **Purpose**:  
  Sets up the grid that the model will use.

---

### 2. **Creating the Bathymetry.ipynb**
- **Purpose**:  
  - Interpolates **GEBCO bathymetry** data onto the model grid.  

- **Outputs**:  
  - `ChukchiSea1.bin` (bathymetry file for the model).  

---

### 3. **Creating the Boundary Conditions.ipynb**
- **Purpose**:  
  - Prepares **boundary conditions** such as temperature, salinity, zonal velocity, and meridional velocity.  
  - Uses data from the **ECCO V5 Alpha** state estimate.  
  - Splits the fields into **east**, **north**, and **west** boundaries for model input.  

- **Outputs**:  
  The notebook generates the following binary files:  

  - **Temperature (`THETA`)**:  
    - `THETA_east_2008`  
    - `THETA_north_2008`  
    - `THETA_west_2008`  

  - **Salinity (`SALT`)**:  
    - `SALT_east_2008`  
    - `SALT_north_2008`  
    - `SALT_west_2008`  

  - **Zonal velocity (`UVEL`)**:  
    - `UVEL_east_2008`  
    - `UVEL_north_2008`  
    - `UVEL_west_2008`  

  - **Meridional velocity (`VVEL`)**:  
    - `VVEL_east_2008`  
    - `VVEL_north_2008`  
    - `VVEL_west_2008`  

---

### 4. **Creating the External Conditions.ipynb**
- **Purpose**:  
  - Prepares **external forcing conditions** such as wind stress, atmospheric temperature, precipitation, and radiation fields.  
  - Interpolates **ECCO external fields** onto the model grid.  

- **Outputs**:  
  The notebook generates the following binary files:  
  - `AQH_2008` : Specific humidity  
  - `ATEMP_2008` : Atmospheric temperature  
  - `LWDOWN_2008` : Longwave downward radiation  
  - `PRECIP_2008` : Precipitation  
  - `SWDOWN_2008` : Shortwave downward radiation  
  - `UWIND_2008` : Zonal wind stress  
  - `VWIND_2008` : Meridional wind stress  

---

### 5. **Creating the Initial Conditions.ipynb**
- **Purpose**:  
  - Prepares **initial conditions** for the ocean model, including temperature, salinity, and velocities.  
  - Interpolates **ECCO fields** onto the model grid.  

- **Outputs**:  
  The notebook generates the following binary files:  
  - `THETA_IC.bin` : Initial temperature  
  - `SALT_IC.bin` : Initial salinity  
  - `UVEL_IC.bin` : Initial zonal velocity  
  - `VVEL_IC.bin` : Initial meridional velocity  
  - `ETAN_IC.bin` : Initial surface pressure anomaly  
