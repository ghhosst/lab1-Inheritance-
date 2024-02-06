#pragma once
#include "BaseQueue.h"

class queue1_public :
    public BaseQueue{
public:
   int Calculation_public(BaseQueue* ptr);
   void ShowCalculation_public(BaseQueue* ptr, bool* empty);
};