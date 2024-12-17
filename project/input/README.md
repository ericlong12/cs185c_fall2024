# Input Files for Tsunami Propagation Model

This directory is intended to hold the **input files** required to run the **Chukchi Sea tsunami propagation model** in MITgcm. These files contain the initial conditions, bathymetry, and other essential model inputs.

---

## **Purpose of Input Files**
The input files listed below are required for initializing and running the ocean model:

| File Name          | Description                                    |
|--------------------|------------------------------------------------|
| `VVEL_IC.bin`      | Initial conditions for meridional velocity (v) |
| `UVEL_IC.bin`      | Initial conditions for zonal velocity (u)      |
| `THETA_IC.bin`     | Initial temperature field                     |
| `SALT_IC.bin`      | Initial salinity field                        |
| `ETAN_IC.bin`      | Initial sea surface height perturbation       |
| `ChukchiSea1.bin`  | Bathymetry data for the Chukchi Sea domain     |

---

## **Why These Files Are Not Uploaded**
The input files are not included in this repository because **GitHub is intended for code storage, not large data files**. These binary files are large and take up too much space.

---

## **Where to Obtain These Files**
To reproduce the results of this project, you need to obtain or generate these files:

1. **Bathymetry (`ChukchiSea1.bin`)**:  
   Generated using the **`Creating the Bathymetry.ipynb`** notebook, which processes GEBCO bathymetric data.

2. **Initial Conditions (VVEL, UVEL, THETA, SALT, ETAN)**:  
   Created using ECCO V5 Alpha state estimate data with the **`Creating the Initial Conditions.ipynb`** notebook.

---

## **How to Use These Files**
1. Place all input files in the `input/` directory:
