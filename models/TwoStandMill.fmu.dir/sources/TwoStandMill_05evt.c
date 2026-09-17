/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "TwoStandMill_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void TwoStandMill_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *TwoStandMill_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"int_sp_1 <= (-I_max_sp) and e_1 < 0.0 or int_sp_1 >= I_max_sp and e_1 > 0.0",
  "abs(M_cmd_1) >= M_max",
  "int_sp_2 <= (-I_max_sp) and e_2 < 0.0 or int_sp_2 >= I_max_sp and e_2 > 0.0",
  "abs(M_cmd_2) >= M_max",
  "omega_1 <= wmin_1 and a_1 < 0.0 or omega_1 >= wmax_1 and a_1 > 0.0",
  "omega_2 <= wmin_2 and a_2 < 0.0 or omega_2 >= wmax_2 and a_2 > 0.0",
  "sigma_int >= 0.999 * sigma_max",
  "sigma_int <= 0.0",
  "diag_tension_low and k_sig * (v_2 - v_1) < 0.0 or sigma_int >= sigma_max and k_sig * (v_2 - v_1) > 0.0"};
  static const int occurEqs0[] = {1,98};
  static const int occurEqs1[] = {1,102};
  static const int occurEqs2[] = {1,91};
  static const int occurEqs3[] = {1,95};
  static const int occurEqs4[] = {1,132};
  static const int occurEqs5[] = {1,151};
  static const int occurEqs6[] = {1,88};
  static const int occurEqs7[] = {1,87};
  static const int occurEqs8[] = {1,103};
  static const int *occurEqs[] = {occurEqs0,occurEqs1,occurEqs2,occurEqs3,occurEqs4,occurEqs5,occurEqs6,occurEqs7,occurEqs8};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */
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
extern void TwoStandMill_eqFunction_130(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_131(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_132(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_147(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_149(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_150(DATA* data, threadData_t *threadData);
extern void TwoStandMill_eqFunction_151(DATA* data, threadData_t *threadData);

int TwoStandMill_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  static void (*const eqFunctions[24])(DATA*, threadData_t*) = {
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
    TwoStandMill_eqFunction_130,
    TwoStandMill_eqFunction_131,
    TwoStandMill_eqFunction_132,
    TwoStandMill_eqFunction_147,
    TwoStandMill_eqFunction_149,
    TwoStandMill_eqFunction_150,
    TwoStandMill_eqFunction_151
  };
  
  for (int id = 0; id < 24; id++) {
    eqFunctions[id](data, threadData);
  }
  
  return 0;
}

int TwoStandMill_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  const int *equationIndexes = NULL;

  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
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
  modelica_boolean tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
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
  modelica_boolean tmp33;
  modelica_real tmp34;
  modelica_real tmp35;
  modelica_boolean tmp36;
  modelica_real tmp37;
  modelica_real tmp38;
  modelica_boolean tmp39;
  modelica_real tmp40;
  modelica_real tmp41;
  modelica_boolean tmp42;
  modelica_real tmp43;
  modelica_real tmp44;
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
  modelica_integer current_index = 0;
  modelica_integer start_index;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ZC);
#endif
  data->simulationInfo->callStatistics.functionZeroCrossings++;

  start_index = current_index;
  tmp1 = 1.0;
  tmp2 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */));
  tmp0 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* int_sp_1 STATE(1) */), (-(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */)), tmp1, tmp2, data->simulationInfo->storedRelations[0]);
  tmp4 = 1.0;
  tmp5 = 0.0;
  tmp3 = LessZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* e_1 variable */), 0.0, tmp4, tmp5, data->simulationInfo->storedRelations[1]);
  tmp7 = 1.0;
  tmp8 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */));
  tmp6 = GreaterEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* int_sp_1 STATE(1) */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */), tmp7, tmp8, data->simulationInfo->storedRelations[2]);
  tmp10 = 1.0;
  tmp11 = 0.0;
  tmp9 = GreaterZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* e_1 variable */), 0.0, tmp10, tmp11, data->simulationInfo->storedRelations[3]);
  gout[start_index] = (((tmp0 && tmp3) || (tmp6 && tmp9))) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp13 = 1.0;
  tmp14 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */));
  tmp12 = GreaterEqZC(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* M_cmd_1 variable */)), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */), tmp13, tmp14, data->simulationInfo->storedRelations[4]);
  gout[start_index] = (tmp12) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp16 = 1.0;
  tmp17 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */));
  tmp15 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* int_sp_2 STATE(1) */), (-(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */)), tmp16, tmp17, data->simulationInfo->storedRelations[5]);
  tmp19 = 1.0;
  tmp20 = 0.0;
  tmp18 = LessZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* e_2 variable */), 0.0, tmp19, tmp20, data->simulationInfo->storedRelations[6]);
  tmp22 = 1.0;
  tmp23 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */));
  tmp21 = GreaterEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* int_sp_2 STATE(1) */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */), tmp22, tmp23, data->simulationInfo->storedRelations[7]);
  tmp25 = 1.0;
  tmp26 = 0.0;
  tmp24 = GreaterZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* e_2 variable */), 0.0, tmp25, tmp26, data->simulationInfo->storedRelations[8]);
  gout[start_index] = (((tmp15 && tmp18) || (tmp21 && tmp24))) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp28 = 1.0;
  tmp29 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */));
  tmp27 = GreaterEqZC(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* M_cmd_2 variable */)), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */), tmp28, tmp29, data->simulationInfo->storedRelations[9]);
  gout[start_index] = (tmp27) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp31 = 1.0;
  tmp32 = 1.0;
  tmp30 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* omega_1 STATE(1) */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[73]] /* wmin_1 variable */), tmp31, tmp32, data->simulationInfo->storedRelations[10]);
  tmp34 = 1.0;
  tmp35 = 0.0;
  tmp33 = LessZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* a_1 variable */), 0.0, tmp34, tmp35, data->simulationInfo->storedRelations[11]);
  tmp37 = 1.0;
  tmp38 = 1.0;
  tmp36 = GreaterEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* omega_1 STATE(1) */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[71]] /* wmax_1 variable */), tmp37, tmp38, data->simulationInfo->storedRelations[12]);
  tmp40 = 1.0;
  tmp41 = 0.0;
  tmp39 = GreaterZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* a_1 variable */), 0.0, tmp40, tmp41, data->simulationInfo->storedRelations[13]);
  gout[start_index] = (((tmp30 && tmp33) || (tmp36 && tmp39))) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp43 = 1.0;
  tmp44 = 1.0;
  tmp42 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* omega_2 STATE(1) */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* wmin_2 variable */), tmp43, tmp44, data->simulationInfo->storedRelations[14]);
  tmp46 = 1.0;
  tmp47 = 0.0;
  tmp45 = LessZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* a_2 variable */), 0.0, tmp46, tmp47, data->simulationInfo->storedRelations[15]);
  tmp49 = 1.0;
  tmp50 = 1.0;
  tmp48 = GreaterEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* omega_2 STATE(1) */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[72]] /* wmax_2 variable */), tmp49, tmp50, data->simulationInfo->storedRelations[16]);
  tmp52 = 1.0;
  tmp53 = 0.0;
  tmp51 = GreaterZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* a_2 variable */), 0.0, tmp52, tmp53, data->simulationInfo->storedRelations[17]);
  gout[start_index] = (((tmp42 && tmp45) || (tmp48 && tmp51))) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp55 = 1.0;
  tmp56 = (0.999) * (fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* sigma_max PARAM */)));
  tmp54 = GreaterEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* sigma_int STATE(1) */), (0.999) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* sigma_max PARAM */)), tmp55, tmp56, data->simulationInfo->storedRelations[18]);
  gout[start_index] = (tmp54) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp58 = 1.0;
  tmp59 = 0.0;
  tmp57 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* sigma_int STATE(1) */), 0.0, tmp58, tmp59, data->simulationInfo->storedRelations[19]);
  gout[start_index] = (tmp57) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp61 = 2.0;
  tmp62 = 0.0;
  tmp60 = LessZC(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* k_sig variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* v_2 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* v_1 variable */)), 0.0, tmp61, tmp62, data->simulationInfo->storedRelations[20]);
  tmp64 = 1.0;
  tmp65 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* sigma_max PARAM */));
  tmp63 = GreaterEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* sigma_int STATE(1) */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* sigma_max PARAM */), tmp64, tmp65, data->simulationInfo->storedRelations[21]);
  tmp67 = 2.0;
  tmp68 = 0.0;
  tmp66 = GreaterZC(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* k_sig variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* v_2 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* v_1 variable */)), 0.0, tmp67, tmp68, data->simulationInfo->storedRelations[22]);
  gout[start_index] = ((((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[2]] /* diag_tension_low DISCRETE */) && tmp60) || (tmp63 && tmp66))) ? 1 : -1;
  current_index++;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ZC);
