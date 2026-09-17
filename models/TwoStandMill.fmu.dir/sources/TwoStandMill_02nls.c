/* Non Linear Systems */
#include "TwoStandMill_model.h"
#include "TwoStandMill_12jac.h"
#include "simulation/jacobian_util.h"
#include "simulation/arrayIndex.h"

#if defined(__cplusplus)
extern "C" {
#endif

/* inner equations */

/*
equation index: 11
type: SIMPLE_ASSIGN
Ld_1 = sqrt(R_1 * max(h_min, h_in_s - ho_1))
*/
void TwoStandMill_eqFunction_11(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,11};
  modelica_real tmp0;
  tmp0 = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[10]] /* R_1 PARAM */)) * (fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */)));
  if(!(tmp0 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(R_1 * max(h_min, h_in_s - ho_1)) was %g should be >= 0", tmp0);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* Ld_1 variable */) = sqrt(tmp0);
  threadData->lastEquationSolved = 11;
}
/*
equation index: 12
type: SIMPLE_ASSIGN
eps_1 = max(eps_min, (h_in_s - ho_1) / h_in_s)
*/
void TwoStandMill_eqFunction_12(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,12};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[53]] /* eps_1 variable */) = fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[19]] /* eps_min PARAM */),DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */),"h_in_s",equationIndexes));
  threadData->lastEquationSolved = 12;
}
/*
equation index: 13
type: SIMPLE_ASSIGN
kf_1 = 160.0 * (1.0 + 2.8 * eps_1) ^ 0.22 * exp((-0.0018) * (temp - 950.0))
*/
void TwoStandMill_eqFunction_13(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,13};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  tmp0 = 1.0 + (2.8) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[53]] /* eps_1 variable */));
  tmp1 = 0.22;
  if(tmp0 < 0.0 && tmp1 != 0.0)
  {
    tmp3 = modf(tmp1, &tmp4);
    
    if(tmp3 > 0.5)
    {
      tmp3 -= 1.0;
      tmp4 += 1.0;
    }
    else if(tmp3 < -0.5)
    {
      tmp3 += 1.0;
      tmp4 -= 1.0;
    }
    
    if(fabs(tmp3) < 1e-10)
      tmp2 = pow(tmp0, tmp4);
    else
    {
      tmp6 = modf(1.0/tmp1, &tmp5);
      if(tmp6 > 0.5)
      {
        tmp6 -= 1.0;
        tmp5 += 1.0;
      }
      else if(tmp6 < -0.5)
      {
        tmp6 += 1.0;
        tmp5 -= 1.0;
      }
      if(fabs(tmp6) < 1e-10 && ((unsigned long)tmp5 & 1))
      {
        tmp2 = -pow(-tmp0, tmp3)*pow(tmp0, tmp4);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
      }
    }
  }
  else
  {
    tmp2 = pow(tmp0, tmp1);
  }
  if(isnan(tmp2) || isinf(tmp2))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* kf_1 variable */) = (160.0) * ((tmp2) * (exp((-0.0018) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[65]] /* temp variable */) - 950.0))));
  threadData->lastEquationSolved = 13;
}
/*
equation index: 14
type: SIMPLE_ASSIGN
Qp_1 = 1.05 + 0.12 * Ld_1 / h_in_s
*/
void TwoStandMill_eqFunction_14(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,14};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* Qp_1 variable */) = 1.05 + (0.12) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* Ld_1 variable */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */),"h_in_s",equationIndexes));
  threadData->lastEquationSolved = 14;
}
/*
equation index: 15
type: SIMPLE_ASSIGN
P_1_raw = 0.001 * width * Ld_1 * Qp_1 * kf_1
*/
void TwoStandMill_eqFunction_15(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,15};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* P_1_raw variable */) = (0.001) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* width variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* Ld_1 variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* Qp_1 variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* kf_1 variable */)))));
  threadData->lastEquationSolved = 15;
}

void residualFunc25(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,25};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(OMC_LOG_NLS, 0, "residualFunc25: Iteration variable `%s` is inf or nan.",
        modelInfoGetEquation(&data->modelData->modelDataXml, 25).vars[i]);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc25 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  TwoStandMill_eqFunction_11(data, threadData);
  /* local constraints */
  TwoStandMill_eqFunction_12(data, threadData);
  /* local constraints */
  TwoStandMill_eqFunction_13(data, threadData);
  /* local constraints */
  TwoStandMill_eqFunction_14(data, threadData);
  /* local constraints */
  TwoStandMill_eqFunction_15(data, threadData);
  /* body */
  res[0] = fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),fmin((0.95) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */)),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[43]] /* S0_1 variable */) + DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* P_1_raw variable */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[4]] /* K_mill_1 PARAM */),"K_mill_1",equationIndexes))) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */);
  threadData->lastEquationSolved = 16;
  /* restore known outputs */
  threadData->lastEquationSolved = 25;
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS25(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = TRUE;
  inSysData->sparsePattern = allocSparsePattern(1, 1, 1);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
}

