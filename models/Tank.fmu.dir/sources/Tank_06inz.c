/* Initialization */
#include "Tank_model.h"
#include "Tank_11mix.h"
#include "Tank_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void Tank_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
h = $START.h
*/
void Tank_eqFunction_1(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1) */) = ((modelica_real *)((data->modelData->realVarsData[0] /* h STATE(1) */).attribute .start.data))[0];
  threadData->lastEquationSolved = 1;
}
extern void Tank_eqFunction_5(DATA *data, threadData_t *threadData);

extern void Tank_eqFunction_4(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void Tank_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  static void (*const eqFunctions[3])(DATA*, threadData_t*) = {
    Tank_eqFunction_1,
    Tank_eqFunction_5,
    Tank_eqFunction_4
  };
  
  for (int id = 0; id < 3; id++) {
    eqFunctions[id](data, threadData);
  }
}

int Tank_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  data->simulationInfo->discreteCall = 1;
  Tank_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  return 0;
}

/* No Tank_functionInitialEquations_lambda0 function */

int Tank_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  return 0;
}


#if defined(__cplusplus)
}
#endif
