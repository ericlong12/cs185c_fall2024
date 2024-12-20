# Open Boundary Condition Files (OBCS) for Tsunami Propagation Model

This directory contains the **open boundary condition (OBCS)** files required to run the Chukchi Sea tsunami propagation model in MITgcm. These files specify time-dependent boundary data for velocities, temperature, and salinity along the **east**, **north**, and **west** boundaries of the domain.

---

## **Why These Files Are Not Uploaded**
The input files are not included in this repository because **GitHub is intended for code storage, not large data files**. These binary files are large and take up too much space.

---

## **Purpose of OBCS Files**
The boundary condition files define the behavior of ocean variables (velocities, temperature, and salinity) on the model. These conditions are made for water flow, temperature, and salinity exchange with the ocean system.

---

## **File List**

| File Name            | Description          |
|-----------------------|----------------------|
| `VVEL_east_2008`     | Meridional velocity  |
| `VVEL_north_2008`    | Meridional velocity  |
| `VVEL_west_2008`     | Meridional velocity  |
| `UVEL_east_2008`     | Zonal velocity       |
| `UVEL_north_2008`    | Zonal velocity       |
| `UVEL_west_2008`     | Zonal velocity       |
| `SALT_east_2008`     | Salinity             |
| `SALT_north_2008`    | Salinity             |
| `SALT_west_2008`     | Salinity             |
| `THETA_east_2008`    | Temperature          |
| `THETA_north_2008`   | Temperature          |
| `THETA_west_2008`    | Temperature          |


**Note**: There are no southern boundary files because the southern edge of the model domain is fully **bounded by land**.

---

# Open Boundary Condition Files (OBCS) for Tsunami Propagation Model

This directory contains the **open boundary condition (OBCS)** files required for running the Chukchi Sea tsunami propagation model in MITgcm. These files specify boundary data for velocities, temperature, and salinity along the **east**, **north**, and **west** boundaries of the domain.

---

## **Using OBCS Files**
To ensure boundary conditions are included in the model, the following steps have already been completed if you are downloading from this repository directly on GitHub.

---

### **1. Identifying Boundary Condition Files**
The boundary files are specified in the **`data.obcs`** configuration file. The southern boundary entries are commented out because it is already land.

```fortran
# identify files (uncomment as needed)
 OBEuFile = 'obcs/UVEL_east',
# OBSuFile = 'obcs/UVEL_south',
 OBWuFile = 'obcs/UVEL_west',
 OBNuFile = 'obcs/UVEL_north',
#
 OBEvFile = 'obcs/VVEL_east',
# OBSvFile = 'obcs/VVEL_south',
 OBWvFile = 'obcs/VVEL_west',
 OBNvFile = 'obcs/VVEL_north',
#
 OBEtFile = 'obcs/THETA_east',
# OBStFile = 'obcs/THETA_south',
 OBWtFile = 'obcs/THETA_west',
 OBNtFile = 'obcs/THETA_north',
#
 OBEsFile = 'obcs/SALT_east',
# OBSsFile = 'obcs/SALT_south',
 OBWsFile = 'obcs/SALT_west',
 OBNsFile = 'obcs/SALT_north',
#
 &
```

### **Enabling the OBCS Package**
The OBCS package is required to include open boundary conditions in the model. This package has already been enabled during compilation by adding the following line to the code/packages.conf file:

```
obcs
```
If you are setting up the repository manually, make sure that this line is included in the packages.conf file

### **Directory Structure**
The boundary condition files are organized in the following structure:

- `input/`
  - `obcs/`
    - **VVEL_east_2008**: Meridional velocity - east  
    - **VVEL_north_2008**: Meridional velocity - north  
    - **VVEL_west_2008**: Meridional velocity - west  
    - **UVEL_east_2008**: Zonal velocity - east  
    - **UVEL_north_2008**: Zonal velocity - north  
    - **UVEL_west_2008**: Zonal velocity - west  
    - **SALT_east_2008**: Salinity - east  
    - **SALT_north_2008**: Salinity - north  
    - **SALT_west_2008**: Salinity - west  
    - **THETA_east_2008**: Temperature - east  
    - **THETA_north_2008**: Temperature - north  
    - **THETA_west_2008**: Temperature - west  


