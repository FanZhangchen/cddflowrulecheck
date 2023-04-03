#include "cddflowrulecheckApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
cddflowrulecheckApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

cddflowrulecheckApp::cddflowrulecheckApp(InputParameters parameters) : MooseApp(parameters)
{
  cddflowrulecheckApp::registerAll(_factory, _action_factory, _syntax);
}

cddflowrulecheckApp::~cddflowrulecheckApp() {}

void
cddflowrulecheckApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"cddflowrulecheckApp"});
  Registry::registerActionsTo(af, {"cddflowrulecheckApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
cddflowrulecheckApp::registerApps()
{
  registerApp(cddflowrulecheckApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
cddflowrulecheckApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  cddflowrulecheckApp::registerAll(f, af, s);
}
extern "C" void
cddflowrulecheckApp__registerApps()
{
  cddflowrulecheckApp::registerApps();
}
