/* Jacobians 11 */
#include "TwoStandMill_model.h"
#include "TwoStandMill_12jac.h"
#include "simulation/jacobian_util.h"
#include "util/omc_file.h"
/* constant equations */
/* dynamic equations */

/*
equation index: 17
type: SIMPLE_ASSIGN
$cse1 = min(0.95 * h_in_s, S0_1 + P_1_raw / K_mill_1)
*/
void TwoStandMill_eqFunction_17(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,17};
  jacobian->tmpVars[1] /* $cse1 JACOBIAN_TMP_VAR */ = fmin((0.95) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */)),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[43]] /* S0_1 variable */) + DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* P_1_raw variable */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[4]] /* K_mill_1 PARAM */),"K_mill_1"));
  threadData->lastEquationSolved = 17;
}

/*
equation index: 18
type: SIMPLE_ASSIGN
$cse2 = exp((-0.0018) * (temp - 950.0))
*/
void TwoStandMill_eqFunction_18(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,18};
  jacobian->tmpVars[0] /* $cse2 JACOBIAN_TMP_VAR */ = exp((-0.0018) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[65]] /* temp variable */) - 950.0));
  threadData->lastEquationSolved = 18;
}

/*
equation index: 19
type: SIMPLE_ASSIGN
Ld_1.$pDERNLSJac0.dummyVarNLSJac0 = 0.5 * R_1 * (if noEvent(h_min > h_in_s - ho_1) then 0.0 else -ho_1.SeedNLSJac0) / sqrt(R_1 * max(h_min, h_in_s - ho_1))
*/
void TwoStandMill_eqFunction_19(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,19};
  modelica_boolean tmp0;
  modelica_real tmp1;
  tmp0 = Greater((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */));
  tmp1 = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[10]] /* R_1 PARAM */)) * (fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */)));
  if(!(tmp1 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(R_1 * max(h_min, h_in_s - ho_1)) was %g should be >= 0", tmp1);
    }
  }
  jacobian->tmpVars[2] /* Ld_1.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_TMP_VAR */ = (0.5) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[10]] /* R_1 PARAM */)) * (DIVISION((tmp0?0.0:(-jacobian->seedVars[0] /* ho_1.SeedNLSJac0 SEED_VAR */)),sqrt(tmp1),"sqrt(R_1 * max(h_min, h_in_s - ho_1))")));
  threadData->lastEquationSolved = 19;
}

/*
equation index: 20
type: SIMPLE_ASSIGN
eps_1.$pDERNLSJac0.dummyVarNLSJac0 = if noEvent(eps_min > (h_in_s - ho_1) / h_in_s) then 0.0 else (-ho_1.SeedNLSJac0) * h_in_s / h_in_s ^ 2.0
*/
void TwoStandMill_eqFunction_20(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,20};
  modelica_boolean tmp2;
  modelica_real tmp3;
  modelica_boolean tmp4;
  modelica_real tmp5;
  tmp2 = Greater((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[19]] /* eps_min PARAM */),DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */),"h_in_s"));
  tmp4 = (modelica_boolean)tmp2;
  if(tmp4)
  {
    tmp5 = 0.0;
  }
  else
  {
    tmp3 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */);
    tmp5 = DIVISION(((-jacobian->seedVars[0] /* ho_1.SeedNLSJac0 SEED_VAR */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */)),(tmp3 * tmp3),"h_in_s ^ 2.0");
  }
  jacobian->tmpVars[3] /* eps_1.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_TMP_VAR */ = tmp5;
  threadData->lastEquationSolved = 20;
}

/*
equation index: 21
type: SIMPLE_ASSIGN
kf_1.$pDERNLSJac0.dummyVarNLSJac0 = 98.56 * eps_1.$pDERNLSJac0.dummyVarNLSJac0 * (1.0 + 2.8 * eps_1) ^ (-0.78) * $cse2
*/
void TwoStandMill_eqFunction_21(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,21};
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  tmp6 = 1.0 + (2.8) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[53]] /* eps_1 variable */));
  tmp7 = -0.78;
  if(tmp6 < 0.0 && tmp7 != 0.0)
  {
    tmp9 = modf(tmp7, &tmp10);
    
    if(tmp9 > 0.5)
    {
      tmp9 -= 1.0;
      tmp10 += 1.0;
    }
    else if(tmp9 < -0.5)
    {
      tmp9 += 1.0;
      tmp10 -= 1.0;
    }
    
    if(fabs(tmp9) < 1e-10)
      tmp8 = pow(tmp6, tmp10);
    else
    {
      tmp12 = modf(1.0/tmp7, &tmp11);
      if(tmp12 > 0.5)
      {
        tmp12 -= 1.0;
        tmp11 += 1.0;
      }
      else if(tmp12 < -0.5)
      {
        tmp12 += 1.0;
        tmp11 -= 1.0;
      }
      if(fabs(tmp12) < 1e-10 && ((unsigned long)tmp11 & 1))
      {
        tmp8 = -pow(-tmp6, tmp9)*pow(tmp6, tmp10);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp6, tmp7);
      }
    }
  }
  else
  {
    tmp8 = pow(tmp6, tmp7);
  }
  if(isnan(tmp8) || isinf(tmp8))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp6, tmp7);
  }
  jacobian->tmpVars[4] /* kf_1.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_TMP_VAR */ = (98.56) * ((jacobian->tmpVars[3] /* eps_1.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_TMP_VAR */) * ((tmp8) * (jacobian->tmpVars[0] /* $cse2 JACOBIAN_TMP_VAR */)));
  threadData->lastEquationSolved = 21;
}

