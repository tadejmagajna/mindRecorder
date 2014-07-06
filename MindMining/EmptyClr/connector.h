#pragma once

using namespace System::Windows::Forms;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
ref class connector
{
public:
	connector();
	void device_connect(int n, BackgroundWorker^ worker, DoWorkEventArgs ^ e);
};

