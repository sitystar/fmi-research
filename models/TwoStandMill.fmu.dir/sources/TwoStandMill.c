/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "TwoStandMill_model.h"
#include "simulation/solver/events.h"
#include "simulation/arrayIndex.h"



/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int TwoStandMill_input_function(DATA *data, threadData_t *threadData)
{
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[43]] /* S0_1 variable */) = data->simulationInfo->inputVars[0];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[44]] /* S0_2 variable */) = data->simulationInfo->inputVars[1];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[55]] /* h_in variable */) = data->simulationInfo->inputVars[2];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[65]] /* temp variable */) = data->simulationInfo->inputVars[3];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[68]] /* v_ref_1 variable */) = data->simulationInfo->inputVars[4];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[69]] /* v_ref_2 variable */) = data->simulationInfo->inputVars[5];
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* width variable */) = data->simulationInfo->inputVars[6];
  
  return 0;
}

int TwoStandMill_input_function_init(DATA *data, threadData_t *threadData)
{
  data->simulationInfo->inputVars[0] = getStartFromScalarIdx(data->simulationInfo, data->modelData, VAR_TYPE_REAL, VAR_KIND_VARIABLE, 43);
  data->simulationInfo->inputVars[1] = getStartFromScalarIdx(data->simulationInfo, data->modelData, VAR_TYPE_REAL, VAR_KIND_VARIABLE, 44);
  data->simulationInfo->inputVars[2] = getStartFromScalarIdx(data->simulationInfo, data->modelData, VAR_TYPE_REAL, VAR_KIND_VARIABLE, 55);
  data->simulationInfo->inputVars[3] = getStartFromScalarIdx(data->simulationInfo, data->modelData, VAR_TYPE_REAL, VAR_KIND_VARIABLE, 65);
  data->simulationInfo->inputVars[4] = getStartFromScalarIdx(data->simulationInfo, data->modelData, VAR_TYPE_REAL, VAR_KIND_VARIABLE, 68);
  data->simulationInfo->inputVars[5] = getStartFromScalarIdx(data->simulationInfo, data->modelData, VAR_TYPE_REAL, VAR_KIND_VARIABLE, 69);
  data->simulationInfo->inputVars[6] = getStartFromScalarIdx(data->simulationInfo, data->modelData, VAR_TYPE_REAL, VAR_KIND_VARIABLE, 70);
  
  return 0;
}

int TwoStandMill_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData, data->modelData->realVarsData[43].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[0], 0, &data->modelData->realVarsData[43].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[44].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[1], 0, &data->modelData->realVarsData[44].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[55].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[2], 0, &data->modelData->realVarsData[55].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[65].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[3], 0, &data->modelData->realVarsData[65].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[68].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[4], 0, &data->modelData->realVarsData[68].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[69].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[5], 0, &data->modelData->realVarsData[69].attribute.start);
  assertStreamPrint(threadData, data->modelData->realVarsData[70].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[6], 0, &data->modelData->realVarsData[70].attribute.start);
  
  return 0;
}

int TwoStandMill_inputNames(DATA *data, char ** names){
  names[0] = (char *) data->modelData->realVarsData[43].info.name;
  names[1] = (char *) data->modelData->realVarsData[44].info.name;
  names[2] = (char *) data->modelData->realVarsData[55].info.name;
  names[3] = (char *) data->modelData->realVarsData[65].info.name;
  names[4] = (char *) data->modelData->realVarsData[68].info.name;
  names[5] = (char *) data->modelData->realVarsData[69].info.name;
  names[6] = (char *) data->modelData->realVarsData[70].info.name;
  
  return 0;
}

int TwoStandMill_data_function(DATA *data, threadData_t *threadData)
{
  return 0;
}

int TwoStandMill_dataReconciliationInputNames(DATA *data, char ** names){
  
  return 0;
}

int TwoStandMill_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  
  return 0;
}

int TwoStandMill_output_function(DATA *data, threadData_t *threadData)
{
  data->simulationInfo->outputVars[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* M_load_1 variable */);
  data->simulationInfo->outputVars[1] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* M_load_2 variable */);
  data->simulationInfo->outputVars[2] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* M_motor_1 variable */);
  data->simulationInfo->outputVars[3] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* M_motor_2 variable */);
  data->simulationInfo->outputVars[4] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* P_1 variable */);
  data->simulationInfo->outputVars[5] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* P_2 variable */);
  data->simulationInfo->outputVars[6] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[57]] /* h_out_1 variable */);
  data->simulationInfo->outputVars[7] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* h_out_2 variable */);
  data->simulationInfo->outputVars[8] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[64]] /* sigma_12 variable */);
  data->simulationInfo->outputVars[9] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* v_1 variable */);
  data->simulationInfo->outputVars[10] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* v_2 variable */);
  
  return 0;
}

int TwoStandMill_setc_function(DATA *data, threadData_t *threadData)
{
  
  return 0;
}

int TwoStandMill_setb_function(DATA *data, threadData_t *threadData)
{
  
  return 0;
}