/*
equation index: 22
type: SIMPLE_ASSIGN
Qp_1.$pDERNLSJac0.dummyVarNLSJac0 = 0.12 * Ld_1.$pDERNLSJac0.dummyVarNLSJac0 / h_in_s
*/
void TwoStandMill_eqFunction_22(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,22};
  jacobian->tmpVars[5] /* Qp_1.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_TMP_VAR */ = (0.12) * (DIVISION(jacobian->tmpVars[2] /* Ld_1.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_TMP_VAR */,(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */),"h_in_s"));
  threadData->lastEquationSolved = 22;
}

/*
equation index: 23
type: SIMPLE_ASSIGN
P_1_raw.$pDERNLSJac0.dummyVarNLSJac0 = 0.001 * width * (Ld_1 * (Qp_1 * kf_1.$pDERNLSJac0.dummyVarNLSJac0 + Qp_1.$pDERNLSJac0.dummyVarNLSJac0 * kf_1) + Ld_1.$pDERNLSJac0.dummyVarNLSJac0 * Qp_1 * kf_1)
*/
void TwoStandMill_eqFunction_23(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,23};
  jacobian->tmpVars[6] /* P_1_raw.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_TMP_VAR */ = (0.001) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* width variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* Ld_1 variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* Qp_1 variable */)) * (jacobian->tmpVars[4] /* kf_1.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[5] /* Qp_1.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* kf_1 variable */))) + (jacobian->tmpVars[2] /* Ld_1.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* Qp_1 variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* kf_1 variable */)))));
  threadData->lastEquationSolved = 23;
}

/*
equation index: 24
type: SIMPLE_ASSIGN
$res_NLSJac0_1.$pDERNLSJac0.dummyVarNLSJac0 = (if noEvent(h_min > $cse1) then 0.0 else if noEvent(0.95 * h_in_s < S0_1 + P_1_raw / K_mill_1) then 0.0 else P_1_raw.$pDERNLSJac0.dummyVarNLSJac0 * K_mill_1 / K_mill_1 ^ 2.0) - ho_1.SeedNLSJac0
*/
void TwoStandMill_eqFunction_24(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,24};
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  modelica_real tmp15;
  modelica_boolean tmp16;
  modelica_real tmp17;
  modelica_boolean tmp18;
  modelica_real tmp19;
  tmp13 = Greater((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),jacobian->tmpVars[1] /* $cse1 JACOBIAN_TMP_VAR */);
  tmp18 = (modelica_boolean)tmp13;
  if(tmp18)
  {
    tmp19 = 0.0;
  }
  else
  {
    tmp14 = Less((0.95) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */)),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[43]] /* S0_1 variable */) + DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* P_1_raw variable */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[4]] /* K_mill_1 PARAM */),"K_mill_1"));
    tmp16 = (modelica_boolean)tmp14;
    if(tmp16)
    {
      tmp17 = 0.0;
    }
    else
    {
      tmp15 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[4]] /* K_mill_1 PARAM */);
      tmp17 = DIVISION((jacobian->tmpVars[6] /* P_1_raw.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[4]] /* K_mill_1 PARAM */)),(tmp15 * tmp15),"K_mill_1 ^ 2.0");
    }
    tmp19 = tmp17;
  }
  jacobian->resultVars[0] /* $res_NLSJac0_1.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_VAR */ = tmp19 - jacobian->seedVars[0] /* ho_1.SeedNLSJac0 SEED_VAR */;
  threadData->lastEquationSolved = 24;
}

OMC_DISABLE_OPT
int TwoStandMill_functionJacNLSJac0_constantEqns(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = TwoStandMill_INDEX_JAC_NLSJac0;
  
  
  return 0;
}

int TwoStandMill_functionJacNLSJac0_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = TwoStandMill_INDEX_JAC_NLSJac0;
  
  static void (*const eqFunctions[8])(DATA*, threadData_t*, JACOBIAN*, JACOBIAN*) = {
    TwoStandMill_eqFunction_17,
    TwoStandMill_eqFunction_18,
    TwoStandMill_eqFunction_19,
    TwoStandMill_eqFunction_20,
    TwoStandMill_eqFunction_21,
    TwoStandMill_eqFunction_22,
    TwoStandMill_eqFunction_23,
    TwoStandMill_eqFunction_24
  };
  
  if (jacobian->evalSelection) {
    for (int i = 0; i < jacobian->evalSelection->n; i++) {
      int id = jacobian->evalSelection->idx[i];
      eqFunctions[id](data, threadData, jacobian, parentJacobian);
    }
  } else {
    for (int id = 0; id < 8; id++) {
      eqFunctions[id](data, threadData, jacobian, parentJacobian);
    }
  }
  
  return 0;
}

void TwoStandMill_JacNLSJac0_DAG(DATA* data, threadData_t* threadData, JACOBIAN* jacobian)
{
  const size_t eqMap[] = {17, 18, 19, 20, 21, 22, 23, 24};
  buildEvalDAG_Jac(jacobian, data->modelData, sizeof(eqMap)/sizeof(size_t), eqMap);
}

/* constant equations */
/* dynamic equations */

/*
equation index: 33
type: SIMPLE_ASSIGN
$cse3 = min(0.95 * ho_1, S0_2 + P_2_raw / K_mill_2)
*/
void TwoStandMill_eqFunction_33(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,33};
  jacobian->tmpVars[1] /* $cse3 JACOBIAN_TMP_VAR */ = fmin((0.95) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */)),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[44]] /* S0_2 variable */) + DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* P_2_raw variable */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[5]] /* K_mill_2 PARAM */),"K_mill_2"));
  threadData->lastEquationSolved = 33;
}

/*
equation index: 34
type: SIMPLE_ASSIGN
$cse4 = exp((-0.0018) * (temp - 950.0))
*/
void TwoStandMill_eqFunction_34(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,34};
  jacobian->tmpVars[0] /* $cse4 JACOBIAN_TMP_VAR */ = exp((-0.0018) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[65]] /* temp variable */) - 950.0));
  threadData->lastEquationSolved = 34;
}

