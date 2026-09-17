/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "Tank_model.h"
#include "simulation/solver/events.h"
#include "simulation/arrayIndex.h"



/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int Tank_input_function(DATA *data, threadData_t *threadData)
{
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* u variable */) = data->simulationInfo->inputVars[0];
  
  return 0;
}

int Tank_input_function_init(DATA *data, threadData_t *threadData)
{
  data->simulationInfo->inputVars[0] = getStartFromScalarIdx(data->simulationInfo, data->modelData, VAR_TYPE_REAL, VAR_KIND_VARIABLE, 3);
  
  return 0;
}

int Tank_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData, data->modelData->realVarsData[3].dimension.numberOfDimensions == 0, "Handling of array variables not yet implemetned.");
  put_real_element(data->simulationInfo->inputVars[0], 0, &data->modelData->realVarsData[3].attribute.start);
  
  return 0;
}

int Tank_inputNames(DATA *data, char ** names){
  names[0] = (char *) data->modelData->realVarsData[3].info.name;
  
  return 0;
}

int Tank_data_function(DATA *data, threadData_t *threadData)
{
  return 0;
}

int Tank_dataReconciliationInputNames(DATA *data, char ** names){
  
  return 0;
}

int Tank_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  
  return 0;
}

int Tank_output_function(DATA *data, threadData_t *threadData)
{
  data->simulationInfo->outputVars[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* height variable */);
  
  return 0;
}

int Tank_setc_function(DATA *data, threadData_t *threadData)
{
  
  return 0;
}

int Tank_setb_function(DATA *data, threadData_t *threadData)
{
  
  return 0;
}


/*
equation index: 4
type: SIMPLE_ASSIGN
$DER.h = (u * Qin - (if h > 0.0 then Qout else 0.0)) / A
*/
void Tank_eqFunction_4(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,4};
  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp1 = 1.0;
  tmp2 = 0.0;
  relationhysteresis(data, &tmp0, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1) */), 0.0, tmp1, tmp2, 0, Greater, GreaterZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* der(h) STATE_DER */) = DIVISION_SIM(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* u variable */)) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* Qin PARAM */)) - ((tmp0?(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[2]] /* Qout PARAM */):0.0)),(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[0]] /* A PARAM */),"A",equationIndexes);
  threadData->lastEquationSolved = 4;
}

/*
equation index: 5
type: SIMPLE_ASSIGN
height = h
*/
void Tank_eqFunction_5(DATA *data, threadData_t *threadData)
{
  const int equationIndexes[2] = {1,5};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* height variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1) */);
  threadData->lastEquationSolved = 5;
}

OMC_DISABLE_OPT
int Tank_functionDAE(DATA *data, threadData_t *threadData)
{
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  Tank_functionLocalKnownVars(data, threadData);
  static void (*const eqFunctions[2])(DATA*, threadData_t*) = {
    Tank_eqFunction_4,
    Tank_eqFunction_5
  };
  
  for (int id = 0; id < 2; id++) {
    eqFunctions[id](data, threadData);
  }
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  return 0;
}


int Tank_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  
  return 0;
}

/* forwarded equations */
extern void Tank_eqFunction_4(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  static void (*const eqFunctions[1])(DATA*, threadData_t*) = {
    Tank_eqFunction_4
  };
  
  if (data->simulationInfo->evalSelection) {
    for (int i = 0; i < data->simulationInfo->evalSelection->n; i++) {
      int id = data->simulationInfo->evalSelection->idx[i];
      eqFunctions[id](data, threadData);
    }
  } else {
    for (int id = 0; id < 1; id++) {
      eqFunctions[id](data, threadData);
    }
  }
}

int Tank_functionODE(DATA *data, threadData_t *threadData)
{
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  Tank_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  return 0;
}

void Tank_ODE_DAG(DATA* data, threadData_t* threadData)
{
  const size_t eqMap[] = {4};
  buildEvalDAG_ODE(data->modelData, sizeof(eqMap)/sizeof(size_t), eqMap);
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char **argv, DATA *data, threadData_t *threadData);
extern int _main_OptimizationRuntime(int argc, char **argv, DATA *data, threadData_t *threadData);

