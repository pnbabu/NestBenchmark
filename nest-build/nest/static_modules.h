#ifndef STATIC_MODULES_H
#define STATIC_MODULES_H

#include "modelsmodule.h"

// Others
#include "interpret.h"

void add_static_modules( SLIInterpreter& engine )
{
  engine.addmodule( new nest::ModelsModule() );
}

#endif