/*
equation index: 35
type: SIMPLE_ASSIGN
Ld_2.$pDERNLSJac1.dummyVarNLSJac1 = 0.5 * R_2 * (if noEvent(h_min > ho_1 - ho_2) then 0.0 else -ho_2.SeedNLSJac1) / sqrt(R_2 * max(h_min, ho_1 - ho_2))
*/
void TwoStandMill_eqFunction_35(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,35};
  modelica_boolean tmp20;
  modelica_real tmp21;
  tmp20 = Greater((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */));
  tmp21 = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[11]] /* R_2 PARAM */)) * (fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */)));
  if(!(tmp21 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(R_2 * max(h_min, ho_1 - ho_2)) was %g should be >= 0", tmp21);
    }
  }
  jacobian->tmpVars[2] /* Ld_2.$pDERNLSJac1.dummyVarNLSJac1 JACOBIAN_TMP_VAR */ = (0.5) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[11]] /* R_2 PARAM */)) * (DIVISION((tmp20?0.0:(-jacobian->seedVars[0] /* ho_2.SeedNLSJac1 SEED_VAR */)),sqrt(tmp21),"sqrt(R_2 * max(h_min, ho_1 - ho_2))")));
  threadData->lastEquationSolved = 35;
}

/*
equation index: 36
type: SIMPLE_ASSIGN
eps_2.$pDERNLSJac1.dummyVarNLSJac1 = if noEvent(eps_min > (ho_1 - ho_2) / ho_1) then 0.0 else (-ho_2.SeedNLSJac1) * ho_1 / ho_1 ^ 2.0
*/
void TwoStandMill_eqFunction_36(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,36};
  modelica_boolean tmp22;
  modelica_real tmp23;
  modelica_boolean tmp24;
  modelica_real tmp25;
  tmp22 = Greater((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[19]] /* eps_min PARAM */),DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */),"ho_1"));
  tmp24 = (modelica_boolean)tmp22;
  if(tmp24)
  {
    tmp25 = 0.0;
  }
  else
  {
    tmp23 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */);
    tmp25 = DIVISION(((-jacobian->seedVars[0] /* ho_2.SeedNLSJac1 SEED_VAR */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */)),(tmp23 * tmp23),"ho_1 ^ 2.0");
  }
  jacobian->tmpVars[3] /* eps_2.$pDERNLSJac1.dummyVarNLSJac1 JACOBIAN_TMP_VAR */ = tmp25;
  threadData->lastEquationSolved = 36;
}

/*
equation index: 37
type: SIMPLE_ASSIGN
kf_2.$pDERNLSJac1.dummyVarNLSJac1 = 98.56 * eps_2.$pDERNLSJac1.dummyVarNLSJac1 * (1.0 + 2.8 * eps_2) ^ (-0.78) * $cse4
*/
void TwoStandMill_eqFunction_37(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,37};
  modelica_real tmp26;
  modelica_real tmp27;
  modelica_real tmp28;
  modelica_real tmp29;
  modelica_real tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  tmp26 = 1.0 + (2.8) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* eps_2 variable */));
  tmp27 = -0.78;
  if(tmp26 < 0.0 && tmp27 != 0.0)
  {
    tmp29 = modf(tmp27, &tmp30);
    
    if(tmp29 > 0.5)
    {
      tmp29 -= 1.0;
      tmp30 += 1.0;
    }
    else if(tmp29 < -0.5)
    {
      tmp29 += 1.0;
      tmp30 -= 1.0;
    }
    
    if(fabs(tmp29) < 1e-10)
      tmp28 = pow(tmp26, tmp30);
    else
    {
      tmp32 = modf(1.0/tmp27, &tmp31);
      if(tmp32 > 0.5)
      {
        tmp32 -= 1.0;
        tmp31 += 1.0;
      }
      else if(tmp32 < -0.5)
      {
        tmp32 += 1.0;
        tmp31 -= 1.0;
      }
      if(fabs(tmp32) < 1e-10 && ((unsigned long)tmp31 & 1))
      {
        tmp28 = -pow(-tmp26, tmp29)*pow(tmp26, tmp30);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp26, tmp27);
      }
    }
  }
  else
  {
    tmp28 = pow(tmp26, tmp27);
  }
  if(isnan(tmp28) || isinf(tmp28))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp26, tmp27);
  }
  jacobian->tmpVars[4] /* kf_2.$pDERNLSJac1.dummyVarNLSJac1 JACOBIAN_TMP_VAR */ = (98.56) * ((jacobian->tmpVars[3] /* eps_2.$pDERNLSJac1.dummyVarNLSJac1 JACOBIAN_TMP_VAR */) * ((tmp28) * (jacobian->tmpVars[0] /* $cse4 JACOBIAN_TMP_VAR */)));
  threadData->lastEquationSolved = 37;
}

/*
equation index: 38
type: SIMPLE_ASSIGN
Qp_2.$pDERNLSJac1.dummyVarNLSJac1 = 0.12 * Ld_2.$pDERNLSJac1.dummyVarNLSJac1 / ho_1
*/
void TwoStandMill_eqFunction_38(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,38};
  jacobian->tmpVars[5] /* Qp_2.$pDERNLSJac1.dummyVarNLSJac1 JACOBIAN_TMP_VAR */ = (0.12) * (DIVISION(jacobian->tmpVars[2] /* Ld_2.$pDERNLSJac1.dummyVarNLSJac1 JACOBIAN_TMP_VAR */,(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */),"ho_1"));
  threadData->lastEquationSolved = 38;
}

/*
equation index: 39
type: SIMPLE_ASSIGN
P_2_raw.$pDERNLSJac1.dummyVarNLSJac1 = 0.001 * width * (Ld_2 * (Qp_2 * kf_2.$pDERNLSJac1.dummyVarNLSJac1 + Qp_2.$pDERNLSJac1.dummyVarNLSJac1 * kf_2) + Ld_2.$pDERNLSJac1.dummyVarNLSJac1 * Qp_2 * kf_2)
*/
void TwoStandMill_eqFunction_39(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,39};
  jacobian->tmpVars[6] /* P_2_raw.$pDERNLSJac1.dummyVarNLSJac1 JACOBIAN_TMP_VAR */ = (0.001) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* width variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* Ld_2 variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[42]] /* Qp_2 variable */)) * (jacobian->tmpVars[4] /* kf_2.$pDERNLSJac1.dummyVarNLSJac1 JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[5] /* Qp_2.$pDERNLSJac1.dummyVarNLSJac1 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* kf_2 variable */))) + (jacobian->tmpVars[2] /* Ld_2.$pDERNLSJac1.dummyVarNLSJac1 JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[42]] /* Qp_2 variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* kf_2 variable */)))));
  threadData->lastEquationSolved = 39;
}

/*
equation index: 40
type: SIMPLE_ASSIGN
$res_NLSJac1_1.$pDERNLSJac1.dummyVarNLSJac1 = (if noEvent(h_min > $cse3) then 0.0 else if noEvent(0.95 * ho_1 < S0_2 + P_2_raw / K_mill_2) then 0.0 else P_2_raw.$pDERNLSJac1.dummyVarNLSJac1 * K_mill_2 / K_mill_2 ^ 2.0) - ho_2.SeedNLSJac1
*/
void TwoStandMill_eqFunction_40(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,40};
  modelica_boolean tmp33;
  modelica_boolean tmp34;
  modelica_real tmp35;
  modelica_boolean tmp36;
  modelica_real tmp37;
  modelica_boolean tmp38;
  modelica_real tmp39;
  tmp33 = Greater((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),jacobian->tmpVars[1] /* $cse3 JACOBIAN_TMP_VAR */);
  tmp38 = (modelica_boolean)tmp33;
  if(tmp38)
  {
    tmp39 = 0.0;
  }
  else
  {
    tmp34 = Less((0.95) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */)),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[44]] /* S0_2 variable */) + DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* P_2_raw variable */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[5]] /* K_mill_2 PARAM */),"K_mill_2"));
    tmp36 = (modelica_boolean)tmp34;
    if(tmp36)
    {
      tmp37 = 0.0;
    }
    else
    {
      tmp35 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[5]] /* K_mill_2 PARAM */);
      tmp37 = DIVISION((jacobian->tmpVars[6] /* P_2_raw.$pDERNLSJac1.dummyVarNLSJac1 JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[5]] /* K_mill_2 PARAM */)),(tmp35 * tmp35),"K_mill_2 ^ 2.0");
    }
    tmp39 = tmp37;
  }
  jacobian->resultVars[0] /* $res_NLSJac1_1.$pDERNLSJac1.dummyVarNLSJac1 JACOBIAN_VAR */ = tmp39 - jacobian->seedVars[0] /* ho_2.SeedNLSJac1 SEED_VAR */;
  threadData->lastEquationSolved = 40;
}

OMC_DISABLE_OPT
int TwoStandMill_functionJacNLSJac1_constantEqns(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = TwoStandMill_INDEX_JAC_NLSJac1;
  
  
  return 0;
}

int TwoStandMill_functionJacNLSJac1_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = TwoStandMill_INDEX_JAC_NLSJac1;
  
  static void (*const eqFunctions[8])(DATA*, threadData_t*, JACOBIAN*, JACOBIAN*) = {
    TwoStandMill_eqFunction_33,
    TwoStandMill_eqFunction_34,
    TwoStandMill_eqFunction_35,
    TwoStandMill_eqFunction_36,
    TwoStandMill_eqFunction_37,
    TwoStandMill_eqFunction_38,
    TwoStandMill_eqFunction_39,
    TwoStandMill_eqFunction_40
  };
  
  if (jacobian->evalSelection) {
    for (int i = 0; i < jacobian->evalSelection->n; i++) {
      int id = jacobian->evalSelection->idx[i];
      eqFunctions[id](data, threadData, jacobian, parentJacobian);
    }
  } else {
    for (int id = 0; id < 8; id++) {
      eqFunctions[id](data, threadData, jacobian, parentJacobian);
    }
  }
  
  return 0;
}

void TwoStandMill_JacNLSJac1_DAG(DATA* data, threadData_t* threadData, JACOBIAN* jacobian)
{
  const size_t eqMap[] = {33, 34, 35, 36, 37, 38, 39, 40};
  buildEvalDAG_Jac(jacobian, data->modelData, sizeof(eqMap)/sizeof(size_t), eqMap);
}

/* constant equations */
/* dynamic equations */

/*
equation index: 120
type: SIMPLE_ASSIGN
Ld_1.$pDERNLSJac2.dummyVarNLSJac2 = 0.5 * R_1 * (if noEvent(h_min > h_in_s - ho_1) then 0.0 else -ho_1.SeedNLSJac2) / sqrt(R_1 * max(h_min, h_in_s - ho_1))
*/
void TwoStandMill_eqFunction_120(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,120};
  modelica_boolean tmp40;
  modelica_real tmp41;
  tmp40 = Greater((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */));
  tmp41 = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[10]] /* R_1 PARAM */)) * (fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */)));
  if(!(tmp41 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(R_1 * max(h_min, h_in_s - ho_1)) was %g should be >= 0", tmp41);
    }
  }
  jacobian->tmpVars[0] /* Ld_1.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */ = (0.5) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[10]] /* R_1 PARAM */)) * (DIVISION((tmp40?0.0:(-jacobian->seedVars[0] /* ho_1.SeedNLSJac2 SEED_VAR */)),sqrt(tmp41),"sqrt(R_1 * max(h_min, h_in_s - ho_1))")));
  threadData->lastEquationSolved = 120;
}

