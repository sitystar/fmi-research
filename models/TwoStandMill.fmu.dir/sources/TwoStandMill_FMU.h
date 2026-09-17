#ifndef TwoStandMill_FMU_H
#define TwoStandMill_FMU_H

#include "simulation_data.h"

// define class name and unique id
#define MODEL_IDENTIFIER TwoStandMill
#define MODEL_GUID "{c8f37d53-e2aa-4840-b471-fd618266c552}"

// define model size
#define NUMBER_OF_STATES 12
#define NUMBER_OF_EVENT_INDICATORS 9
#define NUMBER_OF_REALS 111
#define NUMBER_OF_REAL_INPUTS 7
#define NUMBER_OF_INTEGERS 0
#define NUMBER_OF_STRINGS 0
#define NUMBER_OF_BOOLEANS 8
#define NUMBER_OF_EXTERNALFUNCTIONS 0

// define initial state vector as vector of value references
#define STATES { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }
#define STATESDERIVATIVES { 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 }


#ifdef __cplusplus
extern "C" {
#endif

extern void TwoStandMill_setupDataStruc(DATA *data, threadData_t *threadData);
#define fmu2_model_interface_setupDataStruc TwoStandMill_setupDataStruc
#include "fmi-export/fmu2_model_interface.h"
#include "fmi-export/fmu_read_flags.h"

#define FMI2_FUNCTION_PREFIX TwoStandMill_
#include "fmi2Functions.h"
#include "fmi-export/fmu2_model_interface.h"
#include "fmi-export/fmu_read_flags.h"

void setStartValues(ModelInstance *comp);
void setDefaultStartValues(ModelInstance *comp);
void eventUpdate(ModelInstance* comp, fmi2EventInfo* eventInfo);
fmi2Real getReal(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setReal(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Real value);
fmi2Integer getInteger(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setInteger(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Integer value);
fmi2Boolean getBoolean(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setBoolean(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Boolean value);
fmi2String getString(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setString(ModelInstance* comp, const fmi2ValueReference vr, fmi2String value);
fmi2Status setExternalFunction(ModelInstance* c, const fmi2ValueReference vr, const void* value);
fmi2ValueReference mapInputReference2InputNumber(const fmi2ValueReference vr);
fmi2ValueReference mapOutputReference2OutputNumber(const fmi2ValueReference vr);
fmi2ValueReference mapOutputReference2RealOutputDerivatives(const fmi2ValueReference vr);
fmi2ValueReference mapInitialUnknownsdependentIndex(const fmi2ValueReference vr);
fmi2ValueReference mapInitialUnknownsIndependentIndex(const fmi2ValueReference vr);


#ifdef __cplusplus
}
#endif

#endif /* TwoStandMill_FMU_H */