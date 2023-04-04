#include "ExampleRace.h"

//"Тяжелый" метод будет по инкриминтировать переменную по адресу. Таким образом для
//имитации гонки два потока будут обращаться к одной и той же переменной.
void ExampleRace::DoWork(uint32_t* num, bool mutexOn, int numIterat)
{
    if(mutexOn){
        mut->lock();
        for(uint32_t i = 0; i < numIterat; i++){

            (*num)++;
        }
        mut->unlock();
    }
    else{
        for(uint32_t i = 0; i < numIterat; i++){
            (*num)++;
        }
    }

    emit sig_Finish();
}