/*
equation index: 121
type: SIMPLE_ASSIGN
eps_1.$pDERNLSJac2.dummyVarNLSJac2 = if noEvent(eps_min > (h_in_s - ho_1) / h_in_s) then 0.0 else (-ho_1.SeedNLSJac2) * h_in_s / h_in_s ^ 2.0
*/
void TwoStandMill_eqFunction_121(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,121};
  modelica_boolean tmp42;
  modelica_real tmp43;
  modelica_boolean tmp44;
  modelica_real tmp45;
  tmp42 = Greater((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[19]] /* eps_min PARAM */),DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */),"h_in_s"));
  tmp44 = (modelica_boolean)tmp42;
  if(tmp44)
  {
    tmp45 = 0.0;
  }
  else
  {
    tmp43 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */);
    tmp45 = DIVISION(((-jacobian->seedVars[0] /* ho_1.SeedNLSJac2 SEED_VAR */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */)),(tmp43 * tmp43),"h_in_s ^ 2.0");
  }
  jacobian->tmpVars[1] /* eps_1.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */ = tmp45;
  threadData->lastEquationSolved = 121;
}

/*
equation index: 122
type: SIMPLE_ASSIGN
kf_1.$pDERNLSJac2.dummyVarNLSJac2 = 98.56 * eps_1.$pDERNLSJac2.dummyVarNLSJac2 * (1.0 + 2.8 * eps_1) ^ (-0.78) * $cse6
*/
void TwoStandMill_eqFunction_122(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,122};
  modelica_real tmp46;
  modelica_real tmp47;
  modelica_real tmp48;
  modelica_real tmp49;
  modelica_real tmp50;
  modelica_real tmp51;
  modelica_real tmp52;
  tmp46 = 1.0 + (2.8) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[53]] /* eps_1 variable */));
  tmp47 = -0.78;
  if(tmp46 < 0.0 && tmp47 != 0.0)
  {
    tmp49 = modf(tmp47, &tmp50);
    
    if(tmp49 > 0.5)
    {
      tmp49 -= 1.0;
      tmp50 += 1.0;
    }
    else if(tmp49 < -0.5)
    {
      tmp49 += 1.0;
      tmp50 -= 1.0;
    }
    
    if(fabs(tmp49) < 1e-10)
      tmp48 = pow(tmp46, tmp50);
    else
    {
      tmp52 = modf(1.0/tmp47, &tmp51);
      if(tmp52 > 0.5)
      {
        tmp52 -= 1.0;
        tmp51 += 1.0;
      }
      else if(tmp52 < -0.5)
      {
        tmp52 += 1.0;
        tmp51 -= 1.0;
      }
      if(fabs(tmp52) < 1e-10 && ((unsigned long)tmp51 & 1))
      {
        tmp48 = -pow(-tmp46, tmp49)*pow(tmp46, tmp50);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp46, tmp47);
      }
    }
  }
  else
  {
    tmp48 = pow(tmp46, tmp47);
  }
  if(isnan(tmp48) || isinf(tmp48))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp46, tmp47);
  }
  jacobian->tmpVars[2] /* kf_1.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */ = (98.56) * ((jacobian->tmpVars[1] /* eps_1.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */) * ((tmp48) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* $cse6 variable */))));
  threadData->lastEquationSolved = 122;
}

/*
equation index: 123
type: SIMPLE_ASSIGN
Qp_1.$pDERNLSJac2.dummyVarNLSJac2 = 0.12 * Ld_1.$pDERNLSJac2.dummyVarNLSJac2 / h_in_s
*/
void TwoStandMill_eqFunction_123(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,123};
  jacobian->tmpVars[3] /* Qp_1.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */ = (0.12) * (DIVISION(jacobian->tmpVars[0] /* Ld_1.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */,(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */),"h_in_s"));
  threadData->lastEquationSolved = 123;
}

/*
equation index: 124
type: SIMPLE_ASSIGN
P_1_raw.$pDERNLSJac2.dummyVarNLSJac2 = 0.001 * width * (Ld_1 * (Qp_1 * kf_1.$pDERNLSJac2.dummyVarNLSJac2 + Qp_1.$pDERNLSJac2.dummyVarNLSJac2 * kf_1) + Ld_1.$pDERNLSJac2.dummyVarNLSJac2 * Qp_1 * kf_1)
*/
void TwoStandMill_eqFunction_124(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,124};
  jacobian->tmpVars[4] /* P_1_raw.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */ = (0.001) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* width variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* Ld_1 variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* Qp_1 variable */)) * (jacobian->tmpVars[2] /* kf_1.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[3] /* Qp_1.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* kf_1 variable */))) + (jacobian->tmpVars[0] /* Ld_1.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* Qp_1 variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* kf_1 variable */)))));
  threadData->lastEquationSolved = 124;
}

/*
equation index: 125
type: SIMPLE_ASSIGN
$cse7.$pDERNLSJac2.dummyVarNLSJac2 = if noEvent(0.95 * h_in_s < S0_1 + P_1_raw / K_mill_1) then 0.0 else P_1_raw.$pDERNLSJac2.dummyVarNLSJac2 * K_mill_1 / K_mill_1 ^ 2.0
*/
void TwoStandMill_eqFunction_125(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,125};
  modelica_boolean tmp53;
  modelica_real tmp54;
  modelica_boolean tmp55;
  modelica_real tmp56;
  tmp53 = Less((0.95) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */)),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[43]] /* S0_1 variable */) + DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* P_1_raw variable */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[4]] /* K_mill_1 PARAM */),"K_mill_1"));
  tmp55 = (modelica_boolean)tmp53;
  if(tmp55)
  {
    tmp56 = 0.0;
  }
  else
  {
    tmp54 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[4]] /* K_mill_1 PARAM */);
    tmp56 = DIVISION((jacobian->tmpVars[4] /* P_1_raw.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[4]] /* K_mill_1 PARAM */)),(tmp54 * tmp54),"K_mill_1 ^ 2.0");
  }
  jacobian->tmpVars[5] /* $cse7.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */ = tmp56;
  threadData->lastEquationSolved = 125;
}

