#include "TwoStandMill_FMU.h"

// include fmu header files, typedefs and macros
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "openmodelica.h"
#include "openmodelica_func.h"
#include "util/omc_error.h"
#include "TwoStandMill_functions.h"

#include "simulation/solver/events.h"

// Set values for all variables that define a start value
OMC_DISABLE_OPT
void setDefaultStartValues(ModelInstance *comp) {
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[0].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[1].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[2].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[3].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[4].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[5].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[6].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[7].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[8].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[9].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[10].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[11].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[12].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[13].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[14].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[15].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[16].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[17].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[18].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[19].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[20].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[21].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[22].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[23].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[24].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[25].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[26].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[27].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[28].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[29].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[30].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[31].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[32].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[33].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[34].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[35].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[36].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[37].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[38].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[39].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[40].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[41].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[42].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[43].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[44].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[45].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[46].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[47].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[48].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[49].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[50].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[51].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[52].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[53].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[54].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[55].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[56].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[57].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[58].attribute.start);
  put_real_element(2.3, 0, &comp->fmuData->modelData->realVarsData[59].attribute.start);
  put_real_element(1.5, 0, &comp->fmuData->modelData->realVarsData[60].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[61].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[62].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[63].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[64].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[65].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[66].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[67].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[68].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[69].attribute.start);
  put_real_element(0.0, 0, &comp->fmuData->modelData->realVarsData[70].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[71].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[72].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[73].attribute.start);
  put_real_element(0, 0, &comp->fmuData->modelData->realVarsData[74].attribute.start);
  comp->fmuData->modelData->booleanVarsData[0].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[1].attribute.start = 0;
  comp->fmuData->modelData->booleanVarsData[2].attribute.start = 1;
  comp->fmuData->modelData->booleanVarsData[3].attribute.start = 0;
  put_real_element(2.1e5, 0, &comp->fmuData->modelData->realParameterData[0].attribute.start);
  put_real_element(20.0, 0, &comp->fmuData->modelData->realParameterData[1].attribute.start);
  put_real_element(4.5, 0, &comp->fmuData->modelData->realParameterData[2].attribute.start);
  put_real_element(4.5, 0, &comp->fmuData->modelData->realParameterData[3].attribute.start);
  put_real_element(4500.0, 0, &comp->fmuData->modelData->realParameterData[4].attribute.start);
  put_real_element(4500.0, 0, &comp->fmuData->modelData->realParameterData[5].attribute.start);
  put_real_element(8.0, 0, &comp->fmuData->modelData->realParameterData[6].attribute.start);
  put_real_element(8.0, 0, &comp->fmuData->modelData->realParameterData[7].attribute.start);
  put_real_element(2500.0, 0, &comp->fmuData->modelData->realParameterData[8].attribute.start);
  put_real_element(18.0, 0, &comp->fmuData->modelData->realParameterData[9].attribute.start);
  put_real_element(125.0, 0, &comp->fmuData->modelData->realParameterData[10].attribute.start);
  put_real_element(125.0, 0, &comp->fmuData->modelData->realParameterData[11].attribute.start);
  put_real_element(0.015, 0, &comp->fmuData->modelData->realParameterData[12].attribute.start);
  put_real_element(0.015, 0, &comp->fmuData->modelData->realParameterData[13].attribute.start);
  put_real_element(0.008, 0, &comp->fmuData->modelData->realParameterData[14].attribute.start);
  put_real_element(0.005, 0, &comp->fmuData->modelData->realParameterData[15].attribute.start);
  put_real_element(0.12, 0, &comp->fmuData->modelData->realParameterData[16].attribute.start);
  put_real_element(0.12, 0, &comp->fmuData->modelData->realParameterData[17].attribute.start);
  put_real_element(0.48, 0, &comp->fmuData->modelData->realParameterData[18].attribute.start);
  put_real_element(0.001, 0, &comp->fmuData->modelData->realParameterData[19].attribute.start);
  put_real_element(3.0, 0, &comp->fmuData->modelData->realParameterData[20].attribute.start);
  put_real_element(0.3, 0, &comp->fmuData->modelData->realParameterData[21].attribute.start);
  put_real_element(350.0, 0, &comp->fmuData->modelData->realParameterData[22].attribute.start);
  put_real_element(15.0, 0, &comp->fmuData->modelData->realParameterData[23].attribute.start);
  put_real_element(-5.0, 0, &comp->fmuData->modelData->realParameterData[24].attribute.start);
}
// Set values for all variables that define a start value
OMC_DISABLE_OPT
void setStartValues(ModelInstance *comp) {
  put_real_element(comp->fmuData->localData[0]->realVars[0], 0, &comp->fmuData->modelData->realVarsData[0].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[1], 0, &comp->fmuData->modelData->realVarsData[1].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[2], 0, &comp->fmuData->modelData->realVarsData[2].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[3], 0, &comp->fmuData->modelData->realVarsData[3].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[4], 0, &comp->fmuData->modelData->realVarsData[4].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[5], 0, &comp->fmuData->modelData->realVarsData[5].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[6], 0, &comp->fmuData->modelData->realVarsData[6].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[7], 0, &comp->fmuData->modelData->realVarsData[7].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[8], 0, &comp->fmuData->modelData->realVarsData[8].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[9], 0, &comp->fmuData->modelData->realVarsData[9].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[10], 0, &comp->fmuData->modelData->realVarsData[10].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[11], 0, &comp->fmuData->modelData->realVarsData[11].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[12], 0, &comp->fmuData->modelData->realVarsData[12].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[13], 0, &comp->fmuData->modelData->realVarsData[13].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[14], 0, &comp->fmuData->modelData->realVarsData[14].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[15], 0, &comp->fmuData->modelData->realVarsData[15].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[16], 0, &comp->fmuData->modelData->realVarsData[16].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[17], 0, &comp->fmuData->modelData->realVarsData[17].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[18], 0, &comp->fmuData->modelData->realVarsData[18].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[19], 0, &comp->fmuData->modelData->realVarsData[19].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[20], 0, &comp->fmuData->modelData->realVarsData[20].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[21], 0, &comp->fmuData->modelData->realVarsData[21].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[22], 0, &comp->fmuData->modelData->realVarsData[22].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[23], 0, &comp->fmuData->modelData->realVarsData[23].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[24], 0, &comp->fmuData->modelData->realVarsData[24].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[25], 0, &comp->fmuData->modelData->realVarsData[25].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[26], 0, &comp->fmuData->modelData->realVarsData[26].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[27], 0, &comp->fmuData->modelData->realVarsData[27].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[28], 0, &comp->fmuData->modelData->realVarsData[28].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[29], 0, &comp->fmuData->modelData->realVarsData[29].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[30], 0, &comp->fmuData->modelData->realVarsData[30].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[31], 0, &comp->fmuData->modelData->realVarsData[31].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[32], 0, &comp->fmuData->modelData->realVarsData[32].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[33], 0, &comp->fmuData->modelData->realVarsData[33].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[34], 0, &comp->fmuData->modelData->realVarsData[34].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[35], 0, &comp->fmuData->modelData->realVarsData[35].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[36], 0, &comp->fmuData->modelData->realVarsData[36].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[37], 0, &comp->fmuData->modelData->realVarsData[37].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[38], 0, &comp->fmuData->modelData->realVarsData[38].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[39], 0, &comp->fmuData->modelData->realVarsData[39].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[40], 0, &comp->fmuData->modelData->realVarsData[40].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[41], 0, &comp->fmuData->modelData->realVarsData[41].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[42], 0, &comp->fmuData->modelData->realVarsData[42].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[43], 0, &comp->fmuData->modelData->realVarsData[43].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[44], 0, &comp->fmuData->modelData->realVarsData[44].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[45], 0, &comp->fmuData->modelData->realVarsData[45].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[46], 0, &comp->fmuData->modelData->realVarsData[46].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[47], 0, &comp->fmuData->modelData->realVarsData[47].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[48], 0, &comp->fmuData->modelData->realVarsData[48].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[49], 0, &comp->fmuData->modelData->realVarsData[49].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[50], 0, &comp->fmuData->modelData->realVarsData[50].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[51], 0, &comp->fmuData->modelData->realVarsData[51].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[52], 0, &comp->fmuData->modelData->realVarsData[52].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[53], 0, &comp->fmuData->modelData->realVarsData[53].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[54], 0, &comp->fmuData->modelData->realVarsData[54].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[55], 0, &comp->fmuData->modelData->realVarsData[55].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[56], 0, &comp->fmuData->modelData->realVarsData[56].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[57], 0, &comp->fmuData->modelData->realVarsData[57].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[58], 0, &comp->fmuData->modelData->realVarsData[58].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[59], 0, &comp->fmuData->modelData->realVarsData[59].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[60], 0, &comp->fmuData->modelData->realVarsData[60].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[61], 0, &comp->fmuData->modelData->realVarsData[61].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[62], 0, &comp->fmuData->modelData->realVarsData[62].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[63], 0, &comp->fmuData->modelData->realVarsData[63].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[64], 0, &comp->fmuData->modelData->realVarsData[64].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[65], 0, &comp->fmuData->modelData->realVarsData[65].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[66], 0, &comp->fmuData->modelData->realVarsData[66].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[67], 0, &comp->fmuData->modelData->realVarsData[67].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[68], 0, &comp->fmuData->modelData->realVarsData[68].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[69], 0, &comp->fmuData->modelData->realVarsData[69].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[70], 0, &comp->fmuData->modelData->realVarsData[70].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[71], 0, &comp->fmuData->modelData->realVarsData[71].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[72], 0, &comp->fmuData->modelData->realVarsData[72].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[73], 0, &comp->fmuData->modelData->realVarsData[73].attribute.start);
  put_real_element(comp->fmuData->localData[0]->realVars[74], 0, &comp->fmuData->modelData->realVarsData[74].attribute.start);
  comp->fmuData->modelData->booleanVarsData[0].attribute.start = comp->fmuData->localData[0]->booleanVars[0];
  comp->fmuData->modelData->booleanVarsData[1].attribute.start = comp->fmuData->localData[0]->booleanVars[1];
  comp->fmuData->modelData->booleanVarsData[2].attribute.start = comp->fmuData->localData[0]->booleanVars[2];
  comp->fmuData->modelData->booleanVarsData[3].attribute.start = comp->fmuData->localData[0]->booleanVars[3];
  put_real_element(comp->fmuData->simulationInfo->realParameter[0], 0, &comp->fmuData->modelData->realParameterData[0].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[1], 0, &comp->fmuData->modelData->realParameterData[1].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[2], 0, &comp->fmuData->modelData->realParameterData[2].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[3], 0, &comp->fmuData->modelData->realParameterData[3].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[4], 0, &comp->fmuData->modelData->realParameterData[4].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[5], 0, &comp->fmuData->modelData->realParameterData[5].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[6], 0, &comp->fmuData->modelData->realParameterData[6].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[7], 0, &comp->fmuData->modelData->realParameterData[7].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[8], 0, &comp->fmuData->modelData->realParameterData[8].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[9], 0, &comp->fmuData->modelData->realParameterData[9].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[10], 0, &comp->fmuData->modelData->realParameterData[10].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[11], 0, &comp->fmuData->modelData->realParameterData[11].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[12], 0, &comp->fmuData->modelData->realParameterData[12].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[13], 0, &comp->fmuData->modelData->realParameterData[13].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[14], 0, &comp->fmuData->modelData->realParameterData[14].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[15], 0, &comp->fmuData->modelData->realParameterData[15].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[16], 0, &comp->fmuData->modelData->realParameterData[16].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[17], 0, &comp->fmuData->modelData->realParameterData[17].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[18], 0, &comp->fmuData->modelData->realParameterData[18].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[19], 0, &comp->fmuData->modelData->realParameterData[19].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[20], 0, &comp->fmuData->modelData->realParameterData[20].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[21], 0, &comp->fmuData->modelData->realParameterData[21].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[22], 0, &comp->fmuData->modelData->realParameterData[22].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[23], 0, &comp->fmuData->modelData->realParameterData[23].attribute.start);
  put_real_element(comp->fmuData->simulationInfo->realParameter[24], 0, &comp->fmuData->modelData->realParameterData[24].attribute.start);
}


