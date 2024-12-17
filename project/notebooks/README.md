# **Ocean Model Initialization and Setup**

## **Overview**

This directory contains Jupyter Notebooks for preparing the input data and configurations necessary to run an ocean model using the **MITgcm** framework. The notebooks help generate **bathymetry**, **boundary conditions**, **external forcing conditions**, **initial conditions**, and the **model grid**. These inputs are critical to ensure the successful setup, execution, and analysis of the ocean model.

---

## **Contents**

### 1. **Creating the Model Grid.ipynb**
- **Purpose**:  
  - Defines and visualizes the model grid for the domain of interest.  
  - Quantifies grid spacing and visualizes inter-point distances using great-circle calculations.  
- **Outputs**:  
  - Visualization of grid spacing and grid domain.  
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
  - Prepares **boundary conditions** (e.g., temperature, salinity, velocity) by interpolating data from the **ECCO V5 Alpha state estimate** onto the model grid.  
- **Outputs**:  
  - Binary files for boundary conditions:  
    - `THETA_IC.bin` (temperature)  
    - `SALT_IC.bin` (salinity)  
    - `UVEL_IC.bin` (zonal velocity)  
    - `VVEL_IC.bin` (meridional velocity)  
- **Contribution**:  
  Provides boundary conditions necessary to drive the model and maintain realistic ocean circulation at the domain edges.

---

### 4. **Creating the External Conditions.ipynb**
- **Purpose**:  
  - Prepares **external forcing conditions** such as wind, atmospheric temperature, and precipitation using **ECCO external fields**.  
  - Interpolates these fields onto the model grid.  
- **Outputs**:  
  - Binary files for external forcing conditions:  
    - Atmospheric temperature  
    - Wind stress (zonal and meridional)  
    - Shortwave and longwave radiation  
    - Precipitation  
- **Contribution**:  
  Simulates realistic atmospheric interactions, which are essential for driving the ocean surface processes.

---

### 5. **Creating the Initial Conditions.ipynb**
- **Purpose**:  
  - Prepares **initial conditions** (e.g., temperature, salinity, velocity) to initialize the model state.  
  - Interpolates ECCO fields onto the model grid.  
- **Outputs**:  
  - Binary files for initial conditions:  
    - `THETA_IC.bin` (initial temperature)  
    - `SALT_IC.bin` (initial salinity)  
    - `UVEL_IC.bin` (initial zonal velocity)  
    - `VVEL_IC.bin` (initial meridional velocity)  
    - `ETAN_IC.bin` (surface pressure anomaly)  
- **Contribution**:  
  Provides the starting state for the model simulation, ensuring that the model evolves from a realistic ocean state.