/*
equation index: 126
type: SIMPLE_ASSIGN
$res_NLSJac2_1.$pDERNLSJac2.dummyVarNLSJac2 = (if noEvent(h_min > $cse7) then 0.0 else $cse7.$pDERNLSJac2.dummyVarNLSJac2) - ho_1.SeedNLSJac2
*/
void TwoStandMill_eqFunction_126(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,126};
  modelica_boolean tmp57;
  tmp57 = Greater((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* $cse7 variable */));
  jacobian->resultVars[0] /* $res_NLSJac2_1.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_VAR */ = (tmp57?0.0:jacobian->tmpVars[5] /* $cse7.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */) - jacobian->seedVars[0] /* ho_1.SeedNLSJac2 SEED_VAR */;
  threadData->lastEquationSolved = 126;
}

OMC_DISABLE_OPT
int TwoStandMill_functionJacNLSJac2_constantEqns(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = TwoStandMill_INDEX_JAC_NLSJac2;
  
  
  return 0;
}

int TwoStandMill_functionJacNLSJac2_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = TwoStandMill_INDEX_JAC_NLSJac2;
  
  static void (*const eqFunctions[7])(DATA*, threadData_t*, JACOBIAN*, JACOBIAN*) = {
    TwoStandMill_eqFunction_120,
    TwoStandMill_eqFunction_121,
    TwoStandMill_eqFunction_122,
    TwoStandMill_eqFunction_123,
    TwoStandMill_eqFunction_124,
    TwoStandMill_eqFunction_125,
    TwoStandMill_eqFunction_126
  };
  
  if (jacobian->evalSelection) {
    for (int i = 0; i < jacobian->evalSelection->n; i++) {
      int id = jacobian->evalSelection->idx[i];
      eqFunctions[id](data, threadData, jacobian, parentJacobian);
    }
  } else {
    for (int id = 0; id < 7; id++) {
      eqFunctions[id](data, threadData, jacobian, parentJacobian);
    }
  }
  
  return 0;
}

void TwoStandMill_JacNLSJac2_DAG(DATA* data, threadData_t* threadData, JACOBIAN* jacobian)
{
  const size_t eqMap[] = {120, 121, 122, 123, 124, 125, 126};
  buildEvalDAG_Jac(jacobian, data->modelData, sizeof(eqMap)/sizeof(size_t), eqMap);
}

/* constant equations */
/* dynamic equations */

/*
equation index: 140
type: SIMPLE_ASSIGN
eps_2.$pDERNLSJac3.dummyVarNLSJac3 = if noEvent(eps_min > (ho_1 - ho_2) / ho_1) then 0.0 else (-ho_2.SeedNLSJac3) * ho_1 / ho_1 ^ 2.0
*/
void TwoStandMill_eqFunction_140(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,140};
  modelica_boolean tmp58;
  modelica_real tmp59;
  modelica_boolean tmp60;
  modelica_real tmp61;
  tmp58 = Greater((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[19]] /* eps_min PARAM */),DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */),"ho_1"));
  tmp60 = (modelica_boolean)tmp58;
  if(tmp60)
  {
    tmp61 = 0.0;
  }
  else
  {
    tmp59 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */);
    tmp61 = DIVISION(((-jacobian->seedVars[0] /* ho_2.SeedNLSJac3 SEED_VAR */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */)),(tmp59 * tmp59),"ho_1 ^ 2.0");
  }
  jacobian->tmpVars[0] /* eps_2.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_TMP_VAR */ = tmp61;
  threadData->lastEquationSolved = 140;
}

/*
equation index: 141
type: SIMPLE_ASSIGN
kf_2.$pDERNLSJac3.dummyVarNLSJac3 = 98.56 * eps_2.$pDERNLSJac3.dummyVarNLSJac3 * (1.0 + 2.8 * eps_2) ^ (-0.78) * $cse6
*/
void TwoStandMill_eqFunction_141(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,141};
  modelica_real tmp62;
  modelica_real tmp63;
  modelica_real tmp64;
  modelica_real tmp65;
  modelica_real tmp66;
  modelica_real tmp67;
  modelica_real tmp68;
  tmp62 = 1.0 + (2.8) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* eps_2 variable */));
  tmp63 = -0.78;
  if(tmp62 < 0.0 && tmp63 != 0.0)
  {
    tmp65 = modf(tmp63, &tmp66);
    
    if(tmp65 > 0.5)
    {
      tmp65 -= 1.0;
      tmp66 += 1.0;
    }
    else if(tmp65 < -0.5)
    {
      tmp65 += 1.0;
      tmp66 -= 1.0;
    }
    
    if(fabs(tmp65) < 1e-10)
      tmp64 = pow(tmp62, tmp66);
    else
    {
      tmp68 = modf(1.0/tmp63, &tmp67);
      if(tmp68 > 0.5)
      {
        tmp68 -= 1.0;
        tmp67 += 1.0;
      }
      else if(tmp68 < -0.5)
      {
        tmp68 += 1.0;
        tmp67 -= 1.0;
      }
      if(fabs(tmp68) < 1e-10 && ((unsigned long)tmp67 & 1))
      {
        tmp64 = -pow(-tmp62, tmp65)*pow(tmp62, tmp66);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp62, tmp63);
      }
    }
  }
  else
  {
    tmp64 = pow(tmp62, tmp63);
  }
  if(isnan(tmp64) || isinf(tmp64))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp62, tmp63);
  }
  jacobian->tmpVars[1] /* kf_2.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_TMP_VAR */ = (98.56) * ((jacobian->tmpVars[0] /* eps_2.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_TMP_VAR */) * ((tmp64) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* $cse6 variable */))));
  threadData->lastEquationSolved = 141;
}