void freeSparsePatternNLS25(NONLINEAR_SYSTEM_DATA* inSysData)
{
  if (inSysData->isPatternAvailable) {
    freeSparsePattern(inSysData->sparsePattern);
    free(inSysData->sparsePattern);
    inSysData->sparsePattern = NULL;
    inSysData->isPatternAvailable = FALSE;
  }
}
OMC_DISABLE_OPT
void initializeNonlinearPatternNLS25(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  inSysData->nonlinearPattern = (NONLINEAR_PATTERN*) malloc(sizeof(NONLINEAR_PATTERN));
  inSysData->nonlinearPattern->numberOfVars = 1;
  inSysData->nonlinearPattern->numberOfEqns = 1;
  inSysData->nonlinearPattern->numberOfNonlinear = 1;
  inSysData->nonlinearPattern->indexVar = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->indexEqn = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->columns = (unsigned int*) malloc(1*sizeof(unsigned int));
  inSysData->nonlinearPattern->rows = (unsigned int*) malloc(1*sizeof(unsigned int));
  /* initialize and accumulate index vectors */
  const int index_var[1+1] = {0,1};
  const int index_eqn[1+1] = {0,1};
  memcpy(inSysData->nonlinearPattern->indexVar, index_var, (1+1)*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->indexEqn, index_eqn, (1+1)*sizeof(unsigned int));
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexVar[i] += inSysData->nonlinearPattern->indexVar[i-1];
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexEqn[i] += inSysData->nonlinearPattern->indexEqn[i-1];
  /* initialize columns and rows */
  const int columns[1] = {0};
  const int rows[1] = {0};
  memcpy(inSysData->nonlinearPattern->columns, columns, 1*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->rows, rows, 1*sizeof(unsigned int));
}

OMC_DISABLE_OPT
void initializeStaticDataNLS25(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for ho_1 */
  sysData->nominal[i] = getNominalFromScalarIdx(data->simulationInfo, data->modelData, VAR_KIND_VARIABLE, 59 /* ho_1 */);
  sysData->min[i]     = getMinFromScalarIdx(data->simulationInfo, data->modelData, VAR_TYPE_REAL, VAR_KIND_VARIABLE, 59 /* ho_1 */);
  sysData->max[i++]   = getMaxFromScalarIdx(data->simulationInfo, data->modelData, VAR_TYPE_REAL, VAR_KIND_VARIABLE, 59 /* ho_1 */);
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS25(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS25(sysData);
  }
}

OMC_DISABLE_OPT
void freeStaticDataNLS25(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData)
{
  freeSparsePatternNLS25(sysData);
}

OMC_DISABLE_OPT
void getIterationVarsNLS25(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */);
}


/* inner equations */