// implementation of the Model Exchange functions
// Used to set the next time event, if any.
void eventUpdate(ModelInstance* comp, fmi2EventInfo* eventInfo) {
}

static const int realAliasIndexes[11] = {
  33, 34, 0, 1, 2, 3, 4, 5, 10, 66, 67
};

fmi2Real getReal(ModelInstance* comp, const fmi2ValueReference vr) {
  if (vr < 75) {
    return comp->fmuData->localData[0]->realVars[vr];
  }
  if (vr < 100) {
    return comp->fmuData->simulationInfo->realParameter[vr-75];
  }
  if (vr < 111) {
    int ix = realAliasIndexes[vr-100];
    return ix>=0 ? getReal(comp, ix) : -getReal(comp, -(ix+1));
  }
  return NAN;
}

fmi2Status setReal(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Real value) {
  // set start value attribute for all variable that has start value, till initialization mode
  if (vr < 75 && (comp->state == model_state_instantiated || comp->state == model_state_initialization_mode)) {
    put_real_element(value, 0, &comp->fmuData->modelData->realVarsData[vr].attribute.start);
  }
  if (vr < 75) {
    comp->fmuData->localData[0]->realVars[vr] = value;
    return fmi2OK;
  }
  if (vr < 100) {
    comp->fmuData->simulationInfo->realParameter[vr-75] = value;
    return fmi2OK;
  }
  if (vr < 111) {
    int ix = realAliasIndexes[vr-100];
    return ix >= 0 ? setReal(comp, ix, value) : setReal(comp, -(ix+1), -value);
  }
  return fmi2Error;
}