/*
equation index: 142
type: SIMPLE_ASSIGN
Ld_2.$pDERNLSJac3.dummyVarNLSJac3 = 0.5 * R_2 * (if noEvent(h_min > ho_1 - ho_2) then 0.0 else -ho_2.SeedNLSJac3) / sqrt(R_2 * max(h_min, ho_1 - ho_2))
*/
void TwoStandMill_eqFunction_142(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,142};
  modelica_boolean tmp69;
  modelica_real tmp70;
  tmp69 = Greater((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */));
  tmp70 = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[11]] /* R_2 PARAM */)) * (fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */)));
  if(!(tmp70 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(R_2 * max(h_min, ho_1 - ho_2)) was %g should be >= 0", tmp70);
    }
  }
  jacobian->tmpVars[2] /* Ld_2.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_TMP_VAR */ = (0.5) * (((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[11]] /* R_2 PARAM */)) * (DIVISION((tmp69?0.0:(-jacobian->seedVars[0] /* ho_2.SeedNLSJac3 SEED_VAR */)),sqrt(tmp70),"sqrt(R_2 * max(h_min, ho_1 - ho_2))")));
  threadData->lastEquationSolved = 142;
}

/*
equation index: 143
type: SIMPLE_ASSIGN
Qp_2.$pDERNLSJac3.dummyVarNLSJac3 = 0.12 * Ld_2.$pDERNLSJac3.dummyVarNLSJac3 / ho_1
*/
void TwoStandMill_eqFunction_143(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,143};
  jacobian->tmpVars[3] /* Qp_2.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_TMP_VAR */ = (0.12) * (DIVISION(jacobian->tmpVars[2] /* Ld_2.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_TMP_VAR */,(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */),"ho_1"));
  threadData->lastEquationSolved = 143;
}

/*
equation index: 144
type: SIMPLE_ASSIGN
P_2_raw.$pDERNLSJac3.dummyVarNLSJac3 = 0.001 * width * (Ld_2 * (Qp_2 * kf_2.$pDERNLSJac3.dummyVarNLSJac3 + Qp_2.$pDERNLSJac3.dummyVarNLSJac3 * kf_2) + Ld_2.$pDERNLSJac3.dummyVarNLSJac3 * Qp_2 * kf_2)
*/
void TwoStandMill_eqFunction_144(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,144};
  jacobian->tmpVars[4] /* P_2_raw.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_TMP_VAR */ = (0.001) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* width variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* Ld_2 variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[42]] /* Qp_2 variable */)) * (jacobian->tmpVars[1] /* kf_2.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_TMP_VAR */) + (jacobian->tmpVars[3] /* Qp_2.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* kf_2 variable */))) + (jacobian->tmpVars[2] /* Ld_2.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_TMP_VAR */) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[42]] /* Qp_2 variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* kf_2 variable */)))));
  threadData->lastEquationSolved = 144;
}

/*
equation index: 145
type: SIMPLE_ASSIGN
$cse5.$pDERNLSJac3.dummyVarNLSJac3 = if noEvent(0.95 * ho_1 < S0_2 + P_2_raw / K_mill_2) then 0.0 else P_2_raw.$pDERNLSJac3.dummyVarNLSJac3 * K_mill_2 / K_mill_2 ^ 2.0
*/
void TwoStandMill_eqFunction_145(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,145};
  modelica_boolean tmp71;
  modelica_real tmp72;
  modelica_boolean tmp73;
  modelica_real tmp74;
  tmp71 = Less((0.95) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */)),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[44]] /* S0_2 variable */) + DIVISION((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* P_2_raw variable */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[5]] /* K_mill_2 PARAM */),"K_mill_2"));
  tmp73 = (modelica_boolean)tmp71;
  if(tmp73)
  {
    tmp74 = 0.0;
  }
  else
  {
    tmp72 = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[5]] /* K_mill_2 PARAM */);
    tmp74 = DIVISION((jacobian->tmpVars[4] /* P_2_raw.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[5]] /* K_mill_2 PARAM */)),(tmp72 * tmp72),"K_mill_2 ^ 2.0");
  }
  jacobian->tmpVars[5] /* $cse5.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_TMP_VAR */ = tmp74;
  threadData->lastEquationSolved = 145;
}

/*
equation index: 146
type: SIMPLE_ASSIGN
$res_NLSJac3_1.$pDERNLSJac3.dummyVarNLSJac3 = (if noEvent(h_min > $cse5) then 0.0 else $cse5.$pDERNLSJac3.dummyVarNLSJac3) - ho_2.SeedNLSJac3
*/
void TwoStandMill_eqFunction_146(DATA *data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,146};
  modelica_boolean tmp75;
  tmp75 = Greater((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* $cse5 variable */));
  jacobian->resultVars[0] /* $res_NLSJac3_1.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_VAR */ = (tmp75?0.0:jacobian->tmpVars[5] /* $cse5.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_TMP_VAR */) - jacobian->seedVars[0] /* ho_2.SeedNLSJac3 SEED_VAR */;
  threadData->lastEquationSolved = 146;
}

OMC_DISABLE_OPT
int TwoStandMill_functionJacNLSJac3_constantEqns(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = TwoStandMill_INDEX_JAC_NLSJac3;
  
  
  return 0;
}