/*
equation index: 27
type: SIMPLE_ASSIGN
Ld_2 = sqrt(R_2 * max(h_min, ho_1 - ho_2))
*/
void TwoStandMill_eqFunction_27(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,27};
  modelica_real tmp0;
  tmp0 = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[11]] /* R_2 PARAM */)) * (fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */)));
  if(!(tmp0 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(R_2 * max(h_min, ho_1 - ho_2)) was %g should be >= 0", tmp0);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* Ld_2 variable */) = sqrt(tmp0);
  threadData->lastEquationSolved = 27;
}
/*
equation index: 28
type: SIMPLE_ASSIGN
eps_2 = max(eps_min, (ho_1 - ho_2) / ho_1)
*/
void TwoStandMill_eqFunction_28(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,28};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* eps_2 variable */) = fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[19]] /* eps_min PARAM */),DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */),"ho_1",equationIndexes));
  threadData->lastEquationSolved = 28;
}
/*
equation index: 29
type: SIMPLE_ASSIGN
kf_2 = 160.0 * (1.0 + 2.8 * eps_2) ^ 0.22 * exp((-0.0018) * (temp - 950.0))
*/
void TwoStandMill_eqFunction_29(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,29};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  tmp0 = 1.0 + (2.8) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* eps_2 variable */));
  tmp1 = 0.22;
  if(tmp0 < 0.0 && tmp1 != 0.0)
  {
    tmp3 = modf(tmp1, &tmp4);
    
    if(tmp3 > 0.5)
    {
      tmp3 -= 1.0;
      tmp4 += 1.0;
    }
    else if(tmp3 < -0.5)
    {
      tmp3 += 1.0;
      tmp4 -= 1.0;
    }
    
    if(fabs(tmp3) < 1e-10)
      tmp2 = pow(tmp0, tmp4);
    else
    {
      tmp6 = modf(1.0/tmp1, &tmp5);
      if(tmp6 > 0.5)
      {
        tmp6 -= 1.0;
        tmp5 += 1.0;
      }
      else if(tmp6 < -0.5)
      {
        tmp6 += 1.0;
        tmp5 -= 1.0;
      }
      if(fabs(tmp6) < 1e-10 && ((unsigned long)tmp5 & 1))
      {
        tmp2 = -pow(-tmp0, tmp3)*pow(tmp0, tmp4);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
      }
    }
  }
  else
  {
    tmp2 = pow(tmp0, tmp1);
  }
  if(isnan(tmp2) || isinf(tmp2))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* kf_2 variable */) = (160.0) * ((tmp2) * (exp((-0.0018) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[65]] /* temp variable */) - 950.0))));
  threadData->lastEquationSolved = 29;
}
/*
equation index: 30
type: SIMPLE_ASSIGN
Qp_2 = 1.05 + 0.12 * Ld_2 / ho_1
*/
void TwoStandMill_eqFunction_30(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,30};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[42]] /* Qp_2 variable */) = 1.05 + (0.12) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* Ld_2 variable */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */),"ho_1",equationIndexes));
  threadData->lastEquationSolved = 30;
}
/*
equation index: 31
type: SIMPLE_ASSIGN
P_2_raw = 0.001 * width * Ld_2 * Qp_2 * kf_2
*/
void TwoStandMill_eqFunction_31(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,31};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* P_2_raw variable */) = (0.001) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* width variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* Ld_2 variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[42]] /* Qp_2 variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* kf_2 variable */)))));
  threadData->lastEquationSolved = 31;
}

void residualFunc41(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,41};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(OMC_LOG_NLS, 0, "residualFunc41: Iteration variable `%s` is inf or nan.",
        modelInfoGetEquation(&data->modelData->modelDataXml, 41).vars[i]);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc41 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  TwoStandMill_eqFunction_27(data, threadData);
  /* local constraints */
  TwoStandMill_eqFunction_28(data, threadData);
  /* local constraints */
  TwoStandMill_eqFunction_29(data, threadData);
  /* local constraints */
  TwoStandMill_eqFunction_30(data, threadData);
  /* local constraints */
  TwoStandMill_eqFunction_31(data, threadData);
  /* body */
  res[0] = fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),fmin((0.95) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */)),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[44]] /* S0_2 variable */) + DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* P_2_raw variable */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[5]] /* K_mill_2 PARAM */),"K_mill_2",equationIndexes))) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */);
  threadData->lastEquationSolved = 32;
  /* restore known outputs */
  threadData->lastEquationSolved = 41;
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS41(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = TRUE;
  inSysData->sparsePattern = allocSparsePattern(1, 1, 1);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
}

void freeSparsePatternNLS41(NONLINEAR_SYSTEM_DATA* inSysData)
{
  if (inSysData->isPatternAvailable) {
    freeSparsePattern(inSysData->sparsePattern);
    free(inSysData->sparsePattern);
    inSysData->sparsePattern = NULL;
    inSysData->isPatternAvailable = FALSE;
  }
}
OMC_DISABLE_OPT
void initializeNonlinearPatternNLS41(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  inSysData->nonlinearPattern = (NONLINEAR_PATTERN*) malloc(sizeof(NONLINEAR_PATTERN));
  inSysData->nonlinearPattern->numberOfVars = 1;
  inSysData->nonlinearPattern->numberOfEqns = 1;
  inSysData->nonlinearPattern->numberOfNonlinear = 1;
  inSysData->nonlinearPattern->indexVar = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->indexEqn = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->columns = (unsigned int*) malloc(1*sizeof(unsigned int));
  inSysData->nonlinearPattern->rows = (unsigned int*) malloc(1*sizeof(unsigned int));
  /* initialize and accumulate index vectors */
  const int index_var[1+1] = {0,1};
  const int index_eqn[1+1] = {0,1};
  memcpy(inSysData->nonlinearPattern->indexVar, index_var, (1+1)*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->indexEqn, index_eqn, (1+1)*sizeof(unsigned int));
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexVar[i] += inSysData->nonlinearPattern->indexVar[i-1];
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexEqn[i] += inSysData->nonlinearPattern->indexEqn[i-1];
  /* initialize columns and rows */
  const int columns[1] = {0};
  const int rows[1] = {0};
  memcpy(inSysData->nonlinearPattern->columns, columns, 1*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->rows, rows, 1*sizeof(unsigned int));
}