/*
equation index: 86
type: SIMPLE_ASSIGN
$DER.sigma_f = (sigma_int - sigma_f) / T_s_safe
*/
void TwoStandMill_eqFunction_86(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,86};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* der(sigma_f) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* sigma_int STATE(1) */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* sigma_f STATE(1) */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[46]] /* T_s_safe variable */),"T_s_safe",equationIndexes);
  threadData->lastEquationSolved = 86;
}

/*
equation index: 87
type: SIMPLE_ASSIGN
diag_tension_low = sigma_int <= 0.0
*/
void TwoStandMill_eqFunction_87(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,87};
  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp1 = 1.0;
  tmp2 = 0.0;
  relationhysteresis(data, &tmp0, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* sigma_int STATE(1) */), 0.0, tmp1, tmp2, 19, LessEq, LessEqZC);
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[2]] /* diag_tension_low DISCRETE */) = tmp0;
  threadData->lastEquationSolved = 87;
}

/*
equation index: 88
type: SIMPLE_ASSIGN
diag_tension_max = sigma_int >= 0.999 * sigma_max
*/
void TwoStandMill_eqFunction_88(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,88};
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  tmp4 = 1.0;
  tmp5 = (0.999) * (fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* sigma_max PARAM */)));
  relationhysteresis(data, &tmp3, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* sigma_int STATE(1) */), (0.999) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* sigma_max PARAM */)), tmp4, tmp5, 18, GreaterEq, GreaterEqZC);
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[3]] /* diag_tension_max DISCRETE */) = tmp3;
  threadData->lastEquationSolved = 88;
}

/*
equation index: 89
type: SIMPLE_ASSIGN
v_2 = 0.001 * omega_2 * R_2
*/
void TwoStandMill_eqFunction_89(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,89};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* v_2 variable */) = (0.001) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* omega_2 STATE(1) */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[11]] /* R_2 PARAM */)));
  threadData->lastEquationSolved = 89;
}

/*
equation index: 90
type: SIMPLE_ASSIGN
e_2 = v_ref_2 - v_2
*/
void TwoStandMill_eqFunction_90(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,90};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* e_2 variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[69]] /* v_ref_2 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* v_2 variable */);
  threadData->lastEquationSolved = 90;
}

/*
equation index: 91
type: SIMPLE_ASSIGN
$DER.int_sp_2 = if int_sp_2 <= (-I_max_sp) and e_2 < 0.0 or int_sp_2 >= I_max_sp and e_2 > 0.0 then 0.0 else e_2 / Ti_2_safe
*/
void TwoStandMill_eqFunction_91(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,91};
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_boolean tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_boolean tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_boolean tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  tmp7 = 1.0;
  tmp8 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */));
  relationhysteresis(data, &tmp6, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* int_sp_2 STATE(1) */), (-(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */)), tmp7, tmp8, 5, LessEq, LessEqZC);
  tmp10 = 1.0;
  tmp11 = 0.0;
  relationhysteresis(data, &tmp9, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* e_2 variable */), 0.0, tmp10, tmp11, 6, Less, LessZC);
  tmp13 = 1.0;
  tmp14 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */));
  relationhysteresis(data, &tmp12, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* int_sp_2 STATE(1) */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */), tmp13, tmp14, 7, GreaterEq, GreaterEqZC);
  tmp16 = 1.0;
  tmp17 = 0.0;
  relationhysteresis(data, &tmp15, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* e_2 variable */), 0.0, tmp16, tmp17, 8, Greater, GreaterZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* der(int_sp_2) STATE_DER */) = (((tmp6 && tmp9) || (tmp12 && tmp15))?0.0:DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* e_2 variable */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[48]] /* Ti_2_safe variable */),"Ti_2_safe",equationIndexes));
  threadData->lastEquationSolved = 91;
}

/*
equation index: 92
type: SIMPLE_ASSIGN
$cse8 = min(M_max, Kp_sp_2 * e_2 + int_sp_2)
*/
void TwoStandMill_eqFunction_92(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,92};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* $cse8 variable */) = fmin((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */),((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[7]] /* Kp_sp_2 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* e_2 variable */)) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* int_sp_2 STATE(1) */));
  threadData->lastEquationSolved = 92;
}

/*
equation index: 93
type: SIMPLE_ASSIGN
M_cmd_2 = max(-M_max, $cse8)
*/
void TwoStandMill_eqFunction_93(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,93};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* M_cmd_2 variable */) = fmax((-(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */)),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* $cse8 variable */));
  threadData->lastEquationSolved = 93;
}

/*
equation index: 94
type: SIMPLE_ASSIGN
$DER.M_dyn_2 = (M_cmd_2 - M_dyn_2) / T_e_2
*/
void TwoStandMill_eqFunction_94(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,94};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* der(M_dyn_2) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* M_cmd_2 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* M_dyn_2 STATE(1) */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[13]] /* T_e_2 PARAM */),"T_e_2",equationIndexes);
  threadData->lastEquationSolved = 94;
}