int TwoStandMill_functionJacNLSJac3_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = TwoStandMill_INDEX_JAC_NLSJac3;
  
  static void (*const eqFunctions[7])(DATA*, threadData_t*, JACOBIAN*, JACOBIAN*) = {
    TwoStandMill_eqFunction_140,
    TwoStandMill_eqFunction_141,
    TwoStandMill_eqFunction_142,
    TwoStandMill_eqFunction_143,
    TwoStandMill_eqFunction_144,
    TwoStandMill_eqFunction_145,
    TwoStandMill_eqFunction_146
  };
  
  if (jacobian->evalSelection) {
    for (int i = 0; i < jacobian->evalSelection->n; i++) {
      int id = jacobian->evalSelection->idx[i];
      eqFunctions[id](data, threadData, jacobian, parentJacobian);
    }
  } else {
    for (int id = 0; id < 7; id++) {
      eqFunctions[id](data, threadData, jacobian, parentJacobian);
    }
  }
  
  return 0;
}

void TwoStandMill_JacNLSJac3_DAG(DATA* data, threadData_t* threadData, JACOBIAN* jacobian)
{
  const size_t eqMap[] = {140, 141, 142, 143, 144, 145, 146};
  buildEvalDAG_Jac(jacobian, data->modelData, sizeof(eqMap)/sizeof(size_t), eqMap);
}

int TwoStandMill_functionJacADJ_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  return 0;
}

void TwoStandMill_JacADJ_DAG(DATA* data, threadData_t* threadData, JACOBIAN* jacobian) { /* empty */ }

int TwoStandMill_functionJacH_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  return 0;
}

void TwoStandMill_JacH_DAG(DATA* data, threadData_t* threadData, JACOBIAN* jacobian) { /* empty */ }

int TwoStandMill_functionJacF_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  return 0;
}

void TwoStandMill_JacF_DAG(DATA* data, threadData_t* threadData, JACOBIAN* jacobian) { /* empty */ }

int TwoStandMill_functionJacD_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  return 0;
}

void TwoStandMill_JacD_DAG(DATA* data, threadData_t* threadData, JACOBIAN* jacobian) { /* empty */ }

int TwoStandMill_functionJacC_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  return 0;
}

void TwoStandMill_JacC_DAG(DATA* data, threadData_t* threadData, JACOBIAN* jacobian) { /* empty */ }

int TwoStandMill_functionJacB_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  return 0;
}

void TwoStandMill_JacB_DAG(DATA* data, threadData_t* threadData, JACOBIAN* jacobian) { /* empty */ }

/* constant equations */
/* dynamic equations */

OMC_DISABLE_OPT
int TwoStandMill_functionJacA_constantEqns(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = TwoStandMill_INDEX_JAC_A;
  
  
  return 0;
}

int TwoStandMill_functionJacA_column(DATA* data, threadData_t *threadData, JACOBIAN *jacobian, JACOBIAN *parentJacobian)
{
  int index = TwoStandMill_INDEX_JAC_A;
  
  
  return 0;
}

void TwoStandMill_JacA_DAG(DATA* data, threadData_t* threadData, JACOBIAN* jacobian)
{
  const size_t eqMap[] = {};
  buildEvalDAG_Jac(jacobian, data->modelData, sizeof(eqMap)/sizeof(size_t), eqMap);
}

OMC_DISABLE_OPT
int TwoStandMill_initialAnalyticJacobianNLSJac0(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "TwoStandMill_JacNLSJac0.bin");
  
  initJacobian(jacobian, 1, 1, 8, NULL, TwoStandMill_functionJacNLSJac0_column, NULL, NULL);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  jacobian->isRowEval = 0 /* false */;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 1);
  
  omc_fclose(pFile);
  
  return 0;
}
OMC_DISABLE_OPT
int TwoStandMill_initialAnalyticJacobianNLSJac1(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "TwoStandMill_JacNLSJac1.bin");
  
  initJacobian(jacobian, 1, 1, 8, NULL, TwoStandMill_functionJacNLSJac1_column, NULL, NULL);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  jacobian->isRowEval = 0 /* false */;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 1);
  
  omc_fclose(pFile);
  
  return 0;
}
OMC_DISABLE_OPT
int TwoStandMill_initialAnalyticJacobianNLSJac2(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "TwoStandMill_JacNLSJac2.bin");
  
  initJacobian(jacobian, 1, 1, 7, NULL, TwoStandMill_functionJacNLSJac2_column, NULL, NULL);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  jacobian->isRowEval = 0 /* false */;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 1);
  
  omc_fclose(pFile);
  
  return 0;
}
OMC_DISABLE_OPT
int TwoStandMill_initialAnalyticJacobianNLSJac3(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "TwoStandMill_JacNLSJac3.bin");
  
  initJacobian(jacobian, 1, 1, 7, NULL, TwoStandMill_functionJacNLSJac3_column, NULL, NULL);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  jacobian->isRowEval = 0 /* false */;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 1);
  
  omc_fclose(pFile);
  
  return 0;
}
int TwoStandMill_initialAnalyticJacobianADJ(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int TwoStandMill_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int TwoStandMill_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int TwoStandMill_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int TwoStandMill_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int TwoStandMill_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
OMC_DISABLE_OPT
int TwoStandMill_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, JACOBIAN *jacobian)
{
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "TwoStandMill_JacA.bin");
  
  initJacobian(jacobian, 12, 12, 0, NULL, TwoStandMill_functionJacA_column, NULL, NULL);
  jacobian->sparsePattern = allocSparsePattern(12, 23, 3);
  jacobian->availability = JACOBIAN_ONLY_SPARSITY;
  jacobian->isRowEval = 0 /* false */;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 12+1, pFile, FALSE);
  if (count != 12+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 12+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 23, pFile, FALSE);
  if (count != 23) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 23, count);
  }
  
  /* write color array */
  /* color 1 with 2 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 2, 12);
  /* color 2 with 3 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 2, 3, 12);
  /* color 3 with 7 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 3, 7, 12);
  
  omc_fclose(pFile);
  
  return 0;
}


