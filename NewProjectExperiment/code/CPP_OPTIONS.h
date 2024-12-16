#ifndef CPP_OPTIONS_H
#define CPP_OPTIONS_H

CBOP
C !ROUTINE: CPP_OPTIONS.h
C !INTERFACE:
C #include "CPP_OPTIONS.h"

C !DESCRIPTION:
C *==================================================================*
C | main CPP options file for the model:
C | Control which optional features to compile in model/src code.
C *==================================================================*
CEOP

C CPP flags controlling particular source code features

C-- Forcing code options:

C o Shortwave heating as extra term in external_forcing.F
C Note: this should be a run-time option
#define SHORTWAVE_HEATING

C o Include/exclude Geothermal Heat Flux at the bottom of the ocean
#undef ALLOW_GEOTHERMAL_FLUX

C o Allow to account for heating due to friction (and momentum dissipation)
#undef ALLOW_FRICTION_HEATING

C o Allow mass source or sink of Fluid in the interior
C   (3-D generalisation of oceanic real-fresh water flux)
#undef ALLOW_ADDFLUID

C o Include pressure loading code
#define ATMOSPHERIC_LOADING

C-- Options to discard parts of the main code:
#undef ALLOW_OBCS     /* Disable open boundary conditions */
#undef EXCLUDE_FFIELDS_LOAD
#undef STORE_LOADEDREC_TEST

C o Include/exclude phi_hyd calculation code
#define INCLUDE_PHIHYD_CALCULATION_CODE

C o Include/exclude sound speed calculation code
#undef INCLUDE_SOUNDSPEED_CALC_CODE

C-- Vertical mixing code options:
#define INCLUDE_CONVECT_CALL
#define INCLUDE_CALC_DIFFUSIVITY_CALL

C-- Time-stepping code options:
#define INCLUDE_IMPLVERTADV_CODE

C-- Model formulation options:
#define EXACT_CONSERV
#define NONLIN_FRSURF

#undef ALLOW_EDDYPSI

C-- Algorithm options:
#define ALLOW_SRCG

#endif /* CPP_OPTIONS_H */
