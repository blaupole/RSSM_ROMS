/*** svn $Id: fieber.h 139 2008-01-10 00:17:29Z robertson $
*******************************************************************************
** Copyright (c) 2002-2008 The ROMS/TOMS Group                               **
**   Licensed under a MIT/X style license                                    **
**   See License_ROMS.txt                                                    **
*******************************************************************************
**
** Options for Vertical Mixing Parameterization Evaluation
**
** Application flag:   Fieber
** Input script:       fieb_??.in
*/
#define ROBIN_MODEL
#define NONLINEAR

#define ROBIN
#define SOLVE3D
#define SALINITY
#define CURVGRID
#undef SPHERICAL
#define SPLINES
#define LARGE
#define BV_FREQUENCY
#define PERFECT_RESTART
#undef TS_FIXED /* diagnostic run */

#define AVERAGES
#define AVERAGES_AKV
#define AVERAGES_AKT
#define AVERAGES_FLUXES
#define ICESHELF
#undef SEAICE
#undef BTSEAICE
#define MASKING
#undef TSUNAMI

#define STATIONS

/************************************************/
/* Diagnostics Switches. Set Diagnostics on     */
/* Upper Level. Submodules activated below      */
/************************************************/
/*#undef DIAGNOSTICS*/
#undef DIAGNOSTICS_UV
#undef DIAGNOSTICS_TS
/*#define DIAGNOSTIC_TIDES */ 

/* Robin's FLUX Reporting Variables */
/* First define FLUX then define the FLUX Varuables You Want Reported */

#undef BULK_FLUXES
#undef FLUX
#undef TRANSPORTS 
#undef ENERGY_AVERAGES

/*************************************************/
/* Advection Term Switches                       */
/*************************************************/
#define UV_ADV
#undef UV_C4ADVECTION
#undef UV_U3ADV_SPLIT
#undef UV_C2ADVECTION
#undef TS_C2ADVECTION
#define UV_SMAGORINSKY
#define SMA_CFF4

#define TS_MPDATA
#undef TS_U3HADVECTION
#undef TS_U3ADV_SPLIT
/*#define TS_A4HADVECTION
#define TS_A4VADVECTION
#define TS_C4HADVECTION*/
#undef TS_C4VADVECTION

/*************************************************/
/* Diffusion Terms                               */
/*************************************************/
#define VISC_3DCOEF
#define UV_VIS2
#define UV_VIS4
#define MIX_S_UV

#define TS_DIF2
#define TS_DIF4
#define MIX_GEO_TS

#define VISC_GRID

/*************************************************/
/* Pressure Gradient and Equation of State       */
/*************************************************/
#define DJ_GRADPS_RR
/*#define PJ_GRADP*/
/*#define PJ_GRADPQ2
#define NEUMANN*/
/*#define PJ_GRADPQ4
#define NEUMANN */ /* There is also a NEUMANN option here */
#undef SASHA_GRADPS

#define NONLIN_EOS
#undef SASHA_EOS
#undef SPLIT_EOS

/**************************************************/
/* Coriolis Term                                  */
/**************************************************/
#define UV_COR

/**************************************************/
/* Bottom Drag. Applied to Bottom cell i          */
/**************************************************/
#define UV_QDRAG

/*************************************************/
/* Vertical Mixing Parameterizations             */
/* Pick One. Some subswitches included           */
/*************************************************/
#undef NN_MIXING  /* Naka... Ninno  MY replacement */
#undef JK_MIXING  /* Jody Klymak's internal mixing */
#undef RR_MIXING   /* Robin Robertson's internal mixing */
#undef POLZIN_MIXING
#define MY25_MIXING
#undef LMD_MIXING
#undef GOM_MIXING
#undef GLS_MIXING
#undef BVF_MIXING
#ifdef MY25_MIXING
# define TKE_MIXING
#elif defined GLS_MIXING 
# define TKE_MIXING
#elif defined RR_MIXING 
# define TKE_MIXING
#elif defined NN_MIXING 
# define TKE_MIXING
#elif defined NNJK_MIXING 
# define TKE_MIXING
#elif defined POLZIN_MIXING 
# define TKE_MIXING
#endif

#ifdef MY25_MIXING
# define N2S2_HORAVG
# define K_C4ADVECTION

#elif defined  LMD_MIXING
# define SHORTWAVE
# define LONGWAVE
# define ANA_SRFLUX
# define LMD_CONVEC 
# undef LMD_DDMIX 
# define LMD_RIMIX
# define LMD_SKPP
# define LMD_BKPP
#endif

/*************************************************/
/*     Ice Shelf  Switches                       */
/*************************************************/
#ifdef ICESHELF
# define JM2006_EOS
# undef ICESHELF_NOTHERMO
# undef ISOMIP
# undef HOLLANDJENKINS
# define HOLLANDJENKINS_RR
# define ICE_THERMO
#endif

/*************************************************/
/* Tides Defines to Enable Some Tidal            */
/* Features.                                     */
/*************************************************/

#define ROBINTIDES
#define SSH_TIDES
#define UV_TIDES
#ifdef SSH_TIDES 
# define FSOBC_REDUCED
# undef ZCLIMATOLOGY
# undef ADD_FSOBC
#endif
#ifdef UV_TIDES
# undef M2CLIMATOLOGY
# undef ADD_M2OBC
#endif
#define RAMP_TIDES
#undef AVERAGES_DETIDE

