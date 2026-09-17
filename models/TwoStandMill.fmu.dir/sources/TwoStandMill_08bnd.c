/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "TwoStandMill_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 153
type: SIMPLE_ASSIGN
$START.h_out_2_f = h_in0
*/
static void TwoStandMill_eqFunction_153(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,153};
  ((modelica_real *)((data->modelData->realVarsData[5] /* h_out_2_f STATE(1) */).attribute .start.data))[0] = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[20]] /* h_in0 PARAM */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* h_out_2_f STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[5] /* h_out_2_f STATE(1) */).attribute .start.data))[0];
  infoStreamPrint(OMC_LOG_INIT_V, 0,
                  "updated start value: %s(start=%g)",
                  data->modelData->realVarsData[5] /* h_out_2_f */ .info.name,
                  (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* h_out_2_f STATE(1) */));
  threadData->lastEquationSolved = 153;
}

/*
equation index: 154
type: SIMPLE_ASSIGN
$START.h_out_1_f = h_in0
*/
static void TwoStandMill_eqFunction_154(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,154};
  ((modelica_real *)((data->modelData->realVarsData[4] /* h_out_1_f STATE(1) */).attribute .start.data))[0] = (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[20]] /* h_in0 PARAM */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* h_out_1_f STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[4] /* h_out_1_f STATE(1) */).attribute .start.data))[0];
  infoStreamPrint(OMC_LOG_INIT_V, 0,
                  "updated start value: %s(start=%g)",
                  data->modelData->realVarsData[4] /* h_out_1_f */ .info.name,
                  (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* h_out_1_f STATE(1) */));
  threadData->lastEquationSolved = 154;
}
OMC_DISABLE_OPT
int TwoStandMill_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  /* min ******************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating min-values");
  messageClose(OMC_LOG_INIT);
  
  /* max ******************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating max-values");
  messageClose(OMC_LOG_INIT);
  
  /* nominal **************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating nominal-values");
  messageClose(OMC_LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating primary start-values");
  TwoStandMill_eqFunction_153(data, threadData);
  TwoStandMill_eqFunction_154(data, threadData);
  messageClose(OMC_LOG_INIT);
  
  return 0;
}

void TwoStandMill_updateBoundParameters_0(DATA *data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_9(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_8(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_7(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_6(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_5(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_4(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_3(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_2(DATA *data, threadData_t *threadData);

extern void TwoStandMill_eqFunction_1(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void TwoStandMill_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  static void (*const eqFunctions[9])(DATA*, threadData_t*) = {
    TwoStandMill_eqFunction_9,
    TwoStandMill_eqFunction_8,
    TwoStandMill_eqFunction_7,
    TwoStandMill_eqFunction_6,
    TwoStandMill_eqFunction_5,
    TwoStandMill_eqFunction_4,
    TwoStandMill_eqFunction_3,
    TwoStandMill_eqFunction_2,
    TwoStandMill_eqFunction_1
  };
  
  for (int id = 0; id < 9; id++) {
    eqFunctions[id](data, threadData);
  }
}
OMC_DISABLE_OPT
int TwoStandMill_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TwoStandMill_updateBoundParameters_0(data, threadData);
  return 0;
}

#if defined(__cplusplus)
}
#endif