/*
equation index: 95
type: SIMPLE_ASSIGN
diag_motor_sat_2 = abs(M_cmd_2) >= M_max
*/
void TwoStandMill_eqFunction_95(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,95};
  modelica_boolean tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  tmp19 = 1.0;
  tmp20 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */));
  relationhysteresis(data, &tmp18, fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* M_cmd_2 variable */)), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */), tmp19, tmp20, 9, GreaterEq, GreaterEqZC);
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[1]] /* diag_motor_sat_2 DISCRETE */) = tmp18;
  threadData->lastEquationSolved = 95;
}

/*
equation index: 96
type: SIMPLE_ASSIGN
v_1 = 0.001 * omega_1 * R_1
*/
void TwoStandMill_eqFunction_96(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,96};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* v_1 variable */) = (0.001) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* omega_1 STATE(1) */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[10]] /* R_1 PARAM */)));
  threadData->lastEquationSolved = 96;
}

/*
equation index: 97
type: SIMPLE_ASSIGN
e_1 = v_ref_1 - v_1
*/
void TwoStandMill_eqFunction_97(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,97};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* e_1 variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[68]] /* v_ref_1 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* v_1 variable */);
  threadData->lastEquationSolved = 97;
}

/*
equation index: 98
type: SIMPLE_ASSIGN
$DER.int_sp_1 = if int_sp_1 <= (-I_max_sp) and e_1 < 0.0 or int_sp_1 >= I_max_sp and e_1 > 0.0 then 0.0 else e_1 / Ti_1_safe
*/
void TwoStandMill_eqFunction_98(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,98};
  modelica_boolean tmp21;
  modelica_real tmp22;
  modelica_real tmp23;
  modelica_boolean tmp24;
  modelica_real tmp25;
  modelica_real tmp26;
  modelica_boolean tmp27;
  modelica_real tmp28;
  modelica_real tmp29;
  modelica_boolean tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  tmp22 = 1.0;
  tmp23 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */));
  relationhysteresis(data, &tmp21, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* int_sp_1 STATE(1) */), (-(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */)), tmp22, tmp23, 0, LessEq, LessEqZC);
  tmp25 = 1.0;
  tmp26 = 0.0;
  relationhysteresis(data, &tmp24, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* e_1 variable */), 0.0, tmp25, tmp26, 1, Less, LessZC);
  tmp28 = 1.0;
  tmp29 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */));
  relationhysteresis(data, &tmp27, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* int_sp_1 STATE(1) */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */), tmp28, tmp29, 2, GreaterEq, GreaterEqZC);
  tmp31 = 1.0;
  tmp32 = 0.0;
  relationhysteresis(data, &tmp30, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* e_1 variable */), 0.0, tmp31, tmp32, 3, Greater, GreaterZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* der(int_sp_1) STATE_DER */) = (((tmp21 && tmp24) || (tmp27 && tmp30))?0.0:DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* e_1 variable */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[47]] /* Ti_1_safe variable */),"Ti_1_safe",equationIndexes));
  threadData->lastEquationSolved = 98;
}

/*
equation index: 99
type: SIMPLE_ASSIGN
$cse9 = min(M_max, Kp_sp_1 * e_1 + int_sp_1)
*/
void TwoStandMill_eqFunction_99(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,99};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* $cse9 variable */) = fmin((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */),((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[6]] /* Kp_sp_1 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* e_1 variable */)) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* int_sp_1 STATE(1) */));
  threadData->lastEquationSolved = 99;
}

/*
equation index: 100
type: SIMPLE_ASSIGN
M_cmd_1 = max(-M_max, $cse9)
*/
void TwoStandMill_eqFunction_100(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,100};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* M_cmd_1 variable */) = fmax((-(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */)),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* $cse9 variable */));
  threadData->lastEquationSolved = 100;
}

/*
equation index: 101
type: SIMPLE_ASSIGN
$DER.M_dyn_1 = (M_cmd_1 - M_dyn_1) / T_e_1
*/
void TwoStandMill_eqFunction_101(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,101};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* der(M_dyn_1) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* M_cmd_1 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* M_dyn_1 STATE(1) */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[12]] /* T_e_1 PARAM */),"T_e_1",equationIndexes);
  threadData->lastEquationSolved = 101;
}

/*
equation index: 102
type: SIMPLE_ASSIGN
diag_motor_sat_1 = abs(M_cmd_1) >= M_max
*/
void TwoStandMill_eqFunction_102(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,102};
  modelica_boolean tmp33;
  modelica_real tmp34;
  modelica_real tmp35;
  tmp34 = 1.0;
  tmp35 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */));
  relationhysteresis(data, &tmp33, fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* M_cmd_1 variable */)), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */), tmp34, tmp35, 4, GreaterEq, GreaterEqZC);
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* diag_motor_sat_1 DISCRETE */) = tmp33;
  threadData->lastEquationSolved = 102;
}

