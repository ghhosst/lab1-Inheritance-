#pragma once
#include "BaseQueue.h"

class queue3_private :
    private BaseQueue{
public:
    int Calculation_private(BaseQueue* ptr);
    void ShowCalculation_private(BaseQueue* ptr, bool* empty);
};