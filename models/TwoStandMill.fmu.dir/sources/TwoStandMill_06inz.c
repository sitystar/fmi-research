/* Initialization */
#include "TwoStandMill_model.h"
#include "TwoStandMill_11mix.h"
#include "TwoStandMill_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void TwoStandMill_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
Ti_1_safe = max(Ti_sp_1, 1e-4)
*/
void TwoStandMill_eqFunction_1(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[47]] /* Ti_1_safe variable */) = fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[16]] /* Ti_sp_1 PARAM */),1e-4);
  threadData->lastEquationSolved = 1;
}

/*
equation index: 2
type: SIMPLE_ASSIGN
Ti_2_safe = max(Ti_sp_2, 1e-4)
*/
void TwoStandMill_eqFunction_2(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[48]] /* Ti_2_safe variable */) = fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[17]] /* Ti_sp_2 PARAM */),1e-4);
  threadData->lastEquationSolved = 2;
}

/*
equation index: 3
type: SIMPLE_ASSIGN
T_f_safe = max(T_filt_force, 1e-4)
*/
void TwoStandMill_eqFunction_3(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,3};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[45]] /* T_f_safe variable */) = fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[14]] /* T_filt_force PARAM */),1e-4);
  threadData->lastEquationSolved = 3;
}

/*
equation index: 4
type: SIMPLE_ASSIGN
T_s_safe = max(T_filt_sigma, 1e-4)
*/
void TwoStandMill_eqFunction_4(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,4};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[46]] /* T_s_safe variable */) = fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[15]] /* T_filt_sigma PARAM */),1e-4);
  threadData->lastEquationSolved = 4;
}

/*
equation index: 5
type: SIMPLE_ASSIGN
wmin_1 = 1000.0 * v_min / R_1
*/
void TwoStandMill_eqFunction_5(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,5};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[73]] /* wmin_1 variable */) = (1000.0) * (DIVISION_SIM((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[24]] /* v_min PARAM */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[10]] /* R_1 PARAM */),"R_1",equationIndexes));
  threadData->lastEquationSolved = 5;
}

/*
equation index: 6
type: SIMPLE_ASSIGN
wmax_1 = 1000.0 * v_max / R_1
*/
void TwoStandMill_eqFunction_6(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,6};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[71]] /* wmax_1 variable */) = (1000.0) * (DIVISION_SIM((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[23]] /* v_max PARAM */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[10]] /* R_1 PARAM */),"R_1",equationIndexes));
  threadData->lastEquationSolved = 6;
}

/*
equation index: 7
type: SIMPLE_ASSIGN
wmin_2 = 1000.0 * v_min / R_2
*/
void TwoStandMill_eqFunction_7(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,7};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* wmin_2 variable */) = (1000.0) * (DIVISION_SIM((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[24]] /* v_min PARAM */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[11]] /* R_2 PARAM */),"R_2",equationIndexes));
  threadData->lastEquationSolved = 7;
}

/*
equation index: 8
type: SIMPLE_ASSIGN
wmax_2 = 1000.0 * v_max / R_2
*/
void TwoStandMill_eqFunction_8(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,8};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[72]] /* wmax_2 variable */) = (1000.0) * (DIVISION_SIM((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[23]] /* v_max PARAM */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[11]] /* R_2 PARAM */),"R_2",equationIndexes));
  threadData->lastEquationSolved = 8;
}

/*
equation index: 9
type: SIMPLE_ASSIGN
k_sig = 1000.0 * E_mat / L_dist
*/
void TwoStandMill_eqFunction_9(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,9};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* k_sig variable */) = (1000.0) * (DIVISION_SIM((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[0]] /* E_mat PARAM */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[8]] /* L_dist PARAM */),"L_dist",equationIndexes));
  threadData->lastEquationSolved = 9;
}
extern void TwoStandMill_eqFunction_111(DATA *data, threadData_t *threadData);


void TwoStandMill_eqFunction_11(DATA*, threadData_t*);
void TwoStandMill_eqFunction_12(DATA*, threadData_t*);
void TwoStandMill_eqFunction_13(DATA*, threadData_t*);
void TwoStandMill_eqFunction_14(DATA*, threadData_t*);
void TwoStandMill_eqFunction_15(DATA*, threadData_t*);
void TwoStandMill_eqFunction_16(DATA*, threadData_t*);
/*
equation index: 25
indexNonlinear: 0
type: NONLINEAR

vars: {ho_1}
eqns: {11, 12, 13, 14, 15, 16}
*/
void TwoStandMill_eqFunction_25(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,25};
  int retValue;
  infoStreamPrint(OMC_LOG_DT, 0, "Solving nonlinear system 25 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
  /* get old value */
  data->simulationInfo->nonlinearSystemData[0].nlsxOld[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */);
  retValue = solve_nonlinear_system(data, threadData, 0);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,25};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 25 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */) = data->simulationInfo->nonlinearSystemData[0].nlsx[0];
  threadData->lastEquationSolved = 25;
}
extern void TwoStandMill_eqFunction_130(DATA *data, threadData_t *threadData);