OMC_DISABLE_OPT
void initializeStaticDataNLS41(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for ho_2 */
  sysData->nominal[i] = getNominalFromScalarIdx(data->simulationInfo, data->modelData, VAR_KIND_VARIABLE, 60 /* ho_2 */);
  sysData->min[i]     = getMinFromScalarIdx(data->simulationInfo, data->modelData, VAR_TYPE_REAL, VAR_KIND_VARIABLE, 60 /* ho_2 */);
  sysData->max[i++]   = getMaxFromScalarIdx(data->simulationInfo, data->modelData, VAR_TYPE_REAL, VAR_KIND_VARIABLE, 60 /* ho_2 */);
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS41(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS41(sysData);
  }
}

OMC_DISABLE_OPT
void freeStaticDataNLS41(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData)
{
  freeSparsePatternNLS41(sysData);
}

OMC_DISABLE_OPT
void getIterationVarsNLS41(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */);
}


/* inner equations */

/*
equation index: 113
type: SIMPLE_ASSIGN
Ld_1 = sqrt(R_1 * max(h_min, h_in_s - ho_1))
*/
void TwoStandMill_eqFunction_113(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,113};
  modelica_real tmp0;
  tmp0 = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[10]] /* R_1 PARAM */)) * (fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */)));
  if(!(tmp0 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(R_1 * max(h_min, h_in_s - ho_1)) was %g should be >= 0", tmp0);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* Ld_1 variable */) = sqrt(tmp0);
  threadData->lastEquationSolved = 113;
}
/*
equation index: 114
type: SIMPLE_ASSIGN
eps_1 = max(eps_min, (h_in_s - ho_1) / h_in_s)
*/
void TwoStandMill_eqFunction_114(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,114};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[53]] /* eps_1 variable */) = fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[19]] /* eps_min PARAM */),DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */),"h_in_s",equationIndexes));
  threadData->lastEquationSolved = 114;
}
/*
equation index: 115
type: SIMPLE_ASSIGN
kf_1 = 160.0 * (1.0 + 2.8 * eps_1) ^ 0.22 * $cse6
*/
void TwoStandMill_eqFunction_115(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,115};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  tmp0 = 1.0 + (2.8) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[53]] /* eps_1 variable */));
  tmp1 = 0.22;
  if(tmp0 < 0.0 && tmp1 != 0.0)
  {
    tmp3 = modf(tmp1, &tmp4);
    
    if(tmp3 > 0.5)
    {
      tmp3 -= 1.0;
      tmp4 += 1.0;
    }
    else if(tmp3 < -0.5)
    {
      tmp3 += 1.0;
      tmp4 -= 1.0;
    }
    
    if(fabs(tmp3) < 1e-10)
      tmp2 = pow(tmp0, tmp4);
    else
    {
      tmp6 = modf(1.0/tmp1, &tmp5);
      if(tmp6 > 0.5)
      {
        tmp6 -= 1.0;
        tmp5 += 1.0;
      }
      else if(tmp6 < -0.5)
      {
        tmp6 += 1.0;
        tmp5 -= 1.0;
      }
      if(fabs(tmp6) < 1e-10 && ((unsigned long)tmp5 & 1))
      {
        tmp2 = -pow(-tmp0, tmp3)*pow(tmp0, tmp4);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
      }
    }
  }
  else
  {
    tmp2 = pow(tmp0, tmp1);
  }
  if(isnan(tmp2) || isinf(tmp2))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* kf_1 variable */) = (160.0) * ((tmp2) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* $cse6 variable */)));
  threadData->lastEquationSolved = 115;
}
/*
equation index: 116
type: SIMPLE_ASSIGN
Qp_1 = 1.05 + 0.12 * Ld_1 / h_in_s
*/
void TwoStandMill_eqFunction_116(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,116};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* Qp_1 variable */) = 1.05 + (0.12) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* Ld_1 variable */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */),"h_in_s",equationIndexes));
  threadData->lastEquationSolved = 116;
}
/*
equation index: 117
type: SIMPLE_ASSIGN
P_1_raw = 0.001 * width * Ld_1 * Qp_1 * kf_1
*/
void TwoStandMill_eqFunction_117(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,117};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* P_1_raw variable */) = (0.001) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* width variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* Ld_1 variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* Qp_1 variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* kf_1 variable */)))));
  threadData->lastEquationSolved = 117;
}
/*
equation index: 118
type: SIMPLE_ASSIGN
$cse7 = min(0.95 * h_in_s, S0_1 + P_1_raw / K_mill_1)
*/
void TwoStandMill_eqFunction_118(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,118};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* $cse7 variable */) = fmin((0.95) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* h_in_s variable */)),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[43]] /* S0_1 variable */) + DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* P_1_raw variable */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[4]] /* K_mill_1 PARAM */),"K_mill_1",equationIndexes));
  threadData->lastEquationSolved = 118;
}