/*
equation index: 103
type: SIMPLE_ASSIGN
$DER.sigma_int = if diag_tension_low and k_sig * (v_2 - v_1) < 0.0 or sigma_int >= sigma_max and k_sig * (v_2 - v_1) > 0.0 then 0.0 else k_sig * (v_2 - v_1)
*/
void TwoStandMill_eqFunction_103(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,103};
  modelica_boolean tmp36;
  modelica_real tmp37;
  modelica_real tmp38;
  modelica_boolean tmp39;
  modelica_real tmp40;
  modelica_real tmp41;
  modelica_boolean tmp42;
  modelica_real tmp43;
  modelica_real tmp44;
  tmp37 = 2.0;
  tmp38 = 0.0;
  relationhysteresis(data, &tmp36, ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* k_sig variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* v_2 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* v_1 variable */)), 0.0, tmp37, tmp38, 20, Less, LessZC);
  tmp40 = 1.0;
  tmp41 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* sigma_max PARAM */));
  relationhysteresis(data, &tmp39, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* sigma_int STATE(1) */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* sigma_max PARAM */), tmp40, tmp41, 21, GreaterEq, GreaterEqZC);
  tmp43 = 2.0;
  tmp44 = 0.0;
  relationhysteresis(data, &tmp42, ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* k_sig variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* v_2 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* v_1 variable */)), 0.0, tmp43, tmp44, 22, Greater, GreaterZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* der(sigma_int) STATE_DER */) = ((((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[2]] /* diag_tension_low DISCRETE */) && tmp36) || (tmp39 && tmp42))?0.0:((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* k_sig variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* v_2 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* v_1 variable */)));
  threadData->lastEquationSolved = 103;
}

/*
equation index: 104
type: SIMPLE_ASSIGN
M_motor_2 = M_dyn_2
*/
void TwoStandMill_eqFunction_104(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,104};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* M_motor_2 variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* M_dyn_2 STATE(1) */);
  threadData->lastEquationSolved = 104;
}

/*
equation index: 105
type: SIMPLE_ASSIGN
M_motor_1 = M_dyn_1
*/
void TwoStandMill_eqFunction_105(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,105};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* M_motor_1 variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* M_dyn_1 STATE(1) */);
  threadData->lastEquationSolved = 105;
}

/*
equation index: 106
type: SIMPLE_ASSIGN
P_2 = P_2_f
*/
void TwoStandMill_eqFunction_106(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,106};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* P_2 variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* P_2_f STATE(1) */);
  threadData->lastEquationSolved = 106;
}

/*
equation index: 107
type: SIMPLE_ASSIGN
P_1 = P_1_f
*/
void TwoStandMill_eqFunction_107(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,107};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* P_1 variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* P_1_f STATE(1) */);
  threadData->lastEquationSolved = 107;
}

/*
equation index: 108
type: SIMPLE_ASSIGN
sigma_12 = sigma_f
*/
void TwoStandMill_eqFunction_108(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,108};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[64]] /* sigma_12 variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* sigma_f STATE(1) */);
  threadData->lastEquationSolved = 108;
}

/*
equation index: 109
type: SIMPLE_ASSIGN
h_out_2 = h_out_2_f
*/
void TwoStandMill_eqFunction_109(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,109};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* h_out_2 variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* h_out_2_f STATE(1) */);
  threadData->lastEquationSolved = 109;
}

/*
equation index: 110
type: SIMPLE_ASSIGN
h_out_1 = h_out_1_f
*/
void TwoStandMill_eqFunction_110(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,110};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[57]] /* h_out_1 variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* h_out_1_f STATE(1) */);
  threadData->lastEquationSolved = 110;
}

/*
equation index: 111
type: SIMPLE_ASSIGN
h_in_s = max(h_min, h_in)
*/
void TwoStandMill_eqFunction_111(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,111};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */) = fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[55]] /* h_in variable */));
  threadData->lastEquationSolved = 111;
}

/*
equation index: 112
type: SIMPLE_ASSIGN
$cse6 = exp((-0.0018) * (temp - 950.0))
*/
void TwoStandMill_eqFunction_112(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,112};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* $cse6 variable */) = exp((-0.0018) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[65]] /* temp variable */) - 950.0));
  threadData->lastEquationSolved = 112;
}

void TwoStandMill_eqFunction_113(DATA*, threadData_t*);
void TwoStandMill_eqFunction_114(DATA*, threadData_t*);
void TwoStandMill_eqFunction_115(DATA*, threadData_t*);
void TwoStandMill_eqFunction_116(DATA*, threadData_t*);
void TwoStandMill_eqFunction_117(DATA*, threadData_t*);
void TwoStandMill_eqFunction_118(DATA*, threadData_t*);
void TwoStandMill_eqFunction_119(DATA*, threadData_t*);
/*
equation index: 127
indexNonlinear: 2
type: NONLINEAR

vars: {ho_1}
eqns: {113, 114, 115, 116, 117, 118, 119}
*/
void TwoStandMill_eqFunction_127(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,127};
  int retValue;
  infoStreamPrint(OMC_LOG_DT, 0, "Solving nonlinear system 127 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
  /* get old value */
  data->simulationInfo->nonlinearSystemData[2].nlsxOld[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */);
  retValue = solve_nonlinear_system(data, threadData, 2);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,127};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 127 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */) = data->simulationInfo->nonlinearSystemData[2].nlsx[0];
  threadData->lastEquationSolved = 127;
}