#include "Tank_12jac.h"
#include "Tank_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks Tank_callback = {
  NULL,    /* performSimulation */
  NULL,    /* performQSSSimulation */
  NULL,    /* updateContinuousSystem */
  Tank_callExternalObjectDestructors,    /* callExternalObjectDestructors */
  NULL,    /* initialNonLinearSystem */
  NULL,    /* initialLinearSystem */
  NULL,    /* initialMixedSystem */
  #if !defined(OMC_NO_STATESELECTION)
  Tank_initializeStateSets,
  #else
  NULL,
  #endif    /* initializeStateSets */
  Tank_initializeDAEmodeData,
  Tank_ODE_DAG,
  Tank_functionODE,
  Tank_functionAlgebraics,
  Tank_functionDAE,
  Tank_functionLocalKnownVars,
  Tank_input_function,
  Tank_input_function_init,
  Tank_input_function_updateStartValues,
  Tank_data_function,
  Tank_output_function,
  Tank_setc_function,
  Tank_setb_function,
  Tank_function_storeDelayed,
  Tank_function_storeSpatialDistribution,
  Tank_function_initSpatialDistribution,
  Tank_updateBoundVariableAttributes,
  Tank_functionInitialEquations,
  GLOBAL_EQUIDISTANT_HOMOTOPY,
  NULL,
  Tank_functionRemovedInitialEquations,
  Tank_updateBoundParameters,
  Tank_checkForAsserts,
  Tank_function_ZeroCrossingsEquations,
  Tank_function_ZeroCrossings,
  Tank_function_updateRelations,
  Tank_zeroCrossingDescription,
  Tank_relationDescription,
  Tank_function_initSample,
  Tank_INDEX_JAC_A,
  Tank_INDEX_JAC_ADJ,
  Tank_INDEX_JAC_B,
  Tank_INDEX_JAC_C,
  Tank_INDEX_JAC_D,
  Tank_INDEX_JAC_F,
  Tank_INDEX_JAC_H,
  Tank_initialAnalyticJacobianA,
  Tank_initialAnalyticJacobianADJ,
  Tank_initialAnalyticJacobianB,
  Tank_initialAnalyticJacobianC,
  Tank_initialAnalyticJacobianD,
  Tank_initialAnalyticJacobianF,
  Tank_initialAnalyticJacobianH,
  Tank_functionJacA_column,
  Tank_functionJacADJ_column,
  Tank_functionJacB_column,
  Tank_functionJacC_column,
  Tank_functionJacD_column,
  Tank_functionJacF_column,
  Tank_functionJacH_column,
  Tank_JacA_DAG,
  Tank_linear_model_frame,
  Tank_linear_model_datarecovery_frame,
  Tank_mayer,
  Tank_lagrange,
  Tank_getInputVarIndicesInOptimization,
  Tank_pickUpBoundsForInputsInOptimization,
  Tank_setInputData,
  Tank_getTimeGrid,
  Tank_symbolicInlineSystem,
  Tank_function_initSynchronous,
  Tank_function_updateSynchronous,
  Tank_function_equationsSynchronous,
  Tank_inputNames,
  Tank_dataReconciliationInputNames,
  Tank_dataReconciliationUnmeasuredVariables,
  Tank_read_simulation_info,
  Tank_read_input_fmu,
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

#define _OMC_LIT_RESOURCE_3_name_data "Tank"
#define _OMC_LIT_RESOURCE_3_dir_data "."
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,4,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,42,_OMC_LIT_RESOURCE_3_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,8,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir)}};
void Tank_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &Tank_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "Tank";
  data->modelData->modelFilePrefix = "Tank";
  data->modelData->modelFileName = "tank.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = ".";
  data->modelData->modelGUID = "{ec9d72ef-f13b-40d5-84fa-1f6d0ff4aaee}";
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  GC_asprintf(&data->modelData->modelDataXml.fileName, "%s/Tank_info.json", data->modelData->resourcesDir);
  data->modelData->runTestsuite = 0;
  data->modelData->nStatesArray = 1;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesRealArray = 4;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 0;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersRealArray = 3;
  data->modelData->nParametersIntegerArray = 0;
  data->modelData->nParametersBooleanArray = 0;
  data->modelData->nParametersStringArray = 0;
  data->modelData->nParametersReal = 3;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nAliasRealArray = 1;
  data->modelData->nAliasIntegerArray = 0;
  data->modelData->nAliasBooleanArray = 0;
  data->modelData->nAliasStringArray = 0;
  data->modelData->nInputVars = 1;
  data->modelData->nOutputVars = 1;
  data->modelData->nZeroCrossings = 1;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 1;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 6;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 7;
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