void residualFunc127(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,127};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(OMC_LOG_NLS, 0, "residualFunc127: Iteration variable `%s` is inf or nan.",
        modelInfoGetEquation(&data->modelData->modelDataXml, 127).vars[i]);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc127 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  TwoStandMill_eqFunction_113(data, threadData);
  /* local constraints */
  TwoStandMill_eqFunction_114(data, threadData);
  /* local constraints */
  TwoStandMill_eqFunction_115(data, threadData);
  /* local constraints */
  TwoStandMill_eqFunction_116(data, threadData);
  /* local constraints */
  TwoStandMill_eqFunction_117(data, threadData);
  /* local constraints */
  TwoStandMill_eqFunction_118(data, threadData);
  /* body */
  res[0] = fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* $cse7 variable */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */);
  threadData->lastEquationSolved = 119;
  /* restore known outputs */
  threadData->lastEquationSolved = 127;
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS127(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = TRUE;
  inSysData->sparsePattern = allocSparsePattern(1, 1, 1);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
}

void freeSparsePatternNLS127(NONLINEAR_SYSTEM_DATA* inSysData)
{
  if (inSysData->isPatternAvailable) {
    freeSparsePattern(inSysData->sparsePattern);
    free(inSysData->sparsePattern);
    inSysData->sparsePattern = NULL;
    inSysData->isPatternAvailable = FALSE;
  }
}
OMC_DISABLE_OPT
void initializeNonlinearPatternNLS127(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  inSysData->nonlinearPattern = (NONLINEAR_PATTERN*) malloc(sizeof(NONLINEAR_PATTERN));
  inSysData->nonlinearPattern->numberOfVars = 1;
  inSysData->nonlinearPattern->numberOfEqns = 1;
  inSysData->nonlinearPattern->numberOfNonlinear = 1;
  inSysData->nonlinearPattern->indexVar = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->indexEqn = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->columns = (unsigned int*) malloc(1*sizeof(unsigned int));
  inSysData->nonlinearPattern->rows = (unsigned int*) malloc(1*sizeof(unsigned int));
  /* initialize and accumulate index vectors */
  const int index_var[1+1] = {0,1};
  const int index_eqn[1+1] = {0,1};
  memcpy(inSysData->nonlinearPattern->indexVar, index_var, (1+1)*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->indexEqn, index_eqn, (1+1)*sizeof(unsigned int));
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexVar[i] += inSysData->nonlinearPattern->indexVar[i-1];
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexEqn[i] += inSysData->nonlinearPattern->indexEqn[i-1];
  /* initialize columns and rows */
  const int columns[1] = {0};
  const int rows[1] = {0};
  memcpy(inSysData->nonlinearPattern->columns, columns, 1*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->rows, rows, 1*sizeof(unsigned int));
}

OMC_DISABLE_OPT
void initializeStaticDataNLS127(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for ho_1 */
  sysData->nominal[i] = getNominalFromScalarIdx(data->simulationInfo, data->modelData, VAR_KIND_VARIABLE, 59 /* ho_1 */);
  sysData->min[i]     = getMinFromScalarIdx(data->simulationInfo, data->modelData, VAR_TYPE_REAL, VAR_KIND_VARIABLE, 59 /* ho_1 */);
  sysData->max[i++]   = getMaxFromScalarIdx(data->simulationInfo, data->modelData, VAR_TYPE_REAL, VAR_KIND_VARIABLE, 59 /* ho_1 */);
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS127(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS127(sysData);
  }
}

OMC_DISABLE_OPT
void freeStaticDataNLS127(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData)
{
  freeSparsePatternNLS127(sysData);
}

OMC_DISABLE_OPT
void getIterationVarsNLS127(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */);
}


/* inner equations */

