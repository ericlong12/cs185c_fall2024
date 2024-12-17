# **Ocean Model Initialization and Setup**

## **Overview**

This directory contains Jupyter Notebooks for initializing and setting up the ocean model using the **MITgcm** framework. The notebooks prepare key inputs such as **bathymetry**, **initial conditions**, **external forcing**, and **boundary conditions** required for running the model. The steps included here follow the guidelines for **CS 185C: Introduction to Ocean Modeling**.

---

## **Contents**

1. **Creating the Bathymetry.ipynb**  
   - Generates the bathymetry file (`ChukchiSea1.bin`) required for the model grid.  
   - **Input:** Raw bathymetry data.  
   - **Output:** Formatted bathymetry file.

2. **Creating the Boundary Conditions.ipynb**  
   - Prepares the **boundary conditions** for the model.  
   - **Input:** External data sources for forcing.  
   - **Output:** Boundary condition files to be read by the model.

3. **Creating the External Conditions.ipynb**  
   - Organizes and formats external forcing data (e.g., temperature, salinity, etc.).  
   - **Input:** Forcing datasets.  
   - **Output:** External condition files (e.g., `THETA_IC.bin`, `SALT_IC.bin`).

4. **Creating the Initial Conditions.ipynb**  
   - Creates the **initial condition fields** such as temperature, salinity, and velocity.  
   - **Input:** Parameterized initial datasets.  
   - **Output:** `ETAN_IC.bin`, `UVEL_IC.bin`, `VVEL_IC.bin`.

5. **Creating the Model Grid.ipynb**  
   - Sets up the **grid geometry** and grid parameters for the model simulation.  
   - **Input:** Grid specifications.  
   - **Output:** Model grid setup.

6. **README.md**  
   - Project documentation.

---

## **Steps to Run the Notebooks**

1. Clone the project repository:
   ```bash
   git clone <repository_link>
   cd <notebooks_directory>