#endif

  return 0;
}

const char *TwoStandMill_relationDescription(int i)
{
  const char *res[] = {"int_sp_1 <= (-I_max_sp)",
  "e_1 < 0.0",
  "int_sp_1 >= I_max_sp",
  "e_1 > 0.0",
  "abs(M_cmd_1) >= M_max",
  "int_sp_2 <= (-I_max_sp)",
  "e_2 < 0.0",
  "int_sp_2 >= I_max_sp",
  "e_2 > 0.0",
  "abs(M_cmd_2) >= M_max",
  "omega_1 <= wmin_1",
  "a_1 < 0.0",
  "omega_1 >= wmax_1",
  "a_1 > 0.0",
  "omega_2 <= wmin_2",
  "a_2 < 0.0",
  "omega_2 >= wmax_2",
  "a_2 > 0.0",
  "sigma_int >= 0.999 * sigma_max",
  "sigma_int <= 0.0",
  "k_sig * (v_2 - v_1) < 0.0",
  "sigma_int >= sigma_max",
  "k_sig * (v_2 - v_1) > 0.0"};
  return res[i];
}

int TwoStandMill_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  const int *equationIndexes = NULL;

  modelica_boolean tmp69;
  modelica_real tmp70;
  modelica_real tmp71;
  modelica_boolean tmp72;
  modelica_real tmp73;
  modelica_real tmp74;
  modelica_boolean tmp75;
  modelica_real tmp76;
  modelica_real tmp77;
  modelica_boolean tmp78;
  modelica_real tmp79;
  modelica_real tmp80;
  modelica_boolean tmp81;
  modelica_real tmp82;
  modelica_real tmp83;
  modelica_boolean tmp84;
  modelica_real tmp85;
  modelica_real tmp86;
  modelica_boolean tmp87;
  modelica_real tmp88;
  modelica_real tmp89;
  modelica_boolean tmp90;
  modelica_real tmp91;
  modelica_real tmp92;
  modelica_boolean tmp93;
  modelica_real tmp94;
  modelica_real tmp95;
  modelica_boolean tmp96;
  modelica_real tmp97;
  modelica_real tmp98;
  modelica_boolean tmp99;
  modelica_real tmp100;
  modelica_real tmp101;
  modelica_boolean tmp102;
  modelica_real tmp103;
  modelica_real tmp104;
  modelica_boolean tmp105;
  modelica_real tmp106;
  modelica_real tmp107;
  modelica_boolean tmp108;
  modelica_real tmp109;
  modelica_real tmp110;
  modelica_boolean tmp111;
  modelica_real tmp112;
  modelica_real tmp113;
  modelica_boolean tmp114;
  modelica_real tmp115;
  modelica_real tmp116;
  modelica_boolean tmp117;
  modelica_real tmp118;
  modelica_real tmp119;
  modelica_boolean tmp120;
  modelica_real tmp121;
  modelica_real tmp122;
  modelica_boolean tmp123;
  modelica_real tmp124;
  modelica_real tmp125;
  modelica_boolean tmp126;
  modelica_real tmp127;
  modelica_real tmp128;
  modelica_boolean tmp129;
  modelica_real tmp130;
  modelica_real tmp131;
  modelica_boolean tmp132;
  modelica_real tmp133;
  modelica_real tmp134;
  modelica_boolean tmp135;
  modelica_real tmp136;
  modelica_real tmp137;
  modelica_integer current_index = 0;
  modelica_integer start_index;
  
  if(evalforZeroCross) {
    start_index = current_index;
    tmp70 = 1.0;
    tmp71 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */));
    tmp69 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* int_sp_1 STATE(1) */), (-(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */)), tmp70, tmp71, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[start_index] = tmp69;
    current_index++;

    start_index = current_index;
    tmp73 = 1.0;
    tmp74 = 0.0;
    tmp72 = LessZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* e_1 variable */), 0.0, tmp73, tmp74, data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[start_index] = tmp72;
    current_index++;

    start_index = current_index;
    tmp76 = 1.0;
    tmp77 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */));
    tmp75 = GreaterEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* int_sp_1 STATE(1) */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */), tmp76, tmp77, data->simulationInfo->storedRelations[2]);
    data->simulationInfo->relations[start_index] = tmp75;
    current_index++;

    start_index = current_index;
    tmp79 = 1.0;
    tmp80 = 0.0;
    tmp78 = GreaterZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* e_1 variable */), 0.0, tmp79, tmp80, data->simulationInfo->storedRelations[3]);
    data->simulationInfo->relations[start_index] = tmp78;
    current_index++;

    start_index = current_index;
    tmp82 = 1.0;
    tmp83 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */));
    tmp81 = GreaterEqZC(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* M_cmd_1 variable */)), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */), tmp82, tmp83, data->simulationInfo->storedRelations[4]);
    data->simulationInfo->relations[start_index] = tmp81;
    current_index++;

    start_index = current_index;
    tmp85 = 1.0;
    tmp86 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */));
    tmp84 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* int_sp_2 STATE(1) */), (-(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */)), tmp85, tmp86, data->simulationInfo->storedRelations[5]);
    data->simulationInfo->relations[start_index] = tmp84;
    current_index++;

    start_index = current_index;
    tmp88 = 1.0;
    tmp89 = 0.0;
    tmp87 = LessZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* e_2 variable */), 0.0, tmp88, tmp89, data->simulationInfo->storedRelations[6]);
    data->simulationInfo->relations[start_index] = tmp87;
    current_index++;

    start_index = current_index;
    tmp91 = 1.0;
    tmp92 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */));
    tmp90 = GreaterEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* int_sp_2 STATE(1) */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */), tmp91, tmp92, data->simulationInfo->storedRelations[7]);
    data->simulationInfo->relations[start_index] = tmp90;
    current_index++;

    start_index = current_index;
    tmp94 = 1.0;
    tmp95 = 0.0;
    tmp93 = GreaterZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* e_2 variable */), 0.0, tmp94, tmp95, data->simulationInfo->storedRelations[8]);
    data->simulationInfo->relations[start_index] = tmp93;
    current_index++;

    start_index = current_index;
    tmp97 = 1.0;
    tmp98 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */));
    tmp96 = GreaterEqZC(fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* M_cmd_2 variable */)), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */), tmp97, tmp98, data->simulationInfo->storedRelations[9]);
    data->simulationInfo->relations[start_index] = tmp96;
    current_index++;

    start_index = current_index;
    tmp100 = 1.0;
    tmp101 = 1.0;
    tmp99 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* omega_1 STATE(1) */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[73]] /* wmin_1 variable */), tmp100, tmp101, data->simulationInfo->storedRelations[10]);
    data->simulationInfo->relations[start_index] = tmp99;
    current_index++;

    start_index = current_index;
    tmp103 = 1.0;
    tmp104 = 0.0;
    tmp102 = LessZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* a_1 variable */), 0.0, tmp103, tmp104, data->simulationInfo->storedRelations[11]);
    data->simulationInfo->relations[start_index] = tmp102;
    current_index++;

    start_index = current_index;
    tmp106 = 1.0;
    tmp107 = 1.0;
    tmp105 = GreaterEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* omega_1 STATE(1) */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[71]] /* wmax_1 variable */), tmp106, tmp107, data->simulationInfo->storedRelations[12]);
    data->simulationInfo->relations[start_index] = tmp105;
    current_index++;

    start_index = current_index;
    tmp109 = 1.0;
    tmp110 = 0.0;
    tmp108 = GreaterZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* a_1 variable */), 0.0, tmp109, tmp110, data->simulationInfo->storedRelations[13]);
    data->simulationInfo->relations[start_index] = tmp108;
    current_index++;

    start_index = current_index;
    tmp112 = 1.0;
    tmp113 = 1.0;
    tmp111 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* omega_2 STATE(1) */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* wmin_2 variable */), tmp112, tmp113, data->simulationInfo->storedRelations[14]);
    data->simulationInfo->relations[start_index] = tmp111;
    current_index++;

    start_index = current_index;
    tmp115 = 1.0;
    tmp116 = 0.0;
    tmp114 = LessZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* a_2 variable */), 0.0, tmp115, tmp116, data->simulationInfo->storedRelations[15]);
    data->simulationInfo->relations[start_index] = tmp114;
    current_index++;

    start_index = current_index;
    tmp118 = 1.0;
    tmp119 = 1.0;
    tmp117 = GreaterEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* omega_2 STATE(1) */), (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[72]] /* wmax_2 variable */), tmp118, tmp119, data->simulationInfo->storedRelations[16]);
    data->simulationInfo->relations[start_index] = tmp117;
    current_index++;

    start_index = current_index;
    tmp121 = 1.0;
    tmp122 = 0.0;
    tmp120 = GreaterZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* a_2 variable */), 0.0, tmp121, tmp122, data->simulationInfo->storedRelations[17]);
    data->simulationInfo->relations[start_index] = tmp120;
    current_index++;

    start_index = current_index;
    tmp124 = 1.0;
    tmp125 = (0.999) * (fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* sigma_max PARAM */)));
    tmp123 = GreaterEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* sigma_int STATE(1) */), (0.999) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* sigma_max PARAM */)), tmp124, tmp125, data->simulationInfo->storedRelations[18]);
    data->simulationInfo->relations[start_index] = tmp123;
    current_index++;

    start_index = current_index;
    tmp127 = 1.0;
    tmp128 = 0.0;
    tmp126 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* sigma_int STATE(1) */), 0.0, tmp127, tmp128, data->simulationInfo->storedRelations[19]);
    data->simulationInfo->relations[start_index] = tmp126;
    current_index++;

    start_index = current_index;
    tmp130 = 2.0;
    tmp131 = 0.0;
    tmp129 = LessZC(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* k_sig variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* v_2 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* v_1 variable */)), 0.0, tmp130, tmp131, data->simulationInfo->storedRelations[20]);
    data->simulationInfo->relations[start_index] = tmp129;
    current_index++;

    start_index = current_index;
    tmp133 = 1.0;
    tmp134 = fabs((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* sigma_max PARAM */));
    tmp132 = GreaterEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* sigma_int STATE(1) */), (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* sigma_max PARAM */), tmp133, tmp134, data->simulationInfo->storedRelations[21]);
    data->simulationInfo->relations[start_index] = tmp132;
    current_index++;

    start_index = current_index;
    tmp136 = 2.0;
    tmp137 = 0.0;
    tmp135 = GreaterZC(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* k_sig variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* v_2 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* v_1 variable */)), 0.0, tmp136, tmp137, data->simulationInfo->storedRelations[22]);
    data->simulationInfo->relations[start_index] = tmp135;
    current_index++;
  } else {
    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* int_sp_1 STATE(1) */) <= (-(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */)));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* e_1 variable */) < 0.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* int_sp_1 STATE(1) */) >= (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* e_1 variable */) > 0.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = (fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* M_cmd_1 variable */)) >= (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* int_sp_2 STATE(1) */) <= (-(data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */)));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* e_2 variable */) < 0.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* int_sp_2 STATE(1) */) >= (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[1]] /* I_max_sp PARAM */));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* e_2 variable */) > 0.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = (fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* M_cmd_2 variable */)) >= (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[9]] /* M_max PARAM */));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* omega_1 STATE(1) */) <= (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[73]] /* wmin_1 variable */));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* a_1 variable */) < 0.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* omega_1 STATE(1) */) >= (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[71]] /* wmax_1 variable */));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* a_1 variable */) > 0.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* omega_2 STATE(1) */) <= (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* wmin_2 variable */));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* a_2 variable */) < 0.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* omega_2 STATE(1) */) >= (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[72]] /* wmax_2 variable */));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* a_2 variable */) > 0.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* sigma_int STATE(1) */) >= (0.999) * ((data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* sigma_max PARAM */)));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* sigma_int STATE(1) */) <= 0.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* k_sig variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* v_2 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* v_1 variable */)) < 0.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* sigma_int STATE(1) */) >= (data->simulationInfo->realParameter[data->simulationInfo->realParamsIndex[22]] /* sigma_max PARAM */));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* k_sig variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* v_2 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* v_1 variable */)) > 0.0);
    current_index++;
  }
  
  return 0;
}

#if defined(__cplusplus)
}
#endif