/*
equation index: 133
type: SIMPLE_ASSIGN
eps_2 = max(eps_min, (ho_1 - ho_2) / ho_1)
*/
void TwoStandMill_eqFunction_133(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,133};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* eps_2 variable */) = fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[19]] /* eps_min PARAM */),DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */),"ho_1",equationIndexes));
  threadData->lastEquationSolved = 133;
}
/*
equation index: 134
type: SIMPLE_ASSIGN
kf_2 = 160.0 * (1.0 + 2.8 * eps_2) ^ 0.22 * $cse6
*/
void TwoStandMill_eqFunction_134(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,134};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  tmp0 = 1.0 + (2.8) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* eps_2 variable */));
  tmp1 = 0.22;
  if(tmp0 < 0.0 && tmp1 != 0.0)
  {
    tmp3 = modf(tmp1, &tmp4);
    
    if(tmp3 > 0.5)
    {
      tmp3 -= 1.0;
      tmp4 += 1.0;
    }
    else if(tmp3 < -0.5)
    {
      tmp3 += 1.0;
      tmp4 -= 1.0;
    }
    
    if(fabs(tmp3) < 1e-10)
      tmp2 = pow(tmp0, tmp4);
    else
    {
      tmp6 = modf(1.0/tmp1, &tmp5);
      if(tmp6 > 0.5)
      {
        tmp6 -= 1.0;
        tmp5 += 1.0;
      }
      else if(tmp6 < -0.5)
      {
        tmp6 += 1.0;
        tmp5 -= 1.0;
      }
      if(fabs(tmp6) < 1e-10 && ((unsigned long)tmp5 & 1))
      {
        tmp2 = -pow(-tmp0, tmp3)*pow(tmp0, tmp4);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
      }
    }
  }
  else
  {
    tmp2 = pow(tmp0, tmp1);
  }
  if(isnan(tmp2) || isinf(tmp2))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* kf_2 variable */) = (160.0) * ((tmp2) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* $cse6 variable */)));
  threadData->lastEquationSolved = 134;
}
/*
equation index: 135
type: SIMPLE_ASSIGN
Ld_2 = sqrt(R_2 * max(h_min, ho_1 - ho_2))
*/
void TwoStandMill_eqFunction_135(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,135};
  modelica_real tmp0;
  tmp0 = ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[11]] /* R_2 PARAM */)) * (fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */)));
  if(!(tmp0 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(R_2 * max(h_min, ho_1 - ho_2)) was %g should be >= 0", tmp0);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* Ld_2 variable */) = sqrt(tmp0);
  threadData->lastEquationSolved = 135;
}
/*
equation index: 136
type: SIMPLE_ASSIGN
Qp_2 = 1.05 + 0.12 * Ld_2 / ho_1
*/
void TwoStandMill_eqFunction_136(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,136};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[42]] /* Qp_2 variable */) = 1.05 + (0.12) * (DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* Ld_2 variable */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */),"ho_1",equationIndexes));
  threadData->lastEquationSolved = 136;
}
/*
equation index: 137
type: SIMPLE_ASSIGN
P_2_raw = 0.001 * width * Ld_2 * Qp_2 * kf_2
*/
void TwoStandMill_eqFunction_137(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,137};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* P_2_raw variable */) = (0.001) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* width variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* Ld_2 variable */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[42]] /* Qp_2 variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* kf_2 variable */)))));
  threadData->lastEquationSolved = 137;
}
/*
equation index: 138
type: SIMPLE_ASSIGN
$cse5 = min(0.95 * ho_1, S0_2 + P_2_raw / K_mill_2)
*/
void TwoStandMill_eqFunction_138(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,138};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* $cse5 variable */) = fmin((0.95) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* ho_1 variable */)),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[44]] /* S0_2 variable */) + DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* P_2_raw variable */),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[5]] /* K_mill_2 PARAM */),"K_mill_2",equationIndexes));
  threadData->lastEquationSolved = 138;
}

void residualFunc147(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,147};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(OMC_LOG_NLS, 0, "residualFunc147: Iteration variable `%s` is inf or nan.",
        modelInfoGetEquation(&data->modelData->modelDataXml, 147).vars[i]);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc147 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  TwoStandMill_eqFunction_133(data, threadData);
  /* local constraints */
  TwoStandMill_eqFunction_134(data, threadData);
  /* local constraints */
  TwoStandMill_eqFunction_135(data, threadData);
  /* local constraints */
  TwoStandMill_eqFunction_136(data, threadData);
  /* local constraints */
  TwoStandMill_eqFunction_137(data, threadData);
  /* local constraints */
  TwoStandMill_eqFunction_138(data, threadData);
  /* body */
  res[0] = fmax((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[21]] /* h_min PARAM */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* $cse5 variable */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */);
  threadData->lastEquationSolved = 139;
  /* restore known outputs */
  threadData->lastEquationSolved = 147;
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS147(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = TRUE;
  inSysData->sparsePattern = allocSparsePattern(1, 1, 1);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
}

