#pragma once
#include "BaseQueue.h"

class queue2_protected :
    protected BaseQueue{
public:
    int Calculation_protected(BaseQueue* ptr);
    void ShowCalculation_protected(BaseQueue* ptr, bool* empty);
};