void TwoStandMill_eqFunction_27(DATA*, threadData_t*);
void TwoStandMill_eqFunction_28(DATA*, threadData_t*);
void TwoStandMill_eqFunction_29(DATA*, threadData_t*);
void TwoStandMill_eqFunction_30(DATA*, threadData_t*);
void TwoStandMill_eqFunction_31(DATA*, threadData_t*);
void TwoStandMill_eqFunction_32(DATA*, threadData_t*);
/*
equation index: 41
indexNonlinear: 1
type: NONLINEAR

vars: {ho_2}
eqns: {27, 28, 29, 30, 31, 32}
*/
void TwoStandMill_eqFunction_41(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,41};
  int retValue;
  infoStreamPrint(OMC_LOG_DT, 0, "Solving nonlinear system 41 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
  /* get old value */
  data->simulationInfo->nonlinearSystemData[1].nlsxOld[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */);
  retValue = solve_nonlinear_system(data, threadData, 1);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,41};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 41 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */) = data->simulationInfo->nonlinearSystemData[1].nlsx[0];
  threadData->lastEquationSolved = 41;
}
extern void TwoStandMill_eqFunction_149(DATA *data, threadData_t *threadData);


/*
equation index: 43
type: SIMPLE_ASSIGN
M_dyn_1 = $START.M_dyn_1
*/
void TwoStandMill_eqFunction_43(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,43};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* M_dyn_1 STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[0] /* M_dyn_1 STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 43;
}
extern void TwoStandMill_eqFunction_105(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_131(DATA *data, threadData_t *threadData);


/*
equation index: 46
type: SIMPLE_ASSIGN
M_dyn_2 = $START.M_dyn_2
*/
void TwoStandMill_eqFunction_46(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,46};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* M_dyn_2 STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[1] /* M_dyn_2 STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 46;
}
extern void TwoStandMill_eqFunction_104(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_150(DATA *data, threadData_t *threadData);


/*
equation index: 49
type: SIMPLE_ASSIGN
omega_1 = $START.omega_1
*/
void TwoStandMill_eqFunction_49(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,49};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* omega_1 STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[8] /* omega_1 STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 49;
}
extern void TwoStandMill_eqFunction_132(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_96(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_97(DATA *data, threadData_t *threadData);


/*
equation index: 53
type: SIMPLE_ASSIGN
omega_2 = $START.omega_2
*/
void TwoStandMill_eqFunction_53(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,53};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* omega_2 STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[9] /* omega_2 STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 53;
}
extern void TwoStandMill_eqFunction_151(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_89(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_90(DATA *data, threadData_t *threadData);


/*
equation index: 57
type: SIMPLE_ASSIGN
int_sp_1 = $START.int_sp_1
*/
void TwoStandMill_eqFunction_57(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,57};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* int_sp_1 STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[6] /* int_sp_1 STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 57;
}
extern void TwoStandMill_eqFunction_98(DATA *data, threadData_t *threadData);


/*
equation index: 59
type: SIMPLE_ASSIGN
M_cmd_1 = max(-M_max, min(M_max, Kp_sp_1 * e_1 + int_sp_1))
*/
void TwoStandMill_eqFunction_59(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,59};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* M_cmd_1 variable */) = fmax((-(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */)),fmin((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */),((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[6]] /* Kp_sp_1 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* e_1 variable */)) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* int_sp_1 STATE(1) */)));
  threadData->lastEquationSolved = 59;
}
extern void TwoStandMill_eqFunction_102(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_101(DATA *data, threadData_t *threadData);


/*
equation index: 62
type: SIMPLE_ASSIGN
int_sp_2 = $START.int_sp_2
*/
void TwoStandMill_eqFunction_62(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,62};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* int_sp_2 STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[7] /* int_sp_2 STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 62;
}
extern void TwoStandMill_eqFunction_91(DATA *data, threadData_t *threadData);


/*
equation index: 64
type: SIMPLE_ASSIGN
M_cmd_2 = max(-M_max, min(M_max, Kp_sp_2 * e_2 + int_sp_2))
*/
void TwoStandMill_eqFunction_64(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,64};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* M_cmd_2 variable */) = fmax((-(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */)),fmin((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */),((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[7]] /* Kp_sp_2 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* e_2 variable */)) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* int_sp_2 STATE(1) */)));
  threadData->lastEquationSolved = 64;
}
extern void TwoStandMill_eqFunction_95(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_94(DATA *data, threadData_t *threadData);


/*
equation index: 67
type: SIMPLE_ASSIGN
sigma_int = $START.sigma_int
*/
void TwoStandMill_eqFunction_67(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,67};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* sigma_int STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[11] /* sigma_int STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 67;
}
extern void TwoStandMill_eqFunction_88(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_87(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_103(DATA *data, threadData_t *threadData);


/*
equation index: 71
type: SIMPLE_ASSIGN
P_1_f = $START.P_1_f
*/
void TwoStandMill_eqFunction_71(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,71};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* P_1_f STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[2] /* P_1_f STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 71;
}
extern void TwoStandMill_eqFunction_107(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_128(DATA *data, threadData_t *threadData);


/*
equation index: 74
type: SIMPLE_ASSIGN
P_2_f = $START.P_2_f
*/
void TwoStandMill_eqFunction_74(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,74};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* P_2_f STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[3] /* P_2_f STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 74;
}
extern void TwoStandMill_eqFunction_106(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_148(DATA *data, threadData_t *threadData);


/*
equation index: 77
type: SIMPLE_ASSIGN
h_out_1_f = h_in0
*/
void TwoStandMill_eqFunction_77(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,77};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* h_out_1_f STATE(1) */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[20]] /* h_in0 PARAM */);
  threadData->lastEquationSolved = 77;
}
extern void TwoStandMill_eqFunction_110(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_129(DATA *data, threadData_t *threadData);


/*
equation index: 80
type: SIMPLE_ASSIGN
h_out_2_f = h_in0
*/
void TwoStandMill_eqFunction_80(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,80};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* h_out_2_f STATE(1) */) = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[20]] /* h_in0 PARAM */);
  threadData->lastEquationSolved = 80;
}
extern void TwoStandMill_eqFunction_109(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_152(DATA *data, threadData_t *threadData);


/*
equation index: 83
type: SIMPLE_ASSIGN
sigma_f = $START.sigma_f
*/
void TwoStandMill_eqFunction_83(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,83};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* sigma_f STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[10] /* sigma_f STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 83;
}
extern void TwoStandMill_eqFunction_108(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_86(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void TwoStandMill_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  static void (*const eqFunctions[57])(DATA*, threadData_t*) = {
    TwoStandMill_eqFunction_1,
    TwoStandMill_eqFunction_2,
    TwoStandMill_eqFunction_3,
    TwoStandMill_eqFunction_4,
    TwoStandMill_eqFunction_5,
    TwoStandMill_eqFunction_6,
    TwoStandMill_eqFunction_7,
    TwoStandMill_eqFunction_8,
    TwoStandMill_eqFunction_9,
    TwoStandMill_eqFunction_111,
    TwoStandMill_eqFunction_25,
    TwoStandMill_eqFunction_130,
    TwoStandMill_eqFunction_41,
    TwoStandMill_eqFunction_149,
    TwoStandMill_eqFunction_43,
    TwoStandMill_eqFunction_105,
    TwoStandMill_eqFunction_131,
    TwoStandMill_eqFunction_46,
    TwoStandMill_eqFunction_104,
    TwoStandMill_eqFunction_150,
    TwoStandMill_eqFunction_49,
    TwoStandMill_eqFunction_132,
    TwoStandMill_eqFunction_96,
    TwoStandMill_eqFunction_97,
    TwoStandMill_eqFunction_53,
    TwoStandMill_eqFunction_151,
    TwoStandMill_eqFunction_89,
    TwoStandMill_eqFunction_90,
    TwoStandMill_eqFunction_57,
    TwoStandMill_eqFunction_98,
    TwoStandMill_eqFunction_59,
    TwoStandMill_eqFunction_102,
    TwoStandMill_eqFunction_101,
    TwoStandMill_eqFunction_62,
    TwoStandMill_eqFunction_91,
    TwoStandMill_eqFunction_64,
    TwoStandMill_eqFunction_95,
    TwoStandMill_eqFunction_94,
    TwoStandMill_eqFunction_67,
    TwoStandMill_eqFunction_88,
    TwoStandMill_eqFunction_87,
    TwoStandMill_eqFunction_103,
    TwoStandMill_eqFunction_71,
    TwoStandMill_eqFunction_107,
    TwoStandMill_eqFunction_128,
    TwoStandMill_eqFunction_74,
    TwoStandMill_eqFunction_106,
    TwoStandMill_eqFunction_148,
    TwoStandMill_eqFunction_77,
    TwoStandMill_eqFunction_110,
    TwoStandMill_eqFunction_129,
    TwoStandMill_eqFunction_80,
    TwoStandMill_eqFunction_109,
    TwoStandMill_eqFunction_152,
    TwoStandMill_eqFunction_83,
    TwoStandMill_eqFunction_108,
    TwoStandMill_eqFunction_86
  };
  
  for (int id = 0; id < 57; id++) {
    eqFunctions[id](data, threadData);
  }
}

int TwoStandMill_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  data->simulationInfo->discreteCall = 1;
  TwoStandMill_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  return 0;
}

/* No TwoStandMill_functionInitialEquations_lambda0 function */

int TwoStandMill_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  return 0;
}


#if defined(__cplusplus)
}
#endif
