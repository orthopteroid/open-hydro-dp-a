#pragma once

#ifdef __cplusplus
	extern "C" {
#endif

#define DP_SOLVE_POWER_USE_HK (1)
#define DP_SOLVE_FLOW_USE_HK  (2)

#define DP_CONV_UNDEFINED (0)
#define DP_CONV_IMPERIAL  (62.4 /* POUNDSPERCUBICFT */ * 0.746 /* KWPERHP */ / 550 /* FTPOUNDSPERHP */ ) /* from cfs */
#define DP_CONV_METRIC    (1000.0 /* WATERDENSITYINKGPERM3 */ * 9.81 /* ACCELDUETOGRAVITY */ / 1000 /* WATTSPERKW */ ) /* from cms */

#define DP_WEIGHT_RELATIVE		(1<<30)
#define DP_WEIGHT_CODEMASK		((1<<16) - 1)
#define DP_WEIGHT_DEFAULT		(0)
#define DP_WEIGHT_EQUAL			(1)
#define DP_WEIGHT_MAXPOWER		(2) /* preference given to larger units */
#define DP_WEIGHT_MAXFLOW		(3)
#define DP_WEIGHT_MINPOWER		(4) /* preference given to smaller units */
#define DP_WEIGHT_MINFLOW		(5)

#define FLOAT double
#define UINT32 unsigned long int

UINT32 guUserStepCount;
UINT32 guProblemStepCount;
FLOAT gfConvFactor;
UINT32 guSolveMode;
UINT32 guWeightCode;
FLOAT gfHeadCurr;
UINT32 guStates;

void stdout_redirect( char* szOutfile );
void stdout_unredirect( void );

void curve_register_builtins( void );
UINT32 curve_register_n( UINT32 np, FLOAT* pCap, FLOAT* pPow, FLOAT* pEff );
UINT32 turbine_register_n( UINT32 uType, FLOAT h, FLOAT q, FLOAT p );
void turbine_weight( UINT32 uTurbine, FLOAT fWeight );

void dp_cleanup( void );
void dp_assign_weights( void );
void dp_malloc( void );
void dp( void );

void dp_print_solution( void );

void curve_cleanup( void );
void turbine_cleanup( void );
void track_freeallblocks( void );

FLOAT* gpfSolutionAllocations;
FLOAT* gpfOtherSolutionAllocations;
FLOAT* gpfHKSolutionAverages;

FLOAT* gpfSolution;
FLOAT* gpfOtherSolution;
FLOAT* gpfHKSolution;

#ifdef __cplusplus
	}
#endif
