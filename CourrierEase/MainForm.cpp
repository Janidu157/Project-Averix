#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace CourrierEase;

[STAThreadAttribute]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    CourrierEase::MainForm form;
    Application::Run(%form);

    return 0;
}