/*
equation index: 128
type: SIMPLE_ASSIGN
$DER.P_1_f = (P_1_raw - P_1_f) / T_f_safe
*/
void TwoStandMill_eqFunction_128(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,128};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* der(P_1_f) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* P_1_raw variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* P_1_f STATE(1) */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[45]] /* T_f_safe variable */),"T_f_safe",equationIndexes);
  threadData->lastEquationSolved = 128;
}

/*
equation index: 129
type: SIMPLE_ASSIGN
$DER.h_out_1_f = (ho_1 - h_out_1_f) / T_f_safe
*/
void TwoStandMill_eqFunction_129(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,129};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* der(h_out_1_f) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* h_out_1_f STATE(1) */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[45]] /* T_f_safe variable */),"T_f_safe",equationIndexes);
  threadData->lastEquationSolved = 129;
}

/*
equation index: 130
type: SIMPLE_ASSIGN
M_load_1 = 0.001 * P_1_raw * alpha * Ld_1
*/
void TwoStandMill_eqFunction_130(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,130};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* M_load_1 variable */) = (0.001) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* P_1_raw variable */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[18]] /* alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* Ld_1 variable */))));
  threadData->lastEquationSolved = 130;
}

/*
equation index: 131
type: SIMPLE_ASSIGN
a_1 = 1000.0 * (M_dyn_1 - M_load_1) / J_1
*/
void TwoStandMill_eqFunction_131(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,131};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* a_1 variable */) = (1000.0) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* M_dyn_1 STATE(1) */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* M_load_1 variable */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[2]] /* J_1 PARAM */),"J_1",equationIndexes));
  threadData->lastEquationSolved = 131;
}

/*
equation index: 132
type: SIMPLE_ASSIGN
$DER.omega_1 = if omega_1 <= wmin_1 and a_1 < 0.0 or omega_1 >= wmax_1 and a_1 > 0.0 then 0.0 else a_1
*/
void TwoStandMill_eqFunction_132(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,132};
  modelica_boolean tmp45;
  modelica_real tmp46;
  modelica_real tmp47;
  modelica_boolean tmp48;
  modelica_real tmp49;
  modelica_real tmp50;
  modelica_boolean tmp51;
  modelica_real tmp52;
  modelica_real tmp53;
  modelica_boolean tmp54;
  modelica_real tmp55;
  modelica_real tmp56;
  tmp46 = 1.0;
  tmp47 = 1.0;
  relationhysteresis(data, &tmp45, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* omega_1 STATE(1) */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[73]] /* wmin_1 variable */), tmp46, tmp47, 10, LessEq, LessEqZC);
  tmp49 = 1.0;
  tmp50 = 0.0;
  relationhysteresis(data, &tmp48, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* a_1 variable */), 0.0, tmp49, tmp50, 11, Less, LessZC);
  tmp52 = 1.0;
  tmp53 = 1.0;
  relationhysteresis(data, &tmp51, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* omega_1 STATE(1) */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[71]] /* wmax_1 variable */), tmp52, tmp53, 12, GreaterEq, GreaterEqZC);
  tmp55 = 1.0;
  tmp56 = 0.0;
  relationhysteresis(data, &tmp54, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* a_1 variable */), 0.0, tmp55, tmp56, 13, Greater, GreaterZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* der(omega_1) STATE_DER */) = (((tmp45 && tmp48) || (tmp51 && tmp54))?0.0:(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* a_1 variable */));
  threadData->lastEquationSolved = 132;
}

void TwoStandMill_eqFunction_133(DATA*, threadData_t*);
void TwoStandMill_eqFunction_134(DATA*, threadData_t*);
void TwoStandMill_eqFunction_135(DATA*, threadData_t*);
void TwoStandMill_eqFunction_136(DATA*, threadData_t*);
void TwoStandMill_eqFunction_137(DATA*, threadData_t*);
void TwoStandMill_eqFunction_138(DATA*, threadData_t*);
void TwoStandMill_eqFunction_139(DATA*, threadData_t*);
/*
equation index: 147
indexNonlinear: 3
type: NONLINEAR

vars: {ho_2}
eqns: {133, 134, 135, 136, 137, 138, 139}
*/
void TwoStandMill_eqFunction_147(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,147};
  int retValue;
  infoStreamPrint(OMC_LOG_DT, 0, "Solving nonlinear system 147 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
  /* get old value */
  data->simulationInfo->nonlinearSystemData[3].nlsxOld[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */);
  retValue = solve_nonlinear_system(data, threadData, 3);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,147};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 147 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */) = data->simulationInfo->nonlinearSystemData[3].nlsx[0];
  threadData->lastEquationSolved = 147;
}

/*
equation index: 148
type: SIMPLE_ASSIGN
$DER.P_2_f = (P_2_raw - P_2_f) / T_f_safe
*/
void TwoStandMill_eqFunction_148(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,148};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* der(P_2_f) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* P_2_raw variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* P_2_f STATE(1) */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[45]] /* T_f_safe variable */),"T_f_safe",equationIndexes);
  threadData->lastEquationSolved = 148;
}