fmi2Integer getInteger(ModelInstance* comp, const fmi2ValueReference vr) {
  if (vr < 0) {
    return comp->fmuData->localData[0]->integerVars[vr];
  }
  if (vr < 0) {
    return comp->fmuData->simulationInfo->integerParameter[vr-0];
  }
  return 0;
}

fmi2Status setInteger(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Integer value) {
  // set start value attribute for all variable that has start value, till initialization mode
  if (vr < 0 && (comp->state == model_state_instantiated || comp->state == model_state_initialization_mode)) {
    comp->fmuData->modelData->integerVarsData[vr].attribute.start = value;
  }
  if (vr < 0) {
    comp->fmuData->localData[0]->integerVars[vr] = value;
    return fmi2OK;
  }
  if (vr < 0) {
    comp->fmuData->simulationInfo->integerParameter[vr-0] = value;
    return fmi2OK;
  }
  return fmi2Error;
}
fmi2Boolean getBoolean(ModelInstance* comp, const fmi2ValueReference vr) {
  switch (vr) {
    case 0 : return comp->fmuData->localData[0]->booleanVars[0]; break;
    case 1 : return comp->fmuData->localData[0]->booleanVars[1]; break;
    case 2 : return comp->fmuData->localData[0]->booleanVars[2]; break;
    case 3 : return comp->fmuData->localData[0]->booleanVars[3]; break;
    case 4 : return getBoolean(comp, 0); break;
    case 5 : return getBoolean(comp, 1); break;
    case 6 : return getBoolean(comp, 2); break;
    case 7 : return getBoolean(comp, 3); break;
    default:
      return fmi2False;
  }
}

