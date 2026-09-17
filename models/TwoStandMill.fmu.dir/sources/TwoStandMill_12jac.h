/* Jacobians */
static _index_t one_dim[1] = { 1 };
static modelica_real nominal_data[1] = { 1.0 };
static modelica_real start_data[1]   = { 0.0 };
static modelica_real min_data[1]   = { -DBL_MAX };
static modelica_real max_data[1]   = { DBL_MAX };
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = {
  .unit = NULL,
  .displayUnit = NULL,
  .min = {
    .ndims     = 1,
    .dim_size  = one_dim,
    .data      = (void*) min_data,
    .flexible  = FALSE
  },
  .max = {
    .ndims     = 1,
    .dim_size  = one_dim,
    .data      = (void*) max_data,
    .flexible  = FALSE
  },
  .fixed = FALSE,
  .useNominal = FALSE,
  .nominal = {
    .ndims     = 1,
    .dim_size  = one_dim,
    .data      = (void*) nominal_data,
    .flexible  = FALSE
  },
  .start = {
    .ndims     = 1,
    .dim_size  = one_dim,
    .data      = (void*) start_data,
    .flexible  = FALSE
  }
};

#if defined(__cplusplus)
extern "C" {
#endif

/* Jacobian Variables */
#define TwoStandMill_INDEX_JAC_NLSJac0 0
int TwoStandMill_functionJacNLSJac0_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int TwoStandMill_initialAnalyticJacobianNLSJac0(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);
void TwoStandMill_JacNLSJac0_DAG(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define TwoStandMill_INDEX_JAC_NLSJac1 1
int TwoStandMill_functionJacNLSJac1_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int TwoStandMill_initialAnalyticJacobianNLSJac1(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);
void TwoStandMill_JacNLSJac1_DAG(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define TwoStandMill_INDEX_JAC_NLSJac2 2
int TwoStandMill_functionJacNLSJac2_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int TwoStandMill_initialAnalyticJacobianNLSJac2(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);
void TwoStandMill_JacNLSJac2_DAG(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define TwoStandMill_INDEX_JAC_NLSJac3 3
int TwoStandMill_functionJacNLSJac3_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int TwoStandMill_initialAnalyticJacobianNLSJac3(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);
void TwoStandMill_JacNLSJac3_DAG(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define TwoStandMill_INDEX_JAC_ADJ 4
int TwoStandMill_functionJacADJ_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int TwoStandMill_initialAnalyticJacobianADJ(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);
void TwoStandMill_JacADJ_DAG(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define TwoStandMill_INDEX_JAC_H 5
int TwoStandMill_functionJacH_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int TwoStandMill_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);
void TwoStandMill_JacH_DAG(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define TwoStandMill_INDEX_JAC_F 6
int TwoStandMill_functionJacF_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int TwoStandMill_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);
void TwoStandMill_JacF_DAG(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define TwoStandMill_INDEX_JAC_D 7
int TwoStandMill_functionJacD_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int TwoStandMill_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);
void TwoStandMill_JacD_DAG(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define TwoStandMill_INDEX_JAC_C 8
int TwoStandMill_functionJacC_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int TwoStandMill_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);
void TwoStandMill_JacC_DAG(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define TwoStandMill_INDEX_JAC_B 9
int TwoStandMill_functionJacB_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int TwoStandMill_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);
void TwoStandMill_JacB_DAG(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);


#define TwoStandMill_INDEX_JAC_A 10
int TwoStandMill_functionJacA_column(DATA* data, threadData_t *threadData, JACOBIAN *thisJacobian, JACOBIAN *parentJacobian);
int TwoStandMill_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);
void TwoStandMill_JacA_DAG(DATA* data, threadData_t *threadData, JACOBIAN *jacobian);

#if defined(__cplusplus)
}
#endif