/*
equation index: 149
type: SIMPLE_ASSIGN
M_load_2 = 0.001 * P_2_raw * alpha * Ld_2
*/
void TwoStandMill_eqFunction_149(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,149};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* M_load_2 variable */) = (0.001) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* P_2_raw variable */)) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[18]] /* alpha PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* Ld_2 variable */))));
  threadData->lastEquationSolved = 149;
}

/*
equation index: 150
type: SIMPLE_ASSIGN
a_2 = 1000.0 * (M_dyn_2 - M_load_2) / J_2
*/
void TwoStandMill_eqFunction_150(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,150};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* a_2 variable */) = (1000.0) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* M_dyn_2 STATE(1) */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* M_load_2 variable */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[3]] /* J_2 PARAM */),"J_2",equationIndexes));
  threadData->lastEquationSolved = 150;
}

/*
equation index: 151
type: SIMPLE_ASSIGN
$DER.omega_2 = if omega_2 <= wmin_2 and a_2 < 0.0 or omega_2 >= wmax_2 and a_2 > 0.0 then 0.0 else a_2
*/
void TwoStandMill_eqFunction_151(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,151};
  modelica_boolean tmp57;
  modelica_real tmp58;
  modelica_real tmp59;
  modelica_boolean tmp60;
  modelica_real tmp61;
  modelica_real tmp62;
  modelica_boolean tmp63;
  modelica_real tmp64;
  modelica_real tmp65;
  modelica_boolean tmp66;
  modelica_real tmp67;
  modelica_real tmp68;
  tmp58 = 1.0;
  tmp59 = 1.0;
  relationhysteresis(data, &tmp57, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* omega_2 STATE(1) */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* wmin_2 variable */), tmp58, tmp59, 14, LessEq, LessEqZC);
  tmp61 = 1.0;
  tmp62 = 0.0;
  relationhysteresis(data, &tmp60, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* a_2 variable */), 0.0, tmp61, tmp62, 15, Less, LessZC);
  tmp64 = 1.0;
  tmp65 = 1.0;
  relationhysteresis(data, &tmp63, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* omega_2 STATE(1) */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[72]] /* wmax_2 variable */), tmp64, tmp65, 16, GreaterEq, GreaterEqZC);
  tmp67 = 1.0;
  tmp68 = 0.0;
  relationhysteresis(data, &tmp66, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* a_2 variable */), 0.0, tmp67, tmp68, 17, Greater, GreaterZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* der(omega_2) STATE_DER */) = (((tmp57 && tmp60) || (tmp63 && tmp66))?0.0:(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* a_2 variable */));
  threadData->lastEquationSolved = 151;
}

/*
equation index: 152
type: SIMPLE_ASSIGN
$DER.h_out_2_f = (ho_2 - h_out_2_f) / T_f_safe
*/
void TwoStandMill_eqFunction_152(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,152};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* der(h_out_2_f) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* h_out_2_f STATE(1) */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[45]] /* T_f_safe variable */),"T_f_safe",equationIndexes);
  threadData->lastEquationSolved = 152;
}

OMC_DISABLE_OPT
int TwoStandMill_functionDAE(DATA *data, threadData_t *threadData)
{
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  TwoStandMill_functionLocalKnownVars(data, threadData);
  static void (*const eqFunctions[39])(DATA*, threadData_t*) = {
    TwoStandMill_eqFunction_86,
    TwoStandMill_eqFunction_87,
    TwoStandMill_eqFunction_88,
    TwoStandMill_eqFunction_89,
    TwoStandMill_eqFunction_90,
    TwoStandMill_eqFunction_91,
    TwoStandMill_eqFunction_92,
    TwoStandMill_eqFunction_93,
    TwoStandMill_eqFunction_94,
    TwoStandMill_eqFunction_95,
    TwoStandMill_eqFunction_96,
    TwoStandMill_eqFunction_97,
    TwoStandMill_eqFunction_98,
    TwoStandMill_eqFunction_99,
    TwoStandMill_eqFunction_100,
    TwoStandMill_eqFunction_101,
    TwoStandMill_eqFunction_102,
    TwoStandMill_eqFunction_103,
    TwoStandMill_eqFunction_104,
    TwoStandMill_eqFunction_105,
    TwoStandMill_eqFunction_106,
    TwoStandMill_eqFunction_107,
    TwoStandMill_eqFunction_108,
    TwoStandMill_eqFunction_109,
    TwoStandMill_eqFunction_110,
    TwoStandMill_eqFunction_111,
    TwoStandMill_eqFunction_112,
    TwoStandMill_eqFunction_127,
    TwoStandMill_eqFunction_128,
    TwoStandMill_eqFunction_129,
    TwoStandMill_eqFunction_130,
    TwoStandMill_eqFunction_131,
    TwoStandMill_eqFunction_132,
    TwoStandMill_eqFunction_147,
    TwoStandMill_eqFunction_148,
    TwoStandMill_eqFunction_149,
    TwoStandMill_eqFunction_150,
    TwoStandMill_eqFunction_151,
    TwoStandMill_eqFunction_152
  };
  
  for (int id = 0; id < 39; id++) {
    eqFunctions[id](data, threadData);
  }
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  return 0;
}