void freeSparsePatternNLS147(NONLINEAR_SYSTEM_DATA* inSysData)
{
  if (inSysData->isPatternAvailable) {
    freeSparsePattern(inSysData->sparsePattern);
    free(inSysData->sparsePattern);
    inSysData->sparsePattern = NULL;
    inSysData->isPatternAvailable = FALSE;
  }
}
OMC_DISABLE_OPT
void initializeNonlinearPatternNLS147(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  inSysData->nonlinearPattern = (NONLINEAR_PATTERN*) malloc(sizeof(NONLINEAR_PATTERN));
  inSysData->nonlinearPattern->numberOfVars = 1;
  inSysData->nonlinearPattern->numberOfEqns = 1;
  inSysData->nonlinearPattern->numberOfNonlinear = 1;
  inSysData->nonlinearPattern->indexVar = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->indexEqn = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->columns = (unsigned int*) malloc(1*sizeof(unsigned int));
  inSysData->nonlinearPattern->rows = (unsigned int*) malloc(1*sizeof(unsigned int));
  /* initialize and accumulate index vectors */
  const int index_var[1+1] = {0,1};
  const int index_eqn[1+1] = {0,1};
  memcpy(inSysData->nonlinearPattern->indexVar, index_var, (1+1)*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->indexEqn, index_eqn, (1+1)*sizeof(unsigned int));
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexVar[i] += inSysData->nonlinearPattern->indexVar[i-1];
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexEqn[i] += inSysData->nonlinearPattern->indexEqn[i-1];
  /* initialize columns and rows */
  const int columns[1] = {0};
  const int rows[1] = {0};
  memcpy(inSysData->nonlinearPattern->columns, columns, 1*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->rows, rows, 1*sizeof(unsigned int));
}

OMC_DISABLE_OPT
void initializeStaticDataNLS147(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for ho_2 */
  sysData->nominal[i] = getNominalFromScalarIdx(data->simulationInfo, data->modelData, VAR_KIND_VARIABLE, 60 /* ho_2 */);
  sysData->min[i]     = getMinFromScalarIdx(data->simulationInfo, data->modelData, VAR_TYPE_REAL, VAR_KIND_VARIABLE, 60 /* ho_2 */);
  sysData->max[i++]   = getMaxFromScalarIdx(data->simulationInfo, data->modelData, VAR_TYPE_REAL, VAR_KIND_VARIABLE, 60 /* ho_2 */);
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS147(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS147(sysData);
  }
}

OMC_DISABLE_OPT
void freeStaticDataNLS147(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData)
{
  freeSparsePatternNLS147(sysData);
}