fmi2Status setBoolean(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Boolean value) {
  switch (vr) {
    case 0 : comp->fmuData->localData[0]->booleanVars[0] = value; break;
    case 1 : comp->fmuData->localData[0]->booleanVars[1] = value; break;
    case 2 : comp->fmuData->localData[0]->booleanVars[2] = value; break;
    case 3 : comp->fmuData->localData[0]->booleanVars[3] = value; break;
    case 4 : return setBoolean(comp, 0, value); break;
    case 5 : return setBoolean(comp, 1, value); break;
    case 6 : return setBoolean(comp, 2, value); break;
    case 7 : return setBoolean(comp, 3, value); break;
    default:
      return fmi2Error;
  }
  return fmi2OK;
}

fmi2String getString(ModelInstance* comp, const fmi2ValueReference vr) {
  switch (vr) {
    default:
      return "";
  }
}

fmi2Status setString(ModelInstance* comp, const fmi2ValueReference vr, fmi2String value) {
  switch (vr) {
    default:
      return fmi2Error;
  }
  return fmi2OK;
}

fmi2Status setExternalFunction(ModelInstance* c, const fmi2ValueReference vr, const void* value){
  switch (vr) {
    default:
      return fmi2Error;
  }
  return fmi2OK;
}

/* function maps input references to a input index used in partialDerivatives */
fmi2ValueReference mapInputReference2InputNumber(const fmi2ValueReference vr) {
    switch (vr) {
      case 43: return 0; break;
      case 44: return 1; break;
      case 55: return 2; break;
      case 65: return 3; break;
      case 68: return 4; break;
      case 69: return 5; break;
      case 70: return 6; break;
      default:
        return -1;
    }
}
/* function maps output references to a input index used in partialDerivatives */
fmi2ValueReference mapOutputReference2OutputNumber(const fmi2ValueReference vr) {
    switch (vr) {
      case 33: return 0; break;
      case 34: return 1; break;
      case 35: return 2; break;
      case 36: return 3; break;
      case 37: return 4; break;
      case 39: return 5; break;
      case 57: return 6; break;
      case 58: return 7; break;
      case 64: return 8; break;
      case 66: return 9; break;
      case 67: return 10; break;
      default:
        return -1;
    }
}
/* function maps output references to an internal output Real derivatives */
fmi2ValueReference mapOutputReference2RealOutputDerivatives(const fmi2ValueReference vr) {
    switch (vr) {
      case 33: return -1; break;
      case 34: return -1; break;
      case 35: return -1; break;
      case 36: return -1; break;
      case 37: return -1; break;
      case 39: return -1; break;
      case 57: return -1; break;
      case 58: return -1; break;
      case 64: return -1; break;
      case 66: return -1; break;
      case 67: return -1; break;
      default:
        return -1;
    }
}
/* function maps initialUnknowns UnknownVars ValueReferences to an internal partial derivatives index */
fmi2ValueReference mapInitialUnknownsdependentIndex(const fmi2ValueReference vr) {
    switch (vr) {
      case 4: return 0; break;
      case 5: return 1; break;
      case 12: return 2; break;
      case 13: return 3; break;
      case 14: return 4; break;
      case 15: return 5; break;
      case 16: return 6; break;
      case 17: return 7; break;
      case 18: return 8; break;
      case 19: return 9; break;
      case 20: return 10; break;
      case 21: return 11; break;
      case 22: return 12; break;
      case 23: return 13; break;
      case 33: return 14; break;
      case 34: return 15; break;
      case 35: return 16; break;
      case 36: return 17; break;
      case 37: return 18; break;
      case 39: return 19; break;
      case 57: return 20; break;
      case 58: return 21; break;
      case 64: return 22; break;
      case 66: return 23; break;
      case 67: return 24; break;
      default:
        return -1;
    }
}
/* function maps initialUnknowns knownVars ValueReferences to an internal partial derivatives index */
fmi2ValueReference mapInitialUnknownsIndependentIndex(const fmi2ValueReference vr) {
    switch (vr) {
      case 0: return 0; break;
      case 1: return 1; break;
      case 2: return 2; break;
      case 3: return 3; break;
      case 6: return 4; break;
      case 7: return 5; break;
      case 8: return 6; break;
      case 9: return 7; break;
      case 10: return 8; break;
      case 11: return 9; break;
      case 43: return 10; break;
      case 44: return 11; break;
      case 55: return 12; break;
      case 65: return 13; break;
      case 68: return 14; break;
      case 69: return 15; break;
      case 70: return 16; break;
      case 75: return 17; break;
      case 76: return 18; break;
      case 77: return 19; break;
      case 78: return 20; break;
      case 79: return 21; break;
      case 80: return 22; break;
      case 81: return 23; break;
      case 82: return 24; break;
      case 83: return 25; break;
      case 84: return 26; break;
      case 85: return 27; break;
      case 86: return 28; break;
      case 87: return 29; break;
      case 88: return 30; break;
      case 89: return 31; break;
      case 90: return 32; break;
      case 91: return 33; break;
      case 92: return 34; break;
      case 93: return 35; break;
      case 94: return 36; break;
      case 95: return 37; break;
      case 96: return 38; break;
      case 97: return 39; break;
      case 98: return 40; break;
      case 99: return 41; break;
      default:
        return -1;
    }
}