int TwoStandMill_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  
  return 0;
}

/* forwarded equations */
extern void TwoStandMill_eqFunction_86(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_87(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_89(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_90(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_91(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_92(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_93(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_94(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_96(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_97(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_98(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_99(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_100(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_101(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_103(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_111(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_112(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_127(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_128(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_129(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_130(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_131(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_132(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_147(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_148(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_149(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_150(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_151(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_152(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  static void (*const eqFunctions[29])(DATA*, threadData_t*) = {
    TwoStandMill_eqFunction_86,
    TwoStandMill_eqFunction_87,
    TwoStandMill_eqFunction_89,
    TwoStandMill_eqFunction_90,
    TwoStandMill_eqFunction_91,
    TwoStandMill_eqFunction_92,
    TwoStandMill_eqFunction_93,
    TwoStandMill_eqFunction_94,
    TwoStandMill_eqFunction_96,
    TwoStandMill_eqFunction_97,
    TwoStandMill_eqFunction_98,
    TwoStandMill_eqFunction_99,
    TwoStandMill_eqFunction_100,
    TwoStandMill_eqFunction_101,
    TwoStandMill_eqFunction_103,
    TwoStandMill_eqFunction_111,
    TwoStandMill_eqFunction_112,
    TwoStandMill_eqFunction_127,
    TwoStandMill_eqFunction_128,
    TwoStandMill_eqFunction_129,
    TwoStandMill_eqFunction_130,
    TwoStandMill_eqFunction_131,
    TwoStandMill_eqFunction_132,
    TwoStandMill_eqFunction_147,
    TwoStandMill_eqFunction_148,
    TwoStandMill_eqFunction_149,
    TwoStandMill_eqFunction_150,
    TwoStandMill_eqFunction_151,
    TwoStandMill_eqFunction_152
  };
  
  if (data->simulationInfo->evalSelection) {
    for (int i = 0; i < data->simulationInfo->evalSelection->n; i++) {
      int id = data->simulationInfo->evalSelection->idx[i];
      eqFunctions[id](data, threadData);
    }
  } else {
    for (int id = 0; id < 29; id++) {
      eqFunctions[id](data, threadData);
    }
  }
}

int TwoStandMill_functionODE(DATA *data, threadData_t *threadData)
{
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  TwoStandMill_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  return 0;
}

void TwoStandMill_ODE_DAG(DATA* data, threadData_t* threadData)
{
  const size_t eqMap[] = {86, 87, 89, 90, 91, 92, 93, 94, 96, 97, 98, 99, 100, 101, 103, 111, 112, 127, 128, 129, 130, 131, 132, 147, 148, 149, 150, 151, 152};
  buildEvalDAG_ODE(data->modelData, sizeof(eqMap)/sizeof(size_t), eqMap);
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char **argv, DATA *data, threadData_t *threadData);
extern int _main_OptimizationRuntime(int argc, char **argv, DATA *data, threadData_t *threadData);

#include "TwoStandMill_12jac.h"
#include "TwoStandMill_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks TwoStandMill_callback = {
  NULL,    /* performSimulation */
  NULL,    /* performQSSSimulation */
  NULL,    /* updateContinuousSystem */
  TwoStandMill_callExternalObjectDestructors,    /* callExternalObjectDestructors */
  TwoStandMill_initialNonLinearSystem,    /* initialNonLinearSystem */
  NULL,    /* initialLinearSystem */
  NULL,    /* initialMixedSystem */
  #if !defined(OMC_NO_STATESELECTION)
  TwoStandMill_initializeStateSets,
  #else
  NULL,
  #endif    /* initializeStateSets */
  TwoStandMill_initializeDAEmodeData,
  TwoStandMill_ODE_DAG,
  TwoStandMill_functionODE,
  TwoStandMill_functionAlgebraics,
  TwoStandMill_functionDAE,
  TwoStandMill_functionLocalKnownVars,
  TwoStandMill_input_function,
  TwoStandMill_input_function_init,
  TwoStandMill_input_function_updateStartValues,
  TwoStandMill_data_function,
  TwoStandMill_output_function,
  TwoStandMill_setc_function,
  TwoStandMill_setb_function,
  TwoStandMill_function_storeDelayed,
  TwoStandMill_function_storeSpatialDistribution,
  TwoStandMill_function_initSpatialDistribution,
  TwoStandMill_updateBoundVariableAttributes,
  TwoStandMill_functionInitialEquations,
  GLOBAL_EQUIDISTANT_HOMOTOPY,
  NULL,
  TwoStandMill_functionRemovedInitialEquations,
  TwoStandMill_updateBoundParameters,
  TwoStandMill_checkForAsserts,
  TwoStandMill_function_ZeroCrossingsEquations,
  TwoStandMill_function_ZeroCrossings,
  TwoStandMill_function_updateRelations,
  TwoStandMill_zeroCrossingDescription,
  TwoStandMill_relationDescription,
  TwoStandMill_function_initSample,
  TwoStandMill_INDEX_JAC_A,
  TwoStandMill_INDEX_JAC_ADJ,
  TwoStandMill_INDEX_JAC_B,
  TwoStandMill_INDEX_JAC_C,
  TwoStandMill_INDEX_JAC_D,
  TwoStandMill_INDEX_JAC_F,
  TwoStandMill_INDEX_JAC_H,
  TwoStandMill_initialAnalyticJacobianA,
  TwoStandMill_initialAnalyticJacobianADJ,
  TwoStandMill_initialAnalyticJacobianB,
  TwoStandMill_initialAnalyticJacobianC,
  TwoStandMill_initialAnalyticJacobianD,
  TwoStandMill_initialAnalyticJacobianF,
  TwoStandMill_initialAnalyticJacobianH,
  TwoStandMill_functionJacA_column,
  TwoStandMill_functionJacADJ_column,
  TwoStandMill_functionJacB_column,
  TwoStandMill_functionJacC_column,
  TwoStandMill_functionJacD_column,
  TwoStandMill_functionJacF_column,
  TwoStandMill_functionJacH_column,
  TwoStandMill_JacA_DAG,
  TwoStandMill_linear_model_frame,
  TwoStandMill_linear_model_datarecovery_frame,
  TwoStandMill_mayer,
  TwoStandMill_lagrange,
  TwoStandMill_getInputVarIndicesInOptimization,
  TwoStandMill_pickUpBoundsForInputsInOptimization,
  TwoStandMill_setInputData,
  TwoStandMill_getTimeGrid,
  TwoStandMill_symbolicInlineSystem,
  TwoStandMill_function_initSynchronous,
  TwoStandMill_function_updateSynchronous,
  TwoStandMill_function_equationsSynchronous,
  TwoStandMill_inputNames,
  TwoStandMill_dataReconciliationInputNames,
  TwoStandMill_dataReconciliationUnmeasuredVariables,
  TwoStandMill_read_simulation_info,
  TwoStandMill_read_input_fmu,
  NULL,
  NULL,
  -1,
  NULL,
  NULL,
  -1

};

#define _OMC_LIT_RESOURCE_0_name_data "Complex"
#define _OMC_LIT_RESOURCE_0_dir_data ". 4.1.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,7,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,56,_OMC_LIT_RESOURCE_0_dir_data);

#define _OMC_LIT_RESOURCE_1_name_data "Modelica"
#define _OMC_LIT_RESOURCE_1_dir_data ". 4.1.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,8,_OMC_LIT_RESOURCE_1_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir,57,_OMC_LIT_RESOURCE_1_dir_data);

#define _OMC_LIT_RESOURCE_2_name_data "ModelicaServices"
#define _OMC_LIT_RESOURCE_2_dir_data ". 4.1.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_name,16,_OMC_LIT_RESOURCE_2_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir,65,_OMC_LIT_RESOURCE_2_dir_data);

#define _OMC_LIT_RESOURCE_3_name_data "TwoStandMill"
#define _OMC_LIT_RESOURCE_3_dir_data "."
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,12,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,60,_OMC_LIT_RESOURCE_3_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,8,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir)}};
void TwoStandMill_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &TwoStandMill_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "TwoStandMill";
  data->modelData->modelFilePrefix = "TwoStandMill";
  data->modelData->modelFileName = "TwoStandMill.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = ".";
  data->modelData->modelGUID = "{c8f37d53-e2aa-4840-b471-fd618266c552}";
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  GC_asprintf(&data->modelData->modelDataXml.fileName, "%s/TwoStandMill_info.json", data->modelData->resourcesDir);
  data->modelData->runTestsuite = 0;
  data->modelData->nStatesArray = 12;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesRealArray = 75;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 4;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersRealArray = 25;
  data->modelData->nParametersIntegerArray = 0;
  data->modelData->nParametersBooleanArray = 0;
  data->modelData->nParametersStringArray = 0;
  data->modelData->nParametersReal = 25;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nAliasRealArray = 11;
  data->modelData->nAliasIntegerArray = 0;
  data->modelData->nAliasBooleanArray = 4;
  data->modelData->nAliasStringArray = 0;
  data->modelData->nInputVars = 7;
  data->modelData->nOutputVars = 15;
  data->modelData->nZeroCrossings = 9;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 23;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 164;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 4;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 11;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  data->modelData->nDelayExpressions = 0;
  data->modelData->nBaseClocks = 0;
  data->modelData->nSpatialDistributions = 0;
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
  data->modelData->nSetcVars = 0;
  data->modelData->ndataReconVars = 0;
  data->modelData->nSetbVars = 0;
  data->modelData->nRelatedBoundaryConditions = 0;
  data->modelData->linearizationDumpLanguage = OMC_LINEARIZE_DUMP_LANGUAGE_MODELICA;
}

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}

