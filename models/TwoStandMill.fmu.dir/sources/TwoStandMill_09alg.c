/* Algebraic */
#include "TwoStandMill_model.h"

#ifdef __cplusplus
extern "C" {
#endif

/* forwarded equations */
extern void TwoStandMill_eqFunction_88(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_95(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_102(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_104(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_105(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_106(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_107(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_108(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_109(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_110(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  static void (*const eqFunctions[10])(DATA*, threadData_t*) = {
    TwoStandMill_eqFunction_88,
    TwoStandMill_eqFunction_95,
    TwoStandMill_eqFunction_102,
    TwoStandMill_eqFunction_104,
    TwoStandMill_eqFunction_105,
    TwoStandMill_eqFunction_106,
    TwoStandMill_eqFunction_107,
    TwoStandMill_eqFunction_108,
    TwoStandMill_eqFunction_109,
    TwoStandMill_eqFunction_110
  };
  
  if (data->simulationInfo->evalSelection) {
    for (int i = 0; i < data->simulationInfo->evalSelection->n; i++) {
      int id = data->simulationInfo->evalSelection->idx[i];
      eqFunctions[id](data, threadData);
    }
  } else {
    for (int id = 0; id < 10; id++) {
      eqFunctions[id](data, threadData);
    }
  }
}
/* for continuous time variables */
int TwoStandMill_functionAlgebraics(DATA *data, threadData_t *threadData)
{

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ALGEBRAICS);
#endif
  data->simulationInfo->callStatistics.functionAlgebraics++;

  TwoStandMill_function_savePreSynchronous(data, threadData);
  
  functionAlg_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ALGEBRAICS);
#endif

  return 0;
}

#ifdef __cplusplus
}
#endif