OMC_DISABLE_OPT
void getIterationVarsNLS147(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* ho_2 variable */);
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize non-linear systems */
void TwoStandMill_initialNonLinearSystem(int nNonLinearSystems, NONLINEAR_SYSTEM_DATA* nonLinearSystemData)
{
  
  nonLinearSystemData[3].equationIndex = 147;
  nonLinearSystemData[3].size = 1;
  nonLinearSystemData[3].homotopySupport = 0 /* false */;
  nonLinearSystemData[3].mixedSystem = 0 /* false */;
  nonLinearSystemData[3].residualFunc = residualFunc147;
  nonLinearSystemData[3].strictTearingFunctionCall = NULL;
  nonLinearSystemData[3].analyticalJacobianColumn = TwoStandMill_functionJacNLSJac3_column;
  nonLinearSystemData[3].initialAnalyticalJacobian = TwoStandMill_initialAnalyticJacobianNLSJac3;
  nonLinearSystemData[3].jacobianIndex = 3 /*jacInx*/;
  nonLinearSystemData[3].initializeStaticNLSData = initializeStaticDataNLS147;
  nonLinearSystemData[3].freeStaticNLSData = freeStaticDataNLS147;
  nonLinearSystemData[3].getIterationVars = getIterationVarsNLS147;
  nonLinearSystemData[3].checkConstraints = NULL;
  
  const int tmp_eqn_indices_3[7] = {133, 134, 135, 136, 137, 138, 139};
  nonLinearSystemData[3].eqn_simcode_indices = malloc(7 * sizeof(int));
  memcpy(nonLinearSystemData[3].eqn_simcode_indices, tmp_eqn_indices_3, 7 * sizeof(int));
  nonLinearSystemData[3].torn_plus_residual_size = 7;
  
  
  nonLinearSystemData[2].equationIndex = 127;
  nonLinearSystemData[2].size = 1;
  nonLinearSystemData[2].homotopySupport = 0 /* false */;
  nonLinearSystemData[2].mixedSystem = 0 /* false */;
  nonLinearSystemData[2].residualFunc = residualFunc127;
  nonLinearSystemData[2].strictTearingFunctionCall = NULL;
  nonLinearSystemData[2].analyticalJacobianColumn = TwoStandMill_functionJacNLSJac2_column;
  nonLinearSystemData[2].initialAnalyticalJacobian = TwoStandMill_initialAnalyticJacobianNLSJac2;
  nonLinearSystemData[2].jacobianIndex = 2 /*jacInx*/;
  nonLinearSystemData[2].initializeStaticNLSData = initializeStaticDataNLS127;
  nonLinearSystemData[2].freeStaticNLSData = freeStaticDataNLS127;
  nonLinearSystemData[2].getIterationVars = getIterationVarsNLS127;
  nonLinearSystemData[2].checkConstraints = NULL;
  
  const int tmp_eqn_indices_2[7] = {113, 114, 115, 116, 117, 118, 119};
  nonLinearSystemData[2].eqn_simcode_indices = malloc(7 * sizeof(int));
  memcpy(nonLinearSystemData[2].eqn_simcode_indices, tmp_eqn_indices_2, 7 * sizeof(int));
  nonLinearSystemData[2].torn_plus_residual_size = 7;
  
  
  nonLinearSystemData[1].equationIndex = 41;
  nonLinearSystemData[1].size = 1;
  nonLinearSystemData[1].homotopySupport = 0 /* false */;
  nonLinearSystemData[1].mixedSystem = 0 /* false */;
  nonLinearSystemData[1].residualFunc = residualFunc41;
  nonLinearSystemData[1].strictTearingFunctionCall = NULL;
  nonLinearSystemData[1].analyticalJacobianColumn = TwoStandMill_functionJacNLSJac1_column;
  nonLinearSystemData[1].initialAnalyticalJacobian = TwoStandMill_initialAnalyticJacobianNLSJac1;
  nonLinearSystemData[1].jacobianIndex = 1 /*jacInx*/;
  nonLinearSystemData[1].initializeStaticNLSData = initializeStaticDataNLS41;
  nonLinearSystemData[1].freeStaticNLSData = freeStaticDataNLS41;
  nonLinearSystemData[1].getIterationVars = getIterationVarsNLS41;
  nonLinearSystemData[1].checkConstraints = NULL;
  
  const int tmp_eqn_indices_1[6] = {27, 28, 29, 30, 31, 32};
  nonLinearSystemData[1].eqn_simcode_indices = malloc(6 * sizeof(int));
  memcpy(nonLinearSystemData[1].eqn_simcode_indices, tmp_eqn_indices_1, 6 * sizeof(int));
  nonLinearSystemData[1].torn_plus_residual_size = 6;
  
  
  nonLinearSystemData[0].equationIndex = 25;
  nonLinearSystemData[0].size = 1;
  nonLinearSystemData[0].homotopySupport = 0 /* false */;
  nonLinearSystemData[0].mixedSystem = 0 /* false */;
  nonLinearSystemData[0].residualFunc = residualFunc25;
  nonLinearSystemData[0].strictTearingFunctionCall = NULL;
  nonLinearSystemData[0].analyticalJacobianColumn = TwoStandMill_functionJacNLSJac0_column;
  nonLinearSystemData[0].initialAnalyticalJacobian = TwoStandMill_initialAnalyticJacobianNLSJac0;
  nonLinearSystemData[0].jacobianIndex = 0 /*jacInx*/;
  nonLinearSystemData[0].initializeStaticNLSData = initializeStaticDataNLS25;
  nonLinearSystemData[0].freeStaticNLSData = freeStaticDataNLS25;
  nonLinearSystemData[0].getIterationVars = getIterationVarsNLS25;
  nonLinearSystemData[0].checkConstraints = NULL;
  
  const int tmp_eqn_indices_0[6] = {11, 12, 13, 14, 15, 16};
  nonLinearSystemData[0].eqn_simcode_indices = malloc(6 * sizeof(int));
  memcpy(nonLinearSystemData[0].eqn_simcode_indices, tmp_eqn_indices_0, 6 * sizeof(int));
  nonLinearSystemData[0].torn_plus_residual_size = 6;
}

#if defined(__cplusplus)
}
#endif