/**************************************************/
/* Boundary Conditions                            */
/**************************************************/
#define OBC
#undef ANA_FSOBC /* free surface from bry file */
#undef ANA_M2OBC /* 2D velocities from bry file */
#undef ANA_M3OBC /* 3D velocities from bry file */
#undef ANA_TOBC

#define RADIATION_2D
/**************************************************/
/* free surface boundary conditions               */

#define NORTH_FSOBC
#define EAST_FSOBC
#define WEST_FSOBC

#define NORTH_FSCHAPMAN
#define EAST_FSCHAPMAN
#define WEST_FSCHAPMAN

#undef NORTH_FSGRADIENT
#undef EAST_FSGRADIENT
#undef WEST_FSGRADIENT

#undef EAST_FSCLAMPED
#undef WEST_FSCLAMPED
#undef NORTH_FSCLAMPED

#undef NORTH_FSGRADIENT
#undef EAST_FSGRADIENT
#undef WEST_FSGRADIENT

/**************************************************/
/* 2D momentum boundary conditions               */

#define WEST_M2OBC       
#define EAST_M2OBC       
#define NORTH_M2OBC

#undef NORTH_M2FLATHER
#undef EAST_M2FLATHER
#undef WEST_M2FLATHER

#undef NORTH_M2CLAMPED
#undef EAST_M2CLAMPED
#undef WEST_M2CLAMPED

#define EAST_M2NUDGING
#define NORTH_M2NUDGING
#define WEST_M2NUDGING

/**************************************************/
/* 2D / T radiation boundary conditions               */

#define NORTH_M2RADIATION
#define NORTH_TRADIATION

#undef SOUTH_M3RADIATION
#undef SOUTH_TRADIATION 

#define WEST_M2RADIATION
#define WEST_TRADIATION

#define EAST_M2RADIATION
#define EAST_TRADIATION 

/**************************************************/
/* 3D momentum boundary conditions               */
/*
#define WEST_M3OBC       
#define EAST_M3OBC       
#define NORTH_M3OBC
*/
#undef NORTH_M3CLAMPED
#undef EAST_M3CLAMPED
#undef WEST_M3CLAMPED

#define NORTH_M3GRADIENT
#define EAST_M3GRADIENT
#define WEST_M3GRADIENT

/**************************************************/
/* tracer boundary conditions               */
/*
#define WEST_TOBC
#define EAST_TOBC
#define NORTH_TOBC
*/
#undef NORTH_TCLAMPED
#undef EAST_TCLAMPED
#undef WEST_TCLAMPED

#define EAST_TNUDGING
#define NORTH_TNUDGING
#define WEST_TNUDGING

/**************************************************/
/* wall boundary conditions               */
#define SOUTHERN_WALL
#undef NORTHERN_WALL
#undef EASTERN_WALL
#undef WESTERN_WALL


#undef FLOW_RELAX     /* Here is Robin'sFlow Relaxation Boundary */
/*   It will only work with   UV_U3ADV_SPLIT   at least now */

#ifdef FLOW_RELAX
# define WEST_TFLOWRELAXATION
# define EAST_TFLOWRELAXATION
# undef SOUTH_TFLOWRELAXATION
# define NORTH_TFLOWRELAXATION

# define WEST_M3FLOWRELAXATION
# define EAST_M3FLOWRELAXATION
# define SOUTH_M3FLOWRELAXATION
# define NORTH_M3FLOWRELAXATION

#else                     /* Other Open Boundary conditions */
/*
# define NORTH_M3RADIATION
# define NORTH_TRADIATION
# define SOUTH_M3RADIATION
# define SOUTH_TRADIATION 
# define WEST_M3RADIATION
# define WEST_TRADIATION
# define EAST_M3RADIATION
# define EAST_TRADIATION */
#endif


/**************************************************/
/* Volume conservation                            */
/**************************************************/

#define EAST_VOLCONS
#define WEST_VOLCONS
#define NORTH_VOLCONS
#undef SOUTH_VOLCONS
/**************************************************/
/* Tides                                          */
/**************************************************/


#define TEMP_SALINITY

#ifdef TEMP_SALINITY

/* Here are fluxes for a basic run with just temp and salinity */


/***************************************************/
/* Various Functional Modules. Some interdepencies */
/* Outlined in the analytical idefs below.         */
/****************************************************/

#define ANA_WINDS
#define ANA_HUMIDITY
#define ANA_CLOUD
#define ANA_TAIR
#define ANA_PAIR
#define ANA_RAIN
#define ANA_SRFLUX
#undef ANA_SMFLUX
#define ANA_BTFLUX
#define ANA_BSFLUX
#define SHORTWAVE
#define LONGWAVE
#endif

/***************************************************/
/* surface tracers                                 */
/***************************************************/
#undef ANA_SSFLUX
#undef ANA_STFLUX
#undef ANA_SST

#define QCORRECTION /* heat transfer correction as a function of imposed SST and model SST */
/*************************************************/
/* special keywords */
#undef SJ_M2OBC
#undef NO_FORCING
#define RM_SUPERCOOLING
#define USE_POT_Tf